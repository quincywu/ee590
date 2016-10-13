#include <stdio.h>


static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year ( int year, int month, int day ){
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    /*
    for (i = 1; i < month; i++){
        day += daytab[leap][i];
    }
    */
    for (i = 1; i < month; i++){
        day += *( *(daytab + leap) + i );
    }

    return day;
}

void month_day (int year, int yearday, int *pmonth, int *pday){
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    //for (i = 1; yearday > daytab[leap][i]; i++)
    //    yearday -= daytab[leap][i];
    for( i = 1; yearday > *(*(daytab + leap) + i); i ++ )
        yearday -= *(*(daytab + leap) + i) ;

    *pmonth = i;
    *pday = yearday;
}

int main (int argc, char* argv[]){

    if(argc == 3){
        int pmonth = 0, pday = 0;
        month_day(atoi(argv[1]), atoi(argv[2]), &pmonth, &pday); // ./day 1988 60 => 2 29
        printf("%d %d\n", pmonth, pday);
    }
    if(argc == 4){
        int result = day_of_year( atoi(argv[1]), atoi(argv[2]), atoi(argv[3]) ); // ./day 1988 2 29
        printf("%d\n", result);
    }

    return 0;
}
