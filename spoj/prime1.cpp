#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 32000;
const int maxl = 100010;
int mark[maxl];
bool b[maxn];
int pr[maxn];
int pk;

void init() {
    b[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!b[i]) {
            pr[pk++] = i;
            for (int j = i * i; j < maxn; j += i)
                b[j] = 1;
        }
    }
}

int main() {
    init();
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        memset(mark, 0, maxl);
        scanf("%d%d", &m, &n);
        for (int i = m; i <= n; i++) {
            //if (mark[i - m]) continue;
            for (int j = 0; j < pk && pr[j] * pr[j] <= i; j++) {
                if (i % pr[j] == 0) {
                    for (int k = i; k <= n; k += pr[j])
                        mark[k - m] = 1;
                    break;
                }
            }
            if (i == 1) mark[i - m] = 1;
        }
        for (int i = 0; i < (n - m + 1); i++) 
            if (!mark[i])
                printf("%d\n", i + m);
        printf("\n");
    }
    return 0;
}
