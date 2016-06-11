#include <cstdio>

using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n < 7) printf("-1\n");
        else {
            int m = 7;
            if (n > 7) m += (n - m) * 2;
            printf("%d\n", m);
            for (int i = 1; i <= 4; i++) 
                printf("%d %d\n", i, i + 1);
            printf("6 7\n2 6\n4 6\n");
            for (int i = 8; i <= n; i++) {
                printf("3 %d\n", i);
                printf("6 %d\n", i);
            }
            printf("3\n");
        }
    }
    return 0;
}
