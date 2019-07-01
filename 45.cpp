#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
using ll = long long;

bool is(ll x, ll d, ll remains, ll a) {
	ll r = sqrt(1 + d * x);
	return r * r == 1 + d * x && r % a == remains;
}
int main() {
	freopen("input.txt", "r", stdin);
	vector<ll> pn;
	ll i = 40755, c = 1, cur = 1, k = 143;
	while (1) {
		i += 4LL * k + 1;
		k++;
		if (is(i, 24, 5, 6) && is(i, 8, 3, 4) && is(i, 8, 1, 2)) {
			printf("%lld", i);
			break;
		}

	}
	return 0;
}
