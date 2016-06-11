#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 1 << 25;
const ll limn = 1LL << 50;
//const ll maxn = 32;
//const ll limn = 1000;
bool b[(int)maxn];
vector<ll> v;

void init() {
    for (int i = 2; i < maxn; i++) {
        if (b[i] == 0) {
            v.push_back(ll(i));
            for (ll j = (ll)i * (ll)i; j < maxn; j += (ll)i)
                b[j] = 1;
        }
    }
}

ll sq_free(int i, ll q, int r) {
    ll x = 0;
    r = r * (-1);
    for (int j = i; j < v.size() && v[j] <= maxn / q; j++) {
        ll pp = q * v[j];
        x = x + r * (limn - 1) / (pp * pp);
        x += sq_free(j + 1, pp, r);
    }
    return x;
}

int main() {
    init();
    cout << limn << endl;;
    ll x = sq_free(0, 1, -1);
    cout << x << endl;
    cout << limn - 1 - x << endl;
    return 0;
}
