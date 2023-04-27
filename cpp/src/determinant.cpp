#include <assert.h>
#include <thread>
#include <vector>

#include "err.h"
#include "determinant.h"

double findDet(std::vector<std::vector<double>> &A) {
	auto start = std::chrono::high_resolution_clock::now();

    if (A.size() != A[0].size())
		errx(1, "Matrix is not square.");

    double tol = 1e-9;
    int N = A.size();

    std::vector<double> P(N+1, 0);    

    for (int i = 0; i <= N; i++) {
        P[i] = i; // Initialize permutation vector
    }

    for (int i = 0; i < N; i++) {
        double maxA = 0.0;
        int maxRow = i;

        // Find the maximum element in the current column
        for (int k = i; k < N; k++) {
            if (std::abs(A[k][i]) > maxA) {
                maxA = std::abs(A[k][i]);
                maxRow = k;
            }
        }

        // Check for singularity
        if (maxA < tol) {
            return 0; // Matrix is singular
        }

        // Swap rows
        if (maxRow != i) {
            std::swap(P[i], P[maxRow]);
            for (int k = 0; k < N; k++) {
                std::swap(A[i][k], A[maxRow][k]);
            }
        }

        // Perform Gaussian elimination
        for (int k = i + 1; k < N; k++) {
            A[k][i] /= A[i][i];
            for (int j = i + 1; j < N; j++) {
                A[k][j] -= A[k][i] * A[i][j];
            }
        }
    }

    // Calculate the determinant
    double det = 1.0;
    for (int i = 0; i < N; i++) {
        det *= A[i][i];
    }

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	printf("C++ Determinant: %lld microsecs", duration.count());

    return det;
}
