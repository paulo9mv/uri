#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p, J, R, i, j, pp, maior=0;
	scanf("%d", &J);
	p=calloc(J ,sizeof(int)*J);
	scanf("%d", &R);

	for(i=0; i<R; i++){
		for(j=0; j<J; j++){
			scanf("%d", &pp);
			p[j] += pp;		
		
		}
	}
	
	for(i=0; i<J; i++)
	{
		if(maior<=p[i]){
			maior = p[i];
			j=i+1;
		}
	}
	
	printf("%d\n", j);
	
	free(p);	
	return 0;
	
}