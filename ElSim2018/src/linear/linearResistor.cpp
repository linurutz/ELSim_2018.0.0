/*
 * linearResistor.cpp
 *
 *  Created on: 15.05.2018
 *      Author: ruby
 */


#include "linearResistor.hpp"

LinearResistor::LinearResistor(int elNum) : conductance(10){ // @suppress("Class members should be properly initialized")
	this->elementNumber = elNum;
	this->resistance = 1;
	//TODO: implement other constructors
	//TODO: setResistance

}

void LinearResistor::setResistance(double resis){
	this->conductance *= this->resistance;
	this->resistance = resis;
	this->conductance /= this->resistance;
}

int LinearResistor::getElementNumber(void){
	return this->elementNumber;
}

Matrix LinearResistor::getConductance(void){
	return this->conductance;
}

double LinearResistor::getCurrent(Vector voltages){
	Vector buffer = this->conductance * voltages;
	return buffer.getValue(this->nodeTwo);
}
