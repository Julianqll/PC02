#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 7> array = {80,64,33,7,74,2,8};

    size_t last_swapped_idx = 0;
    for (size_t i = 0; i < array.size(); ++i) {
        if (array.at(i) % 2 == 0) {
            std::swap(array.at(i), array.at(last_swapped_idx));
            ++last_swapped_idx;
        }
    }

    std::sort(array.begin(), array.begin() + last_swapped_idx);

    std::sort(array.begin() + last_swapped_idx, array.end());

    for (int el : array)
        std::cout << el << std::endl;
}