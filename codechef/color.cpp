#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
char s[MAXN];

int c[3];

int main() {
    int t, n;
    scanf("%d\n", &t);
    while (t--) {
        c[0] = c[1] = c[2] = 0;
        scanf("%d\n", &n);
        scanf("%s\n", s);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') c[0]++;
            else if (s[i] == 'G') c[1]++;
            else c[2]++;
        }
        int ans = max(c[0], max(c[1], c[2]));
        ans = n - ans;
        printf("%d\n", ans);
    }
    return 0;
}
