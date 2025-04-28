#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ASCII art for the game choices
const string ROCK = R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
)";

const string PAPER = R"(
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________)
)";

const string SCISSORS = R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
)";

int main() {
    srand(time(0)); // seed the random number generator

    string playerChoice;
    string computerChoice;
    int playerScore = 0, computerScore = 0;

    cout << "Welcome to Rock-Paper-Scissors!" << endl;

    while (true) {
        // Get player's choice
        cout << "Choose rock, paper, or scissors: ";
        cin >> playerChoice;

        // Generate computer's choice
        int randomChoice = rand() % 3;
        if (randomChoice == 0) {
            computerChoice = "rock";
        } else if (randomChoice == 1) {
            computerChoice = "paper";
        } else {
            computerChoice = "scissors";
        }

        // Display the choices
        cout << "You chose:" << endl << playerChoice << endl;
        if (playerChoice == "rock") {
            cout << ROCK << endl;
        } else if (playerChoice == "paper") {
            cout << PAPER << endl;
        } else {
            cout << SCISSORS << endl;
        }

        cout << "The computer chose:" << endl << computerChoice << endl;
        if (computerChoice == "rock") {
            cout << ROCK << endl;
        } else if (computerChoice == "paper") {
            cout << PAPER << endl;
        } else {
            cout << SCISSORS << endl;
        }

        // Determine the winner
        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if (
            (playerChoice == "rock" && computerChoice == "scissors") ||
            (playerChoice == "paper" && computerChoice == "rock") ||
            (playerChoice == "scissors" && computerChoice == "paper")
        ) {
            cout << "You win!" << endl;
            playerScore++;
        } else {
            cout << "The computer wins!" << endl;
            computerScore++;
        }

        cout << "Player score: " << playerScore << ", Computer score: " << computerScore << endl;

        // Ask if the player wants to play again
        char playAgain;
        cout << "Do you want to play again? (y/n) ";
        cin >> playAgain;
        if (playAgain != 'y') {
            break;
        }

        cout << endl;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
