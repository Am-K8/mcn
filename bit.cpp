#include <iostream> 
 
using namespace std; 
 
void bit_stuffing(string data) 
{ 
    int i = 0, j = 0, count = 0; 
    string stuffed_data; 
    
    while(i < data.length()) 
    { 
        if(data[i] == '1') 
            { 
                count++; 
            } 
    else 
            { 
                count = 0; 
            } 
    stuffed_data += data[i]; 
    if(count == 5 && data[i+1] == '1') 
        { 
            stuffed_data += '0'; 
            count = 0; 
        } 
        i++; 
    } 
    cout << "Stuffed data: " << stuffed_data << endl; 
} 
int main(void) 
{ 
    string data; 
    cout << "Enter the data: "; 
    cin >> data; 
    bit_stuffing(data); 
} 