#include <iostream>

using namespace std;

int gcd(int x, int y){
    if(y == 0)  return x;
    else    return gcd(y, x%y);
}

int lms(int x, int y, int g){
    return g * (x/g) * (y/g);
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int x, y, g;
        cin >> x >> y;
        g = gcd(x,y);
        cout << lms(x,y,g) << endl;
    }

}