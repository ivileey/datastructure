//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.4.1   һԪ����ʽ�ı�ʾ������
//���࣬һԪ����ʽ��һ��

#include <iostream>
using namespace std;
#include <math.h>

class TermX                                                //���࣬һԪ����ʽ��һ��
{
//  protected:
  public:
    double coef;                                           //ϵ��
    int xexp;                                              //x����ָ������Ϊ����0

    TermX(double coef=0, int xexp=0);                      //����һ�ָ��Ĭ��ֵ
//    TermX(char* termstr);                                  //�ԡ�ϵ��x^ָ������ʽ�ַ�������һ��
    friend ostream& operator<<(ostream& out, const TermX& term); //����<<����������
    bool operator==(TermX& term);                          //��xָ���Ƚ������Ƿ���ȣ����������==
    bool operator!=(TermX& term);
    bool operator<(TermX& term);                           //��xָ���Ƚ������С������<�����
    bool operator<=(TermX& term);
    bool operator>(TermX& term);
    bool operator>=(TermX& term);
    void operator+=(TermX& term);                          //�ӷ������أ�=�������Լ����Ԫ����ӹ���
//    TermX operator+(TermX& term);                          //�ӷ������أ�����������ض���
    bool removable();                                      //Լ��ɾ��Ԫ������
};
