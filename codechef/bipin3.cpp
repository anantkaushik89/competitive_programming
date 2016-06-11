#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll power(ll a, int b) {
    if (b == 0) return 1;
    else if (b == 1) return a;
    else {
        ll t = power(a, b / 2);
        t = (t * t) % mod;
        if (t < 0) t = (t + mod) % mod;
        if (b & 1) t = (t * a) % mod;
        if (t < 0) t = (t + mod) % mod;
        return t;
    }
}

int main() {
    int t, n; ll k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &n, &k);
        ll ans = k - 1;
        ans = power(ans, n - 1);
        ans = (ans * k) % mod;
        printf("%lld\n", ans);
    }
}
