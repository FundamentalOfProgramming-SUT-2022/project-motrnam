#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

//https://github.com/FundamentalOfProgramming-SUT-2022/project-motrnam.git
//start project naghavi moghaddam
int last_actin=0;
char junk[150];
char command_save[600];//for saving the command
char fristword[30];//for saving frist word
//this function saves frist word in fristword array
char word[20][500];//separate word here
char line[600];//line saved here
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
char word_of_files[20000];
int state_of_star[10];//for find & replace & grep
int place_of_word[100];//for find & replace & grep
char seq_of_word[10][22];//for find & replace & grep
char one_word[20];
char fake_add[500];
char old_address[500];//old address of file
int num_of_modi=0;
char modify_file[100][100];
//has =D function......(arman)
int has_d(){
    for(int i=0;i<599;i++){
        if(line[i]=='='&&line[i+1]=='D'){
            return 1;
        }
    }
    return 0;
}
//fake address
void make_copy(char address[500])
{
    char temp_text[2000];
    strcpy(modify_file[num_of_modi], address);
    strcat(modify_file[num_of_modi], "_copy_.txt");
    remove(modify_file[num_of_modi]);
    FILE * salam1;FILE * org;
    org=fopen(address,"r+");
    salam1= fopen(modify_file[num_of_modi], "w");
    while (!feof(org))
    {
        fgets(temp_text, 2000 ,org);
        if(!strcmp(temp_text,EOF)){
        fputs(temp_text,salam1);
        }

    }
    rewind(salam1);
    fclose(salam1);
    SetFileAttributes(modify_file[num_of_modi], FILE_ATTRIBUTE_HIDDEN);
    num_of_modi++;
}
//for undo function
int make_copy_file(char address[500]){
system("attrib -h -s _copy_.txt");
remove("_copy_.txt");
    for(int k=0;k<500;k++){
        old_address[k]='\0';
    }
FILE * copy;

copy=fopen("_copy_.txt","w+");
FILE * org;
org=fopen(address,"r+");
if(org==NULL){
    return -1;
}
char t=' ';
while(t!=EOF){
    t=fgetc(org);
    if(t!=EOF){
        fputc(t,copy);
    }
}
fclose(org);
fclose(copy);
system("attrib +h +s _copy_.txt");
strcpy(old_address,address);
return 0;
}
void file_yab(char *basePath, const int r,int depth){
    int i;
    char masir[1000];
    struct dirent *dp;
    DIR *naghavi = opendir(basePath);
    if (!naghavi)
        return;
    while ((dp = readdir(naghavi)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && strcmp(dp->d_name,".git")!=0)
        {
            for (i=0; i<r; i++)
            {
                if (i%2 == 0 || i == 0)
                    printf("%c", 179);
                else
                    printf(" ");
            }
            printf("%c%c%s\n", 195, 196, dp->d_name);
            strcpy(masir,basePath);
            strcat(masir,"/");
            strcat(masir,dp->d_name);
            if(r<2*depth){
            file_yab(masir,r+2,depth);
            }
        }
    }
    closedir(naghavi);
}
//shift char
void shift_char(int n,int b){
for(int i=n;i<20;i++){
    seq_of_word[b][i]=seq_of_word[b][i+1];
}
}
//has star function
int if_star(int n){
for(int o=1;o<(strlen(seq_of_word[n])-1);o++){
    if(seq_of_word[n][o]=='*'){
        return 1;
    }
}
return 0;
}
//auto indent function
int atuo_indent(char file_address[500]){
int last_b=0;
int number_of_opening=0;
int char_number=0;
FILE * naghavi;
naghavi=fopen(file_address,"r+");
FILE * moghaddam;
moghaddam=fopen("mytemp.txt","w");
char temp;
char lastchar;
int i=0;
int space_mode=0;
while(temp!=EOF){
    temp=fgetc(naghavi);
    if(temp!=EOF){
       if(temp==' '&&space_mode==0){
        space_mode=1;
        fputc(temp,moghaddam);
       }
       if(temp!=' '){
        space_mode=0;
        if(temp=='\n'){
            space_mode=1;
        }
        if(lastchar!=' '&&temp=='{'){
            fputc(' ',moghaddam);
        }
        fputc(temp,moghaddam);
        lastchar=temp;
       }
    }
}
fclose(naghavi);
fclose(moghaddam);
remove(file_address);
rename("mytemp.txt",file_address);
FILE * morteza;
morteza=fopen(file_address,"r+");
FILE * salam;
salam=fopen("_temp1_.txt","w+");
temp=' ';
char old;
int control=0;
while(temp!=EOF){
    old=temp;
    temp=fgetc(morteza);
    if(temp!=EOF){
        if(temp=='\n'&&control==1){
            temp=fgetc(morteza);
            control=0;
            if(temp==EOF){
                break;
            }
        }
        if(temp=='\n'){
            char_number=0;
        }
        if(temp!='\n'){
            char_number++;
        }
        if(temp=='{'){
            fputc(temp,salam);
            for(int i1=0;i1<4*number_of_opening+4;i1++){
                fputc(' ',salam);
            }
            number_of_opening++;
        if(temp=='}'){
            if(old!='{'){
            fputc('\n',salam);
            }
            for(int i3=0;i3<4*number_of_opening;i3++){
                fputc(' ',salam);
            }
            number_of_opening--;
            fputc(temp,salam);
            fputc('\n',salam);
            control=1;
        }
        if(temp!='{'&&temp!='}'){
            putc(temp,salam);
        }
    }
}
    }
fclose(morteza);
fclose(salam);
remove(file_address);
rename("_temp1_.txt",file_address);
return 0;
}
//compare two number
int mini(int a,int b){
if(a<b){
    return a;
}
return b;
}
//byword function
int byword(int input){
    int number_word=0;
for(int p=0;p<input;p++){
   if(word_of_files[p]==' '||word_of_files[p]=='\n'){
    number_word++;
   }
}
return number_word;
}
//remove element
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

int can_accept(int start){
int t=start;
if(start!=0){
    if(word_of_files[start-1]!='\n'&&word_of_files[start-1]!=' '){
        return -1;
    }
    if(word_of_files[start]==' '||word_of_files[start]=='\n'){
        return -1;
    }
}
int i1=0;
int i2=0;
while(state_of_star[i1]!=-1){
if(state_of_star[i1]==0){
        t=start;
        i2=0;
          int lenght=0;

    while(word_of_files[t+lenght]!=' '&&word_of_files[t+lenght]!='\n'){
        lenght++;
    }
    if(lenght<strlen(seq_of_word[i1])){
        return -1;
    }
    while(word_of_files[t]!=' '&&word_of_files[t]!='\n'){
        if(seq_of_word[i1][i2]!=word_of_files[t]){
                //printf("%c%c?%i %i %i\n",seq_of_word[i1][i2],word_of_file[t],t,i1,i2);
                //printf("a");
            return -1;
        }
        i2++;t++;
    }
    t++;
    start=t;
}
if(state_of_star[i1]==1){
    int lenght=0;
    while(word_of_files[t+lenght]!=' '&&word_of_files[t+lenght]!='\n'){
        lenght++;
    }
    if(lenght<strlen(seq_of_word[i1])){
        return -1;
    }
    int place2=strlen(seq_of_word[i1])-1;
    int place=start+lenght-1;
      while(place2>=0&&seq_of_word[i1][place2]!='*'){
            //printf("%c%c?",seq_of_word[i1][place2],word_of_file[place]);
        if(seq_of_word[i1][place2]!=word_of_files[place]){
            return -1;
        }
        place--;place2--;
    }

    start+=(lenght+1);
}
if(state_of_star[i1]==2){
    int lenght=0;
    while(word_of_files[t+lenght]!=' '&&word_of_files[t+lenght]!='\n'){
        lenght++;
    }
    if(lenght<strlen(seq_of_word[i1])){
        return -1;
    }
    for(int o=0;o<strlen(seq_of_word[i1]);o++){
        if(seq_of_word[i1][o]!=word_of_files[o+start]){
            return -1;
        }
    }
    start+=(lenght+1);
}
if(state_of_star[i1]==3){
   int lenght=0;
    while(word_of_files[t+lenght]!=' '&&word_of_files[t+lenght]!='\n'){
        lenght++;
    }
    if(lenght<strlen(seq_of_word[i1])){
        return -1;
    }
    int place=start;
    int place2=0;
    while(seq_of_word[i1][place2]!='*'){
        if(seq_of_word[i1][place2]!=word_of_files[place]){
            return -1;
        }
        place++;place2++;
    }
    place2=strlen(seq_of_word[i1])-1;
    place=start+lenght-1;
      while(place2>=0&&seq_of_word[i1][place2]!='*'){
        if(seq_of_word[i1][place2]!=word_of_files[place]){
            return -1;
        }
        place--;place2--;
    }
    start+=(lenght+1);

}
if(state_of_star[i1]==4){
        int lenght=0;
    while(word_of_files[t+lenght]!=' '&&word_of_files[t+lenght]!='\n'){
        lenght++;
    }
    start+=(lenght+1);
}
i1++;
}
return start;
}
int find_word(char address[500],char myword[500]){
for(int sss=0;sss<20000;sss++){
    word_of_files[sss]='\0';
}
memset(state_of_star,-1,50);
for(int r=0;r<10;r++){
    memset(seq_of_word[r],'\0',22);
}
FILE * myfile;
myfile=fopen(address,"r+");
char temp='s';
int i=0;
while(temp!=EOF){
    temp=fgetc(myfile);
    if(temp!=EOF){
    word_of_files[i]=temp;
    i++;
    }
}
fclose(myfile);
int len = strlen(myword);
int b=0;
int c=0;
int i4=0;
while(myword[i4]!='\0'){
    if(myword[i4]==' '){
        b++;c=0;
    }
    else{
        seq_of_word[b][c]=myword[i4];
        c++;
    }
    i4++;
}

b++;
int i2=0;
int action_mode=1;
int saver=0;
int s=0;
for(int ii=0;ii<b;ii++){
    i2=0;
    s=0;
    if(!strcmp("*",seq_of_word[ii])){
        state_of_star[ii]=4;
        s=1;
    }
    saver=0;
    if(seq_of_word[ii][0]=='*'&&s==0){
        state_of_star[ii]=1;
        saver=1;
        s=1;
    }
    if(s==0&&seq_of_word[ii][strlen(seq_of_word[ii])-1]=='*'){
        if(seq_of_word[ii][strlen(seq_of_word[ii])-2]!='\\'){
         state_of_star[ii]=2;
         seq_of_word[ii][strlen(seq_of_word[ii])-1]='\0';
         s=1;
        }
    }
    if(s==0&&if_star(ii)){
        state_of_star[ii]=3;
        s=1;
    }
    if(s==0){
        state_of_star[ii]=0;
    }


    if(saver==1){
        shift_char(0,ii);
    }
}
for(int h=0;h<b;h++){
    for(int hh=0;hh<20;hh++){
        if(seq_of_word[h][hh]=='\\'&&seq_of_word[h][hh+1]=='*'){
            shift_char(hh,h);
        }
    }
}
int shom=0;
for(int i=0;i<20000;i++){
    if(-1!=can_accept(i)){
        place_of_word[shom]=i;
        shom++;
    }
}
return shom;
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
    for(int u=0;u<line-num_of-1;u++){
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

//replace functions
int replace_n(int n,char old[500],char new1[500],char add[500]){
int num=find_word(add,old);
if(n>num){
    return -1;
}
int start_point=place_of_word[n-1];
int len_of_old=can_accept(start_point)-start_point-1;
int len_of_new=strlen(new1);

int len_of_file=strlen(word_of_files);
    char temp[20000];
    for(int my=0;my<20000;my++){
    temp[my]='\0';
}
    for(int ii=0;ii<start_point;ii++){
        temp[ii]=word_of_files[ii];
    }
    for(int i1=0;i1<len_of_new;i1++){
        temp[i1+start_point]=new1[i1];
    }
    int pl_te=start_point+len_of_new;
    int pl_old=start_point+len_of_old;
    while(word_of_files[pl_old]!='\0'){
        temp[pl_te]=word_of_files[pl_old];
        pl_old++;pl_te++;
    }
int hg=0;
while(temp[hg]!='\0'){
    word_of_files[hg]=temp[hg];
    hg++;
}
return 1;
}
//for saving file
void save_file(char add[500]){
remove(add);
int u=0;
FILE * ab;
ab=fopen(add,"w+");
while(word_of_files[u]!='\0'){
    fprintf(ab,"%c",word_of_files[u]);
    u++;
}
fclose(ab);
}
//main function
int main(){
//FILE * g;
//g=fopen("_copy_.txt","w");
//fclose(g);
//system("attrib -h -s _copy_.txt");
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
int has_eq_d=has_d();
if(has_eq_d==1){
    //some action need
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
    last_actin=1;
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
        last_actin=2;
        if(!has_file(word[2])){
        printf("Sorry! No file found!\n");
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
        last_actin=3;
        make_copy(word[2]);
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
}

if(!strcmp(word[0],"find")){
    last_actin=4;
    if(!has_file(word[4])){
        printf("no file!\n");
    }
    else{
        int tedad=find_word(word[4],word[2]);
        if(tedad==0){
            printf("no word found!\n");
        }
        else{
            if(!strcmp("",word[5])){
                printf("%i\n",place_of_word[0]);
            }
            else{
            if(!strcmp("-count",word[5])){
                if(strcmp("",word[6])){
                    printf("invalid command\n");
                }
                else{
                  printf("%i\n",tedad);
                }
            }
            if(!strcmp("-at",word[5])){
                int kj=0;
                int num=0;
                while(word[6][kj]!='\0'){
                    num=10*num+(word[6][kj]-'0');
                    kj++;
                }
                if(num>tedad){
                    printf("out of range!\n");
                }
                else{
                    if(!strcmp(word[7],"-byword")){
                        printf("%d\n",byword(place_of_word[num-1]));
                    }
                    if(!strcmp(word[6],"-count")){
                        printf("Invalid command!\n");
                    }
                    else{
                    printf("%i\n",place_of_word[num-1]);
                    }
                }
            }
            if(!strcmp("-all",word[5])){
                if(!strcmp("-at",word[6])){
                    printf("invalid command!\n");
                }
                if(!strcmp("-byword",word[6])){
                    for(int na=0;na<tedad;na++){
                        printf("%i\n",byword(place_of_word[na]));
                    }
                if(!strcmp("",word[6])){
                    for(int na=0;na<tedad;na++){
                        printf("%i\n",place_of_word[na]);
                    }
                }
                if(!strcmp("-count",word[6])){
                    printf("invalid command!\n");
                }
                }
            }//
            if(!strcmp("-byword",word[5])){
                if(!strcmp("",word[6])){
                    printf("%i\n",byword(place_of_word[0]));
                }
                if(!strcmp("-all",word[6])){
                    for(int ji=0;ji<tedad;ji++){
                        printf("%i\n",byword(place_of_word[ji]));
                    }
                }
                if(!strcmp("-at",word[6])){
                    int hl=0;
                    int cc=0;
                    while(word[7][cc]!='\0'){
                        hl=10*hl+(word[7][cc]-'0');
                        cc++;
                    }
                    if(hl>tedad){
                        printf("out of range\n");
                    }
                    else{
                        printf("%i\n",byword(place_of_word[hl-1]));
                    }
                }
                else{
                    printf("invalid command!\n");
                }
            }
        }
    }
    }
    }

if(!strcmp(fristword,"compare")){
    last_actin=5;
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
        int num=0;
    if(!strcmp(word[1],"-c")){
        for(int g=5;g<15;g++){
            num+=find_word(word[g],word[3]);
        }
        printf("%i\n",num);
    }
    if(!strcmp(word[1],"-i")){
        for(int gg=5;gg<15;gg++){
            if(find_word(word[gg],word[3])>0){
                printf("%s\n",word[gg]);
            }
        }
    }
    if(!strcmp("-str",word[1])){
        for(int ggg=4;ggg<15;ggg++){
            int h=find_word(word[ggg],word[2]);
            for(int r=0;r<h;r++){
                printf("%i\n",place_of_word[r]);
            }
        }
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
        make_copy(word[2]);
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
    for(int h=0;h<20000;h++){
        word_of_files[h]='\0';
    }
    FILE * last;
    char gj;
    last=fopen(word[2],"r");
    for(int tr=0;tr<20000;tr++){
        gj=fgetc(last);
        if(gj==EOF){
            break;
        }
        word_of_files[tr]=gj;
    }
    int len=strlen(word_of_files);
    if(!strcmp("-f",word[7])){
    int st=chanomin_karakteri(word[2],lin1,co1);
    if(st+num_of_char>len){
        printf("sorry it is imposible!\n");
    }
    else{
    for(int h1=st;h1<st+num_of_char;h1++){
        clipcopy[h1-st]=word_of_files[h1];
    }
    remove_elment(word[2],st,num_of_char);
    }
    }
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
    make_copy(word[2]);
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
printf("done!\n");
//int some=chanomin_karakteri(word[2],lin1,co1);
insertstr(word[2],lin1,co1,clipcopy);
}
if(!strcmp("atuo-indent",word[0])){
    make_copy(word[1]);
    atuo_indent(word[1]);
}
if(!strcmp("replace",word[0])){
    make_copy(word[2]);
    int tedad=find_word(word[6],word[2]);
    if(!has_file(word[6])){
        printf("no file !\n");
    }
    else{
    if(tedad==0){
        printf("No word to replace!\n");
    }
    else{
        if(!strcmp("",word[7])){
            replace_n(1,word[2],word[4],word[6]);
        }
        if(!strcmp("-all",word[7])){
            if(!strcmp("",word[8])){
                int te=find_word(word[6],word[2]);
                for(int k=0;k<te;k++){
                    replace_n(1,word[2],word[4],word[6]);
                    save_file(word[6]);
                }
            }
            else{
                printf("invalid command!\n");
            }
        }
        if(!strcmp("-at",word[7])){
            if(!strcmp("",word[9])){
                int na=0;int cl=0;
                while(word[8][na]!='\0'){
                    cl=10*cl+(word[8][na]-'\0');cl++;
                }
                if(cl<=tedad&&cl!=0){
                    replace_n(cl,word[2],word[4],word[6]);
                }
                else{
                    printf("out of range!\n");
                }
            }
            else{
                printf("invalid command!\n");
            }
        }
    }
    }
}
if(!strcmp("undo",word[0])){
    system("attrib -h -s _copy_.txt");
    rename(word[1],"_copy1_.txt");
    rename("_copy_.txt",word[1]);
    rename("_copy1_.txt","_copy_.txt");
    system("attrib +h +s _copy_.txt");
}
if(!strcmp("tree",word[0])){
    //address is saved in word[2]
    int ip=0;
    int number_sign=0;
    int adad=0;
    if(word[1][0]=='-'){
        number_sign=-1;
        ip++;
    }
    else{
        number_sign=1;
    }
    while (word[1][ip]!='\0'){
        adad=10*adad+(word[1][ip]-'48');
        ip++;
    }
    if(number_sign==-1){
        if(adad==1){
            file_yab(word[2],0,400);
            //infinity=400 :)
        }
        else{
            printf("invalid depth!\n");
        }
    }
    else{
        file_yab(word[2],0,adad);
    }
}

}
}
