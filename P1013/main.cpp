#include <iostream>
#include <string>

using namespace std;

int main() {

    int i, n;
    string st;

    cin >> st;
    while (st != "0") {
        n = 0;
        for (i = 0; i < st.size(); ++i) {
            n = (n + st[i] - '0') % 9;
        }
        if (n % 9) {
            cout << n % 9 << endl;
        } else {
            cout << 9 << endl;
        }
        cin >> st;
    }
    return 0;
}