#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30
/*this program gets an string to check and has 2 options:
1)if gets 'a' from the client: checks the given text for lines that contain the given string, and printes them.
2)if gets 'b' from the client: checks the given text for words that are similiar to the given string, and prints them.
*/

//method to receive lines from the standart input char by char and save it in an given String.
//return the amount of letters that had actually received.
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

//method to receive words from the standart input char by char and save it in an given String.
//return the amount of letters that had actually received.
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

/*
given two strings(str1,str2), the method checks whether str2 is contained in str 1.
return 1 if yes, 0 else.
*/
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

/*
given two strings(s,t) and an integer n,the method checks if we can get to s from t with only ommiting 'n' letters from it.
return 1 if yes, 0 else.
*/
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

/*
this method actually checks whether given string 'str' contained in the text lines.
if do the method will print that line, else ignore.
*/
void print_lines(char *str){
    while(1){
        char line[LINE]={"\0"};
        int countl = 0,j=0;
        countl = get_line(line);    //reads new line from the text and saves it un 'line', 'countl' gets the number of letters actually read.
        if(countl<=0){              //stops when not getting more words.
            break;
        }
        else{
            while(j<countl){
                char word[WORD]={'\0'};
                for (int i=0;i<WORD;i++)        //copy the next word in line to 'word'.
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
                if(substring(word,str)){        //if 'word' contains 'str' printing the line that conatins 'word'.
                    j=countl;
                    printf("%s\n",line);
                }
            }
        }
    }
}

/*
this method actually checks whether given string 'str' has similar words(with ommiting maximum 1 letter) in the text.
if do the method will print that word, else ignore.
*/
void print_similar_word(char *str){
    while(1){
        char word[WORD]={"\0"};
        int countw = getword(word);     //reads new word from the text and saves it in 'word', countw gets the number of letters actually read.
        if(countw<=0){                  //stops when no more words to read.
            break;
        }
        else{
            if(similar(word,str,1)||similar(word,str,0)){   //if we can get 'str' from 'word' by ommiting max 1 letter print the word.
                printf("%s\n",word);
            }
        }
    
    }
}

// main to use the methods above.
int main(){     
    char word[WORD] = {'\0'};
    getword(word);              //gets the word to check for
    char c = '\0';
    scanf("%c",&c);             //gets the client choice what to check for.
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