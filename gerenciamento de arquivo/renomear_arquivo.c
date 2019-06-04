#include<unistd.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<fcntl.h>


int main() 
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

