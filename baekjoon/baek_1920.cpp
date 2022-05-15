#include <iostream>
#include <algorithm>

using namespace std;

// 이분 검색 구현
void binarySearch(long long key, long long *a, int len){
    int start=0;
    int end=len-1;
    int mid;

    while(end - start >= 0){
        mid = (start + end) / 2;

        if(a[mid] == key){
            cout << "1\n";
            return;
        }
        else if(a[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    cout << "0\n";
    return;
}

int main(){
    // Don't use the below code with scanf
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int len1, len2;
    cin >> len1;
    long long *a = new long long[len1];
    
    for(int i=0; i<len1; i++)
        cin >> a[i];

    cin >> len2;

    sort(a, a+len1);
    for(int i=0; i<len2; i++){
        long long target;
        cin >> target;
        binarySearch(target, a, len1);
    }

    return 0;
}