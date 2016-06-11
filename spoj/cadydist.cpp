#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
typedef long long ll;
ll nm[MAXN];
ll pr[MAXN];

int main() {
    int n; ll ans = 0;
    while (scanf("%d", &n) && n) {
        ans = 0;
        for (int i = 0; i < n; i++)
            scanf("%lld", nm + i);
        for (int i = 0; i < n; i++)
            scanf("%lld", pr + i);
        sort(nm, nm + n);
        sort(pr, pr + n);
        for (int i = 0; i < n; i++) 
            ans += (nm[i] * pr[n - i - 1]);
        printf("%lld\n", ans);
    }
    return 0;
}
