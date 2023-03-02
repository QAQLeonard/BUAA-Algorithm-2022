#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eps 1e-9
int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
//int sgn(ll x){
//    if(x==0)return 0;
//    if(x<0)return -1;
//    return 1;
//}
const double pi=acos(-1.0);
double cmp(double a,double b){return sgn(a-b);}
double sqr(double x){return x*x;}
struct Point{
    double x,y;
    Point(){}
    Point(double xx,double yy){x=xx;y=yy;}
    void input(){scanf("%lf %lf",&x,&y);}
    void output(){printf("%.0f %.0f\n",x,y);}
    bool operator ==(const Point &p)const{return sgn(x-p.x)==0&&sgn(y-p.y)==0;}
    bool operator !=(const Point &p)const{return sgn(x-p.x)!=0||sgn(y-p.y)!=0;}
    bool operator < (const Point &p)const{
        return sgn(x-p.x)<0||(sgn(x-p.x)==0&&sgn(y-p.y)<0);
    }
    Point operator + (const Point &p)const{
        return {x+p.x,y+p.y};
    }
    Point operator - (const Point &p)const{
        return {x-p.x,y-p.y};
    }
    Point operator * (double k)const{
        return {x*k,y*k};
    }
    Point operator / (const double &k)const{
//assert(k!=0);
        return {x/k,y/k};
    }
    double dot(Point p) const{return p.x*x+p.y*y;}
    double cross(Point p) const {return x * p.y - y * p.x;}
    double dis(Point p) const {return sqrt(sqr(x - p.x) + sqr(y - p.y));}
    double abs() const{return sqrt(sqr(x)+sqr(y));}
    double abs2() const{return sqr(x)+sqr(y);}
    Point rot(Point p,double a){
//逆时针旋转
        Point v = (*this) - p;
        double c = cos(a), s = sin(a);
        return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
    }
    Point rotLeft() const{return Point(-y,x);}
    Point rotRight() const{return Point(y,-x);}
    double getW() const{return atan2(y,x);}
    Point unit()const{
        if(sgn(abs())==0)return (*this);
        else return {x/abs(),y/abs()};
    }
    Point trunc(double r)const{Point tmp=unit();return tmp*r;}
};
double cross(Point p1,Point p2,Point p3){
    return (p2-p1).cross(p3-p1);
}
double dot(Point p1,Point p2,Point p3){
    return (p2-p1).dot(p3-p1);
}
struct Line{
    Point s,e;//有向直线
    double ang;
    Line(){}
    Line(Point ss,Point ee){s=ss;e=ee;}
    void input(){s.input();e.input();}
    bool operator ==(const Line &v)const{return s==v.s&&e==v.e;}
    double len(){return (e-s).abs();}
    void calcAng(){ang= atan2(dir().y,dir().x);}
    Point dir(){return e-s;}
    int checkLP(Point p){
/* s e p make a counterclockwise 1
* s e p make a clockwise 2
* p is on a line p s e 3
* p is on a line s e p 4
* p is on a seg s e 5
* error 6 */
        int tmp = sgn(cross(s,p,e));
        if(tmp<0)return 1;
        if(tmp>0)return 2;
        int dt=sgn(dot(p,s,e));
        if(dt<=0)return 5;
        if(sgn(dot(s,p,e))>0)return 4;
        if(sgn(dot(s,p,e))<0)return 3;
        assert(0);
    }
    int checkLL(Line v){
// 3 coincide 2 parallel 1 orthogonal 0 others
        int tmp = sgn((e-s).cross(v.e-v.s));
        if(tmp==0){
            if(v.checkLP(e)>2)return 3;
            return 2;
        }
        if(sgn((e-s).dot(v.e-v.s))==0)return 1;
        return 0;
    }
    int checkSS(Line v){
// 2 not strict 1 strict 0 not ins
        if(checkLP(v.s)==5|| checkLP(v.e)==5)return 2;
        if(v.checkLP(s)==5||v.checkLP(e)==5)return 2;
        int tmp=sgn(cross(s,e,v.s)* cross(s,e,v.e));
        int tmp2=sgn(cross(v.s,v.e,s)* cross(v.s,v.e,e));
        if(tmp<0&&tmp2<0)return 1;
        return 0;
    }
    int checkLS(Line v){//untested 2严格1不严格
        int d1 = sgn((e-s).cross(v.s-s));
        int d2 = sgn((e-s).cross(v.e-s));
        if((d1^d2)==-2) return 2;
        return (d1==0||d2==0);
    }
    Point getLL(Line v){
        double tmp=(s-v.s).cross(v.e-v.s),tmp2=(v.e-v.s).cross(e-v.s);
        return (s*tmp2+e*tmp)/(tmp+tmp2);
    }
    Point proj(Point p){
        return s+(e-s).trunc(dot(s,p,e)/len());
    }
    double disLP(Point p){return p.dis(proj(p));}
    double disSP(Point p){
        if(checkLP(proj(p))!=5)return min(p.dis(s),p.dis(e));
        return disLP(p);
    }
};
bool onSeg(Point p,Point a,Point b){return Line(a,b).checkLP(p)==5;}
struct Circle{
    Point p;
    double r;
    Circle(){}
    Circle(Point pp,double rr){p=pp;r=rr;}
    bool operator == (const Circle &c)const{
        return (p==c.p)&&(sgn(r-c.r)==0);
    }
    Point point(double a){return p+Point(r*cos(a),r*sin(a));}
    void input(){p.input();scanf("%lf",&r);}
    int include(Point q){if(sgn(p.dis(q)-r)==0)return 1;if(sgn(p.dis(q)-r)
                                                           <0)return 2;return 0;}
    int checkCC(Circle c){
//0 内含 1 内切 2 相交 3 外切 4 相离
        double d=c.p.dis(p);
        if(sgn(d-r-c.r)>0)return 4;
        if(sgn(d-r-c.r)==0)return 3;
        if(sgn(d- fabs(r-c.r))==0)return 1;
        if(sgn(d- fabs(r-c.r))<0)return 0;
        return 2;
    }
    int checkCL(Line l){
//2 相交 1相切 0 相离
        if(sgn(l.disLP(p)-r)==0)return 1;
        if(sgn(l.disLP(p)-r)<0)return 2;
        return 0;
    }
    vector<Point> getCL(Line v){
//相切给出两个
        if(checkCL(v)==0)return {};
        vector<Point> tmp;
        double d=v.disLP(p);
        double x=sqrt(r*r-d*d);
        if(sgn(d-r)==0){
            tmp.pb(v.proj(p));
            tmp.pb(v.proj(p));
        }else{
            tmp.pb(v.proj(p)-(v.e-v.s).trunc(x));
            tmp.pb(v.proj(p)+(v.e-v.s).trunc(x));
//和v方向一致
        }
        return tmp;
    }
    double circ(){return 2*pi*r;}
    double area(){return pi*r*r;}
    vector<Point> getCC(Circle c){//沿当前逆时针给出,相切给出两个
        if(checkCC(c)==0|| checkCC(c)==4)return {};
        double b=p.dis(c.p),cosA=(r*r+b*b-c.r*c.r)/(2*r*b);
        double tmp=r*cosA,h=sqrt(r*r-tmp*tmp);
        Point v=(c.p-p).trunc(tmp).rotLeft().trunc(h);
        Point ini=p+(c.p-p).trunc(tmp);
        return {ini-v,ini+v};
    }
};
double polyArea(const vector<Point> &p){
    double ans=0;
    int sz=p.size();
    for(int i=0;i<sz;i++){
        ans+=(p[i].cross(p[(i+1)%sz]));
    }
    return fabs(ans)/2.0;
}
double polyCir(const vector<Point> &p){
    double ans=0;
    int sz=p.size();
    for(int i=0;i<sz;i++){
        ans+=(p[i].dis(p[(i+1)%sz]));
    }
    return ans;
}
bool isConvex(const vector<Point> &p,int flag=0){//0 严格 1 非严格 counterclockwise
    int sz=p.size();
    for(int i=0;i<sz;i++){
        int x=Line(p[i],p[(i+1)%sz]).checkLP(p[(i+2)%sz]);
        if(x!=1){
            if(flag){if(x==2)return false;}
            else return false;
        }
    }
    return true;
}
int contain(vector<Point> ps, Point p){ //2:inside 1:onSeg 0:outside
    int n = ps.size(), ret = 0;
    for(int i=0;i<n;i++){
        Point u=ps[i],v=ps[(i+1)%n];
        if(onSeg(p,u,v)) return 1;
        if(cmp(u.y,v.y)<=0) swap(u,v);
        if(cmp(p.y,u.y) >0 || cmp(p.y,v.y) <= 0) continue;
        ret ^= sgn(cross(p,u,v)) > 0;
    }
    return ret*2;
}
double convexDiameter(vector<Point> ps){
    int n = ps.size(); if(n <= 1) return 0;
    int is = 0, js = 0;
    for(int k=0;k<n;k++)is=ps[k]<ps[is]?k:is, js = ps[js] < ps[k]?k:js;
    int i = is, j = js;
    double ret = ps[i].dis(ps[j]);
    do{
        if((ps[(i+1)%n]-ps[i]).cross(ps[(j+1)%n]-ps[j]) >= 0)
            (++j)%=n;
        else
            (++i)%=n;
        ret = max(ret,ps[i].dis(ps[j]));
    }while(i!=is || j!=js);
    return ret;
}
vector<Point> convexHull(vector<Point>A, int flag = 1) { // flag=0 不严格 flag=1 严格
    int n = A.size(); vector<Point>ans(n * 2);
    if(n==1)return A;
    sort(A.begin(), A.end()); int now = -1;
    for (int i = 0; i < A.size(); i++) {
        while (now > 0 && sgn(cross(ans[now-1],ans[now],A[i]))<flag)now--;
        ans[++now] = A[i];
    } int pre = now;
    for (int i = n - 2; i >= 0; i--) {
        while (now > pre && sgn(cross(ans[now-1],ans[now],A[i]))<flag)now--;
        ans[++now] = A[i];
    } ans.resize(now); return ans;
}
vector<Point> norm(vector<Point> p,Point q){//极角排序
    sort(p.begin(),p.end(),[&](Point a,Point b){
        int d = sgn((a-q).cross(b-q));
        if(d == 0){
            return sgn(a.dis(q)-b.dis(q)) < 0;
        }
        return d > 0;
    });
    return p;
}
vector<Point> graHam(vector<Point> ps){
    auto mi=ps[0];
    for(auto i:ps)mi=min(mi,i);
    ps = norm(ps,mi);
    int n=ps.size();
    vector<Point> ans(n*2);
    int top = 0;
    if(n == 1){
        top = 1;
        ans[0] = ps[0];
    }else if(n == 2){
        top = 2;
        ans[0] = ps[0];
        ans[1] = ps[1];
        if(ans[0] == ans[1])top--;
    }else{
        ans[0] = ps[0];
        ans[1] = ps[1];
        top = 2;
        for (int i = 2; i < n; i++) {
            while (top > 1 &&
                   sgn((ans[top-1]-ans[top - 2]).cross(ps[i]-ans[top-2]))<=0)
                top--;
            ans[top++] = ps[i];
        }
        if (top== 2 && (ans[0] == ans[1]))top--;
    }
    ans.resize(top);return ans;
}
int main(){
}