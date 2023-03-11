#include <iostream>
#include <cassert>
#include <array>
#include <ctime>
#include <random>
#include <iterator>
#include <algorithm>

class Player;
class Card
{
public:
enum Suit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum Rank
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

public:
    Card() = default;

    Card(Rank rank, Suit suit): m_rank{rank}, m_suit{suit} {}

    void printCard(const Rank& rank, const Suit& suit) const{
        switch (rank)
        {
            case Rank::rank_2:      std::cout << '2';   break;
            case Rank::rank_3:      std::cout << '3';   break;
            case Rank::rank_4:      std::cout << '4';   break;
            case Rank::rank_5:      std::cout << '5';   break;
            case Rank::rank_6:      std::cout << '6';   break;
            case Rank::rank_7:      std::cout << '7';   break;
            case Rank::rank_8:      std::cout << '8';   break;
            case Rank::rank_9:      std::cout << '9';   break;
            case Rank::rank_10:     std::cout <<  "10";   break;
            case Rank::rank_jack:   std::cout << 'J';   break;
            case Rank::rank_queen:  std::cout << 'Q';   break;
            case Rank::rank_king:   std::cout << 'K';   break;
            case Rank::rank_ace:    std::cout << 'A';   break;
            default:
                std::cout << '?';
                break;
        }

        switch (suit)
        {
            case Suit::club:       std::cout << 'C';   break;
            case Suit::diamond:    std::cout << 'D';   break;
            case Suit::heart:      std::cout << 'H';   break;
            case Suit::spade:      std::cout << 'S';   break;
            default:
                std::cout << '?';
                break;
        }
    }

    int getCardValue(const Rank& rank) const{
        switch (rank)
        {
            case Rank::rank_2:        return 2;
            case Rank::rank_3:        return 3;
            case Rank::rank_4:        return 4;
            case Rank::rank_5:        return 5;
            case Rank::rank_6:        return 6;
            case Rank::rank_7:        return 7;
            case Rank::rank_8:        return 8;
            case Rank::rank_9:        return 9;
            case Rank::rank_10:       return 10;
            case Rank::rank_jack:     return 10;
            case Rank::rank_queen:    return 10;
            case Rank::rank_king:     return 10;
            case Rank::rank_ace:      return 11;
            default:
                assert(false && "should never happen");
                return 0;
        }
    }

    void print() const{
        printCard(m_rank, m_suit);
    }

    int value() const{
        return getCardValue(m_rank);
    }
    friend class playBlackJack;

private:
    Rank m_rank{};
    Suit m_suit{};
};

class Deck
{
private:
    using deck  = std::array<Card, 52>;
    using card  = deck::size_type;

    deck m_deck{};
    card m_card{};
    card m_cardIndex{};

public:
    Deck()
    {
        // this call the constructor of the class Card
        for (int suit{0}; suit < static_cast<int>(Card::max_suits); ++suit) {
            for (int rank{0}; rank < static_cast<int>(Card::max_ranks); ++rank) {
                m_deck[m_card] = {static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)};
                ++m_card;
            }
        }
    }

    const Card& dealCard() {
        return m_deck[m_cardIndex++];
    }

    void print() {
        for(auto& card: m_deck) {
            card.print();
            std::cout << " ";
        }
        std::cout << "\n";
    }

    void shuffle() {
        m_cardIndex = 0;
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        std::shuffle(m_deck.begin(), m_deck.end(), mt);
    }
    friend class Player;
    friend class playGame;
    friend class playBlackJack;

    friend bool playerTurn(Deck& deck, Player& player);
    friend bool dealerTurn(Deck& deck, Player& player);
};

int g_maximumScore{21};
class Player
{
private:
    int m_score;

public:
    bool isBust() {
        return ( m_score > g_maximumScore );
    }

    int drawCard(Deck& deck) {
        return deck.dealCard().value();
    }

    int score() {
        return m_score;
    }

    friend class playGame;
    friend class playBlackJack;

    // this is to access the members of this class
    friend bool playerTurn(Deck& deck, Player& player);
    friend bool dealerTurn(Deck& deck, Player& player);
};

bool playerWantsHit() {
    while(true)
    {
        std::cout << "Would you like to hit(h) or stand(s) ?: ";
        char ch{};
        std::cin >> ch;

        switch(ch) {
            case 'h': return true;
            case 's': return false;
        }
    }
}

bool playerTurn(Deck& deck, Player& player) {
    while(true)
    {
        if(player.isBust()) {
            std::cout << "You busted! \n";
            return true;
        }

        if(playerWantsHit()) {

            int playerCard{player.drawCard(deck)};
            player.m_score += playerCard;

            std::cout << "The player was dealt with "
                      << playerCard
                      << " and the score is "
                      << player.score() << ".\n";
        }
        else
            return false;
    }
}

int g_minDealerScore{17};

bool dealerTurn(Deck& deck, Player& dealer) {
    while(dealer.score() < g_minDealerScore) {

        int dealerCard{dealer.drawCard(deck)};
        dealer.m_score += dealerCard;

        std::cout << "The dealer was dealt with "
                  << dealerCard
                  << " and the score is "
                  << dealer.score() << ".\n";
    }

    if(dealer.isBust()) {
        std::cout << "The dealer busted. \n";
        return true;
    }
    return false;
}


class playBlackJack
{
public:
    bool playGame(Deck& deck, Player& player, Player& dealer) {
        player.m_score += deck.dealCard().value();
        dealer.m_score += deck.dealCard().value();

        std::cout << "The player's first card is " << player.score() << "\n";
        std::cout << "The dealer's first card is " << dealer.score() << "\n";

        // this is to check if the player busted
        if(playerTurn(deck, player))
            return false;

        // checking if the dealer went bust
        if(dealerTurn(deck, dealer))
            return true;

        return (player.score() > dealer.score());
    }

    bool isTie(Player& player, Player& dealer) {
        return (player.score() == dealer.score());
    }
};

int main()
{
    Deck deck{};
    deck.shuffle();

    Player player{};
    Player dealer{};

    playBlackJack playGame{};

    if(playGame.playGame(deck, player, dealer))
        std::cout << "You won!. \n";
    else if(playGame.isTie(player, dealer))
        std::cout << "It's a tiedaddy!. \n";
    else
        std::cout << "The dealer has won the game. \n";

    return 0;
}
