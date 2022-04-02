#include <iostream>
#include <algorithm>

using namespace std;

string convertToN(int n, int k){
    string str = "";
    string changeNumber = "";
    int now = n;

    while(now > 0){
        if(now % k < 10)
            str += (char) (now % k) + '0';
        else
            str += (char)(now % k - 10 + 'A');
        now /= k;
    }
    
    reverse(str.begin(), str.end());
    changeNumber = str;

    return changeNumber;
}

int main(){
    int n = 437674;
    int k = 3;
    cout << convertToN(n, k);
    return 0;
}