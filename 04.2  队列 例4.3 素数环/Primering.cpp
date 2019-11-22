//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����4.3�� ������������⡣

#include <math.h>                                          //����sqrt()����
#include "SeqList.h"                                       //˳�����
#include "SeqQueue.h"                                      //˳��ѭ��������
#include "LinkedQueue.h"                                   //��ʽ������
#include "DoublyQueue.h"                                   //��ʽ�����࣬ʹ��ѭ��˫��������Ϊ��Ա����ʵ�ֶ���

bool isPrime(int key)                                      //�ж�key�Ƿ�Ϊ����
{
    if (key==2)
        return true;
    if (key<2 || key>2 && key%2==0)
        return false;

    int j=(int)sqrt((double)key);                          //sqrt(key)����key��ƽ����ֵ��������math.h��
    if (j%2==0)
        j--;                                               //��ò��Է�Χ�ڵ��������
    while (j>2 && key%j!=0)
        j-=2;
    return j<2;
}

void primering(int n)                                      //���1��n��������һ����
{
    SeqList<int> ring(n);                                  //����һ��˳���洢������
    ring.insert(1);                                        //1��ӵ���������

    SeqQueue<int> que;                                     //�ն���
//    LinkedQueue<int> que;
//    DoublyQueue<int> que;
    for (int i=2; i<=n; i++)                               //2��nȫ�����
        que.enqueue(i);

    int i=0;
    while (!que.empty()) 
    {
        int key = que.dequeue();                           //����
        if (isPrime((ring[i]+key)))                        //�ж��Ƿ�Ϊ����
        {
            ring.insert(key);                              //key��ӵ����������
            i++;
        }
        else
            que.enqueue(key);                              //�ٴ����
        cout<<que;                                         //�������
    }
    cout<<"1��"<<n<<"��������"<<ring;                      //���������
}

int main()
{
    primering(10);
    system("pause");
    return 0;
}
    
/*
�������н�����£�
1��10��������(1, 2, 3, 4, 7, 10, 9, 8, 5, 6)

1��20��������(1, 2, 3, 4, 7, 10, 13, 16, 15, 8, 9, 14, 17, 20, 11, 12, 19, 18, 5, 6)

*/
