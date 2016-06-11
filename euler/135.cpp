#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1000000;
bool b[maxn];
void init() {
    for (int i = 2; i <= 1000; i++) {
        if (!b[i]) {
            for (int j = i * i; j < maxn; j += i)
                b[j] = true;
        }
    }
}

int main() {
    int cnt = 0;
    init();
    for (int n = 1155; n < maxn; n++) {
        if (!b[n]) continue;
        int lim = sqrt(n) + 1;
        int ans = 0;
        for (int i = 1; i <= lim; i++) {
            if (n % i == 0) {
                int u = i, v = n / i;
                int d = (u + v);
                int oldd = 0, oldz = 0;
                int z = (3 * u - v);
                if (d % 4 == 0 && z % 4 == 0) {
                    d = d / 4; z = z / 4;
                    oldd = d, oldz = z;
                    if (z > 0)
                        ans++;
                }
                u = n / i, v = i;
                d = (u + v);
                z = (3 * u - v);
                if (d % 4 == 0 && z % 4 == 0) {
                    d = d / 4; z = z / 4;
                    if (z > 0) {
                        if (d != oldd || z != oldz)
                            ans++;
                    }
                }
            }
        }
        //printf("%d\n", ans);
        if (ans == 10) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
