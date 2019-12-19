#include <iostream>
using namespace std;
int main(){
    int T;
    int y,n;
    cin >> T;
    while(T--){
        cin >> y >> n;
        do{
            if( (y%4==0 && y%100!=0) || (y%400==0))
            {   
                break;
            }
        }while(y++);

        for(int i=1;i<n;i++){
            while(y+=4){
                if( (y%4==0 && y%100!=0) || (y%400==0))
                {   
                    break;
                }
            }
            //cout <<y<< endl;
        }
        cout << y <<endl;
    }
}
