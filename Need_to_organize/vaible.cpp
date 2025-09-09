#include <iostream>
#include <vector>
using namespace std;

int findSmallestViableElement(const vector<int>& A) {
    int viable = -1; // Step 5: Initialize with -1 (no viable element yet)

    for (int i = 0; i < A.size(); ++i) {
        int element = A[i];

        // Step 2: Check if divisible by both 4 and 6
        if (element % 4 == 0 && element % 6 == 0) {
            // Step 3 & 4: Store or update if smaller than previous viable
            if (viable == -1 || element < viable) {
                viable = element;
            }
        }
    }

    return viable; // Step 5: Return final result
}

int main() {
    vector<int> A = {3, 24, 42, 6, 9};
    int result = findSmallestViableElement(A);
    cout << result << endl;
    return 0;
}
