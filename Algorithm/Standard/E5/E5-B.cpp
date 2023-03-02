#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=200005;
const double eps=1e-7;
int getint(){
    char c;int flag=0,num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag?-num:num;
}
double getdb(){double x;scanf("%lf",&x);return x;}
inline int sgn(double x){return (x>eps)-(x<-eps);}
inline double sqr(double x){return x*x;}
struct Point{
    double x,y;
    Point operator + (const Point&b)const{
        return (Point){x+b.x,y+b.y};
    }
    Point operator - (const Point&b)const{
        return (Point){x-b.x,y-b.y};
    }
    double operator * (const Point&b)const{
        return x*b.x+y*b.y;
    }
    double operator ^ (const Point&b)const{
        return x*b.y-y*b.x;
    }
    double dis(Point b){
        return sqrt(sqr(x-b.x)+sqr(y-b.y));
    }
};
vector<Point> p,ans;
bool cmpx(Point a,Point b){
    return sgn(a.x-b.x)==0 ? a.y<b.y : a.x<b.x;
}
vector<Point> ConvexHull(vector<Point> A,int flag){
    int n=A.size(),now=-1;
    vector<Point> ans(n<<1);
    sort(A.begin(),A.end(),cmpx);
    for(int i=0;i<n;i++){
        while(now>0 && sgn((ans[now]-ans[now-1])^(A[i]-ans[now-1]))<flag) now--;
        ans[++now]=A[i];
    }
    int pre=now;
    for(int i=n-2;i>=0;i--){
        while(now>pre && sgn((ans[now]-ans[now-1])^(A[i]-ans[now-1]))<flag) now--;
        ans[++now]=A[i];
    }
    ans.resize(now);return ans;
}
double convexDiameter(vector<Point> A){
    int n=A.size(),now=0;
    double ans=0;
    for(int i=0;i<n;i++){
        now=max(now,i);
        while(1){
            double k1=A[i].dis(A[now%n]),k2=A[i].dis(A[(now+1)%n]);
            ans=max(ans,max(k1,k2));
            if(k2>k1) now++;else break ;
        }
    }
    return ans;
}
int main(){
    int n=getint();
    for(int i=0;i<n;i++){
        double x=getdb(),y=getdb();
        p.push_back((Point){x,y});
    }
    ans=ConvexHull(p,1);
    printf("%.6f\n",convexDiameter(ans));
    return 0;
}
