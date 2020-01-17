#include <iostream>
#include <iomanip>
/*此题关键是表达式的意思要清楚，
 * 0！=1， 1！=1,2！=2*1，3！=3*2*1 
 * 类推，然后还有就是输出结果格式的转换
 * setfill 设置填充字符，left 表示靠左对齐
 * setw设置宽度因为有一位 最后小数点后有0
 * 所以比较麻烦*/
using namespace std;
int main(){
    double e;
    int a[10]={1,1,2,6,24,120,720,5040,40320,362880};
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    for(int i=e=0;i <= 9; i++){
        e += 1/(a[i]*1.0);
        if(i>2)
            cout << i << ' ' << setw(11) << left <<setfill('0') << setprecision(10) << e << endl;
        else
            cout << i << ' ' << e << endl;
    }
}
