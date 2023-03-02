#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e100
#define eps 1e-8
//用于浮点数正负判断，根据题目精度修改
const double pi = acos(-1.0);//圆周率
long long sgn(long long x) {
	if(fabs(x)<eps)return 0;
	if(x<0)return -1;
	return 1;
}//判断浮点数正负
long long sqr(long long x) {
	return x*x;   //距离等运算涉及大量平方，简便
}
//使用Point时注意部分函数是返回新Point而非修改本身值
struct Point {
	long long x,y;
	/*构造函数*/
	Point() {}
	Point(long long xx,long long yy) {
		x=xx;
		y=yy;
	}
	/*重载一些点的基础运算符*/
	bool operator == (Point b)const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	bool operator < (Point b)const {
		return sgn(x-b.x)== 0?sgn(y-b.y)<0:x<b.x;
	}
	Point operator -(const Point &b)const {
		return Point(x-b.x,y-b.y);
	}
	Point operator +(const Point &b)const {
		return Point(x+b.x,y+b.y);
	}
	Point operator *(const long long &k)const {
		return Point(x*k,y*k);
	}
	Point operator /(const long long &k)const {
		return Point(x/k,y/k);
	}
	//叉积
	long long operator ^(const Point &b)const {
		return x*b.y - y*b.x;
	}
	//点积
	long long operator *(const Point &b)const {
		return x*b.x + y*b.y;
	}
	/*当前点为p，求角apb大小*/
	long long rad(Point a,Point b) {
		Point p = *this;
		return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
	}
	/*逆时针旋转90度*/
	Point rotleft() {
		return Point(-y,x);
	}
	/*顺时针旋转90度*/
	Point rotright() {
		return Point(y,-x);
	}
	//两点距离
	long long dis(Point p) {
		return sqrt(sqr(x-p.x)+sqr(y-p.y));
	}
	long long dis2(Point p) {
		return sqr(x-p.x)+sqr(y-p.y);
	}
	//原点距离
	long long abs() {
		return sqrt(abs2());
	}
	long long abs2() {
		return sqr(x)+sqr(y);
	}
	//改变向量长度
	Point trunc(long long r) {
		long long l = abs();
		if(!sgn(l))return *this;
		r /= l;
		return Point(x*r,y*r);
	}
	//单位化
	Point unit() {
		return *this/abs();
	}
	//IO
	void input() {
		scanf("%lld%lld",&x,&y);
	}
	void output() {
		printf("%lld %lld\n",x,y);
	}
	//绕着p点逆时针旋转angle
	Point rotate(Point p,long long angle) {
		Point v = (*this) - p;
		long long c = cos(angle), s = sin(angle);
		return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
	}
};

//多边形面积，需保证A逆时针
long long area(vector<Point> A) {
	long long ans = 0;
	for (int i = 0; i < A.size(); i++) ans += (A[i]^A[(i + 1) % A.size()]);
	return ans / 2;
}

long long n,cnt;
vector<Point> p;
int main() {
	//freopen("2.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		p.clear();
		p.resize(n);
		for(int i = 0; i<n; i++) {
			p[i].input();
		}
		printf("%lld\n",-area(p));
	}
}
