#include<iostream>

using namespace std;
int main(){
	int max = 0, score[1000] = {0, }, i, j, n;
	double sum = 0.0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &score[i]);
		max < score[i] ? (max = score[i]) : max;
	}
	for(i = 0; i < n; i++){
		sum += (double)score[i] / (double)max * 100.0;
	}
	printf("%.2lf", sum / (double)n);
}
