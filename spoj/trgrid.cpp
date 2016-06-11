#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (n == m) {
            if (n & 1) printf("R\n");
            else printf("L\n");
        }
        else {
            if (n > m) {
                if (m & 1) printf("D\n");
                else printf("U\n");
            }
            else {
                if (n & 1) printf("R\n");
                else printf("L\n");
            }
        }
    }
    return 0;
}
