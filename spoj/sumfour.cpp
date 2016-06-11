#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 4000;
const int maxl = 16000000;
const int sz = 1 << 29;

int a[4][maxn];
int aa[maxl];
int bb[maxl];

int find_bs_l(int v, int n, int* arr) {
}

int find_bs_h(int v, int n, int* arr) {
}

int main() {
    int n, x[4];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            scanf("%d", a[j] + i);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aa[k++] = a[0][i] + a[1][j];
            bb[k] = a[2][i] + a[3][j];
        }
    }
    sort(bb, bb + k);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int v = -aa[i];
        int l = find_bs_l(v, k, bb);
        int h = find_bs_h(v, k, bb);
        if (l != -1) ans += h - l + 1;
    }
    printf("%d\n", ans);
    return 0;
}
