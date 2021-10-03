#include <stdio.h>
#include <iostream>
#include "matrix.h"

const double k = 1;
const double dx = 0.01;
const double A = dx;
const double u = 1;
const double rho = 1;

double ap = 4 * k * A / dx;
double an = k * A / dx;
double as = k * A / dx;
double ae = k * A / dx - rho * u / 2;
double aw = k*A/dx + rho * u / 2;

const int x_size = 100;
const int y_size = 100;
const int iterations = 1000;

std::string name = "data.txt";

int main()
{
	matrix<double> phi(x_size, y_size);
	matrix<double> u(x_size, y_size);
	matrix<double> x(1, x_size);

	for (int i = 0; i < x_size; i++)
	{
		x.get(0, i) = i * dx;
	}

	for (int i = 0; i < y_size; i++)
	{
		if (x.get(0,i) > 0 && x.get(0, i) < 0.3)
		{
			phi.get(i, 0) = 1;
		}
	}


	for (int i = 0; i < x_size;i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			u.get(j, i) = 8 / 3 * x.get(0, j) * (1 - x.get(0, j));
		}
	}

	//phi.print_to_file(name);

	for (int k = 0; k < iterations; k++)
	{
		for (int i = 1; i < x_size-1; i++)
		{
			for (int j = 1; j < y_size-1; j++)
			{
				phi.get(j, i) = an / ap * phi.get(j + 1, i) + as / ap * phi.get(j - 1, i) + ae / ap * phi.get(j, i + 1) + aw / ap * phi.get(j, i - 1);
			}
		}
	}
	phi.print_to_file(name);
}