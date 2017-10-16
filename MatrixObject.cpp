#include "MatrixObject.h"

using namespace::std;

MatrixObject::MatrixObject()
{
	m = n = 0;
	matrix = nullptr;
}

MatrixObject::MatrixObject(int rows, int cols, int **arr)
{
	m = rows;
	n = cols;
	matrix = arr;
}

MatrixObject::MatrixObject(MatrixObject &mo)
{
	this->n = mo.getN();
	this->m = mo.getM();

	this->copyArray(mo.getMatrix());
}

//basic matrix addition one matrix added to another
MatrixObject MatrixObject::operator+(MatrixObject& x)
{
	if (this->m != x.getM() || this->n != x.getN())
		throw "Matrix size mismatch.\n";

	int **arr = new int*[m];
	for (int i = 0; i < m; i++)
		*arr = new int[n];

	MatrixObject temp = MatrixObject(this->m, this->n, arr);

	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
			temp.setMember( i, j, this->matrix[i][j] + x.getMember(i, j));
	}

	return temp;
}

//reverse of matrix addition, matrix subtraction left minus right
MatrixObject MatrixObject::operator-(MatrixObject& x)
{
	if (this->m != x.getM() || this->n != x.getN())
		throw "Matrix size mismatch.\n";

	int **arr = new int*[m];
	for (int i = 0; i < m; i++)
		*arr = new int[n];

	MatrixObject temp = MatrixObject(this->m, this->n, arr);

	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
			temp.setMember(i, j, this->matrix[i][j] - x.getMember(i, j));
	}

	return temp;
}

//matrix multiplaction, matrix dot product
MatrixObject MatrixObject::operator*(MatrixObject& x)
{
	//Matrix dot product requires the columns of the leftmost matrix to align to the rows of the rightmost
	if ( this->getN() != x.getM() )
		throw "Matrix size mismatch.\n";

	// MxN * NxN2 = MxN2
	int rows = this->getM();
	int cols = x.getN();
	int line = 0;
	int **matrix = new int*[rows];

	//for each row, set up a number of columns
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	//row number
	for (int i = 0; i < rows; i++)
		//column number
		for (int j = 0; j < cols; j++)
		{
			//iteration through each row of matrix 1 by each column of matrix 2
			for (int k = 0; k < this->getN(); k++)
				line += this->getMember(i, k) * x.getMember(k, j);

			matrix[i][j] = line;
			line = 0;
		}

	MatrixObject temp = MatrixObject(rows, cols, matrix);

	return temp;
}
MatrixObject MatrixObject::operator=(MatrixObject & x)
{
	m = x.getM();
	n = x.getN();

	this->copyArray(x.getMatrix());

	return *this;
}

int MatrixObject::getM(){ return m; }
int MatrixObject::getN(){ return n; }

int MatrixObject::getMember(int row, int col)
{
	if (row >= m || row < 0 || col < 0 || col >= n)
		throw "Matrix size mismatch.\n";

	return matrix[row][col];
}

void MatrixObject::setMember(int row, int col, int val)
{
	if (row > m || row < 0 || col < 0 || col > n)
		throw "Matrix size mismatch.\n";

	this->matrix[row][col] = val;
}

void MatrixObject::copyArray(int **arr)
{
	delete[] this->matrix;
	matrix = new int*[this->m];
	for (int i = 0; i < this->m; i++)
		matrix[i] = new int[this->n];

	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			matrix[i][j] = arr[i][j];
		}
	}
}
