#include<bits/stdc++.h>
using namespace std;
#define inf 1e100
#define ll long long
#define eps 1e-8
//���ڸ����������жϣ�������Ŀ�����޸�
const double pi = acos(-1.0);//Բ����
int sgn(ll x) {
    if(x==0)return 0;
    return x<0?-1:1;
}
//ʹ��Pointʱע�ⲿ�ֺ����Ƿ�����Point�����޸ı���ֵ
struct Point {
    ll x,y;
    /*���캯��*/
    Point() {}
    Point(ll xx,ll yy) {
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
    //���
    ll operator ^(const Point &b)const {
        return x*b.y - y*b.x;
    }
    //���
    ll operator *(const Point &b)const {
        return x*b.x + y*b.y;
    }

    void input() {
        scanf("%lld%lld",&x,&y);
    }
};
struct Line {
    //����ȷ��ֱ��
    Point s,e;
    Line() {}
    Line(Point ss,Point ee) {
        s=ss;
        e=ee;
    }
    void input() {
        s.input();
        e.input();
    }
    //�����߶���
    bool checkPS(Point p) {
        return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <= 0;
    }
    //ֱ��ƽ��
    bool parallel(Line v) {
        return sgn((e-s)^(v.e-v.s)) == 0;
    }
    //���ֱ�߹�ϵ
    //1  �����
    //2  ���Ҳ�
    //3  ��ֱ����
    int relation(Point p) {
        int c = sgn((p-s)^(e-s));
        if(c < 0)return 1;
        else if(c > 0)return 2;
        else return 3;
    }
    //�߶��ཻ
    //2 �淶�ཻ
    //1 �ǹ淶�ཻ
    //0 ���ཻ
    int checkSS(Line v) {
        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        int d3 = sgn((v.e-v.s)^(s-v.s));
        int d4 = sgn((v.e-v.s)^(e-v.s));
        if( (d1^d2)==-2 && (d3^d4)==-2 )return 2;
        return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) ||
               (d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
               (d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
               (d4==0 && sgn((e-v.s)*(e-v.e))<=0);
    }
    //ֱ�ߺ��߶��ཻ
    //2 �淶�ཻ
    //1 �ǹ淶�ཻ
    //0 ���ཻ
    int checkLS(Line v) {
        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        if((d1^d2)==-2) return 2;
        return (d1==0||d2==0);
    }
    //��ֱ�߹�ϵ
    //0 ƽ��
    //1 �غ�
    //2 �ཻ
    int checkLL(Line v) {
        if((*this).parallel(v))
            return v.relation(s)==3;
        return 2;
    }
};


int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int type1,type2,xs,ys,xe,ye;
        Line l1, l2;
        scanf("%d%d%d%d%d",&type1,&xs,&ys,&xe,&ye);
        l1 = Line(Point(xs,ys),Point(xe,ye));
        scanf("%d%d%d%d%d",&type2,&xs,&ys,&xe,&ye);
        l2 = Line(Point(xs,ys),Point(xe,ye));
        if(type1 == 1 && type2 == 1) {
            if(l1.checkLL(l2) == 0) {
                puts("Parallel");
            } else if(l1.checkLL(l2) == 1) {
                puts("Coincide");
            } else {
                puts("Intersect");
            }
        }
        else if(type1 == 1) {
            if(l1.checkLS(l2) == 2) {
                puts("Strict");
            } else if(l1.checkLS(l2) == 1) {
                puts("Not strict");
            } else {
                puts("Don't intersect");
            }
        } else if(type2 == 1) {
            if(l2.checkLS(l1) == 2) {
                puts("Strict");
            } else if(l2.checkLS(l1) == 1) {
                puts("Not strict");
            } else {
                puts("Don't intersect");
            }
        } else {
            if(l1.checkSS(l2) == 2) {
                puts("Strict");
            } else if(l1.checkSS(l2) == 1) {
                puts("Not strict");
            } else {
                puts("Don't intersect");
            }
        }
    }
}
