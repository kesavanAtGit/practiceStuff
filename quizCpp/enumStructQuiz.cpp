#include <iostream>
#include <string>

// Defining our monster types
enum class MonsterType
{
  ogre,
  dragon,
  orc,
  giant_spider,
  slime,
};

// Define a struct to represent a monster
struct Monster
{
  // can be of any type
  MonsterType monsterType{};

  // has a name and the health left
  std::string name{};
  int remainingHealth{};
};

std::string getMonsterType(Monster& type)
{
  switch (static_cast<int>(type.monsterType))
  {
    case 0: return "Ocre"; break;
    case 1: return "Dragon"; break;
    case 2: return "Orc"; break;
    case 3: return "Giant_spider"; break;
    case 4: return "Slime"; break;
  }
  return "Unknown type";
}

void printMonster(Monster& x)
{
  // the function is called here since initializing the str to a variable in the main function can be expensive
  std::cout << "This " << getMonsterType(x) << " is named " << x.name << " and has " << x.remainingHealth << ". \n";
}

int main()
{
  Monster ogre{MonsterType::ogre, "Trog", 145};
  Monster slime{MonsterType::slime, "Blurp", 23};

  printMonster(ogre);
  printMonster(slime);
  return 0;
}
