#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxl = 6110;
char a[maxl], b[maxl];
int dp[maxl][maxl];

void reverse(char* a, char* b, int l) {
    for (int i = l - 1; i >= 0; i--)
        b[l - i - 1] = a[i];
    b[l] = 0;
}

int lcs(char* a, char* b, int l) {
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            int t = dp[i - 1][j - 1];
            if (a[i - 1] == b[j - 1]) t++;
            dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], t));
        }
    }
    return dp[l][l];
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        gets(a);
        int l = strlen(a);
        memset(dp, 0, sizeof(dp));
        reverse(a, b, l);
        int lc = lcs(a, b, l);
        printf("%d\n", l - lc);
    }
    return 0;
}
