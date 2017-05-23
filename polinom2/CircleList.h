#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include "monom.h"
#include <string>
#include <sstream>
using namespace std;

class CircleList
{
private:
	monom* first;
public:
	CircleList()	// конструктор иницилизатор
	{
		monom *tmp;
		tmp = new monom(); first = tmp;
	}

	void addmonom(monom * contr)	// добавление элемента к циклическому списку
	{
		monom *tmp; tmp = new monom;
		*tmp = *contr;
		monom* prev = first;
		monom* cur = first->GetNext();
		while (cur->GetSvert() > tmp->GetSvert())
		{
			prev = cur;
			cur = cur->GetNext();
		}
		if (cur->GetSvert() == tmp->GetSvert())
		{
			cur->SetCoinf(cur->GetCoinf() + tmp->GetCoinf());
			if (cur->GetCoinf() == 0)
			{
				prev->SetNext(cur->GetNext()); cur->SetNext(NULL);
				delete cur;
			}
		}
		else
		{
			tmp->SetNext(cur); prev->SetNext(tmp);
		}
	}
	

	CircleList(CircleList const& tmp)	// конструктор копирования
	{
		monom *tmp1;
		tmp1 = new monom();
		first = tmp1;
		monom * cur = tmp.first->GetNext();
		while (cur != tmp.first)
		{
			monom * newcur(cur);
			addmonom(newcur); 
			cur = cur->GetNext();
		}
	}

	~CircleList()	// Деструктор
	{
		monom * cur = first->GetNext(); first->SetNext(NULL);
		first = NULL;
	}

	CircleList & operator=(CircleList & tmp)	//оператор присваивания
	{
		monom * prev = first;
		monom * cur = first->GetNext();
		monom * tmpcur = tmp.first->GetNext();
		while ((cur != first) && (tmpcur != tmp.first))
		{
			*cur = *tmpcur; cur = cur->GetNext();
			tmpcur = tmpcur->GetNext();
		}
		if (cur == first)
		{
			while (tmpcur != tmp.first)
			{				monom copy = *tmpcur;	
				addmonom(&copy);
				tmpcur = tmpcur->GetNext();
			}
		}
		else
		{
			if (cur != first)
			{
				prev->SetNext(first);	
				while (cur != first)
				{
					prev = cur;
					cur = cur->GetNext(); prev->SetNext(NULL); delete prev;

				}
			}
		}
		return *this;
	}

	CircleList	operator+(CircleList copy)	// оператор суммирования двух циклических списков
	{
		CircleList tmp = copy;
		monom * cur = first->GetNext();
		while (cur != first)
		{
			monom copymonom = *cur; tmp.addmonom(&copymonom); cur = cur->GetNext();
		}
		return tmp;
	}

	CircleList operator*(double k)	// оператор умножения на число
	{
		if (k != 0)
		{
			CircleList copy = *this;
			monom * cur = copy.first->GetNext();
			while (cur != copy.first)
			{
				cur->SetCoinf(cur->GetCoinf()*k); cur = cur->GetNext();

			}
			return copy;
		}
		else
		
		
		{CircleList copy;
		return copy; }
	}

	CircleList multy(CircleList tmp, int maxSt)	// метод умножения списка на список
	{
		CircleList rez;
		int maxSv = (maxSt*maxSt + maxSt)*maxSt + maxSt;
		monom * cur = first->GetNext();
		while (cur != first)
		{
			monom * curtmp = tmp.first->GetNext();
			while (curtmp != tmp.first)
			{
				monom rezmonom((cur->GetCoinf())*(curtmp->GetCoinf()), cur ->GetSvert() + curtmp->GetSvert());
				if
					(((rezmonom.GetSvert() / (maxSt*maxSt)) >= maxSt) || ((rezmonom.GetSvert() / maxSt%maxSt) >= maxSt) || ((rezmonom.GetSvert() % maxSt) >= maxSt))
				{
					CircleList rez;
					return rez;
				}
				else
				{
					rez.addmonom(&rezmonom); 
					curtmp = curtmp->GetNext();											
				}				
			}
			cur = cur->GetNext();			
		}
		return rez;
	}

	CircleList operator-(CircleList & tmp)	// оператор вычитания списков
	{
		CircleList rez = tmp*(-1);
		return *this + rez;
	}


	string getpolynom(int maxSt)	// методы вывода циклического списка
	{
		string st = "";
		monom * cur = first->GetNext();
		while (cur != first)
		{
			char buffer[100];

			string stmonom = itoa(cur->GetCoinf(), buffer, 10);
			if (stmonom[0] != '-')	
				stmonom = '+' + stmonom;
			_itoa_s((cur->GetSvert() / (maxSt*maxSt)), buffer, 10);
			stmonom = stmonom + "x^" + buffer;
			_itoa_s((cur->GetSvert() / maxSt%maxSt), buffer, 10); stmonom = stmonom + "y^" + buffer;
			_itoa_s((cur->GetSvert() % maxSt), buffer, 10); stmonom = stmonom + "z^" + buffer;
			st = st + stmonom; cur = cur->GetNext();
		}
		cout << st<<endl;
		return st;
	}

	void addmonom(int a, int s)	// метод добавления монома в список при получении коэфицента и свёртки
	{
		monom tmp(a, s); addmonom(&tmp);
	}

};

