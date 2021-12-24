#include <iostream>
#include <string>

using namespace std;

int* split3(string str){
    int s = str.size();

    int len = (s/3) + ((s%3 > 0)? 1 : 0);
    int *res = new int[len]();

    for(int i=s-1, j=0; i>=0; i-=3, j++){
        if(str[i] == '0' || str[i] == '1')
            res[j] += (str[i] - '0');
        if(str[i-1] == '0' || str[i-1] == '1')
            res[j] += (str[i-1] - '0') * 2;
        if(str[i-2] == '0' || str[i-2] == '1')
            res[j] += (str[i-2] - '0') * 4;
    }

    return res;
}

int main(){
    string in;
    cin >> in;

    int *ans = split3(in);
    int s = in.size();
    int len = (s/3) + ((s%3 > 0)? 1 : 0);

    for(int i=len-1; i>=0; i--)
        cout << ans[i];

}