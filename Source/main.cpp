
// after project
	// char => wchar? 
	// chk utf-8 or ansi? => UTF-16 wchar? for C#
// in now project, char, std::string -> Token2, with buffer, static char[2] for "#"


#define _CRT_SECURE_NO_WARNINGS // in main?

#include <iostream>
#include <string>
#include <fstream>
// header only?
#include "readonly_parser.h"

#include <ctime>


int main(void)
{
	std::ofstream outFile;
	outFile.open("output.eu4");

	wiz::load_data::LoadData::Node node;
	char* buffer = nullptr;

	int a = clock();
	wiz::load_data::LoadData::LoadDataFromFile2("input.eu4", node, -1, 0, &buffer);
	int b = clock();
	std::cout << b - a << "ms";
	
	wiz::load_data::LoadData::Print(node.first_child, outFile);
	
	outFile.close();

	return 0;
}

