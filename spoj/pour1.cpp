#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);
        a = max(a, b);
        b = min(a, b);
        if (a < c) printf("-1\n");
        else {
            int ans = -1;
            for (int i = 1; (a * (i - 1) - b * (i - 1)) <= c; i++) {
                int d = a * i - b * (i - 1);
                if (d == c) {
                    if (i != 1) i++;
                    ans = 2 * i - 1; break;
                }
                int d = a * (i - 1) - b * i;
                if (d == c) {
                    if (i != 1) i++;
                    ans = 2 * i - 1; break;
                }
                d = a * i - b * i;
                if (d == c) {
                    if (i != 1) i++;
                    ans = 2 * i; break;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
