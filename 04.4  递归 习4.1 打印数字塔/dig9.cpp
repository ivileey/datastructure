//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//��ϰ4.1��  ��ӡ��������

#include <iostream>
using namespace std;

void count(int i, int n)                         //�ݹ麯�������һ��
{
    cout<<i<<"  ";
    if (i<n)
    {
        count(i+1,n);
        cout<<i<<"  ";
    }
}

int main()
{
   int n=9;
   for(int i=1; i<=n; i++)
   {
       for (int j=n; j>i; j--)
           cout<<"   ";
       count(1, i);
       cout<<"\n";
   }
   return 0;
}

/*
�������н�����£�
                          1
                       1  2  1
                    1  2  3  2  1
                 1  2  3  4  3  2  1
              1  2  3  4  5  4  3  2  1
           1  2  3  4  5  6  5  4  3  2  1
        1  2  3  4  5  6  7  6  5  4  3  2  1
     1  2  3  4  5  6  7  8  7  6  5  4  3  2  1
  1  2  3  4  5  6  7  8  9  8  7  6  5  4  3  2  1
*/
