#include "Matrix.h"

Matrix::Matrix() {};
Matrix::Matrix(int row, int col):m_row(row),m_col(col)
{
	m_arr = new int[row*col];
};
//
//Matrix::~Matrix()
//{
//	for (int i = 0; i < m_row; i++) delete[] m_arr[i];
//	delete[] m_arr;
//};

bool Matrix::equalto(Matrix& M)
{
	if ((m_col == M.m_col) && (m_row == M.m_row)) return true;
	else return false;
};


void Matrix::sortRow(int rowIndex)
{
	int n = m_col + rowIndex * m_col;
	for (int i = rowIndex * m_col; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (m_arr[i] > m_arr[j]) swap(m_arr[i], m_arr[j]);
	}
};
void Matrix::sortCol(int colIndex)
{
	int n = colIndex + m_row * m_col;
	for (int i = colIndex; i < n - m_col; i += m_col)
	{
		for (int j = i + m_col; j < n; j += m_col)
			if (m_arr[i] > m_arr[j]) swap(m_arr[i], m_arr[j]);
	}
};

Matrix& Matrix::operator=(Matrix& M) {

	if (m_arr != nullptr) delete[] m_arr;

	m_row = M.m_row;
	m_col = M.m_col;
	m_arr = new int[m_row * m_col];

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_arr[i * m_col + j] = M.m_arr[i * m_col + j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(Matrix& M)
{
	Matrix Result(m_row, m_col);

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			Result.m_arr[i * m_col + j] = m_arr[i * m_col + j] + M.m_arr[i * m_col + j];
		}
	}
	return Result;
}

istream& operator >> (istream& input, Matrix& M)
{
	/*cout << "\nInput value of matrix:\n";
	for (int i = 0; i < M.m_row; i++)
	{
		for (int j = 0; j < M.m_col; j++)
		{
			input >> M.m_arr[i][j];
		}
		cout << "\n";
	}
	return input;*/
	//cout << "\nInput value of matrix:\n";

	cout << "\n";
	for (int i = 0; i < M.m_row * M.m_col; i++)
	{
		bool check = true;
		while (check)
		{
			check = false;
			M.m_arr[i] = rand() % (M.m_row * M.m_col) + 1;
			for (int k = 0; k < i; k++) 
				if (M.m_arr[i] == M.m_arr[k]) check = true;
		} 
		 cout << M.m_arr[i] << "\t";
		 if ((i + 1)%M.m_col == 0) cout << "\n";
	}
	return input;
}

ostream& operator << (ostream& output, const Matrix& M)
{
	cout << "\nValue of matrix:\n";
	for (int i = 0; i < M.m_row; i++)
	{
		for (int j = 0; j < M.m_col; j++)
		{
			output << M.m_arr[i * M.m_col + j];
			cout << "\t";
		}
		cout << "\n";
	}
	return output;
}