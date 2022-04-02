#include <iostream>
#include <cmath>

// Sieve of Eratosthenes
using namespace std;

// 단순 소수 구하는 법
bool isPrime(long long n){
    if(n == 0) 
        return false;
    if(n == 1) 
        return false;
    
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0) 
            return false;
    }
    
    return true;
}

int main(){
    cout << "2는 소수일까? : " << isPrime(2) << '\n';

    // 아래는 아리토스테네스의 체이다
    int begin, end;
    scanf("%d",&begin);
    scanf("%d",&end);
 
    // 소수이면 false
    // 소수가 아니면 true이다    
    bool *c = new bool[end+1];
    c[1] = true;
    for(int i = 2; i*i<= end; i++){
        if(c[i] == false){
            for(int j = i * i; j <= end; j+=i){
                c[j] = true;
            }
        }
    }
    for(int i = begin; i <= end; i++)
        if(c[i] == false)
            printf("%d\n",i);
    return 0;
}

