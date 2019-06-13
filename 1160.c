#include <stdio.h>
 
int main() {
 
    int n,pa,pb,i,cont=0;
    float ca,cb;

    scanf("%d %d %d %f %f",&n,&pa,&pb,&ca,&cb);

    for(i=1;i<=n;i++){
        while(pa<=pb){
            pa=pa+(pa*(ca/100));
            pb=pb+(pb*(cb/100));
            cont++;
            if(cont>100){
            pa=1;
            pb=0;
            }
        }
        if(cont>100)
        printf("Mais de 1 seculo.\n");
        else
        printf("%d anos.\n",cont);
        cont=0;

        if(i!=n)
        scanf("%d %d %f %f",&pa,&pb,&ca,&cb);
    }
 
    return 0;
}