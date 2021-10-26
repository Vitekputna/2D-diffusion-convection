#pragma once
#include <string>
#include <iostream>

class data
{
private:
	int rows, collums;
	std::string name;

public:
	double* data_p;
	data();
	data(int num_row, int num_coll);
	data(int num_row, int num_coll, std::string name);
	~data();
	data(const data& other);

	void operator=(data& other);
	std::shared_ptr<data> operator+(data& other);
	std::shared_ptr<data> operator*(double scalar);

	double& get(int row, int collum);

	std::shared_ptr<data> collum(int collum);
	std::shared_ptr<data> row(int row);
	//void boundary(const char site, data& BC);

	void print_to_file(int num_rows);
	void print_to_file(std::string path);

	friend void W_2_variables(data& W, int t);
};
