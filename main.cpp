#include <iostream>
#include "BigInt.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream text ("input.txt");


    //READING A TEXT FILE
    BigInt Res;
    if (text)
    {
        string temp;
        string operation = "";
        while (!text.eof())
        {
            text >> temp;
            if (temp == "*" || temp == "+")
                operation = temp;
            else
            {
                if (operation.empty())
                {
                    Res.createBigInt(temp);
                    continue;
                }

                BigInt gecici;
                gecici.createBigInt(temp);

                if (operation == "+")
                    Res = Res.add(gecici);
                else if (operation == "*")
                    Res = Res.multiply(gecici);
            }
        }

        text.close();
    }

    //WRITING RESULT TO THE OUTPUT FILE
    ofstream output ("output.txt", ofstream::trunc);
    if (output)
    {
        output << Res.GetBigIntAsString() <<endl;
        output.close();
    }

    return 0;
}
