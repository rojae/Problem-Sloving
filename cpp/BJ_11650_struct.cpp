#include<iostream>
#include<algorithm>

typedef struct point{
	int x,y;
} point;

bool compare(point const& a, point const& b){
	if(a.x < b.x)	return true;
	else if(a.x == b.x)	return a.y < b.y;
	else	return false;
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	point *p = new point[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d %d",&p[i].x,&p[i].y);
	}
	std::sort(p,p+n,compare);
	for(int i = 0; i < n; i++)
		printf("%d %d\n",p[i].x,p[i].y);
	delete p;
	return 0;
}
