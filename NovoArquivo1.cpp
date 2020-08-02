#include <stdio.h>
 int main ()
{
	
int idade, ano;
float altura;
char nome[30];
printf ("DIGITE O SEU NOME:   ");
printf ("%s", nome);
printf ("DIGITE A SUA IDADE:   ");
scanf ("%d", &idade);
printf ("DIGITE A ALTURA:  ");
scanf ("%f", &altura );

ano = 2012 - idade;

printf("\nO nome e :    %s", nome);
printf("\nA altura e :  %f", altura);
printf("\nA idade e :   %d", idade);
printf("\nO ano de nascimento e :%d", ano);
	return 0;
}