// 895A. Pizza Separation
// http://codeforces.com/problemset/problem/895/A

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Students Vasya and Petya are studying at the BSU (Byteland State University). At one of the breaks they decided to order a pizza. In this problem pizza is a circle of some radius. The pizza was delivered already cut into n pieces. The i-th piece is a sector of angle equal to ai. Vasya and Petya want to divide all pieces of pizza into two continuous sectors in such way that the difference between angles of these sectors is minimal. Sector angle is sum of angles of all pieces in it. Pay attention, that one of sectors can be empty.

// Input
// The first line contains one integer n (1 ≤ n ≤ 360)  — the number of pieces into which the delivered pizza was cut.

// The second line contains n integers ai (1 ≤ ai ≤ 360)  — the angles of the sectors into which the pizza was cut. The sum of all ai is 360.

// Output
// Print one integer  — the minimal difference between angles of sectors that will go to Vasya and Petya.

// Examples
// input
// 4
// 90 90 90 90
// output
// 0
// input
// 3
// 100 100 160
// output
// 40
// input
// 1
// 360
// output
// 360
// input
// 4
// 170 30 150 10
// output
// 0
// Note
// In first sample Vasya can take 1 and 2 pieces, Petya can take 3 and 4 pieces. Then the answer is |(90 + 90) - (90 + 90)| = 0.

// In third sample there is only one piece of pizza that can be taken by only one from Vasya and Petya. So the answer is |360 - 0| = 360.

// In fourth sample Vasya can take 1 and 4 pieces, then Petya will take 2 and 3 pieces. So the answer is |(170 + 10) - (30 + 150)| = 0.

// Picture explaning fourth sample:



// Both red and green sectors consist of two adjacent pieces of pizza. So Vasya can take green sector, then Petya will take red sector.

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int f1(vector<int> & A) {
            int sz = A.size(), i = 0, j = 0, a = 0, b = 0, result = 360;
            if (sz == 1) {
                return 360;
            }
            while (j < sz) {
                b += A[j];
                ++j;
                if (b - a == 180) {
                    return 0;
                }
                result = min(result, abs(360 - 2 * (b - a)));
                while (i < j and b - a > 180) {
                    a += A[i];
                    ++i;
                    if (b - a == 180) {
                        return 0;
                    }
                    result = min(result, abs(360 - 2 * (b - a)));
                }
            }
            return result;
        }

};

int main(void) {
    Solution solution;
    int n, a;
    vector<int> A;
    cin >> n;
    while (n-- > 0) {
        cin >> a;
        A.push_back(a);
    }
    cout << solution.f1(A);
    return 0;
}