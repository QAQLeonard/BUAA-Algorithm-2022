#include<bits/stdc++.h>
using namespace std;
#define ll long long
int sgn(ll x) {
	if(x==0)return 0;
	return x<0?-1:1;
}
struct Point {
	ll x,y;
	Point() {}
	Point(ll xx,ll yy) {
		x=xx;
		y=yy;
	}
	void input() {
		scanf("%lld %lld",&x,&y);
	}
	bool operator ==(const Point &p)const {
		return sgn(x-p.x)==0&&sgn(y-p.y)==0;
	}
	bool operator !=(const Point &p)const {
		return sgn(x-p.x)!=0||sgn(y-p.y)!=0;
	}
	bool operator < (const Point &p)const {
		return sgn(x-p.x)<0||(sgn(x-p.x)==0&&sgn(y-p.y)<0);
	}
	Point operator + (const Point &p)const {
		return {x+p.x,y+p.y};
	}
	Point operator - (const Point &p)const {
		return {x-p.x,y-p.y};
	}
	Point operator * (ll k)const {
		return {x*k,y*k};
	}
	Point operator / (const ll &k)const {
		return {x/k,y/k};
	}
	ll dot(Point p) const {
		return p.x*x+p.y*y;
	}
	ll cross(Point p) const {
		return x * p.y - y * p.x;
	}
};
ll cross(Point p1,Point p2,Point p3) {
	return (p2-p1).cross(p3-p1);
}
ll dot(Point p1,Point p2,Point p3) {
	return (p2-p1).dot(p3-p1);
}
struct Frac {
	ll a,b;
	Frac() {}
	Frac(ll aa,ll bb) {
		if(aa!=0&&bb!=0) {
			ll g=__gcd(abs(aa),abs(bb));
			a=aa/g;
			b=bb/g;
		}
		if(aa==0&&bb!=0) {
			a=0;
			b=bb/abs(bb);
		}
		if(aa!=0&&bb==0) {
			b=0;
			a=aa/abs(aa);
		}
	}
};
map<pair<ll,ll>,int> mp;
vector<Point> ps;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		ps.clear();
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			Point tmp;
			tmp.input();
			ps.push_back(tmp);
		}
		int q;
		scanf("%d",&q);
		while(q--) {
			Point p;
			p.input();
			mp.clear();
			for(auto i:ps) {
				Frac f=Frac(i.x-p.x,i.y-p.y);
				mp[ {f.a,f.b}]++;
			}
			ll ans=0;
			for(auto i:ps) {
				Frac f=Frac(i.x-p.x,i.y-p.y);
				int sz=mp[ {-f.a,-f.b}]+mp[ {f.a,f.b}];
				if(sz>=2)ans=ans+sz/2;
				mp[ {-f.a,-f.b}]=0;
				mp[ {f.a,f.b}]=0;
			}
			printf("%lld\n",ans);
		}
	}
}
