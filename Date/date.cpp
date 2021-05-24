#include <iostream>
#include "date.h"
//#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <ctime> //used for getMonth
#include <string>
#include <fstream>




//Default Constructor that creates a date 1/1/1900
Date::Date()
{
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int localMonth = 1 + newtime.tm_mon;
	int localDay = newtime.tm_mday;
	int localYear = 1900 + newtime.tm_year;
	month = localMonth;
	day = localDay;
	year = localYear;
	std::cout << "Default Constructor called" << std::endl;
}

//Parameterized Constructor
Date::Date(int m, int d, int y)
{
	month = d;
	day = d;
	year = y;
	std::cout << "Parameterized Constructor called" << std::endl;
}


//returns local date
int* getLocalDate()
{
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int month = 1 + newtime.tm_mon;
	int year = 1900 + newtime.tm_year;
	int day = newtime.tm_mday;
	int* calendar = new int[3];
	calendar[0] = month;
	calendar[1] = day;
	calendar[2] = year;

	return calendar;
}

//returns weekDay as an integer from 0 to 6
int Date::getWeekDayInt(int m, int d, int y)
{
	int m0, y0, d0, x;
	y0 = y - (14 - m) / 12;
	x = y0 + y0 / 4 - y0 / 100 + y0 / 400;
	m0 = m + 12 * ((14 - m) / 12) - 2;
	d0 = (d + x + (31 * m0) / 12) % 7;
	return d0;
}

//returns weekDat as a string from Sunday to Saturday
std::string Date::getWeekDayString(int d0) {
	switch (d0)
	{
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	default:
		std::cout << "getWeekDay error";
		return "Error";
	}
}

//takes a month number and returns the name of that month
std::string Date::getMonthString(int m)
{
	switch (m)
	{
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "getMonthString error";
	}
}

//checks if year is leap year or not
bool Date::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

//adds a number of days to a date and returns the updated date
int* Date::addDay(int addedDay)
{
	// int day = 28;
	// int month = 2;
	// int year = 2020;
	// int addedDay = 6;

	for (int i = 0; i < addedDay; i++)
	{
		day++;
		if (day == 32 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
		{
			month++;
			day = 1;
		}
		else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		{
			month++;
			day = 1;
		}
		else if (month == 2 && isLeapYear(year) && day == 30)
		{
			month++;
			day = 1;
		}
		else if (month == 2 && !isLeapYear(year) && day == 29)
		{
			month++;
			day = 1;
		}
		if (month == 13)
		{
			month = 1;
			year++;
		}
	}
	//cout << "Month is: " << month << endl;
	//cout << "Day is: " << day << endl;
	//cout << "Year is: " << year << endl;
	int* newDate = new int[3];
	return newDate;
}

//returns date as a string
std::string Date::dateToString()
{
	return std::string();
}

