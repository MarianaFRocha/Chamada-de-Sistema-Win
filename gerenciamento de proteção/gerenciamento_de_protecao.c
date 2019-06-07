#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include<fcntl.h>


int cs_chmod()
{
	open("teste", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	system("ls -l");

   	int rt;
   	rt = chmod("teste", S_IRUSR|S_IRGRP|S_IROTH);
   	if (rt == -1)
      	printf("Erro chmod() %d: %s\n", errno, strerror(errno)); 

    system("ls -l");
}

int imprimeUID()
{
   	uid_t uid;
	uid = getuid();
    printf("UID: %u\n", uid);
}


int imprimiGID()
{
  	gid_t gid;
  	gid = getgid();
    printf("GID: %d \n", gid);
}


int geteuid_setreuid()
{
	  uid_t euid, ruid;

	  ruid = getuid ();   //Lê o UID real
  	euid = geteuid ();  //Lê o UID efetivo
  	printf("ruid antigo: %d euid: %d\n", ruid, euid);
  	if(setreuid (euid, ruid) != 0)  //Trasnforma o UID efetivo em UID real
  		printf("erro ao estabelecer novo UID real\n");

  	printf("ruid novo: %d\n", euid);

}

int main(int argc, char const *argv[])
{
  //cs_chmod();
  //imprimeUID();
  //imprimiGID();
  //geteuid_setreuid();
  
  return 0;
}