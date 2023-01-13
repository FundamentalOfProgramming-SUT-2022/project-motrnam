#include <stdio.h>

char word[70][70];
char line[600];

void line_to_word(){
int i1=0;
int i2=0;
int i3=0;
char start;
start=' ';
while(line[i1]!='\n'){
    i2=0;
    while((line[i3]!=start)&&(line[i3]!=start)&&(line[i3]!=start)){
        word[i1][i2]=line[i3];
        i3++;
    }
    i1++;
    i3++;
    if(line[i3]!='”'){

    }
}
}
