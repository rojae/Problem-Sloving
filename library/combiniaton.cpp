#include <iostream>
#include <algorithm>

using namespace std;

bool asc(int a, int b){
    return a < b;
}

// nCr
int main(){
    int s = 9;
    int *a = new int[s];
    int *idx = new int[s];
    int choice = 6;

    for(int i=1; i<=s; i++)
        a[i] = i;

    for(int i=0; i<choice; i++)
        idx[i] = 1;
    
    for(int i=choice; i<s; i++)
        idx[i] = 0;
    
    sort(idx, idx+s, asc);

    do{
        for(int i=0; i<s; i++){
            if(idx[i] == 1)
                cout << a[i] << ' ';
        }

        cout << '\n';

    }while(next_permutation(idx, idx+s, asc));

    return 0;
}