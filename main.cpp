#include "MatrixObject.h"
#include<iostream>

using namespace::std;

void main(void)
{
	//int arr1[2][2] = { { 1, 2 }, { 3, 4} };
	//int arr2[2][1] = { { 5 }, { 6} };
	int **arr1 = new int*[2];
	arr1[0] = new int[2];
	arr1[1] = new int[2];
	arr1[0][0] = 1;
	arr1[0][1] = 2;
	arr1[1][0] = 3;
	arr1[1][1] = 4;
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cout << arr1[i][j];
	cout << "\n";

	int **arr2 = new int*[2];
	arr2[0] = new int;
	arr2[1] = new int;
	arr2[0][0] = 5;
	arr2[1][0] = 6;
	for (int i = 0; i < 2; i++)
		cout << arr2[i][0];
	cout << "\n";

	MatrixObject matrix1 = MatrixObject(2, 2, arr1);
	MatrixObject matrix2 = MatrixObject(2, 1, arr2);

	MatrixObject matrix3 = matrix1 * matrix2;

	for (int i = 0; i < 2; i++)
		cout << matrix3.getMember(i, 0);

	cin.get();
}