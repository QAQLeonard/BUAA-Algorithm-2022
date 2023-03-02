#include<bits/stdc++.h>
using namespace std;
const int N = 2000;
int a[N];
const double eps = 1e-8;
const double Pi = acos(-1.0);
int dcmp(const double x) {
	if(fabs(x)<=eps)return 0;
	return x>0?1:-1;
}
struct Point {
	double x,y;
	Point() {}
	Point(double x,double y):x(x),y(y) {}
	Point operator + (const Point&a)const {
		return Point(x+a.x,y+a.y);
	}
	Point operator - (const Point&a)const {
		return Point(x-a.x,y-a.y);
	}
	Point operator * (const double&a)const {
		return Point(x*a,y*a);
	}
	Point operator / (const double&a)const {
		return Point(x/a,y/a);
	}
	double operator * (const Point&a)const {
		return x*a.x+y*a.y;
	}
	double operator ^ (const Point&a)const {
		return x*a.y-y*a.x;
	}
	bool operator < (const Point&a)const {
		return (x!=a.x)?x<a.x:y<a.y;
	}
	bool operator == (const Point&a)const {
		return !dcmp(x-a.x)&&!dcmp(y-a.y);
	}
} p[N],s[N];
typedef Point Vector;
double lth(const Vector a) {
	return sqrt(a*a);
}
double S_(const Point a,const Point b,const Point c) {
	return ((b-a)^(c-a))/2;
}
int build(int n,Point *p,Point *s) {
	sort(p,p+n);
	int m = 0;
	for(int i = 0; i < n; i++) {
		while(m>1&&((s[m]-s[m-1])^(p[i]-s[m-1]))<=0)m--;
		s[++m] = p[i];
	}
	int lim = m;
	for(int i = n-2; i >= 0; i--) {
		while(m>lim&&((s[m]-s[m-1])^(p[i]-s[m-1]))<=0)m--;
		s[++m] = p[i];
	}
	if(m!=1)m--;
	return m;
}
int main() {
	int t=1,n;
	long long x1,y1,x2,y2,x3,y3;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		int m=build(n,p,s);
		s[0]=s[m];
		double ans=0;
		for(int i=1; i<=m; i++) {
			ans+=lth(s[i]-s[i-1]);
		}
		printf("%.10lf",ans);

	}
}
