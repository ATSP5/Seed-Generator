#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

double Floor(double number_)
{
	double fraction_ = number_;
	double integer_ = 0;
	fraction_ = modf(number_, &integer_);
	if (number_ >= 0.0)
	{
		return integer_;
	}
	else
	{
		return integer_ - 1.0;
	}

}

double Random(double &kernel_)
{
	double M = 2147483647.0;
	double A = 16807.0;
	double Q = 127773.0;
	double R = 2836;
	double h = Floor(kernel_ / Q);
	kernel_ = A * (kernel_ - Q * h) - R * h;
	if (kernel_ < 0.0)
	{
		kernel_ += M;
	}
	return kernel_ / M ;
}

double RandomMM(double min, double max, double& kernel_)
{
	return Random(kernel_) * (max - min) + min;
}


int main()
{
	double kernel_ = time(NULL);
	double random_value_;
	ofstream file;
	string txt_="", filename_="";
	for (int i = 0; i < 10; i++)
	{
		txt_ += "<L" + to_string(i + 1) + "> ";
		for (int q = 0; q < 50; q++)
		{
			random_value_ = RandomMM(1000000,9999999, kernel_);
			txt_ += to_string(random_value_)+" ";
		}
		txt_ += "<EOL" + to_string(i + 1) + "> \n";
	}
	txt_ += "<EOF>";
	cout << "Specify filename.smf" << endl;
	cin >> filename_;
	file.open(filename_);
	file << txt_;
	file.close();
}