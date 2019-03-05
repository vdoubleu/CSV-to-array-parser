// CSV_to_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>


int main()
{/*
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
*/


	
	//char file_path[] = "C:/Users/victor/Desktop/test.csv";

	const std::string file_path = "C:/Users/victor/Desktop/test.csv";
	
	
	std::string line = "";
	std::ifstream csv_file;
	csv_file.open(file_path);
	
	//char string[100];
	//FILE* usd_file_read = fopen(file_path, "r");

	//gets(string);

	int array_width = 8; //number of values that need to be parsed per line
	int* array_width_ptr = &array_width;

	int line_count = 0;
	int* line_count_ptr = &line_count;


	//counts number of lines in file
	while (getline(csv_file, line)) {
		line_count++;
	}
	
	/*while (string[c] != '\0') {

	}*/


	//creates array of correct size
	double** profile_info = new double*[line_count];

	for (int i = 0; i < line_count; i++){
		profile_info[i] = new double[array_width];
	}

	//resets file
	csv_file.clear();
	csv_file.seekg(0);

	//start to take things from CSV
	int current_line = 0;
	while (getline(csv_file, line)) {
			for (int current_val = 0; current_val < array_width; current_val++) {
				std::size_t comma_location = line.find(","); //finds and stores location of comma

				if (comma_location != std::string::npos) {//if comma exists
					profile_info[current_line][current_val] = stod(line.substr(0, comma_location));
					line = line.substr(comma_location + 1, line.length() - 1 - comma_location);
				}
				else {//if comma does not exist
					profile_info[current_line][current_val] = stod(line);
				}

			}
		
		current_line++;
	}
	
	for (int i = 0; i < line_count; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << profile_info[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//std::cout << line_count << " :linecount:" << std::endl;


}

