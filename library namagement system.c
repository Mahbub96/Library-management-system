 /*************************************************************************
   *  Project: $(proejct 01)
   *  Project Name: $(Library Management System)
   *  Function:Welcome,menu,add,list,search,modify,Removes;
   *  c features:string,loop,file,structure,user define function and pointer also
   *************************************************************************
   *  $Author: Mahbub Alam And Rakiba Akter $
   *  $Name  : $ Library Management System
   *  CSE 69-B 2019
   *************************************************************************
   *
   *  Copyright 2019 by Anonymous Coder
   *
   ************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"style.h"
#define UP 72
#define DOWN 80
struct books{
    char number[3];
    char name[50];
    char Name[50];
    char writer[50];
    char department[30];
    char self[5];
}b;
void menu();
void add();
void list();
void search();
void modify();
void removes();
void backToMenu();
int main(){
   printf("\t************************************************************************ \n");
   printf("\t*  Project: $(proejct 01)\n");
   printf("\t*  Project Name: $(Library Management System)\n");
   printf("\t*  Function:Welcome,menu,add,list,search,modify,Removes;\n");
   printf("\t*  c features:string,loop,file,structure,user define function\n");
   printf("\t*************************************************************************\n");
   printf("\t*  $Author: Mahbub Alam And Rakiba Akter $\n");
   printf("\t*  $Name  : $ Library Management System\n");
   printf("\t*  CSE 69-B 2019\n");
   printf("\t*************************************************************************\n");
   printf("\t*\n");
   printf("\t*  Copyright 2019 by Anonymous Coder\n");
   printf("\t*\n");
   printf("\t***********************************************************************\n");

    loader();
    system("color 0F");
    menu();

    return 0;
}
void menu(){
    char ch;
    int count=1;
    while(1){
    system("cls");
    welcome();
    printf("\n\n\tPress \'W\' or \'S\' to move up and down");
    switch(count){
    case 1:
    printf("\n\n\t\tAdd books\n");
    printf("\tView book list\n");
    printf("\tSearch book\n");
    printf("\tModify list\n");
    printf("\tDelete Books\n");
    printf("\tExit");
        ch=getch();
        if(ch==13 || ch==32) add();
        break;
    case 2:
        printf("\n\n\tAdd books\n");
        printf("\t\tView book list\n");
        printf("\tSearch book\n");
        printf("\tModify list\n");
        printf("\tDelete Books\n");
        printf("\tExit");
        ch=getch();
        if(ch==13 || ch==32) list();
        break;
    case 3:
        printf("\n\n\tAdd books\n");
        printf("\tView book list\n");
        printf("\t\tSearch book\n");
        printf("\tModify list\n");
        printf("\tDelete Books\n");
        printf("\tExit");
        ch=getch();
        if(ch==13 || ch==32) search();
        break;
    case 4:
        printf("\n\n\tAdd books\n");
        printf("\tView book list\n");
        printf("\tSearch book\n");
        printf("\t\tModify list\n");
        printf("\tDelete Books\n");
        printf("\tExit");
        ch=getch();
        if(ch==13 || ch==32) modify();
        break;
    case 5:
        printf("\n\n\tAdd books\n");
        printf("\tView book list\n");
        printf("\tSearch book\n");
        printf("\tModify list\n");
        printf("\t\tDelete Books\n");
        printf("\tExit");
        ch=getch();
        if(ch==13 || ch==32) removes();
        break;
    case 6:
        printf("\n\n\tAdd books\n");
        printf("\tView book list\n");
        printf("\tSearch book\n");
        printf("\tModify list\n");
        printf("\tDelete Books\n");
        printf("\t\tExit");
        ch=getch();
        if(ch==13 || ch==32) exit(1);
        break;
    }
    ///check command
    if(ch==119 || ch == 87 || ch == UP) count--;
    else if(ch==115 || ch == 83 || ch == DOWN ) count++;
        if(count>6) count = 6;
        if(count<1) count = 1;
    }
}
void add(){
    system("cls");
    welcome();
    FILE *fp;
    fp=fopen("data.dat","ab+");
    if(!fp){
        fp=fopen("data.dat","wb+");
        if(!fp){
            printf("\n\n\n System error ! ! \a\a\a");
            menu();
        }
    }
    char another='y';
    while(another=='y'){
        fflush(stdin);
        printf("\n\n\tEnter book name:");
        gots(b.name);
        strupr(b.name);
        printf("\n\tEnter Writers name:");
        gots(b.writer);
        printf("\n\tEnter department name:");
        gots(b.department);
        printf("\n\tEnter Book-self Number:");
        gots(b.self);
        printf("\n\tHow many Books:");
        gots(b.number);
        fwrite(&b,sizeof(b),1,fp);
        printf("\n\t\tDo you want to add another book?: [ y / n ]");
        another=getch();
    }
    fclose(fp);
    menu();
}
void list(){
    FILE *fpr;
    int i=6,serial=1;
    fpr=fopen("data.dat","rb");
    system("cls");
    welcome();
    fastLoader();
    system("cls");
    welcome();
    upperWrap();
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
    downWrap();
    backToMenu();

}
void search(){
    FILE *fpr;
    fpr=fopen("data.dat","rb");
    char name[40];
    int found=0,serial=1,i=8,n=0;
    system("cls");
    welcome();
    fflush(stdin);
    printf("\n\t Enter Book Name:");
    gots(name);
    strupr(name);
    upperWrap();
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
    downWrap();
    fclose(fpr);
   backToMenu();
}
void modify(){
    FILE *fp;
    struct books s;
    fp=fopen("data.dat","rb+");
    char name[40];
    int found=0,serial=1,i=8,n=0;
    system("cls");
    welcome();
    fflush(stdin);
    printf("\n\t Enter Book Name:");
    gots(name);
    strupr(name);
    upperWrap();
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
            printf("%s",b.number);
            i+=2;
            serial++;
            downWrap();
            fflush(stdin);
            printf("\n\n\tEnter New book name:");
            gots(s.name);
            strupr(s.name);
            printf("\n\tEnter New Writers name:");
            gots(s.writer);
            printf("\n\tEnter New department name:");
            gots(s.department);
            printf("\n\tEnter New Book-self Number:");
            gots(s.self);
            printf("\n\tHow many Books(updated):");
            gots(s.number);
            fseek(fp,-sizeof(b),SEEK_CUR);
            fwrite(&s,sizeof(s),1,fp);
            found++;
            break;
            }
    }
     fclose(fp);
    if(!found) printf("\n\nFile not found\a");
    else printf("\n\nSuccessfully Modified ......");
    backToMenu();
}
void removes(){
    FILE *fpr,*temp;
    fpr=fopen("data.dat","rb");
    temp=fopen("temp","wb+");
    system("cls");
    welcome();
    printf("\n\n\tEnter name to delete:");
    char name[40];
    fflush(stdin);
    gots(name);
    strupr(name);
    int flag=0,serial=1,i=8,n=0;
    upperWrap();
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
     downWrap();
    if(!flag){
        fclose(temp);
        fclose(fpr);
        if(remove("temp")) printf("\n\n\t Temp file not removed...");
        else printf(" ");
        puts("\n\n\nFile not found..\n\n\n\tpress 1.For retry.\n\n\tpress ESC to Exit");
        char choice;
        while(1){
            choice = getch();
            if(choice == 27) menu();
            else if(choice == '1') removes();

        }
    }
    else{
        printf("\n\n\n\tfile Sucessfully delete....");
        fclose(fpr);
        fclose(temp);
        remove("data.dat");
        if(rename("temp","data.dat")) printf("\n\n\tRename function doesn't worked properly..");
        backToMenu();
    }
}
void backToMenu(){
     char choice;
    printf("\n\n\n\t.....Press ESC to exit............");
    do{
        choice=getch();
        if(choice == 27) menu();
    }while(1);
}
