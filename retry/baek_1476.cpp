#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int ie,is,im;
    int ans = 0;
    int e=0,s=0,m=0;
    cin >> ie >> is >> im;

    while(true){

        if(e==16)
            e=1;
        if(s==29)
            s=1;
        if(m==20)
            m=1;
        if(e==ie && s==is && m==im){
            cout << ans;
            break;
        }
        
        e++; s++; m++;
        ans++;
    }

    return 0;
}