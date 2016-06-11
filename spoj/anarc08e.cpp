#include <cstdio>
#include <algorithm>

using namespace std;
int dp[21];

int main() {
    int a, b;
    dp[0] = 1;
    for (int i = 1; i < 11; i++) dp[i] = dp[i - 1] * i;
    while(scanf("%d%d", &a, &b) && a != -1 && b != -1) {
        int c = (a + b);
        int d = dp[c] / (dp[a] * dp[b]);
        if (c != d) printf("%d+%d!=%d\n", a, b, c);
        else printf("%d+%d=%d\n", a, b, c);
    }
    return 0;
}
