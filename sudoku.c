#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    int arreglo[9][9];
    int i,j,k,z;
    for(i=0; i<9 ;i++){
      for(j=0; j<9 ;j++){
        arreglo[i][j] = n->sudo[i][j];
      }
    }
    for(i=0; i<9 ;i++){
      for(j=0; j<9 ;j++){
        if(n->sudo[i][j] != 0){
          for(k=0; k<9 ;k++){
            if((arreglo[k][j] == n->sudo[i][j]) && (k != i)){
              return 0;
            }
          }
          for(z=0; z<9 ;z++){
            if((arreglo[i][z] == n->sudo[i][j]) && (z != j)){
              return 0;
            }
          }
        }
      }
    }
   return 1;
}

List* get_adj_nodes(Node* n){
    List* list=createList();
    int i,j,k;
    for(i=0; i<9 ;i++){
      for(j=0; j<9 ;j++){
        if(n->sudo[i][j]==0){
          for(k=1; k<=9 ;k++){
            n->sudo[i][j]=k;
            if(is_valid(n)){
              Node * nuevo = copy(n);
              pushBack(list,nuevo);
            }
          }
          n->sudo[i][j]=0;
          return list;
        }
      }
    }
    return list;
}


int is_final(Node* n){
  /*
    int i,j;
    for(i=0; i<9 ;i++){
      for(j=0; j<9 ;j++){
        if(n->sudo[i][j] == '\0'){
          return 0;
        }
      }
    }*/
    return 1;
}

Node* DFS(Node* initial, int* cont){
  /*
  Stack * S = createStack();
  push(S, initial);
  while(is_empty(S) != 1){
    cont++;
    Node * node = top(S);
    pop(S);
    if(is_final(node)){
      return node;
    }
    List * lista = createList();
    lista = get_adj_nodes(node);
    Node* nod = first(lista);
    while(nod != NULL){
      push(S,nod);
      nod = next(lista);
    }
    free(node);
    free(nod);
  }*/
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/