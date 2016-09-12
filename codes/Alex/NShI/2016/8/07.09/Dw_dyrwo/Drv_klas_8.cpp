/*
===================================
   ������� �����
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
//
//  �������� �� �������
//
void Dobawi(int k){
link t,q;	
// �������� �� �����
// ���������� �� ����� ����� �� ���� � q
	t=pStart;
	while (true) {							
		if (k<t->key) {						// ����� � ������ ��������
			if (t->l==NULL) {
				q=new node;
				q->key=k;
				q->l=q->r=NULL;
				q->p=t;
				t->l=q;
				break;
			}
			else
			t=t->l;
		}
		else
		if (k>t->key) {						// ����� � ������� ��������
			if (t->r==NULL) {
				q=new node;
				q->key=k;
				q->l=q->r=NULL;
				q->p=t;
				t->r=q;
				break;
			}
			else
			t=t->r;
		}
	}
}

void preorder(link t) {
	if (t) {
		cout<<t->key<<" ";
		preorder(t->l);
		preorder(t->r);
	}
}

void tyrsi (int k, link t, link &q) {
		if (t) {
			if (t->key == k) {
				q=t;
				exit;
			}
			else
			if (k < t->key)	
 		 		tyrsi (k,t->l,q);
 		 	else
 		 	tyrsi (k,t->r,q);
		}
}

void trie (int k) {
link t,q;
		t=pStart;
		tyrsi (k,pStart,t);
		if (t) {
				if (t->l == NULL && t->r == NULL) {		//	���� �����
					if (t->p != NULL) {						
						if (k > t->p->key)					
							t->p->r=NULL;						
							else									
							t->p->l=NULL;						
					}
				}
				else
				if (t->l == NULL && t->r != NULL) {		// ��� �����, ���� ��� ���������
					if (t->p !=NULL)							
						if (k > t->p->key)					
							t->p->r = t->r;					
							else									
							t->p->l = t->r;					
				}
				else
				if (t->l != NULL && t->r == NULL) {		// ��� ���, ���� ����� ���������	
					if (t->p !=NULL)							
						if (k > t->p->key)					
							t->p->r = t->l;					
							else									
							t->p->l = t->l;					
				}
				else {									// ��� ��� ����������
					q=t->r;								// ������ �� ������� ��������
					while (q->l != NULL) {				// ���-����� �������
						q = q->l;				
					}								
					t->key = q->key;			
					if (q == t->r) {					// ������ ������� �������� �� 
						t->r = NULL;					// � ��� ����������
					}								
					else							
					if (q->r != NULL)					// ������ ����� ������ �� ���
						q->p->l = q->r;					// ����� ���������
						else						
						q->p->l = NULL;		
				}
		}
}

int main (){
int i=0;
link t;
	pStart=new node;									// ������������� �� �����
   pStart->key=20;
   pStart->l=pStart->r=pStart->p=NULL;
//   Dobawi (10);
   Dobawi (15);
   Dobawi (30);

   preorder (pStart); cout<<endl;
   tyrsi (30,pStart,t);
   cout<<t<<endl;
   
//   preorder (pStart); cout<<endl;
	
  	return 0;
}

