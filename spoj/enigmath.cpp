#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    else return gcd(b, a % b);
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        int mx = max(a, b), mn = min(a, b);
        int g = gcd(mx, mn);
        printf("%d %d\n", b / g, a / g);
    }
    return 0;
}
