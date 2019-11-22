//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����1.2��  ���Լ��

#include <iostream>
using namespace std; 

int gcd(int a, int b)                 //����a,b�����Լ��
{
    cout<<"gcd("<<a<<","<<b<<")=";
    while (b!=0)
    {
        int temp = a%b;
        a = b;
        b = temp; 
        cout<<"gcd("<<a<<","<<b<<")=";
    }
    return a;
}

int gcd2(int a, int b)                  //����a,b�����Լ�����ݹ麯��
{
    cout<<"gcd("<<a<<","<<b<<")=";
    if (b==0)
	    return a;
    return gcd2(b, a%b);
}

int main() 
{
    int a=91, b=49;
    cout<<gcd(b,-a)<<endl;
    cout<<gcd2(a,b)<<endl;

    int c=35;
    cout<<"gcd("<<a<<","<<b<<","<<c<<")="<<gcd(gcd(a,b),c)<<endl;

    cout<<gcd(26460,12375)<<endl;
    system("pause");
    return 0;
}

/*
�������н������:
gcd(49,-91)=gcd(-91,49)=gcd(49,-42)=gcd(-42,7)=gcd(7,0)=7
gcd(91,49)=gcd(49,42)=gcd(42,7)=gcd(7,0)=7
gcd(91,49,35)=7
gcd(26460,12375)=gcd(12375,1710)=gcd(1710,405)=gcd(405,90)=gcd(90,45)=gcd(45,0)=45
*/