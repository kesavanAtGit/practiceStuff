#include <cstdlib>
#include <iostream>
#include <random>
#include <limits>

// function to ignore the extraneous characters
void ignoreExtraCharacters()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int generateRandomNumber()
{
  std::random_device rd;
  std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
  std::mt19937 mt{ss};
  std::uniform_int_distribution<> guessGame{1, 100};

  return guessGame(mt);
}

bool isTrueOrFalse()
{
  int actualGuess{ generateRandomNumber() };
  int count{7};

  for (int i = 1; i <= count; i++)
  {
    std::cout << "Guess Number #" << i << ": ";

  tryagain: // this is a statement label
    int myGuess{};
    std::cin >> myGuess;

      // input again if the extraction fails
      if (!std::cin)
      {
        std::cin.clear();
        ignoreExtraCharacters();
        std::cerr << "Not a valid character! Please try again.";
        goto tryagain;
      }

      else
        ignoreExtraCharacters();

    // ask user to enter input only between 1 to 100
    if( myGuess == 0 || myGuess < 0 || myGuess > 100)
    {
      std::cout << "Enter a number only from 1 to 100: \n";
      goto tryagain;
    }

    else if ( myGuess == actualGuess)
    {
      std::cout << "Correct, you win! \n";
      return true;
    }

    else if (myGuess < actualGuess)
      std::cout << "Your guess is too low. \n";

    else if (myGuess > actualGuess)
      std::cout << "Your guess is too high. \n";
  }

    std::cout << "Aw, you lost! ";
    std::cout << "The actual guess is " << actualGuess << ". \n";

  return false;
}

void playGame()
{
  isTrueOrFalse();

  // ask the player if he wants to play again
  while(true)
  {
    std::cout << "Would you like to play again? 'y/n': ";
    char c{};
    std::cin >> c;
    ignoreExtraCharacters();

    switch (c)
    {
      case 'y':
        isTrueOrFalse();
      case 'n':
        std::cout << "Thanks for playing. \n";
        return;
    }
  }
}

int main()
{
  std::cout << "Let's play a game. I'm thinking of a number between 1 to 100. You have 7 tries to guess it. \n";
  playGame();

  return 0;
}
