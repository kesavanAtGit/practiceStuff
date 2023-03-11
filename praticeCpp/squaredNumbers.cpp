#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

// store the magic numbers in a namespace for simplified use
namespace Constants
{
    constexpr int minRandomNumber{2};
    constexpr int maxRandomNumber{4};
    constexpr int maximumDifference{4};
}

// going to use this often so a type alias
using gameArray = std::vector<int>;
using type = std::vector<int>::size_type;

// get the integers from the user assume they are valid
int getUserInput()
{
    int num{};
    std::cin >> num;
    return num;
}

int getRandomNumber()
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::uniform_int_distribution<> randomNumber(Constants::minRandomNumber, Constants::maxRandomNumber);
    return randomNumber(mt);
}

// generate the square numbers
gameArray resultArr(int& start, int& count, int& randomNumber)
{
    // set the array's size to count
    gameArray arr(count);

    // iterate through the array and get the squared numbers multiplied by the randomNumber
    int index{0};
    for(int i{start}; i < start + count; ++i)
    {
        arr[index] = (i*i) * randomNumber;
        ++index;
    }
    return arr;
}

bool checkGuessNumber(gameArray& arr, int& guess)
{
    auto found{std::find(arr.begin(), arr.end(), guess)};
    if(found == arr.end())
        return false;
    else
    {
        arr.erase(found);
        return true;
    }
}

// this should be called after printMeDaddy if checkGuessNumber returns true
void printSuccess(gameArray& arr, int& guess)
{
    if(arr.size() == 0)
        std::cout << "Nize! You found all the numbers, good job! \n";
    else
    {
        std::cout << "Nize! " << arr.size() << " number(s) left";
        std::cout << "\n";
    }
}

// find the closest number to the wrong value
auto findClosestNumber(gameArray& arr, int guess)
{
    return *std::min_element(arr.begin(), arr.end(), [=](int a, int b)
            {
            return (std::abs(a - guess) < std::abs(b - guess));
            });
}

void printFailure(gameArray& arr, int& guess)
{
    int closestValue{findClosestNumber(arr, guess)};

    if(std::abs(closestValue - guess) <= Constants::maximumDifference)
        std::cout << "Guess is wrong. Try " << closestValue << " next time.\n";
    else
        std::cout << guess << " is wrong \n";
}

// shit to display
void printMeDaddy(int& count, int& randomNumber)
{
    std::cout << "I generated " << count << " squared numbers. Do you know what each number is after multiplying it by " << randomNumber << "?\n";
}

bool playGame(gameArray& arr)
{
    std::cout << "> ";
    int guess{};
    std::cin >> guess;

    if(checkGuessNumber(arr, guess))
    {
        printSuccess(arr, guess);
        return !arr.empty();
    }
    else
    {
        printFailure(arr, guess);
        return false;
    }
}

int main()
{
    std::cout << "Start where? ";
    int start{getUserInput()};

    std::cout << "How many? ";
    int count{getUserInput()};

    // random number for the array and the text to display
    int randomNumber{getRandomNumber()};

    // create the array
    gameArray arr{resultArr(start, count, randomNumber)};
    printMeDaddy(count, randomNumber);

    // play the game
    while(playGame(arr));
    return 0;
}
