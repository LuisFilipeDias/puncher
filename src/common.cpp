#include "common.h"

common::common()
{
}

int days_in_month(int month)
{
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
        return 28; // or 29 calculate
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    }
    return -1;
}
