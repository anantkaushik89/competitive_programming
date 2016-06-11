#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int p[37];
int c[37];

void recurse(int* a, int ix, int j, int l, int* d) {
    if (ix == j) {
        int s = 0;
        for (int i = 0; i < j; i++)
            s += a[i];
        d[s]++;
        return;
    }
    for (int i = 1; i <= l; i++) {
        a[ix] = i;
        recurse(a, ix + 1, j, l, d);
    }
}

int main() {
    int a[9];
    memset(a, 0, sizeof(a));
    recurse(a, 0, 9, 4, p);
    memset(a, 0, sizeof(a));
    recurse(a, 0, 6, 6, c);
    for (int i = 1; i < 37; i++)
        c[i] += c[i - 1];
    long long ans = 0;
    for (int i = 1; i < 37; i++) {
        ans += (p[i] * c[i - 1]);
    }
    cout << ans << endl;
    long long total = 36LL * 36LL * 36LL * 256 * 256 * 4;
    cout << total << endl;
    //cout << ans / total << endl;
    return 0;
}
