#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int subset_sum(vector<int> a, int sum)
{
    // Initializing the matrix
    int n = a.size();
    int tab[n + 1][sum + 1];
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++) {
        tab[0][i] = 0;
    }
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (a[i - 1] > j) {
                tab[i][j] = tab[i - 1][j];
            }
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    } 
 
    return tab[n][sum];
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
	
	cout << subset_sum(arr, k);
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
