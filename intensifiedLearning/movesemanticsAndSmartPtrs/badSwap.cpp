#include <iostream>
#include <string>
#include <type_traits>

// the right way to swap the movable object using move constructor and move assignment operator
class Game {
private:
    std::string m_game{};

public:
    Game(std::string game)
        :m_game{game} {}

    Game(const Game& game) = default;
    Game& operator=(const Game& game) = default;

    friend void swap(Game& game, Game& anotherGame) {
        std::swap(game.m_game, anotherGame.m_game);
    }

    Game(Game&& game) noexcept = delete;
    //    std::cout << "swap move constructor \n";
    //    swap(*this, game);
    //}

    Game& operator=(Game&& game) noexcept = delete;
    //    std::cout << "swap move assignment\n";
    //    swap(*this, game);
    //    return *this;
    //}

    const std::string& getGameName() const {
        return m_game;
    }

};

int main() {
    Game game{"cricket"};
    //game = Game{"football"};

    std::cout << game.getGameName();
    return 0;
}
