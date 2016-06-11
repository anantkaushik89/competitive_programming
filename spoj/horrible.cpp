#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int maxn = 100010;
ll ft1[maxn];
ll ft2[maxn];

void point_update(ll ft[], ll v, int idx, int n) {
    for (int i = idx; i <= n; i += (i & (-i)))
        ft[i] += v;
}

ll point_query(ll ft[], int idx, int n) {
    ll sum = 0;
    for (int i = idx; i; i -= (i & (-i)))
        sum += ft[i];
    return sum;
}

void update(ll v, int a, int b, int n) {
    point_update(ft1, v, a, n);
    point_update(ft1, -v, b + 1, n);
    point_update(ft2, v * (a - 1), a, n);
    point_update(ft2, -v * b, b + 1, n);
}

ll query(int idx, int n) {
    ll pq = 0;
    pq = point_query(ft1, idx, n) * idx;
    pq -= point_query(ft2, idx, n);
    return pq;
}

int main() {
    int t, n, c, x, p, q; ll v;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &c);
        memset(ft1, 0, sizeof(ft1));
        memset(ft2, 0, sizeof(ft2));
        while (c--) {
            scanf("%d%d%d", &x, &p, &q);
            if (x == 0) {
                scanf("%lld", &v);
                update(v, p, q, n);
            }
            else {
                ll x = query(q, n);
                x -= query(p - 1, n);
                printf("%lld\n", x);
            }
        }
    }
    return 0;
}
