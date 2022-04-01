/** ==================================================
* @fileName: bestAlbum.cpp
* @author: rojae 
* @date: 2022.04.02
* @description: https://programmers.co.kr/learn/courses/30/lessons/42579
==================================================**/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> ans;            
    map<string, int> music;                  // 각 장르별로 횟수 저장
    map<string, map<int, int>> musicList;    // 각 장르별로 무슨 노래가 몇번씩 저장되었는지

    for(int i=0; i<genres.size(); i++){
        music[genres[i]] += plays[i];       // 장르별로 횟수 추가
        musicList[genres[i]][i] = plays[i];
    }

    while(music.size() > 0){
        string genre{};
        int max{0};

        // 장르 중에서 제일 높은 것 찾기
        for(auto mu : music){
            if(max < mu.second){
                max = mu.second;
                genre = mu.first;
            }
        }

        // 2곡을 넣어야 하기 때문에 2번 반복
        for(int i=0; i<2; i++){
            int val=0, ind=-1;
            
            for(auto ml : musicList[genre]){
                if(val < ml.second){
                    val = ml.second;
                    ind = ml.first;
                }
            }

            if(ind == -1)
                break;
            ans.push_back(ind);
            musicList[genre].erase(ind);
        }
        music.erase(genre);
    }

    return ans;
}

int main(){
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    vector<int> ans = solution(genres, plays);

    for(int one : ans)
        cout << one << ' ';
    
    return 0;
}