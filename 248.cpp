#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<map>
using namespace std;
using ll = long long;
const ll LIMIT = 1e6 + 1, MAX_N = 1e14;
vector<ll> p, ans, d;
ll cur = 1, N;
unordered_set<ll> used, overflow;
map<ll, vector<pair<ll, ll>>> pool;
ll _pow(ll a, ll n) {
	if (n <= 1LL) return n ? a : 1LL;
	ll h = _pow(a, n / 2LL);
	return h * h * (n % 2LL ? a : 1LL);
}
void back(int pos) {
	if (N == 1) {
		ans.push_back(cur);
		return;
	}
	if (pos >= d.size()) return;
	if (N < d[pos])
		return;
	if (N % d[pos] == 0) {
		auto it = pool.find(d[pos]);
		if (it != pool.end()) {
			for (auto prs : it->second) if (used.find(prs.first) == used.end()) {
				ll pw = _pow(prs.first, prs.second);
				used.insert(prs.first);
				N /= d[pos];
				cur *= pw;
				back(pos + (it->second.size() == 1));
				cur /= pw;
				N *= d[pos];
				used.erase(used.find(prs.first));
			}
		}
		else {
			ll L = sqrt(N) + 1;
			if (N >= LIMIT && overflow.find(N) == overflow.end()) {
				overflow.insert(N);
				int can = 1;
				/*
				for (ll& pr : p) {
				if (pr > L) break;
				if ((N - 1) % pr == 0) {
				can = 0;
				break;
				}
				}
				*/
				for (ll i = 2; i <= L; i++) if ((N + 1) % i == 0) {
					can = 0;
					break;
				}
				if (can) {
					pool[N].push_back(make_pair(N + 1, 1));
					ans.push_back(cur*(N + 1));
				}
			}
		}
	}

	back(pos + 1);
}
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	long long t, i, j, L, c;
	vector<bool> chk(LIMIT, false);
	scanf("%d", &T);
	for (i = 2; i < LIMIT; i++) if (!chk[i]) {
		p.push_back(i);
		t = i - 1;
		c = 1;
		while (t < MAX_N) {
			pool[t].push_back(make_pair(i, c));
			t *= i;
			++c;
		}
		for (j = i * i; j < LIMIT; j += i) chk[j] = 1;
	}

	while (T--) {
		scanf("%lld", &N);

		ans.clear();
		d.clear();

		L = sqrt(N);
		for (i = 1; i <= 3 * L + 1; i++) if (N % i == 0) {
			d.push_back(i);
			if (N / i != i)
				d.push_back(N / i);
		}
		sort(d.begin(), d.end());
		back(0);
		if (ans.empty()) printf("none!\n");
		else {
			sort(ans.begin(), ans.end());
			L = unique(ans.begin(), ans.end()) - ans.begin();
			printf("%lld\n", ans[L - 1]);
			//for (i = 0; i<L; i++) printf("%lld ", ans[i]);
			//printf("\n");
		}
	}
	return 0;
}
