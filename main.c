#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//start project naghavi moghaddam

char command_save[200];//for saving the command
char fristword[30];//for saving frist word
//this function saves frist word in fristword array
int frist_word(){
for(int i1=0;i1<30;i1++){
    if(command_save[i1]==' '){
        return 1;

}
fristword[i1]=command_save[i1];
}
return 1;
}
int is_valid_one(){
if(command_save[0]=='\n'){
    return 2;
}
if((!strcmp(fristword,"create"))||(!strcmp(fristword,"insert"))||(!strcmp(fristword,"cat"))||(!strcmp(fristword,"remove"))||(!strcmp(fristword,"copy"))||(!strcmp(fristword,"paste"))||(!strcmp(fristword,"find"))||(!strcmp(fristword,"replace"))||(!strcmp(fristword,"grep"))||(!strcmp(fristword,"undo"))||(!strcmp(fristword,"auto-indent"))){
    return 1;
}
if((!strcmp(fristword,"compare")||(!strcmp(fristword,"tree"))||(!strcmp(fristword,"finish")))){
    return 1;
    }
return 0;
}
int main(){
system("color 40");//red
system("cls");//clean the screen
while(1){
gets(command_save);
if(!is_valid_one()){
    printf("invalid command");
    printf("\n");
}
if(is_valid_one()){
    puts(command_save);
}
if(!strcmp(fristword,"finish")){
    break;
}

}
return 0;
}
