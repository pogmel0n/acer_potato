/*
ID: aqua4fa1
PROG: palsquare
LANG: C++                 
*/

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#define MAX_N 300

string change_base(int num, int base) {
    int remainder = 0;
    string res = "";

    while (num > 0) {
        remainder = num % base;
        if (remainder < 10) {
            res = to_string(remainder) + res;
        }
        else {
			char c;
			c = 'A' + (remainder - 10);
            res = c + res;
        }
        num /= base;
    }
    
    return res;
}

bool check_pal(string num) {
    int p1 = 0;
    int p2 = num.size() - 1;

    while (p1 < p2) {
        if (num[p1] != num[p2]) {
            return false;
        }

        p1++;
        p2--;
    }
    return true;
}

int main() {
    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");

    int base;
    fin >> base;

    for (int i = 1; i <= MAX_N; i++) {
        string num = change_base(i, base);
        string square = change_base(i * i, base);
		if (i == 39) {
			cout << square << endl;
		} 
		if (square.size() == 1 && square[0] > '9') {
			continue;
		} 
        if (check_pal(square)) {
            fout << num << " " << square << "\n";
        }
    }
}
