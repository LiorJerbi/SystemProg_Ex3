#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

void shift_elemnt(int *arr, int i){
    int temp=0;
    for(int counter=0;counter<i;counter++){
        temp=(int)*(arr-counter-1);
        *(arr-counter)=temp;
        *(arr-counter-1)=0;
    }
}

void insertion_sort(int *arr, int len){
    for(int i=1;i<len;i++){
        int counter=1,temp=0;
        while(i>=counter){
        if(*(arr+i)<*(arr+i-counter)){
            temp=*(arr+i);
            counter++;
        }
        else{
            break;
        }
        }
        counter--;
        if(counter>0){
        shift_elemnt((arr+i),counter);
        *(arr+i-counter)=temp;
        }
    }
}


int main(){

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