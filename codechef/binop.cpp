#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxl = 1000010;
char s1[maxl], s2[maxl];

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%s\n", s1);
        scanf("%s\n", s2);
        int d = 0, d1 = 0, d0 = 0, n0 = 0;
        int l = strlen(s1);
        for (int i = 0; i < l; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == '1') d1++;
                else d0++;
                d++;
            }
            if (s1[i] == '1') n0++;
        }
        if (n0 == l || n0 == 0) {
            printf("Unlucky Chef\n");
            continue;
        }
        int ways = min(d1, d0);
        int diff = d - 2 * ways;
        printf("Lucky Chef\n%d\n", ways + diff);
    }
    return 0;
}
