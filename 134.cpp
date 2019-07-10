#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
using namespace std;
using ll = long long;
const int LIMIT = 1100001, LL = 20;
ll eea(ll a, ll b, ll& x, ll& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = eea(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}
const int MOD = 1e5;
ll a[LL], b[LL];
void apply() {
	ll i, s, c = 0;
	for (i = 0; i < LL; i++) {
		s = a[i] + b[i] + c;
		c = s / MOD;
		s %= MOD;
		a[i] = s;
	}
}
void pr() {
	int i;
	for (i = LL - 1; i >= 0; i--) if (a[i])
		break;
	printf("%d", a[i]);
	i--;
	while (i >= 0) {
		printf("%05d", a[i]);
		i--;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	vector<int> p;
	bool chk[LIMIT] = {1,1};
	ll i, j, p10 = 1, ans = 0, d, k, dx, dy, x, y, c;
	for (i = 2; i < LIMIT; i++) if (!chk[i]) {
		p.push_back(i);
		for (j = i * i; j < LIMIT; j += i)
			chk[j] = 1;
	}
	for (i = 2; p[i] <= 1e6; i++) {
		if (p10 < p[i]) p10 *= 10;
		d = eea(p[i + 1], p10, x, y);
		assert(p[i] % d == 0);
		assert(d == 1);

		k = p[i] / d;
		x *= k;
		y *= k;
		dx = p10 / d, dy = p[i + 1] / d;
		
		
		c = (-x + 1) / dx;
		x += c * dx;
		y -= c * dy;
		//printf("%lld\n", -y * p10 + p[i]);
		while (y >= 0) {
			x += dx;
			y -= dy;			
		}
		assert(-y * p10 + p[i] == x * p[i + 1]);
		memset(b, 0, sizeof b);
		ans = -y * p10 + p[i];
		//printf("%lld\n", ans);
		assert(ans >= 0);
		for (int j = 0; j < LL; j++) {
			b[j] = ans % MOD;
			ans /= MOD;
		}
		apply();
	}
	pr();
	return 0;
}