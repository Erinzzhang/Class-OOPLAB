//
//  main.cpp
//  Palindrome
//
//  Created by erin on 2017/3/2.
//  Copyright © 2017年 erin. All rights reserved.
//

// strings and c-strings
#include <iostream>
#include <string>
#include <iomanip>


//Reverses the order of the elements in the range [first,last).
std::string convert (std::string str){
    std::reverse(str.begin(),str.end());
    return str;
}

std::string DectoAry (int findNum, int base)
{
    int temp = 0;
    std::string aryNum = "" ;
    while( findNum != 0 ) /* 替 findNum 長除法，找出 findNum 的base進位值，並將轉換的結果送入temp變數 */
    {
        temp = findNum % base;  // findNum % base：代表findNum除ary的餘數(temp)
        findNum = findNum / base;   // findNum/base：代表a除n的商
        aryNum = static_cast<char>(temp + '0') + aryNum;
    }
    return aryNum;
}

int main(int argc, const char * argv[]) {
    std::string str;
    std::string findNumStr,cNum,aryNum,cAryNum;
    int num;
    int findNum = 0;
    
    // input string
    while(std::cin >> str){
        int count = 0;
        num = std::stoi( str );// string to number
        
        //find palindrome number
        for (int i = num; i <= 100000 ; i++){
            findNum = i;
            std::string findNumStr = std::to_string(findNum);
            cNum = convert(findNumStr);
        
                for (int base = 2; base < 10; base++){
                    //Ary num
                    aryNum =  DectoAry(findNum,base);
                    //reserve number
                    cAryNum = convert(aryNum);
                    
                    if (findNumStr == cNum && aryNum == cAryNum && count < 1){
                        std::cout << findNum << " \n";
                        std::cout << base << " " << cAryNum << "\n";
                        std::cout << "10 " << findNum << " \n";
                        count ++;
                    }//end if
                    
                }//end for
            
        }//end for
        
        //show No answer
        if (count == 0){
            std::cout << "No answer. \n";
        }
        
    }
    
    return 0;
    
}
