#include <stdio.h>
#include <conio.h>

//Função que recebe um número qualquer e verifica se ele é primo.
bool eh_primo(int num){

    int i, count = 0;

    //Verifico todos os números de 2 até o numero anterior ao numero
    //(pois um numero primo é divisível por 1 e por ele mesmo)
    for (i = 2; i <= num-1; i++){
        
        //Se o resto da divisão inteira do numero pelo número do laço (i)
        if (num % i == 0){
           
           //então o numero não é primo.
           return(false);
        }
    }
    
    //Se não for divisivel por outro numero alem dele mesmo e 1
    //numero é primo
       return(true);
}
    

int main(int argc, char *argv[])
{
    int numero_ini=1;
    int numero_fin=50;
	bool achou=false;

    //Mostra mensagem para o usuário solicitando o primeiro numero
    printf("Entre com o primeiro numero: ");
    //Leio do teclado o numero digitado.
    scanf("%d",&numero_ini);
    
    //Idem para o segundo numero.
    printf("Entre com o segundo numero: ");
    scanf("%d",&numero_fin);
    
    //Verifico se o primeiro numero é menor que o segundo.
    if (numero_ini > numero_fin)
       printf("\n Erro: O primeiro numero deve ser menor que o segundo.\n\n");
    else
    
        //Para cada número do intervalo, chamo a função para verificar se o número é primo.
        for(int i=numero_ini; i<=numero_fin;i++)
        
           //Se a função retornar verdadeiro, o número é primo.
           if(eh_primo(i))
           {
               //Imprimo na tela o número em questão.
			   if (!achou){
				printf("Numero Primo: %d \n",i);
				achou=true;
			   }
			   else
				printf(" %d, ",i);
		   }
}
