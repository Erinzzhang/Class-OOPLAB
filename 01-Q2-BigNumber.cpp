// Name: 張雅涵
// Date: February 23, 2017
// Last Update: March 6, 2017
// Problem statement: 給定兩正整數A、B，請求出此兩數相加結果，請注意A與B的最大位數可高達10000位數。

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#define LEN 10000

using namespace std;

struct SBigInt ////initialize BigInt structure
{
    char value[LEN];
};

SBigInt Add(SBigInt &lhs, SBigInt &rhs) //add big number
{
    SBigInt ans;
    int i;
    for (i = 0; i < LEN; i++)
        ans.value[i] = lhs.value[i] + rhs.value[i];
    for (i = 0; i < LEN - 1; i++)
    {
        if (ans.value[i] >= 10)
        {
            ans.value[i + 1] += ans.value[i] / 10;
            ans.value[i] = ans.value[i] % 10;
        }
    }
    return ans;
}

int Input(char n[]) //input data
{
    string s;
    int i, l = 0;
    
    for (i = 0; i < LEN; i++)
    {
        n[i] = 0;
    }
    
    cin >> s;
    l = (int)s.length();
    
    // check the range of data  is allowed
    for (i = 0; i < l; i++)
    {
        n[i] = s[l - i - 1] - '0';
        if (n[i] > 10 || n[i] < 0)
        {
            cout << "Not a valid number, please try again." << endl;
            system("pause");
            exit(0);
        }
    }
    return 0;
}

void Print(SBigInt &result) // print result
{
    int i;
    //the length of bing number
    for (i = LEN - 1; i > 0; i--)
    {
        if (result.value[i] != 0)
        {
            break;
        }
    }
    
    for (int k = i; k >= 0; k--)
    {
        // char to int
        cout << (int)result.value[k];
    }
    cout << endl;
}

int main()
{
    SBigInt a, b, result;
    
    //input a, b
    Input(a.value);
    Input(b.value);
    
    //calculate result
    result = Add(a, b);
    
    //output result
    Print(result);
    return 0;
}
