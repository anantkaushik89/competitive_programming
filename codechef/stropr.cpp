#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn = 100010;
ll inp[maxn];
const ll modn = 1000000007;

ll mod_inverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1)
      return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
 
    if (x1 < 0)
       x1 += m0;
 
    return x1 % m0;
}

int main() {
    int t, n, x; ll m, ai;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%lld", &n, &x, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &ai);
            inp[i] = ai % modn;
        }
        ll num = 1, den = 1, d = 1, ans = inp[x];
        for (int i = x - 1; i >= 1; i--) {
            ll tp = (m + x - i - 1) % modn;
            if (tp < 0) tp = (tp + modn) % modn;
            num = (num * tp) % modn;
            if (num < 0) num = (num + modn) % modn;
            d = (d * den) % modn;
            if (d < 0) d = (d + modn) % modn;
            ll inv_den = mod_inverse(d, modn);
            ll temp = (num * inv_den) % modn;
            if (temp < 0) temp = (temp + modn) % modn;
            ll X = (temp * inp[i]) % modn;
            if (X < 0) X = (X + modn) % modn;
            ans = (ans + X) % modn;
            den++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
