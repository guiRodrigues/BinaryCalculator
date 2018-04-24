/*
 *      ~> Problemas com o tipo de dado { long long ~ int }
 */


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int Power(int base, int exponent){
    int response=1;
    for(int i=1; i<=exponent; i++) response*=base;
    return response;
}

void BinaryToDecimal(){
    int counter=0, sum=0;
    bool invalidNumber=false;
//    Qual a razao do DIGIT ser long long int
    long long int number=0, digit=0;

    cout << "\n\n~> OK, now you need input the binary number:\n";

    cin >> number;

    while(number>0){
        digit=number%10;
        if(digit!=0 && digit!=1){
            invalidNumber=true;
            break;
        }
        if(digit==1) sum+=Power(2,counter);
        counter++;
        number/=10;
    }

    if(invalidNumber) cout << "\n\n~> I'm sorry, I can't solve the problem, you input a invalid value\n\n\n";
    else cout << "\n\n°°°{  " << sum << "  }°°°\n\n\n";
}

void DecimalToBinary(){
    int number=0;

    cout << "\n\n~> OK, now you need input the decimal number:\n";

    cin >> number;

    long long binaryNumber = 0;
    int remainder, i = 1;

    while (number!=0)
    {
        remainder = number%2;
        number /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }

    cout << "\n\n°°°{  " << binaryNumber << "  }°°°\n\n\n";
}

void Exercise(){
    int operation=0;

    cout << "\n\n~> Ok, now you will choose the type of exercise:\n~~~~~> { 1 } to decimal~binary;\n~~~~~> { 2 } to binary~decimal\n\n";

    cin >> operation;

    if(operation==1) cout << ( rand()%100 )+1 << "\n\n";
    else if(operation) cout << "wait\n\n";
}

int main() {

    int operation=0;
    bool end=false;

    while(!end) {

        cout << "\n\n~> Hello User\n~> Welcome to the binary calculator\n";
        cout << "~> So, to start you need choose the operation:\n";
        cout << "~> Press { 1 } to BINARY ~ DECIMAL\n";
        cout << "~> Press { 2 } to DECIMAL ~ BINARY\n";
        cout << "~> Press { 3 } to exercise\n";

        cin >> operation;

        while (operation!=1 && operation!=2 && operation!=3) {
            cout << "~> Invalid operation, write again" << "\n";
            cin >> operation;
        }
        if (operation == 1) BinaryToDecimal();
        else if (operation == 2) DecimalToBinary();
        else if(operation == 3) Exercise();

        cout << "~> Another operation? Press { 1 } to continue or { 2 } to finish.\n";
        cin >> operation;
        if(operation==2) end=true;
    }

    return 0;
}