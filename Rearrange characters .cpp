#include <bits/stdc++.h>
using namespace std;
class compare {
public:
	bool operator()(pair<char, int> const &a, pair<char, int> const &b) {
		return a.second < b.second;
	}
};

int rearrange(string s) {
	/*
		Use priority Queue with pair where first will represent freq and second will character
	*/

	unordered_map<char, int> freq;
	int maxfreq = 0;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		freq[s[i]]++;
		maxfreq = max(maxfreq, freq[s[i]]);
	}

	if (maxfreq <= (n - maxfreq + 1)) return 1;
	return 0;
}

int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = rearrange(s);
		cout << ans << endl;
	}
	return 0;
}