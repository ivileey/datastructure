//2.2.2   ˳��� 2. ˳����ǳ���������
//2.2.3   ����˳���
//10.  �麯�����ͺ�����
//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//��ϰ2.2��  �������˳���

#include "SortedSeqList.h"                                 //����˳����࣬����"Array.h"

int main()
{
    const int N=10, SIZE=100; 
    int values[N]={0};
    random(values,N,SIZE);                                 //��������1.3 Array.h��

    //��1�� ����ʱ��̬������˵����⣬�̲ĵ�48ҳ���麯���ı�Ҫ��
    //��2�� ����ʱ��̬���ͺ��������麯��
    //SeqList������insert(T x)Ϊvirtual�麯�����  
    SeqList<int> *p = new SeqList<int>(values, N);         //pָ��ָ��˳������
    p->insert(50);                                         //ִ��SeqList���insert(x)������˳���β����
    cout<<"p->new SeqList()��      "<<*p;

    p = new SortedSeqList<int>(values, N);                 //pָ��ָ������˳�����󣬸�ֵ����
    p->insert(50);                                         //ִ��SeqList��������ĸ����insert(x)������
    cout<<"p->new SortedSeqList()��"<<*p;

    // int search(T key, int start=0); ����virtual���
    cout<<"����50������ţ�"<<p->search(50)<<endl;         //ִ��SeqList��������ĸ����search(key)������

//    p->insertUnrepeatable(50);                           //�����insertUnrepeatable����SeqList�ĳ�Ա
//�������н����������ϰ����2.2��




    //��������������
    SeqList<int> *q = new SortedSeqList<int>(*p);          //pָ��ָ������˳������ִ��SortedSeqList(SeqList<T> &list)
                                   //û�ж��������⣬��Ϊ��SortedSeqList(SortedSeqList<T> &list)���캯�������б�ͬ������
    cout<<"q->new SortedSeqList()��"<<*q;
    q->insert(50);                                         //ִ��
    cout<<"����50��"<<*q;

    system("pause");
    return 0;
}

/*
�������н����

*/
    
