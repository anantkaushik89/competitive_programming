#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxl = 100010;
char s[maxl];
int dp[26];

void reset() {
    memset(dp, 0, sizeof(dp));
}

int main() {
    int t, k;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%s %d\n", s, &k);
        int len = strlen(s);
        reset();
        for (int i = 0; i < len; i++)
            dp[s[i] - 'a']++;
        sort(dp, dp + 26);
        int sp = 0;
        for (sp = 0; sp < 26; sp++)
            if (dp[sp]) break;
        int ll = 26 - sp; int ans = -1;
        for (int l = ll; l >= 1; l--) {
            for (int i = sp; i + l - 1 < 26; i++) {
                int j = i + l - 1;
                if ((dp[j] - dp[i]) <= k) {
                    ans++;
                    for (int ss = i; ss <= j; ss++) 
                        ans += dp[ss];
                    break;
                }
            }
            if (ans >= 0) break;
        }
        printf("%d\n", len - ans);
    }
    return 0;
}
