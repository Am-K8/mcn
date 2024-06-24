#include <iostream>
#include <cstring>
using namespace std;

char* differentialManchesterEncoding(const char* inputString) {
    static char output[1000];
    int outputIndex = 0;

    int prevPos = 0; // 0 = low and 1 = high

    // Display the characters in the string
    for (int i = 0; inputString[i] != '\0'; ++i) {
        char currentChar = inputString[i];
        output[outputIndex++] = ' ';
        output[outputIndex++] = currentChar;
        output[outputIndex++] = ' ';
    }
    output[outputIndex++] = '\n';

    // Display HIGH LOW or LOW HIGH for each bit
    for (int i = 0; inputString[i] != '\0'; ++i) {
        char currentChar = inputString[i];
        if (currentChar == '0') {
            if (i == 0) {
                strcpy(&output[outputIndex], " HIGH LOW ");
                outputIndex += strlen(" HIGH LOW ");
                prevPos = 0;
            } else {
                if (prevPos == 0) {
                    strcpy(&output[outputIndex], " LOW HIGH ");
                    outputIndex += strlen(" LOW HIGH ");
                    prevPos = 1;
                } else {
                    strcpy(&output[outputIndex], " HIGH LOW ");
                    outputIndex += strlen(" HIGH LOW ");
                    prevPos = 0;
                }
            }
        } else {
            if (i == 0) {
                strcpy(&output[outputIndex], " LOW HIGH ");
                outputIndex += strlen(" LOW HIGH ");
                prevPos = 1;
            } else {
                if (prevPos == 0) {
                    strcpy(&output[outputIndex], " LOW HIGH ");
                    outputIndex += strlen(" LOW HIGH ");
                    prevPos = 1;
                } else {
                    strcpy(&output[outputIndex], " HIGH LOW ");
                    outputIndex += strlen(" HIGH LOW ");
                    prevPos = 0;
                }
            }
        }
    }
    output[outputIndex++] = '\n';

    // Display vertical bars for each bit
    for (int i = 0; inputString[i] != '\0'; ++i) {
        output[outputIndex++] = ' ';
        output[outputIndex++] = '|';
    }
    output[outputIndex++] = '\n';

    prevPos = 0;
    // Display underscores and bars to represent the bits
    for (int i = 0; inputString[i] != '\0'; ++i) {
        char currentChar = inputString[i];
        if (currentChar == '0') {
            if (i == 0) {
                strcpy(&output[outputIndex], "|----|___");
                outputIndex += strlen("|---|____");
                prevPos = 0;
            } else {
                if (prevPos == 0) {
                    strcpy(&output[outputIndex], "|---|____");
                    outputIndex += strlen("|---|____");
                    prevPos = 0;
                } else {
                    strcpy(&output[outputIndex], "_|---|__");
                    outputIndex += strlen("_|---|__");
                    prevPos = 1;
                }
            }
        } else {
            if (i == 0) {
                strcpy(&output[outputIndex], "|____|---");
                outputIndex += strlen("|____|---");
                prevPos = 1;
            } else {
                if (prevPos == 0) {
                    strcpy(&output[outputIndex], "|____|‾‾‾‾");
                    outputIndex += strlen("|____|‾‾‾‾");
                    prevPos = 1;
                } else {
                    strcpy(&output[outputIndex], "‾‾‾‾|____");
                    outputIndex += strlen("‾‾‾‾|____");
                    prevPos = 0;
                }
            }
        }
    }
    output[outputIndex++] = '|';
    output[outputIndex++] = '\n';

    // Display vertical bars for each bit
    for (int i = 0; inputString[i] != '\0'; ++i) {
        output[outputIndex++] = ' ';
        output[outputIndex++] = '|';
    }
    output[outputIndex++] = '\n';
    output[outputIndex] = '\0';

    return output;
}

int main() {
    char inputString[200];
    cout << "Enter the String: ";
    cin >> inputString;
    cout << endl;

    char* result = differentialManchesterEncoding(inputString);
    cout << result;

    return 0;
}
