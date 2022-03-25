/** ==================================================
* @fileName: wordConvert.cpp
* @author: rojae 
* @date: 2022.03.26
* @description: https://programmers.co.kr/learn/courses/30/lessons/43163
==================================================**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
int ans = 1e9;

int solution(string begin, string target, vector<string> words);
void dfs(string begin, string target, vector<string> words, int cnt);
bool visit[50] = {false,};

int main(){
    // Don't use the below code with scanf
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string begin = "hit";
    string target =	"cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << solution(begin, target, words);
    return 0;
}

void dfs(string begin, string target, vector<string> words, int cnt){
    if(begin == target){
        ans = (ans > cnt)? cnt : ans;
        return;
    }
    for(int i=0; i<words.size(); i++){
        int notSameCount = 0;

        for(int j=0; j<begin.length(); j++){
            if(begin[j] != words[i][j])
                notSameCount++;   
            if(j == begin.length()-1 && notSameCount == 1 && !visit[i]){
                visit[i] = true;
                dfs(words[i], target, words, cnt+1);
                visit[i] = false;
            }
        }    
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    return (ans == 1e9)? 0 : ans;
}