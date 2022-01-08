#include <stdio.h>
#define mod 10007
 
int main(void){
    int N;
    int number[1001][10] = {};
    int total = 0;
 
    scanf("%d", &N);
 
    for (int i = 0; i < 10; i++)
        number[1][i] = 1;
 
    for (int i = 2; i <= N; i++)
        for (int j = 0; j < 10; j++)
            for (int k = j; k < 10; k++)
                number[i][j] = (number[i][j] + number[i - 1][k]) % mod;
 
    for (int i = 0; i < 10; i++)
        total = (total + number[N][i]) % mod;
 
    printf("%d\n", total);
 
    return 0;
}
