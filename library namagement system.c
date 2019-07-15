 /*************************************************************************
   *  Project: $(proejct 01)
   *  Project Name: $(Library Management System)
   *  Function:Welcome,menu,add,list,search,modify,Removes;
   *  c features:string,loop,file,structure,user define function
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
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

struct books{

    char number[3];
    char name[50];
    char Name[50];
    char writer[50];
    char department[30];
    //char pas[30];
    char self[5];

}b;
void gotoxy(int x,int y);
//void pass();
void welcome();
void menu();
void add();
void list();
void search();
void modify();
void removes();
void loader();
void fastLoader();
void backToMenu();
void upperWrap();
void downWrap();

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
    system("color e");
   // pass();
    menu();

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
    printf("\t\t\t\t");
    while(i<50){
        i++;
        printf("%c",219);
    }
    i=0;
    printf("\n\t\t\t\t%c\tWelcome to library Management System\t %c\n",219,219);
    printf("\t\t\t\t");

    while(i<50){
        i++;
        printf("%c",219);
    }

}

//Without password
/*
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
*/


void menu(){
    system("cls");
    welcome();
    int choice;
    gotoxy(30,4);
    printf("1.Add books");
    gotoxy(50,4);
    printf("2.View book list");
    gotoxy(70,4);
    printf("3.Search book");
    gotoxy(30,6);
    printf("4.Modify list");
    gotoxy(50,6);
    printf("5.Delete Books");
    gotoxy(70,6);
    printf("6.Exit");
    gotoxy(30,9);
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
    gets(name);
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

    if(!found)
        printf("\n\n\tBook not found.... \a\a");
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
    gets(name);
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
    if(!found)
        printf("\n\nFile not found\a");
    else
        printf("\n\nSuccessfully Modified ......");




    backToMenu();
}

void removes(){
    system("cls");
    welcome();
    FILE *fpr,*temp,*fp;
    int flag=0,serial=1,i=8,n=0;
    char name[40];
    struct books s;
    fpr=fopen("data.dat","rb");
    fp=fopen("data.dat","rb");

    if(!fpr){
        printf("\n\n\n\t  System Error !! \a\a\a");
    }
    else{

        temp=fopen("temp","wb+");
        if(!temp){
            printf("\n\n\n system error press any key");
            getch();
            menu();
        }

        if(!fp){
        printf("\n\n\n\t  System Error !! \a\a\a");
    }


        printf("\n\tEnter Book Name:");
        fflush(stdin);
        gets(name);

        strupr(name);


        /**for showing file**/
     //upperWrap();
     /**if we use this upperWrap function ,program not worked properly ,that's why we are using print function****/

    printf("\n-----------------------------------------------------------------------------------------------------------\nSerial\tName\t\t\tWriter\t\t\tDepartment\tSelf number\tTotal Number of books");

    while(fread(&s,sizeof(s),1,fpr)){

        if(!strcmp(s.name,name)){

            gotoxy(2,i);
            printf("%d",serial);
            gotoxy(8,i);
            printf("%s",s.name);
            gotoxy(32,i);
            printf("%s",s.writer);
            gotoxy(56,i);
            printf("%s",s.department);
            gotoxy(77,i);
            printf("%s",s.self);
            gotoxy(92,i);
            printf("%s",s.number);
            i+=2;
            serial++;
        }

    }
    downWrap();









        while(fread(&b,sizeof(b),1,fp)){
            if(strcmp(name,b.name)){
                fwrite(&b,sizeof(b),1,temp);
            }
            if(!strcmp(name,b.name))
            {
               flag=1;
            }


        }



        if(!flag)
	{
	    fclose(temp);
		printf("\n\n\t NO BOOK TO DELETE.");
		remove("temp");
	}
		else
		{
		    fclose(fpr);
		    fclose(fp);
            fclose(temp);
			remove("data.dat");
			rename("temp","data.dat");
			printf("\n\n\n RECORD DELETED SUCCESSFULLY.");

		}

    }


   backToMenu();

}




void backToMenu(){
     char choice;
    printf("\n\n\n\t.....Press ESC to exit............");
    do{
        choice=getch();
        if(choice == 27)
            menu();
    }while(1);
}



/***** Extra features for style *****/

void upperWrap(){
    int i=110;
    printf("\n");
    while(i){
        printf("%c",220);
        i--;
    }
    printf("\n");


}

void downWrap(){
    int i=110;
    printf("\n\n\n");
    while(i){
        printf("%c",223);
        i--;
    }
    printf("\n");
}


void loader()
{
    int i;
    //system("cls");
    printf("\n\n\n\t please wait While Reading Data....\n\n\t");
    for(i=1;i<80; i++)
    {
        Sleep(45);
        printf("%c",219);

    }
}

void fastLoader()
{
    int i;
    //system("cls");
    printf("\n\n\n\t please wait While Reading Data....\n\n\t");
    for(i=1;i<80; i++)
    {
        Sleep(10);
        printf("%c",219);

    }
}


