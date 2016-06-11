#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;
const int maxn = 100010;
typedef long long ll;
const ll modn = 1000000007LL;
int inp[maxn];
ll dp[maxn];

void init() {
    dp[0] = 1;
    for (int i = 1; i < maxn; i++) 
        dp[i] = dp[i - 1] * i % modn;
}

ll power(ll a, int b) {
    if (b == 0) return 1LL;
    else if (b == 1) return a % modn;
    else {
        ll t = power(a, b / 2);
        t = (t * t) % modn;
        if (t < 0) t = (t + modn) % modn;
        if (b & 1)
        t = (t * a) % modn;
        if (t < 0) t = (t + modn) % modn;
        return t;
    }
}

ll solve(ll n, ll k) {
    ll num = dp[n];
    ll den1 = dp[k];
    ll den2 = dp[n - k];
    ll prod = (den1 * den2) % modn;
    if (prod < 0) prod = (prod + modn) % modn;
    ll pw = power(prod, (int)modn - 2);
    num = (num * pw) % modn;
    if (num < 0) num = (num + modn) % modn;
    //printf("%lld %lld = %lld\n", n, k, num);
    return num;
}

int main() {
    int t, n, k;
    init();
    scanf("%d", &t);
    while (t--) {
        int nz = 0;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", inp + i);
            if (!inp[i]) nz++;
        }
        if (n == 1) {
            printf("1\n");
            continue;
        }
        int sp = k & 1 ? 1 : 0;
        int j = 2;
        if (nz) {
            n -= nz;
            j = 1;
            sp = 0;
        }
        ll ans = 0;
        for (; sp <= min(k, n); sp += j) {
            ans += solve(n, sp);
            ans %= modn;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
