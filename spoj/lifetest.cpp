#include <cstdio>

using namespace std;

int main() {
    int t;
    bool f = false;
    while (scanf("%d", &t) != EOF) {
        if (t == 42)
            f = true;
        if (!f)
            printf("%d\n", t);
    }
    return 0;
}
