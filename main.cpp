#include <cmath>
#include <iostream>
#include <iomanip> 
using namespace std;

double t[2][9] = { {  0.98,   1.36,   1.7,   1.99,   2.61,   2.65,   2.78,    2.89,   3.1},
					{ 0.7753, 0.9368, 1.0391, 1.1051, 1.2049, 1.21, 1.2255, 1.2377, 1.2588 } };


double L1(double i) // local
 {
	double l1 = 0;

	if ((t[0][0] < i) && (i < t[0][2]))
	{
		for (int j = 0; j < 3; j++) 
		{
			double d1 = 1; 
			double d2 = 1;

			for (int k = 0; k < 3; k++)
			{
				if (j == k)
					continue;
				else
				{
					d1 *= i - t[0][k];
					d2 *= t[0][j] - t[0][k];
				}
			}
			l1 += (d1 / d2) * t[1][j];
		}
		return l1;
	}
	else if ((t[0][2] <= i) && (i < t[0][5]))
	{
		for (int j = 2; j < 6; j++)
		{
			double d1 = 1;
			double d2 = 1;

			for (int k = 2; k < 6; k++)
			{
				if (j == k)
					continue;
				else
				{
					d1 *= i - t[0][k];
					d2 *= t[0][j] - t[0][k];
				}
			}
			l1 += (d1 / d2) * t[1][j];
		}
		return l1;
	}
	else if ((t[0][5] <= i) && (i < t[0][8]))
	{
		for (int j = 5; j < 9; j++)
		{
			double d1 = 1;
			double d2 = 1;

			for (int k = 5; k < 9; k++)
			{
				if (j == k)
					continue;
				else
				{
					d1 *= i - t[0][k];
					d2 *= t[0][j] - t[0][k];
				}
			}
			l1 += (d1 / d2) * t[1][j];
		}
		return l1;
	}

}
double L2(double i)
{
	double l2 = 0;

	for (int j = 0; j < 9; j++)
	{
		double d1 = 1;
		double d2 = 1;

		for (int k = 0; k < 9; k++)
		{
			if (j == k)
				continue;
			else
			{
				d1 *= i - t[0][k];
				d2 *= t[0][j] - t[0][k];
			}
		}
		l2 += (d1 / d2) * t[1][j];
	}
	return l2;
}
// розрахунок похідних функції
double D1(double i)
{
	double d = 0;
	double h = 0.1;

	if (i == 1)
		d = (L1(i + h) - L1(i)) / h;
	else if (i == 3)
		d = (L1(i) - L1(i - h)) / h;
	else
		d = (L1(i + h / 2) - L1(i - h / 2)) / h;

	return d;
}

double D2(double i)
{
	double d = 0;
	double h = 0.1;

	if (i == 1)
		d = (L1(i + 2 * h) - 2 * L1(i + h) + L1(i)) / pow(h, 2);
	else if (i == 3)
		d = (L1(i) - 2 * L1(i - h) + L1(i - 2 * h)) / pow(h, 2);
	else
		d = (L1(i + h) - 2 * L1(i) + L1(i - h)) / pow(h, 2);

	return d;
}

int main()
{
	    cout << setw(7) << "1. \nx | "
		<< setw(10) << "f(x) | "
		<< setw(10) << "Ll(x) | "
		<< setw(11) << "Lg(x) | "<<endl;
		for (double i = 1; i <= 3; i += 0.1)
		{
			cout << setw(4) << i << " | "
			<< setw(7) << asin(i/(sqrt(1+pow(i, 2)))) << " | " 
			<< setw(7) << L1(i) << " | "
			<< setw(8) << L2(i) << " | "<<endl;
		}
		
		cout<< setw(7) << "2. \nx | "
		<< setw(11) << "first derivative(f`(x)) | "
		<< setw(11) << "approximate first derivative | "<<endl;
		
		for (double i = 1; i <= 3; i += 0.1)
		{
			cout << setw(4) << i << " | "
			<< setw(16) << (sqrt(1/(1+pow(i, 2))))/(sqrt(1+pow(i, 2))) << " | " 
			<< setw(28) << D1(i) << " | "<<endl;
		}
		cout<< setw(7) << "3. \nx | "
		<< setw(11) << "second derivative(f``(x)) | "  
		<< setw(11) << "approximate second derivative |\n";
		

		for (double i = 1; i <= 3; i += 0.1)
		{
			    cout << setw(4) << i << " | "
				<< setw(17) << (-2*i*sqrt(1/(1+pow(i, 2))))/pow(1+pow(i, 2), 3/2) << " | " 
				<< setw(29) << D2(i) << " |\n";
		}

}