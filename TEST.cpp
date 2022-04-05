#include "TEST.h"
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <string>

void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}


NODE* GetNODE(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}


bool IsPrimeNum(int n)
{
	if (n < 2) {
		return 0;
	}

	for (int i = 2; i < (n - 1); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int CountPrimeNum(LIST l)
{
	int count = 0;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		if (IsPrimeNum(p->info))
			count++;
		p = p->pNext;
	}
	return count;
}

void SortPrimeNum(LIST& l)
{
	NODE* p = l.pHead;
	NODE* q = p->pNext;
	int temp;
	while (p != NULL)
	{
		if (IsPrimeNum(p->info))
		{
			while (q != NULL)
			{
				if (IsPrimeNum(q->info) == 1 && (p->info > q->info))
				{
					temp = p->info;
					p->info = q->info;
					q->info = temp;
				}
				q = q->pNext;
			}
		}
		p = p->pNext;
	}
}

void Swap(LIST& l1, LIST& l2)
{
	//
}

void Input(const char* filename, LIST& l1, LIST& l2)
{
	Init(l1);
	Init(l2);
	ifstream ifs(filename);
	int a;
	string line;
	int count = 0;
	getline(ifs, line);

	while (ifs >> a && count < 4)
	{
		NODE* p = GetNODE(a);
		AddTail(l1, p);
		count++;
	}
	//
	ifs.close();
}

void Output(LIST l)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}