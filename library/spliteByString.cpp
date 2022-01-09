/*
* ==================================================
* FileName : spliteByString.cpp
* Subject : String Splited By String
* author : rojae
*
* description 
* "chicken and pizza and ramen" -> splited[3] (delimiter : " and ")
* splited[0] = chicken
* splited[1] = pizza
* splited[2] = ramen
* ==================================================
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s, string delimiter)
{
    vector<string> rtn;
    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        rtn.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    rtn.push_back(s);

	return rtn;
}

int main(){
    string s = "chicken and pizza and ramen";
    vector<string> splited = split(s, " and ");

    for(int i=0; i<splited.size(); i++)
        cout << "Index[" << i << "] : " << splited.at(i) << '\n';

    return 0;
}