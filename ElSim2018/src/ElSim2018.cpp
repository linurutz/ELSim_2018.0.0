//============================================================================
// Name        : ElSim2018.cpp
// Author      : Jörn Rutz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "mathmatics/vector.hpp"
#include "mathmatics/matrix.hpp"
#include "linear/linresistor.cpp"

using namespace std;

int main() {
	double voltages[] = {0, 12, 8};

	Vector voltagesVect = *(new Vector(voltages, 3));

	LinResistor R1 = *(new LinResistor(1, 100., 1, 2));

	R1.setResistance(220);

	Matrix mat = R1.getConductivity;

	cout << mat.getLength() << "\n\n";

	for(int i = 0; i < 7; i++){
		cout << mat.getValue(i,0);
		for(int j = 1; j < 7; j++){
			cout << "\t" << mat.getValue(i, j);
		}
		cout << "\n";
	}

	cout << R1.getCurrent(voltagesVect) << "\n\n";

	return 0;
}
