#include<stdio.h>
#include<string.h>
int main(){    
typedef struct pokemon {
    int hp;
    int speed;
    int attack;
    char tear;
} pokemon;

    pokemon pikachu;
    pikachu.hp=70;
    pikachu.speed=110;
    pikachu.attack=90;
    pikachu.tear='A';

    printf("\n%p\n",&pikachu.hp);
    printf("%p\n",&pikachu.speed);
    printf("%p\n",&pikachu.attack);
    printf("%p\n\n",&pikachu.tear);

    pokemon* x=&pikachu;
    printf("%p\n\n",x);

    return 0;
}