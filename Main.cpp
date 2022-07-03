#include "Matrix.h"
#include <vector>
int main()
{
	int row = rand() % 12 - 2;
	int col = rand() % 12 - 2;
	cout << "\nNumber of row in Matrix: "<< row;
	cout << "\nNumber of column in Matrix: "<< col;
	Matrix M(row, col);
	cin >> M;

	for (int i = 0; i < row; i++) M.sortRow(i);
	cout << "\nMatrix after sorted rows:";
	cout << M;

	for (int j = 0; j < col; j++) M.sortCol(j);
	cout << "\nMatrix after sorted columns:";
	cout << M;

	//cout << "\nEnter number of row in Matrix 2: "; cin >> row;
	//cout << "Enter number of column in Matrix 2: "; cin >> col;
	//Matrix N(row, col);

	//cout << "\nMatrix M: \n";
	//cin >> M;
	//cin >> N;
	//
	//Matrix A;
	//A = M;
	//cout << "\n\nMatrix A: \n";
	//cout << A;
	//*(M.m_arr) = 0;
	//cout << "\n\nMatrix A after M changed: \n";
	//cout << A;
	//if (M.equalto(N))
	//{
	//	cout << M + N;
	//}
	//else cout << "\nColumn or Row number is different!\n";

	return 0;
}