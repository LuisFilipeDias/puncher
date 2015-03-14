#ifndef COMMON_H
#define COMMON_H

#include <QString>

struct sw_pos{
    int day;
    int month;
    int year;
};

int days_in_month(int, int);
QString month_to_string(int);

#endif // COMMON_H
