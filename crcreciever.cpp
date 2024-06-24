
#include<bits/stdc++.h>
using namespace std;

string xor2(string a, string b)
{
    int n = b.length();
    string result = "";

    for (int i=0; i<n; i++){
        if (a[i]==b[i])
            result += '0';
        else
            result += '1';
    }
    result = result.substr(1, n);
    return result;
}

string division(string dividend, string divisor)
{
    int n = dividend.length();
    int m = divisor.length();

    string temp = dividend.substr(0, m);

    while (m<n){
        if (temp[0]=='1'){
            temp = xor2(divisor, temp) + dividend[m];
        }
        else
            temp = xor2(std::string(m, '0'), temp) + dividend[m];
        m=m+1;
    }

    if (temp[0]=='1')
        temp = xor2(divisor, temp);
    else
        temp = xor2(std::string(m, '0'), temp);

    //temp = temp.substr(1, 3);
    return temp;
}

string sender_side(string dividend, string divisor)
{
    int n = divisor.length();
    int m = dividend.length();
    string appended_dividend = dividend + std::string(n-1, '0');
    string rem = division(appended_dividend, divisor);
    cout<<endl<<"Remainder (at sender side): "<<rem;
    cout<<endl;

    appended_dividend = appended_dividend.substr(0, m);
    appended_dividend = appended_dividend + rem;

    return appended_dividend;
}

void receiver_side(string data, string divisor)
{
    cout<<endl<<"---Receiver---"<<endl;
    cout<<"Dividend: "<<data<<endl;
    cout<<"Divisor: "<<divisor<<endl;
    string rem = division(data, divisor);
    cout<<"Remainder (at receiver side): "<<rem;

    bool errorDetected = false;
    for (char c : rem) {
        if (c != '0') {
            errorDetected = true;
            break;
        }
    }

    if (errorDetected) {
        cout << "\nError detected in received data." << endl;
    } else {
        cout << "\nNo error in received data." << endl;
    }

}

int main()
{
    string dividend, divisor, encoded_data;
    cout<<"Enter dividend: ";
    cin>>dividend;
    cout<<"Enter divisor: ";
    cin>>divisor;
    encoded_data = sender_side(dividend, divisor);

    cout<<"Data sent to receiver: "<<encoded_data;
    cout<<endl;

    receiver_side(encoded_data, divisor);

    return 0;

}
