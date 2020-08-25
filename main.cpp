#include <iostream>
#include <fstream>		// ifstream のため
#include <string>
#include "simple_sch.h"

using namespace std;


int main(int argc, char *argv[])
{
	if (argc != 3) {
		cout << "USAGE: (app_name) <ファイル名> <検索文字列>" << endl;
		cout << endl;
		exit(0);
	}
	ifstream in(argv[1]);
	if (!in) {
		cout << "File Not Found." << endl;
		cout << endl;
		exit(0);
	}

	SimpleSearch ss(argv[2]);
	string str;
	size_t pos;
	int count = 0;

	while (!in.eof()) {
		//in >> str;
		getline(in, str);
		pos = 0;
		do {
			pos = ss.exec(str.c_str(), pos); 
			if (pos == SIZE_MAX) break;
			++count;
			++pos;
		} while (1);
	}

	cout << "found: " << count << endl;
	cout << endl;

	return 0;
}
