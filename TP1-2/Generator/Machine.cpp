//
// Created by Thomas Couchoud on 08/02/2018.
//

#include "Machine.h"

Machine::Machine(int i, int j, int k) : Node("Hca", "Node", 1, i, j, k)
{
}

void Machine::setConnectedTo(Node * node)
{
	setLink(0, node);
}
