#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    else return gcd(b, a % b);
}

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);
        int g = gcd(a, b);
        int m = max(a, b);
        if (m >= c && c % g == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
