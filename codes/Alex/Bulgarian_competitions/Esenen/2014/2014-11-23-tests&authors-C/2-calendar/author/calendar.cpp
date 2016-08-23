#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CALENDARPAGES 160
#define YEARDAYS 366
// #define PRINTCAL // Uncoment if you want print the calendar
using namespace std;
typedef struct
   {
    int Page;
    int fd;
    int fm;
    int DayOfWeekFront;
    int fds;
    int fms;
    int DayOfWeekFrontw;
    int bd;
    int bm;
    int DayOfWeekBack;
    int bds;
    int bms;
    int DayOfWeekBackw;
   } sheet ;
sheet ART[CALENDARPAGES];
int DayIdx[YEARDAYS];
int N;          // Number of Years days.
int SheetsNum;  // Number of Calendar sheets
char *DayName[] =
          {(char *)"Monday", (char *)"Tuesday", (char *)"Wednesday",(char *)"Thursday",
           (char *)"Friday", (char *)"Saturday", (char *)"Sunday",(char *)"   ", (char *)"Flip"};
int MonthDaySt[] = { 0, 31,  59,  90, 120, 151, 181,
                       212, 243, 273, 304, 334, 365 };
bool IsLeapYear(int year)
     {
      if (year % 400 == 0) return true;
      if ((year % 4 == 0) && (year % 100 != 0)) return true;
      return false;
     }
void MonthDayStart(int year)
     {
      int i;
      if (IsLeapYear( year ))
         {
          for(i=2; i<13; i++)MonthDaySt[i]++;
         }
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
/* ============================================*/
#ifdef PRINTCAL
void PrintSheet(int i)
{
 printf("Page: %03d %02d/%02d %-9s %02d/%02d %-9s <---> %02d/%02d %-9s %02d/%02d %-9s\n",
             ART[i].Page,ART[i].fd, ART[i].fm, DayName[ART[i].DayOfWeekFront],
                         ART[i].fds,ART[i].fms,DayName[ART[i].DayOfWeekFrontw],
                         ART[i].bd, ART[i].bm, DayName[ART[i].DayOfWeekBack],
                         ART[i].bds,ART[i].bms,DayName[ART[i].DayOfWeekBackw]);
}
#endif
/*===========================================*/
void Init(int year)
     {
       int i, j, day, month, step=1;;
       int dwk; // Day of week: 0 - Mon, 1-Tue,...,5-Sat,6-Sun
       MonthDayStart( year); // If leap year
       for(i=0; i<CALENDARPAGES; i++)
          {
           ART[i].Page=i+1;
           ART[i].fd=0;
           ART[i].fm=0;
           ART[i].DayOfWeekFront=7;
           ART[i].fds=0;
           ART[i].fms=0;
           ART[i].DayOfWeekFrontw=7;
           ART[i].bd=0;
           ART[i].bm=0;
           ART[i].DayOfWeekBack=7;
           ART[i].bds=0;
           ART[i].bms=0;
           ART[i].DayOfWeekBackw=7;
          }
       // Calculate the number of pages and sheets on the calendar
       N=0; int dd=0;
       if(dayofwk(1, 1, year) == 6)N++; // If year start with sun, sun reserved page
       for(month=1, i = 0; month <= 12; month++)
          {
           for(day = 1; day <= MonthDaySt[month]-MonthDaySt[month-1]; day++)
              {
               dd++;
               dwk =  dayofwk(day, month, year);
               if(dwk<=5)N++;
              }
          }
       SheetsNum = (N + 2) / 2;
      // cout<<"Page Num:"<<N<<" Days:"<<dd<<" SheetsNum:"<<SheetsNum<<endl;
       N=MonthDaySt[12];
       // Filling the sheets on the calendar
       for(month=1, i=j=0; month<=12; month++)
          {
           for(day=1; day<=MonthDaySt[month]-MonthDaySt[month-1]; day++)
              {
               dwk =  dayofwk(day, month, year);
               if((dwk>=0) && (dwk<=5))
                 {
                  if(step>0)
                    {
                     ART[i].fd = day;
                     ART[i].fm = month;
                     ART[i].DayOfWeekFront = dwk;
                    }
                  else
                    {
                     ART[i].bd = day;
                     ART[i].bm = month;
                     ART[i].DayOfWeekBack = dwk;
                    }

                  DayIdx[j++] = ART[i].Page;
                  if(dwk!=5){ i+=step;}
                 }
               else
                 {
                  if(step>0)
                    {
                     ART[i].fds = day;
                     ART[i].fms = month;
                     ART[i].DayOfWeekFrontw = dwk;
                    }
                  else
                    {
                     ART[i].bds = day;
                     ART[i].bms = month;
                     ART[i].DayOfWeekBackw = dwk;
                    }
                  DayIdx[j++] = ART[i].Page;
                  i+=step;
                }
               if((i>SheetsNum-2)&&(step>0))
                 {
                  step=-step;
                  // Reminder flip Page
                  ART[i].fd = 99;
                  ART[i].fm = 99;
                  ART[i].DayOfWeekFront = 8;
                  ART[i].fds = 99;
                  ART[i].fms = 99;
                  ART[i].DayOfWeekFrontw = 8;
                  // DayIdx[j++] = ART[i].Page; // Page reminder do not indexed!
                 }
              } //End Days for
          } // End months for
     }

int main()
{
 int i, j, k=0, year;
 char buff[24];

 cin>>year>>buff;
 Init(year);
 /* ===========================*/
 #ifdef PRINTCAL
 for(i=0; i<SheetsNum; i++) PrintSheet( i);
 #endif
 /*=============================*/
   cin>>buff;
   if(strcmp(buff, DayName[8])==0)
     { // flip day
       k=SheetsNum-1;
       printf("Face: Flip\nBack: %02d.%02d %s",
               ART[k].bd, ART[k].bm, DayName[ART[k].DayOfWeekBack]);
       if(ART[k].bds>0)
         printf(" %02d.%02d %s",
               ART[k].bds,ART[k].bms,DayName[ART[k].DayOfWeekBackw]);
       printf("\n");
     }
   else
     { // Date dd.mm
      sscanf(buff,"%d.%d", &i, &j);
      k = i+MonthDaySt[j-1]-1;
      k = DayIdx[k]-1;
      printf("Face: ");
      if(ART[k].fd==99)
           {
             printf("Flip\n");
           }
         else
           {
            if(ART[k].fd>0)
               printf("%02d.%02d %s",
                 ART[k].fd, ART[k].fm, DayName[ART[k].DayOfWeekFront]);
            if(ART[k].fds>0)
               printf("% 02d.%02d %s", ART[k].fds,ART[k].fms,DayName[ART[k].DayOfWeekFrontw]);
               printf("\n");
           }
      if(ART[k].bd > 0)
        {
         printf("Back: %02d.%02d %s",
                ART[k].bd, ART[k].bm, DayName[ART[k].DayOfWeekBack]);
         if(ART[k].bds>0)
            printf(" %02d.%02d %s", ART[k].bds,ART[k].bms,DayName[ART[k].DayOfWeekBackw]);
            printf("\n");
        }
      }
 return 0;
}
/* End of File */
