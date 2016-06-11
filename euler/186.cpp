#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 1000001;
map<ll, int> s;
map<ll, int> r;
ll records[maxn][2];
ll aux[2 * maxn];
int par[maxn], rank[maxn];
int tx, rx;

void init() {
    for (int i = 1; i < maxn; i++) {
        par[i] = i; rank[i] = 1;
    }
    for (int i = 1; i < 2 * maxn; i++) {
        ll t = 0;
        if (i < 56) {
            ll t1 = (200003 * (ll)i) % 1000000LL;
            ll t2 = ((ll)i * (ll)i) % 1000000LL;
            t2 = (t2 * i) % 1000000LL;
            t2 = (t2 * 300007) % 1000000LL;
            t = (100003 - t1 + t2) % 1000000LL;
        }
        else
            t = (aux[i - 24] + aux[i - 55]) % 1000000LL;
        aux[i] = t;
    }
    for (int i = 1; i < maxn; i++) {
        records[i][0] = aux[2 * i - i];
        records[i][1] = aux[2 * i];
        cout << aux[2 * i - 1] << " " << aux[2 * i] << endl;
        if (records[i][1] == 524287) rx = i;
        else if (records[i][0] == 524287) tx = i;
        s[records[i][0]] = i;
        s[records[i][1]] = i;
    }
}

int find(int x) {
    if (par[x] != x) 
        par[x] = find(par[x]);
    return par[x];
}

void _union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        if (rank[px] > rank[py])
            par[py] = px;
        else {
            par[px] = py;
            if (rank[px] == rank[py])
                rank[py]++;
        }
    }
}

int main() {
    init();
    cout << rx << " " << tx << endl;
    return 0;
}
