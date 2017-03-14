//  main.cpp
//  fraction-EgyptianMethod
//
//  Created by erin on 2017/3/9.
//  Copyright © 2017年 erin. All rights reserved.
//

//#include "stdafx.h"
#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */

using namespace std;

int frequency_of_primes(int n) {
    int i, j;
    int freq = n - 1;
    for (i = 2; i <= n; ++i) for (j = sqrt(i); j>1; --j) if (i%j == 0) { --freq; break; }
    return freq;
}

int main(int argc, const char * argv[]) {
    
    clock_t t;
    int f;
    int data, n, count = 0;
    long long a, b;
    
    cin >> data;
    int nArray[data];

    for (int i = 0; i < data; i++){
        cin >> nArray[i];
    }
    for (int i = 0; i < data; i++){
        n = nArray[i];
        for (b = 2 * n; b >= (n + 1); b--){
            if ((n * b) % (b - n) == 0){
                a = (n * b) / (b - n);
                count++;
            }
        }

        cout << count << endl;
        
        for (b = 2 * n; b >= (n + 1); b--){
            if ((n * b) % (b - n) == 0){
                a = (n * b) / (b - n);
                if (n == (a * b) / (a + b)){
                    cout << a << "\t" << b << endl;
                }
            }
        }
        cout << endl;
    }
    
    t = clock();
    
    f = frequency_of_primes(99999);
    t = clock() - t;
    cout << "time : " << ((float)t) / CLOCKS_PER_SEC << "sec." << endl;
    
    system("pause");
    
    return 0;
    
}
