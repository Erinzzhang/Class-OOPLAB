//
//  main.cpp
//  calculator
//
//  Created by erin on 2017/3/12.
//  Copyright © 2017年 erin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct SNumArray{
    vector<char> CharNum;
    vector<int> newNum;
    vector<int> ansNum;
    vector<int> ans;
};

bool isNum(char word){
    if (word <= '9' && word >= '0'){
        return true;
    }else {
        return false;
        
    }
}

int isOperator(int num){
    if (num == '+' || num == '-' || num == '*' || num == '/'){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    
    //initial
    SNumArray array;
    char readWord;
    int temp = 0;
    int ans = 0;
    int n = 0;
    
    cin >> n;
    for (int i = 0; i <= n; i++){
        //input data
        readWord = cin.get();
        while (readWord != '\n')
        {
            if (readWord != ' ')
            {
                array.CharNum.push_back(readWord);
            }
            readWord = cin.get();
        }
        
        //turn INPUT frotm char to int
        for(int i = 0; i < array.CharNum.size(); i++)
        {
            if(isNum(array.CharNum[i]) == 1)
            {
                temp = 0;
                while (isNum(array.CharNum[i]) == 1 && i < array.CharNum.size())
                {
                    temp = temp * 10 + (int)(array.CharNum[i] - '0');
                    i++;
                }
                array.newNum.push_back(temp);
                temp = 0;
                i--;
                
            }else if(isNum(array.CharNum[i]) == 0)
            {
                temp = (int)array.CharNum[i];
                array.newNum.push_back(temp);
            }else
            {
                cout << "error!" << endl;
            }
            
        }
    
        //先 * / 後 + -
        int sign = 0;
        for (int i = 0; i < array.newNum.size(); i++){

            if (array.newNum[0] != '-' && i == 0)
            {
                temp = array.newNum[0];
                array.ansNum.push_back(temp);
            }else if ((array.newNum[i] == '+' || array.newNum[i] == '-') && isOperator(array.newNum[i + 1]) == false )
            {
                if (array.newNum[i] == '+'){
                    sign = 1;
                }else{
                    sign = -1;
                }
                i++;
                temp = sign * array.newNum[i];
                array.ansNum.push_back(temp);
            }else if ((array.newNum[i] == '+' || array.newNum[i] == '-') && isOperator(array.newNum[i + 1]) == true )
            {
                if (array.newNum[i] == '+'){
                    sign = -1;
                }else{
                    sign = 1;
                }
                
                i += 2;
                temp = sign * array.newNum[i];
                array.ansNum.push_back(temp);
            }else if ((array.newNum[i] == '*' || array.newNum[i] == '/') && isOperator(array.newNum[i + 1]) == false )
            {
                if(array.newNum[i] == '*'){
                    i++;
                    temp = array.ansNum.back() * array.newNum[i];
                    array.ansNum.pop_back();
                    array.ansNum.push_back(temp);
                }else{
                    i++;
                    temp = array.ansNum.back() / array.newNum[i];
                    array.ansNum.pop_back();
                    array.ansNum.push_back(temp);
                }
                
                
            }else if ((array.newNum[i] == '*' || array.newNum[i] == '/') && isOperator(array.newNum[i + 1]) == true )
            {
                if (array.newNum[i] == '*'){
                    i += 2;
                    temp = array.ansNum.back() * array.newNum[i] * (-1);
                    array.ansNum.pop_back();
                    array.ansNum.push_back(temp);
                }else{
                    i += 2;
                    temp = array.ansNum.back() / array.newNum[i] * (-1);
                    array.ansNum.pop_back();
                    array.ansNum.push_back(temp);
                }
                
            }
        }
        
        //ans = ?
        for (int i = 0; i < array.ansNum.size(); i++){
            ans += array.ansNum[i];
            //cout << array.ansNum[i] << " ";
        }
        
        //store answer
        array.ans.push_back(ans);
        
        //reset data
        ans = 0;
        array.CharNum.clear();
        array.newNum.clear();
        array.ansNum.clear();
        
    }
    
    //print ans
    for (int i = 1; i < array.ans.size(); i++){
        cout << array.ans[i] << endl;
    }

    return 0;
}
