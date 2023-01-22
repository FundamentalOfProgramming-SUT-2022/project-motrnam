#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//https://github.com/FundamentalOfProgramming-SUT-2022/project-motrnam.git
//start project naghavi moghaddam

char junk[150];
char command_save[600];//for saving the command
char fristword[30];//for saving frist word
//this function saves frist word in fristword array
char word[20][500];
char line[600];
char line2[300];//reading from file
char test[20];
char name_of_new_file[20];
char temp_address[70];//saving address
char first_lines[100][100];//saving first lines
char last_lines[100][100];//saving last lines
char clipcopy[4000];//for copy
char clipcut[4000];//for cut
//finding first element
char word_of_file[40];//for get input from file
char word_of_line_array[20][20];//word pro
//compare two number
int mini(int a,int b){
if(a<b){
    return a;
}
return b;
}
int remove_elment(char address[500],int start,int num_of_char){
FILE * temp;
FILE * org;
int fjt=0;
char movagh;
org=fopen(address,"r+");
temp=fopen("__temp.txt","w+");
for(;fjt<start;fjt++){
    movagh=fgetc(org);
    if(movagh==EOF){
        return -1;
    }
    fputc(movagh,temp);
}
for(int t=0;t<num_of_char;t++){
movagh=fgetc(org);
if(movagh==EOF){
    return -1;
}
}
while(movagh!=EOF){
    movagh=fgetc(org);
    if(movagh!=EOF){
    fputc(movagh,temp);
    }
}
fclose(org);
fclose(temp);
remove(address);
rename("__temp.txt",address);
return 0;
}

int has_star(char myword[]){
    int d=0;
for(int g=0;g<500;g++){
    if(myword[g]=='*'&&myword[(g+499)%500]!='\\'){
        myword[g]='\0';
        d=1;
    }
}
return 0;
}

int chanomin_karakteri(char add[500],int line,int col){
FILE * salam;
salam=fopen(add,"r+");
char temp;
int cur_line=1;
int cur_col=0;
int chand=0;
while(cur_line!=line||cur_col!=col){
    temp=fgetc(salam);
    if(temp=='\n'){
        cur_line++;
        cur_col=0;
    }
    else{
        cur_col++;
    }
    chand++;

}
fclose(salam);
return chand;
}

void satr_ston(int * line,int *col,int chand,char add[200]){
    FILE * tmp;
    tmp=fopen(add,"r+");
    char tem;
    int ht;
for(int i1=0;i1<chand;i1++){
    tem=fgetc(tmp);
    if(tem=='\n'){
        (*line)++;
        ht=*col;
        (*col)=0;
    }
    else{
        (*col)++;
    }
}
}
//finding word function
void all_element(char myinp[20],FILE * nagh){
fscanf(nagh,"%s");
}
int first_element1(FILE *fptr, const char *myword, int *l, int *c){
    char wordstr[200];
    int li;
    int len=0;
    *l = -1;
    *c = -1;

    while ((fscanf(fptr,"%s",wordstr)) != NULL)
    {
        *l += 1;
        len=len+strlen(wordstr)+1;
        li= strcmp(wordstr, myword);
        if (li==0)
        {
            break;
        }
    }
    if (*c == -1){
        *l = -1;
        return -1;}
    return len;
}
int first_element2(FILE *fptr, const char *myword, int *l, int *c){
    char wordstr[200];
    char *p;
    int len=0;
    *l = -1;
    *c = -1;

    while ((fgets(wordstr,200, fptr)) != NULL)
    {
        *l += 1;
        len=len+strlen(wordstr);
        p = strcmp(wordstr, myword);
        if (p != NULL)
        {
            *c = (p - wordstr);
            break;
        }
    }
    if (*c == -1){
        *l = -1;
        return -1;}
    return len;
}

int how_many_element(char add[500],char myword[20]){
    FILE * nagh;
nagh=fopen(add,"r+");
int num=0;
int i=0;
char myarray[50];
//char ar[1000][20];
while(!feof(nagh)){
    fscanf(nagh,"%s",myarray);
        if(!strcmp(myarray,myword)){
            num++;
        }

}
fclose(nagh);
return num;
}
int how_many_line(char ad[500]){
FILE * f;
f=fopen(ad,"r+");
int t=0;
char c;
c=fgetc(f);
while(c!=EOF){
    c=fgetc(f);
    if(c=='\n'){
        t++;
    }
}
fclose(f);
return (t+1);
}

void clean_word(){
for(int i=0;i<20;i++){
    for(int j=0;j<500;j++){
        word[i][j]='\0';
    }
}
for(int u=0;u<600;u++){
    command_save[u]='\0';
}
}
int is_acceptable(int number1){
if(command_save[number1]!='"'){
    return 1;
}
if(command_save[number1]=='"'){
    if(command_save[(number1+599)%600]=='\\'){
        return 1;
    }
    return 0;
}

}
void line_to_word(){
char naghavi=command_save[0];
int i1=0;
int i2=0;
int i3=0;
int ii=0;
int mode_of_coma=0;
int stop=0;
if(naghavi=='"'){
    mode_of_coma++;
}
while(command_save[ii]!='\n'&&command_save[ii]!='\0'){

    if(mode_of_coma%2==0){
        while(command_save[ii]!=' '&&command_save[ii]!='\0'&&command_save[ii]!='\n'){
                //printf("%c",command_save[ii]);

                stop=0;
                if(command_save[ii]=='\\'&&(command_save[(ii+1)%600]=='\\')){
                    word[i2][i1]='\\';
                    ii=ii+2;
                    i1++;
                    stop=1;
                }
                if(command_save[ii]=='\\'&&(command_save[(ii+1)%600]=='n')){
                    word[i2][i1]='\n';
                    ii=ii+2;
                    i1++;
                    stop=1;
                }
                if(command_save[ii]=='\\'&&(command_save[(ii+1)%600]=='"')){
                    word[i2][i1]='"';
                    ii=ii+2;
                    i1++;
                    stop=1;
                }
            if(command_save[ii]=='\\'&&stop==0){
                word[i2][i1]='\\';
                i1=ii+1;
            }
            if(command_save[ii]!='\\'){
            word[i2][i1]=command_save[ii];
            ii++;
            i1++;
            }
        }
        i2++;
        i1=0;
        if(command_save[ii+1]=='"'){
            mode_of_coma++;
            ii=ii+2;
        }
        if(command_save[ii+1]!='"'){
            ii++;
        }
        //ii=ii+2;
    }
    if(mode_of_coma%2==1){
            i1=0;
            ii--;
        while(is_acceptable(ii)){
                //printf("%i\n",ii);
            stop=0;
            if(command_save[ii]=='\\'&&(command_save[(ii+1)%600]=='\\')){
                    word[i2][i1]='\\';
                    ii=ii+2;
                    i1++;
                    stop=1;
                }
        if(command_save[ii]=='\\'&&(command_save[(ii+1)%600]=='n')){
                    word[i2][i1]='\n';
                    ii=ii+2;
                    i1++;
                    stop=1;
                }
        if(command_save[ii]=='\\'&&(command_save[(ii+1)%600]=='"')){
                    word[i2][i1]='"';
                    ii=ii+2;
                    i1++;
                    stop=1;
                }
        if(command_save[ii]=='\\'&&stop==0){
                word[i2][i1]='\\';
                i1=ii+1;
            }
        if(command_save[ii]!='\\'){
            word[i2][i1]=command_save[ii];
            ii++;
            i1++;
            }
        }
        ii=ii+2;
        mode_of_coma++;
        i1=0;
        i2++;
    }
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
void first_word_clean(){
for(int i=0;i<30;i++){
    fristword[i]='\0';
}
}
//erase temp_address array
void clean(){
for(int f=0;f<500;f++){
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
if((!strcmp(fristword,"createfile"))||(!strcmp(fristword,"insertstr"))||(!strcmp(fristword,"cat"))||(!strcmp(fristword,"removestr"))||(!strcmp(fristword,"copystr"))||(!strcmp(fristword,"pastestr"))||(!strcmp(fristword,"find"))||(!strcmp(fristword,"replace"))||(!strcmp(fristword,"grep"))||(!strcmp(fristword,"undo"))||(!strcmp(fristword,"auto-indent"))){
    return 1;
}
if((!strcmp(fristword,"compare")||(!strcmp(fristword,"tree"))||(!strcmp(fristword,"finish"))||(!strcmp(fristword,"cutstr")))){
    return 1;
    }
return 0;
}
//copy_word_we_want
void copy_word(char file_address[500],int start_line,int start_col,int number_of_char,int mode){
int ali=chanomin_karakteri(file_address,start_line,start_col);
FILE * fil;
fil=fopen(file_address,"r");
for(int u=0;u<4000;u++){
    clipcopy[u]='\0';
}
if(mode==2){
    ali=ali-number_of_char;
}
for(int tr=0;tr<ali;tr++){
    fgetc(fil);
}
for(int tf=0;tf<number_of_char;tf++){
   clipcopy[tf]=fgetc(fil);
}
fclose(fil);
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
//remove elemen

//insert funtion

void insertstr(char add[500],int line,int col,char input[4000]){
int num_of=how_many_line(add);
//int tedad=number_of_char_in_a_line("test.txt",2);
//printf("\n%d\n",tedad);
if(line>num_of){
    FILE * aval;
    //printf("done");
    aval=fopen(add,"a+");
    for(int u=0;u<line-num_of;u++){
        fprintf(aval,"\n");
    }
    for(int uu=0;uu<col;uu++){
        fprintf(aval," ");
    }
    fprintf(aval,"%s",input);
    fclose(aval);
}
if(line<=num_of){
    FILE * org;
    FILE * temp;
    org=fopen(add,"r+");
    char df[4000];
    char hhh;
    temp=fopen("_temp_.txt","w");
    for(int cu=1;cu<line;cu++){
        fgets(df,4000,org);
        fputs(df,temp);
    }
    //printf("%i %i",col,tedad);
    int cu_co=0;
    char si;
    if(col!=0){
    hhh=fgetc(org);
    while(cu_co<col&&hhh!='\n'){
        //printf("%i\n",cu_co);
        fprintf(temp,"%c",hhh);
        hhh=fgetc(org);
        cu_co++;
    }
    si=hhh;
    //printf("aaa %i %i\n",cu_co,col);
    if(cu_co<col){
        //printf("took");
        for(int i=0;i<(col-cu_co);i++){
                //printf("book");
            fprintf(temp," ");
        }
    }
    }
    fprintf(temp,"%s",input);
    fprintf(temp,"%c",si);
    while(hhh!=EOF){
        hhh=fgetc(org);
        if(hhh!=EOF){
        fputc(hhh,temp);
        }
    }
    fclose(org);
    fclose(temp);
    remove(add);
    rename("_temp_.txt",add);
}

}

//main function
int main(){
system("color 40");//red
system("cls");//clean the screen
while(1){
first_word_clean();
clean_word();
clean();
clean_name();
gets(command_save);
int pp=0;
if(command_save[0]=='\0'||command_save[0]=='\n'){
    pp=1;
}
line_to_word();
if((!is_valid_one()&&(pp==0))){
    printf("invalid command!");
    printf("\n");
}
if(!strcmp(fristword,"finish")){
    break;
}
if(!strcmp(fristword,"createfile")){
    //mkdir("ali");
    //mkdir("ali/alii");
        //printf("sal");
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
if(!strcmp("cat",fristword)){
        if(!has_file(word[2])){
        printf("%s Sorry! No file found!\n");
    }
    else{
    FILE * myfile;
    myfile=fopen(word[2],"r+");
    while(!feof(myfile)){
        fgets(line2,298,myfile);
        printf("%s",line2);
    }
    fclose(myfile);
    printf("\n");
    }
}
if(!strcmp(fristword,"insertstr")){
    if(!has_file(word[2])){
        printf("Sorry! No file found!\n");
    }
    else{
        FILE * bb;
        char gabli='\n';
        char hal;
        bb=fopen(word[2],"r+");
        while(hal!=EOF){
            gabli=hal;
            hal=getc(bb);
        }
 fprintf(bb,"\n");
 fprintf(bb,"\n");
        fclose(bb);
        char bu[200];
        char rep[200];
        int myline=0,mycol=0;
        int g=0;
        while(word[6][g]!=':'){
            myline=10*myline+(word[6][g]-'0');
            g++;
        }
        g++;
        while(word[6][g]!='\0'){
            mycol=(10*mycol)+(word[6][g]-'0');
            g++;
        }
    insertstr(word[2],myline,mycol,word[4]);
    }

if(!strcmp(word[0],"find")){
        if(!strcmp(word[5],"")){
if(0==has_star(word[2])){
    FILE *thisfile;
    int li,co;
    thisfile=fopen(word[4],"r+");
    int df=0;
    if(thisfile==NULL){
        printf("No file\n");
    }
    else{
    first_element1(thisfile,word[2],&li,&co);
    if(li==-1){
        printf("Sorry! Not found!\n");
    }
    else{
            fclose(thisfile);
            li=chanomin_karakteri(word[4],li+1,co);
            printf("line: %d col: %d char: %d\n",li+1,co,li);
    }
    }
    }
if(1==has_star(word[2])){
    FILE *thisfile;
    int li,co;
    thisfile=fopen(word[4],"r+");
    int df=0;
    if(thisfile==NULL){
        printf("No file\n");
    }
    else{
    first_element2(thisfile,word[2],&li,&co);
    if(li==-1){
        printf("Sorry! Not found!\n");
    }
    else{
            fclose(thisfile);
            li=chanomin_karakteri(word[4],li+1,co);
            printf("line: %d col: %d char: %d\n",li+1,co,li);
    }
    }
    }
    }
if(!strcmp(word[5],"-count")){
int te=how_many_element(word[4],word[2]);
printf("%i\n",te);
}
if(!strcmp(word[5],"-all")){

}
}
if(!strcmp(fristword,"compare")){
    char b1[1000];
    char b2[1000];
    for(int ghj=0;ghj<1000;ghj++){
        b1[ghj]='\0';
        b2[ghj]='\0';
    }
    int numff1=how_many_line(word[1]);
    int numff2=how_many_line(word[2]);
    int shorter;
    if(numff2>numff1){
        printf("Second file is longer\n");
        shorter=numff1;
    }
    if(numff1>numff2){
        printf("First file is longer\n");
        shorter=numff2;
    }
    FILE * ff1;
    FILE * ff2;
    ff1=fopen(word[1],"r+");
    ff2=fopen(word[2],"r+");
    int inc=0;
    int ss=0;
    while((!feof(ff1))||(!feof(ff2))){
        if(inc<shorter){
            for(int ghj=0;ghj<1000;ghj++){
        b1[ghj]='\0';
        b2[ghj]='\0';
    }
        fgets(b1,1000,ff1);
        fgets(b2,1000,ff2);
        if(strcmp(b1,b2)){
            printf("******************** line: %i *********************\n",inc+1);
            printf("first one:  ");
            printf("%s",b1);
            printf("second one:  ");
            printf("%s",b2);
        }
        }
        else{
            if(shorter==numff1){
                    if(ss==0){
                        printf("longer file\n");
                        ss=1;
                    }
                while(!feof(ff2)){
                        for(int ghj=0;ghj<1000;ghj++){
        b1[ghj]='\0';
        b2[ghj]='\0';
    }
                    fgets(b2,1000,ff2);
                    puts(b2);
                    inc++;
                }
            }
            if(shorter==numff2){
                    if(ss==0){
                        printf("longer file\n");
                        ss=1;
                    }
                while(!feof(ff1)){
                        for(int ghj=0;ghj<1000;ghj++){
        b1[ghj]='\0';
        b2[ghj]='\0';
    }
                    fgets(b1,1000,ff1);
                    puts(b1);
                    inc++;
                }
            }
        }
        inc++;
    }
}
if(!strcmp(fristword,"grep")){
    if(!strcmp(word[1],"--str")){

    }
}

if(!strcmp(word[0],"copystr")){
    //printf("salam\n");
    int lin1=0;int co1=0;
    int gg=0;
    int ggg=0;
    int num_of_char=0;
    while(word[4][gg]!=':'){
        lin1=10*lin1+(word[4][gg]-'0');
        gg++;
    }
    gg++;
    while(word[4][gg]!=' '&&word[4][gg]!='\0'){
        co1=10*co1+(word[4][gg]-'0');
        gg++;
    }
    while(word[6][ggg]!=' '&&word[6][ggg]!='\0'){
        num_of_char=(10*num_of_char)+(int)(word[6][ggg]-'0');
        //printf("%d ",num_of_char);
        ggg++;
    }
//printf("%s\n",word[7]);
    if(!strcmp("-f",word[7])){
        //printf("%i\n",num_of_char);
        copy_word(word[2],lin1,co1,num_of_char,1);
    }
    if(!strcmp("-b",word[7])){
        copy_word(word[2],lin1,co1,num_of_char,2);
    }
    printf("copy\n");
}
if(!strcmp("cutstr",word[0])){
    int lin1=0;int co1=0;
    int gg=0;
    int ggg=0;
    int num_of_char=0;
    while(word[4][gg]!=':'){
        lin1=10*lin1+(word[4][gg]-'0');
        gg++;
    }
    gg++;
    while(word[4][gg]!=' '&&word[4][gg]!='\0'){
        co1=10*co1+(word[4][gg]-'0');
        gg++;
    }
    while(word[6][ggg]!=' '&&word[6][ggg]!='\0'){
        num_of_char=(10*num_of_char)+(int)(word[6][ggg]-'0');
        //printf("%d ",num_of_char);
        ggg++;
    }
    if(!strcmp("-f",word[7])){
    int st=chanomin_karakteri(word[2],lin1,co1);
    remove_elment(word[2],st,num_of_char);}
    if(!strcmp("-b",word[7])){
    int st=chanomin_karakteri(word[2],lin1,co1);
    if(st-num_of_char<0){
        printf("Sorry it is impossible\n");
    }
    else{
    remove_elment(word[2],st-num_of_char,num_of_char);
    }
    }
}
if(!strcmp("pastestr",word[0])){
     int lin1=0;int co1=0;
    int gg=0;
    int ggg=0;
    int num_of_char=0;
    while(word[4][gg]!=':'){
        lin1=10*lin1+(word[4][gg]-'0');
        gg++;
    }
    gg++;
    while(word[4][gg]!=' '&&word[4][gg]!='\0'){
        co1=10*co1+(word[4][gg]-'0');
}
//int some=chanomin_karakteri(word[2],lin1,co1);
insertstr(word[2],lin1,co1,clipcopy);
}
}
}
}
