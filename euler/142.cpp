#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<int, int> m;
const int maxn = 1000;

int main() {
    for (int i = 1; i < maxn; i++) {
        for (int j = i + 1; j < maxn; j++) {
            int k = i * i + j * j;
            if (m.find(k) == m.end())
                m[k] = 0;
            if (k == 25) printf("%d %d\n", i, j);
            m[k]++;
        }
    }
    printf("done\n");
    map<int, int>::const_iterator mitr, me = m.end();
    for (mitr = m.begin(); mitr != me; mitr++) {
        if (mitr->second > 1) printf("%d\n", mitr->first);
    }
    return 0;
}
