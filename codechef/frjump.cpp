#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll sum  = 0, maxn = 100001;
    for (ll i = 2; i < maxn; i++) {
        sum += (maxn - 1) / i;
    }
    printf("%lld\n", sum);
    return 0;
}
