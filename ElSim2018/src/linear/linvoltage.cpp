/*
 * linvoltage.cpp
 *
 *  Created on: 27.04.2018
 *      Author: linurutz
 */

#include "linvoltage.hpp"

LinVoltage::LinVoltage(int elNm){
	this->elementNumber = elNm;
	this->voltages = 0.;
	this->referenceNode = 0;
	this->potentialNode = 1;
}

LinVoltage::LinVoltage(int elNm, int rNode, int pNode){
	this->elementNumber = elNm;
	this->voltages = 0.;
	this->referenceNode = rNode;
	this->potentialNode = pNode;
}

LinVoltage::LinVoltage(int elNm, double voltg, int rNode, int pNode){
	this->elementNumber = elNm;
	this->voltages = voltg;
	this->referenceNode = rNode;
	this->potentialNode = pNode;
}

void LinVoltage::setRefNode(int nNode){
	this->referenceNode = nNode;
}

void LinVoltage::setPotNode(int nNode){
	this->potentialNode = nNode;
}

void LinVoltage::setVoltage(double voltg){
	this->voltages = voltg;
}

double LinVoltage::getVoltage(){
	return this->voltages;
}

int LinVoltage::getElemNum(){
	return this->elementNumber;
}

int LinVoltage::getRefNode(){
	return this->referenceNode;
}

int LinVoltage::getPotNode(){
	return this->potentialNode;
}

int LinVoltage::getMaxNode(){
	if(this->potentialNode > this->referenceNode){
		return this->potentialNode;
	}
	else{
		return this->referenceNode;
	}
}

int LinVoltage::getMinNode(){
	if(this->potentialNode > this->referenceNode){
		return this->referenceNode;
	}
	else{
		return this->potentialNode;
	}
}


