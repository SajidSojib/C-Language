#include<stdio.h>
#include<string.h>
int main(){
    typedef struct pokemon {
        char name[20];
        int hp;
        int speed;
        int attack;
        char tear;
    } pokemon;

    typedef struct legendary{
        char ability[50];
        pokemon stats;
    } legendary;

    typedef struct god{
        int  sp_att;
        legendary power;
    } god;
    

    pokemon pikachu;
    strcpy(pikachu.name,"Pikachu");
    pikachu.hp=70;
    pikachu.speed=110;
    pikachu.attack=90;
    pikachu.tear='A';

    legendary mewtwo;
    strcpy(mewtwo.stats.name,"Mewtow");
    mewtwo.stats.hp=120;
    mewtwo.stats.speed=110;
    mewtwo.stats.attack=150;
    mewtwo.stats.tear='S';
    strcpy(mewtwo.ability,"Intimidation");

    god arcius;
    strcpy(arcius.power.stats.name,"Arcius");
    arcius.power.stats.hp=180;
    arcius.power.stats.speed=150;
    arcius.power.stats.attack=200;
    arcius.power.stats.tear='G';
    strcpy(arcius.power.ability,"Creator Of all Things");
    arcius.sp_att=285;

    printf("\n%s\n",pikachu.name);
    printf("HP: %d\n",pikachu.hp);
    printf("Speed: %d\n",pikachu.speed);
    printf("Attack: %d\n",pikachu.attack);
    printf("Tear: %c\n\n",pikachu.tear);
    

    printf("%s\n",mewtwo.stats.name);
    printf("HP: %d\n",mewtwo.stats.hp);
    printf("Speed: %d\n",mewtwo.stats.speed);
    printf("Attack: %d\n",mewtwo.stats.attack);
    printf("Tear: %c\n",mewtwo.stats.tear);
    printf("Ability: %s\n\n",mewtwo.ability);


    printf("%s\n",arcius.power.stats.name);
    printf("HP: %d\n",arcius.power.stats.hp);
    printf("Speed: %d\n",arcius.power.stats.speed);
    printf("Attack: %d\n",arcius.power.stats.attack);
    printf("Tear: %c\n",arcius.power.stats.tear);
    printf("Ability: %s\n",arcius.power.ability);
    printf("Special Attack: %d\n",arcius.sp_att);

    return 0;
}