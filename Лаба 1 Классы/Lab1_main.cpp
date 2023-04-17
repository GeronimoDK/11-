#include "fraction.h"
#include <iostream>
using namespace std;
fraction make_fraction(double F, int S)
{
	fraction t;//������� ��������� ���������� 

	t.Init(F, S);//���������������� ���� ���������� t � ������� ���������� �������

	return t;//������� �������� ���������� t
}
int main()
{
	setlocale(0, "");

	//����������� ���������� � � �
	fraction A;
	fraction B;

	A.Init(3, 2);//������������� ���������� �
	A.Show();//����� �������� ����� ���������� �

	B.Read();//���� ����� ���������� �
	B.Show();//����� �������� ����� ���������� �

	//����� �������� �������, ������������ � ������� ������� Power() 
	cout << "A.�������(" << A.first << "," << A.second << ")=" << A.Power() << endl;
	cout << "B.�������(" << B.first << "," << B.second << ")=" << B.Power() << endl;


	//���������
	fraction* X = new fraction;//��������� ������ ��� ������������ ����������

	X->Init(2, 5);//�������������
	X->Show();//����� �������� �����
	X->Power();//���������� �������

	cout << "X.�������(" << X->first << "," << X->second << ")=" << X->Power() << endl;


	//�������
	fraction mas[3];//����������� �������

	for (int i = 0; i < 3; i++)
		mas[i].Read();//������ �������� �����

	for (int i = 0; i < 3; i++)
		mas[i].Show(); //����� �������� �����

	for (int i = 0; i < 3; i++)
	{
		mas[i].Power(); //���������� �������
		cout << "mas[" << i << "].�������(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].Power() << endl;
	}

	//������������ ������
	fraction* p_mas = new fraction[3];//��������� ������

	for (int i = 0; i < 3; i++)
		p_mas[i].Read();//������ �������� �����

	for (int i = 0; i < 3; i++)
		p_mas[i].Show();//����� �������� �����

	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Power();//���������� �������
		cout << "p_mas[" << i << "].�������(" << p_mas[i].first << "," << p_mas[i].second;
		cout << ")=" << p_mas[i].Power() << endl;
	}

	//����� ������� make_fraction()
	double y; int z;

	cout << "������� ������ �����: "; cin >> y;
	cout << "������� ������ �����: "; cin >> z;

	//���������� F ����������� � ������� ������� make_fraction()
	fraction F = make_fraction(y, z);
	F.Show();
	return 0;
}