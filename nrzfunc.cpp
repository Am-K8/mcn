#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10

// Function to display digital signal with textual and visual representation
void displayDigitalSignal(int n, int a[], char* input) {
    string textualRepresentation;
    string visualRepresentation;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            textualRepresentation += "Low->";
            visualRepresentation += "__";
        } else if (a[i] == 1) {
            textualRepresentation += "High->";
            visualRepresentation += "----";
        } else {
            textualRepresentation = "Invalid signal value: " + to_string(a[i]) + ". Only 0 and 1 are allowed.\n";
            return;
        }

        // Insert vertical line between bits except after the last bit
        if (i < n - 1) {
            textualRepresentation += "|";
            visualRepresentation += "|";
        }
    }

    // Copying textual representation to char* input
    strcpy(input, textualRepresentation.c_str());

    // Print the visual representation
    cout << "Visual Representation: " << visualRepresentation << endl;
}

int main() {
    int n;
    int a[MAX];
    char input[100]; // Assuming a reasonable size for the input buffer

    cout << "Enter the length of signal: ";
    cin >> n;

    if (n > MAX) {
        cout << "Length of signal should not exceed " << MAX << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
        a[i] = 0;

    cout << "Enter the signal (0 or 1): ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Call the function to display and store the signal representation
    displayDigitalSignal(n, a, input);

    // Output stored in input buffer
    cout << "Textual Representation (stored in input): " << input << endl;

    return 0;
}
