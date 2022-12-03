#include <iostream> //standard input/output streams
#include <iomanip> //setw
#include <cctype> //declares a set of functions to classify and transform characters
#include <ctime> //functions to get and use date and time information
#include <windows.h> //SetConsoleCursorPosition, SetConsoleCursor, gotoxy,GetAsyncKeyState
#include <sstream> // stringstream
#include <string>
#pragma warning(disable: 4996)

using namespace std;

void gotoxy(int x, int y) //set cursor position to a exact coordinate
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Color(int color) //function to change color of text and backround
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ShowConsoleCursor(bool showFlag) //function to enable or disable cursor
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
const std::string currentTime()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);
	return buf;
}

bool alpha(string name) { //function to check a string if it contains characters other than alphanumerics
	for (int z = 0; z < name.size(); z++) {
		if (!isalpha(name[z])) {
			if (isspace(name[z])) {
				continue;
			}
			else
				return false;
		}

	}
	return true;
}

int main() {
	string  date = "", surname[11], frstname[11], mi[11], pssngrs, type1, destination1, schedule, plane1, payment, selection, availInsurance, age_str, baggage_str, logo = "\t\t\t\t\t  \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\t\t\t\t\t  \xba     \xdb   \xdb \xdb\xdf\xdf\xdf \xdb\xdf\xdf\xdc \xdb\xdf\xdf\xdb      \xba\n   \t\t\t\t\t  \xba     \xdb\xdb \xdb\xdb \xdb\xfe\xfe  \xdb\xdc\xdc\xdf \xdb\t  \xba\n   \t\t\t\t\t  \xba     \xdb \xdb \xdb \xdb\xdc\xdc\xdc \xdb  \xdb \xdb\xdc\xdc\xdb      \xba\n \t\t\t\t\t  \xba A    I    R    L    I    N   E\xba\n\t\t\t\t\t  \xba     R E S E R V A T I O N S   \xba\n\t\t\t\t\t  \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
	int pssngr, x, ctr1, ctr2, ctr3, group = 0, hr, hr2, conv, young[11], senior[11], age[11], index1 = 1, index2 = 1, index3 = 1; char yn = 'x', type[10000], sched[10000], destination[10000], plane[10000], insurance1[10000], type2, sched2;
	int excessBaggage[11], year, year1, month1, day1, seniors, child = 0, month, day, is_num = 0, decimal_count = 0; double disc, pssngr_fee[11], insurance[11], trip_fare, baggage[11], BaggageFee[11];
	double amount, vat, gross = 0, gross2, change, cash;
	bool is_num_bool = 0, contains_spaces = false, running = true;
	time_t t = time(0);

	system("color f1"); //set the main color of text and backround of program
	cout << logo;
	cout << "\n\n\n\t\t\t\t" << char(201);      for (int i = 0; i < 51; i++) { cout << char(205); }      cout << char(187) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "                                                   "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "                     WELCOME                       "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "                                                   "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "  WOULD YOU LIKE TO MAKE AN AIRLINE RESERVATION?   "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "                  YES       NO                     "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "                                                   "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(200);      for (int i = 0; i < 51; i++) { cout << char(205); }      cout << char(188) << endl;
	gotoxy(50, 14);
	gotoxy(1, 14);
	ShowConsoleCursor(false); //make cursor invisible
	cout << "\t\t\t\t"; Color(241); cout << char(186) << "                 " << ">YES"; Color(240); cout << "       NO                     "; Color(241); cout << char(186) << endl;
	yn = 'Y';
	gotoxy(54, 14);

	system("pause>nul");
	while (running) { //run a loop with a bool as a condition

		if (GetAsyncKeyState(VK_RIGHT)) { //detect if left arrow key is pressed
			gotoxy(1, 14);
			cout << "\t\t\t\t" << char(186); Color(240); cout << "                  YES"; Color(241); cout << "      >NO" << "                     " << char(186) << endl; //moves arrow and highltght NO
			yn = 'N';
			gotoxy(63, 14);
		}
		if (GetAsyncKeyState(VK_LEFT)) { //detect if right arrow key is pressed
			gotoxy(1, 14);
			cout << "\t\t\t\t"; Color(241); cout << char(186) << "                 " << ">YES"; Color(240); cout << "       NO                     "; Color(241); cout << char(186) << endl; //moves arrow and highltght YES
			yn = 'Y';
			gotoxy(54, 14);
		}
		if (GetAsyncKeyState(VK_RETURN)) { //detect if enter key is pressed
			switch (yn) { //switch case of decision of user
			case 'y': case 'Y':
				system("cls");
				running = false; //sets bool value to false to stop loop
				gotoxy(1, 1);
				break;
			case 'n': case 'N': // ends program if NO isthe choice
				system("cls");
				cout << logo;
				cout << "\n\n\n\t\t\t\t\t      Thank You! And Goodbye!";
				return 0;
				break;
			}
		}
	}

	cout << logo;
	//do loading berfore program starts
	cout << "\n\n\n\n\n\t\t\t\t\t\xfe MERC Airlines Reservations is Loading \xfe\n\n";
	char a = 177, b = 219;
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i <= 22; i++)
		cout << a;
	cout << "\r";
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i <= 22; i++)
	{
		cout << b;
		for (int j = 0; j <= 3e7; j++);
	}

	system("cls");
	cout << logo;
	cout << "\n\n\t\t\t ";
	cout << char(201);      for (int i = 0; i < 66; i++) { cout << char(205); }      cout << char(187) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186); Color(240); cout << "                     Press Any Key to Proceed  "; Color(241); cout << setw(20) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(200);      for (int i = 0; i < 66; i++) { cout << char(205); }      cout << char(188) << endl;
	system("pause>nul");

	system("cls");
	cout << logo;
	//prints all of available trip destinations
	cout << "\n\n\n\n\t\t\t\t      " << char(201);  for (int i = 0; i < 40; i++) { cout << char(205); }  cout << char(187) << endl;
	cout << "\t\t\t\t      " << char(186) << "            \xfe DESTINATIONS \xfe            " << char(186) << endl;
	cout << "\t\t\t\t      " << char(204);  for (int i = 0; i < 40; i++) { cout << char(205); }  cout << char(185) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0 DOMESTIC FLIGHTS \xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0" << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (A) \xb3 Batanes              "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (B) \xb3 Bacolod              "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (C) \xb3 Palawan              "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (D) \xb3 Davao                "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(204);  for (int i = 0; i < 40; i++) { cout << char(205); }  cout << char(185) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "      Please Refer from the Above       "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << " And Enter Desired Destination(A - I):  "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(200);      for (int i = 0; i < 40; i++) { cout << char(205); }      cout << char(188) << endl;
	gotoxy(77, 23);
	cin >> destination;
	while ((destination[0] > 'i' || destination[0] < 'a') && (destination[0] > 'I' || destination[0] < 'A') || (destination[1] > 0)) { //input validation
		destination[1] = 0;
		gotoxy(1, 30);
		cout << "\t\t\t\t      " << char(186); Color(240); cout << " INVALID Destination, Please Re-Input:  "; Color(241); cout << char(186) << endl;
		gotoxy(77, 30);
		cin >> destination;
	}
	switch (destination[0]) { //switch case to determine the price and assign whether international or domestic depending on destinations
	case 'a': case 'A':
		destination1 = "Batanes";
		selection = "D"; //assigns international or domestic
		if (plane[0] == '1') { //assigns price of trip depending on type of plane
			trip_fare = 8650;
		}
		else {
			trip_fare = 15500;
		}
		break;
	case 'b': case 'B':
		destination1 = "Bacolod";
		selection = "D";
		if (plane[0] == '1') {
			trip_fare = 4543;
		}
		else {
			trip_fare = 9500;
		}
		break;
	case 'c': case 'C':
		destination1 = "Palawan";
		selection = "D";
		if (plane[0] == '1') {
			trip_fare = 5882;
		}
		else {
			trip_fare = 13200;
		}
		break;
	case 'd': case 'D':
		destination1 = "Davao";
		selection = "D";
		if (plane[0] == '1') {
			trip_fare = 4096;
		}
		else {
			trip_fare = 9230;
		}
		break;
	}

	system("cls");
	cout << logo;
	tm* now = localtime(&t); //get current time or date
	//prints out and input of schedule of flight
	cout << "\n\n\n\t\t      " << char(201);  for (int i = 0; i < 74; i++) { cout << char(205); }  cout << char(187) << endl;
	cout << "\t\t      " << char(186); Color(240); cout << "       When would you like your reservation flight to be scheduled?       "; Color(241); cout << char(186) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(186); Color(240); cout << "             Kindly indicate the Date of the Year, Month, Day.            "; Color(241); cout << char(186) << endl;
	cout << "\t\t      " << char(204);  for (int i = 0; i < 74; i++) { cout << char(205); }  cout << char(185) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Year: "; Color(241); cout << setw(40) << char(186) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Month: "; Color(241); cout << setw(40) << char(186) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Day: "; Color(241); cout << setw(40) << char(186) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(200);      for (int i = 0; i < 74; i++) { cout << char(205); }      cout << char(188) << endl;
	gotoxy(58, 15);
	getline(cin >> ws, date); //input of year of schedule
	//loop to validate whether input string has any other characters other than numeric
	do {

		for (int i = 0; i < date.size(); i++) //checks if input have spcaes
		{
			if (isspace(date[i]))
				contains_spaces = true;
		}

		if ((date[0] == '0' && isdigit(date[1]))) // input can't start from 0
			is_num = 0;
		else
		{
			for (int i = 0; i < date.size(); i++)
			{
				if (isdigit(date[i]))
					is_num++;
				if (date[i] == '.')
					decimal_count++;
			}
		}

		if (decimal_count == 1) //validates decimals 66.7 8..9.9.9..9.9
			is_num = 0;

		if (is_num == date.size() && contains_spaces == false) //determine whether the input has passed the previous validations
		{
			stringstream str_stream_object(date);
			str_stream_object >> year; //converts the numbers in the string into int
			if (year < (now->tm_year + 1900) || year>(now->tm_year + 1901)) { //validates if input year is less than or mare than the expected available years
				gotoxy(1, 15);
				cout << "\t\t      " << char(186); Color(241); cout << setw(35) << "Invalid Year: "; Color(241); cout << setw(40) << char(186) << endl;
				gotoxy(58, 15);
				date = "";
				getline(cin >> ws, date);
				is_num_bool = 0;
			}
			else {
				is_num_bool = 1; //change value of bool to stop loop
				break;
			}

		}
		else if (is_num == 0) { //input has characters other than numerics
			gotoxy(1, 15);
			cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Year: "; Color(241); cout << setw(40) << char(186) << endl;
			gotoxy(58, 15);
			date = "";
			getline(cin >> ws, date);
			is_num_bool = 0;
		}
		//reset value for use on the next loop
		is_num_bool = 0;
		is_num = 0;
		decimal_count = 0;
		contains_spaces = false;
	} while (is_num_bool == 0);


	gotoxy(44, 15);
	cout << "        Year: ";
	is_num_bool = 0;
	gotoxy(58, 17);
	date = "";
	getline(cin >> ws, date); // month of date schedule
	do {

		for (int i = 0; i < date.size(); i++)
		{
			if (isspace(date[i]))
				contains_spaces = true;
		}

		if ((date[0] == '0' && isdigit(date[1]))) // can't start from 0
			is_num = 0;
		else
		{
			for (int i = 0; i < date.size(); i++)
			{
				if (isdigit(date[i]))
					is_num++;
				if (date[i] == '.')
					decimal_count++;
			}
		}

		if (decimal_count == 1) //decimals 66.7 // 8..9.9.9..9.9
			is_num = 0;

		if (is_num == date.size() && contains_spaces == false)
		{
			stringstream str_stream_object(date);
			str_stream_object >> month; //convertion of string numerics into int
			if (year == (now->tm_year + 1900)) { //checks the year input if whether the same as the current year
				if (month < (now->tm_mon + 1) || month > 12) { //validates month and cannot input previous months
					gotoxy(1, 17);
					cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Month: "; Color(241); cout << setw(40) << char(186) << endl;
					gotoxy(58, 17);
					getline(cin >> ws, date);
					is_num_bool = 0;
				}
				else {
					is_num_bool = 1;
					break;
				}
			}
			else if (year > (now->tm_year + 1900)) { //checks of input is next year for schedule
				if (month < 1 || month > 12) { //validates month from 1-12
					gotoxy(1, 17);
					cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Month: "; Color(241); cout << setw(40) << char(186) << endl;
					gotoxy(58, 17);
					getline(cin >> ws, date);
					is_num_bool = 0;
				}
				else {
					is_num_bool = 1;
					break;
				}
			}
			else {
				is_num_bool = 1;
				break;
			}
		}
		else if (is_num == 0) { //input has characters other than numerics
			gotoxy(1, 17);
			cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Month: "; Color(241); cout << setw(40) << char(186) << endl;
			gotoxy(58, 17);
			getline(cin >> ws, date);
			is_num_bool = 0;
		}
		is_num_bool = 0;
		is_num = 0;
		decimal_count = 0;
		contains_spaces = false;
	} while (is_num_bool == 0);

	gotoxy(43, 17);
	cout << "        Month: ";
	gotoxy(58, 19);
	date = "";
	getline(cin >> ws, date); //input of day of date schedule
	do {

		for (int i = 0; i < date.size(); i++)
		{
			if (isspace(date[i]))
				contains_spaces = true;
		}
		if ((date[0] == '0' && isdigit(date[1]))) // can't start from 0
			is_num = 0;
		else
		{
			for (int i = 0; i < date.size(); i++)
			{
				if (isdigit(date[i]))
					is_num++;
				if (date[i] == '.')
					decimal_count++;
			}
		}

		if (decimal_count == 1) //decimals 66.7 // 8..9.9.9..9.9
			is_num = 0;

		if (is_num == date.size() && contains_spaces == false)
		{
			stringstream str_stream_object(date);
			str_stream_object >> day; //convertion of string numerics into int
			//get the month input and validate the input day and limit it by the corresponding month
			switch (month) {
			case 1: case 3: case 5: case 8: case 10: case 12: //jan, mar, may, july, aug, oct, dec
				if (day > 31) {
					gotoxy(1, 19);
					cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Day: "; Color(241); cout << setw(40) << char(186) << endl;
					gotoxy(58, 19);
					getline(cin >> ws, date);
					is_num_bool = 0;
				}
				break;
			case 2: //feb
				if (day > 28) {
					gotoxy(1, 19);
					cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Day: "; Color(241); cout << setw(40) << char(186) << endl;
					gotoxy(58, 19);
					getline(cin >> ws, date);
					is_num_bool = 0;

				}
				break;
			case 4: case 6: case 7: case 9: case 11: //april, june, sept, nov
				if (day > 30) {
					gotoxy(1, 19);
					cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Day: "; Color(241); cout << setw(40) << char(186) << endl;
					gotoxy(58, 19);
					getline(cin >> ws, date);
					is_num_bool = 0;

				}
				break;
			}
			if (month == (now->tm_mon + 1) && year == (now->tm_year + 1900)) { //gets the value of month and year and whether it has the same date as today
				if (day < (now->tm_mday)) { //day con't be any previous day
					gotoxy(1, 19);
					cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Day: "; Color(241); cout << setw(40) << char(186) << endl;
					gotoxy(58, 19);
					date = "";
					getline(cin >> ws, date);
					is_num_bool = 0;
				}
				else {
					is_num_bool = 1;
					break;
				}
			}
			else if (month > (now->tm_mon + 1)) {
				if (day < 1) { // checks if input is any negatice value
					gotoxy(1, 19);
					cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Day: "; Color(241); cout << setw(40) << char(186) << endl;
					gotoxy(58, 19);
					date = "";
					getline(cin >> ws, date);
					is_num_bool = 0;
				}
				else {
					is_num_bool = 1;
					break;
				}
			}
			else {
				is_num_bool = 1;
				break;
			}
		}
		else if (is_num == 0) { //input has characters other than numerics
			gotoxy(1, 19);
			cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Invalid Day: "; Color(241); cout << setw(40) << char(186) << endl;
			gotoxy(58, 19);
			getline(cin >> ws, date);
			is_num_bool = 0;
		}
		is_num_bool = 0;
		is_num = 0;
		decimal_count = 0;
		contains_spaces = false;
	} while (is_num_bool == 0);

	system("cls");
	cout << logo;
	//prints all of available trip time destinations
	cout << "\n\n\n\n\t\t\t\t      " << char(201);  for (int i = 0; i < 40; i++) { cout << char(205); }  cout << char(187) << endl;
	cout << "\t\t\t\t      " << char(186) << "            \xfe ONWARD FLIGHT \xfe           " << char(186) << endl;
	cout << "\t\t\t\t      " << char(204);  for (int i = 0; i < 40; i++) { cout << char(205); }  cout << char(185) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0 FLIGHT SCHEDULES \xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0" << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (A) \xb3 12:00am              "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (B) \xb3 2:00am               "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (C) \xb3 4:00am               "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (D) \xb3 6:00am               "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (E) \xb3 8:00am               "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (F) \xb3 10:00am              "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (G) \xb3 12:00pm              "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (H) \xb3 2:00pm               "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (I) \xb3 4:00pm               "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (J) \xb3 6:00pm               "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (K) \xb3 8:00pm               "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186) << "                                        " << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "             (L) \xb3 10:00pm              "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(204);  for (int i = 0; i < 40; i++) { cout << char(205); }  cout << char(185) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "      Please Refer from the Above       "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(186); Color(240); cout << "    And Enter Desired Time (A - L):     "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t      " << char(200);      for (int i = 0; i < 40; i++) { cout << char(205); }      cout << char(188) << endl;
	gotoxy(75, 41);
	cin >> sched;
	while ((sched[0] > 'l' || sched[0] < 'a') && (sched[0] > 'L' || sched[0] < 'A') || (sched[1] > 0)) { //input validation
		sched[1] = 0;
		gotoxy(1, 41);
		cout << "\t\t\t\t      " << char(186); Color(240); cout << " INVALID Schedule, Please Re-Input:     "; Color(241); cout << char(186) << endl;
		gotoxy(75, 42);
		cin >> sched;
	}
	switch (sched[0]) { //switch case to determine time
	case 'a': case 'A':
		schedule = "12:00am";
		schedule = "12:00am";
		hr = 0; // 12am is 0 in 24 hr format
		break;

	case 'b': case 'B':
		schedule = "2:00am";
		hr = 2; // 2am is 2 in 24 hr format
		break;

	case 'c': case 'C':
		schedule = "4:00am";
		hr = 4; // 4am is 4 in 24 hr format
		break;

	case 'd': case 'D':
		schedule = "6:00am";
		hr = 6; // 6am is 6 in 24 hr format
		break;

	case 'e': case 'E':
		schedule = "8:00am";
		hr = 8; // 8am is 8 in 24 hr format
		break;

	case 'f': case 'F':
		schedule = "10:00am";
		hr = 10; // 10am is 10 in 24 hr format
		break;

	case 'g': case 'G':
		schedule = "12:00pm";
		hr = 12; // 12pm is 12 in 12 hr format
		break;

	case 'h': case 'H':
		schedule = "2:00pm";
		hr = 14; // 2pm is 14 in 24 hr format
		break;

	case 'i': case 'I':
		schedule = "4:00pm";
		hr = 16; // 4pm is 16 in 24 hr format
		break;

	case 'j': case 'J':
		schedule = "6:00pm";
		hr = 18; // 6pm is 18 in 24 hr format
		break;

	case 'k': case 'K':
		schedule = "8:00pm";
		hr = 20; // 8pm is 20 in 24 hr format
		break;

	case 'l': case 'L':
		schedule = "10:00pm";
		hr = 22; // 10pm is 22 in 24 hr format
		break;
	}
	stringstream str_stream_object(currentTime());
	str_stream_object >> conv;

	if (year == now->tm_year + 1900 && month == now->tm_mon + 1 && day == now->tm_mday)
	{
		while (hr <= conv)
		{

			stringstream str_stream_object(currentTime());
			str_stream_object >> conv;
			hr = 24;
			sched[0] = 0;
			gotoxy(1, 41);
			cout << "\t\t\t\t      " << char(186); Color(240); cout << " INVALID Schedule, Please Re-Input:     "; Color(241); cout << char(186) << endl;
			gotoxy(75, 41);
			cin >> sched;
			cout << "\t\t\t\t      " << char(200);      for (int i = 0; i < 40; i++) { cout << char(205); }      cout << char(188) << endl;
			while ((sched[0] > 'l' || sched[0] < 'a') && (sched[0] > 'L' || sched[0] < 'A') || (sched[1] > 0))
			{ //input validation
				sched[1] = 0;
				gotoxy(1, 42);
				cout << "\t\t\t\t      " << char(186); Color(240); cout << " INVALID Schedule, Please Re-Input:     "; Color(241); cout << char(186) << endl;
				gotoxy(75, 42);
				cin >> sched;
				cout << "\t\t\t\t      " << char(200);      for (int i = 0; i < 40; i++) { cout << char(205); }      cout << char(188) << endl;
			}
			switch (sched[0]) { //switch case to determine time

			case 'a': case 'A':
				schedule = "12:00am";
				hr = 0; // 12am is 0 in 24 hr format
				break;

			case 'b': case 'B':
				schedule = "2:00am";
				hr = 2; // 2am is 2 in 24 hr format
				break;

			case 'c': case 'C':
				schedule = "4:00am";
				hr = 4; // 4am is 4 in 24 hr format
				break;

			case 'd': case 'D':
				schedule = "6:00am";
				hr = 6; // 6am is 6 in 24 hr format
				break;

			case 'e': case 'E':
				schedule = "8:00am";
				hr = 8; // 8am is 8 in 24 hr format
				break;

			case 'f': case 'F':
				schedule = "10:00am";
				hr = 10; // 10am is 10 in 24 hr format
				break;

			case 'g': case 'G':
				schedule = "12:00pm";
				hr = 12; // 12pm is 12 in 24 hr format
				break;

			case 'h': case 'H':
				schedule = "2:00pm";
				hr = 14; // 2pm is 14 in 24 hr format
				break;

			case 'i': case 'I':
				schedule = "4:00pm";
				hr = 16; // 4pm is 16 in 24 hr format
				break;

			case 'j': case 'J':
				schedule = "6:00pm";
				hr = 18; // 6pm is 18 in 24 hr format
				break;

			case 'k': case 'K':
				schedule = "8:00pm";
				hr = 20; // 8pm is 20 in 24 hr format
				break;

			case 'l': case 'L':
				schedule = "10:00pm";
				hr = 22; // 10pm is 22 in 12 hr format
				break;
			}
		}
	}


	system("cls");
	cout << logo;
	//asks user how many passenger reservation
	cout << "\n\n\n\t\t\t ";
	cout << char(201);      for (int i = 0; i < 66; i++) { cout << char(205); }      cout << char(187) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186); Color(240); cout << "                Please State How Many Passengers:  "; Color(241); cout << setw(16) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(200);      for (int i = 0; i < 66; i++) { cout << char(205); }      cout << char(188) << endl;
	gotoxy(76, 12);
	is_num_bool = 0;
	is_num = 0;
	getline(cin >> ws, pssngrs); //input
	do {

		for (int i = 0; i < pssngrs.size(); i++)
		{
			if (isspace(pssngrs[i]))
				contains_spaces = true;
		}

		if ((pssngrs[0] == '0' && isdigit(pssngrs[1]))) // can't start from 0
			is_num = 0;
		else
		{
			for (int i = 0; i < pssngrs.size(); i++)
			{
				if (isdigit(pssngrs[i]))
					is_num++;
				if (pssngrs[i] == '.')
					decimal_count++;
			}
		}

		if (decimal_count == 1) //decimals 66.7 // 8..9.9.9..9.9
			is_num = 0;

		if (is_num == pssngrs.size() && contains_spaces == false)
		{
			stringstream str_stream_object(pssngrs);
			str_stream_object >> pssngr;
			if (plane[0] == '1') { //when type of plane is private, maximum of passengers is 10
				if (pssngr > 10 || pssngr < 1) {
					gotoxy(1, 11);
					cout << "\t\t\t " << char(186); Color(240); cout << "                           Please Retry"; Color(241); cout << setw(28) << char(186) << endl;
					gotoxy(1, 12);
					cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
					gotoxy(1, 13);
					cout << "\t\t\t " << char(186); Color(240); cout << " And Enter an Approriate Number of Passenger Reservation(1-10):   "; Color(241); cout << char(186) << endl;
					gotoxy(90, 13);
					getline(cin >> ws, pssngrs);
					is_num_bool = 0;
				}
				else {
					is_num_bool = 1;
					break;
				}
			}
			else if (plane[0] == '2') { //when type of plane is business, maximum of passengers is 6
				if (pssngr > 6 || pssngr < 1) {
					gotoxy(1, 11);
					cout << "\t\t\t " << char(186); Color(240); cout << "                           Please Retry"; Color(241); cout << setw(28) << char(186) << endl;
					gotoxy(1, 12);
					cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
					gotoxy(1, 13);
					cout << "\t\t\t " << char(186); Color(240); cout << "  And Enter an Approriate Number of Passenger Reservation(1-6):   "; Color(241); cout << char(186) << endl;
					gotoxy(90, 13);
					getline(cin >> ws, pssngrs);
					is_num_bool = 0;
				}
				else {
					is_num_bool = 1;
					break;
				}
			}
			else {
				is_num_bool = 1;
				break;
			}

		}
		else if (is_num == 0) { //input has characters other than numerics
			gotoxy(1, 11);
			cout << "\t\t\t " << char(186); Color(240); cout << "                           Please Retry"; Color(241); cout << setw(28) << char(186) << endl;
			gotoxy(1, 12);
			cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
			gotoxy(1, 13);
			cout << "\t\t\t " << char(186); Color(240); cout << "    And Enter an Approriate Number of Passenger Reservation:      "; Color(241); cout << char(186) << endl;
			gotoxy(87, 13);
			getline(cin >> ws, pssngrs);
			is_num_bool = 0;
		}
		is_num_bool = 0;
		is_num = 0;
		decimal_count = 0;
		contains_spaces = false;
	} while (is_num_bool == 0);

	if (pssngr > 5) { //checks if reservations is mare than 5 to reference later for discount
		group = 1;
	}

	ctr1 = 0;
	bool hasMinorPassngr = false;
	bool hasAdultPssngr = false;

	system("cls");
	//loop that will ask each pasengers their information
	while (ctr1 != pssngr) {
		cout << logo;
		cout << "\n\n\n\n\t\t      " << char(201);  for (int i = 0; i < 74; i++) { cout << char(205); }  cout << char(187) << endl;
		cout << "\t\t      " << char(186) << " \xfe Please Enter the Names and Corresponding Age of the Passengers Below \xfe " << char(186) << endl;
		cout << "\t\t      " << char(204);  for (int i = 0; i < 74; i++) { cout << char(205); }  cout << char(185) << endl;
		cout << "\t\t      " << char(186) << setw(40) << " \xfe PASSENGER " << index1 << " \xfe " << setw(31) << char(186) << endl;
		cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
		cout << "\t\t      " << char(186); Color(240); cout << "                    Surname: "; Color(241); cout << setw(46) << char(186) << endl;
		cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
		cout << "\t\t      " << char(186); Color(240); cout << "                 First Name: "; Color(241); cout << setw(46) << char(186) << endl;
		cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
		cout << "\t\t      " << char(186); Color(240); cout << "             Middle Initial: "; Color(241); cout << setw(46) << char(186) << endl;
		cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
		cout << "\t\t      " << char(186); Color(240); cout << "                        Age: "; Color(241); cout << setw(46) << char(186) << endl;
		cout << "\t\t      " << char(204);  for (int i = 0; i < 74; i++) { cout << char(205); }  cout << char(185) << endl;
		cout << "\t\t      " << char(186); Color(240); cout << "                        Baggage Weight (Kg): "; Color(241); cout << setw(30) << char(186) << endl;
		cout << "\t\t      " << char(200);      for (int i = 0; i < 74; i++) { cout << char(205); }      cout << char(188) << endl;
		gotoxy(52, 15);
		getline(cin >> ws, surname[index1]); //input of surname
		while (alpha(surname[index1]) == false) { //uses the alpha function to validate whether the input has any other characters other than alphabet
			gotoxy(1, 15);
			cout << "\t\t      " << char(186); Color(240); cout << "            Invalid Surname: "; Color(241); cout << setw(46) << char(186) << endl;
			gotoxy(52, 15);
			getline(cin >> ws, surname[index1]);
			alpha(surname[index1]);
		}
		gotoxy(1, 15);
		cout << "\t\t      " << char(186); Color(240); cout << "                    Surname: "; Color(241);
		gotoxy(52, 17);
		getline(cin >> ws, frstname[index1]); //input of firstname
		while (alpha(frstname[index1]) == false) { //uses the alpha function to validate whether the input has any other characters other than alphabet
			gotoxy(1, 17);
			cout << "\t\t      " << char(186); Color(240); cout << "         Invalid First Name: "; Color(241); cout << setw(46) << char(186) << endl;
			gotoxy(52, 17);
			getline(cin >> ws, frstname[index1]);
			alpha(frstname[index1]);
		}
		gotoxy(1, 17);
		cout << "\t\t      " << char(186); Color(240); cout << "                 First Name: "; Color(241);
		gotoxy(52, 19);
		getline(cin, mi[index1]); //input of middle intital
		while (alpha(mi[index2]) == false) { //uses the alpha function to validate whether the input has any other characters other than alphabet
			gotoxy(1, 19);
			cout << "\t\t      " << char(186); Color(240); cout << "     Invalid Middle Initial: "; Color(241); cout << setw(46) << char(186) << endl;
			gotoxy(52, 19);
			getline(cin, mi[index2]);
			alpha(mi[index2]);
		}
		gotoxy(1, 19);
		cout << "\t\t      " << char(186); Color(240); cout << "             Middle Initial: "; Color(240);
		gotoxy(52, 21);
		getline(cin >> ws, age_str); //input of age
		//loop for validation of age whether it contains any other charaters other than numbers
		do {

			for (int i = 0; i < age_str.size(); i++)
			{
				if (isspace(age_str[i]))
					contains_spaces = true;
			}

			if ((age_str[0] == '0' && isdigit(age_str[1]))) // can't start from 0
				is_num = 0;
			else
			{
				for (int i = 0; i < age_str.size(); i++)
				{
					if (isdigit(age_str[i]))
						is_num++;
					if (age_str[i] == '.')
						decimal_count++;
				}
			}

			if (decimal_count == 1) //decimals 66.7 // 8..9.9.9..9.9
				is_num = 0;

			if (is_num == age_str.size() && contains_spaces == false)
			{
				stringstream str_stream_object(age_str);
				str_stream_object >> age[index1];
				if (age[index1] > 120 || age[index1] < 1) {
					gotoxy(1, 21);
					cout << "\t\t      " << char(186); Color(240); cout << "                Invalid Age: "; Color(241); cout << setw(46) << char(186) << endl;
					gotoxy(52, 21);
					getline(cin >> ws, age_str);
					is_num_bool = 0;
				}
				else {
					is_num_bool = 1;
				}

			}
			else if (is_num == 0) {
				gotoxy(1, 21);
				cout << "\t\t      " << char(186); Color(240); cout << "                Invalid Age: "; Color(241); cout << setw(46) << char(186) << endl;
				gotoxy(52, 21);
				getline(cin >> ws, age_str);
				is_num_bool = 0;
			}

			is_num = 0;
			decimal_count = 0;
			contains_spaces = false;
			stringstream age_int(age_str);
			int age;
			age_int >> age;

			//validation for passengers for minor/s
			if (age < 18)
			{
				hasMinorPassngr = true;

			}
			else {
				hasAdultPssngr = true;
			}

			if (ctr1 == (pssngr - 1) && hasAdultPssngr == false && hasMinorPassngr == true)
			{
				gotoxy(1, 21);
				cout << "\t\t      " << char(186); Color(240); cout << "                Invalid Age: "; Color(241); cout << setw(46) << char(186) << endl;
				gotoxy(52, 21);
				getline(cin >> ws, age_str);
				is_num_bool = 0;
			}
			else {
				is_num_bool = 1;
			}
		} while (is_num_bool == 0);
		gotoxy(1, 21);
		cout << "\t\t      " << char(186); Color(240); cout << "                        Age: "; Color(240);
		gotoxy(68, 23);

		getline(cin >> ws, baggage_str); //input of weight of baggage
		//loop for validation of baggage weight whether it contains any other charaters other than numbers
		do {

			for (int i = 0; i < baggage_str.size(); i++)
			{
				if (isspace(baggage_str[i]))
					contains_spaces = true;
			}

			if ((baggage_str[0] == '0' && isdigit(baggage_str[1]))) // can't start from 0
				is_num = 0;
			else
			{
				for (int i = 0; i < baggage_str.size(); i++)
				{
					if (isdigit(baggage_str[i]))
						is_num++;
					if (baggage_str[i] == '.')
						decimal_count++;
				}
			}

			if (decimal_count == 1) //decimals 66.7 // 8..9.9.9..9.9
				is_num = 0;

			if (is_num == baggage_str.size() && contains_spaces == false)
			{
				stringstream str_stream_object(baggage_str);
				str_stream_object >> baggage[index2];
				if (baggage[index2] > 30 || baggage[index2] < 1) {
					gotoxy(1, 23);
					cout << "\t\t      " << char(186); Color(240); cout << "                        Baggage Weight (Kg): "; Color(241); cout << setw(30) << char(186) << endl;
					gotoxy(68, 23);
					getline(cin >> ws, baggage_str);
					is_num_bool = 0;
				}
				else {
					is_num_bool = 1;
					break;
				}

			}
			else if (is_num == 0) {
				gotoxy(1, 23);
				cout << "\t\t      " << char(186); Color(240); cout << "                Invalid Baggage Weight (Kg): "; Color(241); cout << setw(30) << char(186) << endl;
				gotoxy(68, 23);
				getline(cin >> ws, baggage_str);
				is_num_bool = 0;
			}
			is_num_bool = 0;
			is_num = 0;
			decimal_count = 0;
			contains_spaces = false;
		} while (is_num_bool == 0);
		gotoxy(1, 23);
		cout << "\t\t      " << char(186); Color(240); cout << "                        Baggage Weight (Kg): "; Color(241); cout << endl;
		if (selection == "I") { //checks if destination is inter national and maximum baggage is 8kg
			if (baggage[index2] > 10) {
				excessBaggage[index2] = (baggage[index2] - 10);
			}
			if (plane[0] == '1') { //checks type of plane and assigns price for excess baggage for the corresponding type
				BaggageFee[index2] = excessBaggage[index2] * 1250;
			}
			else if (plane[0] == '2') {
				BaggageFee[index2] = excessBaggage[index2] * 1450;
			}
		}

		else if (selection == "D") { //domestic flight
			if (baggage[index2] > 8) {
				excessBaggage[index2] = (baggage[index2] - 8);
			}
			if (plane[0] == '1') {
				BaggageFee[index2] = excessBaggage[index2] * 1250;
			}
			else if (plane[0] == '2') {
				BaggageFee[index2] = excessBaggage[index2] * 1450;
			}
			if (baggage[index1] < 9) {
				BaggageFee[index1] = 0;
			}
		}

		index1++;
		index2++;
		index3++;
		ctr1++;
		system("cls");
	}
	//reset of values used in loop
	index1 = 1;
	index2 = 1;
	index3 = 1;
	ctr1 = 0;
	system("cls");
	cout << logo;
	if (type[0] == '2') {
		trip_fare = trip_fare * 2; //multiply trip fare by two if two-way flight was chosen
	}
	seniors = 0;

	while (ctr1 != pssngr) { //loop for calculating each passengers fee
		if (age[index1] >= 60) { //checks if age of passenger is 60 or above
			if (group == 1) {
				pssngr_fee[index2] = trip_fare + BaggageFee[index3] + insurance[index3] - (trip_fare * .25); //discount of  20% for seniors and 5% for group reservation
			}
			else {
				pssngr_fee[index2] = trip_fare + BaggageFee[index3] + insurance[index3] - (trip_fare * .2); //discount of  20% for seniors
			}
			senior[index3] = 1;
			seniors++; //add counter for each seniors
		}
		else if (age[index1] <= 13) { //checks age of passenger is 13 or below
			if (group == 1) {
				disc = (trip_fare) * .07; //discount of  2% for childrens and 5% for group reservation
			}
			else {
				disc = (trip_fare) * .02; //discount of  2% for childrens
			}
			pssngr_fee[index2] = (trip_fare + BaggageFee[index3] + insurance[index3]) - disc;
			young[index3] = 1;
			child++;
		}
		else { //else adult
			pssngr_fee[index1] = trip_fare + BaggageFee[index3] + insurance[index3];
			young[index3] = 0;
			senior[index3] = 0;
			if (group == 1) {
				disc = (trip_fare) * .05; //adds 5% if group reservation
				pssngr_fee[index2] = pssngr_fee[index2] - disc;
			}
		}
		++ctr1;
		++index1;
		++index2;
		++index3;
	}
	index1 = 1;
	index2 = 1;
	index3 = 1;
	ctr1 = 0;
	while (ctr1 != pssngr) { //addign all passengers fee
		gross += pssngr_fee[index1];
		gross2 = gross;
		if (senior[index1] == 1) { //removing sniors passengers fee for computation of vat
			gross2 -= pssngr_fee[index1];
		}
		++ctr1;
		++index1;
	}
	ctr1 = 0;
	index1 = 1;
	vat = gross2 * .12; //computation of vat
	amount = gross + vat; //total due amount
	cout << fixed << setprecision(2); //limits any decimal output into two decimal spaces
	system("cls");
	//prints out booking summary of reservation
	cout << logo;
	cout << "\n\n\n\t\t\t" << char(201);      for (int i = 0; i < 67; i++) { cout << char(205); }      cout << char(187) << endl;
	cout << "\t\t\t" << char(186) << "                         \xfe BOOKING SUMMARY \xfe                       " << char(186) << endl;
	cout << "\t\t\t" << char(204);      for (int i = 0; i < 67; i++) { cout << char(205); }      cout << char(185) << endl;
	cout << "\t\t\t" << char(186) << "\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0 BOOKING DESTINATION \xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0" << char(186) << endl;
	cout << "\t\t\t" << char(186); Color(240); cout << "  \t\t    Manila --------TO--------    "; Color(241); cout << setw(20) << char(186) << endl;
	gotoxy(70, 13);
	cout << destination1;
	gotoxy(1, 14);
	cout << "\t\t\t" << char(186) << "\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0" << char(186) << endl;
	cout << "\t\t\t" << char(204);      for (int i = 0; i < 67; i++) { cout << char(205); }      cout << char(185) << endl;
	cout << "\t\t\t" << char(186); Color(240); cout << "  Departure Date: " << "\t\t\t\t   "; Color(241); cout << setw(18) << char(186) << endl;
	gotoxy(78, 16);
	cout << day << "/" << month << "/" << year;
	gotoxy(1, 17);
	x = 20;
	cout << "\t\t\t" << char(186) << "   \t\t\t\t\t\t\t\t    " << char(186) << endl;
	cout << "\t\t\t" << char(186) << "                           \xfe PASSENGERS \xfe                          " << char(186) << endl;
	while (ctr1 != pssngr) { //prints out each passengers details and computation for their corresponding passengers fee
		cout << "\t\t\t" << char(186) << "   \t\t\t\t\t\t\t\t    " << char(186) << endl;
		cout << "\t\t\t" << char(186); Color(240); cout << " " << index1 << ". " << surname[index1] << ", " << frstname[index1] << " " << mi[index1]; Color(241);
		gotoxy(92, x);
		cout << char(186) << endl;
		cout << "\t\t\t" << char(186); Color(240); cout << "     Trip Fare"; Color(241); cout << setw(54) << char(186) << endl;
		x++;
		gotoxy(79, x);
		Color(240); cout << "P" << trip_fare; Color(241); cout << endl;
		x++;
		if (young[index3] == 1) { //prints if passenger is children
			cout << "\t\t\t" << char(186); Color(240); cout << "     (A Children Discount of 2% Deducted)"; Color(241); cout << setw(27) << char(186) << endl;
			x++;
		}
		if (senior[index3] == 1) { //prints if passenger is senior
			cout << "\t\t\t" << char(186); Color(240); cout << "     (A Seniors Discount of 20% Deducted)"; Color(241); cout << setw(27) << char(186) << endl;
			x++;
		}
		if (group == 1) { //prints if passenger reservations is more than 5
			cout << "\t\t\t" << char(186); Color(240); cout << "     (A Group Reservation Discount of 5% Deducted)"; Color(241); cout << setw(18) << char(186) << endl;
			x++;
		}
		if (BaggageFee[index1] != 0) { //prints if passenger has excess baggage
			cout << "\t\t\t" << char(186); Color(240); cout << "     Excess Baggage Fee"; Color(241); cout << setw(45) << char(186) << endl;
			gotoxy(79, x);
			Color(240); cout << "P" << BaggageFee[index1]; Color(241); cout << endl;
			x++;
		}
		cout << "\t\t\t" << char(186); Color(240); cout << " Total Passenger's Fee"; Color(241); cout << setw(46) << char(186) << endl; //prints out amount of each total passengers fee
		gotoxy(79, x);
		Color(240); cout << "P" << pssngr_fee[index2]; Color(241); cout << endl;
		x += 2;
		++ctr1;
		++index1;
		++index2;
		++index3;
	}
	x += 2;
	//prints out vat that was added
	cout << "\t\t\t" << char(186) << "   \t\t\t\t\t\t\t\t    " << char(186) << endl;
	cout << "\t\t\t" << char(186) << "\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0" << char(186) << endl;
	cout << "\t\t\t" << char(186) << "   \t\t\t\t\t\t\t\t    " << char(186) << endl;
	cout << "\t\t\t" << char(186); Color(240); cout << "        VAT +12%"; Color(241); cout << setw(52) << char(186) << endl;
	gotoxy(79, x);
	Color(240); cout << "P" << vat; Color(241); cout << endl;
	cout << "\t\t\t" << char(186) << "   \t\t\t\t\t\t\t\t    " << char(186) << endl;
	cout << "\t\t\t" << char(186) << "\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0" << char(186) << endl;
	cout << "\t\t\t" << char(186) << "   \t\t\t\t\t\t\t\t    " << char(186) << endl;
	cout << "\t\t\t" << char(186); Color(240); cout << "\tT O T A L\t\t\t\t              \t    "; Color(241); cout << char(186) << endl; //prints total amount due
	x += 4;
	gotoxy(79, x);
	Color(240); cout << "P" << amount; Color(241); cout << endl;
	cout << "\t\t\t" << char(186) << "   \t\t\t\t\t\t\t\t    " << char(186) << endl;
	cout << "\t\t\t" << char(200);      for (int i = 0; i < 67; i++) { cout << char(205); }      cout << char(188) << endl;
	//pause program so user can review or check the booking summary
	cout << "\n\n\t\t\t ";
	cout << char(201);      for (int i = 0; i < 66; i++) { cout << char(205); }      cout << char(187) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186); Color(240); cout << "                     Press Any Key to Proceed  "; Color(241); cout << setw(20) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(200);      for (int i = 0; i < 66; i++) { cout << char(205); }      cout << char(188) << endl;
	system("pause>nul");
	system("cls");


	cout << logo;
	//payment
	cout << "\n\n\n\t\t      " << char(201);  for (int i = 0; i < 74; i++) { cout << char(205); }  cout << char(187) << endl;
	cout << "\t\t      " << char(186); Color(240); cout << "\t\t\t               \xfe PAYMENT \xfe    \t                         "; Color(241); cout << char(186) << endl;
	cout << "\t\t      " << char(204);  for (int i = 0; i < 74; i++) { cout << char(205); }  cout << char(185) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Total: "; Color(241); cout << setw(40) << char(186) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(186); Color(240); cout << setw(35) << "Enter Payment: P "; Color(241); cout << setw(40) << char(186) << endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	//cout << "\t\t      "<< char(186) ;Color(240);cout <<setw(35)<< "Change: ";Color(241);cout <<setw(40)<< char(186)<<endl;
	cout << "\t\t      " << char(186) << setw(75) << char(186) << endl;
	cout << "\t\t      " << char(200);      for (int i = 0; i < 74; i++) { cout << char(205); }      cout << char(188) << endl;
	x += 4;//amount
	gotoxy(58, 14);
	Color(240); cout << "P " << amount; Color(241); cout << endl;

	gotoxy(58, 16);
	getline(cin >> ws, payment); //input of payment
	//loop to validate whether input string has any other characters other than numeric
	do {

		for (int i = 0; i < payment.size(); i++) //checks if input have spcaes
		{
			if (isspace(payment[i]))
				contains_spaces = true;
		}

		if ((payment[0] == '0' && isdigit(payment[1]))) // input can't start from 0
			is_num = 0;
		else
		{
			for (int i = 0; i < payment.size(); i++)
			{
				if (isdigit(payment[i]))
					is_num++;
				if (payment[i] == '.')
					decimal_count++;
			}
		}

		if (decimal_count == 1) //validates decimals 66.7 8..9.9.9..9.9
			is_num = 0;

		if (is_num == payment.size() && contains_spaces == false) //determine whether the input has passed the previous validations
		{
			stringstream str_stream_object(payment);
			str_stream_object >> cash; //converts the numbers in the string into int
			if (cash != amount && cash < amount) {
				gotoxy(1, 16);
				cout << "                    " << char(186); Color(240); cout << setw(35) << "Invalid Payment: P "; Color(241); cout << endl;
				gotoxy(60, 16);
				payment = "";
				getline(cin >> ws, payment);
				is_num_bool = 0;
			}
			else {
				is_num_bool = 1; //change value of bool to stop loop
				break;
			}

		}
		else if ((is_num == 0)) { //input has characters other than numerics
			gotoxy(1, 16);
			cout << "                    " << char(186); Color(240); cout << setw(35) << "Invalid Payment: P "; Color(241); cout << endl;
			gotoxy(59, 16);
			payment = "";
			getline(cin >> ws, payment);
			is_num_bool = 0;
		}
		//reset value for use on the next loop
		is_num_bool = 0;
		is_num = 0;
		decimal_count = 0; 1;
		contains_spaces = false;
	} while (is_num_bool == 0);


	if (cash >= amount)
	{
		gotoxy(50, 18);
		cout << "Change: " << "P " << cash - amount;
	}

	cout << "\n\n\n\n\t\t\t ";
	cout << char(201);      for (int i = 0; i < 66; i++) { cout << char(205); }      cout << char(187) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186); Color(240); cout << "                     Press Any Key to Proceed  "; Color(241); cout << setw(20) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(186) << setw(67) << char(186) << endl;
	cout << "\t\t\t " << char(200);      for (int i = 0; i < 66; i++) { cout << char(205); }      cout << char(188) << endl;
	system("pause>nul");
	system("cls");

	cout << logo;
	//asks again if user wants to book again
	cout << "\n\n\n\t\t\t\t" << char(201);      for (int i = 0; i < 51; i++) { cout << char(205); }      cout << char(187) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "                                                   "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "          Thank You for Booking with Merc!         "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "                                                   "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186); Color(240); cout << "           Would You Like to Book Again?           "; Color(241); cout << char(186) << endl;
	cout << "\t\t\t\t" << char(186) << "                   [Y]/[N]:                        " << char(186) << endl;
	cout << "\t\t\t\t" << char(186) << "                                                   " << char(186) << endl;
	cout << "\t\t\t\t" << char(200);      for (int i = 0; i < 51; i++) { cout << char(205); }      cout << char(188) << endl;
	gotoxy(61, 14);
	gotoxy(1, 14);
	ShowConsoleCursor(false);
	cout << "\t\t\t\t"; Color(241); cout << char(186) << "                 " << ">YES"; Color(240); cout << "       NO                     "; Color(241); cout << char(186) << endl;
	yn = 'Y';
	gotoxy(54, 14);
	running = true;
	system("pause>nul");
	while (running) {

		if (GetAsyncKeyState(VK_RIGHT)) {
			gotoxy(1, 14);
			cout << "\t\t\t\t" << char(186); Color(240); cout << "                  YES"; Color(241); cout << "      >NO" << "                     " << char(186) << endl;
			yn = 'N';
			gotoxy(63, 14);
			running = true;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			gotoxy(1, 14);
			cout << "\t\t\t\t"; Color(241); cout << char(186) << "                 " << ">YES"; Color(240); cout << "       NO                     "; Color(241); cout << char(186) << endl;
			yn = 'Y';
			gotoxy(54, 14);
			running = true;
		}
		if (GetAsyncKeyState(VK_RETURN)) {
			switch (yn) {
			case 'y': case 'Y': //if input is YES run the program again
				system("cls");
				running = false;
				main();
				break;
			case 'n': case 'N': // if NO stop the program
				system("cls");
				cout << logo;
				cout << "\n\n\n\t\t\t\t\t      Thank You! And Goodbye!";
				return 0;
			}
		}
	}
}