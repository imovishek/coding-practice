#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
int i,test,day1,day2,month1,month2,year1,year2,age;
char daten[11],dateb[11];;
while(scanf("%d",&test)==1)
{
for(i=1;i<=test;i++){
scanf("%s",daten);
scanf("%s",dateb);
day1=(daten[0]-'0')*10+daten[1]-'0';
day2=(dateb[0]-'0')*10+dateb[1]-'0';
month1=(daten[3]-'0')*10+daten[4]-'0';
month2=(dateb[3]-'0')*10+dateb[4]-'0';
year1=(daten[6]-'0')*1000+(daten[7]-'0')*100+(daten[8]-'0')*10+daten[9]-'0';
year2=(dateb[6]-'0')*1000+(dateb[7]-'0')*100+(dateb[8]-'0')*10+dateb[9]-'0';
//printf("\n%d %d %d",day1,month1,year1);
//printf("\n%d %d %d",day2,month2,year2);
age=year1-year2;
if(day1<day2)month1--;
if(month1<month2)age--;
if(age<0) printf("Case #%d: Invalid birth date\n",i);
else if(age>130)printf("Case #%d: Check birth date\n",i);
else if(age==0)printf("Case #%d: 0\n",i);
else  printf("Case #%d: %d\n",i,age);
}
  }

  return 0;
  }
