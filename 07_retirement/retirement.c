#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info
{
    int months;
    double contribution, rate_of_return;
} retire_info;

double totalReturns(double currentSavings, double contribution, double rate)
{
    double interestReturn = currentSavings * rate;
    return interestReturn + contribution + currentSavings;
}

double monthlyInterest(double interest)
{
    return interest / 12;
}

void printOut(int ageInitial, int monthsInitial, double initial)
{
    printf("Age %3d month %2d you have $%.2lf\n", ageInitial, monthsInitial, initial);
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{

    int monthsInitial = startAge % 12;
    int ageInitial = startAge / 12;
    double monthlyRateW = monthlyInterest(working.rate_of_return);
    double monthlyRateR = monthlyInterest(retired.rate_of_return);

    for (int i = 0; i < working.months; ++i)
    {
        printOut(ageInitial, monthsInitial, initial);
        initial = totalReturns(initial, working.contribution, monthlyRateW);

        if (monthsInitial < 11)
        {
            monthsInitial++;
        }
        else
        {
            monthsInitial = 0;
            ageInitial++;
        }
    }
 
    for (int j = 0; j < retired.months; ++j)
    {
        printOut(ageInitial, monthsInitial, initial);
        initial = totalReturns(initial, retired.contribution, monthlyRateR);
        if (monthsInitial < 11)
        {
            monthsInitial++;
        }
        else
        {
            monthsInitial = 0;
            ageInitial++;
        }
    }
}

int main(void)
{
    retire_info working1 = {489, 1000, 0.045};
    retire_info retired1 = {384, -4000, 0.01};
    retirement(327, 21345, working1, retired1);
}