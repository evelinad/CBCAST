/** Simple server that calls (or is called) by another RPC server.

    Author: Avelino F. Zorzo
    avelino.zorzo@pucrs.br

    Date: 13.04.2012
    Modified: 13.04.2012

**/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "cbcast.h"
#include "_cbcast.h"




int *creategroup_1_svc(cbcast_params *params, struct svc_req *req)
{
    if (params == NULL)
        return -1;
    
}

int * joingroup_1_svc(cbcast_params *params, struct svc_req *req)
{
    if (params == NULL)
        return -1;
    
}

int * leavegroup_1_svc(cbcast_params *params, struct svc_req *req)
{
    if (params == NULL)
        return -1;
    
}

int * sendgroup_1_svc(cbcast_params *params, struct svc_req *req)
{
    if (params == NULL)
        return -1;
    
}

int * receivegroup_1_svc(cbcast_params *params, struct svc_req *req)
{
    if (params == NULL)
        return -1;
    
}






#if 0

pthread_t tid1;  /* Descritores para as threads */
char clt_address[32];
FILE *flog;    /* debug do sistema */

/* Rotina a ser executada por uma das threads */
void *p1 () {
  
    CLIENT *cl;
    int *answer;
    void *pvoid;

     fprintf(flog,"P1: entrando. Vou comunicar com = %s\n",clt_address);
     fflush(flog);

    // connect to the server that was send through the start routine

    if (!(cl = clnt_create(clt_address, CBCASTPROG,CBCASTVERS,"tcp"))) { 
        fprintf(flog,"P1: Error: could not create a connection wiht -%s-\n",clt_address); 
        fflush(flog); fclose(flog);
        return(1); 
    } 

    answer = numero_1(pvoid,cl); 

    if (answer == (int *) NULL) { 
        fprintf(flog,"P1: Error: state could not produce meaningful results"); 
        fflush(flog); fclose(flog);
        return(1); 
    } 

   fprintf(flog,"P1: saindo. valor = %d\n",*answer);
   fflush(flog);
   fclose(flog);
  
}

int *numero_1_svc(void *pvoid, struct svc_req *rqstp) {

   static int valor = 15;

   return &valor;
}

int *start_1_svc(char **endereco, struct svc_req *rqstp) {

       static int first = 1;
       static int result;
       pid_t processo;
       char temp[20];


       if (first) {
   
   	  /* pega o pid deste processo */
   
          processo = getpid ();
          sprintf (temp,"cbcast.log.%d",processo);
     	  /* abre o arquivo de log  */
   
          flog  = fopen (temp,"w");

          sprintf(clt_address,"%s",*endereco);

          fprintf(flog,"Start: Endereco = %s %s\n",*endereco,clt_address);
          fflush(flog);
         
          result = pthread_create(&tid1, NULL, p1, NULL);
          first = 0;
       }

       return &result;
}
#endif