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
    printf("Digite um título para a senha: ");
    fflush (stdin);
    gets(p.titulo);

    printf("Digite o seu login: ");
    fflush (stdin);
    gets(p.login);
    
    printf("Digite a sua senha: ");
    fflush (stdin);
    gets(p.senha);

    printf("\n");

    printf("Você deseja adicionar mais senhas?\n Digite 's' para sim e 'n' para não: ");
    continuar = getchar();
    printf("\n");
    } while (continuar != 'n'); 


//CRIAÇÃO DO ARQUIVO E ESCRITA
FILE *f = fopen("pessoas.bin", "ab"); //ab cria um arquivo binario
fwrite (&p, sizeof(Pessoa), 1, f);   //passa o endereço da struct, tamanho,   quantidade de vezes que será escrito e nome do arrquivo
fclose(f); //fecha o arquivo /


fopen("pessoas.bin", "rb"); //rb é o argumento de leitura para binario
if (!f) { // (!f) testa se o resultado da operação foi NULL
printf("Não foi possível abrir o arquivo\n");
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

