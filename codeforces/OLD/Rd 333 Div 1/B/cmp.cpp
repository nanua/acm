#include <bits/stdc++.h>

using namespace std;

long long vet[100010];
long long dif[100010];
long long a[100010];
long long b[100010];

long long stac[100010];
long long fim = 0;

int main() {
	
	freopen("in","r",stdin);
	freopen("std","w",stdout);
	long long n, q;
	
	scanf("%lld %lld", &n, &q);
	
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &vet[i]);
	}
// 	printf("0\n");
	for (long long i = 0; i < n - 1; i++) {
		dif[i] = abs(vet[i + 1] - vet[i]);
	}
// 	printf("1\n");
	for (long long i = 0; i < n - 1; i++) {
		if (!fim) {
			a[i] = -1;
		} else {
			while (fim && dif[stac[fim - 1]] < dif[i]) {
				fim--;
			}
			if (!fim) {
				a[i] = -1;
			} else {
				a[i] = stac[fim - 1];
			}
		}
		stac[fim++] = i;
	}
// 	printf("2\n");
	fim = 0;
	for (long long i = n - 2; i >= 0; i--) {
		if (!fim) {
			b[i] = n - 1;
		} else {
			while (fim && dif[stac[fim - 1]] < dif[i]) {
				fim--;
			}
			if (!fim) {
				b[i] = n - 1;
			} else {
				b[i] = stac[fim - 1];
			}
		}
		stac[fim++] = i;
	}
// 	printf("3\n");
	
// for (long long i = 0; i < n - 1; i++) {
// printf("(%lld, %lld, %lld)\n", dif[i], a[i], b[i]);
// }
	long long resp = 0;
	for (long long i = 0; i < q; i++) {
		long long l, r;
		scanf("%lld %lld", &l, &r);
		l--, r--;
		
		resp = 0;
		for (long long j = l; j < r; j++) {
			long long aa = max(a[j], l - 1);
			long long bb = min(b[j], r);
// 			printf("%lld %lld %lld\n", dif[j], a[j], b[j]);
// 			printf("%lld %lld\n", aa, bb);
// 			printf("(%lld,%lld)\n", (j - aa), (bb - j));
			resp += dif[j] * (j - aa) * (bb - j);
		}
		printf("%lld\n", resp);
	}
	
	return 0;
	
}
