#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int imap[101][101];
char cmap[101][101];
int n,m,mint;
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int direct[101][101];
int BFS(int x,int y,int t,int dir)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return 0;
    if(x==n-1 && y==m-1 && t>0 )
        return 0;
    if(cmap[x][y]=='X')
        return 0;
    int hp=cmap[x][y]-'0';
    if(hp > 9 || hp < 0)
        hp=0;
    while(hp--){
        t++;
    }
    if(imap[x][y]!=0 && imap[x][y] < t)
        return 0;
    else{
        imap[x][y]=t;
        direct[x][y]=dir;
    }
    if(x==0 && y==0)
    {
        if(mint > imap[x][y] || mint==0)
            mint = imap[x][y];
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ", imap[i][j] ) ;
            }
            printf("\n");
        }
        printf("\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ", direct[i][j] ) ;
            }
            printf("\n");
        }
        printf("\n");
        */
    }
    for(int i=0;i<4;i++){
        BFS(x+step[i][0],y+step[i][1],t+1,i);
    }
    return 0;
}
int printmap(int x,int y)
{
    if(x <0 || y<0 || y>=m || x>=n || mint==0)
        return 0;
    if(x==n-1 && y==m-1)
    {
        int dist = imap[x][y] - 0;
        for(int i=0;i<dist;i++){
            printf("%ds:FIGHT AT (%d,%d)\n",mint-imap[x][y]-i+1,x,y);
        }
        return 0;
    }
    int distance=imap[x][y]-imap[x-step[direct[x][y]][0]][y-step[direct[x][y]][1]];
    for(int i=1;i<distance;i++){
        printf("%ds:FIGHT AT (%d,%d)\n",mint-(imap[x][y]-i),x,y);
    }
    printf("%ds:(%d,%d)->(%d,%d)\n",mint-(imap[x][y]-distance),x,y,x-step[direct[x][y]][0],y-step[direct[x][y]][1] );
    printmap(x-step[direct[x][y]][0],y-step[direct[x][y]][1]);
    return 0;
}
int main(){
    while(scanf("%d%d", &n, &m) !=EOF)
    {
        int i,j;
        for(i=0;i<n;i++){
               scanf("%s",&cmap[i]);
               for(j=0; j<m;j++)
                   imap[i][j]=0;
        }
        mint=0;
        BFS(n-1,m-1,0,0);
        if(mint ==0)
            printf("God please help our poor hero.\n");
        else{
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",mint);
            printmap(0,0);
            /*for(i=1;i<=mint;i++){
                printf("%s",route[i]);
            }*/
        }
        printf ("FINISH\n"); 
    }
}
