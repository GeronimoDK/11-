#define _CRT_SECURE_NO_WARNINGS //����� �� ���������
#include <iostream>
#include <stdio.h> //��� ������ � �������
#include <windows.h> //��� �������� �����-������ ������

using namespace std;
const int MAXLINE = 255; //���� ����� ������

struct Point
{
	char data[MAXLINE]; //������, �������� � �� �������� �������
	Point* next = nullptr; //��������� ������� �������
};
Point* head = nullptr; //��������� �� ������ ������� �������
Point* top = nullptr; //��������� �� ��������� ������� �������
size_t size_queue = 0;

void push(char* str); //�������� ����� ������� ������
bool queue_is_empty(); //�������� �� ������ ����

void create_queue(int size)
{
	if (size > 0 && queue_is_empty())
	{
		char str[MAXLINE];
		cout << "������� ����� " << size << " ��������� �������: " << endl;
		cin.get();
		for (int i = 1; i <= size; i++)
		{
			cout << i << ". ";
			gets_s(str, MAXLINE);
			push(str);
		}
	}
}
void push(char* str) //�������� ����� ������� ������
{
	if (queue_is_empty())
	{
		head = new Point;
		strcpy(head->data, str);
		top = head;
	}
	else
	{
		Point* obj = new Point;
		strcpy(obj->data, str);
		top->next = obj;
		top = obj;
	}
	size_queue++;

}
void pop()
{
	Point* temp = head;
	head = head->next;
	size_queue--;
	delete temp;
}
bool queue_is_empty() //�������� �� ������ ����
{
	return size_queue == 0;
}
void push_before(int index, int k)
{
	if (!queue_is_empty() && index >= 1 && index <= size_queue && k > 0)
	{
		int i = 1;
		while (i < index)
		{
			push(head->data);
			pop();
			i++;
		}
		char str[MAXLINE];
		cout << "������� �������� ��� �������: " << endl;
		cin.get();
		for (int j = 1; j <= k; j++)
		{
			cin.getline(str, MAXLINE);
			push(str);
		}
		for (i; i <= size_queue - k; i++)
		{
			push(head->data);
			pop();
		}
	}
	else cout << "������� ����� ��� ������ �������� ������" << endl;
}
void output(Point* obj)
{
	cout << obj->data << endl;
	if (obj == top) return;
	output(obj->next);
}
void show_queue() //����� �����
{
	if (queue_is_empty()) cout << "������� �����" << endl;
	else output(head);
}
void remove_obj(char* str)
{
	if (queue_is_empty()) cout << "������� �����, ������ �������!" << endl;
	int i = 1;
	while (i <= size_queue)
	{
		if (strcmp(head->data, str) == 0)
		{
			pop();
		}
		else
		{
			push(head->data);
			pop();
			i++;
		}
	}
}
void remove_queue()
{
	while (head != nullptr)
	{
		pop();
	}
	cout << size_queue << " ������� �������!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	fputs(obj->data, file);
	fputs("\n", file);
	toFile_obj(obj->next, file);
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
	cout << "1. �������� �������;" << endl;
	cout << "2. ����� ������ �������� �������;" << endl;
	cout << "3. ���������� K �������� ����� �������� � �������� N;" << endl;
	cout << "4. �������� ������� � �������� ������;" << endl;
	cout << "5. �������� �������;" << endl;
	cout << "6. ��������� ������ ������� � ����;" << endl;
	cout << "7. ������� ������ �� ����� � �������;" << endl;
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
			create_queue(size);
			break; }
		case 2: {
			show_queue();
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

		case 5: {remove_queue(); break; }
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