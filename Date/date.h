#ifndef DATE_H
#define DATE_H


#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <sstream>
//including local header files in directory


class Date
{
private:
	std::string weekDay;
	int month;
	int day;
	int year;

public:
	//Default Constructor
	Date();
	//Parameterized Constructor
	Date(int m, int d, int y);
	//Getters
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }

	int getWeekDayInt(int m, int d, int y);

	std::string getWeekDayString(int d0);
	//int* getLocalDate();

	bool isLeapYear(int year);

	std::string getMonthString(int m);
	int* addDay(int addedDay);
	std::string dateToString();

};


#endif // !DATE_H