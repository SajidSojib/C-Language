#include<stdio.h>
#include<stdlib.h>

#define max 10
int arr[max];
int count = 0;
int front=0;
int rear= 0;

int main(){
    int truckID[max] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};

    // adding 6 truck
    for (int i = 0; i < 6; i++)
    {
        if(rear==0){
            arr[rear]=truckID[rear];
            printf("%d is added to the queue\n", arr[rear]);
            front = i;
            rear= (rear+1)%max;
            count++;
        }
        else{
            arr[rear]=truckID[rear];
            printf("%d is added to the queue\n", arr[rear]);
            rear = (i + 1) % max;
            count++;
        }
    }

    // removing two truck
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%d is removed from the queue\n", arr[front]);
        front=(front+1)%max;
        count--;
    }

    // again adding two truck
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        if (rear == 0)
        {
            arr[rear] = truckID[rear];
            front = i;
            rear = (i + 1) % max;
            count++;
        }
        else
        {
            arr[rear] = truckID[rear];
            printf("%d is added to the queue\n", arr[rear]);
            rear = (rear + 1) % max;
            count++;
        }
    }

    printf("\n\n");

    // printing the queue
    int j=count;
    for (int i = front; j > 0; j--)
    {
        printf("%d < ", arr[i]);
        i=(i+1)%max;
    }
    printf("X ");

    return 0;
}