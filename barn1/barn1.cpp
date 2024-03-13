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

	vector<int> occupied(c);
	for (int i = 0; i < c; i++) {
		fin >> occupied[i];
	}
	
	vector<int> gap_lengths;
	for (int i = 1; i < c; i++) {
		int gap_len = occupied[i] - occupied[i - 1] - 1;
		if (gap_len > 0) {
			gap_lengths.push_back(gap_len);
		}
	}
	
	cout << gap_lengths[0] << endl;
	sort(gap_lengths.begin(), gap_lengths.end());
	int res = 0;
	for (int i = 0; i < m; i++) {
		res += gap_lengths[i];
	}

	int start_gap = occupied[0] - 1;
	int end_gap = s - occupied[c - 1];

	fout << (s - res - start_gap - end_gap);
}
