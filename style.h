//Header file of library management system
#include<stdio.h>
#include<windows.h>
COORD coord = {0,0};
void gotoxy(int x,int y){
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
void loader(){
    int i;
    printf("\n\n\n\t please wait While Reading Data....\n\n\t");
    for(i=1;i<80; i++)
    {
        Sleep(45);
        printf("%c",219);
    }
}
void fastLoader(){
    int i;
    printf("\n\n\n\t please wait While Reading Data....\n\n\t");
    for(i=1;i<80; i++){
        Sleep(10);
        printf("%c",219);
    }
}
void gots(char *name){
   int i=0,j;
    char c,ch;
    do{
        c=getch();
                if(c!=8&&c!=13){
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8){
                    if(i>0) i--;
                    system("cls");
                    for(j=0;j<i;j++){
                        ch=*(name+j);
                        putch(ch);
                    }
                }
    }while(c!=13);
      *(name+i)='\0';
}
