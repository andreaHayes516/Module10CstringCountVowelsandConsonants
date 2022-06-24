/************************************************
** Author: Andrea Hayes
** Date: September 16, 2020
** Module 10 - C-String 
*************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
// Function Prototypes
int countVowels(char *);
int countConsta(char *);
int main() {

    // Declare Variables
    const int SIZE = 101;
    char words[SIZE], choice;
    const char VOWEL = 'A', CONSTA = 'B', BOTH = 'C', AGAIN = 'D', EXIT = 'E';

    // User Menu
    bool newString;
    do {
        newString = true;
        cout << "Enter a string: ";
        cin.getline(words, SIZE);

        do {
            cout << endl;
            cout << "Please choose (A,B,C,D or E) from the following options: " << endl;
            cout << "A) Count the number of vowels in the string" << endl;
            cout << "B) Count the number of consonants in the string" << endl;
            cout << "C) Count both the vowels and consonants in the string" << endl;
            cout << "D) Enter another string" << endl;
            cout << "E) Exit the program" << endl;
            cout << "Choice: ";
            cin >> choice;
            choice = toupper(choice);

            if (choice < VOWEL || choice > EXIT) {
                cout << "Please enter a valid choice from the menu" << endl;
                continue;
            }

            switch (choice) {
            case VOWEL:
                cout << "--------" << endl;
                cout << "Number of vowels: " << countVowels(words) << endl;
                cout << "--------" << endl;
                continue;

            case CONSTA:
                cout << "--------" << endl;
                cout << "Number of consonants " << countConsta(words) << endl;
                cout << "--------" << endl;
                continue;

            case BOTH:
                cout << "--------" << endl;
                cout << "Number of vowels " << countVowels(words) << endl;
                cout << "Number of consonants " << countConsta(words) << endl;
                cout << "--------" << endl;
                continue;

            case AGAIN:
                newString = false;
                cin.getline(words, SIZE);
                break;

            case EXIT:
                return 0;
            }

        } while (choice != EXIT && newString);

    } while (true);
    
    return 0;
}
//Functions
int countVowels(char* strPtr) {
    int vowels=0;
    while (*strPtr != '\0') {
        if (*strPtr == 'a' || *strPtr == 'A' || *strPtr == 'e' || *strPtr == 'E' || *strPtr == 'i' 
            || *strPtr == 'I' || *strPtr == 'o' || *strPtr == 'O' || *strPtr == 'u' || *strPtr == 'U')
            vowels++;
        strPtr++;
    }
    return vowels;
}
int countConsta(char* strPtr) {
    int consta = 0;
    bool v;
    
    while (*strPtr != '\0') {
        v = (*strPtr == 'a' || *strPtr == 'A' || *strPtr == 'e' || *strPtr == 'E' || *strPtr == 'i' || *strPtr == 'I'
            || *strPtr == 'o' || *strPtr == 'O' || *strPtr == 'u' || *strPtr == 'U');
        if (v == false)
            consta++;
        strPtr++;
}
    return consta;
}

