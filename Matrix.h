#pragma once
#include <iostream>
using namespace std;
class Matrix {
private:
	int m_row, m_col;
	int* m_arr;
	
public:
	Matrix();
	Matrix(int row, int col);
	/*~Matrix();*/

	void sortRow(int rowIndex);
	void sortCol(int colIndex);

	bool equalto(Matrix& M);

	Matrix& operator=(Matrix& M);
	Matrix operator+(Matrix& M);

	friend istream& operator >> (istream& input, Matrix& M);
	friend ostream& operator << (ostream& output, const Matrix& M);
};