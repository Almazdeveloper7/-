#include <iostream>
#include <random>
#include <array>
#include <cmath>
#include <string>

using namespace std;

void level_difficulty(int min_value, int max_value, const array<string, 4>& pass_words, const array<string, 4>& failed_words, int &summary, int &total) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min_value, max_value);
    uniform_int_distribution<> word_dist(0 , pass_words.size() - 1);
    uniform_int_distribution<> word_dist2(0 , failed_words.size() - 1);
    uniform_int_distribution<> ops(0,3);
    array<char, 4>operands = {'*', '-', '+', '/'}; 
    int chances = 10;
    int your_answer;
    int attempts = 0;

    do {
        attempts++;
        int first_number = dist(gen);
        int second_number = dist(gen);
        char operation = operands[ops(gen)];
        int correct_answer;
        char message;
        switch(operation) {
            case '+': correct_answer = first_number + second_number; message = '+'; break;
            case '-': correct_answer = first_number - second_number; message = '-'; break;
            case '*': correct_answer = first_number * second_number; message = '*'; break;
            case '/': if (first_number > second_number)  {
                correct_answer = first_number / second_number;
            } else {
                correct_answer = second_number / first_number;
            }  
            message = '/'; 
            break;
        }

        if ((message == '/') && (first_number > second_number)) {
            cout << "How much is " <<  first_number << " " << message << " " << second_number << '\n';
        } else if ((message == '/') && (second_number > first_number)) {
            cout << "How much is " <<  second_number << " " << message << " " << first_number << '\n';
        }  else {cout << "How much is " <<  first_number << " " << message << " " << second_number << '\n';}
        
        cout << "Please input the answer: " << '\n';
        cin >> your_answer;

    if (your_answer != correct_answer) {
         chances--;
         cout <<  failed_words[word_dist2(gen)] << " You have " << chances << " chances left" << '\n';
         cout << "--------------------------" << endl;
    } else {
        cout << pass_words[word_dist(gen)] << " You have guessed with " << attempts << " attempts!" << endl;
        cout << "--------------------------" << endl;
        summary += 10;  
    }
    total += 10;
} while (chances > 0);

}

int main() {
    array<string, 4>pass_words = {"Very good!", "Excellent!", "Nice work!", "Keep up the good work!"};
    array<string, 4>failed_words = {"No. Please try again.", "Wrong. Try once more.", "Don't give up!", "No. Keep trying."};
    
    int summary = 0;
    int total = 0;
    int level;
    cout << " Choose your level from 1 to 3" << '\n';
    cin >> level;

    if (level == 1) {
        level_difficulty(1,9, pass_words, failed_words, summary,total);
    } else if (level == 2) {
        level_difficulty(10,99, pass_words, failed_words, summary, total);
    } else if (level == 3) {
        level_difficulty(100, 999, pass_words, failed_words, summary, total);
    } else {
        cout << "Invalid input" << endl;
    }
    
    float passed_result = (1.0f * summary / total) * 100;
    cout << "You have run out of attempts! " << endl; 
    if (passed_result > 75) {
            cout << "Congratulations, you are ready to go to the next level!" << endl;
    } else {
            cout << "Please ask your teacher for extra help." << endl;
    }

    return 0;
}
 

