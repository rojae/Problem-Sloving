#include <iostream>
#include <string>

using namespace std;

int main(){
    string A,B,C,D;
    string AB, CD;

    cin >> A >> B >> C >> D;

    AB = A+B;
    CD = C+D;

    long a = stol(AB);
    long b = stol(CD);

    cout << a+b;


}