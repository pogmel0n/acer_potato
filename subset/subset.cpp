#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int search(vector<int> arr, int k) {
	if (k == 0) {
		return 1;
	}

	int result = 0;

	for (int i = 0; i < arr.size(); i++) {
		if ((k - arr[i]) < 0) {
			continue;
		}
		vector<int> copy(arr);
		copy.erase(copy.begin() + i);
		result += search(copy, k - arr[i]);
	}
	
	return result;	
}

int main() {
	ifstream fin ("subset.in");
	ofstream fout ("subset.out");

	int n, k;
	fin >> n >> k;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		fin >> arr[i];
	}
	
	cout << search(arr, k);
}

/*
THIS DOESN'T WORK BECAUSE THE NUMBERS AREN'T REPLACED

// this is a dynamic programming question
int subset_sum(vector<int> arr, int k) {
	// maps a number to how many ways it can be constructed
	map<int, int> memo;
	
	memo[0] = 1;
	
	// bottom-up approach	
	for (int i = 1; i < k + 1; i++) {
		memo[i] = 0;
		
		for (const int& element : arr) {
			int subproblem = i - element;
			if (subproblem < 0) {
				continue;
			}
			memo[i] = memo[i] + memo[subproblem];
		}
	}

	// solution is O(N * K)
	return memo[k];
}
*/
