#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
using namespace std;

void flipping_coins(int num, vector<int>& heads, vector<int>& tails) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>tossing(1,2);
    
    for (int i{0}; i < num; ++i) {
        int result = tossing(gen);
        result == 1 ? heads.push_back(result) : tails.push_back(result);
    }
    double result1 = (static_cast<double>(heads.size()) / num) * 100;
    double result2 = (static_cast<double>(tails.size()) / num) * 100;
    cout << "The result of flipping coins by " << num << " is for heads " << result1 << " % for coins " << result2 << " % " << endl;
}


void two_dice(int num, vector<int>& results, vector<int>& freq) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>first_dice(1,6);
    uniform_int_distribution<>second_dice(1,6);
    for (int i{0}; i < num; ++i) {
        int result1 = first_dice(gen);
        int result2 = second_dice(gen);
        int sum = result1 + result2;
        results.push_back(sum);
        ++freq.at(sum);
    }

   
    cout << setw(6) << "Number" << setw(12) << "Frequency" << setw(12) << "Percentage" << '\n';
    for (size_t number{2}; number < freq.size(); ++number) {  
        double percentage = (static_cast<double>(freq.at(number)) / num) * 100;
        cout << setw(6) << number << setw(12) << freq.at(number) << setw(12) << fixed << setprecision(4) << percentage << "%" << '\n';
    }

}

int main() {
    vector<int>head_level1;
    vector<int>tail_level1;
    vector<int>head_level2;
    vector<int>tail_level2;
    vector<int>head_level3;
    vector<int>tail_level3;

    vector<int>results;
    vector<int>frequences(13, 0);

    //1 -head 2 -tail
   flipping_coins(200, head_level1, tail_level1);
   flipping_coins(20000, head_level2, tail_level2);
   flipping_coins(200000, head_level3, tail_level3);

   two_dice(36000000, results, frequences);

    return 0;
}
