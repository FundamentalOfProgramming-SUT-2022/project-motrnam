#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//start project naghavi moghaddam

char command_save[600];//for saving the command
char fristword[30];//for saving frist word
//this function saves frist word in fristword array
char word[70][70];
char line[600];
char test[20];
char name_of_new_file[20];
char temp_address[70];//saving address

clean_word(){
for(int i=0;i<70;i++){
    for(int j=0;j<70;j++){
        word[i][j]='\0';
    }
}
for(int u=0;u<600;u++){
    command_save[u]='\0';
}
}
//word pro
void line_to_word(){
int i1=0;
int i2=0;
int i3=0;
char start;
start =132;
int is_started_with=0;
int stop=0;
while((command_save[i3]!='\n')&&(command_save[i3]!=0)){
    i2=0;
    is_started_with=0;
    stop=0;
    while(((command_save[i3]!=' ')&&(command_save[i3]!='\n')&&(command_save[i3]!='\0'))){
        if(stop==1){
            if(line[i3]=='”'){
            break;
          }
          }
        if(command_save[i3]!='”'){
        word[i1][i2]=command_save[i3];
        i3++;
        i2++;}
        if(line[i3]=='”'){
            i3++;
            stop=1;
            is_started_with=1;
        }
    }
    i1++;
    i3++;
    //printf("%i %i  \n",i1,i2);
}
}
int frist_word(){

for(int i1=0;i1<30;i1++){
    if(command_save[i1]==' '){
        return 1;
}
fristword[i1]=command_save[i1];
}
return 1;
}
//erase temp_address array
void clean(){
for(int f=0;f<70;f++){
   temp_address[f]='\0';
}
}
void clean_name(){
for(int f=0;f<20;f++){
   name_of_new_file[f]='\0';
}
}

int is_valid_one(){
    frist_word();
if(command_save[0]=='\n'){
    return 2;
}
if((!strcmp(fristword,"createfile"))||(!strcmp(fristword,"insert"))||(!strcmp(fristword,"cat"))||(!strcmp(fristword,"remove"))||(!strcmp(fristword,"copy"))||(!strcmp(fristword,"paste"))||(!strcmp(fristword,"find"))||(!strcmp(fristword,"replace"))||(!strcmp(fristword,"grep"))||(!strcmp(fristword,"undo"))||(!strcmp(fristword,"auto-indent"))){
    return 1;
}
if((!strcmp(fristword,"compare")||(!strcmp(fristword,"tree"))||(!strcmp(fristword,"finish")))){
    return 1;
    }
return 0;
}
//https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c
//checking exitance a file
int has_file(char file_name[100])
{
    FILE * myfile;
    if ((myfile = fopen(file_name, "r")))
    {
        fclose(myfile);
        return 1;
    }
    return 0;
}
int main(){
system("color 40");//red
system("cls");//clean the screen
while(1){
clean_word();
clean();
clean_name();
gets(command_save);
line_to_word();
if(!is_valid_one()){
    printf("invalid command");
    printf("\n");
}
if(!strcmp(fristword,"finish")){
    break;
}
if(!strcmp(fristword,"createfile")){
    //mkdir("ali");
    //mkdir("ali/alii");
        printf("sal");
    if(has_file(word[2])){
        printf("This file exists already\n");
    }
    else{
        int j1=0;
        int j2=0;

    while(word[2][j1]!='.'){

        temp_address[j1]=word[2][j1];
        if(temp_address[j1]=='/'){
            clean_name();
        j2=0;
            mkdir(temp_address);

        }
        j1++;
        name_of_new_file[j2]=word[2][j1];
    }
    FILE* naghavi;
    naghavi = fopen(word[2],"w+");
    fclose(naghavi);
    }
}
}
return 0;
}
