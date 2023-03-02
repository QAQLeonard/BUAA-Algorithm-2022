#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
char A[1100],B[1100];
int dp[1100][1100];
int n,m;
int targetlen;
set<string> ans;
bool flag = false;
void LCS() {
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=m; j++) {

			if(A[i] == B[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	targetlen = dp[n][m];
}
void dfs(int i, int j, string s) {

	if(i<=0 || j<=0 || flag)    return ;
	if(A[i] == B[j]) {
		s.push_back(A[i]);
		if(s.length() == targetlen) {
			reverse(s.begin(),s.end());
			ans.insert(s);
			flag = true;
		} else   dfs(i-1,j-1,s);
	} else {
		if(dp[i-1][j] >= dp[i][j-1])   dfs(i-1,j,s);
		if(dp[i-1][j] <= dp[i][j-1])    dfs(i,j-1,s);
	}
}
int main() {
	int k;
	scanf("%s%s",A+1,B+1);
	n = strlen(A+1);
	m = strlen(B+1);
	LCS();
	dfs(n,m,"");
	for(string s : ans) {
		puts(s.c_str());
		break;
	}
	return 0;
}
