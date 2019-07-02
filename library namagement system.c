#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

struct books{
    int serial,number;
    char name[50];
    char writer[50];
    char department[30];
    char pas[30];
    char self[3];

}b;
void gotoxy(int x,int y);
void pass();
void welcome();
void menu();
void add();
void list();
void search();
void modify();
void removes();

int main(){
    printf("*********Welcome to Library Management system**********\n\n\n\t Name:Mahbub Alam \t Stamford University Bangladesh ");
    Sleep(500);
    system("color e");
    pass();

    return 0;
}
COORD coord = {0,0};
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void welcome(){

    int i=0;
    printf("\t");
    while(i<50){
        i++;
        printf("%c",219);
    }
    i=0;
    printf("\n\t%c\tWelcome to library Management System\t %c\n",219,219);
    printf("\t");

    while(i<50){
        i++;
        printf("%c",219);
    }

}
void pass(){
    system("cls");
    welcome();
    FILE *fp,*fpr;
    int i=0;
    fpr=fopen("data.dat","rb");
    if(!fpr){
        fp=fopen("data.dat","wb+");
        if(!fp){
            printf("\n\n\n\t\t System error! \a\a\a");
        }

        printf("\n\t Enter New Password:");
        gets(b.pas);
        fwrite(&b,sizeof(b),1,fp);
        fclose(fp);
        menu();
    }
    else{
        char pas[30];
        gotoxy(60,7);
        printf("\n\t Enter Password:");
        fflush(stdin);
        gets(pas);
        while(fread(&b,sizeof(b),1,fpr)){
            if(!strcmp(pas,b.pas)){
                fclose(fpr);
                menu();
                i=1;
            }
        }
        if(!i)
            printf("\n\n\t Wrong password.. \a\a\a");
    }
    fclose(fpr);
}



void menu(){
    system("cls");
    welcome();
    int choice;
    gotoxy(5,4);
    printf("1.Add books");
    gotoxy(25,4);
    printf("2.View book list");
    gotoxy(45,4);
    printf("3.Search book");
    gotoxy(5,6);
    printf("4.Modify list");
    gotoxy(25,6);
    printf("5.Delete Books");
    gotoxy(45,6);
    printf("6.Exit");
    gotoxy(5,9);
    printf("Enter your Choice :> ");
    fflush(stdin);
    scanf("%d",&choice);

    switch(choice){
    case 1:
        add();
        break;
    case 2:
        list();
        break;
    case 3:
        search();
        break;
    case 4:
        modify();
        break;
    case 5:
        removes();
        break;
    case 6:
        system("cls");
        gotoxy(10,6);
        printf("Thanks for using this program.....");
        Sleep(1000);
        exit(0);
    default :
        printf("\n\n \tEnter a correct number From 1 to 6 \a\a\a \n\t Press any key.........");
        getch();
        menu();

    }



}

void add(){
    system("cls");
    welcome();
    FILE *fp,*fpr;
    fp=fopen("data.dat","ab+");

    if(!fp){
        fp=fopen("data.dat","wb+");
        if(!fp){
            printf("\n\n\n System error ! ! \a\a\a");
            menu();
        }
    }
    fpr=fopen("data.dat","rb");
    char another='y';
    char tempName[30],tempWriter[30];
    while(another=='y'){


        fflush(stdin);
        printf("\n\n\tEnter book name:");
        gets(b.name);
        printf("\n\tEnter Writers name:");
        gets(b.writer);
        printf("\n\tEnter department name:");
        gets(b.department);
        printf("\n\tEnter Book-self Number:");
        gets(b.self);


        strcpy(tempName,b.name);
        strcpy(tempWriter,b.writer);

        /* book  Number auto generate */

        //have to debug.......
        while(fread(&b,sizeof(b),1,fpr)){
            if(!(strcmp(b.name,tempName) && strcmp(b.writer,tempWriter))){
                b.number++;
            }
        }
        fwrite(&b,sizeof(b),1,fp);

        printf("\n\\tDo you want to add another book?: [ y / n ]");
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
    printf("\n\n\nSerial\tName\t\t\tWriter\t\t\tDepartment\tSelf number\tTotal Number of books");
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
            printf("%d",b.number);
            i+=2;
            serial++;
    }
    fclose(fpr);
    printf("\n\n\n\t\tPress any key to.......");
    getch();
    menu();


}

void search(){

}

void modify(){

}

void removes(){

}
