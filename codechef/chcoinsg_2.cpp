#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
const ll maxn = 1000000001;
const int maxp = 10010;
bool b[100010];
ll p[maxp];
int pk = 0;

void sieve() {
    ll lm = sqrt(maxn) + 1;
    for (ll i = 2; i <= lm; i++) {
        if (!b[(int)i]) {
            p[pk++] = i;
            for (ll j = i * i; j <= lm; j += i)
                b[int(j)] = 1;
        }
    }
}

bool solve(ll k) {
    ll lm = sqrt(maxn) + 1;
    if (k < lm) {
        if (!b[k]) return true;
    }
    ll orig = k;
    bool first = false;
    for (int i = 0; i < pk && p[i] * p[i] < k; i++) {
        if (k % p[i] == 0) {
            first = true;
            while (k % p[i] == 0) 
                k /= p[i];
            break;
        }
    }
    if (k == 1) return true;
    else if (k == orig) return true;
    else return false;
}

int main() {
    sieve();
    int t; ll n;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld")
    }
    return 0;
}
