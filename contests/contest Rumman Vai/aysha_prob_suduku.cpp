#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
/// I used bool on a function so... c++ required ... good luck! Aysha, valo complicated code likhte paros ;)
int board[9][9],A,B,f,m;

int find_unassigned(int i,int j,int n)
{
//printf("unassigment loop\n");
    int loop1,loop2,flag=0;
    for(loop1=0; loop1<n; loop1++)///change on it
    {
        if(flag) j=0;
        for(loop2=0; loop2<n; loop2++)///change on it
        {
            flag=1;
            if(board[loop1][loop2]==0)
            {
// printf("empty row col=%d %d\n",loop1,loop2);

                A=loop1,B=loop2;
                return 1;
            }
        }
    }
    return 0;
}

int place(int value,int row,int column,int n)
{
//printf("place loop\n");
    int loop,loop2,sq;
    for(loop=0; loop<n; loop++)
    {
        if(board[row][loop]==value || board[loop][column]==value) return 0;
    }
    sq=sqrt(n);
    for(loop=row-row%sq,f=0; f<sq; f++) ///change on it
    {
        for(loop2=column-column%sq,m=0; m<sq; m++)///change on it
        {
            if(board[loop+f][loop2+m]==value) return 0;///change on it
        }
    }
    return 1;
}


bool checkall(int n)        ///new function by ovi
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==0)return false;
        }
    return true;
}


int bigflag=0;
int solvesudoku(int i,int j,int n)
{
//printf("sudoku loop\n");
    int row,col,value;
    if(checkall(n)){bigflag=1;return 1;}///change on it
    if(find_unassigned(i,j,n))
    {
        row=A,col=B;//printf("empty A B row col=%d %d %d %d \n",A,B,row,col);
        for(value=1; value<=n; value++)
        {
            if(place(value,row,col,n))
            {
                board[row][col]=value;
//printf("\n\nrow %d col %d vaue=%d\n\n",row, col, value);
                if(solvesudoku(row,col,n))return 1;/// congratulations! backtracking shikhe gesish!

                board[row][col]=0;///change on it
            }
        }

    }
    return 0;
}

void printgrid(int n)
{
// printf("print loop\n");
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
    int nsq,n,i,j;
    while(scanf("%d",&n)==1)
    {
        nsq=n*n;
        for(i=0; i<nsq; i++)
        {
            for(j=0; j<nsq; j++)
            {
                scanf("%d",&board[i][j]);
            }
        }
//if(
//     find_unassigned(0,0,9);
        solvesudoku(0,0,nsq);
//)
        printgrid(nsq);
//else printf("NO SOLUTION\n");
/// ekhane board er shob element 0 kore dish... Best of luck!
    }
    return 0;
}
