//
// Created by Thomas Couchoud on 08/02/2018.
//

#ifndef GENERATOR_COMMUTATOR_H
#define GENERATOR_COMMUTATOR_H

#include "Node.h"
#include "Machine.h"

/**
 * A Switch.
 */
class Commutator : public Node
{
public:
	/**
	 * Constructor.
	 * @param name The name of the switch.
	 * @param connections The number of ports of teh switch.
	 * @param i The x coordinate.
	 * @param j The y coordinate.
	 * @param k The z coordinate.
	 */
	Commutator(const std::string &name, int connections, int i, int j, int k);
	
	/**
	 * Normalize ports to follow those in the TP subject.
	 */
	void normalizePorts();
};

#endif //GENERATOR_COMMUTATOR_H
