#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//work09
struct pokemon {
  char *name;
  int hp;
  int atk;
  struct pokemon *next;
};

void print_pokemon(struct pokemon *p){
  printf("POKEMON: %s \t HP: %d \t ATTACK: %d\n", p->name, p->hp, p->atk);
}

struct pokemon * make_pokemon(char* poke, int hitPoints, int attackPower){
  struct pokemon *p;
  p = malloc(sizeof(struct pokemon));
  
  p->name = poke;
  p->hp = hitPoints;
  p->atk = attackPower;
  return p;
}

//work10
//takes a pointer to a node struct and prints out all of the data
void print_list(struct pokemon *p){
  while(p){
    print_pokemon(p);
    printf("\n");
    p = p->next;
  }
}

//take pointer to existing list and data to be added
//create a new node and put it at beginning of list.
struct pokemon * insert_front(struct pokemon *p, char *name, int hp, int atk){
  struct pokemon *front = make_pokemon(name, hp, atk);
  return front;
}

//take pointer to list as parameter
//go through list freeing each node 
//return a pointer to the beginning of the list 
struct pokemon * free_list(struct pokemon *p){
  if (p->next != 0){
    free_list(p->next);
    free(p);
  }
  return p;
}

int main(){
  srand(time(NULL));

  struct pokemon *p1 = make_pokemon("CHARZARD", rand(), rand());
  print_pokemon(p1);
  free(p1);
  struct pokemon *p2 = make_pokemon("BLASTOISE", rand(), rand());
  print_pokemon(p2);
  free(p2);
  struct pokemon *p3 = make_pokemon("VENUSAUR", rand(), rand());
  print_pokemon(p3);
  free(p3);
  
  print_list(p1);
  print_list(p2);
  print_list(p3);

  printf("Freed List: \n");
  p3 = free_list(p3);
  print_list(p3);

  return 0;
}
