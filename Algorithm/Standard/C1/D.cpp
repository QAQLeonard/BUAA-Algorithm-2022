#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define eps 1e-14
#define maxn 300005
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

char s[10], t[10];
int y[2], m[2], d[2]; 
int mx[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int a, int b, int c){
	int s[10], t = 0;
	for(int i = 1; i <= 2; i++) s[++t] = c % 10, c /= 10;
	for(int i = 1; i <= 2; i++) s[++t] = b % 10, b /= 10;
	for(int i = 1; i <= 4; i++) s[++t] = a % 10, a /= 10;
	for(int i = 1; i <= 8; i++){
		bool f = 1;
		for(int j = i + 1; j <= 8; j++) if(s[j] < s[j - 1]) f = 0;
		for(int j = i - 1; j >= 1; j--) if(s[j] < s[j + 1]) f = 0;
		if(f) return 1;
		f = 1;
		for(int j = i + 1; j <= 8; j++) if(s[j] > s[j - 1]) f = 0;
		for(int j = i - 1; j >= 1; j--) if(s[j] > s[j + 1]) f = 0;
		if(f) return 1;
	}
	return 0;
}

bool isleap(int x){
	return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
}

void solve(){
	scanf("%s", s + 1), scanf("%s", t + 1);
	for(int i = 1; i <= 4; i++) y[0] = y[0] * 10 + s[i] - '0';
	for(int i = 5; i <= 6; i++) m[0] = m[0] * 10 + s[i] - '0';
	for(int i = 7; i <= 8; i++) d[0] = d[0] * 10 + s[i] - '0';
	for(int i = 1; i <= 4; i++) y[1] = y[1] * 10 + t[i] - '0';
	for(int i = 5; i <= 6; i++) m[1] = m[1] * 10 + t[i] - '0';
	for(int i = 7; i <= 8; i++) d[1] = d[1] * 10 + t[i] - '0';
	int ans = 0;
	while(y[0] != y[1] || m[0] != m[1] || d[0] != d[1]){
		ans += check(y[0], m[0], d[0]);
		d[0]++;
		if(d[0] > mx[m[0]] + (m[0] == 2 && isleap(y[0]))) m[0]++, d[0] = 1;
		if(m[0] > 12) m[0] = 1, y[0]++;
	}
	ans += check(y[1], m[1], d[1]);
	printf("%d\n", ans);
}

int main(){
    int t = 1, cnt = 1;
	while(t--){
		solve();
	}
	
   return 0;
}
