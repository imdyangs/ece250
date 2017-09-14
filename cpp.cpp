#include <iostream>
#include <string>

using namespace std;

int doubleNumber(int&);

int main ()
{
    int x = 12;
    doubleNumber(x);
    cout << x << "," << endl;
    return 0;
}

int doubleNumber(int& x) {
    return 2 * x;
}