// MapFunctions.h
#pragma once
#include <map>

using namespace std;

// ������� ��� �������� � ���������� �������������� ���������� ���� map<double, double>
map<double, double> createAndFillMap();

// ������� ��� ���������� �������� � ���������
void addToMap(map<double, double>& myMap, double key, double value);

// ������� ��� �������� �������� �� ����������
void removeFromMap(map<double, double>& myMap, double key);

// ������� ��� ���������� ������� �������� ��� ����������
void performTask(map<double, double>& myMap);
