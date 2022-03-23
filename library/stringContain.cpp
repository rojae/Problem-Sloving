#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1 = "hello! C wor";
    string s2 = "world";

    if ( s1.find(s2) != string::npos) {
        cout << "found!" << '\n';
    }
    else{
        cout << "not found" << '\n';
    }

}