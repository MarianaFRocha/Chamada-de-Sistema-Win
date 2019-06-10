#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <signal.h>
#include <unistd.h>


void cs_signal()
{
	int i;
	while(1){
		 signal(SIGINT, SIG_IGN); //Ignorando o sinal SIGINT que eh Interrupção (CTRL-C) 

		 printf("Nao eh possivel o uso do CTRL-C. Experimente!\n");
		 for(i=0; i<10; i++) {
			 sleep(1);  //espera um segundo entre cada loop do for para assim permitir que o use o CTRL-C
		 }

		 signal(SIGINT, SIG_DFL); // O sinal volta ao seu funcionamento 
		 printf("\nO CTRL-C voltou funcionar para finalizar a execucao do codigo\n");
		 sleep(10);
	}
}


	{

	pid_t pid = fork();

	if (pid == 0) {
		while(1) {
			
			printf("pid=%ld\n",getpid()); //Imprime o processo filho, demonstrando que ele ainda está vivo
			sleep(1); 
		}
	}
	else {
		sleep(5);  //O processo pai vai esperar 5 segundos para executar a proxima instrução
		kill(pid,SIGKILL);  // Vai "matar" o processo pid
		exit(0); 
	}
}


void mensagem(int signum)
{
   time_t tp;
   time(&tp);
   printf("%s", ctime(&tp));
}

void cs_alarm()
{
   signal(SIGALRM, mensagem);
   while (1)
     {
       alarm(5);
       pause();
     }
}

void sinal(int signal) {
   printf("sinal recebido!!\n");
}

int cs_raise () {
   int aux;

   aux = signal(SIGINT, sinal);

   printf("Vamos raise(aumentar) o signal\n");
   aux = raise(SIGINT);
   
   if(aux !=0) {
      printf("Error: nao foi possivel raise(aumentar) SIGINT signal.\n");
      exit(0);
   }
   
   return(0);
}

int main()
{
	//cs_signal();
	//cs_kill();
	//cs_alarm();
	//cs_raise();

	return 0;
}