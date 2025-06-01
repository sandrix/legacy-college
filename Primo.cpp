#include <stdio.h>
#include <conio.h>

//Fun��o que recebe um n�mero qualquer e verifica se ele � primo.
bool eh_primo(int num){

    int i, count = 0;

    //Verifico todos os n�meros de 2 at� o numero anterior ao numero
    //(pois um numero primo � divis�vel por 1 e por ele mesmo)
    for (i = 2; i <= num-1; i++){
        
        //Se o resto da divis�o inteira do numero pelo n�mero do la�o (i)
        if (num % i == 0){
           
           //ent�o o numero n�o � primo.
           return(false);
        }
    }
    
    //Se n�o for divisivel por outro numero alem dele mesmo e 1
    //numero � primo
       return(true);
}
    

int main(int argc, char *argv[])
{
    int numero_ini=1;
    int numero_fin=50;
	bool achou=false;

    //Mostra mensagem para o usu�rio solicitando o primeiro numero
    printf("Entre com o primeiro numero: ");
    //Leio do teclado o numero digitado.
    scanf("%d",&numero_ini);
    
    //Idem para o segundo numero.
    printf("Entre com o segundo numero: ");
    scanf("%d",&numero_fin);
    
    //Verifico se o primeiro numero � menor que o segundo.
    if (numero_ini > numero_fin)
       printf("\n Erro: O primeiro numero deve ser menor que o segundo.\n\n");
    else
    
        //Para cada n�mero do intervalo, chamo a fun��o para verificar se o n�mero � primo.
        for(int i=numero_ini; i<=numero_fin;i++)
        
           //Se a fun��o retornar verdadeiro, o n�mero � primo.
           if(eh_primo(i))
           {
               //Imprimo na tela o n�mero em quest�o.
			   if (!achou){
				printf("Numero Primo: %d \n",i);
				achou=true;
			   }
			   else
				printf(" %d, ",i);
		   }
}
