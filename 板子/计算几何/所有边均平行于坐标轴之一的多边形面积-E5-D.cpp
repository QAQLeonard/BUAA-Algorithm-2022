#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e100
#define eps 1e-8
//���ڸ����������жϣ�������Ŀ�����޸�
const double pi = acos(-1.0);//Բ����
long long sgn(long long x) {
	if(fabs(x)<eps)return 0;
	if(x<0)return -1;
	return 1;
}//�жϸ���������
long long sqr(long long x) {
	return x*x;   //����������漰����ƽ�������
}
//ʹ��Pointʱע�ⲿ�ֺ����Ƿ�����Point�����޸ı���ֵ
struct Point {
	long long x,y;
	/*���캯��*/
	Point() {}
	Point(long long xx,long long yy) {
		x=xx;
		y=yy;
	}
	/*����һЩ��Ļ��������*/
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
	//���
	long long operator ^(const Point &b)const {
		return x*b.y - y*b.x;
	}
	//���
	long long operator *(const Point &b)const {
		return x*b.x + y*b.y;
	}
	/*��ǰ��Ϊp�����apb��С*/
	long long rad(Point a,Point b) {
		Point p = *this;
		return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
	}
	/*��ʱ����ת90��*/
	Point rotleft() {
		return Point(-y,x);
	}
	/*˳ʱ����ת90��*/
	Point rotright() {
		return Point(y,-x);
	}
	//�������
	long long dis(Point p) {
		return sqrt(sqr(x-p.x)+sqr(y-p.y));
	}
	long long dis2(Point p) {
		return sqr(x-p.x)+sqr(y-p.y);
	}
	//ԭ�����
	long long abs() {
		return sqrt(abs2());
	}
	long long abs2() {
		return sqr(x)+sqr(y);
	}
	//�ı���������
	Point trunc(long long r) {
		long long l = abs();
		if(!sgn(l))return *this;
		r /= l;
		return Point(x*r,y*r);
	}
	//��λ��
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
	//����p����ʱ����תangle
	Point rotate(Point p,long long angle) {
		Point v = (*this) - p;
		long long c = cos(angle), s = sin(angle);
		return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
	}
};

//�����������豣֤A��ʱ��
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
