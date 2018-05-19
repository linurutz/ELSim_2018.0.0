/*
 * linvoltage.hpp
 *
 *  Created on: 27.04.2018
 *      Author: linurutz
 */

#ifndef LINVOLTAGE_HPP_
#define LINVOLTAGE_HPP_

class LinVoltage{
protected:
	int elementNumber, referenceNode, potentialNode;
	double voltages;

public:
	LinVoltage(int);
	LinVoltage(int, int, int);
	LinVoltage(int, double, int, int);
	void setRefNode(int);
	void setPotNode(int);
	void setVoltage(double);
	double getVoltage(void);
	int getElemNum(void);
	int getRefNode(void);
	int getPotNode(void);
	int getMaxNode(void);
	int getMinNode(void);

};


#endif /* LINVOLTAGE_HPP_ */
