#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

#include "determinant.h"
#include "err.h"
#include "main.h"
#include "mat_mul.h"

int main()
{
	srand(time(NULL));

	/*auto printMat = [](const auto &v) {
		for (const auto &a : v) {
			for (const auto &i : a) {
				std::cout<<i<<'\t';
			}
			std::cout<<'\n';
		}
	};*/

	std::vector<std::vector<double>> A, B;
	A.reserve(M);
	B.reserve(N);
	std::vector<double> temp;
	for (size_t i = 0; i < M; ++i) {
		temp.clear();
		for (size_t j = 0; j < N; ++j) {
			temp.push_back(rand() % 10);
		}
		A.push_back(temp);
	}

	for (size_t i = 0; i < N; ++i) {
		temp.clear();
		for (size_t j = 0; j < P; ++j) {
			temp.push_back(rand() % 10);
		}
		B.push_back(temp);
	}
	auto C = mat_mul_thread(A, B);


	std::vector<std::vector<double>> mat {
		{1,2,3},
		{2,5,0},
		{0,0,1}
	};

	printf("\nDeterminant: %f\n", findDet(mat));

	return 0;
}
