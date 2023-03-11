#include <iostream>
#include <bitset>
#include <cstdint>

void someFunction(std::bitset<32> options) {
    std::cout << options << "\n";
}

int main()
{
    // this is bit manipulation using bitset and its functions
    // but what if we want to do this for multiple bits use (bit masks)

    std::bitset<4> name{0b1010};
    //std::cout << name.set(2) << "\n";
    //std::cout << name.any() << "\n";
    //std::cout << name.set(2) << "\n";
    //std::cout << name.flip(3) << "\n";

    // bit mask is a pre-defined set of bits to manipulate some other bits
    // let's define a bit mask

    [[maybe_unused]] constexpr std::uint16_t mask0{0b00000001};
    [[maybe_unused]] constexpr std::uint16_t mask1{0b00000010};
    [[maybe_unused]] constexpr std::uint16_t mask2{0b00000100};
    [[maybe_unused]] constexpr std::uint16_t mask3{0b00001000};
    [[maybe_unused]] constexpr std::uint16_t mask4{0b00010000};
    [[maybe_unused]] constexpr std::uint16_t mask5{0b00100000};
    [[maybe_unused]] constexpr std::uint16_t mask6{0b01000000};
    [[maybe_unused]] constexpr std::uint16_t mask7{0b10000000};

    // can test using & operator
    // can turn on a bit using | operator
    std::uint16_t comparingValue{0b01000000};

    std::cout << "Bit 6 is " << ((comparingValue & mask6)? "on \n": "off \n");
    std::cout << "Bit 0 is " << ((comparingValue & mask0)? "on \n": "off \n");

    // use |= to turn on
    comparingValue |= (mask4 | mask5);
    std::cout << std::bitset<8>{comparingValue} << "\n";

    // use &= to turn off
    comparingValue &= ~(mask4 | mask5);
    std::cout << std::bitset<8>{comparingValue} << "\n";

    // use ^= to flip multiple bits
    comparingValue ^= (mask4 | mask5);
    std::cout << std::bitset<8>{comparingValue} << "\n";

    return 0;
}
