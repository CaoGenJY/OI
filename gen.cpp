#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int r = rand() % 21 - 10; // r ∈ [-10, 10]
    int d = rand() % 201 - 100; // d ∈ [-100, 100]
    while (r == 0) r = rand() % 21 - 10; // 避免 r = 0

    int b1 = rand() % 200001 - 100000;
    int b2 = r * b1 + d;
    int b3 = r * b2 + d;
    int b4 = r * b3 + d;

    // 确保三项不相等
    if (b1 != b2 && b2 != b3) {
        cout << b1 << " " << b2 << " " << b3 << "\n";
        // cout << b4 << "\n";
    } 
    return 0;
}
