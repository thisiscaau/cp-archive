#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> whitelist, blacklist;
int knights;
int a, b;

vector<pair<int, int>> adj;
vector<int> round_table;

bool check_display(vector<int> v) {
	if (v[0] != 0) {
		// cout << "arthur is the first\n";
		return false;
	}
	// for (auto i : v) {
	// 	cout << i << " ";
	// }
	// cout << "\n";
	for (int i = 0; i < knights; ++i) {
		int c = v[i];
		int l = v[adj[i].first], r = v[adj[i].second];
		if (blacklist[c].count(l) > 0 || blacklist[c].count(r) > 0) {
			// cout << "blacklisted case: " << l << " or " << r << " shouldn't be next to " << c << "\n";
			return false;
		}
		if (whitelist[c].size() == 2) {
			if (whitelist[c].count(l) == 0 || whitelist[c].count(r) == 0) {
				// cout << "c asked for both of them: " << l << " " << r << "\n";
				return false;
			}
		}
		else if (whitelist[c].size() == 1) {
			if (whitelist[c].count(l) == 0 && whitelist[c].count(r) == 0) {
				// cout << "where is he? " << (*whitelist[c].begin()) << "\n";
				return false;
			}
		}
	}
	// cout << "ah yes, there's everyone.\n";
	for (auto i : v) {
		cout << i+1 << " ";
	}
	cout << "\n";
	return true;
}

bool find_permutations(vector<int> v) {
	do {
		if (check_display(v)) {
			return true;
		}
	} while (next_permutation(v.begin(), v.end()));
	return false;
}

signed main() {
	freopen("arthin.txt","r",stdin);
	freopen("arthout.txt","w",stdout);
	cin >> knights;
	whitelist.assign(knights, unordered_set<int>());
	blacklist.assign(knights, unordered_set<int>());
	adj.assign(knights, pair<int, int>(-1, -1));
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		whitelist[a-1].insert(b-1);
		whitelist[b-1].insert(a-1);
	}
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		blacklist[a-1].insert(b-1);
		blacklist[b-1].insert(a-1);
	}

	for (int i = 0; i < knights; ++i) {
		if (i == 0) {
			adj[i] = make_pair(knights-1, 1);
		}
		else if (i == knights-1) {
			adj[i] = make_pair(knights-2, 0);
		}
		else {
			adj[i] = make_pair(i-1, i+1);
		}
	}

	for (int i = 0; i < knights; ++i) {
		if (whitelist[i].size() > 2) {
			cout << "Meeting cancelled.\n";
			return 0;
		}
	}
	for (int i = 0; i < knights; ++i) {
		if (blacklist[i].size() > knights-2) {
			cout << "Meeting cancelled.\n";
			return 0;
		}
	}
	for (int i = 0; i < knights; ++i) {
		round_table.push_back(i);
	}
	if (find_permutations(round_table)) {
		return 0;
	}
	cout << "Meeting cancelled.\n";
	return 0;
}