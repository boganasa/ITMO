#include "Class_Polynom.h"
#include <iostream>

Polynom::Polynom(int nn, double* arr0)
{
	n = nn;
	if (n == 0)
	{
		arr = 0;
	}
	else
	{
		arr = new double[n + 1];
		for (int i = 0; i <= n; i++)
		{
			arr[i] = arr0[i];
		}
	}
}

Polynom::Polynom(const Polynom& pol)
{
	n = pol.n;
	if (n == 0)
	{
		arr = 0;
	}
	else
	{
		arr = new double [n + 1];
		for (int i = 0; i <= n; i++)
		{
			arr[i] = pol.arr[i];
		}
	}
}

Polynom::~Polynom()
{
	if (arr != 0)
	{
		delete[] arr;
	}
}

void Polynom::set(int nn, double* arr0)
{
	if (arr != 0)
	{
		delete[] arr;
	}
	n = nn;
	if (n == 0)
	{
		arr = 0;
	}
	else
	{
		arr = new double [n + 1];
		for (int i = 0; i <= n; i++)
		{
			arr[i] = arr0[i];
		}
	}
}


Polynom& Polynom::operator = (const Polynom& pol)
{
	if (&pol == this)
	{
		return *this;
	}
	set(pol.n, pol.arr);
	return *this;
}

bool Polynom::operator == (const Polynom& pol0)
{
	if (n != pol0.n)
	{
		return false;
	}
	for (int i = 0; i <= n; i++)
	{
		if (arr[i] != pol0.arr[i])
		{
			return false;
		}
	}
	return true;
}

bool Polynom::operator != (const Polynom& pol0)
{
	bool t = !(*this == pol0);
	return t;
}



Polynom Polynom::operator + (const Polynom& pol0)
{
	int n_max = pol0.n, n_min = n;
	if (pol0.n < n)
	{
		n_max = n;
		n_min = pol0.n;
	}

	double* arr_n = new double[n_max + 1];

	for (int i = 0; i <= n_max; i++)
	{
		if (i <= n_min)
		{
			arr_n[i] = pol0.arr[i] + arr[i];
		}
		else
		{
			if (n_max == n)
			{
				arr_n[i] = arr[i];
			}
			else
			{
				arr_n[i] = pol0.arr[i];
			}
		}
	}

	Polynom pol_n(n_max, arr_n);
	delete[] arr_n;
	return pol_n;
}

Polynom Polynom::operator += (const Polynom& pol0)
{
	int n_max = pol0.n, n_min = n;
	if (pol0.n < n)
	{
		n_max = n;
		n_min = pol0.n;
	}

	double* arr_n = new double[n_max + 1];

	for (int i = 0; i <= n_max; i++)
	{
		if (i <= n_min)
		{
			arr_n[i] = pol0.arr[i] + arr[i];
		}
		else
		{
			if (n_max == n)
			{
				arr_n[i] = arr[i];
			}
			else
			{
				arr_n[i] = pol0.arr[i];
			}
		}
	}

	Polynom pol_n(n_max, arr_n);
	*this = pol_n;
	delete[] arr_n;
	return *this;
}

Polynom Polynom::operator - (const Polynom& pol0)
{
	int n_max = pol0.n, n_min = n;
	if (pol0.n < n)
	{
		n_max = n;
		n_min = pol0.n;
	}

	double* arr_n = new double[n_max + 1];

	for (int i = n_max; i >= 0; i--)
	{
		if (i <= n_min)
		{
			arr_n[i] = arr[i] - pol0.arr[i];
		}
		else
		{
			if (n_max == n)
			{
				arr_n[i] = arr[i];
			}
			else
			{
				arr_n[i] = -pol0.arr[i];
			}
		}
	}

	Polynom pol_n(n_max, arr_n);
	delete[] arr_n;
	return pol_n;
}

Polynom Polynom::operator -= (const Polynom& pol0)
{
	int n_max = pol0.n, n_min = n;
	if (pol0.n < n)
	{
		n_max = n;
		n_min = pol0.n;
	}

	double* arr_n = new double[n_max + 1];

	for (int i = n_max; i >= 0; i--)
	{
		if (i <= n_min)
		{
			arr_n[i] = arr[i] - pol0.arr[i];
		}
		else
		{
			if (n_max == n)
			{
				arr_n[i] = arr[i];
			}
			else
			{
				arr_n[i] = -pol0.arr[i];
			}
		}
	}

	Polynom pol_n(n_max, arr_n);
	*this = pol_n;
	delete[] arr_n;
	return *this;
}

Polynom& Polynom::operator + ()
{
	return *this;
}

Polynom& Polynom::operator - ()
{
	for (int i = 0; i <= n; i++)
	{
		arr[i] = -arr[i];
	}
	return *this;
}

Polynom Polynom::operator * (double c)
{
	double* arr_n = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		arr_n[i] = arr[i] * c;
	}
	Polynom pol_n(n, arr_n);
	delete[] arr_n;
	return pol_n;
}

Polynom Polynom::operator / (double c)
{
	if (c == 0)
	{
		cout << "BEDA";
		exit(-1);
	}
	double* arr_n = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		arr_n[i] = arr[i] / c;
	}
	Polynom pol_n(n, arr_n);
	delete[] arr_n;
	return pol_n;
}

Polynom Polynom::operator *= (double c)
{
	for (int i = 0; i <= n; i++)
	{
		arr[i] *= c;
	}
	return *this;
}

Polynom Polynom::operator /= (double c)
{
	if (c == 0)
	{
		cout << "BEDA";
		exit(-1);
	}
	for (int i = 0; i <= n; i++)
	{
		arr[i] /= c;
	}
	return *this;
}

double Polynom::operator [] (int i)
{
	if ((i >= 0) && (i <= n))
	{
		return arr[i];
	}
	else
	{
		cout << "BEDA";
		exit(-1);
	}
}



ostream& operator << (ostream& out, const Polynom& p)
{
	std::cout << "Ваш полином:" << '\n';
	for (int i = p.n; i >= 0; i--)
	{
		std::cout << p.arr[i] << "x^" << i << " ";
		if (i != 0)
		{
			std::cout << "+ ";
		}
	}
	std::cout << "= 0" << '\n';
	return out;
}


istream& operator >> (istream& in, Polynom& p)
{
	int nn;
	std::cout << "Введите степень полинома" << '\n';
	std::cin >> nn;
	double* arr0 = new double[nn + 1];
	std::cout << "Введите коэффициенты полинома" << '\n';
	for (int i = nn; i >= 0; i--)
	{
		std::cin >> arr0[i];
	}
	Polynom pp(nn, arr0);
	delete[] arr0;
	p = pp;
	return in;
}

