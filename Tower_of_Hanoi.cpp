#include <iostream>

using namespace std;

void hanoi(int number_of_ring, int peg_A, int peg_B, int peg_C) {
    if (number_of_ring > 0) {
        hanoi(number_of_ring - 1, peg_A, peg_C, peg_B);
        cout << "\n|    " << peg_A << " => " << peg_C << "    |";
        hanoi(number_of_ring - 1, peg_B, peg_A, peg_C);
    }
}

int main() {
    int A = 1, B = 2, C = 3, rings;

    cout << "Enter NUMBER OF RINGS to solve TOWER OF HANOI problems\n";
    cin >> rings;
    hanoi(rings, A, B, C);
    return 0;
}