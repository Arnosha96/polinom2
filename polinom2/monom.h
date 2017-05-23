#pragma once

class monom
{
private:
	double coinf; int svert; monom* Next;
public:
	monom(double _coinf = 0, int _svert = -1)	//конструктор иницилизации
	{
		svert = _svert; coinf = _coinf;
		Next = this;
	}

	monom(monom & tmp)	//конструктор копирования
	{
		coinf = tmp.coinf; svert = tmp.svert; Next = 0;
	}

	monom operator=(monom & tmp)	//оператор присваивания
	{
		coinf = tmp.coinf;
		svert = tmp.svert;
		return *this;
	}



	void SetCoinf(double tmp)	//метод задания коэфицента
	{
		coinf = tmp;
	}

	void SetSvert(int tmp)	//метод задания свёртки
	{
		svert = tmp;
	}

	void SetNext(monom* tmp)	//метод задания указателя на следующий элемент
	{
		Next = tmp;
	}

	double GetCoinf()	// получить коэфицент
	{
		return coinf;
	}

	int GetSvert()	// получить свёртку
	{
		return svert;
	}

	monom* GetNext()	// получить следующий элемент
	{
		return Next;
	}

	~monom()	//деструктор
	{
		Next = 0;
		delete Next;
	}
};


