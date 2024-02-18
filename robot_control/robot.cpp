#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;

    Point operator+(const Point &a) {
        return Point{x + a.x, y + a.y};
    }

    Point operator-(const Point &a) {
        return Point{x - a.x, y - a.y};
    }

    bool operator==(const Point &a) {
        return x == a.x && y == a.y;
    }
    
    bool operator!=(const Point &a) {
        return x != a.x && y != a.y;
    }

};

vector<pair<Point, int>> all_subsets(const vector<Point> &instuctions) {
    vector<pair<Point, int>> v{{}};

    for (const Point &i : instuctions) {
        v.resize(2 * v.size());

        for (int j = 0; j < v.size() / 2; j++) {
            v[v.size() / 2 + j] = {v[j].first + i, v[j].second + 1}; 
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main() {
    int n;
    cin >> n;

    Point goal;
    cin >> goal.x >> goal.y;
    
    vector<Point> instructions(n);
    for (int i = 0; i < n; i++) {
        cin >> instructions[i].x >> instructions[i].y;
    }
    
    vector<pair<Point, int>> a = all_subsets(vector<Point>{begin(instructions), begin(instructions) + n / 2});  
    vector<pair<Point, int>> b = all_subsets(vector<Point>{begin(instructions) + n / 2, end(instructions)});  
    reverse(b.begin(), b.end());

    int result[n + 1];
    vector<int> count_b;
    Point rest_prev{INT_MAX, INT_MAX};
    int ib = 0;

    for (const auto &p : a) {
        const Point rest = goal - p.first;
        if (rest_prev != rest) {
            rest_prev = rest;
            count_b = vector<int>(n / 2 + 1);

            for (; ib < b.size() && b[ib].first == rest; ib++) {
                count_b[b[ib].second]++;
            }
        }
        for (int i = 0; i < count_b.size(); i++) {
            result[i + p.second] += count_b[i]; 
        }
    }

    for (int i = 1; i < n + 1; i++) {
        cout << result[i] << endl;
    } 
}
