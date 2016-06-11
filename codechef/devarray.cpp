#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int inp[maxn];

int main() {
    int n, q, x;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) 
        scanf("%d", inp + i);
    sort(inp, inp + n);
    int mn = inp[0];
    int mx = inp[n - 1];
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        if (x >= mn && x <= mx)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
