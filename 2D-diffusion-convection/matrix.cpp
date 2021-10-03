#include "matrix.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

template<typename T>
inline matrix<T>::matrix()
{
	rows = 0;
	collums = 0;
	data_p = NULL;
}

template<typename T>
matrix<T>::~matrix()
{
	free(data_p);
}

template<typename T>
matrix<T>::matrix(int rows, int collums)
{
	this->rows = rows;
	this->collums = collums;

	data_p = reinterpret_cast<T*>(calloc(rows * collums, sizeof(T)));
}

template<typename T>
T& matrix<T>::operator[](const int pos)
{
	T* address = data_p;
	return address[pos];
}

template<typename T>
matrix<T> matrix<T>::operator+(matrix<T>& other)
{
	matrix<T> output(other.rows, other.collums);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
		{
			output.get(i, j) = this->get(i, j) + other.get(i, j);
		}
	}

	return output;
}

template<typename T>
matrix<T> matrix<T>::operator-(matrix<T>& other)
{
	matrix<T> output(other.rows, other.collums);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
		{
			output.get(i, j) = this->get(i, j) - other.get(i, j);
		}
	}

	return output;
}

template<typename T>
matrix<T> matrix<T>::operator*(matrix<T>& other)
{
	if (this->collums != other.rows)
	{
		std::cout << "wrong matrix dimentions" << std::endl;
		matrix<T> E;
		return E;
	}

	int num_of_sums = this->collums;

	int o_rows = this->rows;
	int o_collums = other.collums;

	matrix<T> output(o_rows, o_collums);

	for (int i = 0; i < o_rows; i++)
	{
		for (int j = 0; j < o_collums; j++)
		{
			for (int k = 0; k < num_of_sums; k++)
			{

				output.get(i, j) += this->get(i, k) * other.get(k, j);
			}
		}
	}

	return output;
}

template<typename T>
matrix<T> matrix<T>::operator*(int number)
{
	matrix<T> output(rows, collums);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
		{
			output.get(i, j) = number * this->get(i, j);
		}
	}

	return output;
}

template<typename T>
matrix<T> matrix<T>::operator*(float number)
{
	return matrix<T>();
}

template<typename T>
matrix<T>::matrix(const matrix& A)
{
	rows = A.rows;
	collums = A.collums;



	data_p = reinterpret_cast<T*>(malloc(rows * collums * sizeof(T)));

	if (data_p)
	{
		std::memcpy(data_p, A.data_p, rows * collums * sizeof(T));
	}
}

template<typename T>
T& matrix<T>::get(const int x, const int y)
{
	T* address = data_p;
	return address[x * collums + y];
}

template<typename T>
void matrix<T>::print()
{
	std::cout << "matrix:" << typeid(this).name() << std::endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
		{
			std::cout << this->get(i, j) << "\t";
		}
		std::cout << std::endl;
	}
}

template<typename T>
void matrix<T>::print_to_file(std::string name)
{
	std::ofstream file(name);

	int r = 1;
	for (int i = 0; i < rows * collums; i++)
	{
		file << this->data_p[i] << " ";

		if (i == (collums * r - 1))
		{
			file << "\n";
			r++;
		}
	}
	file.close();
}

template<typename T>
T* matrix<T>::row(const int row)
{
	return data_p + row * collums;
}

template<typename T>
T* matrix<T>::collum(const int collum)
{
	std::cout << "no worky worky" << std::endl;
	return 0;
}


template class matrix<int>;
template class matrix<char>;
template class matrix<float>;
template class matrix<double>;