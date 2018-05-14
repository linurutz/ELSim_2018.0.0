/*
 * vector.cpp
 *
 *  Created on: 26.04.2018
 *      Author: linurutz
 */

#include "vector.hpp"
/*
Vector::Vector(){
	Vector(10);
}*/

Vector::Vector(int len){
	this->length = len;
	this->vector = new double[len];
	for(int i = 0; i < len; i++){
		this->vector[i] = 0;
	}
}

Vector::Vector(double vectArr[], int len){
	this->vector = vectArr;
	this->length = len;
}

void Vector::setValue(int num, double val){
	this->vector[num] = val;
}

int Vector::getLength(){
	return this->length;
}


double Vector::getValue(int num){
	if(this->length > num){
		return this->vector[num];
	}
	else{
		return 0;
	}
}

Vector Vector::operator+(Vector addVect){
	int maxLength = addVect.getLength();
	if(this->length > maxLength){ maxLength = this->length;}
	Vector* res = new Vector(maxLength);
	for(int i = 0; i < maxLength; i++){
		if(i < this->length){
			res->setValue(i, this->vector[i] + addVect.getValue(i));
		}
		else{
			res->setValue(i, addVect.getValue(i));
		}
	}
	return *res;
}

Vector Vector::operator+=(Vector addVect){
	int maxLength = addVect.getLength();
	if(this->length > maxLength){
		for(int i = 0; i < maxLength; i++){
			this->vector[i] += addVect.getValue(i);
		}
	}
	else{
		Vector *oldVect = new Vector(this->length);
		oldVect->vector = this->vector;
		this->length = maxLength;
		this->vector = new double[maxLength];
		for(int i = 0; i < maxLength; i++){
			this->vector[i] = addVect.getValue(i) + oldVect->getValue(i);
		}
	}
	return *this;
}

Vector Vector::operator-(Vector subtVect){
	int maxLength = subtVect.getLength();
	if(this->length > maxLength){ maxLength = this->length;}
	Vector* res = new Vector(maxLength);
	for(int i = 0; i < maxLength; i++){
		if(i < this->length){
			res->setValue(i, this->vector[i] + subtVect.getValue(i));
		}
		else{
			res->setValue(i, subtVect.getValue(i));
		}
	}
	return *res;
}

Vector Vector::operator-=(Vector subtVect){
	int maxLength = subtVect.getLength();
	if(this->length > maxLength){
		for(int i = 0; i < maxLength; i++){
			this->vector[i] += subtVect.getValue(i);
		}
	}
	else{
		Vector *oldVect = new Vector(this->length);
		oldVect->vector = this->vector;
		this->length = maxLength;
		this->vector = new double[maxLength];
		for(int i = 0; i < maxLength; i++){
			this->vector[i] = subtVect.getValue(i) + oldVect->getValue(i);
		}
	}
	return *this;
}

Vector Vector::operator*(double scalar){
	Vector *res = new Vector(this->length);
	for(int i = 0; i < this->length; i++){
		res->setValue(i, scalar * this->vector[i]);
	}
	return *res;
}

Vector operator*(double scalar, Vector mulVect){
	Vector* res = new Vector(mulVect.getLength());
	for(int i = 0; i < mulVect.getLength(); i++){
		res->setValue(i, scalar * mulVect.getValue(i));
	}
	return *res;
}

Vector Vector::operator*=(double scalar){
	for(int i = 0; i < this->length; i++){
		this->vector[i] *= scalar;
	}
	return *this;
}

Vector Vector::operator/(double scalar){
	Vector *res = new Vector(this->length);
	for(int i = 0; i < this->length; i++){
		res->setValue(i, this->vector[i] / scalar);
	}
	return *res;
}

Vector Vector::operator/=(double scalar){
	for(int i = 0; i < this->length; i++){
		this->vector[i] /= scalar;
	}
	return *this;
}

double Vector::operator*(Vector mulVect){
	double res = 0;
	int minLength = mulVect.getLength();
	if(this->length < minLength){
		minLength = this->length;
	}
	for(int i = 0; i < minLength; i++){
		res += this->vector[i] * mulVect.getValue(i);
	}
	return res;
}



