#include <iostream> 
using namespace std; 
int main(){ 
   int T; 
   cin >>T; 
   for(int i = 0; i < T; i++){ 
      int a,b; 
      cin >> a; 
      cin >> b; 
      int person[15][15]; 
      for(int i = 0; i < 15; i++){  //모두 0으로 초기화.. 
         for(int j = 0; j < 15; j++){ 
            person[i][j] = 0; 
         } 
      } 
      for(int i = 0; i < 15; i++){  //0층과 1번호 세팅 
         person[0][i] = i; 
         person[i][1] = 1; 
      } 
      for(int i = 1; i <15; i++){ 
         for(int j =2; j < 15; j++){ 
            for(int k=1;k<=j;k++){  //아래층의 현재호까지 합을 더하기.. 
               person[i][j] += person[i-1][k]; 
            } 
         } 
      } 
      cout << person[a][b] << endl; 
   }  
   return 0; 
} 