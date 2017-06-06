#include<iostream>
#include<map>
#include<limits.h>
#include<ctime>

using namespace std;

class matrix{
public:
int r,c;

public:
    matrix(int row, int col){
       r = row;
       c = col;
    }

};

map<int,matrix*> matrices;
static int table[4][4];

int matrix_chain(int b, int e){

      if(b==e){
         return 0;
      } 

       int min = INT_MAX; 
       int value = 0;
       int value1 = 0; 
       for(int j=b+1; j<=e; j++){
          
          if(table[b][j-1] > 0 && table[j][e] > 0){
            value = table[b][j-1] + table[j][e] + ( matrices[b] -> r * matrices[j-1] -> c * matrices[e] -> c );
          }

          else if(table[b][j-1] > 0){
            value1 = matrix_chain(j,e) ;
            value = table[b][j-1] + value1 + ( matrices[b] -> r * matrices[j-1] -> c * matrices[e] -> c );
            table[j][e] = value1;
          }

          else if(table[j][e] > 0){
            value1 = matrix_chain(b,j-1);
            value = value1 + table[j][e] + ( matrices[b] -> r * matrices[j-1] -> c * matrices[e] -> c );
            table[b][j-1] = value1;
          }

          else{
            value = matrix_chain(b,j-1) + matrix_chain(j,e) + ( matrices[b] -> r * matrices[j-1] -> c * matrices[e] -> c );  
          }

          cout << b << " " << j-1 << ", " << j << " " << e << " -> " << value << "\n"; 

          if(value < min){
            min = value;
          } 

      }
      return min;
}   

int main(){

    int l = 1,b = 0, e = 3, n = 4;

    /*matrix m1(40,20);
    matrix m2(20,30);
    matrix m3(30,10);
    matrix m4(10,30); */

    matrix m1(2,3);
    matrix m2(3,6);
    matrix m3(6,4);
    matrix m4(4,5); 

    matrices[0] = &m1;
    matrices[1] = &m2;
    matrices[2] = &m3;
    matrices[3] = &m4;


    int start_s=clock();
  
    cout << matrix_chain(b,e) <<"\n";

    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

  return 0;
}

