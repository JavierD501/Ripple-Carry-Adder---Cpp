#include <iostream>

//global arrays
int a [32];
int b [32];
int s [32];
int D = 0;
int binary[32];


int D_array[10000];
int part2[32];
float delayAvg;


void decimalToBinary(int num, int store[])
{
    //array the contains all 32 bits of the binary number
    int binaryDigits[32];

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
                    //Delay += 1;
                }
                else
                {
                    //sum = 0, carry = 0
                    carry = 0;
                    tempSum = 0;
                    //Delay += 1;
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

    for (int k = 31; k >= 0; k--)
    {
        //std::cout << s[k];
    }
    if (Delay > 64)
    {
        D = Delay;
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
    srand(time(0));
        for (int i = 0; i < 10000; i++)
        {
            generateRandoms();
            D_array[i] = D;

            delayAvg += D;
        }
        std::cout << "Total Delay: " << delayAvg;
        delayAvg /= 10000;
        std::cout << "\nAverage delay: " << delayAvg << "\n";

}
