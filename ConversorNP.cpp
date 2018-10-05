#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 10

void Enfilar(char * pilha,char valor,int base);
void Desenfilar(char *pilha);
void Converter(char * exp,bool infixo,bool pre,bool pos);
void VerExp(char * exp);
int TamanhoExp(char * exp); 
void PosFixoConverte(char * exp);
void PreFixoConverte(char * exp);
void InfixoConverter(char * exp);

int *ptam1,*ptam2,base1=0,base2=0;
int tam =10;

main(){
	
	int tam;
	printf("\t\t\t\t\t CONVERSOR DE NOTAÇÕES POLONESAS \n\n\n ",setlocale(LC_ALL,""));
	printf("\t\t\t\t\t   Tamanho maximo da expressão: ",setlocale(LC_ALL,""));
	scanf("%d",&tam);
	fflush(stdin);
	char exp [tam];	
	system("cls");
	
	printf("\t\t\t\t\t CONVERSOR DE NOTAÇÕES POLONESAS \n\n\n ",setlocale(LC_ALL,""));
	printf("\t\t\t\t\t       Digite a expressão:",setlocale(LC_ALL,""));
	gets(exp);
	system("cls");
	VerExp(exp);
	

	system ("pause");
	return 0;
}
int TamanhoExp(char *exp){
	int t = strlen(exp);
	
	return t;
}
void VerExp(char * exp){
	
	int t = TamanhoExp(exp);
	bool inf,pre,pos= false;
	
	for (int i=0;i<t-1;i++){
		
		if(i==0 && exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'){
			printf("\t\t\t\t\t CONVERSOR DE NOTAÇÕES POLONESAS \n\n\n ",setlocale(LC_ALL,""));
			printf("\t\t\t\t\t VOCÊ DIGITOU UMA NOTAÇÃO PRE-FIXA\n\n\n",setlocale(LC_ALL,""));
			pre =true;
			break;
		}
		
		if(i!=0 && exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'){
			if(exp[t-1]=='+'||exp[t-1]=='-'||exp[t-1]=='/'||exp[t-1]=='*'){
				printf("\t\t\t\t\t CONVERSOR DE NOTAÇÕES POLONESAS \n\n\n ",setlocale(LC_ALL,""));
				printf("\t\t\t\t\t VOCÊ DIGITOU UMA NOTAÇÃO POS-FIXA\n\n\n",setlocale(LC_ALL,""));
				pos =true;
				break;
			}
		}
		if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*' && i!=t-1){
			if((exp[i+1]>='a'&& exp[i+1]<='z'||exp[i+1]>='a'&& exp[i+1]<='z')){
					printf("\t\t\t\t\t CONVERSOR DE NOTAÇÕES POLONESAS \n\n\n ",setlocale(LC_ALL,""));
					printf("\t\t\t\t\t VOCÊ DIGITOU UMA NOTAÇÃO INFIXA\n\n\n",setlocale(LC_ALL,""));
					inf =true;
					break;	
		}else if((exp[i+1]>='A'&& exp[i+1]<='Z'||exp[i+1]>='A'&& exp[i+1]<='Z')){
					printf("\t\t\t\t\t CONVERSOR DE NOTAÇÕES POLONESAS \n\n\n ",setlocale(LC_ALL,""));
					printf("\t\t\t\t\t VOCÊ DIGITOU UMA NOTAÇÃO INFIXA\n\n\n",setlocale(LC_ALL,""));
					inf =true;
					break;	
		}
			
		}
	}
	  Converter(exp,inf,pre,pos);
}
void Converter(char * exp,bool infixo,bool pre,bool pos){
	
	if(infixo){	
		PosFixoConverte(exp);		
	}
	
	if(pre){
		
	}
	
	if(pos){
		
	}

}
void Enfilar(char * pilha,char valor,int base){
	int t = TamanhoExp(pilha);
	
		pilha[base]=valor;
	
		
	
}


void PosFixoConverte(char * exp){
	int t = TamanhoExp(exp);
	
	char pilha1[tam];
	char pilha2[tam];
		
	for(int i = 0;i<=t-1;i++){

		if(exp[i]>='a'&&exp[i]<='z'||exp[i]>='a'&&exp[i]<='z' || exp[i]>='A'&&exp[i]<='Z'||exp[i]>='A'&&exp[i]<='Z'){
				printf("Empilhando na Pilha 1 no indice (%d) \n",base1);
			Enfilar(pilha1,exp[i],base1);
			base1++;	
		}
	}
		for(int i =0;i <=t;i++){
		if(exp[i]=='+'){
			printf("Empilhando na Pilha 2 no indice (%d) \n",base2);
			fflush(stdin);
			Enfilar(pilha2,exp[i],base2);
			base2++;
		}
	}
	
	fflush(stdin);
	puts(pilha1);
	puts(pilha2);

		
}

