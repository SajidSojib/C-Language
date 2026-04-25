#include<stdio.h>
#include<string.h>
int main(){
    union pokemon
    {
        char name[20];
        int hp;
        int speed;
        int attack;
        char tear;
    } pikachu;

    //only take one(last) input
    strcpy(pikachu.name,"Pikachu");
    pikachu.hp=70;
    pikachu.speed=110;
    pikachu.attack=90;
    pikachu.tear='A';

    printf(" %s\n",pikachu.name);
    printf("HP: %d\n",pikachu.hp);
    printf("Speed: %d\n",pikachu.speed);
    printf("Attack: %d\n",pikachu.attack);
    printf("Tear: %c\n\n",pikachu.tear);

    return 0;
}