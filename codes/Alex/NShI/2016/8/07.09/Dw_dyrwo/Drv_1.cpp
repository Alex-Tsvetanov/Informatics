/*
===================================
   ������� ����� �� �������
===================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
  int key;
  node *l, *r, *p;
};

typedef node *link;
link pStart;

void Dobawi(int k){
// � ����������� �� ����� � ����� ���� k
link t, q;											// ��������� t

	t=pStart;										// ���������� ������� �� ������ pStart
	while (true)	{								// �������� ���������� � ���� �����


	}
}

void preorder(link t) {
	if (t) {
		cout<<t->key<<endl;
		preorder(t->l);
		preorder(t->r);
	}
}

int main (){
int i=0;

	pStart=new node;										// ������������� �� �����
	pStart->key=20;
	pStart->l=pStart->r=pStart->p=NULL;
	Dobawi (10);
	Dobawi (15);
	Dobawi (30);
	Dobawi ( 8);
	Dobawi (40);
	Dobawi (18);




	preorder (pStart);
	
	return 0;
}

