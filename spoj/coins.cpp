#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<int, ll> m;

ll value(int n) {
    if (!n) return 0;
    else if (n == 1) return 1;
    else if (m.find(n) != m.end())
        return m.find(n)->second;
    else {
        ll t = value(n / 2) + value(n / 3) + value (n / 4);
        t  = max(t, (ll)n);
        m[n] = t;
        return t;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        m.clear();
        printf("%lld\n", value(n));
    }
    return 0;
}
