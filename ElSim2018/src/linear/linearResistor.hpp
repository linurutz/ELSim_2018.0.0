/*
 * linearResistor.hpp
 *
 *  Created on: 15.05.2018
 *      Author: ruby
 */

#ifndef SRC_LINEAR_LINEARRESISTOR_HPP_
#define SRC_LINEAR_LINEARRESISTOR_HPP_

#include "../mathmatics/matrix.hpp"

class LinearResistor {

protected:
	//Member Variables
	int elementNumber, nodeOne, nodeTwo;
	double resistance,current;
	Matrix conductance;

public:
	//Constructors
	LinearResistor(int);
	LinearResistor(int, int, int);
	LinearResistor(int, double, int, int);

	//Method stubs

	void setResistance(double);
	Matrix getConductance(void);
	int getElementNumber(void) ;
	void setConductance(Matrix);
	double getCurrent(Vector);
	void setNodes(int, int);
	void initNodes(void);
};



#endif /* SRC_LINEAR_LINEARRESISTOR_HPP_ */
