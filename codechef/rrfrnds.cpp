#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

char s[2010][2010];
int p[2010], r[2010];

int find(int i) {
    if (p[i] != i) 
        p[i] = find(p[i]);
    return p[i];
}

void _union(int i, int j) {
    int pi = find(i);
    int pj = find(j);
    if (pi != pj) {
        if (r[pi] >= r[pj]) {
            r[pi]++;
            p[pj] = pi;
        }
        else {
            r[pj]++;
            p[pi] = pj;
        }
    }
    return;
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s\n", s[i]);
        p[i] = i; r[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i][j] == '1') 
                _union(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i][j] != '1') { 
                int pi = find(i);
                int pj = find(j);
                if (pi == pj) ans += 2;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
