#include <iostream>
using namespace std;

int main() {
    char inputString[200];
    cout << "Enter the String: ";
    cin >> inputString;
    cout << endl;

    int prevPos = 0; // 0 = low and 1 = high

    // Display the characters in the string
    for (int i = 0; inputString[i] != '\0'; ++i) {
        char currentChar = inputString[i];
        cout << " " << currentChar << " ";
    }
    cout << endl;

    // Display HIGH LOW or LOW HIGH for each bit
    for (int i = 0; inputString[i] != '\0'; ++i) {
        char currentChar = inputString[i];
        if (currentChar == '0') {
            if (i == 0) {
                cout << " HIGH LOW ";
                prevPos = 0;
            } else {
                if (prevPos == 0) {
                    cout << " LOW HIGH ";
                    prevPos = 1;
                } else {
                    cout << " HIGH LOW ";
                    prevPos = 0;
                }
            }
        } else {
            if (i == 0) {
                cout << " LOW HIGH ";
                prevPos = 1;
            } else {
                if (prevPos == 0) {
                    cout << " LOW HIGH ";
                    prevPos = 1;
                } else {
                    cout << " HIGH LOW ";
                    prevPos = 0;
                }
            }
        }
    }
    cout << endl;

    // Display vertical bars for each bit
    for (int i = 0; inputString[i] != '\0'; ++i) {
        cout << " |";
    }
    cout << endl;

    prevPos = 0;
    // Display underscores and bars to represent the bits
    for (int i = 0; inputString[i] != '\0'; ++i) {
        char currentChar = inputString[i];
        if (currentChar == '0') {
            if (i == 0) {
                cout << "|----|____";
                prevPos = 0;
            } else {
                if (prevPos == 0) {
                    cout << "|----|____";
                    prevPos = 0;
                } else {
                    cout << "_|----|__";
                    prevPos = 1;
                }
            }
        } else {
            if (i == 0) {
                cout << "|___|----";
                prevPos = 1;
            } else {
                if (prevPos == 0) {
                    cout << "|____|---";
                    prevPos = 1;
                } else {
                    cout << "----|____";
                    prevPos = 0;
                }
            }
        }
    }
    cout << "|";
    cout << endl;

    // Display vertical bars for each bit
    for (int i = 0; inputString[i] != '\0'; ++i) {
        cout << " |";
    }
    cout << endl;

    return 0;
}
