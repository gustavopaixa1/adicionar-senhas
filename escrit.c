#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct {
    char titulo[100];
    char login[100];
    char senha[100];
} Pessoa;


int main (){
    setlocale (LC_ALL,"");
    Pessoa p;
    char continuar;

do {
    printf("Digite um t�tulo para a senha: ");
    fflush (stdin);
    gets(p.titulo);

    printf("Digite o seu login: ");
    fflush (stdin);
    gets(p.login);
    
    printf("Digite a sua senha: ");
    fflush (stdin);
    gets(p.senha);

    printf("\n");

    printf("Voc� deseja adicionar mais senhas?\n Digite 's' para sim e 'n' para n�o: ");
    continuar = getchar();
    printf("\n");
    } while (continuar != 'n'); 


//CRIA��O DO ARQUIVO E ESCRITA
FILE *f = fopen("pessoas.bin", "ab"); //ab cria um arquivo binario
fwrite (&p, sizeof(Pessoa), 1, f);   //passa o endere�o da struct, tamanho,   quantidade de vezes que ser� escrito e nome do arrquivo
fclose(f); //fecha o arquivo /


fopen("pessoas.bin", "rb"); //rb � o argumento de leitura para binario
if (!f) { // (!f) testa se o resultado da opera��o foi NULL
printf("N�o foi poss�vel abrir o arquivo\n");
}

while (fread (&p, sizeof(Pessoa), 1, f)) {//
printf("%s\n", p.titulo);
printf("Login: %s\n", p.login);
printf("Senha: %s\n", p.senha);
printf("\n\n");
}

fclose(f);
return 0;
}

