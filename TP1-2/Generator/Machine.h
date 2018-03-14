//
// Created by Thomas Couchoud on 08/02/2018.
//

#ifndef GENERATOR_MACHINE_H
#define GENERATOR_MACHINE_H

#include "Node.h"

/**
 * A machine.
 */
class Machine : public Node
{
public:
	/**
	 * Constructor.
	 *
	 * @param i The x coordinate.
	 * @param j The y coordinate.
	 * @param k The z coordinate.
	 */
	Machine(int i, int j, int k);
	
	/**
	 * Set the node where the machine is connected to.
	 * @param node The node to connect.
	 */
	void setConnectedTo(Node * node);
};

#endif //GENERATOR_MACHINE_H
