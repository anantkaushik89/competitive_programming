#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxl = 10010;
char s[maxl];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)             
            s[i] = 'a' + i % 26;
        s[n] = 0;
        printf("%s\n", s);
    }
    return 0;
}
