/*
 * linresistor.cpp
 *
 *  Created on: 27.04.2018
 *      Author: linurutz
 */

#include "linresistor.hpp"

LinResistor::LinResistor(int elNum) : conductance(10){
	this->elNumber = elNum;
	this->resistance = 1;
}

LinResistor::LinResistor(int elNum, int node_1, int node_2)  : conductance(10){
	this->elNumber = elNum;
	this->resistance = 1;
	int maxNode = node_2;
	if(node_1 > node_2) {maxNode = node_1;}
	if(node_2 == node_1){
		this->nodeNumber_2 = node_1;
		this->nodeNumber_1 = 0;
	}
	else{
		this->nodeNumber_1 = node_1;
		this->nodeNumber_2 = node_2;
	}
	this->conductance = *(new Matrix(maxNode + 1));
	this->conductance.setValue(this->nodeNumber_1, this->nodeNumber_1, -1.);
	this->conductance.setValue(this->nodeNumber_2, this->nodeNumber_2, -1.);
	this->conductance.setValue(this->nodeNumber_1, this->nodeNumber_2, 1.);
	this->conductance.setValue(this->nodeNumber_2, this->nodeNumber_1, 1.);
}

LinResistor::LinResistor(int elNum, double resis, int node_1, int node_2)  : conductance(10){
	this->elNumber = elNum;
	this->resistance = 1;
	int maxNode = node_2;
	if(node_1 > node_2) {maxNode = node_1;}
	if(node_2 == node_1){
		this->nodeNumber_2 = node_1;
		this->nodeNumber_1 = 0;
	}
	else{
		this->nodeNumber_1 = node_1;
		this->nodeNumber_2 = node_2;
	}
	this->conductance = *(new Matrix(maxNode + 1));
	this->conductance.setValue(this->nodeNumber_1, this->nodeNumber_1, -1.);
	this->conductance.setValue(this->nodeNumber_2, this->nodeNumber_2, -1.);
	this->conductance.setValue(this->nodeNumber_1, this->nodeNumber_2, 1.);
	this->conductance.setValue(this->nodeNumber_2, this->nodeNumber_1, 1.);
	this->resistance = resis;
	this->conductance /= this->resistance;
}

void LinResistor::setResistance(double resis){
	this->conductance *= this->resistance;
	this->resistance = resis;
	this->conductance /= this->resistance;
}

void LinResistor::setNodes(int node_1, int node_2){
	int maxNode = node_2;
	if(node_1 > node_2) {maxNode = node_1;}
	if(node_2 == node_1){
		this->nodeNumber_2 = node_1;
		this->nodeNumber_1 = 0;
	}
	else{
		this->nodeNumber_1 = node_1;
		this->nodeNumber_2 = node_2;
	}
	this->conductance = *(new Matrix(maxNode + 1));
	this->conductance.setValue(this->nodeNumber_1, this->nodeNumber_1, -1.);
	this->conductance.setValue(this->nodeNumber_2, this->nodeNumber_2, -1.);
	this->conductance.setValue(this->nodeNumber_1, this->nodeNumber_2, 1.);
	this->conductance.setValue(this->nodeNumber_2, this->nodeNumber_1, 1.);
	this->conductance /= this->resistance;
}

double LinResistor::getCurrent(Vector voltags){
	Vector buffer = this->conductance * voltags;
	return buffer.getValue(this->nodeNumber_2);
}

Matrix LinResistor::getConductivity(void){
	return this->conductance;
}


int LinResistor::getElemNum(){
	return this->elNumber;
}
