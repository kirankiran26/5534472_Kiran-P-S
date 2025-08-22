#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int isleap(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

int main() {
    char start[11], end[11];
    scanf("%s %s", start, end);

    int d1 = (start[0]-'0')*10 + (start[1]-'0');
    int m1 = (start[3]-'0')*10 + (start[4]-'0');
    int y1 = (start[6]-'0')*1000 + (start[7]-'0')*100 + (start[8]-'0')*10 + (start[9]-'0');

    int d2 = (end[0]-'0')*10 + (end[1]-'0');
    int m2 = (end[3]-'0')*10 + (end[4]-'0');
    int y2 = (end[6]-'0')*1000 + (end[7]-'0')*100 + (end[8]-'0')*10 + (end[9]-'0');

    int count = 0;

    while (1) {
        long num = d1;
        num = num * 100 + m1;
        num = num * 10000 + y1;   
        if (num % 4 == 0 || num % 7 == 0) 
            count++;

        if (d1 == d2 && m1 == m2 && y1 == y2) break;

        d1++;
        if (m1 == 2) {
            if (isleap(y1) && d1 > 29) { d1 = 1; m1++; }
            else if (!isleap(y1) && d1 > 28) { d1 = 1; m1++; }
        }
        else if (d1 > month[m1-1]) { d1 = 1; m1++; }

        if (m1 > 12) { m1 = 1; y1++; }
    }

    printf("%d\n", count);
    return 0;
}
