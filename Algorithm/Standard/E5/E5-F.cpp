#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int n, m;
vector<pair<int, int>> now;

char s[maxn];

int gettp(char x){
	if(x == 'S') return 0;
	if(x == 'R') return 1;
	return 2;
}

char getans(int x){
	if(x == 0) return 'S';
	if(x == 1) return 'R';
	return 'P';
}

bool check(int a, int b){
	if(a == 0 && b == 2) return 1;
	if(a == 1 && b == 0) return 1;
	if(a == 2 && b == 1) return 1;
	return 0;
}

void insert(pair<int, int> x){
	if(now.empty()) now.push_back(x);
	else{
		pair<int, int> y = now[now.size() - 1];
		now.pop_back();
		if(y.second == x.second){
			y.first += x.first;
			now.push_back(y);
		}else{
			if(check(x.second, y.second)){
				x.first += y.first;
				insert(x);
			}
			else{
				now.push_back(y);
				now.push_back(x);
			}
		}
	}
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		now.clear();
		for(int i = 1; i <= n; i++){
			int tp = gettp(s[i]);
			insert({1, tp});
		}
		printf("%c\n", getans(now[0].second));
	}
}
