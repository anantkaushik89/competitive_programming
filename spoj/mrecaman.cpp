#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

const int N = 500010;
set<int> s;
int a[N];
int b[3012900];

void init() {
    a[0] = 0;
    for (int i = 1; i < N; i++) {
        int t = a[i - 1] - i;
        if (t > 0 & !b[t]) {
            b[t] = 1;
            a[i] = t;
        }
        else {
            t = a[i - 1] + i;
            b[t] = 1;
            a[i] = t;
        }
    }
}

int main() {
    init();
    int n;
    while(scanf("%d", &n) && n != -1) {
        printf("%d\n", a[n]);
    }
    return 0;
}
