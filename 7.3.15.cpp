#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{ 
	setlocale(LC_ALL, "ru");
	ofstream fout, fout2;
	
	string str, str2, str3, str4, stri;
	
	fout.open("1.txt");
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (i % 2 == 0) {
			str3.push_back(str[i]);
			stri = to_string(i);
			str2 += stri;
		}
		else str2.push_back(str[i]);
		
	}
	fout << str2;	
	fout.close();

	str.clear();

	ifstream fin("1.txt");
	fout2.open("2.txt");

	getline(fin, str);
	std :: cout << str << endl;
	cout << str3 << endl;

	int i = 0;
	str.erase(0, 1);
	str.insert(str.begin(), str3[0]);
	str3.erase(0, 1);
	while (!str3.empty()) {
		if (i % 2 != 0) {
			str.erase(i + 1, to_string(i + 1).size());
			str.insert(str.begin() + i + 1, str3[0]);
			str3.erase(0, 1);
		}
		i++;
	}


	cout << str;

	fout2 << str;

	fin.close();
	fout2.close();


	return 0;
}
   