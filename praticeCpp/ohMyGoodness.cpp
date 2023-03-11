#include <iostream>
#include <string>
#include <array>
#include <assert.h>
#include <iterator>
#include <algorithm>
#include <random>
#include <ctime>

// create 2enums for the ranks and the suits
enum class CardsRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

enum class CardSuits
{
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits
};

// a card should have a rank and a suit
struct Card
{
    CardsRank rank{};
    CardSuits suit{};
};

void printCard(const Card& card)
{
    switch(static_cast<int>(card.rank))
    {
        case 0: std::cout << 2; break;
        case 1: std::cout << 3; break;
        case 2: std::cout << 4; break;
        case 3: std::cout << 5; break;
        case 4: std::cout << 6; break;
        case 5: std::cout << 7; break;
        case 6: std::cout << 8; break;
        case 7: std::cout << 9; break;
        case 8: std::cout << 10; break;
        case 9: std::cout << "J"; break;
        case 10: std::cout << 'Q'; break;
        case 11: std::cout << 'K'; break;
        case 12: std::cout << 'A'; break;
        default:
                 std::cout << "Unknown rank babby";
                 break;
    }

    switch(card.suit)
    {
        case CardSuits::clubs: std::cout << 'C'; break;
        case CardSuits::diamonds: std::cout << 'D'; break;
        case CardSuits::hearts: std::cout << 'H'; break;
        case CardSuits::spades: std::cout << 'S'; break;
        default:
                std::cout << "Unknown suit";
                break;
    }
}

// create a deck of 52cards
auto createDeck()
{
    using Deck = std::array<Card, 52>;
    using Index = Deck::size_type;
    Deck cardsArray{};
    Index arrIndex{0};

    for(int index{static_cast<int>(CardSuits::clubs)}; index < static_cast<int>(CardSuits::max_suits); ++index)
    {
        for(int i{static_cast<int>(CardsRank::rank_2)}; i < static_cast<int>(CardsRank::max_ranks); ++i)
        {
            cardsArray[arrIndex].rank = static_cast<CardsRank>(i);
            cardsArray[arrIndex].suit= static_cast<CardSuits>(index);
            ++arrIndex;
        }
    }

    return cardsArray;
}

using Deck = std::array<Card, 52>;
void printDeck(const Deck arr)
{
    for(auto& var: arr)
    {
        printCard(var);
        std::cout << " ";
    }
}

void shuffleDeck(Deck arr)
{
    std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(arr.begin(), arr.end(), mt);

    printDeck(arr);
}

int getCardValue(const Card& card)
{
    switch(card.rank)
    {
        case CardsRank::rank_2: return 2; break;
        case CardsRank::rank_3: return 3; break;
        case CardsRank::rank_4: return 4; break;
        case CardsRank::rank_5: return 5; break;
        case CardsRank::rank_6: return 6; break;
        case CardsRank::rank_7: return 7; break;
        case CardsRank::rank_8: return 8; break;
        case CardsRank::rank_9: return 9; break;
        case CardsRank::rank_10:
        case CardsRank::rank_jack:
        case CardsRank::rank_queen:
        case CardsRank::rank_king:
                                return 10; break;
        case CardsRank::rank_ace: return 11; break;
        default:
            assert(false && "should never happen");
            return 0;
    }
}

int main()
{
    const Deck arr{createDeck()};
    printDeck(arr);
    std::cout << "\n";

    //shuffleDeck(arr);
    const Card card{arr[52]};
    std::cout << getCardValue(card);

    return 0;
}

