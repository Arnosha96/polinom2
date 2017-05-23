#pragma once

class monom
{
private:
	double coinf; int svert; monom* Next;
public:
	monom(double _coinf = 0, int _svert = -1)	//����������� ������������
	{
		svert = _svert; coinf = _coinf;
		Next = this;
	}

	monom(monom & tmp)	//����������� �����������
	{
		coinf = tmp.coinf; svert = tmp.svert; Next = 0;
	}

	monom operator=(monom & tmp)	//�������� ������������
	{
		coinf = tmp.coinf;
		svert = tmp.svert;
		return *this;
	}



	void SetCoinf(double tmp)	//����� ������� ����������
	{
		coinf = tmp;
	}

	void SetSvert(int tmp)	//����� ������� ������
	{
		svert = tmp;
	}

	void SetNext(monom* tmp)	//����� ������� ��������� �� ��������� �������
	{
		Next = tmp;
	}

	double GetCoinf()	// �������� ���������
	{
		return coinf;
	}

	int GetSvert()	// �������� ������
	{
		return svert;
	}

	monom* GetNext()	// �������� ��������� �������
	{
		return Next;
	}

	~monom()	//����������
	{
		Next = 0;
		delete Next;
	}
};


