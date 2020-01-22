#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
char nome[30];
int ra;
char curso[30];
}aluno;

typedef struct{
   int idsem;
   struct{
      int idmat;
      char nomem[30];
      struct{
   int idaluno;
       float n1,n2,n3,media;
   }aluno[100];
   }materia[100];
}semestre;

int main(int argc, char *argv[]) {

int x,y,z,a,na,ns,nm;
float maior=0;
char nomemaior[30],nomemaiorcurso[30];


int op;

printf("Digite o numero de alunos\n");
scanf("%d",&na);
printf("Digite o numero de semestres\n");
scanf("%d",&ns);
printf("Digite o numero de materias\n");
scanf("%d",&nm);


aluno aluno[na];
semestre semestre[ns];


do{
 
printf("-----CADASTRO DE ALUNO-----\n");
printf("Digite 1 para inserir os dados de Alunos\n");
printf("Digite 2 para inserir os dados de Materias\n");
printf("Digite 3 para inserir os alunos nas Materias\n");
printf("Digite 4 para consultar os dados de Alunos\n");
printf("Digite 5 para consultar melhor aludo da Materia\n");
printf("Digite 0 para SAIR\n");
scanf("%d",&op);
printf("\n");

switch(op){
 
   case 1:
     printf("\nCADASTRANDO DADOS...\n\n");
     printf("Alunos...\n\n");
     for(x=0;x<na;x++){
       printf("Nome do Aluno %d\n",(x+1));
       scanf("%s",&aluno[x].nome);
       printf("RA\n");
       scanf("%d",&aluno[x].ra);
       printf("Curso\n");
       scanf("%s",&aluno[x].curso);
     printf("\n\n");
  }
    break;
 
   case 2:
    printf("\nCADASTRANDO DADOS...\n\n");
    printf("Semestres e Materias...\n\n");
      for(x=0;x<ns;x++){
       printf("Semestre %d\n\n",(x+1));
       semestre[x].idsem = (x+1);
       for(y=0;y<nm;y++){
         semestre[x].materia[y].idmat = (y+1);
         printf("Nome da Materia %d\n",(y+1));
         scanf("%s",&semestre[x].materia[y].nomem);
           }
       printf("\n\n");
      } 
 break;

 case 3:
  printf("\nCADASTRANDO DADOS...\n\n");
  printf("Inserindo alunos nas materias...\n\n");
  int idsem,idmat,idaluno;

  printf("Digite o numero do semestre\n");
  scanf("%d",&idsem);

  for(x=0;x<ns;x++){
   if(idsem==semestre[x].idsem){
    printf("Digite o numero da materia\n");
    scanf("%d",&idmat);
    for(y=0;y<nm;y++){
     if(idmat==semestre[x].materia[y].idmat){
      printf("Digite o RA do Aluno\n");
      scanf("%d",&idaluno);
      for(z=0;z<na;z++){  
      if(idaluno==aluno[z].ra){
       semestre[x].materia[y].aluno[z].idaluno=idaluno;
       
       printf("Aluno: %s\nCurso: %s\n",aluno[z].nome,aluno[z].curso);
       printf("N1\n");
            scanf("%f",&semestre[x].materia[y].aluno[z].n1);
            printf("N2\n");
            scanf("%f",&semestre[x].materia[y].aluno[z].n2);
            printf("N3\n");
            scanf("%f",&semestre[x].materia[y].aluno[z].n3);
   
            semestre[x].materia[y].aluno[z].media = (semestre[x].materia[y].aluno[z].n1*0.5) + (semestre[x].materia[y].aluno[z].n2*0.3) + (semestre[x].materia[y].aluno[z].n3*0.2);
            printf("Media de %s\n",semestre[x].materia[y].nomem);
            printf("%0.1f",semestre[x].materia[y].aluno[z].media);
            printf("\n\n");
   
       }
      }
     }
    } 
   }
 break;
 
   case 4:
     printf("\nMOSTRANDO DADOS...\n\n");
     int ncadastro;
     printf("Digite o RA do Aluno que deseja pesquisar\n");
     scanf("%d",&ncadastro);
     printf("\n");
     for(x=0;x<na;x++){
     	if(ncadastro==aluno[x].ra){
      	printf("---------------------------------------------\n");
   		printf("Nome do Aluno: %s\nRA: %d\nCurso: %s\n\n",aluno[x].nome,aluno[x].ra,aluno[x].curso);
      	for(y=0;y<ns;y++){
       		printf("Semestre %d | \n",(y+1));
    		for(z=0;z<nm;z++){
     			printf("Nome da Materia: %s\n\n",semestre[y].materia[z].nomem);
         		 for(a=0;a<na;a++){
         		 	if(ncadastro==semestre[y].materia[z].aluno[a].idaluno){
          			printf("N1  | N2  | N3  | MEDIA\n");
         			printf("%0.1f | %0.1f | %0.1f | %0.1f\n",semestre[y].materia[z].aluno[a].n1,semestre[y].materia[z].aluno[a].n2,semestre[y].materia[z].aluno[a].n3,semestre[y].materia[z].aluno[a].media);
       
          			if(semestre[y].materia[z].aluno[a].media>=6){
            			printf("Aprovado em %s\n",semestre[y].materia[z].nomem);
          			}else{
           				printf("Reprovado em %s\n",semestre[y].materia[z].nomem);
          			}
          			printf("\n");
          			
					}
          		}
        	}  
   		}
   		printf("---------------------------------------------\n");
    	}
    	
		}
  	 }
     break;
   
   case 5:
    
  
  
  

  printf("Digite o numero do semestre\n");
  scanf("%d",&idsem);

  for(x=0;x<ns;x++){
   if(idsem==semestre[x].idsem){
    printf("Digite o numero da materia\n");
    scanf("%d",&idmat);
    for(y=0;y<nm;y++){
     if(idmat==semestre[x].materia[y].idmat){
      
      for(z=0;z<na;z++){ 
    	
	   		if(semestre[x].materia[y].aluno[z].media>maior){
	   			maior=semestre[x].materia[y].aluno[z].media;
	   			strcpy(nomemaior, aluno[z].nome);
	   			strcpy(nomemaiorcurso, aluno[z].curso);
	   			
	   		}
   			
		}
	   
	   printf("\nMelhor aluno de %s\n",semestre[x].materia[y].nomem);      
       printf("Aluno: %s\nCurso: %s\n",nomemaior,nomemaiorcurso);
       printf("Media\n");
            printf("%0.1f",maior);
            printf("\n\n");
   
       }
      }
     }
    } 
    
    
   break; 
   
 case 0:
     exit(1);  
   break;
 
 default:
     printf("Comando invalido!\n");
   break;
}

}while(1);

system("pause");
return 0;
}
