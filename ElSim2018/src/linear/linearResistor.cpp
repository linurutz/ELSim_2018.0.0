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
}

LinearResistor::LinearResistor(int elNum, int node_1, int node_2)  : conductance(10){
	this->elementNumber = elNum;
	this->resistance = 1;
	int maxNode = node_2;

	if(node_1 > node_2)
	{
		maxNode = node_1;
	}

	if(node_2 == node_1){
		this->nodeTwo = node_1;
		this->nodeOne = 0;
	}

	else //Node_1 < Node_2
	{
		this->nodeOne = node_1;
		this->nodeTwo = node_2;
	}

	Matrix buffer = *(new Matrix(maxNode + 1));
	this->conductance = buffer;
	initNodes();
}

LinearResistor::LinearResistor(int elNum, double resis, int node_1, int node_2)  : conductance(10){
	this->elementNumber = elNum;
	this->resistance = 1;
	int maxNode = node_2;
	if(node_1 > node_2) {
		maxNode = node_1;
		}
	if(node_2 == node_1)
	{
		this->nodeTwo = node_1;
		this->nodeOne = 0;
	}
	else //Node_1 < Node_2
	{
		this->nodeOne = node_1;
		this->nodeTwo = node_2;
	}
	Matrix buffer = *(new Matrix(maxNode + 1));
	this->conductance = buffer;
	initNodes();
	this->resistance = resis;
	this->conductance /= this->resistance;
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

void LinearResistor::setNodes(int node_1, int node_2){
	int maxNode = node_2;
	if(node_1 > node_2) 
	{
		maxNode = node_1;
	}
	if(node_2 == node_1)
	{
		this->nodeOne = node_1;
		this->nodeTwo = 0;
	}
	else
	{
		this->nodeOne = node_1;
		this->nodeTwo = node_2;
	}
	Matrix buffer = *(new Matrix(maxNode + 1));
	this->conductance = buffer;
	initNodes();
	this->conductance /= this->resistance;
}

void LinearResistor::initNodes() {

	this->conductance.setValue(this->nodeOne, this->nodeOne, -1.);
	this->conductance.setValue(this->nodeTwo, this->nodeTwo, -1.);
	this->conductance.setValue(this->nodeOne, this->nodeTwo, 1.);
	this->conductance.setValue(this->nodeTwo, this->nodeOne, 1.);
}