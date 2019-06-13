#include <stdio.h>
 
int main() {
 
        int i,n,cont=0;
    scanf("%d",&n);

    for(i=1;cont!=n;i++){
            if(i%4==0){
            printf("PUM\n");
            cont++;
            i++;
    }
    if(cont!=n)
    printf("%d ",i);
    }
  
    return 0;
}