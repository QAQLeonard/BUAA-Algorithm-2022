#include <stdio.h>
int main(){
    int n, m, op, l, k, r;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d", &op);
        switch (op){
        case 1:
            scanf("%d%d", &l, &r);
            break;
        case 2:
            scanf("%d%d%d", &l, &r, &k);
            break;
        case 3:
            scanf("%d%d", &l, &r);
            printf("0\n");
        }
    }
    return 0;
}
