#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <unistd.h>
#include<stdbool.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#define DIM_MIN 3
#define DIM_MAX 9
#define true 1
#define false 0

/////////////////////////////////////////////////////////////////////////////////////////////////

struct node{
int num;
struct node *next;
struct node *rand;
char ch;
}*start=NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////

struct node1
{
    int row ;
    int col ;
    char val ;
    struct node1 *right ;
    struct node1 *down ;
}   *tempn;

struct cheadnode
{
    int colno ;
    struct node1 *down ;
    struct cheadnode *next ;
} *tempc, *col;

struct rheadnode
{
    int rowno ;
    struct node1 * right ;
    struct rheadnode *next ;
} *tempr,*row;

struct spmat
{
    struct rheadnode *firstrow ;
    struct cheadnode *firstcol ;
    int noofrows ;
    int noofcols ;
} *head;

int win[DIM_MAX][DIM_MAX];
int d;
int i=0;
int j=0;

/////////////////////////////////////////////////////////////////////////////////////////////////

void create(int i){
    struct node *new_node, *temp;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->num=i;
    new_node->rand=NULL;
    new_node->next=NULL;
    new_node->ch='\0';
    if(start==NULL)
    {
        start=new_node;
        temp=new_node;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=new_node;
        //printf("%d\n",temp->num);
        temp=new_node;
    }
}

void newGame(){
    int i;
    for(i=0;i<=100;i++)
    {
        create(i);
    }

    /*
    struct node *temp = start;
    while(temp->next!=NULL)
    {
        printf("here : %d\n",temp->num);
        temp=temp->next;
    }
    */

    ladder(19,38);
    ladder(21,82);
    ladder(28,53);
    ladder(36,57);
    ladder(43,77);
    ladder(50,91);
    ladder(54,88);
    ladder(62,96);
    ladder(66,87);
    ladder(80,99);

    snake(98,13);
    snake(95,37);
    snake(92,51);
    snake(83,22);
    snake(69,33);
    snake(68,2);
    snake(64,24);
    snake(59,18);
    snake(52,11);
    snake(48,9);
    snake(46,15);
    snake(44,22);
}

void ladder(int a, int b){
    struct node *beg, *end;
    beg=start;
    end=start;
    while(beg->num!=a)
    {
        beg=beg->next;
    }

    //printf("%d",beg->num);

    while(end->num!=b)
    {
        end=end->next;
    }

    //printf("\t%d\n",end->num);

    beg->rand=end;
    beg->ch='L';

    //printf("%d\n",beg->rand->num);
}

void snake(int a, int b){
    struct node *beg, *end;
    beg=start;
    end=start;

    while(beg->num!=a)
    {
        beg=beg->next;
    }

    //printf("%d",beg->num);

    while(end->num!=b)
    {
        end=end->next;
    }

    //printf("\t%d\n",end->num);

    beg->rand=end;
    beg->ch='S';

    //printf("%d\n",beg->rand->num);
}

void display(){
    struct node *temp=start;
    while(temp->next!=NULL)
    {
        printf("%d\n",temp->num);
        temp=temp->next;
    }
    printf("%d\n",temp->num);
}

void play()
{
    struct node *p1, *p2, *p3, *p4;
    int dval,flag,i,pno;

    p1=start;
    p2=start;
    p3=start;
    p4=start;

    printf("Enter no. of players between 2 to 4: ");
    scanf("%d",&pno);

    while(pno<2||pno>4)
            {
                printf("\nINVALID CHOICE!!!\nEnter again.\t");
                scanf("%d",&pno);
            }

        flag=0;

        while(flag==0)
        {
            dval=0;

            printf("\nPlayer 1 roll dice : \t");
            //printf("here");
            //printf("%d",p1->num);
            //printf("%c",p1->ch);
            scanf("%d",&dval);
            while(dval>6)
            {
                printf("\nDice value can't be greater than 6!!!\nEnter again.\t");
                scanf("%d",&dval);
            }


           // printf("%d",p1->num+dval);
            if(p1->num+dval>100)
                printf("\nNot enough spaces.. Cannot move!");
            else
                for(i=0;i<dval;i++)
                {
                    p1=p1->next;
                }
            if(p1->ch=='S')
            {
                printf("\nOops! You got bitten by a snake. :(");
                p1=p1->rand;
            }
            if(p1->ch=='L')
            {
                printf("\nYay! You've landed on a ladder. :D");
                p1=p1->rand;
            }
            printf("\nPLAYER ONE is now on %d\n\n", p1->num);
            if(p1->num==100)
            {
                printf("\n\nCONGRATULATIONS! PLAYER 1 WINS!!!");
                flag=1;
                break;
            }



            printf("\nPlayer 2 roll dice : \t");
            scanf("%d",&dval);
            while(dval>6)
            {
                printf("\nDice value can't be greater than 6!!!\nEnter again.\t");
                scanf("%d",&dval);
            }

            if(p2->num+dval>100)
                printf("\nNot enough spaces.. Cannot move!");
            else
                for(i=0;i<dval;i++)
                {
                    p2=p2->next;
                }
            if(p2->ch=='S')
            {
                printf("\nOops! You got bitten by a snake. :(");
                p2=p2->rand;
            }
            if(p2->ch=='L')
            {
                printf("\nYay! You've landed on a ladder. :D");
                p2=p2->rand;
            }
            printf("\nPLAYER TWO is now on %d\n\n", p2->num);
            if(p2->num==100)
            {
                printf("\n\nCONGRATULATIONS! PLAYER 2 WINS!!!");
                flag=1;
                break;
            }

            if(pno==3||pno==4)
            {
                printf("\nPlayer 3 roll dice : \t");
            scanf("%d",&dval);
            while(dval>6)
            {
                printf("\nDice value can't be greater than 6!!!\nEnter again.\t");
                scanf("%d",&dval);
            }

            if(p3->num+dval>100)
                printf("\nNot enough spaces.. Cannot move!");
            else
                for(i=0;i<dval;i++)
                {
                    p3=p3->next;
                }
            if(p3->ch=='S')
            {
                printf("\nOops! You got bitten by a snake. :(");
                p3=p3->rand;
            }
            if(p3->ch=='L')
            {
                printf("\nYay! You've landed on a ladder. :D");
                p3=p3->rand;
            }
            printf("\nPLAYER THREE is now on %d\n\n", p2->num);
            if(p3->num==100)
            {
                printf("\n\nCONGRATULATIONS! PLAYER 3 WINS!!!");
                flag=1;
                break;
            }

        if(pno==4)
        {
            printf("\nPlayer 4 roll dice : \t");
            scanf("%d",&dval);
            while(dval>6)
            {
                printf("\nDice value can't be greater than 6!!!\nEnter again.\t");
                scanf("%d",&dval);
            }

            if(p4->num+dval>100)
                printf("\nNot enough spaces.. Cannot move!");
            else
                for(i=0;i<dval;i++)
                {
                    p4=p4->next;
                }
            if(p4->ch=='S')
            {
                printf("\nOops! You got bitten by a snake. :(");
                p4=p4->rand;
            }
            if(p4->ch=='L')
            {
                printf("\nYay! You've landed on a ladder. :D");
                p4=p4->rand;
            }
            printf("\nPLAYER FOUR is now on %d\n\n", p4->num);
            if(p4->num==100)
            {
                printf("\n\nCONGRATULATIONS! PLAYER 4 WINS!!!");
                flag=1;
                break;
            }

        }
            }
        }
}

void snakesAndLadders()
{
    system("cls");
    newGame();
    play();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void startgame()
{
    system("cls");
    printf("WELCOME TO PUZZLE...!!!\n");
    usleep(500000);
    //system("cls");
    printf("Note : Enter zero to exit the game.\n");
    usleep(500000);
    //system("cls");
}

void create1()
{
    int count=0;
    for(i=1;i<=d;i++)
    {
        if(i==1)
        {
            tempc=(struct cheadnode*)malloc(sizeof(struct cheadnode));
              tempc->colno=i;
              head->firstcol=tempc;
        }
        else {
                tempc->next=(struct cheadnode*)malloc(sizeof(struct cheadnode));
                tempc=tempc->next;
        }
        tempc->next=NULL;
        tempc->colno=i;
    }

    for(i=1;i<=d;i++)
    {
        if(i==1)
        {
            tempr=(struct rheadnode*)malloc(sizeof(struct rheadnode));
              tempr->rowno=i;
              head->firstrow=tempr;
        }
        else
        {
            tempr->next=(struct rheadnode*)malloc(sizeof(struct rheadnode));
            tempr=tempr->next;
        }
        tempr->next=NULL;
        tempr->rowno=i;
    }
}

void boardInsert(int m, int n , int data)
{
    m=m+1;
    n=n+1;
    tempr=head->firstrow;
    while(tempr->rowno!=m)
    {
        tempr=tempr->next;
    }

    tempn=tempr->right;

    while(tempn->col!=n)
    {tempn=tempn->right;
    }
    tempn->val=data;

}

int boardRet(int m, int n)
{
    m=m+1;
    n=n+1;
    tempr=head->firstrow;

    while(tempr->rowno!=m)
    {
        tempr=tempr->next;
    }

    tempn=tempr->right;

    while(tempn->col!=n)
    {tempn=tempn->right;
    }
    return tempn->val;

}

void init()
{
    int s,temp;
    s=(d*d)-1;
    tempr=head->firstrow;
    tempc=head->firstcol;
    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d;j++)
        {

            if( j==1 )
            {
                //printf("in here.");
                //usleep(500000);
                tempn=(struct node1*)malloc(sizeof(struct node1));
                tempr->right=tempn;
                tempn->val=s;
                tempn->row=i;
                tempn->col=j;
                tempn->right=NULL;
                tempn->down=NULL;
                //printf ( "Row: %d Col: %d Val: %d\n", tempn -> row, tempn -> col,tempn -> val ) ;
                //usleep(500000);
                tempr=tempr->next;
            }
            else
            {
                tempn->right=(struct node1*)malloc(sizeof(struct node1));
                tempn=tempn->right;
                tempn->val=s;
                tempn->row=i;
                tempn->col=j;
                tempn->right=NULL;
                tempn->down=NULL;
                //printf ( "Row: %d Col: %d Val: %d\n", tempn -> row, tempn -> col,tempn -> val ) ;
                //usleep(500000);
            }
            s=s-1;


        }
    }
}

void draw(void)
{
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
        {   int k=boardRet(i,j);
            if(k==0)
            {
                printf(" _");
                printf("\t");
            }
            else
            {
                printf("%2d",k);
                printf("\t");
            }
        }
        printf("\n");
    }
}

bool won(void)
{
      int s=1,a;
    a=d*d;
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
        {
            win[i][j]=s;
            s=s+1;
        }
    }
    win[d-1][d-1]=0;
    int count;
    for(i=0;i<d;i++)
    {
        count=0;
        for(j=0;j<d;j++)
        {   int p=boardRet(i,j);
            if(win[i][j]==p)
            {
                count++;
            }
        }
    }
    if(count==d)
    {
        return true;
    }
    return false;
}

bool move(int tile)
{
    int tposi,tposj,bposi,bposj,temp;
    for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++)
        {   int p=boardRet(i,j);
            if(p==tile)
            {
                tposi=i;
                tposj=j;
            }
            if(p==0)
            {
                bposi=i;
                bposj=j;
            }

            if((tposi+1)==bposi && bposj==tposj)
            {
                temp=boardRet(tposi,tposj);
                boardInsert(tposi,tposj,boardRet(bposi,bposj));
                boardInsert(bposi,bposj,temp);
                return true;
            }
            else if(tposi==(bposi+1) && bposj==tposj)
            {
                temp=boardRet(tposi,tposj);
                boardInsert(tposi,tposj,boardRet(bposi,bposj));
                boardInsert(bposi,bposj,temp);
                return true;
            }
            else if(tposi==bposi && bposj==(tposj+1))
            {
                temp=boardRet(tposi,tposj);
                boardInsert(tposi,tposj,boardRet(bposi,bposj));
                boardInsert(bposi,bposj,temp);
                return true;
            }
            else if(tposi==bposi && (bposj+1)==tposj)
            {
                temp=boardRet(tposi,tposj);
                boardInsert(tposi,tposj,boardRet(bposi,bposj));
                boardInsert(bposi,bposj,temp);
                return true;
            }
        }
    }
    return false;
}

int puzzle()
{
    startgame();

    printf("Enter the size of board\n");
    scanf("%d",&d);
    head=(struct spmat*)malloc(sizeof(struct spmat));
    head->noofcols=d;
    head->noofrows=d;

    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    create1();
    init();

    while(true)
    {
        system("cls");
        draw();

        for (i = 0; i < d; i++)
        {
            for (j = 0; j < d; j++)
            {
                fprintf(file, "%i", boardRet(i,j));
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        if (won())
        {
            printf("You Win!!!\n");
            break;
        }

        printf("Number to move: ");

        int tile;
        scanf("%d",&tile);

        if (tile == 0)
            break;

        fprintf(file, "%i\n", tile);
        fflush(file);

        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }
        usleep(500000);
    }
    fclose(file);
    return 0;
}

void main()
{
    int a;
    printf("\n\n\t\tWELCOME TO *THE 90's KID*");
    printf("\n\n\t\t*****************************");
    printf("\n\n\t\tWhat do you feel like playing today?");
    printf("\n\n\t\tAll alone and need to pass time?\n\t\tPress 1 to solve a puzzle!");
    printf("\n\n\t\tHave company? How about a game of snakes and ladders?\n\t\tPress 2 to play.");
    printf("\n\n\t\t*****************************\n\n");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        puzzle();
        break;
    case 2:
        snakesAndLadders();
        break;
    default:
        printf("INVALID CHOICE");
    }
}
