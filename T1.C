#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define TAM1 120000
#define clrscr(); system("cls");

static long int bubble_sort(int v[],int tam)
{
   int i,lim,k,tmp;
   int troca=1;
   long int trocas=0;

   lim = tam-1;
   while (troca)
   {
      troca=0;
      for (i=0;i<=lim;i++)
      {
	 if (v[i] > v[i+1])
	 {
	    tmp=v[i];
	    v[i]=v[i+1];
	    v[i+1]=tmp;
	    troca=1;
	    k=i;
	    trocas++;
	 }
      }
      lim=k;
   }
   return(trocas);
}

static long int insertion_sort (int v[], int tam)
{
	int i,j,k,tmp;
	int achei;
	long int movim;
	
	movim=0;
	for (i=2;i<=tam;i++)
	{
		j=1;
		achei=0;
		while ((j<i) && (!achei))
		{
			if (v[i] < v[j])
				achei=1;
			else
				j++;
		}
		if (achei)
		{
			tmp=v[i];
			k=i-1;
			while (k>=j)
			{
				v[k+1]=v[k];
				k--;
				movim++;
			}
			v[j]=tmp;
		}
	}
	return(movim);
}

static long int selection_sort(int v[],int tam)
{
   int i,pos_menor,tmp,j;
   long int movim;

   movim=0;
   for (i=1;i<=tam-1;i++)
   {
      pos_menor=i;
      for (j=i+1;j<=tam;j++)
	 if (v[j] < v[pos_menor])
	    pos_menor=j;
      tmp = v[i];
      v[i] = v[pos_menor];
      v[pos_menor] = tmp;
      movim++;
   }
   return(movim);
}

static void particao(int v[],int esq,int dir,int *i,int *j,int *trocas)
{
   int pivo,tmp;

   pivo=v[(esq+dir)/2];
   do{
      while (pivo > v[esq]) esq++;
      while (pivo < v[dir]) dir--;
      if (esq <= dir)
      {
	 tmp=v[esq];
	 v[esq]=v[dir];
	 v[dir]=tmp;
	 esq++;
	 dir--;
	 (*trocas)++;
      }
   }
   while (esq < dir);
   *i=esq;
   *j=dir;
}

static int quick_sort(int v[],int esq,int dir)
{
   int i,j,retorno=0;

   particao(v,esq,dir,&i,&j,&retorno);
   if (esq<j) quick_sort (v,esq,j);
   if (dir>i) quick_sort (v,i,dir);
   return(retorno);
}

int parent(int i) { return i/2; }
int left(int i) {return 2*i;}
int right(int i) {return 2*i+1;}

static void heapify(int v[],int tam,int i,int *trocas)
{
   int l,r,largest,tmp;

   l=left(i);
   r=right(i);

   if ((l <= tam) && (v[l] > v[i]))
      largest=l;
   else
      largest=i;

   if ((r <= tam) && (v[r] > v[largest]))
      largest=r;
   if (largest != i)
   {
      tmp = v[largest];
      v[largest] = v[i];
      v[i]=tmp;
      (*trocas)++;
      heapify (v,tam,largest,&trocas);
   }
}

static void build_heap (int v[],int tam,int *trocas)
{
   int i;

   for (i=tam/2;i;i--)
      heapify(v,tam,i,&trocas);
}

static int heap_sort(int v[],int tam)
{
   int i,tmp,trocas=0,retorno;

   build_heap (v,tam,&trocas);
   for (i=tam;i>1;i--)
   {
      tmp=v[1];
      v[1]=v[i];
      v[i]=tmp;
      trocas++;
      heapify(v,--tam,1,&trocas);
   }
   return(trocas);
}

static void bubble(int vetor[],int tam)
{
   clock_t antes,depois;
   int opcao;
   long int retorno;

   clrscr();
   printf("\nOpcoes:\n");
   printf("(1) Testar o Bubble Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em Segundos.\n");
   printf("(2) Testar o Bubble Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em trocas de elementos no vetor.\n");
   printf("\nEntre com a opcao : ");
   scanf("%d",&opcao);
   switch(opcao)
   {
      case 1 :  clrscr();
		antes=clock();
		bubble_sort(vetor,tam);
		depois=clock();
		printf("O Selection Sort demorou %f segundo(s)...\n",(float)(depois-antes)/CLK_TCK);
		break;
      case 2 :  clrscr();
		retorno=bubble_sort(vetor,tam);
		printf("O Bubble Sort fez %ld trocas...\n",retorno);
		break;
   }
}

static void insertion(int vetor[],int tam)
{
   clock_t antes,depois;
   int opcao;
   long int retorno;

   clrscr();
   printf("\nOpcoes:\n");
   printf("(1) Testar o Insertion Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em Segundos.\n");
   printf("(2) Testar o Insertion Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em movimentos de elementos no vetor.\n");
   printf("\nEntre com a opcao : ");
   scanf("%d",&opcao);
   switch(opcao)
   {
      case 1 :  clrscr();
		antes=clock();
		retorno=insertion_sort(vetor,tam);
		depois=clock();
		printf("O Insertion Sort demorou %f segundo(s)...\n",(float)(depois-antes)/CLK_TCK);
		break;
      case 2 :  clrscr();
		retorno=insertion_sort(vetor,tam);
		printf("O Insertion Sort fez %ld movimentos...\n",retorno);
		break;
   }
}

static void selection(int vetor[],int tam)
{
   clock_t antes,depois;
   int opcao;
   long int retorno;

   clrscr();
   printf("\nOpcoes:\n");
   printf("(1) Testar o Selection Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em Segundos.\n");
   printf("(2) Testar o Selection Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em movimentos de elementos no vetor.\n");
   printf("\nEntre com a opcao : ");
   scanf("%d",&opcao);
   switch(opcao)
   {
      case 1 :  clrscr();
		antes=clock();
		selection_sort(vetor,tam);
		depois=clock();
		printf("O Selection Sort demorou %f segundo(s)...\n",(float)(depois-antes)/CLK_TCK);
		break;
      case 2 :  clrscr();
		retorno=selection_sort(vetor,tam);
		printf("O Selection Sort fez %ld movimentos...\n",retorno);
		break;
   }
}


static void quick(int vetor[],int tam)
{
   clock_t antes,depois;
   int opcao,retorno;

   clrscr();
   printf("\nOpcoes:\n");
   printf("(1) Testar o Quick Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em Segundos.\n");
   printf("(2) Testar o Quick Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em trocas de elementos no vetor.\n");
   printf("\nEntre com a opcao : ");
   scanf("%d",&opcao);
   switch(opcao)
   {
      case 1 :  clrscr();
		antes=clock();
		retorno=quick_sort(vetor,1,tam);
		depois=clock();
		printf("O Quick Sort demorou %f segundo(s)...\n",(float)(depois-antes)/CLK_TCK);
		break;
      case 2 :  clrscr();
		retorno=quick_sort(vetor,1,tam);
		printf("O Quick Sort fez %d trocas...\n",retorno);
		break;
   }
}


static void heap(int vetor[],int tam)
{
   clock_t antes,depois;
   int opcao,retorno;

   clrscr();
   printf("\nOpcoes:\n");
   printf("(1) Testar o Heap Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em Segundos.\n");
   printf("(2) Testar o Heap Sort com um vetor de %d posicoes.\n",tam);
   printf("    Resultado: Medido em trocas de elementos no vetor.\n");
   printf("\nEntre com a opcao : ");
   scanf("%d",&opcao);
   switch(opcao)
   {
      case 1 :  clrscr();
		antes=clock();
		retorno=heap_sort(vetor,tam);
		depois=clock();
		printf("O Heap Sort demorou %f segundo(s)...\n",(float)(depois-antes)/CLK_TCK);
		break;
      case 2 :  clrscr();
		retorno=heap_sort(vetor,tam);
		printf("O Heap Sort fez %d trocas...\n",retorno);
		break;
   }
}


static void inicializa_vetor(int vetor1[],int tam)
{
  int i;
  clrscr();
  printf("Gerando %d numeros aleatorios...",tam);
  //randomize();
  for (i=0;i<=tam;i++)
     vetor1[i]=rand();
  printf("\n\nNumeros gerados, pronto para continuar...");
  getch();
  clrscr();
}

static void lista_vetor(int vetor[],int tam)
{
   int i;
   for (i=0;i<=tam;i++)
      printf("%d ",vetor[i]);
   printf("\n\nContinuar...\n\n");
   getch();
   clrscr();
}

static void randomiza(int vetor[],int vetor2[],int tam)
{
  int i;

  inicializa_vetor(vetor,tam);
  for(i=0;i<=tam;i++)          //cria um backup do vetor (ja que ele e passado por
     vetor2[i]=vetor[i];       //referencia, assim a cada retorno de um sorteamento
			       //tenho como chamar outro sorteamento com os mesmos elementos.
}

void main()
{
  int opcao,vetor[TAM1],vetor2[TAM1],i;
  randomiza(vetor,vetor2,TAM1);
  do
  {
     printf("\nTrabalho 1 - Algoritmos 3\n\n");
     printf("Opcoes : \n");
     printf("(0) - Bubble Sort\n" );
     printf("(1) - Insertion Sort\n");
     printf("(2) - Selection Sort\n");
     printf("(3) - QuickSort\n");
     printf("(4) - HeapSort\n");
     printf("(5) - Listar o vetor\n");
     printf("(6) - Randomizar novamente\n" );
     printf("\n(7) - Sair\n");
     printf("\nEntre com a opcao : ");
     scanf("%d",&opcao);
     clrscr();
     switch(opcao)
     {
	case 0: for(i=0;i<=TAM1;i++)     //Ordena o vetor ao contrario
		   vetor[i] = TAM1-i;
		bubble(vetor,TAM1);
		break;
	case 1: for(i=0;i<=TAM1;i++)     //Ordena o vetor ao contrario
		   vetor[i] = TAM1-i;
		insertion(vetor,TAM1);
		break;
	case 2: for(i=0;i<=TAM1;i++)     //Ordena o vetor ao contrario
		   vetor[i] = TAM1-i;
		selection(vetor,TAM1);
		break;
	case 3: for(i=0;i<=TAM1;i++)     //Ordena o vetor ao contrario
		   vetor[i] = TAM1-i;
		quick(vetor,TAM1);
		break;
	case 4: for(i=0;i<=TAM1;i++)     //Ordena o vetor ao contrario
		   vetor[i] = TAM1-i;
		heap(vetor,TAM1);
		break;
	case 5: lista_vetor(vetor,TAM1);break;
	case 6: randomiza(vetor,vetor2,TAM1);
	case 7: break;
     }
  }while (opcao != 7);
}
