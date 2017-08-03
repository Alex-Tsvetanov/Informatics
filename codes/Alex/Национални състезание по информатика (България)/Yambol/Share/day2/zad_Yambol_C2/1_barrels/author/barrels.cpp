//Task barells
//Author Plamenka Hristova
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main () {
 int n,i,j;
 double sx[100][100],sy[100][100],r,temp,vx,vy,px,py,l,xrez, yrez;
 cin>>n>>r;
 for (i=0;i<n;i++)
 {
  cin>>sx[0][i];
  sy[0][i] = r;
 }
 for (i=0;i<n;i++){
  for (j=i+1;j<n;j++)
	if (sx[0][i]>sx[0][j]){
	   temp = sx[0][i];
	  sx[0][i] = sx[0][j];
	  sx[0][j] = temp;
	}
 }
 for (i=1;i<n;i++)
 {
  for (j=0;j<n-i;j++){
	sx[i][j] = (sx[i-1][j]+sx[i-1][j+1])/2; //координати на точка S
	sy[i][j] = (sy[i-1][j]+sy[i-1][j+1])/2;
	vx = sx[i-1][j+1]-sx[i-1][j];
	vy = sy[i-1][j+1]-sy[i-1][j];
	px = -vy / sqrt(vx*vx+vy*vy); // - sin alpha
	py = vx / sqrt(vx*vx+vy*vy);  // cos alpha
	l = sqrt(4.0*r*r - (vx*vx)/4 - (vy*vy)/4);//дължината на se`ka О1S
	sx[i][j] += l*px; // от триъгълник SNO3:
	sy[i][j] += l*py; // към координатите на точка S, добавяме делта x и делта y до точка O3
    }
 }
    xrez=sx[n-1][0];
    yrez=sy[n-1][0] + r;
    printf("%.4f %.4f\n",xrez,yrez);
  return 0;
}
