//
// Created by Thomas Couchoud on 08/02/2018.
//

#include <algorithm>
#include <sstream>
#include "Node.h"

using namespace std;

int Node::NEXT_ID = 0;

Node::Node(const std::string &type, const std::string &name, int connections, int i, int j, int k) : type(type)
{
	this->ID = Node::NEXT_ID++;
	connectedTo = vector<Node *>();
	connectedTo.resize(connections, nullptr);
	
	stringstream s;
	s << name << "(" << i;
	if(j != -1 && k != -1)
		s << " " << j << " " << k;
	s << ")";
	this->name = s.str();
}

string &Node::getType()
{
	return type;
}

int Node::getID()
{
	return ID;
}

string &Node::getName()
{
	return name;
}

void Node::setLink(int index, Node * node)
{
	if(index >= connectedTo.size())
	{
		printf("Trying to set a link on a non existing port (%d/%d) on %s", index, getPortCount(), getName().c_str());
		exit(EXIT_FAILURE);
	}
	if(connectedTo[index] != nullptr)
		printf("WARN: Overriding existing link of %s (%d)\n", getName().c_str(), index);
	connectedTo[index] = node;
}

int Node::getPortCount()
{
	return static_cast<int>(connectedTo.size());
}

Node * Node::getLink(int index)
{
	if(index >= connectedTo.size())
	{
		perror("Trying to get a link of a non existing port");
		exit(EXIT_FAILURE);
	}
	return connectedTo[index];
}

int Node::getPortWhereIs(Node * node)
{
	auto it = std::find(connectedTo.begin(), connectedTo.end(), node);
	return static_cast<int>(it == connectedTo.end() ? -1 : distance(connectedTo.begin(), it));
}

bool Node::operator==(const Node &rhs) const
{
	return ID == rhs.ID;
}

bool Node::operator!=(const Node &rhs) const
{
	return !(rhs == *this);
}


