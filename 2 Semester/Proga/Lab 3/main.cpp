#include "Class_Conteiner.h"
#include <iostream>
#include <string.h>
#include <functional>

using namespace std;

template < class Iterator, class Type >
bool all_of(Iterator first, Iterator last, bool (*predicate)(Type t))//- ���������� true, ���� ��� �������� ��������� ������������� ���������� ���������.����� false
{
	for (; first != last; ++first)
	{
		if (!predicate(*first)) {
			return false;
		}
	}
		
	return true;
}

template < class Iterator, class Type >
bool any_of(Iterator first, Iterator last, bool (*predicate)(Type t))//���������� true, ���� ���� �� ���� �� ��������� ��������� ������������� ���������� ���������.����� false
{
	for (; first != last; ++first)
	{
		if (predicate(*first)) {
			return true;
		}
	}

	return false;
}

template < class Iterator, class Type >
bool non_of(Iterator first, Iterator last, bool (*predicate)(Type t))//���������� true, ���� ��� �������� ��������� �� ����������������������� ���������.����� false
{	
	for (; first != last; ++first)
	{
		if (predicate(*first)) {
			return false;
		}
	}

	return true;
}

template < class Iterator, class Type >
bool one_of(Iterator first, Iterator last, bool (*predicate)(Type t))//���������� true, ���� ����� ���� ������� ��������� ������������ ���������� ���������.����� false
{
	int count = 0;
	for (; first != last; ++first)
	{
		if (predicate(*first)) {
			count++;
			if (count > 1)
			{
				return false;
			}
		}
	}

	if (count == 0)
	{
		return false;
	}

	return true;
}

template < class Iterator, class Type >
bool is_sorted(Iterator first, Iterator last, bool (*predicate)(Type t, Type f))//���������� true, ���� ��� �������� ��������� ��������� � ��������������� ������� ������������ ���������� ��������
{
	--last;
	Iterator next;
	for (; first != last; ++first)
	{
		next = first;
		++next;
		if (!(predicate(*first, *next)))
		{
			return false;
		}
	}

	return true;
}

template < class Iterator, class Type >
bool is_partitioned(Iterator first, Iterator last, bool (*predicate)(Type t))//���������� true, ���� � ��������� ���� �������, ������� ��� �������� �� ��������������� � �� ��������������� ���������� ���������. ����� false.
{
	int counter_true = 0;
	int counter_false = 0;
	for (; first != last; ++first)
	{
		if (predicate(*first)) {
			counter_true++;
		}
		else
		{
			counter_false++;
		}
	}
	if ((counter_true == 0) || (counter_false == 0))
	{
		return false;
	}
	return true;
}

template < class Iterator, class Type >
Iterator find_not(Iterator first, Iterator last, Type value) //������� ������ �������, �� ������ ���������
{
	for (; first != last; ++first)
		if (value != *first)
			return first;
	return last;
}

template < class Iterator, class Type >
Iterator find_backward(Iterator first, Iterator last, Type value) //������� ������ �������, ������ ���������, � �����
{
	Iterator it = --last;
	for (; it != last; --it)
		if (value == *it)
			return it;
	return last;
}

template < class Iterator, class Type >
bool is_palindrome(Iterator first, Iterator last, bool (*predicate)(Type t)) //������� ������ �������, ������ ���������, � �����
{
	--last;
	while (!((first == last) && (first+1 != last)))
	{
		if (predicate(*first) != predicate (*last))
		{
			return false;
		}
		++first;
		--last;
	}

	return true;
} 


bool MyFunc(int a)
{
	return a > 1;
}

bool MyFuncCompare(int a, int b)
{
	return a < b;
}

bool MyFuncPolindrome(int a)
{
	return (a % 2 == 0);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "��� �������� ���������� ������, ������������ ������� �� 0 �� 12";
	Conteiner<double> buf(6);
	Conteiner<double>::iterator buf_iter;

	cout << "������������ ���������� �������� � �����" << endl;
	for (int i = 0; i < 12; ++i)
	{
		buf.add_rear(i + i*0.1);
		buf.print();
	}

	cout << "������ ��������� �������" << endl;
	buf.remove_front();
	buf.print();

	cout << "������������ ������ ���������� ������ ����� ���������" << endl;
	for (buf_iter = buf.front(); buf_iter != buf.rear(); ++buf_iter)
	{
		std::cout << *buf_iter << " ";
	}
	std::cout << std::endl;

	cout << "������� find_not" << endl;
	Conteiner<double>::iterator find_n = find_not(buf.front(), buf.rear(), 0);
	if (find_n == buf.rear())
	{
		cout << "Each element is equal to the specified" << endl;
	}
	else
	{
		cout << *find_n << endl;
	}

	cout << "������� find_backward" << endl;
	Conteiner<double>::iterator find_b = find_backward(buf.front(), buf.rear(), 11);
	if (find_b == buf.rear())
	{
		cout << "There is no such element" << endl;
	}
	else
	{
		cout << *find_b << endl;
	}
	
	cout << "������� all_of" << endl;
	if (all_of(buf.front(), buf.rear(), MyFunc))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	
	cout << "������� any_of" << endl;
	if (any_of(buf.front(), buf.rear(), MyFunc))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	cout << "������� non_of" << endl;
	if (non_of(buf.front(), buf.rear(), MyFunc))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	cout << "������� one_of" << endl;
	if (one_of(buf.front(), buf.rear(), MyFunc))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	cout << "������� is_sorted" << endl;
	if (is_sorted(buf.front(), buf.rear(), MyFuncCompare))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	cout << "������� is_partitioned" << endl;
	if (is_partitioned(buf.front(), buf.rear(), MyFunc))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	cout << "������� is_palindrome" << endl;
	if (is_palindrome(buf.front(), buf.rear(), MyFuncPolindrome))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	return 0;
}