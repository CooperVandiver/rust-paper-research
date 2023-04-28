#include <thread>
#include <vector>

#include "err.h"
#include "main.h"
#include "mat_mul.h"

std::vector<std::vector<int>> mat_mul(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B)
{
	if (A[0].size() != B.size())
		errx(1, "Matrices are not conformable.");

	std::vector<std::vector<int>> res;
	res.reserve(A.size());
	std::vector<int> temp;
	temp.reserve(B[0].size());
	int intermediateValue;

	for(size_t i = 0; i < A.size(); ++i) {
		temp.clear();

		for (size_t j = 0; j < B[0].size(); ++j) {
			intermediateValue = 0;

			for (size_t k = 0; k < B.size(); ++k) {
				intermediateValue += A[i][k] * B[k][j];
			}
			
			temp.push_back(intermediateValue);
		}

		res.push_back(temp);
	}
	return res;
}

std::vector<std::vector<int>> mat_mul_thread(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B)
{
	if (A[0].size() != B.size())
		errx(1, "Matrices are not conformable.");

	std::vector<std::vector<int>> res;
	res.reserve(A.size());
	std::vector<std::thread> handles;
	std::atomic<int> threadCount;
	
	for (size_t i = 0; i < A.size(); ++i) {
		while (threadCount >= MAX_THREAD)
			;

		std::vector<int> temp;
		temp.reserve(B[0].size());
		res.push_back(temp);
		handles.push_back(std::thread([&](int ni, std::vector<int> *v) {
			++threadCount;
			int inter_val;
			for (size_t j = 0; j < B[0].size(); ++j) {
				inter_val = 0;

				for (size_t k = 0; k < B.size(); ++k) {
					inter_val += A[ni][k] * B[k][j];
				}
				v->push_back(inter_val);
			}
			--threadCount;
		}, i, &res.back()));
	}

	for (auto &h : handles)
		h.join();

	return res;
}
