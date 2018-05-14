/*
 * linresistor.hpp
 *
 *  Created on: 27.04.2018
 *      Author: linurutz
 */

#ifndef LINRESISTOR_HPP_
#define LINRESISTOR_HPP_

#include "../mathmatics/matrix.hpp"
//#include "../mathmatics/vector.hpp"

class LinResistor{
protected:
	int elNumber, nodeNumber_1, nodeNumber_2;
	double resistance;
	Matrix conductance;

public:
	LinResistor(int);
	LinResistor(int, int, int);
	LinResistor(int, double, int, int);

	void setResistance(double);
	void setNodes(int, int);

	double getCurrent(Vector);

	Matrix getConductivity(void);

	int getElemNum(void);

};

#endif /* LINRESISTOR_HPP_ */
