#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>


int main(int argc, char * const argv[], char * const envp[]){
  
  /* cria um processo-filho*/
  pid_t pid; 
  pid = fork(); 

  /* verifica se ocorreu  um erro na criacao*/
  if(pid<0){  

    fprintf(stderr, "Fork Failed");
    return  1;
  }

  if(pid==0){  /* processo-filho  */
    printf("pid filho=%d \n", getpid());
    execve("./filho.sh", argv, envp);  //executa um outro programa, no caso um script

  }
  else{ /*  processo-pai  */
    printf("pid pai=%d \n", getpid());
    execve("./pai.sh", argv, envp);  //executa um outro programa, no caso um script
    wait(NULL); /* o pai esperara que o filho seja concluído*/ 

  }
  return  0;
}
