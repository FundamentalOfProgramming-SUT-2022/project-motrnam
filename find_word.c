#include <stdio.h>
#include <stdlib.h>

char word_of_file[20000];
int state_of_star[10];
int place_of_word[100];
char seq_of_word[10][22];
char one_word[20];
char just_for_test[100];
int has_file(char file_name[500])
{
    FILE * myfile;
    if ((myfile = fopen(file_name, "r")))
    {
        fclose(myfile);
        return 1;
    }
    return 0;
}
int mystrlen(int start,int i1){
int len=0;
while(seq_of_word[i1][start+len]!=' '&&seq_of_word[i1][start+len]!='\n'&&seq_of_word[start+len]!=EOF){
    if(seq_of_word[i1][start+len]=='*'){
        start++;
    }
    else{
        printf("%c",seq_of_word[i1][start+len]);
        len++;
    }
}
return(len);
}
void shift_char(int n,int b){
for(int i=n;i<20;i++){
    seq_of_word[b][i]=seq_of_word[b][i+1];
}
}

int if_star(int n){
for(int o=1;o<(strlen(seq_of_word[n])-1);o++){
    if(seq_of_word[n][o]=='*'){
        return 1;
    }
}
return 0;
}
int can_accept(int start){
int mov=start;
int t=start;
if(start!=0){
    if(word_of_file[start-1]!='\n'&&word_of_file[start-1]!=' '){
        return -1;
    }
    if(word_of_file[start]==' '||word_of_file[start]=='\n'){
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
    while(word_of_file[t+lenght]!=' '&&word_of_file[t+lenght]!='\n'){
        lenght++;
    }
    //printf("%i  ",lenght);
    if(lenght<strlen(seq_of_word[i1])){
            //printf("t\n");
        return -1;
    }
    while(word_of_file[t]!=' '&&word_of_file[t]!='\n'){
        if(seq_of_word[i1][i2]!=word_of_file[t]){
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
    while(word_of_file[t+lenght]!=' '&&word_of_file[t+lenght]!='\n'){
        lenght++;
    }
    if(lenght<strlen(seq_of_word[i1])){
        //printf("b");
        return -1;
    }
    int place2=strlen(seq_of_word[i1])-1;
    int place=start+lenght-1;
      while(place2>=0&&seq_of_word[i1][place2]!='*'){
            //printf("%c%c?",seq_of_word[i1][place2],word_of_file[place]);
        if(seq_of_word[i1][place2]!=word_of_file[place]){
            //printf("d");
            return -1;
        }
        place--;place2--;
    }

    start+=(lenght+1);
}
if(state_of_star[i1]==2){
    int lenght=0;
    while(word_of_file[t+lenght]!=' '&&word_of_file[t+lenght]!='\n'){
        lenght++;
    }
    if(lenght<strlen(seq_of_word[i1])){
            //printf("%i %i %i\n",mov,strlen(seq_of_word[i1]),i1);
            //problem
        return -1;
    }
    for(int o=0;o<strlen(seq_of_word[i1]);o++){
        if(seq_of_word[i1][o]!=word_of_file[o+start]){
            return -1;
        }
    }
    start+=(lenght+1);
}
if(state_of_star[i1]==3){
   int lenght=0;
    while(word_of_file[t+lenght]!=' '&&word_of_file[t+lenght]!='\n'){
        lenght++;
    }
    if(lenght<strlen(seq_of_word[i1])){
        return -1;
    }
    int place=start;
    int place2=0;
    while(seq_of_word[i1][place2]!='*'){
        if(seq_of_word[i1][place2]!=word_of_file[place]){
            return -1;
        }
        place++;place2++;
    }
    place2=strlen(seq_of_word[i1])-1;
    place=start+lenght-1;
      while(place2>=0&&seq_of_word[i1][place2]!='*'){
        if(seq_of_word[i1][place2]!=word_of_file[place]){
            return -1;
        }
        place--;place2--;
    }
    start+=(lenght+1);

}
if(state_of_star[i1]==4){
        int lenght=0;
    while(word_of_file[t+lenght]!=' '&&word_of_file[t+lenght]!='\n'){
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
    word_of_file[sss]='\0';
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
    word_of_file[i]=temp;
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
//printf("%s\n",seq_of_word[0]);
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
        if(s==0&&seq_of_word[ii][strlen(seq_of_word[ii])-1]=='*'){
        if(seq_of_word[ii][(strlen(seq_of_word[ii])+498)%500]=='\\'){
         state_of_star[ii]=0;
         seq_of_word[ii][strlen(seq_of_word[ii])-1]='\0';
         seq_of_word[ii][strlen(seq_of_word[ii])-2]='*';
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

int replace_n(int n,char old[500],char new1[500],char add[500]){
int num=find_word(add,old);
if(n>num){
    return -1;
}
int start_point=place_of_word[n-1];
int len_of_old=can_accept(start_point)-start_point-1;
int len_of_new=strlen(new1);

int len_of_file=strlen(word_of_file);
    char temp[20000];
    for(int my=0;my<20000;my++){
    temp[my]='\0';
}
    for(int ii=0;ii<start_point;ii++){
        temp[ii]=word_of_file[ii];
    }
    for(int i1=0;i1<len_of_new;i1++){
        temp[i1+start_point]=new1[i1];
    }
    int pl_te=start_point+len_of_new;
    int pl_old=start_point+len_of_old;
    while(word_of_file[pl_old]!='\0'){
        temp[pl_te]=word_of_file[pl_old];
        pl_old++;pl_te++;
    }
int hg=0;
while(temp[hg]!='\0'){
    word_of_file[hg]=temp[hg];
    hg++;
}

}

void save_file(char add[500]){
remove(add);
int u=0;
FILE * ab;
ab=fopen(add,"w+");
while(word_of_file[u]!='\0'){
    fprintf(ab,"%c",word_of_file[u]);
    printf("%c",word_of_file[u]);
    u++;
}
fclose(ab);
}

int main ()
{
    for(int to=0;to<100;to++){
        just_for_test[to]='\0';
    }
int u=find_word("test_file.txt","iran*");
printf("%i\n",u);
//printf("%s %i\n",seq_of_word[0],state_of_star[0]);
printf("........................................\n");
for(int hh=0;hh<u;hh++){
    printf("%i\n",place_of_word[hh]);
}
printf("........................................\n");
//printf("%i",strlen(just_for_test));
printf("%c%c%c%c\n",word_of_file[48],word_of_file[49],word_of_file[50],word_of_file[51]);
printf("........................................\n");
printf("%i",can_accept(43));
printf("\n........................................\n");
replace_n(2,"*abad","tebriz","test.txt");
save_file("test.txt");
}
