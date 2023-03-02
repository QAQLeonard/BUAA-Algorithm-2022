#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define pi acos(-1)
#define inf 2147483647
#define llinf 9223372036854775807
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

#define N 200010
void swap(int *a,int *b) {
	int t=*a;
	*a=*b;
	*b=t;
}
int heap_size=0;
int heap[N];

int heapDel_size=0;
int heapDel[N];
void put(int x) {
	int now,next,res;
	heap[++heap_size]=x;
	now=heap_size;
	while(now>1) {
		next=now>>1;
		if(heap[now]>=heap[next]) {
			return;
		} else {
			swap(&heap[now],&heap[next]);
			now=next;
		}
	}
}
int get() {
	if(heap_size<1)exit(-1);
	return heap[1];
}
int del() {
	if(heap_size<1)exit(-1);
	int res=heap[1];
	heap[1]=heap[heap_size--];
	int now=1,next;
	while(now*2<=heap_size) {
		next=now*2;
		if(next<heap_size&&heap[next+1]<heap[next]) {
			next++;
		}
		if(heap[now]<=heap[next]) {
			return res;
		}
		swap(&heap[now],&heap[next]);
		now=next;
	}
	return res;
}

void putDel(int x) {
	int now,next,res;
	heapDel[++heapDel_size]=x;
	now=heapDel_size;
	while(now>1) {
		next=now>>1;
		if(heapDel[now]>=heapDel[next]) {
			return;
		} else {
			swap(&heapDel[now],&heapDel[next]);
			now=next;
		}
	}
}
int getDel() {
	if(heapDel_size<1)return -2;
	return heapDel[1];
}
int delDel() {
	int res=heapDel[1];
	heapDel[1]=heapDel[heapDel_size--];
	int now=1,next;
	while(now*2<=heapDel_size) {
		next=now*2;
		if(next<heapDel_size&&heapDel[next+1]<heapDel[next]) {
			next++;
		}
		if(heapDel[now]<=heapDel[next]) {
			return res;
		}
		swap(&heapDel[now],&heapDel[next]);
		now=next;
	}
	return res;
}

int main() {
	int n,op,x;
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&op);
		if(op==1) {
			scanf("%d",&x);
			put(x);
		} else if(op==2) {
			while(get()==getDel()) {
				del();
				delDel();
			}
			del();
		} else if(op==3) {
			while(get()==getDel()) {
				del();
				delDel();
			}
			printf("%d\n",get());
		} else if(op==4) {
			scanf("%d",&x);
			putDel(x);
		}
	}
	while(heap_size>0) {
		if(get()==getDel()) {
			del();
			delDel();
		} else {
			printf("%d ",del());
		}
	}
	return 0;
}
