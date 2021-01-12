#include <iostream>
using namespace std;
int map[8][8];
char cmap[8][8];
int N,M,T;
int BFS(int x,int y,int value){
    if(x<0 || y <0 || x>6 || y >6)//超范围直接退出
        return 0;
    if(cmap[x][y] == 'X') //遇到墙直接退出
        return 0;
    if(value+1 > T+1) //超时直接退出
        return 0;
    if(map[x][y]==0 || map[x][y]>(value+1))
    {        
        map[x][y]=value+1;
        BFS(x,y-1,map[x][y]);
        BFS(x+1,y,map[x][y]);
        BFS(x,y+1,map[x][y]);
        BFS(x-1,y,map[x][y]);
    }
    return 0;
}
int main(){
    int isx,isy;
    int iex,iey;
    while(1){
        cin >> N >> M >> T;
        if(N==0 && M==0 && T==0)
            break;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin >> cmap[i][j];
                map[i][j]=0;
                if(cmap[i][j] == 'S')
                {
                    isx=i;
                    isy=j;
                }
                if(cmap[i][j] == 'D')
                {
                    iex=i;
                    iey=j;
                }
            }
        }
        BFS(isx,isy,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout << map[i][j];
            }
            cout << endl;
        }
        if(map[iex][iey] == T+1)
            cout << "YES"<<endl;
        else
            cout << "NO"<<endl;
    }
}
