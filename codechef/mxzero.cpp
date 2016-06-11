#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t, n, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int t1 = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x) t1++;
        }
        if (t1 & 1) printf("%d\n", t1);
        else printf("%d\n", n - t1);
    }
    return 0;
}
