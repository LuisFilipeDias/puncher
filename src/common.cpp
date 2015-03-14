#include "common.h"
#include <QDate>

QString month_string[] = {"January", "February", "March", "April",
                        "May", "June", "July", "August",
                        "September", "October", "November", "December"};

common::common()
{
}

int days_in_month(int month, int year)
{
    QDate *date;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 2:
        if (!date->isLeapYear(year))
            return 28;
        else
            return 29;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    }
    return -1;
}

QString month_to_string(int month)
{
    /* index - 1 for it starts at 0 */
    return month_string[month - 1];
}
