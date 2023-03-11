#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <array>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cassert>

// a game where we fight monsters
// fucking pay attention to the access specifiers man
int getRandomNumber(int min, int max) {
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

class Creature {

    protected:
        std::string m_name{};
        char m_symbol{};
        int m_healthAmount{};
        int m_damagePerAttack{};
        int m_amountOfGold{};

    public:
        Creature(std::string name, char symbol, int healthAmount, int damagePerAttack, int amountOfGold)
            :m_name{name},
            m_symbol{symbol},
            m_healthAmount{healthAmount},
            m_damagePerAttack{damagePerAttack},
            m_amountOfGold{amountOfGold} {}

        // write some getters and setters
        const std::string& getName()const {
            return m_name;
        }

        char getSymbol() const{
            return m_symbol;
        }

        int getHealth() const{
            return m_healthAmount;
        }

        int getDamage() const{
            return m_damagePerAttack;
        }

        int getGold() const{
            return m_amountOfGold;
        }

        void reduceHealth(int damage) {
            m_healthAmount -= damage;
        }

        bool isDead() {
            return ( m_healthAmount <= 0);
        }

        void addGold(int gold) {
            m_amountOfGold += gold;
        }

        friend std::ostream& operator<< (std::ostream& out, const Creature& creature) {
            out << creature.m_name << " " << creature.m_symbol << " " << creature.m_healthAmount << " "
                << creature.m_damagePerAttack << " " << creature.m_amountOfGold;
            return out;
        }
};

class Potion {

    public:
        enum PotionType {
            health,
            strength,
            poison,
            max_type
        };

        enum PotionSize {
            small,
            medium,
            large,
            max_size
        };

        Potion(PotionType type, PotionSize size)
            :m_type{type}, m_size{size} {}

        PotionType getType() {return m_type;}
        PotionSize getSize() {return m_size;}

        static std::string_view getPotionName(PotionType type) {
            static constexpr std::array  potionNames {
                "health",
                "strength",
                "poison"
            };
            return potionNames.at(static_cast<std::size_t>(type));
        }

        static std::string_view getPotionSize(PotionSize size) {
            static constexpr std::array potionSizes {
                "small",
                "medium",
                "large"
            };
            return potionSizes.at(static_cast<std::size_t>(size));
        }

        std::string getName() {
            std::stringstream endResult{};
            endResult << getPotionSize(getSize()) << " potion of " << getPotionName(getType());
            return endResult.str();
        }

        static Potion getRandomPotion() {
            return {
                static_cast<PotionType>(getRandomNumber(0, static_cast<int>(PotionType::max_type) - 1)),
                static_cast<PotionSize>(getRandomNumber(0, static_cast<int>(PotionSize::max_size) - 1))
            };
        }

        private:
           PotionType m_type{};
           PotionSize m_size{};
};

class Player;
class Monster : public Creature{

    public:
        enum class Type{
            dragon,
            orc,
            slime,
            max_types,
        };

        Monster(Type type)
            : Creature{getDefaultCreature(type)} {}

        static Monster getRandomMonster() {
            int randomNumber{getRandomNumber(0, static_cast<int>(Monster::Type::max_types) - 1)};
            return Monster{static_cast<Type>(randomNumber)};
        }

        void attackPlayer(Player& player);

    private:
        static const Creature& getDefaultCreature(Type type) {
            static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData {
                { {"dragon", 'd', 20, 4, 100},
                    {"orc", 'o', 4, 2, 25},
                    {"slime", 's', 1, 1, 10}  }
            };
            return monsterData.at(static_cast<std::size_t>(type));
        }
};

class Player : public Creature {

    private:
        int m_playerLevel{1};

    public:
        Player(std::string name)
            :Creature{name, '@', 10, 1, 0}{}

        void levelUp() {
            ++m_playerLevel;
            ++m_damagePerAttack;
        }

        int getLevel() {
            return m_playerLevel;
        }

        bool hasWon() {
            return (m_playerLevel >= 20);
        }

        void fightMonster() {

            Monster monster{Monster::getRandomMonster()};
            std::cout << "You have encountered a " << monster.getName() << ". \n";

            while(!isDead() && !monster.isDead()) {
                std::cout << "(R)un or (F)ight: ";
                char ch{};
                std::cin >> ch;

                if(ch == 'R' || ch == 'r') {
                    if(getRandomNumber(1, 2) == 1) {
                        std::cout << "You fled successfully \n";
                        return;
                    }
                    // the monster gets a free attack
                    else
                        monster.attackPlayer(*this);
                }

                if(ch == 'F' || ch == 'f')
                    attackMonster(monster);
            }
        }

        void attackMonster(Monster& monster) {

            if(isDead())
                return;

            monster.reduceHealth(getDamage());
            std::cout << "You hit the " << monster.getName() << " for " << getDamage() << " damage \n";

            if(monster.isDead()) {

                std::cout << "You killed the " << monster.getName() << '\n';
                levelUp();
                addGold(monster.getGold());
                std::cout << "You are now level " << getLevel() << '\n';
                std::cout << "You found " << monster.getGold() << " gold \n";

                // 30% chance of getting a potion
                if(getRandomNumber(1, 100) <= 30) {
                    std::cout << "You found a mythical potion! Do you want to drink it [y/n]?: ";
                    char ch{};
                    std::cin >> ch;

                    if(ch == 'y' || ch == 'Y') {
                        Potion potion{Potion::getRandomPotion()};
                        drinkPotion(potion);
                        std::cout << "You drank a " << potion.getName() << '\n';
                    }
                    else
                        return;
                }
            }

            // the monster attacks the player back if it's still alive
            else {
                reduceHealth(monster.getDamage());
                std::cout << "The " <<  monster.getName() << " hit you for " << monster.getDamage() << " damage. \n";
            }
        }

        void drinkPotion(Potion& potion) {

            switch(potion.getType()) {
                case Potion::health:
                    m_healthAmount += ((potion.getSize() == Potion::large) ? 5:2);
                    break;

                case Potion::strength:
                    ++m_damagePerAttack;
                    break;

                case Potion::poison:
                    reduceHealth(1);
                    break;

                case Potion::max_type:
                    break;
            }
        }
};

void Monster::attackPlayer(Player& player) {

    if(isDead())
        return;

    std::cout << "You failed to flee \n";
    player.reduceHealth(getDamage());
    std::cout << "The " << getName() << " hit you for " << getDamage() << " damage. \n";
}

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    std::cout << "Enter your name: ";
    std::string name{};
    std::cin >> name;
    std::cout << "Welcome, " << name << '\n';

    Player player{name};

    while(!player.isDead() && !player.hasWon()) {
        player.fightMonster();
    }

    if(player.isDead()) {
        std::cout << "You died at level " << player.getLevel() << " with " << player.getGold() << " gold \n";
        std::cout << "Too bad you can't take it with you \n";
    }
    else
        std::cout << "You have won with " << player.getGold() << " gold \n";

    return 0;
}
