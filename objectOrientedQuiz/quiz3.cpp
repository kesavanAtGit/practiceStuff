#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <iterator>

class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_type
    };

    Monster() = default;

    Monster(Type type, const std::string& name, const std::string& roar, int hitPoints)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints} {}

    std::string getTypeString() const{
        switch(m_type)
        {
            case Type::dragon:   return "dragon"; break;
            case Type::goblin:   return "goblin"; break;
            case Type::ogre:     return "ogre"; break;
            case Type::orc:      return "orc"; break;
            case Type::skeleton: return "skeleton"; break;
            case Type::troll:    return "troll"; break;
            case Type::vampire:  return "vampire"; break;
            case Type::zombie:   return "zombie"; break;

            default:
                return "No such monster. Please try a valid monster type";
        }
    }

    void printMonster() {
        std::cout << m_name << ", the " << getTypeString() << " has " << m_hitPoints << " hitpoints and says " << m_roar << ".\n";
    }

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};
};

// create a random MonsterGenerator class
class MonsterGenerator
{
private:
    static constexpr double fraction{};

public:
    static int getRandomNumber(int min, int max) {
        static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }

    static Monster generateMonster() {
        static std::string s_nameArray[6] {"Luffy", "Zoro", "Sanji", "Kaido", "Doflamingo", "Sengoku"};
        static std::string s_roarArray[6] {"baka", "nani", "oi oi", "rarara", "hehehe", "ara ara"};
        return Monster(static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_type) - 1)),
                                        s_nameArray[getRandomNumber(0, 5)],
                                        s_roarArray[getRandomNumber(0,5)], getRandomNumber(1, 100));
    }
};

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();
    Monster m{MonsterGenerator::generateMonster()};
    m.printMonster();

    return 0;
}
