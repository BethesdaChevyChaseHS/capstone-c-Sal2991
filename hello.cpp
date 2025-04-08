#include <iostream>

int FtoC(int degree){
    return (degree - 32) * 5/9;
}

int main()
{
    int input;
    std::cout << "Enter a Fahrenheit: ";
    std::cin >> input;
    std::cout << "In Celcius It's: " <<  FtoC(input) << std::endl;

    return 0;
}