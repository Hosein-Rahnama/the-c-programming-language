/* This program deals with a date conversion problem. Given a day of year, it
   returns the corresponding month and day of month. Conversely, given a year,
   month, and day of month, the program returns the associated day of year. */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int year_day, int* month, int* day);
int is_leap_year(int year);
char* month_name(int n);

int main() {
    int month, day, year_day;

    month_day(1988, 60, &month, &day);
    printf("day 60 of 1988 is equivalent to 1988.%s.%d.\n", month_name(month), day);

    year_day = day_of_year(1988, 2, 29);
    printf("1988.2.29 is equivalent to day %d of 1988.", year_day);

    return 0;
}

int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = is_leap_year(year);
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

void month_day(int year, int year_day, int* month, int* day) {
    int i, leap;

    leap = is_leap_year(year);
    for (i = 1; year_day > daytab[leap][i]; i++) {
        year_day -= daytab[leap][i];
    }
    *month = i;
    *day = year_day;
}

int is_leap_year(int year) {
    return ((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0;
}

char* month_name(int n) {
    static char* name[] = {
        "Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}
