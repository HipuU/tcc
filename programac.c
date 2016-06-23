#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct lista{
	int conteudo;
	struct lista *prox;
};
typedef struct lista fila;

fila* cria_fila (void);
void insere (int x, fila *f);
void tiraprimeiro (fila **f);
void imprimir (fila *f);

void main()
{
	int grafo[5][5];
	int cor[5	];
	int i=0;
	int j=0;
	int k=0;
	
	char url[]="matriz.txt";
	char ch;
	
	fila *f; 
	f = cria_fila();
	
	FILE *arq;
	
	arq = fopen(url,"r");
	if(arq == NULL)
		printf("\nNao leu o arquivo txt\n");
	else
		while( (ch=fgetc(arq))!= EOF )
		{
			//putchar(ch);
			if(ch == '0')
			{
				if(i==0 && j==0)
				{
					grafo[i][j] = 0;
					j++;
				}
				else{
					grafo[i][j] = 0;
					j++;
				}
			}
			if(ch == '1')
			{
				if(i==0 && j==0)
				{
					grafo[i][j] = 0;
					j++;
				}
				else{
					grafo[i][j] = 1;
					j++;
				}
			}
			if(ch == '\n')
			{
				i++;
				j=0;
			}
		}
	fclose(arq);
	
		//cor branca = 0
		//cor cinza = 1
		//cor preta = 2
		
	//Esse for pinta todos os vertices de branco (0)	
	for(i = 0; i <= 4; i++)
	{
		cor[i] = 0;
	}
	
	//Escolho um vertice
	//Como padrão pegar sempre o primeiro vertice ou seja 0

	cor[0] = 1; //Pinta o vertice na cor cinza (1) Que indica que ele foi visitado
	insere(0,f); //Insere o primeiro vertice visitado na fila
	
	k=0; //contador auxiliar para andar pelo grafo
	
	
	while(f->prox != NULL)
	{
		for(j = k; j<=4; j++)
		{
			if(grafo[f->prox->conteudo][j] == 1) //Verifica se o vertice é vizinho 
			{
				if(cor[j] == 1)
				{
					break;
				}
				else{
					cor[j] = 1; //Caso verdadeiro pinta o vertice como visitado cinza (1)
					insere(j,f); //Insere o vertice na lista 
					//imprimir(f);
					}
			}
		}
		cor[f->prox->conteudo] = 2; //Pinta o vertice cujo todos os seus vizinho ja tenham sido visitados de preto (2)
		tiraprimeiro(&f); //Remove o vertice cujo todos os vizinhos foram visitados
		k++; 
	}
}

fila* cria_fila (void)
{
	fila *p;
	p = (fila *) malloc (sizeof(fila));
	p->conteudo = 10;
	p->prox = NULL;
	return p;	
}

void insere (int x, fila *f)
{
   fila *nova, *temp;
  nova = (fila *) malloc (sizeof(fila));
  nova->conteudo = x; 
  nova->prox = NULL;

  if(f->prox == NULL) //verifica se fila esta vazia
  {
  	f->prox = nova;
  }
  else{
  		temp = f; //Cópia do primeiro elemento para poder percorrer a fila
  		while(temp->prox != NULL)
  		{
   			temp = temp->prox;
  		}   
  		temp->prox = nova;
  }
}

void tiraprimeiro (fila **f)
{
   fila *lixo;
   if(*f == NULL)
   {
   	printf("\nImprimi: Lista esta vazia!!! \n");
   }
   lixo = *f;
   *f = (*f)->prox;
   free (lixo);
}

void imprimir (fila *f)
{
	fila *p;
	if(f->prox == NULL)
	{
		printf("\nImprimi: Lista Vazia!!!! \n");
	}
	for(p = f->prox; p != NULL; p = p->prox)
	{
		printf("\nImprimi: %d \n", p->conteudo);
	} 
}








