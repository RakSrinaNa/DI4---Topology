#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "Commutator.h"

using namespace std;

/**
 * Write a node into a stream.
 *
 * @param s The stream to write into.
 * @param node The node to write.
 */
void writeNode(ostream &s, Node * node)
{
	//Write node
	s << node->getType() << '\t' << node->getPortCount() << '\t' << '"' << node->getName() << '"' << " lid " << node->getID() << endl;
	for(int i = 0; i < node->getPortCount(); i++)
	{
		//Write connection
		Node * connectedTo = nullptr;
		if((connectedTo = node->getLink(i)) != nullptr)
			s << '[' << (i + 1) << ']' << '"' << connectedTo->getName() << '"' << '[' << (connectedTo->getPortWhereIs(node) + 1) << ']' << endl;
	}
	s << endl;
}

/**
 * Write the topology file.
 * @param s The stream to write into.
 * @param k The k used.
 * @param machines The machines.
 * @param edge The edge switches.
 * @param aggregation The aggregation switches.
 * @param core The core switches.
 */
void writeAll(ostream &s, int k, vector<Machine *> machines, vector<Commutator *> edge, vector<Commutator *> aggregation, vector<Commutator *> core)
{
	s << "#Fat tree topology file" << endl;
	s << "#Value of k = " << k << endl;
	s << "#Total number of hosts = " << machines.size() << endl;
	s << "#Number of hosts under each switch = " << (k / 2) << endl;
	s << "#Number of commutators = " << (edge.size() + aggregation.size() + core.size()) << endl;
	s << "########################################################" << endl << endl;
	
	s << "#Machines:" << endl;
	for(auto m : machines)
		writeNode(s, m);
	
	s << "#Edge:" << endl;
	for(auto c : edge)
		writeNode(s, c);
	
	s << "#Aggregation:" << endl;
	for(auto c : aggregation)
		writeNode(s, c);
	
	s << "#Core:" << endl;
	for(auto c : core)
		writeNode(s, c);
	
	s.flush();
}

int main(int argc, char ** argv)
{
	int k;
	if(argc == 2)
	{
		k = atoi(argv[1]);
	}
	else
	{
		cout << "Enter k: ";
		cin >> k;
	}
	
	cout << "Selected k: " << k << endl;
    if(k%2 != 0)
    {
        cout << "K must be a multiple of 2" << endl;
        exit(EXIT_FAILURE);
    }
	
	//Init constants (count of elements par category)
	auto machineCountPerPod = static_cast<int>(pow(k / 2, 2));
	auto machineCount = machineCountPerPod * k;
	auto edgeCount = static_cast<int>(pow(k, 2) / 2);
	auto aggregationCount = static_cast<int>(pow(k, 2) / 2);
	auto coreCount = static_cast<int>(pow(k / 2, 2));
	
	vector<Machine *> machines = vector<Machine *>();
	vector<Commutator *> edge = vector<Commutator *>();
	vector<Commutator *> aggregation = vector<Commutator *>();
	vector<Commutator *> core = vector<Commutator *>();
	
	//Create machines
	for(int i = 0; i < machineCount; i++)
	{
		cout << "Creating machine " << i << endl;
		machines.push_back(new Machine(i, -1, -1));
	}
	
	//Create edge
	for(int i = 0; i < edgeCount; i++)
	{
		//Create switch
		cout << "Creating edge " << i << endl;
		Commutator * commutator = new Commutator("Edge", k, i / (k / 2), i % (k / 2), 1);
		edge.push_back(commutator);
		
		//Link switch to the machines
		for(int j = 0; j < k / 2; j++)
		{
			Machine * m = machines[i * (k / 2) + j];
			m->setConnectedTo(commutator);
			commutator->setLink(j, m);
		}
	}
	
	//Create aggregation
	for(int i = 0; i < aggregationCount; i++)
	{
		//Create switch
		cout << "Creating aggregation " << i << endl;
		Commutator * commutator = new Commutator("Aggr", k, i / (k / 2), i % (k / 2) + (k / 2), 1);
		aggregation.push_back(commutator);
		
		//Link to edge switches
		int group = i / (k / 2);
		int offsetPort = i % (k / 2);
		for(int j = 0; j < k / 2; j++)
		{
			Commutator * c = edge[group * k / 2 + j];
			c->setLink(k / 2 + offsetPort, commutator);
			commutator->setLink(j, c);
		}
	}
	
	//Create core
	for(int i = 0; i < coreCount; i++)
	{
		//Create switch
		cout << "Creating core " << i << endl;
		Commutator * commutator = new Commutator("Core", k, k, 1 + i / (k / 2), 1 + i % (k / 2));
		core.push_back(commutator);
		
		//Link to aggregation
		int offsetAggregation = 2 * i / k;
		int offsetPortAggregation = i % (k / 2);
		for(int j = 0; j < k; j++)
		{
			Commutator * c = aggregation[offsetAggregation + j * (k / 2)];
			c->setLink(k / 2 + offsetPortAggregation, commutator);
			commutator->setLink(j, c);
		}
	}
	
	//Normalize ports to follow the naming in the TP subject
	for(auto c : edge)
		c->normalizePorts();
	for(auto c : aggregation)
		c->normalizePorts();
	
	//Write file
	ofstream outFile;
	outFile.open("topo.topo");
	writeAll(outFile, k, machines, edge, aggregation, core);
	outFile.close();
	
	//Bye bye
	cout << flush;
	return 0;
}
