//
// Created by Ogweno on 28/07/2025.
//
#include <iostream>
using namespace  std;

bool guessAndCheck(int secretNum, int randomNumber);
int main()
{
    // Guessing game
    constexpr int max_trial_attempts = 5;
    int user_attempts_made = 0;

    cout<<" Welcome to the ULTIMATE GUESSER! " << endl;
    cout<<" I have picked a number between 1 and 100" << endl;
    cout<< "I want you to guess it for... drum rolls please:::Nothing!" << endl;
    srand(time(nullptr));
    const int randomNumber = rand()%100+1;

    bool guessedCorrectly= false;

    while (user_attempts_made<max_trial_attempts && !guessedCorrectly)
    {
        cout << "Attempt " << (user_attempts_made+1)  << endl;
        cout << "Enter your guess!" << endl;

        int guess;
        cin >> guess;

        guessedCorrectly = guessAndCheck(guess, randomNumber);
        user_attempts_made++;

        if (!guessedCorrectly && user_attempts_made<max_trial_attempts)
        {
            cout << (max_trial_attempts-user_attempts_made) << " attempts remaining" << endl;
        }
    }
    if (!guessedCorrectly)
    {
        cout << "Sorry you ran out of guesses"<< endl;
        cout << "The random number is " << randomNumber << endl;
    }

    return 0;
}
/*
 * Guessing game
 *
 */
bool guessAndCheck(int secretNum, int randomNumber)
{

    if (secretNum == randomNumber)
    {
        return true;
    }
    else
    {
        return false;
    }

}
