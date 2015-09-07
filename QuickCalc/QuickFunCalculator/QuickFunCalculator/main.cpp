#include <iostream>
#include <string>
using namespace std;

void IterativeShiftSinglePrint(unsigned int number, unsigned int mask);
unsigned int IterativeShiftAdd(unsigned int number, unsigned int mask);
void PrintBinary(unsigned int number, unsigned int mask);

int main(int argc, char* argv[])
{
	unsigned int mask = 1;
	unsigned int num = 125;

	PrintBinary(num, mask);
	PrintBinary(IterativeShiftAdd(num, mask), mask);

	return 0;
}

void IterativeShiftSinglePrint(unsigned int number, unsigned int mask)
{
	unsigned int rsNumber = number;
	std::string finalBinary = "";

	unsigned int singleNum = 0;

	char thing[10];
	while (rsNumber != 0)
	{
		singleNum = 0;
		rsNumber = rsNumber >> 1;

		singleNum = rsNumber + number;
		singleNum &= mask;
		_itoa_s(singleNum, &thing[0], 10, 10);
		finalBinary = thing[0] + finalBinary;
	}

	cout << "Final: " << finalBinary << endl;
}

void PrintBinary(unsigned int number, unsigned int mask)
{
	unsigned int rsNumber = number;
	std::string finalBinary = "";

	unsigned int singleNum = 0;

	char thing[10];
	while (rsNumber != 0)
	{
		rsNumber = rsNumber >> 1;

		singleNum = rsNumber & mask;
		_itoa_s(singleNum, &thing[0], 10, 10);
		finalBinary = thing[0] + finalBinary;
	}

	cout << "Number: " << number << " Binary : " << finalBinary << endl;
}

unsigned int IterativeShiftAdd(unsigned int number, unsigned int mask)
{
	unsigned int rsNumber = number;
	unsigned int returnNumber = 0;

	while (rsNumber > 0)
	{
		rsNumber = rsNumber >> 1;
		returnNumber += returnNumber + rsNumber;
	}

	return returnNumber;
}