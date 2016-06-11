#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int t; ll n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        ll x = min(n, m);
        ll y = max(n, m);
        if (x == 1) {
            if (y == 2) printf("Yes\n");
            else printf("No\n");
        }
        else {
            if (x & 1 && y & 1) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
} 
