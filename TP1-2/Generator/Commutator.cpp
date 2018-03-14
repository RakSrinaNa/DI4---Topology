//
// Created by Thomas Couchoud on 08/02/2018.
//

#include <vector>
#include <cmath>
#include "Commutator.h"
#include "Machine.h"

using namespace std;

Commutator::Commutator(const std::string &name, int connections, int i, int j, int k) : Node("Switch", name, connections, i, j, k)
{
}

void Commutator::normalizePorts()
{
	unsigned long s = connectedTo.size();
	vector<Node *> normalized = vector<Node *>(s, nullptr);
	for(int i = 0; i < s; i ++)
		normalized[(i * 2) % s + (i * 2 < s ? 1 : 0)] = connectedTo[i];
	swap(connectedTo, normalized);
}

