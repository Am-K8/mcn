#include <iostream>
#include <cstring>

using namespace std;

void bit_stuffing(char* input) {
    int originalLength = strlen(input);
    int newLength = originalLength * 2;  // Estimate new length for the worst-case scenario
    char* result = new char[newLength + 1];  // Allocate memory for the potentially expanded string

    int i = 0, j = 0, count = 0;

    while (input[i] != '\0') {
        if (input[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        result[j++] = input[i];
        if (count == 5 && input[i + 1] == '1') {
            result[j++] = '0';
            count = 0;
        }
        i++;
    }
    result[j] = '\0';  // Null-terminate the encoded string

    strcpy(input, result);  // Copy the encoded string back to input
    delete[] result;  // Free the allocated memory
}

int main() {
    char input[200];
    cout << "Enter the data: ";
    cin >> input;

    bit_stuffing(input);

    cout << "Stuffed data: " << input << endl;

    return 0;
}

