#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define DEBUG 0

using namespace std;
typedef long long ll;
const int maxn = 100;
const ll maxl = 1000000000010LL;
ll pw[maxn];
ll arr[] = {0, 2, 4, 6, 8};
int pk = 1;

void init() {
    for (ll s = 20, i = 5; i < maxl; s *= 10LL, i *= 5LL) {
        pw[pk++] = s;
    }
}

ll solve(ll n) {
    if (n < 5) return arr[n];
    ll i = 1, j = 0;
    while (n >= i) {
        i *= 5;
        j++;
    }
    j--;
    i /= 5;
    ll ans = 0, t = i;
    while (i <= n) {
        i += t;
        ans += pw[(int)j];
    }
    i -= t;
    ans += solve(n - i);
    return ans;
}

int main() {
    init();
    int t; ll k;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &k);
        ll ans = solve(k - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
