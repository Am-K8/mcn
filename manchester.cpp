#include <iostream>
using namespace std;

int main()
{
    int n;
    char a[200];
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

    cout << "\nEncoded Signal:";
    cout << endl;

    // First line: textual representation
    for (int i = 0; i < n; ++i) {
        char currentChar = a[i];
        if (currentChar == '0')
            cout << " Low->High ";
        else if (currentChar == '1')
            cout << " High->Low ";
        else {
            cout << "Invalid input: " << currentChar << endl;
            return 1;
        }
    }

    cout << endl;

    // Second line: graphical representation
    for (int i = 0; i < n; ++i) {
        char currentChar = a[i];
        if (currentChar == '0')
            cout << "__|--";
        else if (currentChar == '1')
            cout << "--|__";
    }

    cout << endl;

    return 0;
}
