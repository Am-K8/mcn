#include<iostream>
using namespace std;
#define MAX 10

void displayDigitalSignal(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << "Low->";
        } else if (a[i] == 1) {
            cout << "High->";
        } else {
            cout << "Invalid signal value: " << a[i] << ". Only 0 and 1 are allowed." << endl;
            return;
        }

        // Insert vertical line between bits except after the last bit
        if (i < n - 1) {
            cout << "|";
        }
    }
    cout << endl;

    //visual rep
    cout << "Digital Signal: ";
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0) {
            cout << "__";
        }
        else if (a[i] == 1) {
            cout << "----";
        }
        else {
            cout << "Invalid signal value: " << a[i] << ". Only 0 and 1 are allowed." << endl;

        }

        // Insert vertical line between bits except after the last bit
        if (i < n - 1) {
            cout << "|";
        }
    }
    cout << endl;
}

int main()
{
    int n, i;
    int a[MAX];
    cout << "Enter the length of signal: ";
    cin >> n;

    if (n > MAX) {
        cout << "Length of signal should not exceed " << MAX << endl;
        return 1;
    }

    for (i = 0; i < n; i++)
        a[i] = 0;

    cout << "Enter the signal: ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    displayDigitalSignal(n,  a);

    return 0;
}
