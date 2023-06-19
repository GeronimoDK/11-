// MapFunctions.h
#pragma once
#include <map>

using namespace std;

// Функция для создания и заполнения ассоциативного контейнера типа map<double, double>
map<double, double> createAndFillMap();

// Функция для добавления элемента в контейнер
void addToMap(map<double, double>& myMap, double key, double value);

// Функция для удаления элемента из контейнера
void removeFromMap(map<double, double>& myMap, double key);

// Функция для выполнения задания варианта для контейнера
void performTask(map<double, double>& myMap);
