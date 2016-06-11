#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <cassert>

using namespace std;
typedef pair<int, int> pii;
const int MAXV = 80010;
const int INF = 1000000000;
vector<vector<pii> > vvi(MAXV, vector<pii>());
int heap_l;
pii heap[MAXV];
bool seen[MAXV];
int curr_wt[MAXV];
map<string, int> m;
char name1[20], name2[20];

void init() {
    for (int i = 0; i < MAXV; i++) {
        curr_wt[i] = INF;
        seen[i] = false;
        vvi[i].clear();
    }
    m.clear();
    heap_l = 0;
}

void reset() {
    for (int i = 0; i < MAXV; i++) {
        curr_wt[i] = INF;
        seen[i] = false;
    }
    heap_l = 0;
}

void heap_up(int idx) {
    if (!idx) return;
    int par = (idx - 1) / 2 ;
    if (heap[par].second > heap[idx].second) {
        int tmp1 = heap[par].second, tmp2 = heap[par].first;
        heap[par].second = heap[idx].second;
        heap[par].first = heap[idx].first;
        heap[idx].second = tmp1;
        heap[idx].first = tmp2;
        heap_up(par);
    }
}

void heap_insert(pii n) {
    assert(heap_l + 1 < MAXV);
    heap[heap_l++] = n;
    heap_up(heap_l - 1);
}

void heap_down(int idx, int lim) {
    int lc = idx * 2 + 1;
    int curr = idx;
    if (lc > lim) return;
    if (heap[lc].second < heap[curr].second)
        curr = lc;
    int rc = idx * 2 + 2;
    if (rc <= lim && heap[rc].second < heap[curr].second)
        curr = rc;
    if (curr != idx) {
        int tmp1 = heap[curr].second, tmp2 = heap[curr].first;
        heap[curr].second = heap[idx].second;
        heap[curr].first = heap[idx].first;
        heap[idx].second = tmp1;
        heap[idx].first = tmp2;
        heap_down(curr, lim);
    }
}

pii heap_pop() {
    pii f = heap[0];
    heap_l--;
    //assert(heap_l >= 0);
    heap[0] = heap[heap_l];
    heap_down(0, heap_l);
    return f;
}

int djikstra(int x, int y) {
    heap[heap_l++] = make_pair(x, 0);
    curr_wt[x] = 0;
    while (true) {
        pii n = heap_pop();
        if (seen[n.first]) continue;
        seen[n.first] = true;
        if (n.first == y) 
            return n.second;
        vector<pii>& nrs = vvi[n.first];
        for (int i = 0; i < nrs.size(); i++) {
            pii p = nrs[i];
            if (!seen[p.first]) {
                int wt = p.second + n.second;
                if (curr_wt[p.first] > wt) {
                    curr_wt[p.first] = wt;
                    heap_insert(make_pair(p.first, wt));
                }
            }
        }
    }
}

int main() {
    int t, n, p, nr, c, r;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d\n", &n);
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%s\n", name1);
            m[name1] = i;
            scanf("%d\n", &p);
            for (int j = 0; j < p; j++) {
                scanf("%d %d\n", &nr, &c);
                vvi[i].push_back(make_pair(nr, c));
                vvi[nr].push_back(make_pair(i, c));
            }
        }
        scanf("%d\n", &r);
        for (int i = 0; i < r; i++) {
            reset();
            scanf("%s %s\n", name1, name2);
            int x = m[name1];
            int y = m[name2];
            int ans = djikstra(x, y);
            printf("%d\n", ans);
        }
    }
    init();
    return 0;
}

