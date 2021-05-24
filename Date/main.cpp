//#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <ctime> //used for getMonth
#include <string>
#include <fstream>
#include "date.h"


int main() {

	Date localDate = Date();
	Date date1 = localDate;
	Date date2 = localDate;
	date1.addDay(1);
	date2.addDay(2);
	std::cout << localDate.getDay() << std::endl;
	std::cout << localDate.getMonth() << std::endl;
	std::cout << localDate.getYear() << std::endl;
	std::cout << date1.getWeekDayString(date1.getWeekDayInt(date1.getMonth(), date1.getDay(), date1.getYear()));


}