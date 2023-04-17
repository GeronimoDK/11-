#define _CRT_SECURE_NO_WARNINGS //����� �� ���������
#include <iostream>
#include <stdio.h> //��� ������ � �������
#include <windows.h> //��� �������� �����-������ ������

using namespace std;
const int MAXLINE = 255; //���� ����� ������

struct Point
{
	char data[MAXLINE]; //������, �������� � �� �������� �����
	Point* next = nullptr; //��������� ������� ������ �����
};
Point* head = nullptr; //��������� �� ��������� �������� ������� �����
size_t stack_size = 0;

bool stack_is_empty(); //�������� �� ������ ����
void output(Point* obj); //����������� ������� ��� ��������� ������ 3 2 1 -> 1 2 3 (���� ��� 1 2 3)
void show_stack(); //����� �����
void push(char* str); //�������� ����� ������� ������
void create_stack(int size); //�������� ����� �� n ���������
void remove_obj(char* str); //������� ������ � �������� ������
void push_before(unsigned index, unsigned k); //�������� ����� ���������
void remove_stack(); //�������� ������
void toFile_obj(Point* obj, FILE* file); //�������� �-�� ��� ��������� ������� ������ � ����
void toFile(char* filename); //��������� � ���� ����� �����
void fromFile(char* filename); //��������� �� ����� ����� �����
void show_menu(); //�������� ������ �������
void menu(); //���� �������

bool stack_is_empty() //�������� �� ������ ����
{
	return head == nullptr; //stack_size = 0;
}
void output(Point* obj) //����������� ������� ��� ��������� ������ 3 2 1 -> 1 2 3 (���� ��� 1 2 3)
{
	if (obj == nullptr) return;
	output(obj->next);
	cout << obj->data << endl;
}
void show_stack() //����� �����
{
	if (stack_is_empty()) cout << "���� ����" << endl;
	else output(head);
}
void push(char* str) //�������� ����� ������� ������
{
	stack_size++;
	Point* obj = new Point;
	strcpy(obj->data, str);
	obj->next = head;
	head = obj;
}
void create_stack(int size) //�������� ����� �� n ���������
{
	if (size > 0 && stack_is_empty())
	{
		char str[MAXLINE];
		cout << "������� ����� " << size << " ��������� �����: " << endl;
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
	if (new_index < 0 || stack_is_empty()) cout << "������ �������� ������/���� ����" << endl;
	else
	{
		if (k == 0) return;
		Point* obj_next = head;
		for (unsigned i = 0; i != new_index; ++i)
		{
			obj_next = obj_next->next;
		}
		cout << "������� " << k << " ������: " << endl;
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
			cout << "������� ������" << endl;
			return;
		}
		prev_obj = obj;
		obj = obj->next;
	}
	cout << "������� �� ������" << endl;
}
void remove_stack() //�������� ������
{
	Point* temp;
	while (head != nullptr)
	{
		temp = (*head).next;
		delete head;
		head = temp;
	}
	stack_size = 0;
	cout << "������ ������!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	toFile_obj(obj->next, file);
	fputs(obj->data, file);
	fputs("\n", file);
}
void toFile(char* filename) //��������� � ���� ����� �����
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //������ �������� ����� 
	{
		cout << "������ �������� �����" << endl;
		exit(1);
	}
	cout << "������� ������ � ����..." << endl;
	toFile_obj(head, file);
	cout << "������ ������� ��������!" << endl;
	fclose(file);
}
void fromFile(char* filename) //��������� �� ����� ����� ������
{
	FILE* file;
	char row[MAXLINE];
	if ((file = fopen(filename, "rb")) == NULL) //������ �������� ����� 
	{
		cout << "������ �������� �����" << endl;
		exit(2);
	}
	cout << "��������� ������ �� �����..." << endl;
	while (!feof(file) && fgets(row, MAXLINE, file))
	{
		row[strlen(row) - 1] = '\0'; //�������� � \n, ����� ��� ������.
		push(row);
	}
	fclose(file);
	cout << "������ ������� �������!" << endl;
}
void show_menu()
{
	cout << "\t����\t" << endl;
	cout << "0. ����� �� ����;" << endl;
	cout << "1. �������� �����;" << endl;
	cout << "2. ����� ������ �������� �����;" << endl;
	cout << "3. ���������� K �������� ����� �������� � �������� N;" << endl;
	cout << "4. �������� ������� � �������� ������;" << endl;
	cout << "5. �������� �����;" << endl;
	cout << "6. ��������� ������ ����� � ����;" << endl;
	cout << "7. ������� ������ �� ����� � ����;" << endl;
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
			cout << "����� �� ����!" << endl;
			break;
		}
		case 1: {
			cout << "������� ���-�� ���������: ";
			cin >> size;
			create_stack(size);
			break; }
		case 2: {
			show_stack();
			break; }
		case 3: {
			cout << "������� ���-�� ������� K � ������� N: " << endl;
			cin >> K >> N;
			push_before(N, K);
			break;
		}
		case 4: {
			cout << "������� ���� �������, ������� ������ �������: " << endl;
			cin.get();
			cin.getline(str, MAXLINE);
			remove_obj(str);
			break;
		}
		case 5: {remove_stack(); break; }
		case 6: {toFile(filename); break; }
		case 7: {fromFile(filename); break; }
		default: { cout << "����� ������� ���!" << endl; break; }
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