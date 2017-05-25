// 127D. Password
// http://codeforces.com/contest/127/problem/D

/*
Asterix, Obelix and their temporary buddies Suffix and Prefix has finally found the Harmony temple. However, its doors were firmly locked and even Obelix had no luck opening them.

A little later they found a string s, carved on a rock below the temple's gates. Asterix supposed that that's the password that opens the temple and read the string aloud. However, nothing happened. Then Asterix supposed that a password is some substring t of the string s.

Prefix supposed that the substring t is the beginning of the string s; Suffix supposed that the substring t should be the end of the string s; and Obelix supposed that t should be located somewhere inside the string s, that is, t is neither its beginning, nor its end.

Asterix chose the substring t so as to please all his companions. Besides, from all acceptable variants Asterix chose the longest one (as Asterix loves long strings). When Asterix read the substring t aloud, the temple doors opened.

You know the string s. Find the substring t or determine that such substring does not exist and all that's been written above is just a nice legend.

Input
You are given the string s whose length can vary from 1 to 106 (inclusive), consisting of small Latin letters.

Output
Print the string t. If a suitable t string does not exist, then print "Just a legend" without the quotes.

Examples
input
fixprefixsuffix
output
fix
input
abcdabc
output
Just a legend
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string password(const string& s) {
		if (s.empty()) {
			return "Just a legend";
		}
		vector<int> pi(s.size() + 1);
		pi.front() = -1;
		const int n = s.size();
		int i = 0, j = -1;
		while (i < n) {
			if (j == -1 or s.at(i) == s.at(j)) {
				pi.at(++i) = ++j;
			}
			else {
				j = pi.at(j);
			}
		}
		vector<int> v(s.size() + 1, 0);
		for (i = 1; i <= n; i++) {
			j = pi.at(i);
			while (j > 0 and v.at(j) < 2) {
				v.at(j)++;
				j = pi.at(j);
			}
		}
		j = pi.back();
		while (j > 0) {
			if (v.at(j) >= 2) {
				return s.substr(0, j);
			}
			j = pi.at(j);
		}
		return "Just a legend";
	}
};

int main(void) {
	string s;
	cin >> s;
	Solution solution;
	cout << solution.password(s);
	return 0;
}
