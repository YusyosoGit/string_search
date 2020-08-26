#include <iostream>
#include <fstream>		// ifstream のため
#include <string>
#include "simple_sch.h"
#include "BM_sch.h"

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

	SearchBase *sb;
//	string app_name(argv[0]);

	sb = new BMSearch(argv[2]);


#if 0
	if (app_name == "Simp_sch.exe") {
		sb = new SimpleSearch(argv[2]);
	}
	else if (app_name == "BM_sch.exe") {
		sb = new BMSearch(argv[2]);
	}
#endif

	string str;
	size_t pos;
	int count = 0;

	while (!in.eof()) {
		//in >> str;		// ホワイトスペース単位でファイルを読む
		getline(in, str);	// 改行単位でファイルを読む
		pos = 0;
		do {
			pos = sb->exec(str.c_str(), pos); 
			if (pos == SIZE_MAX) break;
			++count;
			++pos;
		} while (1);
	}

	cout << "found: " << count << endl;
	cout << endl;

	return 0;
}
