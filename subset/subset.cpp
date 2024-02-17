<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> 466ad83 (added comments for clearer understanding)
#include <fstream>
#include <vector>

using namespace std;

int subset_sum(vector<int> a, int sum)
{
<<<<<<< HEAD
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
=======
    // tab[i][j] is represents the number of subsets 
    // in the first 'i' elements of 'a' that sum up to 'j'

    int n = a.size();
    int tab[n + 1][sum + 1];
    // initialising tab as a memoization method
    // tab[0][0] is 1 because the sum of the empty set is 0
    tab[0][0] = 1;
    for (int i = 1; i < sum + 1; i++) {
        tab[0][i] = 0;
    }
    
    // filling out the dp table in a bottom-up approach
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            // current value is too big
            // use the amount of ways to make using the previous elements
            if (a[i - 1] > j) {
                tab[i][j] = tab[i - 1][j];
            }
            // can include the current value
            // so it is the amount of ways that j can be made without it
            // plus the amount of ways that j can be made with it
>>>>>>> 466ad83 (added comments for clearer understanding)
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
	
<<<<<<< HEAD
	cout << subset_sum(arr, k);
=======
	fout << subset_sum(arr, k) << endl;
>>>>>>> 466ad83 (added comments for clearer understanding)
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
