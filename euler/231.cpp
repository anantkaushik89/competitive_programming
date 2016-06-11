#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
const ll maxn = 20000001;
const ll maxp = 5000001;
//const ll maxn = 11;
//const ll maxp = 4;
bool b[maxn];
int num[maxn];
int den[maxn];

int logn(ll n, ll p) {
    int e = 0;
    while (n && n % p == 0) {
        e++;
        n /= p;
    }
    return e;
}

void init() {
    int p = 0;
    for (int i = 2; i < maxn; i++) {
        if (b[i] == 0) {
            p++;
            ll t = i;
            if (i < maxp) den[t]++;
            else if (i > (maxn - maxp)) num[t]++;
            for (ll j = t * 2; j < maxn; j += t) {
                b[j] = 1;
                int n = logn(j, t);
                if (j < maxp) den[t] += n;
                else if (j > (maxn - maxp)) num[t] += n;
            }
        }
    }
    printf("%d\n", p);
}

int main() {
    init();
    ll sum = 0;
    for (int i = 2; i < maxn; i++) {
        if (b[i] == 0) {
            assert(num[i] >= den[i]);
            sum += (num[i] - den[i]) * (ll)i;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
