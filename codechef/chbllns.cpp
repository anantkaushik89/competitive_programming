#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
int main() {
    int t; ll k;
    ll c[3];
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 3; i++) scanf("%lld", c + i);
        scanf("%lld", &k);
        sort(c, c + 3);
        int i; ll ans = 0;
        for(i = 0; i < 3; i++) {
            if (c[i] < k) ans += c[i];
            else break;
        }
        ans += (3 - i) * (k - 1) + 1;
        printf("%lld\n", ans);
    }
}
