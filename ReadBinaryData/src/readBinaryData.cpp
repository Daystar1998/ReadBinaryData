/******************************************************************************
	Name: readBinaryData.cpp

	Des:
		This program will read a binary file which contains integers and
		outputs the sum of those integers.

	Author: Matthew Day

	Due Date: 9/5/2019
******************************************************************************/

#include <fstream>
#include <iostream>

using namespace std;

/******************************************************************************
		Name: readFile

		Des:
			Reads integers from a binary file

		Params:
			filename - type string, the name of the file
			oCount - type unsigned char &, output the number of integers in
				the file
		Return:
			type short*, the integers from the file

******************************************************************************/
short* readFile(string filename, unsigned char &oCount) {

	short *result = nullptr;

	ifstream fin(filename, ios::in | ios::binary);

	if (fin.good()) {

		fin.read((char *)& oCount, sizeof oCount);

		result = new short[oCount];

		for (int i = 0; i < oCount; i++) {

			fin.read((char *)& result[i], sizeof result[i]);
		}
	}

	fin.close();

	return result;
}

int main() {

	unsigned char count;
	short *values = readFile("numbers.dat", count);

	int sum = 0;

	if (values != nullptr) {

		for (int i = 0; i < count; i++) {

			sum += values[i];
		}

		delete values;
	}

	cout << "The sum of the numbers contained in the file is " << sum << '.' << endl;

	return 0;
}