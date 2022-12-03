#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

string name = "halitertas";

for (size_t i = 1; i <= 30; i++)
    cout << "~";
cout << endl;

cout << left << setw(10) << "letters"
     << left << setw(15) << "ASCII CODES"
     << right << setw(5) << "|" << endl;

for (size_t i = 0; i < name.length(); i++)
    cout << left << setw(10) << name[i] 
         << left << setw(5) << static_cast<int>(name[i]) 
         << right << setw(15) << "|" << endl;

for (size_t i = 1; i <= 30; i++)
    cout << "~";
cout << endl;
    return 0;
}