
#include "Cookie.h"
#include <iostream>

using namespace std;

int main() {
    Cookie* cookie1 = new Cookie("blue");
    Cookie* cookie2 = new Cookie("green");

    cout << "C1: " << cookie1->getColor() << endl;
    cout << "C2: " << cookie2->getColor() << endl;
    
    return 0;
}