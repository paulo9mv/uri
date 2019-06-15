#include <stdio.h>
 
int main() {
 
    float cont = 0;
    int codigo;
    int quantidade;
    float valor;
    
    scanf("%d", &codigo);
    scanf("%d", &quantidade);
    scanf("%f", &valor);
    
    cont += (valor * quantidade);
    
    scanf("%d", &codigo);
    scanf("%d", &quantidade);
    scanf("%f", &valor);
    
    cont += (valor * quantidade);
    
    printf("VALOR A PAGAR: R$ %.2f", cont)
    
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
 
    return 0;
}