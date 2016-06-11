#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100010;
int inp[maxn];
bool b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf("%d", inp + i);
    for (int i = 1; i <= n; i++) {
        if (inp[i]) b[inp[i]] = true;
        else b[i] = true;
    }
    bool f = false;
    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            if (f) printf(" ");
            f = true;
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}
