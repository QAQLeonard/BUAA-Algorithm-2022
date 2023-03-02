#include<stdio.h>
#define maxn 1000005
#define inf 0x3f3f3f3f
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

int n, sz, a[maxn];

void swap(int *a, int *b) {
	int t = *a;
	*a = *b, *b = t;
}

void maxHeapify(int x) {
	int l = ls(x), r = rs(x), larg;
	if(l <= sz && a[l] > a[x]) larg = l;
	else larg = x;
	if(r <= sz && a[r] > a[larg]) larg = r;
	if(larg != x) swap(&a[x], &a[larg]), maxHeapify(larg);
}

void increaseKey(int i, int key) {
	a[i] = key;
	while(i > 1 && a[i / 2] < a[i]) {
		swap(&a[i / 2], &a[i]);
		i = i / 2;
	}
}

void insert(int x) {
	sz += 1;
	a[sz] = -inf;
	increaseKey(sz, x);
}

int top() {
	return a[1];
}

void pop() {
	if(sz < 1) exit(1);
	a[1] = a[sz];
	sz -= 1;
	maxHeapify(1);
}

int main() {
	scanf("%d", &n);
	int i;
	for(i = 1; i <= n; i++) {
		int op, x;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d", &x);
			insert(x);
		}
		if(op == 2) pop();
		if(op == 3) printf("%d\n", top());
	}
	while(sz) {
		printf("%d ", top()), pop();
	}
}
