#include <iostream>

#include "Class_Point.h"
#include "Class_Broken.h"
#include "Class_Closed_Broken.h"
#include "Class_Polygon.h"
#include "Class_RegularPolygon.h"
#include "Class_Trapeze.h"
#include "Class_Triangle.h"
#include "Class_Polynom.h"

int main() //За корректность исходных данный отвечает клиент класса (для пунктов 1-7)
{
	std::setlocale(LC_ALL, "Russian");
	std::cout << "Какую фигуру вы хотите обсудить?" << '\n';
	std::cout << "1) Точка" << '\n';
	std::cout << "2) Ломанная" << '\n';
	std::cout << "3) Замкнутая ломанная" << '\n';
	std::cout << "4) Многоугольник" << '\n';
	std::cout << "5) Правильный многоугольник" << '\n';
	std::cout << "6) Треугольник" << '\n';
	std::cout << "7) Трапеция" << '\n';
	std::cout << "8) Где применим динамический полиморфизм? " << '\n';
	std::cout << "9) Работа с полиномом" << '\n';

	int choice = 0;
	std::cin >> choice;

	if (choice == 1)
	{
		int x, y;
		std::cout << "Введите координаты " << '\n';
		std::cin >> x >> y;
		Point p1(x, y);
		Point p2 = p1;
		Point p3;
		p3 = p1;

		std::cout << "Демонстрация конструктора по умолчанию: " << '\n';
		p1.print();
		std::cout << '\n' << "Демонстрация конструктора копирования: " << '\n';
		p2.print();
		std::cout << '\n' << "Демонстрация оператора присваивания:" << '\n';
		p3.print();
	}

	else if (choice == 2)
	{
		int n, x, y;
		std::cout << "Введите количество вершин " << '\n';
		std::cin >> n;
		std::cout << "Введите координаты " << '\n';
		Point* arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> x >> y;
			arr[i].setx(x);
			arr[i].sety(y);
		}
		Broken b1(n, arr);
		Broken b2 = b1;
		Broken b3;
		b3 = b1;

		std::cout << "Демонстрация конструктора по умолчанию: " << '\n';
		b1.print();
		std::cout << '\n' << "Демонстрация конструктора копирования: " << '\n';
		b2.print();
		std::cout << '\n' << "Демонстрация оператора присваивания:" << '\n';
		b3.print();
	}
	else if (choice == 3)
	{
		int n, x, y;
		std::cout << "Введите количество вершин " << '\n';
		std::cin >> n;
		std::cout << "Введите координаты " << '\n';
		Point* arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> x >> y;
			arr[i].setx(x);
			arr[i].sety(y);
		}
		ClosedBroken cb1(n, arr);
		ClosedBroken cb2 = cb1;
		ClosedBroken cb3;
		cb3 = cb1;

		std::cout << "Демонстрация конструктора по умолчанию: " << '\n';
		cb1.print();
		std::cout << '\n' << "Демонстрация конструктора копирования: " << '\n';
		cb2.print();
		std::cout << '\n' << "Демонстрация оператора присваивания:" << '\n';
		cb3.print();
	}
	else if (choice == 4)
	{
		int n, x, y;
		std::cout << "Введите количество вершин " << '\n';
		std::cin >> n;
		std::cout << "Введите координаты " << '\n';
		Point* arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> x >> y;
			arr[i].setx(x);
			arr[i].sety(y);
		}
		Polygon pol1(n, arr);
		Polygon pol2 = pol1;
		Polygon pol3;
		pol3 = pol1;

		std::cout << "Демонстрация конструктора по умолчанию: " << '\n';
		pol1.print();
		std::cout << '\n' << "Демонстрация конструктора копирования: " << '\n';
		pol2.print();
		std::cout << '\n' << "Демонстрация оператора присваивания:" << '\n';
		pol3.print();
	}
	else if (choice == 5)
	{
		int n, x, y;
		std::cout << "Введите количество вершин " << '\n';
		std::cin >> n;
		std::cout << "Введите координаты " << '\n';
		Point* arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> x >> y;
			arr[i].setx(x);
			arr[i].sety(y);
		}
		RegularPolygon rpol1(n, arr);
		RegularPolygon rpol2 = rpol1;
		RegularPolygon rpol3;
		rpol3 = rpol1;

		std::cout << "Демонстрация конструктора по умолчанию: " << '\n';
		rpol1.print();
		std::cout << '\n' << "Демонстрация конструктора копирования: " << '\n';
		rpol2.print();
		std::cout << '\n' << "Демонстрация оператора присваивания:" << '\n';
		rpol3.print();
	}
	else if (choice == 6)
	{
		int x, y;
		std::cout << "Введите координаты " << '\n';
		Point* arr = new Point[3];
		for (int i = 0; i < 3; i++)
		{
			std::cin >> x >> y;
			arr[i].setx(x);
			arr[i].sety(y);
		}
		Triangle tr1(arr);
		Triangle tr2 = tr1;
		Triangle tr3;
		tr3 = tr1;

		std::cout << "Демонстрация конструктора по умолчанию: " << '\n';
		tr1.print();
		std::cout << '\n' << "Демонстрация конструктора копирования: " << '\n';
		tr2.print();
		std::cout << '\n' << "Демонстрация оператора присваивания: " << '\n';
		tr3.print();
	}
	else if (choice == 7)
	{
		int x, y;
		std::cout << "Введите координаты " << '\n';
		Point* arr = new Point[4];
		for (int i = 0; i < 4; i++)
		{
			std::cin >> x >> y;
			arr[i].setx(x);
			arr[i].sety(y);
		}
		Trapeze trap1(arr);
		Trapeze trap2 = trap1;
		Trapeze trap3;
		trap3 = trap1;

		std::cout << "Демонстрация конструктора по умолчанию: " << '\n';
		trap1.print();
		std::cout << '\n' << "Демонстрация конструктора копирования: " << '\n';
		trap2.print();
		std::cout << '\n' << "Демонстрация оператора присваивания:" << '\n';
		trap3.print();
	}
	else if (choice == 8)
	{
		std::cout << "Динамический полиморфизм применим к таким геомтрическим объектам как: ломанная, замкнутая ломанная," << '\n';
		std::cout << "многоугольник, правильный многоугольник, треугольник и трапеция" << '\n';

		Point arr1[5], arr2[5], arr3[5], arr4[4], arr5[3], arr6[4];

		arr1[0].setx(1);
		arr1[0].sety(2);
		arr1[1].setx(3);
		arr1[1].sety(1);
		arr1[2].setx(8);
		arr1[2].sety(6);
		arr1[3].setx(9);
		arr1[3].sety(1);
		arr1[4].setx(1);
		arr1[4].sety(0);
		Broken b1(5, arr1);

		arr2[0].setx(0);
		arr2[0].sety(0);
		arr2[1].setx(1);
		arr2[1].sety(8);
		arr2[2].setx(5);
		arr2[2].sety(4);
		arr2[3].setx(9);
		arr2[3].sety(1);
		arr2[4].setx(1);
		arr2[4].sety(12);
		ClosedBroken cb1(5, arr2);

		arr3[0].setx(0);
		arr3[0].sety(0);
		arr3[1].setx(1);
		arr3[1].sety(8);
		arr3[2].setx(5);
		arr3[2].sety(12);
		arr3[3].setx(4);
		arr3[3].sety(20);
		arr3[4].setx(0.5);
		arr3[4].sety(12);
		Polygon p1(5, arr3);

		arr4[0].setx(0);
		arr4[0].sety(0);
		arr4[1].setx(2);
		arr4[1].sety(0);
		arr4[2].setx(2);
		arr4[2].sety(2);
		arr4[3].setx(0);
		arr4[3].sety(2);
		RegularPolygon rp1(4, arr4);

		arr5[0].setx(0);
		arr5[0].sety(3);
		arr5[1].setx(2);
		arr5[1].sety(0);
		arr5[2].setx(2);
		arr5[2].sety(21);
		Triangle tr1(arr5);

		arr6[0].setx(0);
		arr6[0].sety(0);
		arr6[1].setx(22);
		arr6[1].sety(0);
		arr6[2].setx(7);
		arr6[2].sety(21);
		arr6[3].setx(28);
		arr6[3].sety(21);
		Trapeze trap1(arr6);

		Broken* PolArr[6];
		PolArr[0] = new Broken(b1);
		PolArr[1] = new ClosedBroken(cb1);
		PolArr[2] = new Polygon(p1);
		PolArr[3] = new RegularPolygon(rp1);
		PolArr[4] = new Triangle(tr1);
		PolArr[5] = new Trapeze(trap1);
		for (int i = 0; i < 6; i++)
		{
			PolArr[i]->print();
		}

		for (int i = 0; i < 6; i++)
		{
			delete PolArr[i];
		}
	}
	else if (choice == 9)
	{
		Polynom pol1;
		Polynom pol2;
		Polynom pol0;

		string choice_p;
		std::cout << "Возможные операции с полиномом (формат ввода: a?b)" << '\n';
		std::cout << "1) =" << '\n';
		std::cout << "2) ==" << '\n';
		std::cout << "3) !=" << '\n';
		std::cout << "4) + унарный" << '\n';
		std::cout << "5) - унарный" << '\n';
		std::cout << "6) +" << '\n';
		std::cout << "7) -" << '\n';
		std::cout << "8) +=" << '\n';
		std::cout << "9) -=" << '\n';
		std::cout << "10) * на число" << '\n';
		std::cout << "11) / на число" << '\n';
		std::cout << "12) *=" << '\n';
		std::cout << "13) /=" << '\n';
		std::cout << "14) <<" << '\n';
		std::cout << "15) >>" << '\n';
		std::cout << "16) []" << '\n';
		std::cout << "Для завершения нажмите 0" << '\n';

		std::cin >> choice_p;
		
		while (choice_p != "0")
		{
			if (choice_p == "a=b")
			{
				pol1 = pol2;
			}
			else if (choice_p == "b=a")
			{
				pol2 = pol1;
			}
			else if (choice_p == "a==b")
			{
				bool t;
				t = (pol1 == pol2);
				if (t)
				{
					std::cout << "True" << '\n';
				}
				else
				{
					std::cout << "False" << '\n';
				}
			}
			else if (choice_p == "a!=b")
			{
				bool t;
				t = (pol1 != pol2);
				if (t)
				{
					std::cout << "True" << '\n';
				}
				else
				{
					std::cout << "False" << '\n';
				}
			}
			else if (choice_p == "+a")
			{
				+pol1;
			}
			else if (choice_p == "+b")
			{
				+pol2;
			}
			else if (choice_p == "-a")
			{
				-pol1;
			}
			else if (choice_p == "-b")
			{
				-pol2;
			}
			else if ((choice_p == "a+b")|| (choice_p == "b+a"))
			{
				pol0 = pol1 + pol2;
				cout << pol0;
			}
			else if (choice_p == "a-b")
			{
				pol0 = pol1 - pol2;
				cout << pol0;
			}
			else if (choice_p == "b-a")
			{
				pol0 = pol2 - pol1;
				cout << pol0;
			}
			else if (choice_p == "a+=b")
			{
				pol1 += pol2;
			}
			else if (choice_p == "b+=a")
			{
				pol2 += pol1;
			}
			else if (choice_p == "a-=b")
			{
				pol1 -= pol2;
			}
			else if (choice_p == "b-=a")
			{
				pol2 -= pol1;
			}
			else if (choice_p == "a*")
			{
				double c;
				std::cout << "Введите число, на которое умножить полином ";
				std::cin >> c;
				pol0 = pol1 * c;
				cout << pol0;
			}
			else if (choice_p == "b*")
			{
				double c;
				std::cout << "Введите число, на которое умножить полином ";
				std::cin >> c;
				pol0 = pol2 * c;
				cout << pol0;
			}
			else if (choice_p == "a/")
			{
				double c;
				std::cout << "Введите число, на которое разделить полином ";
				std::cin >> c;
				pol0 = pol1 / c;
				cout << pol0;
			}
			else if (choice_p == "b/")
			{
				double c;
				std::cout << "Введите число, на которое разделить полином ";
				std::cin >> c;
				pol0 = pol2 / c;
				cout << pol0;
			}
			else if (choice_p == "a*=")
			{
				double c;
				std::cout << "Введите число, на которое умножить полином ";
				std::cin >> c;
				pol1 *= c;
			}
			else if (choice_p == "b*=")
			{
				double c;
				std::cout << "Введите число, на которое умножить полином ";
				std::cin >> c;
				pol2 *= c;
			}
			else if (choice_p == "a/=")
			{
				double c;
				std::cout << "Введите число, на которое разделить полином ";
				std::cin >> c;
				pol1 /= c;
			}
			else if (choice_p == "b/=")
			{
				double c;
				std::cout << "Введите число, на которое разделить полином ";
				std::cin >> c;
				pol2 /= c;
			}
			else if (choice_p == ">>a")
			{
				cin >> pol1;
			}
			else if (choice_p == ">>b")
			{
				cin >> pol2;
			}
			else if (choice_p == "<<a")
			{
				cout << pol1;
			}
			else if (choice_p == "<<b")
			{
				cout << pol2;
			}
			else if (choice_p == "a[]")
			{
				int i;
				cout << "Введите степень перед которой хотите посмотреть коэффициент ";
				std::cin >> i;
				cout << pol1[i] << '\n';
			}
			else if (choice_p == "b[]")
			{
				int i;
				cout << "Введите степень перед которой хотите посмотреть коэффициент ";
				std::cin >> i;
				cout << pol2[i] <<'\n';
			}
			std::cout << "Введите следующую операцию" << '\n';
			std::cin >> choice_p;
		}
	}
}