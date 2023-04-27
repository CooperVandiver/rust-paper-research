#pragma once
#include <vector>

std::vector<std::vector<int>> mat_mul(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&);

std::vector<std::vector<int>> mat_mul_thread(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&);