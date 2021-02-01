#include "BigInt.h"
#include <iostream>

using namespace std;

BigInt::BigInt(){

}

BigInt::BigInt(const BigInt& other)
{
    numbers = other.numbers;
}

BigInt::~BigInt(){

}

void BigInt::createBigInt(string num){
    int i=0;
    while(num[i]!='\0'){
        int a=(num[i]-'0');
        numbers.addToDLLTail(a);
        i++;
    }
}

void BigInt::printBigInt(){
    cout << numbers << endl;
}

void BigInt::freeBigInt(){
    numbers.clear();
}

void BigInt::updateBigInt(string num){
    freeBigInt();
    createBigInt(num);
}

string BigInt::GetBigIntAsString(){
    return numbers.getNumAsString();
}

BigInt BigInt::add(BigInt secondNum){
    BigInt ResultofAdd;

    string num2 = secondNum.GetBigIntAsString();
    string num = GetBigIntAsString();
    int carry = 0;
    int i = num.size() - 1;
    int j = num2.size() - 1;
    while(i>=0 || j>=0 || carry!= 0){
        int x;
        if(i>=0)
            x=num[i] - '0';
        else
            x=0;
        int y;
        if(j>=0)
            y=num2[j] - '0';
        else
            y=0;
        int result = x+y+carry;
        carry=result/10;
        result=result%10;

        ResultofAdd.AddToHead(result);

        i--;
        j--;
    }
    return ResultofAdd;
}

BigInt BigInt::multiply(int y){
    BigInt ResultofMultiply;
    string num = this->GetBigIntAsString();
    int i = num.size()-1;
    int carry=0;
    while(i>=0 || carry!=0){
        int x;
        if(i>=0)
            x=num[i]-'0';
        else
            x=0;
        int result = (x*y)+carry;
        carry=result/10;
        result=result%10;

        ResultofMultiply.AddToHead(result);

        i--;
    }
    return ResultofMultiply;

}

BigInt BigInt::multiply(BigInt secondNum){
    BigInt ResultofMultiply;
    string num2=secondNum.GetBigIntAsString();
    int j=num2.size()-1;
    int y;
    int count = 0;
    while(j>=0){
        y=num2[j]-'0';
        BigInt c = multiply(y);
        for(int i=0; i<count;i++)
            c.AddToTail(0);
        ResultofMultiply = ResultofMultiply.add(c);

        j--;
        count++;
    }
    return ResultofMultiply;
}
void BigInt::AddToHead(int x){
    numbers.addToDLLHead(x);
}
void BigInt::AddToTail(int x){
    numbers.addToDLLTail(x);
}
