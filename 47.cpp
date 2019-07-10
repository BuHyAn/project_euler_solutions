#include<cstdio>
#include<cmath>
using ll = long long;
const int MAX_N = 1e7, LIMIT = 1e7;
int main() {
	freopen("input.txt", "r", stdin);
	ll i, j, p, cur, c, b, chk[LIMIT] = {};
	for (i = 2; i < LIMIT; i++) if (!chk[i]) {
		for (j = 2 * i; j < LIMIT; j += i)
			chk[j] += 1;
	}
	c = 0;
	b = 4;
	for (i = 4; i < MAX_N; i++) {
		if (chk[i] == 4) {
			if (!c) b = i;
			c++;
		}
		else c = 0;
		if (c == 4) {
			printf("%lld", b);
			break;
		}
	}

	return 0;
}
