#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string>&string_List) {

	unordered_map<string, vector<string>> mp;
	int n = string_List.size();
	for (int i = 0; i < n; i++) {
		string temp = string_List[i];
		sort(temp.begin(), temp.end());
		mp[temp].push_back(string_List[i]);
	}

	vector<vector<string>> res;
	for (auto x : mp) {
		vector<string> v;
		for (auto s : x.second) {
			v.push_back(s);
		}
		res.push_back(v);
	}

	return res;

}
int main() {

#ifndef ONLINE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// {act,god,cat,dog,tac}
	int n;
	cin >> n;
	vector<string> stringList(n);
	for (int i = 0; i < n; i++) {
		cin >> stringList[i];
	}

	vector<vector<string>> ans = Anagrams(stringList);
	for (auto x : ans) {
		for (auto s : x) {
			cout << s << " ";
		}
		cout << endl;
	}

	return 0;
}