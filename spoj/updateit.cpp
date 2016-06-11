#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10010;
typedef long long ll;
ll inp[MAXN], inc[MAXN], dec[MAXN];

void reset() {
    memset(inp, 0, sizeof(inp));
    memset(inc, 0, sizeof(inc));
    memset(dec, 0, sizeof(dec));
}

int main() {
    int t, n, u, l, r, q, j; ll val;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &u);
        reset();
        for (int i = 0; i < u; i++) {
            scanf("%d%d%lld", &l, &r, &val);
            inc[l] += val; dec[r + 1] -= val;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += inc[i] + dec[i];
            inp[i] = ans;
        }
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d", &j);
            printf("%lld\n", inp[j]);
        }
    }
    return 0;
}
