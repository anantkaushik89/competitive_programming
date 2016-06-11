#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 2010;
char s[maxn];

int main() {
    int t = 1;
    while (scanf("%s\n", s) && s[0] != '-') {
        int n = 0, ans = 0;
        int l = strlen(s);
        for (int i = 0; i < l; i++) {
            if (s[i] == '}') n--;
            else n++;
            if (n < 0) {ans++; n = 1;}
        }
        if (n)
            ans += n - 1;
        printf("%d. %d\n", t++, ans);
    }
    return 0;
}
