//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����1.1��  �㷨ʱ�临�Ӷȷ�����

#include <iostream>
using namespace std; 

int main() 
{ 
    int n=8,count=0,i,j;
    for (i=1; i<=n; i++)                         //ʱ�临�Ӷ�ΪO(n)��ѭ�����
        count++;
    cout<<"1 count="<<count<<"\tn="<<n<<endl;

    count=0;
    cout<<"i=";
    for (i=1; i<=n; i*=2)                        //ʱ�临�Ӷ�ΪO(log2(n)+1)��ѭ�����
    {
        cout<<i<<"  ";
        count++;
    }
    cout<<"\n2 count="<<count<<"\n";//<<log(n);

    count=0;
    for (i=1; i<=n; i++)                         //ʱ�临�Ӷ�ΪO(n*n)�Ķ���ѭ��
        for(j=1; j<=n; j++)
            count++;
    cout<<"3 count="<<count<<"\tn*n="<<n*n<<endl;

    count=0;
    for (i=1; i<=n; i++)                         //ʱ�临�Ӷ�ΪO(n*n)�Ķ���ѭ��
        for (j=1; j<=i; j++)
            count++;
    cout<<"4 count="<<count<<"\tn*(n+1)/2="<<n*(n+1)/2<<endl;

    count=0;
    for (i=1; i<=n; i*=2)                        //ʱ�临�Ӷ�ΪO(nlog2(n))�Ķ���ѭ��
        for (j=1; j<=n; j++)
            count++;
    cout<<"5 count="<<count<<"\tn*log2(n)="<<endl; //n*log2(n)<<

    count=0;
    for (i=1; i<=n; i*=2)                        //ʱ�临�Ӷ�ΪO(n)�Ķ���ѭ��
        for (j=1; j<=i; j++)
            count++;
    cout<<"6 count="<<count<<"\t2n-1="<<2*n-1<<endl;
    system("pause");
    return 0;
}

/*
�������н������:
1 count=8	n=8
i=1  2  4  8  
2 count=4
3 count=64	n*n=64
4 count=36	n*(n+1)/2=36
5 count=32	n*log2(n)=32
6 count=15	2n-1=15

*/