#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int MAXN = 5010;
char s[MAXN];
ll dp[MAXN];

ll get(int i, int n) {
    if (i >= n) return 1;
    else if (s[i] == '0') return 0;
    else if (dp[i] != -1) return dp[i];
    else {
        ll x = 0;
        x = get(i + 1, n);
        dp[i] = x;
        if (i + 1 < n) {
            int t = (s[i] - '0') * 10 + s[i + 1] - '0';
            if (t <= 26)
                dp[i] += get(i + 2, n);
        }
        return dp[i];
    }
}

int main() {
    while (scanf("%s", s)) {
        if (s[0] != '0') {
            int l = strlen(s);
            for (int i = 0; i <= l; i++) dp[i] = -1;
            ll ans = get(0, l);
            printf("%lld\n", ans);
        }
        else break;
    }
    return 0;
}
