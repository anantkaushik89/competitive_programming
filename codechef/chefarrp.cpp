#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int maxn = 60;
ll inp[maxn];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lld", inp + i);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ll p = 1, s = 0;
            for (int j = i; j < n; j++) {
                p *= inp[j]; s += inp[j];
                if (p == s) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
