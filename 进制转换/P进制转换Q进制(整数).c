#include <iostream>

using namespace std;

//p����ת��10����
int y = 0,product = 1;
while(x != 0){
    y += (x%10)*product;
    x /= 10;
    product *= p; 
}

//10����תQ����,���ʱ�Ӻ���ǰ�������
int z[40],num =0;
do{
    z[num++] = y%Q;
    y /= Q;
}while(y != 0)