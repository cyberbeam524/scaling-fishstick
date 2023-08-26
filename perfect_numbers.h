#pragma once
namespace perfect_numbers {
enum classification : int {
    deficient = -1,
    perfect   = 0,
    abundant  = +1,
};
auto classify(int n) -> classification;
} // namespace perfect_numbers