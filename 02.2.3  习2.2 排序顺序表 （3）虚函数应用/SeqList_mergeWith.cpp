//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.2.2   ˳��� 2. ˳����ǳ���������
//2.2.3   ����˳���
//10.  �麯�����ͺ�����
//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//��ϰ2.2��  �������˳���
//��3�� �麯��Ӧ��

#include "SortedSeqList.h"                                 //����˳����࣬����"Array.h"

int main()
{
    const int N=7, SIZE=100; 
    int values[N]={0};
    random(values,N,SIZE);                                 //��������1.3 Array.h��

    //10.  �麯�����ͺ����࣬�̲ĵ�47ҳ
    //��SeqList������insert(T x)Ϊvirtual�麯��  
    SeqList<int> lista(values, N), listb(lista), listc, listd;
    SortedSeqList<int> slist1(lista), slist2(slist1), slist3;      //slist1(lista)��˳���������˳���
    cout<<"lista(listb)��  "<<lista<<"slist1(slist2)��"<<slist1;

//    lista += slist1;                                       //����+=���࣬��β�������ϲ�����
//    slist1 += listb;                                       //����+=���࣬����˳������ϲ�����Ȼ����
//    cout<<"lista+=slist1�� "<<lista<<"slist1+=listb�� "<<slist1;
  
//    cout<<"listb+slist2��  "<<(listb+slist2)<<"slist2+listb��  "<<(slist2+listb);  //���߿��������д�

    //������û�и���+ʱ��
//    listc = slist2 + listb;          
//    slist3 = slist2 + listb;        //����û�и���+ʱ�������+�ķ���ֵ����ΪSeqList<T>�����ܽ�������ʵ�����޷�ת��

    //�����า��+ʱ��
    listc = listb + slist2;           //ִ��SeqList��+������SeqListʵ������ֵ��SeqList����
    listd = slist2 + listb;           //ִ��SortedSeqList��+������SortedSeqListʵ������ֵ��SeqList����
    slist3 = slist2 + listb;          //ִ��SortedSeqList��+������SortedSeqListʵ������ֵ��SortedSeqList����
    cout<<"listc=listb+slist2��"<<listc<<"listd=slist2+listb��"<<listd<<"slist3=slist2+listb��"<<slist3;

    system("pause");
    return 0;
}

/*
//�������н����������ϰ����2.2��
��1��SortedSeqList����̳�+���������н�����¡�
lista(listb)��  (41, 67, 34, 0, 69, 24, 78)
slist1(slist2)��(0, 24, 34, 41, 67, 69, 78)
lista+=slist1�� (41, 67, 34, 0, 69, 24, 78, 0, 24, 34, 41, 67, 69, 78) //˳���
slist1+=listb�� (0, 0, 24, 24, 34, 34, 41, 41, 67, 67, 69, 69, 78, 78) //����˳���
listb+slist2��  (41, 67, 34, 0, 69, 24, 78, 0, 24, 34, 41, 67, 69, 78) //˳���
slist2+listb��  (0, 24, 34, 41, 67, 69, 78, 41, 67, 34, 0, 69, 24, 78) //����˳����������

�����������ͬ�ϡ�
SeqList<T>& SeqList<T>::operator+=(SeqList<T> &list)

��2��SortedSeqList���า��+���������н�����¡�
lista(listb)��  (41, 67, 34, 0, 69, 24, 78)
slist1(slist2)��(0, 24, 34, 41, 67, 69, 78)
listc=listb+slist2��(41, 67, 34, 0, 69, 24, 78, 0, 24, 34, 41, 67, 69, 78)
listd=slist2+listb��(0, 0, 24, 24, 34, 34, 41, 41, 67, 67, 69, 69, 78, 78)  //����˳��������ȷ
slist3=slist2+listb��(0, 0, 24, 24, 34, 34, 41, 41, 67, 67, 69, 69, 78, 78) //����˳��������ȷ

*/
    
