/*
 * linvoltage.cpp
 *
 *  Created on: 27.04.2018
 *      Author: linurutz
 */

#include "linvoltage.hpp"

LinVoltage::LinVoltage(int elNm){
	this->elNum = elNm;
	this->voltag = 0.;
	this->refNode = 0;
	this->potNode = 1;
}

LinVoltage::LinVoltage(int elNm, int rNode, int pNode){
	this->elNum = elNm;
	this->voltag = 0.;
	this->refNode = rNode;
	this->potNode = pNode;
}

LinVoltage::LinVoltage(int elNm, double voltg, int rNode, int pNode){
	this->elNum = elNm;
	this->voltag = voltg;
	this->refNode = rNode;
	this->potNode = pNode;
}

void LinVoltage::setRefNode(int nNode){
	this->refNode = nNode;
}

void LinVoltage::setPotNode(int nNode){
	this->potNode = nNode;
}

void LinVoltage::setVoltage(double voltg){
	this->voltag = voltg;
}

double LinVoltage::getVoltage(){
	return this->voltag;
}

int LinVoltage::getElemNum(){
	return this->elNum;
}

int LinVoltage::getRefNode(){
	return this->refNode;
}

int LinVoltage::getPotNode(){
	return this->potNode;
}

int LinVoltage::getMaxNode(){
	if(this->potNode > this->refNode){
		return this->potNode;
	}
	else{
		return this->refNode;
	}
}

int LinVoltage::getMinNode(){
	if(this->potNode > this->refNode){
		return this->refNode;
	}
	else{
		return this->potNode;
	}
}


