#include "perfect_numbers.h"

#include <algorithm>
#include <cmath>

namespace perfect_numbers {
namespace {

auto aliquot_sum(int n) {
    if (n <= 0) {
        throw std::domain_error{"n must be positive"};
    }
    auto sum = 1;
    auto const root = static_cast<int>(std::sqrt(n));

    for (auto i = 2; i <= root; ++i) {
        // Since we already perform the % operation,
        // we might as well perform the / operation
        // for free (most machines can do both at once).
        if (n % i == 0) {
            sum += (n / i) + i;
        }
    }

    // Remove the duplicate final factor if n is a perfect square.
    sum -= (n == root * root) * root;
    return sum;
}

} // namespace

auto classify(int n) -> classification {
    auto const sum  = aliquot_sum(n);
    auto const sign = (sum > n) - (sum < n); // -1, 0, or +1
    return static_cast<classification>(sign);
}

} // namespace perfect_numbers

