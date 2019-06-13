#include <stdio.h>
 
int main() {
    double a,b;
    scanf("%lf %lf",&a,&b);

    a = ((3.5*a)+(7.5*b))/11;

    printf("MEDIA = %.5lf\n",a);

 
    return 0;
}