#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 10000;
vector<vector<int> > vvi(maxn, vector<int>());
bool b[maxn];
int ans = 0;

void dfs(int n) {
    for (int i = 0; i < vvi[n].size(); i++) {
        int j = vvi[n][i];
        if (vvi[j].size() && !b[j]) {
            b[j] = true;
            dfs(j);
        } 
        else if (!b[j]) {
            ans++;
            b[j] = true;
        }
    }
}

int main() {
    int n, id, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &id, &m);
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            vvi[id].push_back(x);
        }
    }
    for (int i = 0; i < maxn; i++) {
        if (vvi[i].size()) {
            b[i] = true;
            dfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
