#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 101;
const int maxv = 100010;
typedef long long ll;
bool b[maxv];
int dp[maxv][maxn];
int inp[maxn];


ll solve(int lim, int n) {
    memset(dp, 0, sizeof(dp));
    memset(b, 0, sizeof(b));
    dp[0][0] = 1;

    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;

    for (int i = 1; i <= lim; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= lim; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (inp[j - 1] <= i) 
                dp[i][j] = dp[i][j] || dp[i - inp[j - 1]][j - 1];
            if (dp[i][j])
                b[i] = 1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= lim; i++) 
        if (b[i]) {
            ans += (ll)i;
        }
    
    return ans;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int lim = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", inp + i);
            lim += inp[i];
        }
        ll ans = solve(lim, n);
        printf("%lld\n", ans);
    }
    return 0;
}
