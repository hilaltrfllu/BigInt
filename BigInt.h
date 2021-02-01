#ifndef BIGINT_H
#define BIGINT_H
#include "genDLList.h"

#include <string>

using namespace std;

class BigInt
{
public:
    BigInt();
    BigInt(const BigInt& other);
    virtual ~BigInt();

    void createBigInt(string num);
    void printBigInt();
    void freeBigInt();
    void updateBigInt(string num);
    BigInt add(BigInt num2);
    BigInt multiply(int y);
    BigInt multiply(BigInt num2);
    string GetBigIntAsString();
    void AddToHead(int a);

    void AddToTail(int a);



protected:


private:
    DoublyLinkedList<int> numbers;
};

#endif // BIGINT_H
