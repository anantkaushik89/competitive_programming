#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 110;
const int INF = 999999999;
int inp[maxn];
int dp[maxn][maxn];
int color[maxn][maxn];

void solve(int n) {
    memset(dp, 0, sizeof(dp));
    memset(color, 0, sizeof(color));

    for (int i = 0; i <= n; i++) {
        dp[i][i] = 0;
        color[i][i] = inp[i];
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            int cost = INF;
            int sk = 0;
            for (int k = i; k < j; k++) {
                int lc = dp[i][k] + dp[k + 1][j] + color[i][k] * color[k + 1][j];
                if (cost > lc) {
                    cost = lc;
                    sk = k;
                }
            }
            dp[i][j] = cost;
            int c = (color[i][sk] + color[sk + 1][j]) % 100;
            color[i][j] = c;
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++)
            scanf("%d", inp + i);
        solve(n);
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
