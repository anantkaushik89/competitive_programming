#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const double pi = 3.1415926535897; 

int main() {
    int t; double n;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf\n", &n);
        if (n == 0 || n == 1) { printf("1\n"); continue; }
        ll ans = (ll)floor((log(2 * pi * n) / 2.0 + n * (log(n) - 1)) / log(10))+1;
        printf("%lld\n", ans);
    }
    return 0;
}
