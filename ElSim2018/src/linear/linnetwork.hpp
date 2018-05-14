/*
 * linnetwork.hpp
 *
 *  Created on: 27.04.2018
 *      Author: linurutz
 */

#ifndef LINNETWORK_HPP_
#define LINNETWORK_HPP_

#include "../mathmatics/matrix.hpp"
#include "linresistor.hpp"
#include "linvoltage.hpp"

class LinNetwork{
protected:
	Matrix conductance, reorder;
	Vector inputVoltage, nodalVoltage;
	struct Resistors{
		LinResistor* resistorEl;
		Resistors* next;
	};
	struct Voltages{
		LinVoltage* voltagEl;
		Voltages* next;
	};

	struct Voltages* voltages;
	struct Resistors* resistors;

public:
	LinNetwork(void);
	void addResistor(LinResistor*);
	void addVoltage(LinVoltage*);
	void optimizeSystem(void);
	void solveSystem(void);
	Vector getNodalVoltages(void);
	Matrix getConductance(void);

};


#endif /* LINNETWORK_HPP_ */
