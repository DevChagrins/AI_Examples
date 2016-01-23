#include <iostream>
#include <string>
#include <vector>
using namespace std;

long Reverse(long number);
bool CheckEvenOdd(const char* number, int length);
bool CheckFirstLastDelta(const char* number, int length);
bool CheckSumOdd(const char* number, int length);

bool CheckNumber(long number);

int main()
{
	vector<long> passedNumbers;
	long startNumber = 100;

	cout << "-------- Lychrel Test Rules --------" << endl;
	cout << "Check 1: Check if the number of even and odd digits in the number are inequal" << endl;
	cout << "Check 2: Check if both the difference between the first and last digits is even/odd just like the number of digits in the whole number. /n/tExample: 138...8-1=7 and there are 3 digits, both are odd. Passes the test." << endl << endl;
	cout << "Check 3: Check if the sum of all digits in a number is odd. <Wrong>" << endl;
	cout << "Check 4: Check if next number in the reverse/add process follows rules 1-3." << endl;

	for (long number = startNumber; number <= 9999; number++)
	{
		//cout << "-------- Testing Number --------" << endl;
		//cout << "Number: " << number << endl;
		bool passed = CheckNumber(number);
		long nextNumber = number + Reverse(number);
		passed &= CheckNumber(nextNumber);
		//cout << "Check 1: " << (check1 == 1 ? "True" : "False") << endl;
		//cout << "Check 2: " << (check2 == 1 ? "True" : "False") << endl;

		if (passed)
		{
			passedNumbers.push_back(number);
		}
	}

	cout << "=========== Passed Numbers ===========" << endl;
	for (long passedNumber : passedNumbers)
	{
		cout << passedNumber << endl;
	}

	system("pause");
	return 0;
}

bool CheckNumber(long number)
{
	char buffer[10] = { 0 };
	string strNumber = "";
	_ltoa_s(number, buffer, sizeof(buffer), 10);
	strNumber += buffer;

	bool passed = true;
	passed &= CheckEvenOdd(strNumber.c_str(), strNumber.length());
	passed &= CheckFirstLastDelta(strNumber.c_str(), strNumber.length());
	passed &= CheckSumOdd(strNumber.c_str(), strNumber.length());

	return passed;
}

long Reverse(long number)
{
	long reverse = 0;

	while (number != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + number % 10;
		number = number / 10;
	}

	return reverse;
}

bool CheckEvenOdd(const char* number, int length)
{
	bool passesEvenOdd = false;

	if (nullptr != number)
	{
		int even = 0, odd = 0;
		for (int numberIndex = 0; numberIndex < length; numberIndex++)
		{
			try
			{
				int singleDigit = atoi(&number[numberIndex]);

				if (singleDigit % 2 == 0)
				{
					even++;
				}
				else
				{
					odd++;
				}
			}
			catch (string error)
			{
				cout << "ERROR: " << error << endl;
				break;
			}
		}

		if (even != odd)
		{
			passesEvenOdd = true;
		}
	}

	return passesEvenOdd;
}

bool CheckFirstLastDelta(const char* number, int length)
{
	bool passesFirstLastDelta = false;

	if (nullptr != number)
	{
		if (length > 2)
		{
			char firstDigit = number[0];
			char lastDigit = number[length-1];
			int first = atoi(&firstDigit),
				last = atoi(&lastDigit);

			int firstLastDelta = first - last;

			int deltaSign = (firstLastDelta % 2 == 0);
			int countSign = (length % 2 == 0);

			if (deltaSign == countSign)
			{
				passesFirstLastDelta = true;
			}
		}
	}

	return passesFirstLastDelta;
}

bool CheckSumOdd(const char* number, int length)
{
	bool passesSumOdd = false;

	if (nullptr != number)
	{
		long sum = 0;
		for (int numberIndex = 0; numberIndex < length; numberIndex++)
		{
			try
			{
				char currentDigit = number[numberIndex];
				long digit = atol(&currentDigit);

				sum += digit;
			}
			catch (string error)
			{
				cout << "ERROR: " << error << endl;
				break;
			}
		}

		if (sum % 2 == 1)
		{
			passesSumOdd = true;
		}
	}

	return passesSumOdd;
}