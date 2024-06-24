#include <iostream>
#include <cstring>
using namespace std;

void manchesterEncoding(char* input, int length) {
    // Buffer to store the encoded result
    char encoded[401];  // Enough space for 2 characters per bit + null terminator
    int idx = 0;

    cout << "\nEncoded Signal:\n" << endl;

    // First line: textual representation
    for (int i = 0; i < length; ++i) {
        char currentChar = input[i];
        if (currentChar == '0')
            cout << " Low->High ";
        else if (currentChar == '1')
            cout << " High->Low ";
        else {
            cout << "Invalid input: " << currentChar << endl;
            return;
        }
    }

    cout << endl;

    // Second line: graphical representation
    for (int i = 0; i < length; ++i) {
        char currentChar = input[i];
        if (currentChar == '0') {
            cout << "__|--";
            encoded[idx++] = '__';
            encoded[idx++] = '|';
            encoded[idx++] = '--';
        } else if (currentChar == '1') {
            cout << "--|__";
            encoded[idx++] = '--';
            encoded[idx++] = '|';
            encoded[idx++] = '__';
        }
    }

    encoded[idx] = '\0';  // Null-terminate the encoded string
    strcpy(input, encoded);  // Copy the encoded result back into the input string

    cout << endl;
}

int main() {
    int n;
    char a[201];  // Space for 200 characters + null terminator
    cout << "Enter length of string: ";
    cin >> n;

    if (n > 200) {
        cout << "Length of string should not exceed 200" << endl;
        return 1;
    }

    cout << "Enter the string: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = '\0';  // Null-terminate the string

    manchesterEncoding(a, n);

    cout << "Encoded result stored in input string: " << a << endl;

    return 0;
}
