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
#include"style.h"
#include"mylib.h"
#define UP 72
#define DOWN 80
void menu();
void viewlist();
void dataSearch();
void mod();
void rem();
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
        ch=getche();
        if(ch==13 || ch==32) add();
        break;
    case 2:
        printf("\n\n\tAdd books\n");
        printf("\t\tView book list\n");
        printf("\tSearch book\n");
        printf("\tModify list\n");
        printf("\tDelete Books\n");
        printf("\tExit");
        ch=getche();
        if(ch==13 || ch==32) viewlist();
        break;
    case 3:
        printf("\n\n\tAdd books\n");
        printf("\tView book list\n");
        printf("\t\tSearch book\n");
        printf("\tModify list\n");
        printf("\tDelete Books\n");
        printf("\tExit");
        ch=getche();
        if(ch==13 || ch==32) dataSearch();
        break;
    case 4:
        printf("\n\n\tAdd books\n");
        printf("\tView book list\n");
        printf("\tSearch book\n");
        printf("\t\tModify list\n");
        printf("\tDelete Books\n");
        printf("\tExit");
        ch=getche();
        if(ch==13 || ch==32) mod();
        break;
    case 5:
        printf("\n\n\tAdd books\n");
        printf("\tView book list\n");
        printf("\tSearch book\n");
        printf("\tModify list\n");
        printf("\t\tDelete Books\n");
        printf("\tExit");
        ch=getche();
        if(ch==13 || ch==32) rem();
        break;
    case 6:
        printf("\n\n\tAdd books\n");
        printf("\tView book list\n");
        printf("\tSearch book\n");
        printf("\tModify list\n");
        printf("\tDelete Books\n");
        printf("\t\tExit");
        ch=getche();
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
void viewlist(){
    system("cls");
    welcome();
    fastLoader();
    system("cls");
    welcome();
    upperWrap();
    list();
    downWrap();
    backToMenu();
}
void dataSearch(){
    char name[40];
    system("cls");
    welcome();
    fflush(stdin);
    printf("\n\t Enter Book Name:");
    gets(name);
    strupr(name);
    upperWrap();
    Search(name);
    downWrap();
    backToMenu();
}
void mod(){
    char name[40];
    system("cls");
    welcome();
    fflush(stdin);
    printf("\n\t Enter Book Name:");
    gets(name);
    strupr(name);
    upperWrap();
    modify(name);
    downWrap();
    backToMenu();
}
void rem(){
    system("cls");
    welcome();
    printf("\n\n\tEnter name to delete:");
    char name[40];
    fflush(stdin);
    gets(name);
    strupr(name);
    upperWrap();
    removes(name);
    downWrap();
    backToMenu();
}
void backToMenu(){
     char choice;
    printf("\n\n\n\t.....Press ESC to exit............");
    do{
        choice=getche();
        if(choice == 27) menu();
    }while(1);
}
