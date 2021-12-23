#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;

    while(getline(cin, str)){
        int s = str.size();
        int *ans = new int[4]();

        for(int i=0; i<s; i++){
            if(str[i] >= 'a' && str[i] <= 'z')
                ans[0]++;
            else if(str[i] >= 'A' && str[i] <= 'Z')
                ans[1]++;
            else if(str[i] >= '0' && str[i] <= '9')
                ans[2]++;
            else if(str[i] == ' ')
                ans[3]++;
        }

        //소문자, 대문자, 숫자, 공백의 개수를 공백으로 구분해 출력
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
    }

}