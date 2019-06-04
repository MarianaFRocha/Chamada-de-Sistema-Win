#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int criar_escrever_fechar(){
  int  arq;
  char nome[]  = "teste.txt"; // nome do arquivo
  char frase[30] = "Alo, mundo"; // o que vai ser escrito no arquivo

  arq = open(nome, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); // abre ou cria um novo arquivo
  if (arq == -1)
  {
        printf("Erro na abertura do arquivo");
        exit(1);
  }

  write(arq, frase, strlen(frase));  // escreve no arquivo

  close(arq);
  if (arq == -1){
      printf("Erro ao fechar o arquivo");
      exit(1);
  }
  printf("Arquivo foi criado, escrito e fechado com sucesso!!\n");

  return 0;

}

int renomear_ler() 
{ 
    int resp, arq, n; 
    char linha[10];
    char nomeAntigo[] = "teste.txt"; 
    char nomeNovo[] = "novoArquivo.txt"; 

    resp = rename(nomeAntigo, nomeNovo);

    if (resp == 0)
      printf("Arquivo %s renomeado para %s com Sucesso!\n", nomeAntigo, nomeNovo); 
    else 
      printf("Erro ao renomear arquivo!\n");

    arq = open(nomeNovo, O_RDONLY);
    if (arq == -1)
    {
      printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    while ((n = read(arq, linha, 1)) > 0)
      printf("%s", linha);

    close(arq);
    printf("\nOperacoes finalizadas com sucesso\n");

    return 0;
}


int main ()
{
  //criar_escrever_fechar();
  //renomear_ler();

  return 0;
}
