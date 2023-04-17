#define _CRT_SECURE_NO_WARNINGS //чтобы не жаловался
#include <iostream>
#include <stdio.h> //для работы с файлами
#include <windows.h> //для русского ввода-вывода штучки

using namespace std;
const int MAXLINE = 255; //макс длина строки

struct Point
{
	char data[MAXLINE]; //строка, название и тд элемента стека
	Point* next = nullptr; //следующий элемент списка стека
};
Point* head = nullptr; //указатель на последний входящий элемент стека
size_t stack_size = 0;

bool stack_is_empty(); //проверка на пустой стек
void output(Point* obj); //рекурсивная функция для обратного вывода 3 2 1 -> 1 2 3 (ввод был 1 2 3)
void show_stack(); //вывод стека
void push(char* str); //добавить новый элемент сверху
void create_stack(int size); //создание стека из n элементов
void remove_obj(char* str); //удалить объект с заданным ключом
void push_before(unsigned index, unsigned k); //вставить перед элементом
void remove_stack(); //удаление списка
void toFile_obj(Point* obj, FILE* file); //рекурсия ф-ия для обратного порядка заноса в файл
void toFile(char* filename); //загрузить в файл ключи стека
void fromFile(char* filename); //выгрузить из файла ключи стека
void show_menu(); //показать пункты менюшки
void menu(); //сама менюшка

bool stack_is_empty() //проверка на пустой стек
{
	return head == nullptr; //stack_size = 0;
}
void output(Point* obj) //рекурсивная функция для обратного вывода 3 2 1 -> 1 2 3 (ввод был 1 2 3)
{
	if (obj == nullptr) return;
	output(obj->next);
	cout << obj->data << endl;
}
void show_stack() //вывод стека
{
	if (stack_is_empty()) cout << "Стек пуст" << endl;
	else output(head);
}
void push(char* str) //добавить новый элемент сверху
{
	stack_size++;
	Point* obj = new Point;
	strcpy(obj->data, str);
	obj->next = head;
	head = obj;
}
void create_stack(int size) //создание стека из n элементов
{
	if (size > 0 && stack_is_empty())
	{
		char str[MAXLINE];
		cout << "Введите ключи " << size << " элементов стека: " << endl;
		cin.get();
		for (int i = 1; i <= size; i++)
		{
			cout << i << ". ";
			gets_s(str, MAXLINE);
			push(str);
		}
	}
}
void push_before(unsigned index, unsigned k)
{
	int new_index = stack_size - index;
	if (new_index < 0 || stack_is_empty()) cout << "Введен неверный индекс/стек пуст" << endl;
	else
	{
		if (k == 0) return;
		Point* obj_next = head;
		for (unsigned i = 0; i != new_index; ++i)
		{
			obj_next = obj_next->next;
		}
		cout << "Введите " << k << " ключей: " << endl;
		cin.get();
		for (unsigned i = 0; i < k; i++)
		{
			Point* new_obj = new Point;
			cin.getline(new_obj->data, MAXLINE);
			new_obj->next = obj_next->next;
			obj_next->next = new_obj;
			stack_size++;
		}
	}
}
void remove_obj(char* str)
{
	Point* prev_obj = nullptr;
	Point* obj = head;
	while (obj != nullptr)
	{
		if (strcmp(obj->data, str) == 0)
		{
			if (obj == head) head = obj->next;
			else prev_obj->next = obj->next;
			delete obj;
			stack_size--;
			cout << "Элемент удален" << endl;
			return;
		}
		prev_obj = obj;
		obj = obj->next;
	}
	cout << "Элемент не найден" << endl;
}
void remove_stack() //удаление списка
{
	Point* temp;
	while (head != nullptr)
	{
		temp = (*head).next;
		delete head;
		head = temp;
	}
	stack_size = 0;
	cout << "Список удален!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	toFile_obj(obj->next, file);
	fputs(obj->data, file);
	fputs("\n", file);
}
void toFile(char* filename) //загрузить в файл ключи стека
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(1);
	}
	cout << "Заносим данные в файл..." << endl;
	toFile_obj(head, file);
	cout << "Данные успешно занесены!" << endl;
	fclose(file);
}
void fromFile(char* filename) //выгрузить из файла ключи списка
{
	FILE* file;
	char row[MAXLINE];
	if ((file = fopen(filename, "rb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(2);
	}
	cout << "Считываем данные из файла..." << endl;
	while (!feof(file) && fgets(row, MAXLINE, file))
	{
		row[strlen(row) - 1] = '\0'; //заносили с \n, нужно его убрать.
		push(row);
	}
	fclose(file);
	cout << "Данные успешно считаны!" << endl;
}
void show_menu()
{
	cout << "\tМеню\t" << endl;
	cout << "0. Выход из меню;" << endl;
	cout << "1. Создание стека;" << endl;
	cout << "2. Вывод ключей объектов стека;" << endl;
	cout << "3. Добавление K объектов перед объектом с позицией N;" << endl;
	cout << "4. Удаление объекта с заданным ключом;" << endl;
	cout << "5. Удаление стека;" << endl;
	cout << "6. Сохранить данные стека в файл;" << endl;
	cout << "7. Считать данные из файла в стек;" << endl;
}
void menu()
{
	int n, N, K;
	int size;
	char str[MAXLINE];
	char filename[] = "file.txt";
	do
	{
		system("pause");
		system("cls");
		show_menu();
		cin >> n;
		cout << "---" << endl;
		switch (n)
		{
		case 0: {
			cout << "Выход из меню!" << endl;
			break;
		}
		case 1: {
			cout << "Введите кол-во элементов: ";
			cin >> size;
			create_stack(size);
			break; }
		case 2: {
			show_stack();
			break; }
		case 3: {
			cout << "Введите кол-во объетов K и позицию N: " << endl;
			cin >> K >> N;
			push_before(N, K);
			break;
		}
		case 4: {
			cout << "Введите ключ объекта, который хотите удалить: " << endl;
			cin.get();
			cin.getline(str, MAXLINE);
			remove_obj(str);
			break;
		}
		case 5: {remove_stack(); break; }
		case 6: {toFile(filename); break; }
		case 7: {fromFile(filename); break; }
		default: { cout << "Такой команды нет!" << endl; break; }
		}
	} while (n != 0);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu();

	return 0;
}