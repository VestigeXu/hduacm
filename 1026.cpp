#include <iostream>
#include <sstream>
using namespace std;
int imap[101][101];
char cmap[101][101];
int n,m,mint;
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int direct[101][101];
string route[1001];
int BFS(int x,int y,int t,int dir)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return 0;
    if(x==0 && y==0 && t>0)
        return 0;
    if(cmap[x][y]=='X')
        return 0;
    int hp=cmap[x][y]-'0';
    if(hp > 9 || hp < 0)
        hp=0;
    while(hp--){
        t++;
        //cout << x << ' ' << y << ' ' << t <<endl;
    }
    if(imap[x][y]!=0 && imap[x][y] < t)
        return 0;
    else{
        imap[x][y]=t;
        direct[x][y]=dir;
    }
    if(x==n-1 && y==m-1)
    {
        if(mint > imap[x][y] || mint==0)
            mint = imap[x][y];
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << imap[i][j] << ' ';
            }
            cout <<endl;
        }
        cout << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << direct[i][j] << ' ';
            }
            cout <<endl;
        }
        cout << endl;
        */
    }
    for(int i=0;i<4;i++){
        BFS(x+step[i][0],y+step[i][1],t+1,i);
    }
    return 0;
}
int print(int x,int y)
{
    if(x <0 || y<0 || y>=m || x>=n || mint==0)
        return 0;
    if(x==0 && y==0)
        return 0;
    stringstream ss;
    int distance=imap[x][y]-imap[x-step[direct[x][y]][0]][y-step[direct[x][y]][1]];
    for(int i=1;i<distance;i++){
        stringstream si;
        si << imap[x][y]-i+1 << "s:FIGHT AT (" << x << ',' << y << ')' << endl; //8s:FIGHT AT (1,4)
        route[imap[x][y]-i+1] = si.str();
    }
    ss << imap[x][y]-distance+1 << "s:("<< x-step[direct[x][y]][0] << ',' << y-step[direct[x][y]][1] << ")->(" << x << ',' << y << ')'  << endl;
    route[imap[x][y]-distance+1] = ss.str();
    print(x-step[direct[x][y]][0],y-step[direct[x][y]][1]);
    return 0;
}
int main(){
    while(cin >> n >> m)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cin >> cmap[i][j];
                imap[i][j]=0;
            }
        mint=0;
        BFS(0,0,0,0);
        if(mint ==0)
            cout << "God please help our poor hero." << endl;
        else{
            print(n-1,m-1);
            cout << "It takes "<< mint <<" seconds to reach the target position, let me show you the way."<<endl;
            for(int i=1;i<=mint;i++){
                cout << route[i];
            }
        }
        cout << "FINISH" <<endl;
    }
}
