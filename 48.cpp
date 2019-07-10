#include<cstdio>
#include<cmath>
using ll = long long;
const ll MOD = 1e10;
ll _pow(int a, int n) {
	ll ret = 1;
	for (ll i = 1; i <= n; i++) {
		ret *= a;
		ret %= MOD;
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	ll res = 0;
	for (ll i = 1; i <= 1000; i++) {
		res = (res + _pow(i, i)) % MOD;
		printf("%lld\n", _pow(i, i));
	}
	printf("%lld", res);
	return 0;
}
