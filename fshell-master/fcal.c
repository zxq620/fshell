#include"shell.h"

/*判断输入的年份是否为闰年
**参数说明：year,要判断的年份
**返回值 1：是闰年，0：不是闰年
*/
int Isleap(int year)
{
    if( (year%400==0)||((year%4==0)&&(year%100!=0)) )
        return 1;
    else
        return 0;
}

/*判断输入年份二月份的天数
**参数说明：year,要判断的年份；month，要判断的月份
**返回值:Day[month-1],上个月（month-1）的天数
*/
int Max_day(int year, int month)
{
    int Day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(Isleap(year)==1)
        Day[1]=29;
    return Day[month-1];
}


/*计算输入的日期是这一年的多少天
**参数说明：year,month,day 分别为输入的年、月、日
**返回值:sum,输入的日期是这一年的多少天
*/
int Total_day(int year, int month ,int day)
{
    int sum=0;
    int i=1;
    for(i=1;i<month;i++)
    sum=sum+Max_day(year,i);
    sum=sum+day;
    return sum;
}

/*由输入的日期判断当天是星期几
**参数说明：year,month,day 分别为输入的年、月、日
**返回值:count,0～6，分别表示星期日～星期六
*/
int Weekday(int year, int month ,int day)
{
    int count;
    count=(year-1)+(year-1)/4-(year-1)/100+(year-1)/400 +Total_day(year,month,day);
    count=count%7;
    return count;
}


/*显示输入的日期是星期几
**参数说明：year,month,day 分别为输入的年、月、日
**返回值:无
*/
void display_week(int year, int month , int day)
{
    int count;
    count=Weekday(year,month,day);
    switch(count)
        {
            case 0:printf("\033[32m\t%d-%d-%d is Sunday\n\033[0m",year,month,day);break;
            case 1:printf("\033[32m\t%d-%d-%d is Monday\n\033[0m",year,month,day);break;
            case 2:printf("\033[32m\t%d-%d-%d is Tuesday\n\033[0m",year,month,day);break;
            case 3:printf("\033[32m\t%d-%d-%d is Wednesday\n\033[0m",year,month,day);break;
            case 4:printf("\033[32m\t%d-%d-%d is Thursday\n\033[0m",year,month,day);break;
            case 5:printf("\033[32m\t%d-%d-%d is Friday\n\033[0m",year,month,day);break;
            case 6:printf("\033[32m\t%d-%d-%d is Saturday\n\033[0m",year,month,day);break;
            default: printf("error\n");
        }
}

/*显示输入的日期的当月日历
**参数说明：year,month,day 分别为输入的年、月、日
**返回值:无
*/
void display_month(int year, int month, int day)
{
    int i=0,j=1;
    int week,max;
    week=Weekday(year,month,1); //由每月1号确定打印制表符的个数
    max=Max_day(year,month);
    printf("\033[34m\n\t\t\t%d年%d月\033[0m",year,month);
    printf("\033[31m\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\033[0m");
    for(i=0;i<week;i++)
    printf("\t");
    for(j=1;j<=max;j++)
    {
        printf("\t%d",j);
        if(i%7==6)
            printf("\n");
        i++;
    }
    printf("\n");
}


int Fcal()
{
    int year,month,day;
    struct tm *sysTime;
     time_t nowTime;
     time(&nowTime);
     sysTime=localtime(&nowTime);
    year=1900+sysTime->tm_year;
    month=sysTime->tm_mon+1;
    day=sysTime->tm_mday;
    printf("\033[32m\t%d年%d月%d日是这一年的第%d天\n\033[0m",year,month,day,Total_day(year,month,day));
    display_week(year,month,day);
    display_month(year,month,day);
    return 0;
}
