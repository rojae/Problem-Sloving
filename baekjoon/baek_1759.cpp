#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l,c;
bool asc(int a, int b){
    return a < b;
}

bool desc(int a, int b){
    return a > b;
}

bool check(vector<char> &a){
    bool mo=false;      // 주의 c++의 초기값은 true이다
    int jaCnt=0;

    for(int i=0; i<a.size(); i++){
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
            mo = true;
        else
            jaCnt++;
    }

    return (mo && jaCnt >= 2);
}

int main(){
    cin >> l >> c;

    char *a = new char[c];
    int *idx = new int[c];

    for(int i=0; i<c; i++)
        cin >> a[i];

    for(int i=0; i<l; i++)
        idx[i] = 1;
    
    for(int i=l; i<c; i++)
        idx[i] = 0;
    
    sort(a, a+c, asc);
    sort(idx, idx+c, desc);

    do{
        vector<char> ans;
        for(int i=0; i<c; i++){
            if(idx[i] == 1)
                ans.push_back(a[i]);
        }

        sort(ans.begin(), ans.end(), asc);

        if(check(ans)){
            for(int i=0; i<ans.size(); i++)
                cout << ans[i];
            cout << '\n';
        }

        ans.clear();
    }while(next_permutation(idx, idx+c, desc));

    
    return 0;
}