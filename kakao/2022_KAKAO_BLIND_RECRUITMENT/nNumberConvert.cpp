/** ==================================================
* @fileName: nNumberConvert.cpp
* @author: rojae 
* @date: 2022.04.03
* @description: https://programmers.co.kr/learn/courses/30/lessons/92335
==================================================**/
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
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

bool isPrime(long long n){
    if(n == 0) 
        return false;
    if(n == 1) 
        return false;
    
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0) 
            return false;
    }
    
    return true;
}

vector<string> split(string s, string delimiter)
{
    vector<string> rtn;
    size_t pos = 0;
    string token;

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        rtn.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    rtn.push_back(s);

	return rtn;
}

int solution(int n, int k) {
    int ans = 0;

    // STEP 1 : 진법 변환
    string convertNumber = convertToN(n, k);

    // STEP 2 : '0'으로 문자열 나누기
    vector<string> splited = split(convertNumber, "0");

    // STEP 3 : 소수 검사    
    for(string one : splited){
        if(one != ""){
            long long num = stoll(one);
            if(isPrime(num))
                ans++;
        }
    }

    return ans;
}

int main(){
    int n = 110011;
    int k = 10;

    cout << solution(n, k);
        
    return 0;
}