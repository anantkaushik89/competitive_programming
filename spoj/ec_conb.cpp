#include <cstdio>

using namespace std;

int get_msb(int n) {
    int x = 30;
    for (int i = 1 << x; !(i & n); i = 1 << x) {
        x--;
    }
    return x;
}

int main() {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (!(x & 1)) {
            int m = get_msb(x);
            for (int i = 0; i <= m; i++) {
                x ^= (1 << i);
                //printf("i %d\n", i);
            }
        }
        printf("%d\n", x);
    }
    return 0;
}
