#include <algorithm>
#include <cstdio>

using namespace std;
const int maxn = 10010;
typedef long long ll;
ll inp[maxn];

int main() {
    int t, n, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld", inp + i);
        ll time = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b);
            time += b;
            if (time <= inp[i]) {
                ans++;
            }
            time = inp[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
