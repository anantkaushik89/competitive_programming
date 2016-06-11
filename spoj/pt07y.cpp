#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAXN = 10010;
bool b[MAXN];
int par[MAXN];
vector<vector<int> > vvi;

bool bfs(int n) {
    queue<int> q;
    int nc = 0;
    q.push(1);
    b[1] = true;
    par[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        nc++;
        q.pop();
        for (int i = 0; i < vvi[x].size(); i++) {
            int y = vvi[x][i];
            if (b[y] && par[x] != y) 
                return false;
            else if (!b[y]){
                b[y] = true;
                par[y] = x;
                q.push(y);
            }
        }
    }
    if (nc == n) return true;
    else return false;
}

int main() {
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    vvi.resize(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        vvi[u].push_back(v);
        vvi[v].push_back(u);
    }
    if (bfs(n)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
