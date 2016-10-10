#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoPilha{
	char chave;
	struct NoPilha *prox;
}NoPilha, *Topo;

void inicializa(Topo *y){
	*y = NULL;
}
 	
_Bool empilha(Topo *y, char x);
_Bool desempilha(Topo *y, char *x);
char opcao();
void empilhamento();
_Bool verifCasos(int *i, char *x);
Topo f;

_Bool empilha(Topo *y, char x){
	NoPilha *p;
	if(p = (NoPilha *) malloc (sizeof(NoPilha))){
		p->chave = x;
		p->prox = *y;
		*y = p;
	}
	return p;
}

_Bool desempilha(Topo *y, char *x){
	NoPilha *p;
	if(!(p = *y))
		return false;
	*x = p->chave;
	*y = p->prox;
	p->chave = '\0';
	return true;
}


char opcao(){
	char opt,cu;
	printf("Deseja inserir uma cadeia? (y/n)\n");
	scanf("%c",&opt);
	switch(opt){
		case 'y':
			empilhamento();
			break;
		case 'n':
			return;
		default:
			printf("Opcao invalida.\n");
	}

}

void empilhamento(){
	int i,j;
	char *chave;

	printf("Quantidade de elementos da cadeia: \n");
	scanf("%d",&i);
	if(i>20){
		printf("Valor maximo estourado.\n");
		return;
	}
	chave = (char *)malloc(sizeof(char)*i);
	printf("cadeia: \n");
	scanf("%s",chave);
	for (j = 0; j < i; j++){
		if ((chave[j] != 'a') && (chave[j] != 'b') && (chave[j] != 'c')){
			printf("A cadeia nao pertence a linguagem.\n\n");
			return;
		}
	}
	empilha(&f,'z');
	if(verifCasos(&i,&*chave))
		printf("A cadeia pertence a linguagem.\n");
	else
		printf("A cadeia nao pertence a linguagem.\n");
}

_Bool verifCasos(int *i, char *x){
	char s;
	int j = 0;
	NoPilha *p = f;
q0:	
	if ((x[j] == 'a') && (p->chave == 'z')){
		desempilha(&p,&s);
		empilha(&p,'z');
		empilha(&p,'c');
		empilha(&p,'c');
		j++;
		if((x[j] == '\0') && (p->chave != '\0')){
			return false;
		}else
			goto q1;	
	}else
		return false;
	goto q01;
q1:
	if((x[j] == 'a') && (p->chave == 'c')){
		desempilha(&p,&s);
		empilha(&p,'c');
		empilha(&p,'c');
		empilha(&p,'c');
		j++;
		goto q1;
	}
	if((x[j] == 'b') && (p->chave == 'c')){
		desempilha(&p,&s);
		if((x[j] == '\0') && (p->chave != '\0'))
			return false;
		j++;
		goto q3;
	}
	goto q01;

q3:
	if((x[j] == '\0')&&(p->chave == 'z')){
		desempilha(&p,&s);
		goto q5;
	}
	if((x[j] == '\0') && (p->chave != '\0'))
		return false;
	if((x[j] == 'b')&&(p->chave == 'c')){
		desempilha(&p,&s);
		j++;
		goto q3;
	}

q01:
	j = 0;
	Topo u;
	inicializa(&u);
	empilha(&u,'z');
	p = u;
	if ((x[j] == 'a') && (p->chave == 'z')){
		desempilha(&p,&s);
		empilha(&p,'z');
		empilha(&p,'c');
		j++;
		if((x[j] == '\0') && (p->chave != '\0')){
			return false;
		}else
			goto q2;	
	}else
		return false;

	
	
q2:
	if((x[j] == 'a') && (p->chave == 'c')){
		desempilha(&p,&s);
		empilha(&p,'c');
		empilha(&p,'c');
		j++;
		goto q2;
	}
	if((x[j] == 'c') && (p->chave == 'c')){
		desempilha(&p,&s);
		if((x[j] == '\0') && (p->chave != '\0'))
			return false;
		j++;
		goto q4;
	}

	
q4:
	if((x[j] == '\0')&&(p->chave == 'z')){
		desempilha(&p,&s);
		goto q5;
	}
	if((x[j] == '\0') && (p->chave != '\0'))
		return false;
	if((x[j] == 'c')&&(p->chave == 'c')){
		desempilha(&p,&s);
		j++;
		goto q4;
	}


if(p->chave != '\0')
	return false;


q5:
		return true;

	

	return false;
}


int main(){
	inicializa(&f);
	char op;
	do{
		op=opcao();
		getchar();
	}while(op != 'n');
	return 0;
}