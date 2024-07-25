#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>

using namespace std;

class Date
{
private:
   int Day, Month, Year;
	int daysPerMonth[13] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int getDaysFromStart();
public:
   Date(int day = 1, int month = 1, int year = 2023);
   Date(string date);
   Date(tm date);
   void set(int day, int month, int year);
	
	void setDay(int);
   int operator-(Date other);
   Date operator+(int duration);

   int getDay();
   int getMonth();
   int getYear();
   string toString();
};

#endif