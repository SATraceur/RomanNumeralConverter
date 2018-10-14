/*
Roman Numeral Converter - Version 1.0 (18/03/2016)
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <sstream>

using namespace std;

//======================================== GLOBAL VARIABLES =============================================//

const string units[10] {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const string tens[10] {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string hundreds[10] {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string thousands[4] {"", "M", "MM", "MMM"};

//=========================================== FUNCTIONS ==================================================//


void To_Upper(string& input); // Converts the input string to uppercase.
void Convert_To_Decimal(string input); // Contains the Roman to Decimal conversion code.
void Convert_To_Roman(string input2); // Contains the Decimal to Roman conversion code.

//==========================================  MAIN PROGRAM ===============================================//

int main(int argc, char** argv)
{
	string input;

	while (cin >> input)
	{
		if (isdigit(input[0]) > 0) // Checks to see if first character is a digit.
		{
			Convert_To_Roman(input); // If so then convert to Roman Numeral.
		}
		else if (isalpha(input[0])) // Checks to see if the first character is a letter.
		{
			To_Upper(input); // If so then convert string to uppercase.
			Convert_To_Decimal(input); // Then convert to decimal
		}
		else
		{
			cout << "0"; // If 
		}
	}


//	system("Pause");
	return(0);
}

void To_Upper(string& input) // Converts the string to uppercase.
{
	for (int i = 0; i < input.size(); i++)
	{
		input.at(i) = toupper(input.at(i));
	}
	return;
}

void Convert_To_Roman(string input2) // Converts to Roman Numerals.
{

	int j = 0, k = 0, l = 0, m = 0; // Variables to hold the thousands, hundreds, tens and units values respectivly.
//	int input = stoi(input2); // Converts string characters to intergers and stores it in local input interger.
	int input;
	stringstream convert(input2);
	convert >> input;



	j = input % 10; // Gets units.
	k = ((input % 100) - j) / 10; // Gets tens.
	l = ((input % 1000) - k - j) / 100; // Gets hundreds.
	m = ((input % 10000) - k - j - l) / 1000; // Gets thousands
	

	if (input < 10) // If the input is < 10
	{
		cout << units[j] << endl; // Output the string in the respective units index.
	}
	else if (input >= 10 && input < 100)
	{
		cout << tens[k] << units[j] << endl; // Output the strings in the respective tens and units indexes if the input is >= 10 & < 100.
	}
	else if (input >= 100 && input < 1000)
	{
		cout << hundreds[l] << tens[k] << units[j] << endl;
	}
	else if (input >= 1000 && input <= 3999)
	{
		cout << thousands[m] << hundreds[l] << tens[k] << units[j] << endl;
	}
	else // If all above conditions were not met, output 0.
	{
		cout << "0" << endl;
	}
	
}

void Convert_To_Decimal(string input)
{
	int temp = 0; // Temp is a variable to store the sum of the thousands, hundreds, tens and units.

	if (input[0] == 'M') // Checks input for thousands.
	{
		for (int j = 3; j >= 0; j--)
		{
			if (input.find(thousands[j]) == 0)
			{
				if (j == 0 ? temp += 1000 : temp += (j) * 1000); // If index location is 0, add 1000 otherwise add (index location) * 1000 to temp.
				input.erase(0, thousands[j].length());
				break;
			}
		}
	}
	if (input[0] == 'C' || input[0] == 'D') // Checks input for hundreds.
	{
		for (int j = 9; j >= 0; j--)
		{
			if (input.find(hundreds[j]) == 0)
			{
				if (j == 0 ? temp += 100 : temp += (j) * 100); // If index location is 0, add 100 otherwise add (index location) * 100 to temp.
				input.erase(0, hundreds[j].length());
				break;
			}
		}
	}
	if (input[0] == 'X' || input[0] == 'L') // Checks input for tens.
	{
		for (int j = 9; j >= 0; j--)
		{
			if (input.find(tens[j]) == 0)
			{
				if (j == 0 ? temp += 10 : temp += (j) * 10); // If index location is 0, add 10 otherwise add (index location) * 10 to temp.
				input.erase(0, tens[j].length());
				break;
			}
		}
	}
	if (input[0] == 'I' || input[0] == 'V') // Checks input for units. 
	{
		for (int j = 9; j >= 0; j--)
		{
			if (input.find(units[j]) == 0)
			{
				temp += j; // Adds units to temp.
				input.erase(0, units[j].length());
				break;
			}
		}
	}
	cout << temp << endl;
}
