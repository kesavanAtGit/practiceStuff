#include <iostream>
#include <chrono>
#include <array>
#include <ctime>
#include <cstddef>
#include <numeric>
#include <utility>
#include <algorithm>

class calculate_time
{
private:
    // using type aliases
    using Clock = std::chrono::steady_clock;
    using duration = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<Clock> somePointInTime{ Clock::now() };

public:
    void reset() {
        somePointInTime = Clock::now();
    }

    double gimmeTime() {
        return std::chrono::duration_cast<duration>(Clock::now() - somePointInTime).count();
    }
};

const std::time_t totalArrayElements{10000};

void sortArray(std::array<int, totalArrayElements>& array)
{
    for(std::size_t startIndex{0}; startIndex < totalArrayElements - 1; ++startIndex)
    {
        std::size_t smallestIndex{0};
        for(std::size_t currentIndex{ startIndex + 1}; currentIndex < totalArrayElements; ++currentIndex)
        {
            if(array[currentIndex] < array[startIndex])
                smallestIndex =  currentIndex;
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

int main()
{
    std::array<int, totalArrayElements> array{};
    std::iota(array.rbegin(), array.rend(), 1);

    // instantiate a time object
    calculate_time T;

    std::ranges::sort(array);
    std::cout << T.gimmeTime() << " seconds ";
    return 0;
}
