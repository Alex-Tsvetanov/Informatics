#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

char *DayName[] =
          {(char *)"Monday", (char *)"Tuesday", (char *)"Wednesday",(char *)"Thursday",
           (char *)"Friday", (char *)"Saturday", (char *)"Sunday",(char *)"   ", (char *)"Flip"};
int MonthDaySt[] = { 0, 31,  59,  90, 120, 151, 181,
                       212, 243, 273, 304, 334, 365 };
int  doy[13];
bool IsLeapYear(int year)
     {
      if (year % 400 == 0) return true;
      if ((year % 4 == 0) && (year % 100 != 0)) return true;
      return false;
     }
int dayofwk(int day, int month, int year)
    {
     return((day
        +((153 * (month +  12 * ((14 - month) / 12) - 3) + 2) / 5)
        + (365 * (year + 4800 - ((14 - month) / 12)))
        + ((year + 4800 - ((14 - month) / 12)) / 4)
        - ((year + 4800 - ((14 - month) / 12)) / 100)
        + ((year + 4800 - ((14 - month) / 12)) / 400)
        - 32045) % 7);
    }

int main()
{
    int n;              // Number of tests
    int Year;           // Year
    int Day, dd, mm;    // Days of the Year, Day, Month
    int i, j;
    FILE * fp;
    char FileName[120];

    cin>>n;
  /* initialize random seed: */
  srand (time(NULL));
  /* generate random number between 1900 and 2099: */
  Year = rand() % 200 + 1900;
  for(i=0; i<n; i++){
      for(j=0; j<13; j++) doy[j] = MonthDaySt[j];
      Year = rand() % 200 + 1900;
      if(IsLeapYear(Year)){
         for(j=2; j<13; j++)(doy[j])++;
        }
    Day = rand() % doy[12] + 1;
    for(mm=0; mm<12; mm++)
        if(Day>doy[mm] && Day<=doy[mm+1]) break;
    dd = Day - doy[mm];
    mm++;
    cout<<Year<<" "<<DayName[dayofwk(1, 1, Year)]<<" "<<Day<<" ";
    if(dd<10) cout<<"0";
    cout<<dd<<".";
    if(mm<10) cout<<"0";
    cout<<mm<<endl;

    sprintf(FileName, "calendar.%02d.in", i);
    fp = fopen (FileName, "w+");
    fprintf(fp, "%d %s %02d.%02d", Year, DayName[dayofwk(1, 1, Year)], dd, mm);
    fclose(fp);
   }
 return 0;
}
