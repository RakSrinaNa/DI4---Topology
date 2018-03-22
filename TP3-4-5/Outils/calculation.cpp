#include <iostream>
#include <vector>

#include "calculation.h"

using namespace std;

Calculation::Calculation()
{
}

Calculation::~Calculation()
{
}

/**
 * Constructeur qui charge les informations
 * de la topologie et table de routage en mémoire.
 */
Calculation::Calculation(char * topoFile, char * routeFile)
{
	topologyTable.loadData(topoFile);
	routingTable.loadData(routeFile);
}

/**
 * Méthode qui calcule le nombre de sauts
 * d'un noeud source jusqu'au noeud destination.
 */
int Calculation::getHopCount(int fromId, int toId)
{
  	if(fromId == toId)
		return 0;
	int count = 1;
	struct hostNode * fromHost = topologyTable.getHostById(fromId);
	string fromNode = fromHost->name;
	string toNode = topologyTable.getHostById(toId)->name;
	string switchName = fromHost->dstName; //Get the first switch that the node is connected to.
	bool shouldSearch = true;

	while(shouldSearch)
	{
		bool changed = false;
		routeItem * route = routingTable.getTableByName(switchName);

		for(int i = 0; i < route->subitems; i++) //For each item in the routing table
		{
			if(route->dstInfo.at(static_cast<unsigned long>(i)) == topologyTable.getHostById(toId)->name) //If it's our destination
			{
				string name = topologyTable.getSwitchByName(switchName)->dstName.at(static_cast<unsigned long>(route->outport.at(i)) - 1); //Get the next node
				if(name == topologyTable.getHostById(toId)->name) //If we arrived to our destination, stop
				{
					shouldSearch = false;
					break;
				}
				else //Set new switch
				{
					changed = true;
					switchName = name;
				}
			}
		}

		if(shouldSearch && !changed)
		{
			std::cout << "ERRROR MAMAMIA" << std::endl;
			break;
		}
		count++;
	}

	cout << "From " << fromNode << " to " << toNode << ": Hop Count = " << count << endl;
	return count;
}

/**
 * Méthode qui implémente la métrique Minhop.
 */
int Calculation::calculate()
{
	int minHop = 0xffff; //Max value
	for(int i = 0; i < topologyTable.getHostCount(); i++)
	{
		int cpt = 0;
		for(int j = 0; j < topologyTable.getHostCount(); j++)
		{
			if(i == j)
				continue;
			cpt = max(cpt, getHopCount(i, j));
		}
		minHop = min(minHop, cpt);
	}
	return minHop;
}

/**
 * Méthode qui calcule la charge d'un noeud
 * source jusqu'au noeud destination.
 */
int Calculation::getRoute(int fromId, int toId)
{
	struct hostNode * fromHost = topologyTable.getHostById(fromId);
	string fromNode = fromHost->name;
	string toNode = topologyTable.getSwitchById(toId)->name;
	cout << "From " << fromNode << " to " << toNode;
	string switchName = fromHost->dstName;
	struct routeItem * route = routingTable.getTableByName(switchName);

	for(int i = 0; i < route->dstInfo.size(); i++){
        if(route->dstInfo[i] == toNode)
            return 1;
	}
	return 0;
}

/**
 * Méthode qui implémente la métrique nombre de chemins disjoints.
 */
int Calculation::balance()
{
	int balance = 0x0000;; //Max value
    
    for(int i = 0; i < topologyTable.getSwitchCount(); i++){ //For each switch
        switchNode * s = topologyTable.getSwitchById(i);
        struct routeItem * route = routingTable.getTableByName(s->name);
        int t[s->portCount] = {0};
        for(int j = 0; j < route->subitems; j++){ //Count each route on each port (link)
                t[route->outport[j] -1]++;
        }
        for(int j = 0; j < s->portCount; j++)
            balance = max (balance, t[j]); //Get the max
    }
	return balance;
}

