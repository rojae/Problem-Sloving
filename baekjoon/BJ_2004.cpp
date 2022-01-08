#include <cstdio>
#define min(a,b) a>b?b:a
int num(int a){
    int ans=0;
    while(a){
        ans+=a/5;
        a/=5;
    }
    return ans;
}
 
int num2(int a){
    int ans=0;
    while(a){
        ans+=a/2;
        a/=2;
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d", min(num(n)-num(n-m)-num(m),num2(n)-num2(n-m)-num2(m)));
}
