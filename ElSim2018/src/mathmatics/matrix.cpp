/*
 * matrix.cpp
 *
 *  Created on: 26.04.2018
 *      Author: linurutz
 */


#include "matrix.hpp"

Matrix::Matrix(int len){
	this->length = len;
	this->matrix = new double*[len];
	for(int runv = 0; runv < this->length; runv++){
		this->matrix[runv] = new double[len];
	}
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			this->matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(Vector[], int){
  //TODO: not yet implemented
}

void Matrix::setValue(int rowNum, int colNum, double inVal){
	if((this->length > rowNum) && (this->length > colNum)){
		this->matrix[rowNum][colNum] = inVal;
	}
}


int Matrix::getLength(void){
	return this->length;
}

double Matrix::getValue(int rowNum, int colNum){
	if((rowNum < this->length) && (colNum < this->length)){
		return this->matrix[rowNum][colNum];
	}
	else
	{
		return 0;
	}
}

Vector Matrix::getRow(int rowNum){
	if(rowNum < this->length){
		Vector* res = new Vector(this->matrix[rowNum], this->length);
		return *res;
	}
	else
	{
		return *(new Vector(this->length));
	}
}

Matrix Matrix::operator+(Matrix addMat){
	int maxLength = addMat.getLength();
	if(this->length > maxLength){
		maxLength = this->length;
	}
	Matrix *res = new Matrix(maxLength);
	for(int i = 0; i < maxLength; i++){
		for(int j = 0; j < maxLength; j++){
			res->setValue(i,j,this->getValue(i,j) + addMat.getValue(i,j));
		}
	}
	return *res;
}

Matrix Matrix::operator+=(Matrix addMat){
	int maxLength = addMat.getLength();
	if(this->length > maxLength){
		for(int i = 0; i < addMat.getLength(); i++){
			for(int i = 0; i < maxLength; i++){
				for(int j = 0; j < maxLength; j++){
					this->matrix[i][j] += addMat.getValue(i,j);
				}
			}
		}
	}
	else
	{
		Matrix *oldMat = new Matrix(this->length);
		oldMat->matrix = this->matrix;
		this->length = maxLength;
		this->matrix = new double*[maxLength];
		for(int runv = 0; runv < this->length; runv++){
			this->matrix[runv] = new double[maxLength];
		}
		for(int i = 0; i < addMat.getLength(); i++){
			for(int i = 0; i < maxLength; i++){
				for(int j = 0; j < maxLength; j++){
					this->matrix[i][j] = oldMat->getValue(i,j) + addMat.getValue(i,j);
				}
			}
		}
	}
	return *this;
}

Matrix Matrix::operator-(Matrix subMat){
	int maxLength = subMat.getLength();
	if(this->length > maxLength){
		maxLength = this->length;
	}
	Matrix *res = new Matrix(maxLength);
	for(int i = 0; i < maxLength; i++){
		for(int j = 0; j < maxLength; j++){
			res->setValue(i,j,this->getValue(i,j) - subMat.getValue(i,j));
		}
	}
	return *res;
}

Matrix Matrix::operator-=(Matrix subMat){
	int maxLength = subMat.getLength();
	if(this->length > maxLength){
		for(int i = 0; i < subMat.getLength(); i++){
			for(int i = 0; i < maxLength; i++){
				for(int j = 0; j < maxLength; j++){
					this->matrix[i][j] -= subMat.getValue(i,j);
				}
			}
		}
	}
	else
	{
		Matrix *oldMat = new Matrix(this->length);
		oldMat->matrix = this->matrix;
		this->length = maxLength;
		this->matrix = new double*[maxLength];
		for(int runv = 0; runv < this->length; runv++){
			this->matrix[runv] = new double[maxLength];
		}
		for(int i = 0; i < subMat.getLength(); i++){
			for(int i = 0; i < maxLength; i++){
				for(int j = 0; j < maxLength; j++){
					this->matrix[i][j] = oldMat->getValue(i,j) - subMat.getValue(i,j);
				}
			}
		}
	}
	return *this;
}

Matrix Matrix::operator*(double scalar){
	Matrix *res = new Matrix(this->length);
	for(int i = 0; i < this->length; i++){
		for(int j = 0; j < this->length; j++){
			res->matrix[i][j] = this->matrix[i][j] * scalar;
		}
	}
	return *res;
}

Matrix operator*(double scalar, Matrix mulMat){
	Matrix *res = new Matrix(mulMat.length);
	for(int i = 0; i < mulMat.getLength(); i++){
		for(int j = 0; j < mulMat.getLength(); j++){
			res->matrix[i][j] = mulMat.getValue(i,j) * scalar;
		}
	}
	return *res;
}

Matrix Matrix::operator*=(double scalar){
	for(int i = 0; i < this->length; i++){
		for(int j = 0; j < this->length; j++){
			this->matrix[i][j] *= scalar;
		}
	}
	return *this;
}

Matrix Matrix::operator/(double scalar){
	Matrix *res = new Matrix(this->length);
	for(int i = 0; i < this->length; i++){
		for(int j = 0; j < this->length; j++){
			res->matrix[i][j] = this->matrix[i][j] / scalar;
		}
	}
	return *res;
}

Matrix Matrix::operator/=(double scalar){
	for(int i = 0; i < this->length; i++){
		for(int j = 0; j < this->length; j++){
			this->matrix[i][j] /= scalar;
		}
	}
	return *this;
}

Matrix Matrix::operator*(Matrix mulMat){
	int minLength = mulMat.getLength();
	if(this->length < minLength){
		minLength = this->length;
	}
	Matrix *res = new Matrix(minLength);
	for(int i = 0; i < minLength; i++){
		for(int j = 0; j < minLength; j++){
			res->matrix[i][j] = 0;
			for(int k = 0; k < minLength; k++){
				res->matrix[i][j] += this->matrix[i][k] * mulMat.getValue(k,j);
			}
		}
	}
	return *res;
}

Vector Matrix::operator*(Vector mulVect){
	Vector *res = new Vector(this->length);
	for(int i = 0; i < this->length; i++){
		Vector buffer = *(new Vector(this->matrix[i], this->length));
		res->setValue(i, buffer * mulVect);
	}
	return *res;
}

Vector Matrix::gaussJordan(Vector solVec){
	Vector *res = new Vector(this->length); //Result

	Matrix* buffer = new Matrix(this->length); //MatrixSteps
	//The first row of the matrix is normated including the result
	double diaVal = this->matrix[0][0];
	if(diaVal == 0){diaVal = 0.0001;}
	for(int i = 0; i < this->length; i++){
		buffer->matrix[0][i] = this->matrix[0][i] / diaVal;
	}
	res->setValue(0, solVec.getValue(0) / diaVal);
	//The other lines are stored reduced by the scaled first line
	for(int i = 1; i < this->length; i++){
		diaVal = this->matrix[i][0];
		for(int j = 0; j < this->length; j++){
			buffer->matrix[i][j] = this->matrix[i][j] - diaVal * buffer->matrix[0][j];
		}
		res->setValue(i, solVec.getValue(i) - diaVal * res->getValue(0));
	}
	//Now this is done for all lines
	for(int i = 1; i < this->length; i++){
		diaVal = buffer->matrix[i][i];
		if(diaVal == 0){diaVal = 0.0001;}
		for(int j = 0; j < this->length; j++){
			buffer->matrix[i][j] /= diaVal;
		}
		res->setValue(i, res->getValue(i) / diaVal);
		for(int j = 0; j < this->length; j++){
			if(i != j){
				diaVal = buffer->matrix[j][i];
				for(int k = 0; k < this->length; k++){
					buffer->matrix[j][k] -= diaVal * buffer->matrix[i][k];
				}
				res->setValue(j, res->getValue(j) - diaVal * res->getValue(i));
			}
		}
	}
	return *res;
}


