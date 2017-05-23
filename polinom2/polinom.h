#pragma once
#include "CircleList.h"
#include "monom.h"
#include <string>
using namespace std;

class Polynom
{
public:
	int maxSt;
	CircleList* Mylist;

	void DelenieNaElm(string st, string * w, int & k, string zn)	// закрыт метод деления строки на элементы
	{
		k = 0;
		string out = st + "$";
		string cur = "";
		w[k] = "";
		for (int i = 0; i < out.length(); i++)
		{

			if ((zn.find(out[i]) == -1) || (i == 0))
			{
				if ((out[i] != ' ') && (out[i] != '$'))
				{
					w[k] = w[k] + out[i];

				}
			}
			else
			{
				if (zn.find(out[i]) != -1)
				{
					k++;
					w[k] = w[k] + out[i];
				}
			}
		}
		k++;
	}


	void getMonom(string str, int & a, int & n, int & m, int & k)	//метод получения числовых значений коэфицента и степеней
	{
		string st = "";
		st = str[0];
		for (int i = 0; i < str.length(); i++)
		{
			switch (str[i])
			{
			case 'x':
			{
						string nstr = "";
						if (str[i + 1] != '^')
							n = 1;

						else
						{
							i++;
							i++;
							while ((str.length() > i) && (str[i] >= '0') && (str[i] <= '9'))
							{
								nstr += str[i++];
							}

							n = atoi(nstr.c_str());
							i--;
						}
						
			} break;
			case 'y':
			{
						string nstr = "";
						if (str[i + 1] != '^')
							m = 1;
						else
						{
							
							i++;
							i++;
							while ((str.length() > i) && (str[i] >= '0') && (str[i] <= '9'))
							{
								nstr += str[i++];
							}
							

							m = atoi(nstr.c_str());	
							i--;
						}
						
						
			}
			break;
			case 'z':

			{
						string nstr = "";
						if (str[i + 1] != '^')
						
							k = 1; 
						
						else
						{
							
							i++;
							i++;
							while ((str.length() > i) && (str[i] >= '0') && (str[i] <= '9'))
							{
								nstr += str[i++];
							}
							k = atoi(nstr.c_str());	
							i--;
						}
						
			} break;
			case '+':
			{
						if ((str[i + 1] == 'x') || (str[i + 1] == 'y') || (str[i + 1] == 'z'))
						{
							st = st + "1";
						}
						else
						{
							while ((++i <= str.length()) && (str[i] >= '0') && (str[i] <= '9'))
							{
								st += str[i];
							}
							i--;
						}
						a = atof(st.c_str()); 
			} break;
			case '-':
			{
						if ((str[i + 1] == 'x') || (str[i + 1] == 'y') || (str[i + 1] == 'z'))
						{
							st = st + "1";
						}
						else
						{
							while ((++i <= str.length()) && (str[i] >= '0') && (str[i] <= '9'))
							{
								st += str[i];
							}
							i--;
						}
						a = atof(st.c_str()); 
			} break;

			}
		}
	}

	void get_MyList(string str) // получить полином 
	{
		if ((str[0] != '-') || (str[0] != '+')) str = "+" + str;
		string * w;
		w = new string[str.length() / 2];
		int dl = 0, a = 0, n = 0, m = 0, k = 0;
		string zn = "+-=*/";
		DelenieNaElm(str, w, dl, zn);
		for (int i = 0; i < dl; i++)
		{
			getMonom(w[i], a, n, m, k);
			Mylist->addmonom(a, n*maxSt*maxSt + m*maxSt + k);
		}
	}


	Polynom(string st = "", int _maxSt = 999)	// конструктор иницилизации
	{
		maxSt = _maxSt + 1;
		Mylist = new CircleList();
		if (st.length() > 0)
		{
			get_MyList(st);
		}
	}

	Polynom(Polynom const & tmp)	// конструктор копирования
	{
		maxSt = tmp.maxSt;
		Mylist = new CircleList();
		*Mylist = *tmp.Mylist;
	}

	~Polynom()	// Деструктор
	{
		delete Mylist;
		maxSt = 0;	
	}

	Polynom & operator=(Polynom & tmp)	// Оператор присваивания
	{
		maxSt = tmp.maxSt;
		*Mylist = *tmp.Mylist;
		return *this;
	}

	Polynom operator+(Polynom & tmp)	//Оператор сложения
	{
		Polynom rez; rez.maxSt = maxSt;
		*rez.Mylist = *Mylist + (*tmp.Mylist);
		return rez;
	}

	Polynom operator-(Polynom & tmp)	//Оператор вычитания
	{
		Polynom rez; rez.maxSt = maxSt;
		*rez.Mylist = *Mylist - (*tmp.Mylist);
		return rez;
	}

	Polynom operator*(int k)	// оператор умножения полинома на число
	{
		Polynom rez; rez.maxSt = maxSt;
		*rez.Mylist = (*Mylist)*k;	//
		
		return rez;
	}


	Polynom operator*(Polynom & tmp)	// оператор умножения полинома на полином
	{
		Polynom rez; rez.maxSt = maxSt;
		*rez.Mylist = (*Mylist).multy(*tmp.Mylist, maxSt);
		return rez;
	}

	string getPolynom()	// функция преобразования полинома в строку
	{
		return Mylist->getpolynom(maxSt);
	}
};