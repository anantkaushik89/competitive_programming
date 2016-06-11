#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
char even[] = "WAAMW";
char odd[] = "WMAAW";
string s;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 1) printf("poor conductor\n");
        else {
            n -= 2;
            int q = n / 5;
            int r = n % 5;
            if (q & 1) {
                if (r < 3) s = "R";
                else s = "L";
                printf("%d %c %s\n", q + 1, odd[r], s.c_str());
            }
            else {
                if (r < 2) s = "L";
                else s = "R";
                printf("%d %c %s\n", q + 1, even[r], s.c_str());
            }
        }
    }
    return 0;
}
