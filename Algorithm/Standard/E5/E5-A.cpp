#include <bits/stdc++.h>
#define maxn 300086

using namespace std; 

const double pi = acos(-1);

struct Complex{
	double x, y;
	Complex(double xx = 0, double yy = 0){
		x = xx, y = yy;
	}
};

Complex operator + (Complex a, Complex b){
	return Complex(a.x + b.x, a.y + b.y);
}

Complex operator - (Complex a, Complex b){
	return Complex(a.x - b.x, a.y - b.y);
}

Complex operator * (Complex a, Complex b){
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

int pos[maxn];

void FFT(Complex *a, int lim, int type){
	for(int i = 0;i < lim;i++) if(i < pos[i]) swap(a[i], a[pos[i]]);
	for(int mid = 1;mid < lim;mid <<= 1){
		Complex wn(cos(pi / mid), type * sin(pi / mid));
		for(int i = mid << 1, j = 0;j < lim;j += i){ 
			Complex w(1, 0);
			for(int k = 0;k < mid;k++, w = w * wn){
				Complex x = a[j + k], y = w * a[j + k + mid];
				a[j + k] = x + y;
				a[j + k + mid] = x - y;
			} 
		}
	}
	if(type == -1) for(int i = 0;i < lim;i++) a[i].x /= lim;
} 

int t;
Complex a[maxn], b[maxn];
char s[maxn];
int n, m;
int ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		n = strlen(s);
		for(int i = 0;i < n;i++) a[n - i - 1].x = s[i] - '0';
		scanf("%s", s);
		m = strlen(s);
		for(int i = 0;i < m;i++) b[m - i - 1].x = s[i] - '0';
		int lim = 1;
		while(lim <= n + m - 2) lim <<= 1;
		for(int i = 0;i < lim;i++) pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);
		FFT(a, lim, 1), FFT(b, lim, 1);
		for(int i = 0;i < lim;i++) a[i] = a[i] * b[i];
		FFT(a, lim, -1);
		for(int i = 0;i < maxn;i++) ans[i] = 0;
		for(int i = 0;i < lim;i++){
			ans[i] = (int)(a[i].x + 0.5);
			a[i] = b[i] = {0, 0};
		}
		for(int i = 0;i + 1 < maxn;i++){
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		bool tag = false;
		for(int i = maxn - 1;~i;i--){
			if(ans[i]) tag = true;
			if(!ans[i] && !tag) continue;
			printf("%d", ans[i]);
		}
		puts("");
	}
}
