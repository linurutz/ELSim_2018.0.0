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
		//First the next element and the node element are generated
		Voltages* nextVol = new Voltages;
		nextVol->voltagEl = voltElem;
		nextVol->next = 0;
		// If the element is a root element (attached to node 0) it is set to the start of the
		// array. All followers are automatically after it.
		if(voltElem->getPotNode() == 0){
				// The element is turned around
				int newRefNode = voltElem->getPotNode();
				int newPotNode = voltElem->getRefNode();
				double newVoltage = -voltElem->getVoltage();
				voltElem->setPotNode(newPotNode);
				voltElem->setRefNode(newRefNode);
				voltElem->setVoltage(newVoltage);
		}
		// The starting and end point are stored
		int startNode = nextVol->voltagEl->getRefNode(); int endNode = nextVol->voltagEl->getPotNode();
		// The voltages are stored one by one in a separate array
		Voltages* buffer = this->voltages; Voltages* bufferStart = buffer;
		Voltages* nextVolEnd = nextVol;
		Voltages* volNode = buffer->next;
		buffer->next = 0;
		char elementFound = 0x00; // 0xXY - X inserted? Y found at start, at End in the middle
		while(volNode->next != 0){
			// for each element it is tested, if it is part of a branch. This is the case, when
			// the ref node is the pot node of the last element in the buffer.
			if(volNode->voltagEl->getRefNode() != buffer->voltagEl->getPotNode()){
				// it must be seen if the new element is part of the current branch.
				// There are four cases:
				// a) The element is connected to the first node -> branch is attached to the new element
				// b) The element is connected to the last node -> new element is attached to the branch
				// except if the element is a zero element. in that case the branch is turned and
				// attached to the new element
				// c) The element is not connected: the element is attached to the end of the buffer
				// d) The element is attached within the branch. If it is a zero element, the branch is
				// split in two, the first part is turned around
				if((elementFound & 0x0F) == 0x01){ // case a
					nextVolEnd->next = bufferStart;
					nextVolEnd = buffer;
					elementFound |= 0x10;
					elementFound &= 0xF0;
				}
				else if((buffer->voltagEl->getPotNode() == startNode) || (buffer->voltagEl->getPotNode() == endNode)){ // case b)
					if((nextVol->voltagEl->getRefNode() == 0) || (elementFound & 0xF0)){

					}
					else{

					}
					elementFound |= 0x10;
					elementFound &= 0xF0;
				}
				else if(((elementFound & 0x0F) == 0x02) && (startNode == 0)){ // case d) with zero element

				}
				else{

				}
				buffer = volNode;
				bufferStart = buffer;
				if(buffer->voltagEl->getRefNode() == endNode){
					elementFound |= 0x01;
				}
				else if((buffer->voltagEl->getRefNode() == startNode) && (startNode != 0)){
					if(!(elementFound & 0xF0)){
						buffer->voltagEl->setRefNode(endNode);
						buffer->voltagEl->setPotNode(startNode);
						int buffnode = startNode;
						startNode = endNode;
						endNode = buffnode;
						buffer->voltagEl->setVoltage(-buffer->voltagEl->getVoltage());

					}
					elementFound |= 0x01;
				}
			}
			else{
				buffer->next = volNode;
				buffer = buffer->next;

			}
			volNode = volNode->next;
			buffer->next = 0;
		}
	}
}

void LinNetwork::optimizeSystem(){

}

void LinNetwork::solveSystem(){
	// first the voltages are sorted


}

Vector LinNetwork::getNodalVoltages(){
	return *(new Vector(5));
}

Matrix LinNetwork::getConductance(){
	return this->conductance;
}

