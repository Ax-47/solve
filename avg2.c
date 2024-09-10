#include <stdio.h>

int main(){
    int n ;
    int a,sum=0;
    scanf("%d",&n);
    for (int i=0;i <n;i++){
        scanf("%d",&a);
        sum+=a;
    }
    printf("%.2f",(float)sum/n);
    return 0;
}
