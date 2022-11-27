#include <iostream>

using namespace std;

int main() {

char operation;

do{
  short int age;
  cout << "what is your age? ";
  cin >> age;

    if (age < 18){
      cout << "you are not adult." <<endl;
    }
    else {
      cout << "you are adult." <<endl;
    }

  
  cout << "another process would you like to do? (y/n)";
  cin >> operation;
}while(operation == 'y');

  return 0;
}