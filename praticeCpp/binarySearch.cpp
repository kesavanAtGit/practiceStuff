#include <iostream>
#include <cassert>

// doing this iteratively

int binarySearchIteratively(const int* array, int target, int min, int max)
{
    // this makes sure that the array exists
    assert(array);

    while(!(min > max))
    {
        int midpoint{ (min + max) / 2 };
        int centerElement{array[midpoint]};

        if(centerElement > target)
            max = midpoint - 1;
        else if(centerElement < target)
            min = midpoint + 1;
        else if(centerElement == target)
            return midpoint;
    }
    return -1;
}

// doing this recursively
int binarySearchRecursively(const int* array, int target, int min, int max)
{
    // this makes sure that the array exists
    assert(array);

    // termination condition
    if( min > max)
        return -1;

    int midpoint{ (min + max) / 2 };
    int centerElement{array[midpoint]};

    if(centerElement > target)
        return binarySearchRecursively(array, target, min, max - 1);
    else if(centerElement < target)
        return binarySearchRecursively(array, target, min + 1, max);
    return midpoint;
}

int main(int argc, char* argv[])
{
    constexpr int array[]{3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
    constexpr int numTestValues{ 9 };
    constexpr int testValues[numTestValues]{0, 3, 12, 13, 22, 26, 43, 44, 49};
    int expectedValues[numTestValues]{-1, 0, 3, -1, -1, 8, -1, 13, -1};

    for(int count{0}; count < numTestValues; ++count)
    {
        std::cout << testValues[count] << " has returned " <<  binarySearchRecursively(array, testValues[count], 0, static_cast<int>(std::size(array) - 1));
        std::cout << "\n";
    }

    return 0;
}
