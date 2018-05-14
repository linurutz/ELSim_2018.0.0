/*
 * vector.hpp
 *
 *  Created on: 26.04.2018
 *      Author: linurutz
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

class Vector{
protected:
	double* vector;
	int length;

public:
	//Vector();
	Vector(int);
	Vector(double[], int);
	void setValue(int, double);
	Vector operator+(Vector);
	Vector operator+=(Vector);
	Vector operator-(Vector);
	Vector operator-=(Vector);
	Vector operator*(double);
	friend Vector operator*(double, Vector);
	Vector operator*=(double);
	Vector operator/(double);
	Vector operator/=(double);
	double operator*(Vector);
	double getValue(int);
	int getLength(void);
};


#endif /* VECTOR_HPP_ */
