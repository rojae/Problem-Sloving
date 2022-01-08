#include <iostream>

using namespace std;

int gcd(int x, int y){
    if(y == 0)
        return x;
    else 
        return gcd(y, x%y);
}

int lms(int a, int b, int g){
    return g * (a/g) * (b/g);
}

int main(){
    int A, B, g;
    cin >> A >> B;
    g = gcd(A, B);

    cout << g << endl;
    cout << lms(A, B, g);
}