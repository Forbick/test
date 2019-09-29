#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;
ifstream fin;

int main(int argc, string argv[])
{
	setlocale(LC_ALL, "RUS");
	fin.open(argv[0]);
	float ax, ay, bx, by, cx, cy, dx, dy;
	fin >> ax; fin >> ay; fin >> bx; fin >> by; fin >> cx; fin >> cy; fin >> dx; fin >> dy; //Считываем координаты вершин многоугольника.
	fin.close();
	fin.open(argv[1]);
	float Tochki_x[1000];
	float Tochki_y[1000];
	int i = 0;
	while (fin.eof() == 0) //Считываем координаты точек и заносим в соответствующие массивы.
	{
		fin >> Tochki_x[i];
		fin >> Tochki_y[i];
		i++;
	}
	fin.close();
	for (int j = 0; j < i; j++)//Проверяем все точки на соответствие условиям
	{
		if ((bx < Tochki_x[j] < cx) & (ay < Tochki_y[j] < by))
		{
			cout << 2 << "\n";//Если точка лежит в нижнем и верхнем пределах оси х и оси у, то она лежит внутри.
		}
		else if (((Tochki_x[j] == ax) & (Tochki_y[j] == ay)) || ((Tochki_x[j] == bx) & (Tochki_y[j] == by)) || ((Tochki_x[j] == cx) & (Tochki_y[j] == cy)) || ((Tochki_x[j] == dx) & (Tochki_y[j] == dy)))
		{
			cout << 0 << "\n";//Если координаты точки равны координатам одной из вершин, то она лежит на вершине.
		}
		else if ((Tochki_x[j] < ax) || (Tochki_x[j] > dx) || (Tochki_y[j] < ay) || (Tochki_y[j] > by))
		{
			cout << 3 << "\n";//Если точка находится за границей одного из пределов по осям х и у, то она лежит снаружи.
		}
		else
		{
			cout << 1 << "\n";//Иначе точка лежит на одном ребре.
		}
	}
}
