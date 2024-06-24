#include <iostream>
#include <cstring>

using namespace std;

void byteStuffing(char* input, int n) {
    const char* FLAG = "FLAG";
    const char* ESC = "ESC";
    char* result = new char[1000]; // Allocate a large enough buffer for the result
    int j = 0;

    strcpy(result, FLAG);
    j += strlen(FLAG);
    result[j++] = ' ';

    for (int i = 0; i < n; i++) {
        char d[100];
        cout << "Enter the data: ";
        cin >> d;

        if (strcmp(d, ESC) == 0 || strcmp(d, FLAG) == 0) {
            strcpy(result + j, ESC);
            j += strlen(ESC);
            result[j++] = ' ';
        }

        strcpy(result + j, d);
        j += strlen(d);
        result[j++] = ' ';
    }

    strcpy(result + j, FLAG);
    j += strlen(FLAG);
    result[j] = '\0'; // Null-terminate the result

    strcpy(input, result); // Copy the result back to the input buffer
    delete[] result; // Free the allocated memory
}

int main() {
    char input[1000]; // Allocate a large enough buffer for input
    int n;

    cout << "Enter the number of bytes: ";
    cin >> n;

    byteStuffing(input, n);

    cout << "Stuffed data: " << input << endl;

    return 0;
}
