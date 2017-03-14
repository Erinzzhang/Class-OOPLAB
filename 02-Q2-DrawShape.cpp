// Name: Ya Han Chang
// Date: March 2, 2017
// Last Update: March 6, 2017
// Problem statement: 製作一個簡單繪圖程式(背景用*填滿)，讓使用者可以在Console上畫出正方形、等腰直角三角形及直線(圖案用大寫X填滿)。

#include <iostream>
#include <algorithm> //std::min

using namespace std;

struct Panel{
    int n;                  //width of panel |
    int m;                  //length of panel --
    char array[100][100];   //array to save values for the panel
};

int checkRange(int n, int m, int x,int y ){
    if ( x >= 0 && x <= m-1 && y >= 0 && y <= n-1){
        return 1;
    }else{
        return 0; // out of range
    }
}

int DrawLine(Panel &panel, int x1, int y1, int x2, int y2){
    int dx, dy, minX, minY;
    int check = 0;
    
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    minX = min(x1, x2); //choose minX for draw line
    minY = min(y1, y2); //choose minY for draw line
    
    //check range
    check = checkRange(panel.n, panel.m, x1, y1);
    check += checkRange(panel.n, panel.m, x2, y2);
    
    //change panel's value to drow line
    if(check == 2){
        if (x1 == x2){
            for (int i = 0; i <= dy; i++){
                panel.array[x1][minY+i] = 'X';      // x-way axis
            }
        }else if (y1 == y2 ){
            for (int j = 0; j <= dx; j++){
                panel.array[minX+j][y1] = 'X';      //y-way axis
            }
        }else if(x1 < x2 && y1 < y2){
            for (int k = 0; k <= dx; k++){
                panel.array[minX+k][y1+k] = 'X';    //45 degree
            }
        }else if(x1 < x2 && y2 < y1){
            for (int m = 0; m <= dx; m++){
                panel.array[minX+m][y1-m] = 'X';    //135 degree
            }
        }else{
            cout << "Can't draw line." << endl;
        }
        return 1; //print
    }else{
        return 0; //NO print
    }
}

int DrawSquare(Panel &panel, int x, int y, int width){
    int check =0;
    
    //check range
    check = checkRange(panel.n, panel.m, x + width, y + width);
    
    if(check == 1){
        for(int i = 0; i < width ;i++){
            for (int j = 0; j < width; j++){
                panel.array[x+j][y+i] = 'X';
            }
        }
        return 1; //print
    }else{
        return 0; //NO print
    }
}

int DrawTriangle(Panel &panel, int x, int y, int width, string d){
    int x1,y1,x2,y2;
    int check = 0;
    
    if (d == "RU"){
        width = width - 1;  //true width
        x1 = x;             // Drowline define: x1 < x2
        y1 = y - width;
        x2 = x + width;     // Drowline define: x1 < x2
        y2 = y;
        
        check = checkRange(panel.n, panel.m, x1, y1);
        check += checkRange(panel.n, panel.m, x2, y2);
        
        if(check == 2){
            for(int i = y; i >= y1; i--){       //up
                for(int j = x; j <= x2 ; j++){  //right
                    panel.array[j][i] = 'X';
                }
                x2--; // 邊長向上遞減
            }
            return 1; //print
        }else{
            return 0; //NO print
        }
    }else if (d == "RD"){
        width = width - 1;  //true width
        x1 = x;             // Drowline define: x1 < x2
        y1 = y + width;
        x2 = x + width;     // Drowline define: x1 < x2
        y2 = y;
        
        check = checkRange(panel.n, panel.m, x1, y1);
        check += checkRange(panel.n, panel.m, x2, y2);
    
        if(check == 2){
            for (int i = y; i <= y1; i++){      //down
                for (int j = x; j <= x2; j++){  //right
                    panel.array[j][i] = 'X';
                }
                x2--; // 邊長向下遞減
            }
            return 1; //print
        }else{
            return 0; //NO print
        }
    }else if(d == "LU"){
        width = width - 1;  //true width
        x1 = x - width;     // Drowline define: x1 < x2
        y1 = y;
        x2 = x;             // Drowline define: x1 < x2
        y2 = y - width;
        
        check = checkRange(panel.n, panel.m, x1, y1);
        check += checkRange(panel.n, panel.m, x2, y2);
        
        width = width + 1;
        if(check == 2){
            for(int i = y; i >= y2; i--){       //up
                for (int j = x; j >= x1; j--){   //left
                    panel.array[j][i] = 'X';
                }
                x1++; // 邊長向上遞減
            }
            return 1; //print
        }else{
            return 0; //NO print
        }
    }else if(d == "LD"){
        width = width - 1;  //true width
        x1 = x - width;     // Drowline define: x1 < x2
        y1 = y;
        x2 = x;             // Drowline define: x1 < x2
        y2 = y + width;
        
        check = checkRange(panel.n, panel.m, x1, y1);
        check += checkRange(panel.n, panel.m, x2, y2);
        
        if(check == 2){
            
            for (int i = y; i <= y2; i++){      //down
                for(int j = x; j >= x1; j--){   //left
                    panel.array[j][i] = 'X';
                }
                x1++; // 邊長向下遞減
            }
            return 1; //print
        }else{
            return 0; //NO print
        }
    }else{
        cout << "Can't draw Triangle." << endl;
        return 0;
    }
}

int main() {
    int n,m,x1,y1,x2,y2,width;
    int print = 0;
    string shape,d;

    //create panel
    Panel panel;
    
    cin >> n >> m;
    panel.n = n;
    panel.m = m;
    
    //initial
    for(int i = 0 ; i < panel.n; i++ ){
        for (int j= 0; j < m; j++){
            panel.array[j][i] = '*';
        }
    }
    
    
    while(cin >> shape){
        //choose shape or EXIT
        if (shape == "EXIT"){
            system("pause");
            exit(1);
        }else if(shape == "S"){
            cin >> width;
            cin >> x1 >> y1;
            print = DrawSquare(panel, x1, y1, width);
        }else if(shape == "T"){
            cin >> width;
            cin >> x1 >> y1;
            cin >> d;
            
            print = DrawTriangle(panel, x1, y1, width, d);
        }else if(shape == "L"){
            cin >> x1 >> y1 >> x2 >> y2;
            print = DrawLine(panel, x1, y1, x2, y2);
        }else{
            cout << "Can't draw any shape." << endl;
        }
        
        //print shape
        if (print){
            for(int k = 0 ; k < panel.n; k++ ){
                for (int p= 0; p < m; p++){
                    cout << panel.array[p][k];
                }
                cout << endl;
            }
        }else{
            cout << "Out of range." <<endl;
        }
        cout << endl;
    }
    return 0;
}
