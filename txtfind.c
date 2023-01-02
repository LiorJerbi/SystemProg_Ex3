#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30

int get_line(char s[]){
    int charCount = 0;
    char c = '\n';
    while(1){
        scanf("%c",&c);
        if(c!=EOF&&c!='\n'&&c!='\r'){
            //printf("%ld ",(sizeof(char)*charCount));
            *(s+(sizeof(char)*charCount))=c;
            charCount++;
        }
        else{
            break;
        }
    }
    return charCount;
}

int getword(char w[]){
    int charCount = 0;
    char c = '\0';
    while(1){
        scanf("%c",&c);
        if(c!='\n'&&c!=EOF&&c!='\t'&&c!=' '&&c!='\0'){
        *(w+(sizeof(char)*charCount))= c;
        charCount++;
        }
        else{
            break;
        }
    }
    return charCount;    
}

int substring(char *str1, char *str2){
    int l1=strlen(str1),l2=strlen(str2),counter=0;
    for(int i=0;i<l1&&counter<l2;i++){
        if(*(str1+i)==*(str2+counter)){
            counter++;
        }
        else{
            counter=0;
        }
    }
    if(counter==l2){
        return 1;
    }
    else{
        return 0;
    }
}

int similar(char *s,char *t,int n){
    int l1=strlen(s),l2=strlen(t),counter=0,i;
    for(i=0;i<l1&&n>=0&&counter<l2;i++){
        if(*(s+i)==*(t+counter)){
            counter++;
        }
        else
        {
            n--;
        }
    }
    if(counter==l2){
        while(i<l1&&n>0){
            n--;
            i++;
        }
        if(n==0&&i==l1){
        return 1;
        }
    }
    return 0;

}

void print_lines(char *str){
    while(1){
        char line[LINE]={"\0"};
        int countl = 0,j=0;
        countl = get_line(line);
        //printf("countl=%d , checkline:%s , compare str:%s \n",countl,line,str);
        if(countl<=0){
            break;
        }
        else{
            while(j<countl){
                char word[WORD]={'\0'};
                for (int i=0;i<WORD;i++)
                {   
                    if(line[j]=='\0'||line[j]==' '){
                        j++;
                        break;
                    }
                    else{
                    word[i]=line[j];
                    j++;
                    }
                }
                if(substring(word,str)){
                    j=countl;
                    printf("%s\n",line);
                }
            }
        }
    }
}

void print_similar_word(char *str){
    while(1){
        char word[WORD]={"\0"};
        int countw = getword(word);
        //printf("%s :\n",word);
        if(countw<=0){
            break;
        }
        else{
            if(similar(word,str,1)||similar(word,str,0)){
                printf("%s\n",word);
            }
        }
    
    }
}

int main(){
    char word[WORD] = {'\0'};
    getword(word);
    //printf("%s\n",word);
    char c = '\0';
    scanf("%c",&c);
    getchar();
    getchar();
    if(c=='a'){
        print_lines(word);
    }
    else if (c=='b'){
        print_similar_word(word);
    }

    return 0;
    
}