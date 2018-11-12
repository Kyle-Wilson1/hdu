#include <iostream>
#include<iomanip>

using namespace std;

double factorial(double n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

double calc(int n) {

    double ret = 0;
    for (int i = 0; i <= n; ++i) {
        ret += 1 / factorial(i);
    }
    return ret;
}

int main() {

    cout << "n e" << endl;
    cout << "- -----------" << endl;
    for (int i = 0; i < 10; ++i)
        if (i < 3) {
            printf("%d %g\n", i, calc(i));
        } else {
            printf("%d %.9lf\n", i, calc(i));
        }

    return 0;
}