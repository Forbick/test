#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;
ifstream fin1, fin2, fin3, fin4, fin5;

int main(int argc, string argv[])
{
	fin1.open(argv[0]);//Открываем файлы, содержащие данные очереди.
	fin2.open(argv[1]);
	fin3.open(argv[2]);
	fin4.open(argv[3]);
	fin5.open(argv[4]);
	double sum[16];
	double a1,a2,a3,a4,a5;
	for (int i = 0; i < 16; i++)
	{
		fin1 >> a1;
		fin2 >> a2;
		fin3 >> a3;
		fin4 >> a4;
		fin5 >> a5;
		sum[i] = a1+a2+a3+a4+a5;//Накапливаем сумму, чтобы вычеслить в какой момент времени в очередях было боло больше всего людей.
	}
	fin1.close(); fin2.close(); fin3.close(); fin4.close(); fin5.close();
	double max = sum[0];//Делаем первый элемент максимальным, чтобы уменьшить цикл.
	int maxx = 0;
	for (int i = 1; i < 16; i++)
	{
		if (sum[i]>max)//Находим максимальный размер очереди и запоминаем его индекс.
		{
			max = sum[i];
			maxx = i;
		}
	}
	cout << maxx + 1;//Так как первое значение 0, то необходимое нам значение на 1 больше.
}
