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
if((!strcmp(fristword,"create"))||(!strcmp(fristword,"create"))||(!strcmp(fristword,"create"))||(!strcmp(fristword,"create"))||(!strcmp(fristword,"create"))||(!strcmp(fristword,"create"))||(!strcmp(fristword,"create"))){
    return 1;
}
return 0;
}
int main(){
system("color 40");//red
system("cls");//clean the screen
gets(command_save);

return 0;
}
