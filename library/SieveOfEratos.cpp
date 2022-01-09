/*
* ==================================================
* FileName : SieveOfEratos.cpp
* Subject : 에라토스테네스의 체 (소수구하기)
* author : rojae
* 
* description 
* 소수의 배수는 소수가 아니다.
* ==================================================
*/

#include <iostream>

using namespace std;

int SIZE = 10;


void sieveOfEratos(bool *arr){
    arr[0] = arr[1] = true;

    for(int i=2; i<=SIZE; i++){
        // i가 소수라면
        if(arr[i] == false){
            for(int j=i*i; j<=SIZE; j+=i){
                arr[j] = true;
            }
        }
    }
}

int main(){

    bool *arr = new bool[SIZE + 1];

    sieveOfEratos(arr);

    cout << "=== " << SIZE << "까지 소수 ===" << '\n';

    for(int i=1; i<=SIZE; i++){
        if(!arr[i]) // 소수라면 
            cout << i << '\n';
    }

    return 0;
}