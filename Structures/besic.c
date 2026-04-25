#include<stdio.h>
#include<string.h>
int main(){
    struct pokemon
    {
        char name[20];
        int hp;
        int speed;
        int attack;
        char tear;
    } pikachu,charizard;
   // struct pokemon pikachu;
    strcpy(pikachu.name,"Pikachu");
    pikachu.hp=70;
    pikachu.speed=110;
    pikachu.attack=90;
    pikachu.tear='A';

   // struct pokemon charizard;
    strcpy(charizard.name,"Charizard");
    charizard.hp=90;
    charizard.speed=100;
    charizard.attack=120;
    charizard.tear='S';

    printf(" %s\n",pikachu.name);
    printf("HP: %d\n",pikachu.hp);
    printf("Speed: %d\n",pikachu.speed);
    printf("Attack: %d\n",pikachu.attack);
    printf("Tear: %c\n\n",pikachu.tear);

    printf(" %s\n",charizard.name);
    printf("HP: %d\n",charizard.hp);
    printf("Speed: %d\n",charizard.speed);
    printf("Attack: %d\n",charizard.attack);
    printf("Tear: %c",charizard.tear);

    return 0;
}
 

// #include<stdio.h>
// #include<string.h>
// int main(){
//     typedef struct pokemon
//     {
//         char name[20];
//         int hp;
//         int speed;
//         int attack;
//         char tear;
//     } pokemon;
//     pokemon pikachu={"Pikachu",90,110,100,'A'};
//     pokemon charizard={"Charizard",110,90,125,'S'};

//     printf(" %s\n",pikachu.name);
//     printf("HP: %d\n",pikachu.hp);
//     printf("Speed: %d\n",pikachu.speed);
//     printf("Attack: %d\n",pikachu.attack);
//     printf("Tear: %c\n\n",pikachu.tear);

//     printf(" %s\n",charizard.name);
//     printf("HP: %d\n",charizard.hp);
//     printf("Speed: %d\n",charizard.speed);
//     printf("Attack: %d\n",charizard.attack);
//     printf("Tear: %c",charizard.tear);

//     return 0;
// }