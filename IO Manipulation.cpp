// Name: Ya Han Chang
// Date: February 23, 2017
// Last Update: February 23, 2017
// Problem statement: 輸入Ｎ個員工姓名(Name)、薪水(Salary)、獎金(Bonus)資料，並將N筆員工的資料列印出來，並且確保輸出結果保持整齊。

#include "stdio.h"
#include "stdlib.h"
# include "iostream"
#include "string"
#include "iomanip"

using namespace std;

int main(){
    
    int i, j;
    const int DATA_NUM = 3;
    int Data_Column;
    int maxLength[3] = { 0 };
    string **data;
    string name;
    string salary;
    string bonus;
    
    cout << "輸入人數：";
    cin >> Data_Column;
    
    // make sure members data : 0 < N <= 10^6
    if (Data_Column <= (10^6) && Data_Column > 0){
        
        //new data array : data[data_height][data_width]
        data = new string*[Data_Column];
        for (i = 0; i < Data_Column; i++)
            data[i] = new string[DATA_NUM];
        
        //enter data and put data into array
        for (i = 0; i < Data_Column; i++){
            for (j = 0; j < DATA_NUM; j++){
                //cout << "輸入姓名 薪水( 10^9 ~ 0 之間 ) 獎金( 10^9 ~ 0 之間 )\n";
                cin >> name >> salary >> bonus;
                data[i][j] = name;
                j += 1; 	//next array position
                data[i][j] = salary;
                j += 1;		//next array position
                data[i][j] = bonus;
            }
        }
        
        //find max data length
        for (i = 0; i < Data_Column; i++){
            for (j = 0; j < DATA_NUM; j++){
                if (maxLength[j] < data[i][j].length()){
                    maxLength[j] = data[i][j].length();
                }
            }
        }
        
        //print data
        for (i = 0; i < Data_Column; i++){
            for (j = 0; j < DATA_NUM; j++){
                //use setw() to set the field width to be used on output operations (need to add header <iomanip> )
                cout << setw(maxLength[0]) << data[i][j] << "|" << setw(maxLength[1] + 2) << data[i][j + 1] << "|" << setw(maxLength[2] + 2) << data[i][j + 2] << endl;
                j += 2;
            }
        }
        
    }
    else
    {
        cout << "重新輸入姓名、薪水( 10^9 ~ 0 之間 )及獎金( 10^9 ~ 0 之間 )";
        cin >> Data_Column;
    }
    
    // system pause
    system("pause");
    
    return 0;
}
