#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    int low = N * N;
    int high = (N + 1) * (N + 1);

    for (int C = low; C <= high; ++C) {
        unordered_map<int, int> square_mod;
        for (int A = low; A <= high; ++A) {
            int mod = (1LL * A * A) % C;
            square_mod[mod] = A;
        }

        for (int B = low; B <= high; ++B) {
            int mod_b = (1LL * B * B) % C;
            int target = (C - mod_b) % C;
            if (square_mod.count(target)) {
                int A = square_mod[target];
                if (A != B && A != C && B != C) {
                    cout << A << " " << B << " " << C << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No solution" << endl;
    return 0;
}
