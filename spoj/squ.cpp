#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cout << "1" << endl;;
    int lim = 100;
    cout << lim << endl;
    for (int i = 0; i < lim; i++) {
        int t = rand() % 1001;
        cout << t << " ";
    }
    cout << endl;
    return 0;
}
