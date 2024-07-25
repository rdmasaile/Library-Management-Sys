#include "Date.h"
#include <iostream>
#include <string>
#include "HelperFunc.h"
#include <ctime>
#include <string>

//Date::daysPerMonth = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Date::Date(int day, int month, int year)
{
  set(day, month, year);
}

Date::Date(string date)
{
	vector<string> *data = split(date,'/');
	string* day = data->data();
	string* month = data->data()+1;
	string* year = data->data()+2;
   set(stoi(*day), stoi(*month), stoi(*year));
}
Date::Date(tm date){
  set(date.tm_mday, date.tm_mon + 1, date.tm_year + 1900);
}

void Date::set(int day, int month, int year){
  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
  {
     exit(1);
  }
  Day = day;
  Month = month;
  Year = year;
}

void Date::setDay(int dy){
	Day = dy;
}
int Date::operator-(Date other){	
	return getDaysFromStart() - other.getDaysFromStart();
} 

int Date::getDaysFromStart(){
	int y = getYear();
	long int days = y * 365 + getDay();
	
	for(int i = 0;i<getMonth();i++)
		days += daysPerMonth[i];
	
	if(getMonth() <= 2){
		y--;
	}
	
	days +=  y/4 - y/100 + y/400;
	
	return days;
}      

Date Date::operator+(int duration)
{	
	
	int dy = getDay() + duration;
	int mn = Month;
	int yr = Year;
	
	if(dy > daysPerMonth[Month]){
		dy -= daysPerMonth[Month];
	 	mn++;
	}	
	if(mn > 12){
		mn = 1;
		yr++;
	}
	return Date(dy, mn, yr);
}

int Date::getDay()
{
  return Day;
}
int Date::getMonth()
{
  return Month;
}
int Date::getYear()
{
  return Year;
}
string Date::toString()
{
  return to_string(getDay()) + '/' + to_string(getMonth()) + "/" + to_string(getYear());
}
