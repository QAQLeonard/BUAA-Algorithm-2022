#include<bits/stdc++.h>
using namespace std;

pair<int,int>a[1000005];

int cmp(pair<int,int>a,pair<int,int>b){
    if(a.second!=b.second)return a.second<b.second;
    else return a.first<b.first;
}

int main(){
	using namespace std;
	int n;
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>a[i].first>>a[i].second;
	sort(a,a+n,cmp);
	int ans = 1;
	int temp = a[0].second;
	for(int i=1;i<n;i++){
		if(a[i].first >= temp){
			temp = a[i].second;
			ans++;
		}
	}
	cout<<ans;
}
