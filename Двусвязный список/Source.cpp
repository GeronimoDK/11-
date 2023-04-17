#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <istream>
using namespace std;

struct list {
	int field; // ���� ������
	struct list* next; // ��������� �� ��������� �������
	struct list* prev; // ��������� �� ���������� �������
};
struct list* init(int a) { // �- �������� ������� ����
	struct list* lst;
	// ��������� ������ ��� ������ ������
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = NULL; // ��������� �� ��������� ����
	lst->prev = NULL; // ��������� �� ���������� ����
	return(lst);
}

struct list* addelem(list* lst, int number) {
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // ���������� ��������� �� ��������� ����
	lst->next = temp; // ���������� ���� ��������� �� �����������
	temp->field = number; // ���������� ���� ������ ������������ ����
	temp->next = p; // ��������� ���� ��������� �� ��������� ����
	temp->prev = lst; // ��������� ���� ��������� �� ���������� ����
	if (p != NULL)
		p->prev = temp;
	return(temp);
}

struct list* deletelem(list* lst) {
	struct list* prev, * next;
	prev = lst->prev; // ����, �������������� lst
	next = lst->next; // ����, ��������� �� lst
	if (prev != NULL)
		prev->next = lst->next; // ������������ ���������
	if (next != NULL)
		next->prev = lst->prev; // ������������ ���������
	free(lst); // ����������� ������ ���������� ��������
	return(prev);
}
struct list* deletehead(list* root) {
	struct list* temp;
	temp = root->next;
	temp->prev = NULL;
	free(root);   // ������������ ������ �������� �����
	return(temp); // ����� ������ ������
}
void listprint(list* lst) {
	struct list* p;
	p = lst;
	do {
		cout << " " << p->field; // ����� �������� �������� p
		p = p->next; // ������� � ���������� ����
	} while (p != NULL); // ������� ��������� ������
}
void listprintr(list* lst) {
	struct list* p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // ������� � ����� ������
	do {
		cout << " " << p->field; // ����� �������� �������� p
		p = p->next; // ������� � ���������� ����
	} while (p != NULL); // ������� ��������� ������
}
struct list* swap(struct list* lst1, struct list* lst2, struct list* head)
{
	// ���������� ����� ������ ������
	struct list* prev1, * prev2, * next1, * next2;
	prev1 = lst1->prev;  // ���� �������������� lst1
	prev2 = lst2->prev;  // ���� �������������� lst2
	next1 = lst1->next; // ���� ��������� �� lst1
	next2 = lst2->next; // ���� ��������� �� lst2
	if (lst2 == next1)  // ������������ �������� ����
	{
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		if (next2 != NULL)
			next2->prev = lst1;
		if (lst1 != head)
			prev1->next = lst2;
	}
	else if (lst1 == next2)  // ������������ �������� ����
	{
		lst1->next = lst2;
		lst1->prev = prev2;
		lst2->next = next1;
		lst2->prev = lst1;
		if (next1 != NULL)
			next1->prev = lst2;
		if (lst2 != head)
			prev2->next = lst1;
	}
	else  // ������������ ��������� ����
	{
		if (lst1 != head)  // ��������� prev ����� ���������� ������ ��� ��������,
			prev1->next = lst2; // �� ����������� ��������
		lst2->next = next1;
		if (lst2 != head)
			prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		if (next2 != NULL) // ��������� next ����� ���������� ������ ��� ��������,
			next2->prev = lst1; // �� ����������� ���������
		lst1->prev = prev2;
		if (next1 != NULL)
			next1->prev = lst2;
	}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}

int main() {
	list* head, * cur;
	int num;
	int cf;
	// ������� ������ �� 6 ���������
	cout << "a = ";
	cin >> num;
	head = init(num);
	cur = head;
	for (int i = 0; i < 5; i++) {
		cout << "a = ";
		cin >> num;
		cur = addelem(cur, num);
	}
	listprint(head);
	cout << endl;
	// ������ ������� ������ � ������ ��������
	cur = head->next;
	head = swap(head, cur, head);
	listprint(head);
	cout << endl;
	// ������� ������ ������� ������
	cur = head->next->next;
	deletelem(cur);
	listprint(head);
	cout << endl;
	return 0;
}