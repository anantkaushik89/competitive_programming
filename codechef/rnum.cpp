#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;
const int maxn = 100010;
int inp[maxn];

int get_min(int n) {
    int prev = inp[0];
    int ans = 1, l = 1;
    for (int i = 1; i < n; i++) {
        if (inp[i] - prev == 1) 
            l = (l + 1) % 3;
        else l = 1;
        if (l == 1) ans++;
        if (!l) prev = 1000100;
        else prev = inp[i];
    }
    return ans;
}

int get_max(int n) {
    int first = inp[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (abs(inp[i] - first) > 1) {
            ans++;
            first = inp[i];
        }
    }
    return ans;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", inp + i);
        sort(inp, inp + n);
        int mn = get_min(n);
        int mx = get_max(n);
        printf("%d %d\n", mn, mx);
    }
    return 0;
}
