//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����

#include "TermX.h"
class TermXY : public TermX                                //��Ԫ����ʽ��һ��
{
//  protected:
  public:
    int yexp;                                              //yָ��
    TermXY(double coef=0,int xexp=0,int yexp=0);           //����һ��
    friend ostream& operator<<(ostream& out, TermXY& termxy); //�������������������<<
//    bool operator==(TermXY& termxy);                       //��xָ����yָ���Ƚ������Ƿ����
//    bool operator!=(TermXY& termxy);
    bool operator<(TermXY& termxy);                        //��xָ����yָ���Ƚ������С
    bool operator<=(TermXY& termxy);
    bool operator>(TermXY& termxy);
    bool operator>=(TermXY& termxy);

    TermXY(TermX term) :  TermX(term)           //����һ��
    {
        yexp=0;
    }
/*    bool operator==(TermX& termx)                       //��xָ����yָ���Ƚ������Ƿ����
    {
        return TermX::operator==(termx);
    }*/
};
