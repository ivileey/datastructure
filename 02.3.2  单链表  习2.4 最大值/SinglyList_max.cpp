//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//��ϰ2.4��������Ԫ�ص����ֵ��
//������������

#include "Array.h"                                         //������Ĳ��������̲���1.3
#include "SeqList.h"                                       //˳�����
#include "SinglyList.h"                                    //��������

template <class T>
T max(SeqList<T> &list)                                    //����˳���listԪ�ص����ֵ��T��������>�����
{
    T maxValue = list[0];                                  //maxValue��ס��ǰ���ֵ��ִ��T��=
    for (int i=1; i<list.count(); i++)
        if (list[i] > maxValue)                            //T��������>�����
            maxValue = list[i];                            //ִ��T��=
    return maxValue;                                       //ִ��T�Ŀ������캯��
}  
/*
//����list.get(i)���������У�Ч�ʵ�
template <class T>
T max(SinglyList<T> &list)                                 //���ص�����listԪ�ص����ֵ��T��������>�����
{
    if (list.empty())
        throw invalid_argument("������Ϊ�գ����ܼ��㡣");  //�׳���Ч����
    T maxvalue = list.get(0);                              //��õ������0��Ԫ��
    for (int i=1; i<list.count(); i++)
        if (list.get(i) > maxvalue)                        //T��������>�����
            maxvalue = list.get(i);                        //ִ��T��=
    return maxvalue;                                       //ִ��T�Ŀ������캯��
}
*/

/*//����������Ч����ߣ�ʱ�临�Ӷ���O(n)��
//Ҫ�����list�������head��Ա�����ķ���Ȩ�ޡ����㷨�뵥����Ĵ洢�ṹ�йأ���������벻��ͷ��㣬�㷨ʵ�ֲ�ͬ��
template <class T>
T max(SinglyList<T> &list)                                 //���ص�����listԪ�ص����ֵ��T��������>�����
{
    if (list.empty())
        throw invalid_argument("������Ϊ�գ����ܼ��㡣");  //�׳���Ч����
    T maxvalue = list.head->next->data;                    //Ҫ������head��Ա�����ķ���Ȩ������Ϊpublic
    for (Node<T> *p=list.head->next->next;  p!=NULL;  p=p->next)
        if (p->data > maxvalue)
            maxvalue = p->data;
    return maxvalue;                                       //ִ��T�Ŀ������캯��
}*/

//�Ե�����ʽ����������Ч����ߣ�ʱ�临�Ӷ���O(n)��
//���Բ�����list�������head��Ա�����ķ���Ȩ�ޡ����뵥����Ĵ洢�ṹ�޹أ����벻��ͷ��㣬�㷨��ͬ��
template <class T>
T max(SinglyList<T> &list)                                 //����list����������ֵ��T��������>�����
{
    Node<int> *p=list.first();                             //��õ������0��Ԫ�أ�O(1)
    int maxvalue=p->data;
    while (p!=NULL)
    {
        if (p->data > maxvalue)
            maxvalue = p->data;
        p=list.next(p);                                    //���p���ĺ�̽�㣬O(1)
    }
    return maxvalue;
}

template <class T>
void create(SinglyList<T> &list, T value[], int n)         //��ָ�������ṩԪ�ش�����������
{
    for (int i=0; i<n; i++)
        list.head->next = new Node<T>(value[i], list.head->next);
}

int main()
{
    const int N=10, SIZE=100;
    int value[N]={0};
    random(value,N,SIZE);                                  //������������У�������Array.h��

//    SeqList<int> lista(value, N); 
//    cout<<"˳���lista��"<<lista<<"���ֵ��"<<max(lista)<<endl;

    SinglyList<int> lista;
//    int value[N]={10,9,8,7,6,5,4,3,2,1};
    create(lista, value, N); 
    cout<<"������lista��"<<lista<<"���ֵ��"<<max(lista)<<endl;


    system("pause");
    return 0;
}
/*
�������н�����£�
������lista��(64, 62, 58, 78, 24, 69, 0, 34, 67, 41)
���ֵ��78

*/
