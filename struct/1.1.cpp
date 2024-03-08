#include <iostream>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;

    int compare(Date other)
    {
        if (year > other.year)
        {
            return 1;
        }
        else if (year < other.year)
        {
            return -1;
        }
        else
        {
            if (month > other.month)
            {
                return 1;
            }
            else if (month < other.month)
            {
                return -1;
            }
            else
            {
                if (day > other.day)
                {
                    return 1;
                }
                else if (day < other.day)
                {
                    return -1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    int diff(Date other)
    {
        int days = day - other.day;
        days += (month - other.month) * 30;
        days += (year - other.year) * 365;
        return days;
    }
};

void read(Date &datum)
{
    cin >> datum.day >> datum.month >> datum.year;
}

void print(Date datum)
{
    cout << datum.year << "." << datum.month << "." << datum.day << endl;
}

int main()
{
    Date d1, d2;
    read(d1);
    read(d2);

    int res = d1.compare(d2);
    cout << res;
    if (res == 0)
    {
        cout << "Dates are equal " << endl;
    }
    else if (res > 0)
    {
        cout << "Difference is " << d1.diff(d2) << endl;
    }
    else
    {
        cout << "Difference is " << d2.diff(d1) << endl;
    }
}