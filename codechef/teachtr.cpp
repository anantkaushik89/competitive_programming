#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
using namespace std;
const int MAXN = 100010;
typedef pair<int, int> pii;
vector<vector<int> > vvi(MAXN, vector<int>());
vector<pii> vp(MAXN);
bool b[MAXN];
int start = 0;

void dfs(int u) {
    vector<int>& vs = vvi[u];
    start++;
    vp[u].first = start;
    b[u] = true;
    for (int i = 0; i < vs.size(); i++) {
        assert(!b[vs[i]]);
        dfs(vs[i]);
    }
    start++;
    vp[u].second = start;
}

void dfs_init(int n) {
    for (int i = 1; i <= n; i++) {
        if (!b[i]) 
            dfs(i);       
    }
}

int main() {
    int n, q, a, b, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        vvi[a].push_back(b);
    }
    dfs_init(n);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &x, &y);
        int start_x = vp[x].first;
        int start_y = vp[y].first;
        int end_x = vp[x].second;
        int end_y = vp[y].second;
        //printf("sx:%d sy:%d ex:%d ey%d\n", start_x, start_y, end_x, end_y);
        // First check if x is child of y
        if (start_x > start_y) {
            if (end_x < end_y) 
                printf("%d taught %d\n", y, x);
            else
                printf("No idea\n");
        }
        else if (start_y > start_x){
            if (end_y < end_x) 
                printf("%d taught %d\n", x, y);
            else
                printf("No idea\n");
        }
        else 
            assert(0);   
    }
    return 0;
}
