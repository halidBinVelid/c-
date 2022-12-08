#include <iostream>
#include <vector> 
using namespace std;


void change_numbers(int&, int&);

int main(){
    int num {10};
    int another_num {20};

    cout << "first number  : " << num << endl;
    cout << "second number : " << another_num << endl;
    cout << endl;
    change_numbers(num, another_num);
  

    return 0;
}

void change_numbers(int &a, int &b){
    int c {};
    c = a;
    a = b;
    b = c;
    cout << "first number  : " << a << endl;
    cout << "second number : " << b << endl;
}