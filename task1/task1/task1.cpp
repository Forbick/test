#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;
ifstream fin;
double per(vector<int>&,int i,double perc);

int main(int argc, string argv[])
{
	double percentil; 
	double mediana;
	fin.open(argv[0]);
	int count = 0;
	float sum = 0;
	string s;
	while (getline(fin, s)) count++; //Считаем количество элементов в файле.
	fin.close();
	fin.open(argv[0]);
	vector <int> vec(count);//Создаем вектор целых числел.
	int i = 0;
	while (fin.eof()==0)//Считываем значения из файла.
	{
		fin>>vec[i];
		sum += vec[i];
		i++;
	}
	fin.close();
	sort(vec.begin(), vec.end());
	percentil = per(vec,count,0.9);//Считаем 90 перцентиль
	mediana = per(vec, count, 0.5);//Медиана это 50 перцентиль
	cout << percentil<<"\n";
	cout << mediana << "\n";
	cout << vec[count - 1] << "\n";//Так как вектор отсортирован, то последнее значение будет максимальным
	cout << vec[0] << "\n";//А первое соответственно минимальным.
	cout << (sum+.0) / (count+.0) << "\n";
}

double per(vector<int>&s,int COUNT,double perc)
{
	double k = (COUNT-1) * perc;
	double f = floor(k);
	double c = ceil(k);
	if (f == c)
		return s[(int)k];
	double d0 = s[(int)f] * (c - k);
	double d1 = s[(int)c] * (k - f);
	return d0 + d1;
}