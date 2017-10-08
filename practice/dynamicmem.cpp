#include <iostream>

using namespace std;

int main(){
    int* bestArray = new int[10];
    int* shittyArray = new int[10];
    bestArray[4] = 12;
    shittyArray[4] = 69;
    cout << bestArray[4] << endl;
    delete[] bestArray;
    bestArray = shittyArray;
    cout << bestArray[4] << endl;
    return 0;
}