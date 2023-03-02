#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int N = 200005;
const int M = 55;
const int inf = 0x3f3f3f3f;
int getint() {
	char c;
	bool flag=0;
	int num=0;
	while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
	while(c>='0'&&c<='9') {
		num=num*10+c-48;
		c=getchar();
	}
	return flag ? -num : num;
}
const int cid[3][2] = {{0, 1}, {0, 2}, {1, 2}};
int color[N], len[N], id[N], mx[3];
bool cmp(int i, int j) {
	return len[i] < len[j];
}
void add(int x) {
	for(int i = 0; i < 3; i ++)
		if(color[mx[i]] == color[x]) {
			len[mx[i]] < len[x] ? mx[i] = x : 1;
			return ;
		}
	sort(mx, mx + 3, cmp);
	len[mx[0]] < len[x] ? mx[0] = x : 1;
	return ;
}
bool check(int i, int j, int k) {
	return color[i] != color[k] && color[j] != color[k] && len[i] + len[j] > len[k];
}
int main() {
	int n = getint();
	if(n < 3) {
		puts("I would like to see xf wear a skirt every day !");
		return 0;
	}
	for(int i = 1; i <= n; i ++)
		scanf("%d%d", &color[i], &len[i]), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	add(id[1]), add(id[2]);
	for(int i = 3; i <= n; i ++) {
		for(int j = 0; j < 3; j ++)
			if(check(mx[cid[j][0]], mx[cid[j][1]], id[i])) {
				printf("%d %d %d\n", mx[cid[j][0]], mx[cid[j][1]], id[i]);
				return 0;
			}
		add(id[i]);
	}
	puts("I would like to see xf wear a skirt every day !");
}
