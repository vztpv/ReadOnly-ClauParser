
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


void f(std::vector<wiz::Token2>& vec, wiz::Token2* i) {
	if ((i->len == 1 && i->str[0] == '{') || i == &vec[0]) {
		if (!( (i+1)->len == 1 && (i+1)->str[0] == '}' )) {
			wiz::Token2* x = i;
			do {
				++x;//next
				if (x->len == 1 && x->str[0] == '{') {
				//	std::cout << " { \n";
					f(vec, x);
				//	std::cout << " } \n";
				}
				else {
				//	if (x->str) {
				//		std::cout << std::string(x->str, x->len) << " ";
				//	}
				}
			} while (i->ptr != x);
			//i.up();
			i = i->ptr;
		}
	}
}


int main(void)
{

//	int a = clock();
	//
//	wiz::load_data::UserType ut;
//	wiz::load_data::LoadData::LoadDataFromFile("C:\\Users\\vztpv\\Documents\\Paradox Interactive\\Europa Universalis IV\\save games\\input.eu4", ut, -1, 0);
//	int b = clock();
//	std::cout << b - a << "ms\n";
	//b = clock();
	//wiz::load_data::LoadData::LoadDataFromFile2("C:\\Users\\vztpv\\Documents\\Paradox Interactive\\Europa Universalis IV\\save games\\input.eu4", node, -1, 0, &buffer);
	//int c = clock();
	//std::cout << c - b << "ms\n";
	

	wiz::load_data::UserType test;
	int b = clock();
	wiz::load_data::LoadData::LoadDataFromFileJson2("C:\\Users\\vztpv\\Desktop\\Clau\\New Json Parser\\New Json Parser\\input.json",
		test, 0, 0); 
		//"C:\\Users\\vztpv\\Documents\\Paradox Interactive\\Europa Universalis IV\\save games\\input.eu4", test, 0, & buffer);
	int c = clock();
	std::cout << c - b << "ms\n";
	wiz::load_data::LoadData::SaveWizDB(test, "output.json");

	
	//f(test, &test[0]);

	//delete[] buffer;


	//wiz::load_data::LoadData::Print(node.first_child, outFile); // error...
	//wiz::load_data::LoadData::RemoveAll(&node);
	//delete[] buffer;
	
	//wiz::load_data::LoadData::SaveWizDB(ut, "output.eu4");
	return 0;
}

