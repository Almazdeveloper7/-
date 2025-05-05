#include <iostream>
#include <random>
using namespace std;


int main()
 {
    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1,1001);

    int guess;
    int number_of_guesses = 10;
    int random_number = distr(gen);

    cout << "I have a number between 1 and 1000: \n";
    cout << "Can you guess my number \n";
    cout << "Please type your first guess " << endl;

    while (number_of_guesses > 0) {
        cin >> guess;
        --number_of_guesses;

        if (guess == random_number) {
            cout << "Congratulations you number is " << 
            guess << " and a random_number is " << random_number <<
            " end number of of guesses is " << number_of_guesses << endl;
            break;  
        }

        if (random_number > guess) {
            cout << "Random number is bigger than your number - try more! " << endl;
        } else {
            cout << "Random number is smaller than your guess number - try more! " << endl;

        }

        if (number_of_guesses == 1) {
            cout << " One more chance to guess! " << endl;
        }

    } 

    return 0;
 }
