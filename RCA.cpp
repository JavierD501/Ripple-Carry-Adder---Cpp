//This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>


//global arrays
int a[32];
int b[32];
int s[32];
int D = 0;
int binary[32];


int D_array[10000];
int part2[32];
float delayAvg;


void decimalToBinary(unsigned int num, int store[])
{
    //array that contains all 32 bits of the binary number
    unsigned int binaryDigits[32];

    //set all values to 0 as default
    for (int j = 0; j < 32; j++)
    {
        binaryDigits[j] = 0;
    }

    //for traversing the array
    int i = 0;

    //fill array
    while (num > 0)
    {
        binaryDigits[i] = num % 2;
        num = num / 2;
        i++;
    }

    //allow values to be accessed in global array
    for (int i = 0; i <= 32; i++)
    {
        store[i] = binaryDigits[i];
        binary[i] = binaryDigits[i];
    }
}





void RCA(int a[], int b[])
{
    int carry = 0;
    int tempSum = 0;
    //RCA Delay
    int Delay = 0;

    for (int i = 0; i < 32; i++)
    {
        tempSum = a[i] + b[i] + carry;

        //conditionals on how to update the sum and carry values
        if (tempSum == 3 && carry == 0)
        {
            //sum = 1, carry = 1
            carry = 1;
            tempSum = 1;
            Delay += 2;

        }
        else if (tempSum == 2 && carry == 0)
        {
            carry = 1;
            tempSum = 0;
            Delay += 2;
        }
        else if (tempSum == 1 && carry == 0)
        {
            carry = 0;
            tempSum = 1;
        }
        else if (tempSum == 0 && carry == 0)
        {
            carry = 0;
            tempSum = 0;
        }
        else if (tempSum == 2 || tempSum == 1 || tempSum == 0 && carry == 1)
        {
            if (tempSum == 2)
            {
                //sum = 0, carry = 1
                carry = 1;
                tempSum = 0;
                Delay += 2;
            }
            else
            {
                if (tempSum == 1)
                {
                    //sum = 1, carry = 0
                    carry = 0;
                    tempSum = 1;
                }
                else
                {
                    //sum = 0, carry = 0
                    carry = 0;
                    tempSum = 0;
                }
            }
        }
        else if (tempSum == 3 and carry == 1)
        {
            carry = 1;
            tempSum = 1;
        }

        s[i] = tempSum;
        if (i == 31)
        {
            int LCout = carry;
        }
    }
    if (Delay > 64)
    {
        D = 64;
    }
    else
    {
        D = Delay + 2; //2 is from sum finalization
    }
}



void generateRandoms()
{
    int first = rand();
    int second = rand();
    int firstNum[32];
    int secondNum[32];

    decimalToBinary(first, firstNum);
    decimalToBinary(second, secondNum);

    RCA(firstNum, secondNum);


}





int main()
{
    //part 1
    unsigned int val1 = 4294967295;
    unsigned int val2 = 0;


    std::cout << "Decimal value of A: " << val1 << "\n";
    std::cout << "Decimal value of B: " << val2 << "\n";


    decimalToBinary(val1, a);
    std::cout << "Binary value of a: ";
    for (int k = 31; k >= 0; k--)
    {
        std::cout << binary[k];
    }
    std::cout << "\n";

    decimalToBinary(val2, b);
    std::cout << "Binary value of b: ";
    for (int k = 31; k >= 0; k--)
    {
        std::cout << binary[k];
    }
    std::cout << "\n";

    RCA(a, b);
    std::cout << "Binary sum: ";
    for (int k = 31; k >= 0; k--)
    {
        std::cout << s[k];
    }
    std::cout << "\n";

    //decimal sum
    unsigned int decsum = val1 + val2;
    std::cout << "Decimal sum: " << decsum << "\n" << "Final delay: " << D << "D";;
}
