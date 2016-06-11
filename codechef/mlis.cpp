    #include <cstdio>
    #include <cstdlib>
     
    int test, n;
     
    void work() {
        scanf("%d", &n);
        int need = 32;
        for (int i = 16; i >= 0; i--) {
            if (n & (1 << i)) {
                need = 49 - i;
            }
        }
        
        printf("%d\n", need);
        int cur = 1;
        for (int i = 16; i >= 0; i--) {
            if (n & (1 << i)) {
                while (cur <= 17 - i) {
                    printf("%d ", cur++);
                }
            }
            
            if (i > 0) {
                printf("%d %d ", need - (i - 1) * 2, need - (i - 1) * 2 - 1);
            }
        }
    }
     
    int main() {
        scanf("%d", &test);
        while (test--) {
            work();
        }
        
        return 0;
    }
     
