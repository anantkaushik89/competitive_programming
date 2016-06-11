#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int t;
    double a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf%lf", &a, &b, &c);
        double p = (a + b + c)/ 2;
        double ans1 = 3 * sqrt(p * (p - a) * (p - b) * (p - c));
        double ans2 = sqrt(3) * (a * a + b * b + c * c) / 4;
        double ans = (ans1 + ans2) / 2;
        printf("%.2lf\n", ans);
    }
    return 0;
}
