#include <cstdio>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;

typedef long long ll;
const ll mod = (ll)1 << 32;
const ll maxn = (((ll)1 << 31) - 1);
set<ll> s;
bool bb[maxn];
int main() {
    int q; ll a, b, s1;
    scanf("%d%lld%lld%lld", &q, &s1, &a, &b);
    ll ans = 0;
    for (int i = 0; i < q; i++) {
        ll n = s1 >> 1;
        if (n < maxn) {
            if (s1 & 1) {
                if (bb[n] == 0) ans += n;
                bb[n] = 1;
            }
            else {
                if (bb[n] == 1) ans -= n;
                bb[n] = 0;
            }
        }
        else {
            if (s1 & 1) s.insert(n);
            else s.erase(n);
        }
        s1 = (a * s1 + b) % mod;
        if (s1 < 0) s1 = (s1 + mod) % mod;
    }
    set<ll>::const_iterator sitr, se = s.end();
    for (sitr = s.begin(); sitr != se; sitr++) ans += *sitr;
    printf("%lld\n", ans);
    return 0; 
}
