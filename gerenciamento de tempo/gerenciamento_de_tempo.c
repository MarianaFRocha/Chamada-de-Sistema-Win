#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>
#include <stdlib.h>
#include <inttypes.h>


int cs_time()
{
    time_t tempo;
    struct tm tempoAtual;
    time(&tempo); 

    printf("Quantidade de segundos desde 01/01/1970: %ld\n", tempo);

    tempoAtual = *localtime(&tempo);

    printf("Data  = %i/%i/%i\n", tempoAtual.tm_mday, tempoAtual.tm_mon+1, tempoAtual.tm_year+1900);
    printf("Horas = %i:%i\n", tempoAtual.tm_hour, tempoAtual.tm_min);

    return 0;

}

int cs_utime()
{
    time_t tempoAtual;
         
    tempoAtual = time(NULL); // Obtem o tempo corrente

    if(stime(&tempoAtual) != 0)  //Estabelece o tempo corrente com novo time
        printf("Erro ao establecer novo time\n");
    
    return 0;
}

int modUltAcess()
{
    int fd = open("teste", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    close(fd);
    printf("Antes do utime:\n");
    system("ls -l");

    struct utimbuf timebuf;

    /*Pego o tempo inicial do sitema*/ 
    timebuf.modtime = 0;
    time(&timebuf.actime);

    if (utime("teste", &timebuf) < 0) { // modifica o tempo de ultimo acesso do arquivo teste
        printf("Erro ao executar utime\n");
        return 0;
    }
    printf("Depois do utime\n");
    system("ls -l");
}



int cs_times()
{
    struct tms tempo;

    times(&tempo);

    printf("Tempo.tms_utime = %jd\n\n",  (intmax_t)tempo.tms_utime);
    printf("Tempo.tms_cutime = %jd\n\n", (intmax_t)tempo.tms_cutime);
    printf("Tempo.tms_stime = %jd\n\n",  (intmax_t)tempo.tms_stime);
    printf("Tempo.tms_cstime = %jd\n\n",  (intmax_t)tempo.tms_cstime);

    return 0;
}

int main()
{
    //cs_time();
    //cs_utime();
    //modUltAcess();
    //cs_times();

    return 0;
}
