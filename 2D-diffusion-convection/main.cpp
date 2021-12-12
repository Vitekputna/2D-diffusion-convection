#include <stdio.h>
#include <iostream>
#include "data.h"

double d = 1;
double dx = 0.01;
double A = dx;
double u = 1;
double rho = 1;

int from = 0;
int to = 0.3;

double ap, aw, ae, as, an;

int x_size = 100;
int y_size = 100;
int iterations = 1000;

std::string name = "data.txt";

int main()
{
	data phi(x_size, y_size);
	data x(1, x_size);

	for (int i = 0; i < x_size; i++)
	{
		x(i) = i * dx;
	}

	for (int i = 0; i < y_size; i++)
	{
		if (x(i) > from && x(i) < to)
		{
			phi(i, 0) = 1;
		}
	}


	for (int k = 0; k < iterations; k++)
	{
		for (int i = 1; i < x_size-1; i++)
		{
			for (int j = 1; j < y_size-1; j++)
			{
				u = 4 * x(i) * (1 - x(i));

				ap = 4 * d * A / dx;
				an = d * A / dx;
				as = d * A / dx;
				ae = d * A / dx - rho * u / 2;
				aw = d * A / dx + rho * u / 2;

				phi(j, i) = an / ap * phi(j + 1, i) + as / ap * phi(j - 1, i) + ae / ap * phi(j, i + 1) + aw / ap * phi(j, i - 1);
			}
		}

		for (int j = 0; j < y_size; j++)
		{
			phi(j, x_size - 1) = phi(j, x_size - 2);
		}
	}
	phi.print_to_file(name);
	std::cout << "Done..." << std::endl;
}