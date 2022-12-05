#include <iostream>
#include <iomanip>
#include <string>



using namespace std;

int main(){

string message;
cout << "What is the message will be pyramid?(enter your message without space) ";
cin >> message;
int message_length = message.length();

string reverse_message = message;
for (int i = 0; i < message_length / 2; i++) 
    swap(reverse_message[i], reverse_message[message_length - i - 1]); 


for(size_t i = 0; i<message_length; i++){
    cout << right << setw(message_length) << message.substr(0,i+1)
         << left << setw(message_length) << reverse_message.substr(message_length - i,i+i)
         << endl; 
}

    return 0;
}
