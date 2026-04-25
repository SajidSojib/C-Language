#include<stdio.h>
#include<string.h>
int main(){
    typedef struct pokemon
    {
        char name[20];
        int hp;
        int speed;
        int attack;
        char tear;
    } pokemon;
    
    pokemon arr[3];

    strcpy(arr[0].name,"Pikachu");
    arr[0].hp=70;
    arr[0].speed=110;
    arr[0].attack=90;
    arr[0].tear='A';

    strcpy(arr[1].name,"Charizard");
    arr[1].hp=90;
    arr[1].speed=100;
    arr[1].attack=120;
    arr[1].tear='S';

    strcpy(arr[2].name,"Mewtwo");
    arr[2].hp=200;
    arr[2].speed=130;
    arr[2].attack=180;
    arr[2].tear='G';

    for (int i = 0; i < 3; i++)
    {
    printf("\n%s\n",arr[i].name);
    printf("HP: %d\n",arr[i].hp);
    printf("Speed: %d\n",arr[i].speed);
    printf("Attack: %d\n",arr[i].attack);
    printf("Tear: %c\n",arr[i].tear);
    }
    


    return 0;
}