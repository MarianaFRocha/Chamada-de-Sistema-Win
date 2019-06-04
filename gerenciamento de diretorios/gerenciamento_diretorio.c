#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include<fcntl.h>


int criaDir()
{
    if (mkdir("Nova Pasta", S_IRUSR | S_IWUSR | S_IXUSR) != 0)
       printf("Erro ao criar um novo diretorio\n");

    system("ls");

    return 0;
}

int removerDir()
{
    if (rmdir("Nova Pasta") != 0)
       printf("Erro ao remover o diretorio\n");

    system("ls");
}


int moveDir()
{

	criaDir();
  	char buf[3000];

  	getcwd(buf, sizeof(buf)); //Le o diretorio atual
  	printf("Diretorio atual :%s\n", buf);

  	if (chroot("/home/mariana/Área de Trabalho") != 0)  //move de diretorio
    	printf("Erro ao tentar mover o processo de diretorio!");
  	else
    {
    	getcwd(buf, sizeof(buf)); //Le o diretorio atual
      	printf("Diretorio atual :%s\n", buf);
    }

}


int linkar(){

	char  linha1[50]="Escrito no arquivo 1\n";
	char  linha2[50]="Escrito no arquivo 2\n";
	int   arq;

	/*crie e modifica arquivo 1*/
	arq = open("/home/mariana/Área de Trabalho/arquivo1.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (arq == -1)
	  {
	    printf("Open arq: %s\n", strerror(errno));
	    exit(2);
	  }
	if (write(arq, linha1, strlen(linha1)) == -1) 
	  {
	   printf("Write: %s\n", strerror(errno));
	   exit(3);
	}
	close(arq);

	/*Cria um link entre os arquivos*/ 
	if (link("/home/mariana/Área de Trabalho/arquivo1.txt", "/home/mariana/Documentos/arquivo2.txt") != 0)
	 {
	   printf("Link: %s\n", strerror(errno));
	   exit(6);
	}

	/*Abre e modifica o arquivo 2*/
	arq = open("/home/mariana/Documentos/arquivo2.txt", O_WRONLY | O_APPEND, NULL);
	if (arq == -1)
	  {
	    printf("Open arq2: %s\n", strerror(errno));
	    exit(7);
	  }
	if (write(arq, linha2, strlen(linha2)) == -1) 
	  {
	    printf("Write: %s\n", strerror(errno));
	    exit(8);
	  }
	close(arq);

}

int main()
{
	//criaDir();
	//removerDir();
	//moveDir();
	//linkar();
	
	return 0;
}