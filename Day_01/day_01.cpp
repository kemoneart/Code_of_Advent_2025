#include<iostream>
#include<fstream>
using namespace std;

fstream inputFile;
string input, fileName;
int temp, num, zeros, len;

/* Part 1 */

int main()
{
    fileName = "elf.txt";
    num = 50;
    zeros = 0;

    inputFile.open(fileName.c_str(), fstream::in);

    if(inputFile.is_open() == false)
    {
        cout << "Could not open file." << endl;
    }

    while(inputFile >> input)
    {    
        temp = 0;
        len = input.length();

        for(int i = 1; i < len; i++)
        {
            temp = (temp * 10) + (input[i] - 48);
        }
        if(input[0] == 'L')
            num = num - temp;
        else if (input[0] == 'R')
            num = num + temp;
            
        num = num % 100;

        if(num < 0)
            num = 100 - abs(num);
            
        cout << "num = " << num << endl;     
        
        if(num == 0)
            zeros++;
    }
    cout << "zeros = " << zeros << endl; 
}

