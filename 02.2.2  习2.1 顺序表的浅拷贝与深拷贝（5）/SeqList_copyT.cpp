//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.2.2   ˳���
//2. ˳����ǳ���������
//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//��ϰ2.1��  ˳����ǳ�����������

#include "SeqList.h"                                        //˳�����

//���˳�������Ԫ�أ�����T��ָ�����ͣ���ʽΪ��(,)�����ձ���()
template <class T>
void print(SeqList<T> &list)
{
    cout<<"(";
    int n=list.count();
    if (n>0)
        cout<<*list[0];
    for (int i=1; i<n; i++)
        cout<<", "<<*list[i];
    cout<<")"<<endl;
}

int main()
{
    //�̲ĵ�39��40ҳ
    //��5�� ģ�����T��ʵ�ʲ�������֧�����
    int values[5]={1,2,3,4,5};   
    SeqList<int*> lista;                                   //SeqListԪ��������int*
    for (int i=0; i<5; i++)
        lista.insert(i, &values[i]);                       //��������Ԫ�ص�ַ
    cout<<"lista��"<<lista;
    print(lista);                                          //˳���洢�ṹ���̲�ͼ2.8��a��

    SeqList<int*> listb(lista);                            //ִ��������캯��
    cout<<"listb��"<<listb;
    print(listb);                                          //˳��������Ĵ洢�ṹ���̲�ͼ2.8��a��

    int *p = lista[0];
    *p=9;                                                  //�޸�listaԪ�أ���listb��Ӱ��
    int x=6;
    lista.insert(&x);                                      //ִ�в��롢ɾ��������������listû��Ӱ��
//    listb.remove(3);                                     //ɾ��Ԫ�أ�û���ͷ�Ԫ����ռ�洢��Ԫ
    cout<<"\nlista[0]=9��listaβ����"<<x<<"��listbɾ��Ԫ��"<<*listb.remove(3)<<"��"<<*listb.remove(4)<<endl;
    cout<<"lista��"; print(lista);
    cout<<"listb��"; print(listb);                         //˳���洢�ṹ���̲�ͼ2.8��b��

    system("pause");
    return 0;
}
/*
�������н�����£�
lista��(0029F874, 0029F878, 0029F87C, 0029F880, 0029F884)
(1, 2, 3, 4, 5)
listb��(0029F874, 0029F878, 0029F87C, 0029F880, 0029F884)
(1, 2, 3, 4, 5)

lista[0]=9��listaβ����6��listbɾ��Ԫ��4��5
lista��(9, 2, 3, 4, 5, 6)
listb��(9, 2, 3)

*/