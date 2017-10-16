#pragma once
#include "MathObject.h"

class MatrixObject : public MathObject<MatrixObject> {

public:
	MatrixObject();
	MatrixObject(int, int, int** );
	MatrixObject(MatrixObject &);
	~MatrixObject() { delete[] matrix; }

	MatrixObject operator+(MatrixObject& x);
	MatrixObject operator-(MatrixObject& x);
	MatrixObject operator*(MatrixObject& x);
	MatrixObject operator=(MatrixObject& x);

	int getM();
	int getN();
	int **getMatrix() { return matrix; }
	int getMember(int, int);
	void setMember(int, int, int);

protected:
	int **matrix;
	int m;
	int n;

private:
	void copyArray(int **);
};