/*
ID: aqua4fa1
PROG: barn1
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ifstream fin ("barn1.in");
	ofstream fout ("barn1.out");	
	
	int m, s, c;

	fin >> m >> s >> c;

	int occupied[c];
	for (int i = 0; i < c; i++) {
		fin >> occupied[i];
	}
	
	cout << occupied[0] << endl;
}
