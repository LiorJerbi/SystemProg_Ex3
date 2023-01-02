#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
//this program sorting a given array, Maximum sized 50.

//shifts 'i' elemnts to the given array pointer
void shift_elemnt(int *arr, int i){
    int temp=0; //temp variable to hold the shifted elements
    for(int counter=0;counter<i;counter++){
        temp=(int)*(arr-counter-1);
        *(arr-counter)=temp;
        *(arr-counter-1)=0;
    }
}

/*
sorting a given array with insertion sort Algo,
from the smallest num(in the first index) to the biggest num(in the last index).
*/
void insertion_sort(int *arr, int len){
    for(int i=1;i<len;i++){
        int counter=1,temp=0;   
        while(i>=counter){
        if(*(arr+i)<*(arr+i-counter)){     //checks if the elemnts before the value we are currently on are smaller
            temp=*(arr+i);
            counter++;
        }
        else{
            break;
        }
        }
        counter--;
        if(counter>0){                  //moving the value currently on.
        shift_elemnt((arr+i),counter);
        *(arr+i-counter)=temp;
        }
    }
}


int main(){     //main to run the methods

int arr[MAX_SIZE];
int k=0;
for(int i=0;i<MAX_SIZE;i++){
    scanf(" %d",&k);
    *(arr+i)=k;
}
insertion_sort(arr, MAX_SIZE);
for(int i=0;i<MAX_SIZE;i++){
    if(i==MAX_SIZE-1){
        printf("%d\n",*(arr+i));
    }
    else{
        printf("%d,",*(arr+i));
        }
}

    return 0;
}