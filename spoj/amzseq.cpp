#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

const int maxl = 100;
typedef long long ll;
ll dp[maxl][3];

ll recurse(int k, int l, char prev) {
    if (k == l) {
        return 1;
    }
    ll sum = 0;
    for (char i = 'a'; i < 'd'; i++) {
        if (dp[k][i - 'a'] == -1) {
            if (abs(i - prev) < 2) { 
                dp[k][i - 'a'] = 0;
                dp[k][i - 'a'] += recurse(k + 1, l, i);
            }
        }
        if (abs(i - prev) < 2) { 
            sum += dp[k][i - 'a'];
        }
    }
    return sum;
}

void reset() {
    for (int i = 0; i < maxl; i++)
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
}

int main() {
    int n;
    scanf("%d", &n);
    reset();
    ll ans = recurse(0, n, 'b');
    printf("%lld\n", ans);
    return 0;
}
