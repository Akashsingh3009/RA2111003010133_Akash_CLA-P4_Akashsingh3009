#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
typedef struct Movie
{
char Mv[100];
float Start_time;
char Type[100];
char Seat[100];
int price;
char Lang[100];
}movie;
void display(movie *p);
void error_message()
{
  printf("Bruh!!! Invalid Input!!!");
  exit(0);
}
int main()
{
  printf("Welcome to SRMIST THEATRE 📽🎞🎦🍿🅤/🥤/");
  printf("\n\nMade by Akash & Anuj\n\n");
char x[11][100];int i;
  int dd,mm,yy,chmv,chst,chtype,chs,chl;
   int bprice=100;//base price which will be updated with respect to selected screen type and seat type
  float t[]={8.0,12.5,15.15,17.0,19.20,22.0};
  char type[3][10]={"IMAX 3D","3D","2D"};
  char seat[3][10]={"VIP","PRIME","NORMAL"};
  char lang[3][10]={"HINDI","ENGLISH","TAMIL"};
  FILE *pFile;
  pFile = fopen("list.txt","r");//Movie Names to read from the Text file list.txt which can be updated with new movies when they get realeased
  
for(i=0;i<5;i++)
  {
          fscanf(pFile,"%s",x[i]); 
  }
  printf(("Available movies with Screen_no.\n\n"));
  for(i=0;i<5;i++)
    {
      printf("(%d) %s\n\n",(i+1),x[i]);
    }
  
  printf("Enter movie Title using screen no.\n");
  scanf("%d",&chmv);
  if(chmv>5)
    error_message();
  printf("-----------------------------------------------------------------------------\n");
  printf("Enter Date in format dd/mm/yyyy\n");
  scanf("%d/%d/%d",&dd,&mm,&yy);
  printf("-----------------------------------------------------------------------------\n");
  printf("Available Time Slots(represented in Hours.Minutes)\n");
  for(i=0;i<6;i++)
    {
    printf("(%d) %.2f ",(i+1),t[i]);
    }
  printf("\nselect time slot using numbers assigned to them\n");
  scanf("%d",&chst);
  if(chst>6)
  {
    error_message();
  }
  printf("-----------------------------------------------------------------------------\n");
  printf("Available Types\n");
  for(i=0;i<3;i++)
    {
      printf("(%d) %s ",(i+1),type[i]);
    }
  printf("\nselect type using numbers assigned to them\n");
   scanf("%d",&chtype);
  if(chtype>3)
  {
    error_message();
  }
  (chtype==1)?bprice+=200:(chtype==2)?bprice+=110:bprice;
  
  printf("-----------------------------------------------------------------------------\n");
    printf("Available Seat Types\n");
  for(i=0;i<3;i++)
    {
      printf("(%d) %s ",(i+1),seat[i]);
    }
  printf("\nselect type using numbers assigned to them\n");
   scanf("%d",&chs);
    if(chs>3)
  {
    error_message();
  }
  (chs==1)?bprice+=80:(chs==2)?bprice+=60:bprice;
     printf("-----------------------------------------------------------------------------\n");
      printf("Available Languages\n");
  for(i=0;i<3;i++)
    {
      printf("(%d) %s ",(i+1),lang[i]);
    }
  printf("\nselect Language using numbers assigned to them\n");
   scanf("%d",&chl);
    if(chl>3)
  {
    error_message();
  }
   printf("-----------------------------------------------------------------------------\n");
  movie ticket;
  strcpy(ticket.Mv,x[chmv-1]);
  ticket.Start_time=t[chst-1];
  strcpy(ticket.Type,type[chtype-1]);
  strcpy(ticket.Seat,seat[chs-1]);
  ticket.price=bprice;
  strcpy(ticket.Lang,lang[chl-1]);
  display(&ticket);
  return 0;
}

void display(movie *u)
{
  printf("Ticket Booked🥁\n");
  printf("Movie-Title: %s\nTime-Slot %.2f\nScreen-Type: %s\nSeat Type: %s\nprice: %d\nLanguage: %s",u->Mv,u->Start_time,u->Type,u->Seat,u->price,u->Lang);
}
