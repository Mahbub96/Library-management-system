#include<stdio.h>
#include<conio.h>
struct books{
    char number[3];
    char name[50];
    char Name[50];
    char writer[50];
    char department[30];
    char self[5];
}b;
void add(){
    system("cls");
    welcome();
    FILE *fp;
    fp=fopen("data.dat","ab+");
    if(!fp){
        fp=fopen("data.dat","wb+");
        if(!fp){
            printf("\n\n\n System error ! ! \a\a\a");
        }
    }
    char another='y';
    while(another=='y'){
        fflush(stdin);
        printf("\n\n\tEnter book name:");
        gets(b.name);
        strupr(b.name);
        printf("\n\tEnter Writers name:");
        gets(b.writer);
        printf("\n\tEnter department name:");
        gets(b.department);
        printf("\n\tEnter Book-self Number:");
        gets(b.self);
        printf("\n\tHow many Books:");
        gets(b.number);
        fwrite(&b,sizeof(b),1,fp);
        printf("\n\t\tDo you want to add another book?: [ y / n ]");
        another=getche();
    }
    fclose(fp);
}
void list(){
    FILE *fpr;
    int i=6,serial=1;
    fpr=fopen("data.dat","rb");
    printf("Serial\tName\t\t\tWriter\t\t\tDepartment\tSelf number\tTotal Number of books");
    while(fread(&b,sizeof(b),1,fpr)){
            gotoxy(2,i);
            printf("%d",serial);
            gotoxy(8,i);
            printf("%s",b.name);
            gotoxy(32,i);
            printf("%s",b.writer);
            gotoxy(56,i);
            printf("%s",b.department);
            gotoxy(77,i);
            printf("%s",b.self);
            gotoxy(92,i);
            printf("%s",b.number);
            i+=2;
            serial++;
    }
    fclose(fpr);
}


void Search(char name[]){
    FILE *fpr;
    fpr=fopen("data.dat","rb");
    int found=0,serial=1,i=8,n=0;
    printf("Serial\tName\t\t\tWriter\t\t\tDepartment\tSelf number\tTotal Number of books");
    while(fread(&b,sizeof(b),1,fpr)){
        if(!strcmp(b.name,name)){
            gotoxy(2,i);
            printf("%d",serial);
            gotoxy(8,i);
            printf("%s",b.name);
            gotoxy(32,i);
            printf("%s",b.writer);
            gotoxy(56,i);
            printf("%s",b.department);
            gotoxy(77,i);
            printf("%s",b.self);
            gotoxy(92,i);
            printf("%s",b.number);
            i+=2;
            serial++;
            found=1;
        }
    }
    if(!found) printf("\n\n\tBook not found.... \a\a");
    fclose(fpr);
}
void modify(char name[]){
    FILE *fp;
    struct books s;
    fp=fopen("data.dat","rb+");
    int found=0,serial=1,i=8,n=0;
    printf("Serial\tName\t\t\tWriter\t\t\tDepartment\tSelf number\tTotal Number of books");
    while(fread(&b,sizeof(b),1,fp)){
        if(!strcmp(b.name,name)){
            gotoxy(2,i);
            printf("%d",serial);
            gotoxy(8,i);
            printf("%s",b.name);
            gotoxy(32,i);
            printf("%s",b.writer);
            gotoxy(56,i);
            printf("%s",b.department);
            gotoxy(77,i);
            printf("%s",b.self);
            gotoxy(92,i);
            printf("%s\n\n",b.number);
            i+=2;
            serial++;
            fflush(stdin);
            printf("\n\n\tEnter New book name:");
            gets(s.name);
            strupr(s.name);
            printf("\n\tEnter New Writers name:");
            gets(s.writer);
            printf("\n\tEnter New department name:");
            gets(s.department);
            printf("\n\tEnter New Book-self Number:");
            gets(s.self);
            printf("\n\tHow many Books(updated):");
            gets(s.number);
            fseek(fp,-sizeof(b),SEEK_CUR);
            fwrite(&s,sizeof(s),1,fp);
            found++;
            break;
            }
    }
     fclose(fp);
    if(!found) printf("\n\nFile not found\a");
    else printf("\n\nSuccessfully Modified ......");
}

void removes(char name[]){
    FILE *fpr,*temp;
    fpr=fopen("data.dat","rb");
    temp=fopen("temp","wb+");
    int flag=0,serial=1,i=8,n=0;
    printf("Serial\tName\t\t\tWriter\t\t\tDepartment\tSelf number\tTotal Number of books");
    while(fread(&b,sizeof(b),1,fpr)){
        if(strcmp(name,b.name))
            fwrite(&b,sizeof(b),1,temp);
        else{
            gotoxy(2,i);
            printf("%d",serial);
            gotoxy(8,i);
            printf("%s",b.name);
            gotoxy(32,i);
            printf("%s",b.writer);
            gotoxy(56,i);
            printf("%s",b.department);
            gotoxy(77,i);
            printf("%s",b.self);
            gotoxy(92,i);
            printf("%s",b.number);
            i+=2;
            serial++;
            flag=1;
        }
    }
    if(!flag){
        fclose(temp);
        fclose(fpr);
        if(remove("temp")) printf("\n\n\t Temp file not removed...");
        else printf(" ");
    }
    else{
        printf("\n\n\n\tfile Sucessfully delete....");
        fclose(fpr);
        fclose(temp);
        remove("data.dat");
        if(rename("temp","data.dat")) printf("\n\n\tRename function doesn't worked properly..");

    }
}
