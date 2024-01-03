#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int sortAscending(string number_str){
    string sortedNumber = number_str;

    for (int i = 0; i < sortedNumber.length(); i++) {
        for (int j = i + 1; j < sortedNumber.length(); j++) {
            if (sortedNumber[i] > sortedNumber[j]) {
                swap(sortedNumber[i], sortedNumber[j]);
            }
        }
    }
    return stoi(sortedNumber);   
}

int sortDescending(string number_str){
    string sortedNumber = number_str;

    for (int i = 0; i < sortedNumber.length();i++) {
        for (int j = i + 1; j < sortedNumber.length(); j++) {
            if (sortedNumber[i] < sortedNumber[j]) {
                swap(sortedNumber[i], sortedNumber[j]);
            }
        }
    }
    return stoi(sortedNumber);
}

int stepsToKaprekarConstant(int number) {
    int steps = 0;
    while (number != 6174) {
        string number_str = to_string(number);
        while (number_str.length() < 4) {
            number_str = "0" + number_str;
        }

        int ascendingNumber=sortAscending(number_str);
        int descendingNumber=sortDescending(number_str);     
        number = descendingNumber - ascendingNumber;  
        steps++;
    }

    return steps;
}

int main() {
    int input_number = 5491;
    int steps = stepsToKaprekarConstant(input_number);
    cout << " Steps to reach Kaprekar's constant= "<< steps << endl;
    return 0;
}


