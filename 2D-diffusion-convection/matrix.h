#pragma once
#include <stdio.h>
#include <string>

template<typename T>
class matrix
{
public:
	int rows;
	int collums;
	T* data_p;

	matrix();
	~matrix();
	matrix(int rows, int collums);
	T& operator[](const int pos);
	matrix<T> operator+(matrix<T>& other);
	matrix<T> operator-(matrix<T>& other);
	matrix<T> operator*(matrix<T>& other);
	matrix<T> operator*(int number);
	matrix<T> operator*(float number);
	matrix(const matrix& A);
	T& get(const int row, const int collum);
	T* row(const int row);
	T* collum(const int collum);
	void print();
	void print_to_file(std::string mame);

};

template<typename T>
matrix<T> operator*(const int number, matrix<T>& rhs)
{
	return rhs * number;
}

template<typename T>
matrix<T> diag(matrix<T>& other)
{
	matrix<T> output(other.collums, 1);

	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.collums; j++)
		{
			if (i == j)
			{
				output.get(i, 0) = other.get(i, j);
			}
		}
	}

	return output;
}

template<typename T>
matrix<T> diagm(matrix<T>& other)
{
	matrix<T> output(other.collums, other.collums);

	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.collums; j++)
		{
			if (i == j)
			{
				output.get(i, j) = other.get(i, j);
			}
		}
	}

	return output;
}

template<typename T>
matrix<T> upper(matrix<T>& other)
{
	int m_size = std::min(other.collums, other.rows);

	matrix<T> output(m_size, m_size);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (i != j && i > j)
			{
				output.get(i, j) = other.get(i, j);
			}
		}
	}

	return output;
}

template<typename T>
matrix<T> lower(matrix<T>& other)
{
	int m_size = std::min(other.collums, other.rows);

	matrix<T> output(m_size, m_size);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (i != j && i < j)
			{
				output.get(i, j) = other.get(i, j);
			}
		}
	}

	return output;
}





