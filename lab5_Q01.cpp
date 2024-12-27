#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void guess_number(int random, int turns) {
    int num;
    cout << "Enter your guess (between 1 and 100): ";
    cin >> num;
    if (num == random) {
        cout << "YOU WIN!" << endl;
        return;
    }
    if (turns <= 1) {
        cout << "You lose! The number was " << random << endl;
        return;
    }
    if (num < random) {
        cout << "Too low You have " << turns - 1 << " turns left" << endl;
    } else {
        cout << "Too high You have " << turns - 1 << " turns left" << endl;
    }
    guess_number(random, turns - 1);
}

int main() {
    srand(time(0));
    int random = rand() % 100 + 1;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "You have 5 turns to guess the correct number" << endl;
    guess_number(random, 5); 
}

