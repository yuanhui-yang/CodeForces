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

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close;
#include <ctime>
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push; std::priority_queue; std::priority_queue::top; std::priority_queue::push; std::priority_queue::pop
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
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