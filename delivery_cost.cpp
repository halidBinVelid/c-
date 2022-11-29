#include <iostream> 

using namespace std;

int main(){

float lenght, width, height;
const float cost = 2.50;

cout << "ENTER LENGTH, WIDTH, HEIGHT IN A ROW WITH ONE SPACE:(all the measures must be equal to 10 or less.) ";
cin >> lenght >> width >> height;

float volume;
volume = lenght * width * height;
cout << "volume: " << volume <<endl;

float package_value;
package_value = volume * cost;
cout << "package value: " << package_value << "$" <<endl;

float surcharge;
const float inc_100_charge = 0.1;
const float inc_500_charge = 0.25;

if (lenght <= 10 && width <= 10 && height <= 10){
    if (volume > 500){
        surcharge = package_value * inc_500_charge;
        package_value += surcharge;
        cout << "all cost is " << package_value << "$" <<endl;
    }
    else if (volume > 100){
        surcharge = package_value * inc_100_charge;
        package_value += surcharge;
        cout << "all cost is " << package_value << "$" <<endl;
    }
    else{
        cout << "all cost is " << package_value << "$" <<endl;
    }
    


}else
    cout << "sorry, we cannot ship that delivery" <<endl;


    return 0;
}