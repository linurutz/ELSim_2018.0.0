/*
 * linnetwork.cpp
 *
 *  Created on: 27.04.2018
 *      Author: linurutz
 */


#include "linnetwork.hpp"

LinNetwork::LinNetwork() : conductance(5), reorder(5), inputVoltage(5), nodalVoltage(5){
	this->voltages = 0;
	this->resistors = 0;
}

// The resistors are stored chronologically
void LinNetwork::addResistor(LinResistor* resElem){
	if(this->resistors == 0){
		this->resistors = new Resistors;
		this->resistors->resistorEl = resElem;
		this->resistors->next = 0;
	}
	else{
		Resistors* resNode = this->resistors;
		Resistors* nextRes = new Resistors;
		nextRes->resistorEl = resElem;
		nextRes->next = 0;
		while(resNode->next != 0){
			resNode = resNode->next;
		}
		resNode->next = nextRes;
	}
}

void LinNetwork::addVoltage(LinVoltage* voltElem){
	// The voltages are stored chronologically
	if(this->voltages == 0){
		this->voltages = new Voltages;
		this->voltages->voltagEl = voltElem;
		if(this->voltages->voltagEl->getPotNode() == 0){
			int bufferNodeNum = this->voltages->voltagEl->getPotNode();
			this->voltages->voltagEl->setPotNode(this->voltages->voltagEl->getRefNode());
			this->voltages->voltagEl->setRefNode(bufferNodeNum);
			this->voltages->voltagEl->setVoltage(-this->voltages->voltagEl->getVoltage());
		}
		this->voltages->next = 0;
	}
	else{
		Voltages* buffer = this->voltages;
		while(buffer != 0){
			buffer = buffer->next;
		}
		Voltages* newElem = new Voltages;
		newElem->voltagEl = voltElem;
		if(newElem->voltagEl->getPotNode() == 0){
			int bufferNodeNum = newElem->voltagEl->getPotNode();
			newElem->voltagEl->setPotNode(newElem->voltagEl->getRefNode());
			newElem->voltagEl->setRefNode(bufferNodeNum);
			newElem->voltagEl->setVoltage(-newElem->voltagEl->getVoltage());
		}
		newElem->next = 0;
		buffer = newElem;
	}
}

void LinNetwork::optimizeSystem(){

}

void LinNetwork::solveSystem(){
	// first the Nodes have to be acquired from the resistors and the voltages
	struct Nodearray{
		int nodeNumber;
		Nodearray* next;
	};
	Nodearray* freeNodes = 0;
	Nodearray* voltageNodes = 0;
	Resistors* resRun = this->resistors;
	//Therefore the conductivity matrix is built up
	Matrix conduct = resRun->resistorEl->getConductivity();
	resRun = resRun->next;
	while(resRun != 0){
		conduct += resRun->resistorEl->getConductivity();
		resRun = resRun->next;
	}
	// Now the matrix is searched for non zero elements
	Nodearray* nodesRun = freeNodes;
	for(int i = 0; i < conduct.getLength(); i++){
		if(conduct.getValue(i,i) != 0){
			if(freeNodes == 0){
				freeNodes = new Nodearray;
				freeNodes->nodeNumber = i;
				freeNodes->next = 0;
				nodesRun = freeNodes;
			}
			else{
				nodesRun->next = new Nodearray;
				nodesRun->next->nodeNumber = i;
				nodesRun = nodesRun->next;
				nodesRun->next = 0;
			}
		}
	}
	// Now the resistor nodes are acquired. Next the voltage nodes must be aquired
	nodesRun = voltageNodes;
	Voltages* buffer = this->voltages;
	while(buffer != 0){
		buffer = buffer->next;
	}
}

Vector LinNetwork::getNodalVoltages(){
	return *(new Vector(5));
}

Matrix LinNetwork::getConductance(){
	Resistors* runResist = this->resistors;
	this->conductance = runResist->resistorEl->getConductivity();
	runResist = runResist->next;
	while(runResist != 0){
		this->conductance += runResist->resistorEl->getConductivity();
		runResist = runResist->next;
	}
	return this->conductance;
}

