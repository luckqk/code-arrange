#include <iostream>

using namespace std;

//p进制转换10进制
int y = 0,product = 1;
while(x != 0){
    y += (x%10)*product;
    x /= 10;
    product *= p; 
}

//10进制转Q进制,输出时从后向前输出即可
int z[40],num =0;
do{
    z[num++] = y%Q;
    y /= Q;
}while(y != 0)