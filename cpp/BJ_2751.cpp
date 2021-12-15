#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

void bubbleSort(int *, int);
int main(){
	int n, *list;
	scanf("%d",&n);
	list = (int *)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++)
		scanf("%d",	&(*(list+i)));
	sort(list,list+n);
	for(int i = 0; i < n; i++)
		printf("%d\n",*(list+i));
}
