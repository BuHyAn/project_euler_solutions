#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
using ll = long long;
const int MAX_N = 1e7, LIMIT = 1e6;
int can[MAX_N];
int main() {
	freopen("input.txt", "r", stdin);
	bool chk[LIMIT] = {};
	ll i, j, p, cur;
	vector<ll> pows;
	pows.push_back(1);
	for (i = 2; i < 1e5; i++) {
		pows.push_back(i*i);
	}
	for (i = 2; i < LIMIT; i++) if (!chk[i]) {
		p = i;
		for (auto it : pows) {
			if (p + 2*it >= MAX_N) break;
			can[p + 2 * it] = 1;
		}
		for (j = i * i; j < LIMIT; j += i)
			chk[j] = 1;
	}
	for (i = 3; i < MAX_N; i += 2) {
		if (chk[i] && !can[i]) {
			printf("%lld", i);
			break;
		}
	}
	return 0;
}
