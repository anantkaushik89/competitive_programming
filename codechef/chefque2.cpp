#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = (ll)1 << 32;
typedef unsigned int uint;
const int maxn = 10000000;
typedef pair<uint, pair<int, int> > ppi;

bool comp(const ppi& p1, const ppi& p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    else return (p1.second.first < p2.second.first);
}

ppi p[maxn];

int main() {
    int q; ll a, b, s1;
    scanf("%d%lld%lld%lld", &q, &s1, &a, &b);
    for (int i = 0; i < q; i++) {
        ll n = s1 >> 1;
        int op = (s1 & 1) ? 1 : -1;
        pair<int, int> pii = make_pair(i + 1, op);
        ppi pi = make_pair((int)n, pii);
        p[i] = pi;
        s1 = (a * s1 + b) % mod;
        if (s1 < 0) s1 = (s1 + mod) % mod;
    }
    sort(p, p + q, comp);
    ll ans = 0, prev = -1;
    bool plus = true;
    /*for (int i = 0; i < q; i++) {
        //printf("%d\n", p[i].first);
        if (prev != p[i].first) {
            plus = false;
            prev = p[i].first;
        }
        if (p[i].second.second == 1) {
            plus = true;
            ans += (ll)p[i].first;
        }
        else if (p[i].second.second == -1) {
            if (plus) ans -= p[i].first;
            plus = false;
        }
    }*/
    printf("%lld\n", ans);
    return 0;
}
