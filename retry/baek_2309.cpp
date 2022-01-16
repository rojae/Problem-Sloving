#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a[9], sum=0;
    vector<int> ans;

    for(int i=0; i<9; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if( sum - (a[i] + a[j]) == 100){
                for(int l=0; l<9; l++){
                    if(l==i || l==j)
                        continue;
                    else
                        ans.push_back(a[l]);
                }
                sort(ans.begin(), ans.end());
                
                for(int i=0; i<ans.size(); i++)
                    cout << ans.at(i) << '\n';

                return 0;
            }
        }
    }
}