#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100010;
char s[2][maxn];
pii p[4];

bool compare(const pii& p1, const pii& p2) {
    return p1.first < p2.first;
}

bool dfs(int i, int n) {
    if (i == n) return true;
    char up = s[0][i];
    char down = (i == 0) ? 'F' : s[1][i - 1];
    bool b = false;
    int j = 0;
    for (; j < 4; j++) {
        char t = 'A' + p[j].second;
        if (t != up && t != down && p[j].first < n / 2) {
            p[j].first++;
            s[1][i] = t;
            b = dfs(i + 1, n);
            //assert(b);
            if (b)
                break;
            p[j].first--;
            j = 0;
        }
    }
    return b;
}

int main() {
    int n;
    scanf("%d\n", &n);
    scanf("%s", s[0]);
    for (int i = 0; i < 4; i++) {
        p[i].first = 0; p[i].second = i;
    }
    for (int i = 0; i < 2 * n; i++) 
        p[s[0][i] - 'A'].first++;
    bool b = dfs(0, 2 * n); 
    assert(b);
    s[1][2 * n] = 0;
    printf("%s\n", s[1]);
    /*for (int i = 1; i < 4; i++) {
        if (p[i].first != p[i - 1].first) {
            printf("%d %d\n", p[i].first, p[i - 1].first);
            assert(0);
        }
    }*/
    return 0;
}
