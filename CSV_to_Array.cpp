// CSV_to_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>


int main()
{
	//const std::string file_path = "/usd/test.csv";
	const std::string file_path = "C:/Users/victor/Desktop/test.csv";

	std::string temp = "";

	int array_size = 5; //number of elements per element

	std::ifstream CSV_file;
	CSV_file.open(file_path);

	int line_count = 0;

	//counts number of lines in file
	while (getline(CSV_file, temp)) {
		line_count++;
	}

	line_count = (line_count + 1) / 2;

	//creates array of correct size
	double** numArr = new double*[line_count];

	for (int i = 0; i < line_count; i++){
		numArr[i] = new double[array_size];
	}

	//resets file
	CSV_file.clear();
	CSV_file.seekg(0);

	//start to take things from CSV
	int i = 0;
	while (getline(CSV_file, temp)) {
		if (i % 2 == 0) {
			for (int j = 0; j < array_size; j++) {
				std::size_t location = 0;
				location = temp.find(",");

				if (location != std::string::npos) {
					numArr[i/2][j] = stod(temp.substr(0, location));
					temp = temp.substr(location + 1, temp.length() - 1 - location);
				}
				else {
					numArr[i/2][j] = stod(temp);
				}
				
			}
		}
		i++;
	}



	

/*--------------------------------*/
}

