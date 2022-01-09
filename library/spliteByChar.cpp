/*
 * ==================================================
 * FileName : spliteByChar.cpp
 * Subject : Splited By Charactor
 * author : rojae
 *
 * description 
 * AAA,BBB,CCC => splited[3]
 * splited[0] = AAA
 * splited[1] = BBB
 * splited[2] = CCC
 * ==================================================
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

int main() {
 
    string str="AAA,BBB,CCC,DDD,EEE,FFF,GGG";
 
    vector<string> result = split(str, ',');
 
    for (int i = 0; i < result.size(); i++) {
        cout << "Index[" << i << "] : " << result[i] << "\n";
    }
}
