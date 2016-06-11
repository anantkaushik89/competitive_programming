#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;
const int maxn = 100010;
int inp[maxn];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", inp + i);
        bool f = false;
        for (int i = 0; i < n - 2; i++) {
            if (inp[i] == inp[i + 1] && inp[i + 1] == inp[i + 2]) {
                f = true;
                break;
            }
        }
        if (f) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

