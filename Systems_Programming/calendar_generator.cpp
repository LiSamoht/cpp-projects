/*

   Thomas Li
   7/23/22

   This program outputs a full twelve-month calendar for the user based on
   his or her input for the specific year and his or her input for what day
   of the week the first day of the year starts on. The program begins by
   prompting the user to enter in the specific year of the calendar and
   additionally prompts the user to enter in what day of the week January
   1 is. The program then executes the printCalendar function, which then
   uses other functions to print each month, print the header for each month,
   determine the number of days for each month, determine what day of the week
   each month starts on, line up the dates to be printed, and print the
   dates for each month. Then, the user's desired calendar is printed to the
   output.

*/
#include <iostream>
#include <iomanip>
using namespace std;

void printCalendar(int yearNum, int startDayOfWeek);
void printMonth(int yearNum, int monthNum, int& StartDayOfWeek);
bool isLeapYear(int year);
int findDaysInMonth(int monthNum, bool isLeapYear);
void printHeaderForMonth(int monthNum);
void drawLeadingSpacesBeforeDates(int StartDayOfWeek);
void printDates(int daysInMonth, int& dayOfWeek);

const int MONTHS_IN_YEAR = 12;
const int DAYS_IN_WEEK = 7;

int main() {
	int userYear;
	int startDayOfWeek;

	cout << "What year do you want a calendar for? ";
	cin >> userYear;
	cout << "What day of the week does January 1 fall on?" << endl;
	cout << "(Enter 0 for Sunday, 1 for Monday, 6 for Saturday, etc.): ";
	cin >> startDayOfWeek;

	printCalendar(userYear, startDayOfWeek);
}






/*
   The printCalendar function prints out the entire twelve-month calendar
   through the use of a for loop that iterates 12 times, with each
   iteration printing out a single month. The function uses its two
   pass by value parameters, yearNum and startDayOfWeek, by inputting
   the information stored in them into the printMonth function which
   is utilized in the body of the for loop.
*/
void printCalendar(int yearNum, int startDayOfWeek) {
	cout << setw(11) << yearNum << endl << endl;

	for (int monthNum = 1; monthNum <= MONTHS_IN_YEAR; monthNum++) {
		printMonth(yearNum, monthNum, startDayOfWeek);
	}
}






/*
   The printMonth function uses its two pass by value parameters, yearNum and
   monthNum, along with its pass by reference parameter startDayOfWeek in
   order to print a specific month. The function inputs the yearNum parameter
   into the isLeapYear function to determine whether or not the year is a
   leap year and then inputs this value along with the monthNum parameter
   into the findDaysInMonth function to determine the number of days in the
   desired month. The function then inputs the monthNum parameter into
   the printHeaderForMonth function in order to print out the header for
   the specific month, inputs the startDayOfWeek parameter into the
   drawLeadingSpacesBeforeDates function in order to output the correct
   number of leading spaces to get ready to start printing the dates,
   and finally inputs both the data detailing the number of days in the
   month and the StartDayOfWeek parameter to print the dates.
*/
void printMonth(int yearNum, int monthNum, int& startDayOfWeek) {
	int daysInMonth = findDaysInMonth(monthNum, isLeapYear(yearNum));

	printHeaderForMonth(monthNum);
	drawLeadingSpacesBeforeDates(startDayOfWeek);
	printDates(daysInMonth, startDayOfWeek);

	cout << endl << endl;
}






/*
   The isLeapYear function takes in one pass by value parameter, year, and
   its only purpose is to determine whether or not the parameter year is
   a leap year. If the parameter year is divisible by 400, it is a leap
   year so the function returns true. However, if this was not the case
   and the year was instead only divisible by 100, the parameter year
   can't be a leap year so the function returns false. Then, if both
   of these aren't the case, the value of year can't be a century year
   so the function just checks whether or not the value is divisible by
   4 and returns the boolean value generated.
*/
bool isLeapYear(int year) {
	if (year % 400 == 0) {
		return true;
	}

	if (year % 100 == 0) {
		return false;
	}

	return year % 4 == 0;
}






/*
   The findDaysInMonth function takes in two pass by value integer and boolean
   parameters, monthNum and isLeapYear. The function uses a switch statement
   and, depending on the value of monthNum, assigns the integer numDays with
   a different value corresponding to the month. To account for leap years,
   the function assigns numDays with an extra day for case 2 if the boolean
   value of isLeapYear is true.
*/
int findDaysInMonth(int monthNum, bool isLeapYear) {
	int numDays;

	switch (monthNum) {
	case 1:
		numDays = 31;
		break;

	case 2:
		if (!isLeapYear) {
			numDays = 28;
		}
		else {
			numDays = 29;
		}
		break;

	case 3:
		numDays = 31;
		break;

	case 4:
		numDays = 30;
		break;

	case 5:
		numDays = 31;
		break;

	case 6:
		numDays = 30;
		break;

	case 7:
		numDays = 31;
		break;

	case 8:
		numDays = 31;
		break;

	case 9:
		numDays = 30;
		break;

	case 10:
		numDays = 31;
		break;

	case 11:
		numDays = 30;
		break;

	case 12:
		numDays = 31;
		break;
	}
	return numDays;
}






/*
   The printHeaderForMonth function takes in one pass by value parameter
   monthNum and uses a switch statement to output the month name corresponding
   to the value of monthNum. The function then outputs a series of end lines
   for formatting purposes, the initial letters for the days of the week,
   and a row of dash marks.
*/
void printHeaderForMonth(int monthNum) {
	switch (monthNum) {
	case 1:
		cout << setw(13) << "January" << endl << endl;
		break;

	case 2:
		cout << setw(13) << "February" << endl << endl;
		break;

	case 3:
		cout << setw(13) << "March" << endl << endl;
		break;

	case 4:
		cout << setw(13) << "April" << endl << endl;
		break;

	case 5:
		cout << setw(13) << "May" << endl << endl;
		break;

	case 6:
		cout << setw(13) << "June" << endl << endl;
		break;

	case 7:
		cout << setw(13) << "July" << endl << endl;
		break;

	case 8:
		cout << setw(13) << "August" << endl << endl;
		break;

	case 9:
		cout << setw(13) << "September" << endl << endl;
		break;

	case 10:
		cout << setw(13) << "October" << endl << endl;
		break;

	case 11:
		cout << setw(13) << "November" << endl << endl;
		break;

	case 12:
		cout << setw(13) << "December" << endl << endl;
		break;
	}
	cout << "  S  M  T  W  T  F  S" << endl;
	cout << "---------------------" << endl;
}






/*
   The drawLeadingSpacesBeforeDates function uses one pass by value parameter
   startDayOfWeek to output the correct number of leading spaces before the
   dates are printed so that the dates line up with the days of the week.
   The number of spaces needed to be drawn is three times the value
   of startDayOfWeek and the function uses a for loop to print out
   this exact number of spaces.
*/
void drawLeadingSpacesBeforeDates(int startDayOfWeek) {
	int SpacesToDraw = 3 * startDayOfWeek;

	for (int spaceCount = 0; spaceCount < SpacesToDraw; spaceCount++) {
		cout << " ";
	}
}






/*
   The printDates function takes in one pass by value parameter daysInMonth
   and one pass by reference parameter dayOfWeek. The function uses a for
   loop that iterates daysInMonth times in order to print out the dates in
   the month. The function uses setw(3) to print each date and increments
   dayOfWeek after each date is printed. However, if the dayOfWeek is equal
   to the number of days in the week, the value of dayOfWeek is reset back to
   0 and as long as the date that was printed is not the last day of the month,
   the line is ended to prepare for the next line of dates. Note that because
   dayOfWeek is pass by reference, printMonth knows about the change in
   dayOfWeek and, because its parameter is also pass by reference,
   printCalendar knows about the change in dayOfWeek. Then because of this,
   printCalendar knows exactly what day of week the next month starts on.
*/
void printDates(int daysInMonth, int& dayOfWeek) {
	for (int dateOfMonth = 1; dateOfMonth <= daysInMonth; dateOfMonth++) {
		cout << setw(3) << dateOfMonth;
		dayOfWeek = dayOfWeek + 1;

		if (dayOfWeek == DAYS_IN_WEEK) {
			dayOfWeek = 0;
			if (dateOfMonth != daysInMonth) {
				cout << endl;
			}
		}
	}
}