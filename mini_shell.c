#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h> 
#define TRUE 1
#define MAX 200
void command(char command[MAX],char *argumento[30]){
  argumento[0]=strtok(command,"\0");
  for (int i=0;i<30;i++){
    strtok(NULL,"\0");
  }
}


int main(){
  int status;
  char promt[MAX];
  char *argumento[30];
  while(TRUE){
    printf("\nDigite o comando a ser soliciatado:      \t");
    if (fgets(promt, sizeof(promt)-1, stdin) ==           NULL) {
      printf("error");
      }else{
        promt[strcspn(promt, "\n")] = 0;
        fflush(stdin);
        command(promt,argumento);
        if (fork()!=0){
          waitpid(-1,&status,0);
          continue;
        }else{
          execve(argumento[0], argumento, 0);
        }
      
      }
    }
}

