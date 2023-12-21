#include <iostream>
using namespace std;

int main(void){
    int n=0, m=0, i=0, j=0, k=0;
    cin >> n >> m;
    int* arr = new int[n];
    for(int a =0; a < n; a++){
        arr[a] = 0;
    }
    for(int a = 0; a < m; a++){
        cin >> i >> j >> k;
        for(int index=i-1; index <= j-1; index++){
            arr[index] = k; 
        }
    }
    for(int a= 0; a < n; a++){
        cout << arr[a] <<" ";
    }


}