//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����4.5��  �õݹ��㷨����Fibonacci���С�

#include <iostream>
using namespace std;

int fibonacci(int n)                                       //��Fibonacci���е�n��ݹ麯��
{
    if (n==0 || n==1)                                      //�߽��������ݹ��������
        return n;
    if (n>=2)
        return fibonacci(n-2)+fibonacci(n-1);              //�ݹ���ã�����ͨʽ
    throw invalid_argument("Fibonacci���е�n<0ʱ�޶���");  //�׳���Ч�����쳣
}

int main()
{
    for (int i=0; i<=20; i++)
        cout<<fibonacci(i)<<" ";
    cout<<endl;

    system("pause");
    return 0;
}

/*
�������н�����£�
 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765
*/