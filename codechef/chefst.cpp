#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    int t;
    ll n1, n2, m, ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld", &n1, &n2, &m);
        ll mx = max(n1, n2);
        ll sm = m * (m + 1) / 2;
        if (mx <= sm) {
            if (n1 == n2) ans = 0;
            else ans = max(n1, n2) - min(n1, n2);
        }
        else {
            ll mn = min(n1, n2);
            if (mn <= sm) ans = mx - mn;
            else ans = n1 + n2 - 2 * sm;
        }
        printf("%lld\n", ans); 
    }
    return 0;
}
