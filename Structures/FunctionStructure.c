#include<stdio.h>
#include<string.h>

typedef struct pokemon {
    char name[20];
    int hp;
    int speed;
    int attack;
    char tear;
} pokemon;

void fun(pokemon p){
    printf("HP: %d\n",p.hp);
    printf("Speed: %d\n",p.speed);
    printf("Attack: %d\n\n",p.attack);
    return;
}

void change(pokemon q){
    q.attack=200;
    return;
}

int main(){
    pokemon pikachu;
    pikachu.hp=70;
    pikachu.speed=110;
    pikachu.attack=90;

    fun(pikachu);
    change(pikachu);

    printf("Attack: %d\n",pikachu.attack);

    return 0;
}