/*
===================================
   Двоично дърво за търсене
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
// В процедурата се влиза с новия ключ k
link t, q;											// Обявяваме t

	t=pStart;										// Проверката започва от корена pStart
	while (true)	{								// Напишете добавянето в този цикъл


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

	pStart=new node;										// Инициализация на върха
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

