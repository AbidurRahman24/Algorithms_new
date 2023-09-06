#include <iostream>
using namespace std;

bool canReachTarget(int n, int X, int A[], int cs, int ci) {
    // Base case: If we have processed all elements in the array
    // and the current sum equals the target X, return true.
    if (ci == n) {
        return cs == X;
    }

    // Try adding the current element to the current sum and check if we can reach the target.
    if (canReachTarget(n, X, A, cs + A[ci], ci + 1)) {
        return true;
    }

    // Try subtracting the current element from the current sum and check if we can reach the target.
    if (canReachTarget(n, X, A, cs - A[ci], ci + 1)) {
        return true;
    }

    // If neither addition nor subtraction leads to the target, return false.
    return false;
}

int main() {
    int N, X;
    cin >> N >> X;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Check if it's possible to create an expression equal to X.
    if (canReachTarget(N, X, A, 0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
