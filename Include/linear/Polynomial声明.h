//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.4   ���Ա��Ӧ�ã�����ʽ�ı�ʾ������
//2.4.1   һԪ����ʽ�ı�ʾ������

#include "SortedSinglyList.h"                            //��������

//����ʽ�࣬�̳����������࣬�ṩ����ʽ��Ӻ����������������ĺϲ����㣨+=��+��
//T��������+=����� 
template <class T>
class Polynomial : public SortedSinglyList<T> 
{
  public:
    Polynomial(){}                                    //���캯�����Զ�ִ�л��๹�캯��SortedSinglyList<T>()
    Polynomial(T terms[], int n):SortedSinglyList(terms, n){}
                                                      //���캯������������ָ������ʽ����ֵ���������û��๹�캯��SortedSinglyList<T>(T[], int)
    void print();                                     //�������ʽ
    void operator+=(Polynomial<T> &poly);             //*this��poly����ʽ��ӣ�������������Ӻϲ�
    Polynomial<T> operator+(Polynomial<T> &poly);     //����*this��poly��Ӻ�Ķ���ʽ
};
