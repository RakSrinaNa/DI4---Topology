//
// Created by Thomas Couchoud on 08/02/2018.
//

#ifndef GENERATOR_NODE_H
#define GENERATOR_NODE_H

#include <string>
#include <vector>

/**
 * A node of the network.
 */
class Node
{
private:
	//! Its unique ID.
	int ID;
	//! Next unique ID for the generation.
	static int NEXT_ID;
	//! The type of the node.
	std::string type;
	//! The name of the node.
	std::string name;
protected:
	//! The ports of the node.
	std::vector<Node *> connectedTo;
public:
	/**
	 * Constructor.
	 * @param type The type of the node.
	 * @param name The name of the node.
	 * @param connections The number of ports of the node.
	 * @param i The x coordinate.
	 * @param j The y coordinate.
	 * @param k The z coordinate.
	 */
	Node(const std::string &type, const std::string &name, int connections, int i, int j, int k);
	
	/**
	 * Get the type.
	 * @return The type.
	 */
	std::string &getType();
	
	/**
	 * Get the ID.
	 * @return The ID.
	 */
	int getID();
	
	/**
	 * Get the name.
	 * @return The name.
	 */
	std::string &getName();
	
	/**
	 * Get the number of ports.
	 * @return The number of ports.
	 */
	int getPortCount();
	
	/**
	 * Set where a port is connected.
	 * @param index The port index.
	 * @param node Where this port is connected.
	 */
	void setLink(int index, Node * node);
	
	/**
	 * Get where a port is connected.
	 * @param index The port concerned.
	 * @return The Node connected to, or null if disconnected.
	 */
	Node * getLink(int index);
	
	/**
	 * Get the port where a Node is connected.
	 * @param node The Node to find.
	 * @return The index of the port, -1 if not found.
	 */
	int getPortWhereIs(Node * node);
	
	bool operator==(const Node &rhs) const;
	
	bool operator!=(const Node &rhs) const;
};

#endif //GENERATOR_NODE_H
