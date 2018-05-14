/*
 * matrix.hpp
 *
 *  Created on: 26.04.2018
 *      Author: linurutz
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include "vector.hpp"

class Matrix{
protected:
	double** matrix;
	int length;

public:
	//Matrix();
	Matrix(int);
	Matrix(Vector[], int);
	void setValue(int, int, double);
	Matrix operator+(Matrix);
	Matrix operator+=(Matrix);
	Matrix operator-(Matrix);
	Matrix operator-=(Matrix);
	Matrix operator*(double);
	friend Matrix operator*(double, Matrix);
	Matrix operator*=(double);
	Matrix operator/(double);
	Matrix operator/=(double);
	Matrix operator*(Matrix);
	Vector operator*(Vector);
	double getValue(int, int);
	Vector getRow(int);
	Vector gaussJordan(Vector);
	int getLength(void);

};


#endif /* MATRIX_HPP_ */
