#include<iostream>
#define MAXH 102
#define INF 103
using namespace std;
int w, h, n, maxS=-1;
bool a[MAXH][MAXH];
void Init ()
{
    for (int i=0; i<MAXH; i++)
        for (int j=0; j<MAXH; j++)
            a[i][j]=false;
    cin>>w>>h;
    cin>>n;
    for (int k=0; k<n; k++)
    {
        int x, y, a1, b1;
        cin>>x>>y>>a1>>b1;
        for (int i=y; i<y+b1; i++)
            for (int j=x; j<x+a1; j++)
                a[i][j]=true;
    }
}
void Solve ()
{
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++)//����� ���������� �� ��� ������� �� � ������� ��� ���� �� ��������, ����� �� ������.
        {
            if (a[i][j]==true) continue;
            int maxD=INF;
            for (int k=i; a[k][j]==false && k<h; k++)//���������� ���������� �� �������� - �� � k-i+1.
            {
                int s, d=0;
                for (int l=j; a[k][l]==false && l<w; l++) //���������� ������������ ������ �� ��������,
                    d++;                                  //�� ��� ��� ��-����� ������,
                maxD=min (maxD, d);                       //������������ ����� ����� �� ��-�������.
                s=maxD*(k-i+1);    //�������� ������ �� ��������� ������������
                maxS=max (maxS, s);//� �� ���������� c ������������ ������.
            }
        }
}
int main ()
{
    Init ();
    Solve ();
    cout<<maxS<<endl;
    return 0;
}
