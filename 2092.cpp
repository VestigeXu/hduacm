#include <iostream>
using namespace std;

int main(){
    int n=1,m=1;
    while(n!=0 || m!=0)
    {
        cin >> n >> m;
        int i;
        int im;
        if(m<0)im=-1*m;
        else im=m;
        for(i=1;i<im;i++)
        {
            if((m%i==0 && (m/i+i)==n) || (m%(i*-1)==0 && (m/(-1*i)-i)==n))
            {
                cout << "Yes" << endl;
                break;
            }
        }
        if(i==im)
            cout << "No" << endl;
    }
}
