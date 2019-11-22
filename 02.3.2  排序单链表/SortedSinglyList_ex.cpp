//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.3.2   ������
//5.  �������ǳ���������
//6.  ��������

#include "Array.h"
#include "SortedSinglyList.h"                              //����������

int main()
{
    const int N=7, SIZE=100; 
    int value[N]={0};
    int value2[N]={0};
    random(value,N,SIZE);                                  //������Array.h��
    random(value2,N,SIZE);

    SortedSinglyList<int> slist1(value, N,false);                //Ĭ������
    SortedSinglyList<int> slist2(slist1), slist3=slist1, slist4;  //slist2(slist1), slist3=slist1ִ�п������캯��
    slist4=slist1;                                           //Ĭ�ϸ�ֵ�����̳л����=
    cout<<"slist1��"<<slist1<<"slist2��"<<slist2<<"slist3��"<<slist3<<"slist4��"<<slist4;
    cout<<"slist1.getCount()="<<slist1.count()<<endl;

    int x = slist1.get(0)-1;                                //֧��get(i)
    slist1.insert(x);                                       //���ຯ�������ǻ���
    int y = slist1.get(slist1.count()-1);
    slist1.insert(y);
    slist1.remove(value[0]); 
    cout<<"slist1����"<<x<<"��"<<y<<"��ɾ��"<<value[0]<<endl;
    cout<<"slist1��"<<slist1<<"slist2��"<<slist2<<"slist3��"<<slist3<<"slist4��"<<slist4;
//    slist1.set(0,100);                                    //��֧�ָò���
//    slist1.insert(0,50);                                  //�������SortedSinglyList<T>::insert��: ���������� 2 ������

    SinglyList<int> lista(value2, N),listb(lista);
    lista.insert(0,-1);                                    //���������û��ຯ�������������
    lista.insert(50);                                      //���������û��ຯ����������β����
    SinglyList<int> listc(slist2), listd;                  //listb(list2)ִ��SinglyList<T>�������캯��������������������󣬲�����ֵ����
    listd = slist2;                                        //ִ�л���ĸ�ֵ��������ֵ����
    cout<<"lista��"<<lista<<"listb��"<<listb<<"listc��"<<listc<<"listd��"<<listd;

    //==�ļ̳��ԣ��̳й�ϵ
    cout<<"slist2==listb��"<<(slist2==listb)<<endl;        //����==����
    cout<<"listb==slist2��"<<(listb==slist2)<<endl;        //����==����
    cout<<"slist2==slist3��"<<(slist2==slist3)<<endl;      //����==����

    SortedSinglyList<int> slist5(lista);                 //�ɻ����������������ɵ���������������û�ж�����
               //����ִ��slist5.insert(50);���ǣ��������������ຯ���������������
               //���า�ǻ���ͬ����Ա���������۲����б��Ƿ���ͬ������ʱ��̬��Ҳ���������ࡣ
    cout<<"slist5��"<<slist5;

    SortedSinglyList<int> slist6(lista, false);             //�ɻ��������������󣬽����ɵ���������������û�ж�����
    cout<<"slist6��"<<slist6;


    //�麯��������ʱ���ǡ�����ʱ��̬��Ҳ���ͺ����ࡣ
    lista += slist1;                               //���ӣ�����+=���ִ࣬�л��ຯ�����������������
    cout<<"lista += slist1;\nlista��"<<lista;
/*    //һ��������������̳У�û�и��ǣ������µ����﷨��ȷ�����嶼�����ӡ�mergeWith()������Ϊ�麯��
    slist2 += listb;                               //���ӣ�����.mergeWith(����)��ִ�л��ຯ���������ǻ������
    cout<<"slist2 += listb;\nslist2��"<<slist2<<"listb��"<<listb;
    slist3.mergeWith(slist4);                              //���ӣ�����.mergeWith(����)��ִ�л��ຯ�����������������
    cout<<"slist3.mergeWith(slist4);\nslist3��"<<slist3<<"slist4��"<<slist4;
*/
    //��һ���������������������ǣ��������﷨��������塣
//    slist2.mergeWith(listb);                               //��������ǣ�SortedSinglyList<T>::mergeWith ��֧��SinglyList<T>���Ͳ���
//    cout<<"slist2.mergeWith(listb);\nslist2��"<<slist2;
    slist3 += slist4;                              //�鲢�������� += ���ִ࣬�����ຯ������������������Ƿ��麯���������ͬ
    cout<<"slist3 += slist4;\nslist3��"<<slist3<<"slist4��"<<slist4;

    system("pause");
    return 0;
}

/*
�������н�����£�
slist1��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
slist2��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
slist3��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
slist4��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
slist1����40��61��ɾ��41
slist1��(40, 61, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
slist2��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
slist3��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
slist4��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
lista��(-1, 41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 50)
listb��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
listc��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
slist5��(-1, 0, 5, 24, 27, 34, 41, 45, 50, 58, 61, 62, 64, 67, 69, 78, 81)
slist2==listb��1
listb==slist2��1
slist2==slist3��1
*p��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 50)
*p��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)                        //insert(T x)û������virtual
����50��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 50)
�밴���������. . . 
SinglyList����(-1, 0, 5, 24, 27, 34, 41, 45, 50, 58, 61, 62, 64, 67, 69, 78, 81)
SinglyList����(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
SinglyList����(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
SinglyList����(-1, 41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 50)
SinglyList����(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
SinglyList����(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
SinglyList����(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)
SinglyList����(40, 61, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61)


*p��(41, 67, 34, 0, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61, 50)
*p��(0, 5, 24, 27, 34, 41, 45, 58, 61, 62, 64, 67, 69, 78, 81)                       //insert(T x)����virtual
����50��(0, 5, 24, 27, 34, 41, 45, 50, 58, 61, 62, 64, 67, 69, 78, 81)



    //+=��+�ļ̳��ԣ��̳й�ϵ��������Ҫ����ʱ����
    cout<<"lista + slist1��"<<(lista.mergeWith(slist1);            //����+���ִ࣬�л��ຯ�����������������
//����    cout<<"slist2 + listb��"<<(slist2 + listb);            //����+���࣬�̳У������ǻ������
//����    cout<<"slist3 + slist4��"<<(slist3 + slist4);          //����+���࣬�̳У��������������

    lista += slist1;                                       //����+=���ִ࣬�л��ຯ�����������������
    cout<<"lista += slist1;\nlista��"<<lista;
    slist2 += listb;                                       //����+=���࣬�̳У������ǻ������
    cout<<"slist2 += listb;\nslist2��"<<slist2;
    slist3 += slist4;                                      //����+=���࣬�̳У��������������
    cout<<"slist3 += slist4;\nslist3��"<<slist3;


*/
//������������롢ɾ�����ԣ���


/* 2013��9��19��
slist1��(0, 24, 34, 41, 67, 69, 78)
slist2��(0, 24, 34, 41, 67, 69, 78)
slist3��(0, 24, 34, 41, 67, 69, 78)
slist4��(0, 24, 34, 41, 67, 69, 78)
slist1.getCount()=7
slist1����-1��78��ɾ��41
slist1��(-1, 0, 24, 34, 67, 69, 78, 78)
slist2��(0, 24, 34, 41, 67, 69, 78)
slist3��(0, 24, 34, 41, 67, 69, 78)
slist4��(0, 24, 34, 41, 67, 69, 78)
lista��(-1, 58, 62, 64, 5, 45, 81, 27, 50)
listb��(58, 62, 64, 5, 45, 81, 27)
listc��(0, 24, 34, 41, 67, 69, 78)
listd��(0, 24, 34, 41, 67, 69, 78)
slist2==listb��0
listb==slist2��0
slist2==slist3��1
�밴���������. . . 
slist5��(-1, 5, 27, 45, 50, 58, 62, 64, 81)
slist6��(81, 64, 62, 58, 50, 45, 27, 5, -1)
lista.mergeWith(slist1);
lista��(-1, 58, 62, 64, 5, 45, 81, 27, 50, -1, 0, 24, 34, 67, 69, 78, 78)
slist2.mergeWith(listb);                                   //һ�����������̳�û�и���ʱ�����﷨��ȷ�����嶼�����ӡ�
slist2��(0, 24, 34, 41, 67, 69, 78, 58, 62, 64, 5, 45, 81, 27)
listb��()
slist3.mergeWith(slist4);
slist3��(0, 24, 34, 41, 67, 69, 78, 0, 24, 34, 41, 67, 69, 78)
slist4��()

slist3.mergeWith(slist4);                                  //��һ������������������ǣ���������壬�鲢����
slist3��(0, 0, 24, 24, 34, 34, 41, 41, 67, 67, 69, 69, 78, 78)
slist4��()

*/