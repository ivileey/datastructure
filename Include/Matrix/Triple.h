//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//5.2.2   ϡ������ѹ���洢
//1. ϡ��������Ԫ�ص���Ԫ����

#include<iostream>
using namespace std;

class Triple                                               //ϡ��������Ԫ�ص���Ԫ����
{
  public:
    int row, column, value;                                //�кš��кš�Ԫ��ֵ

    Triple(int row=0, int column=0, int value=0)           //����ϡ�������Ԫ��
    {
        if (row>=0 && column>=0)
        {
            this->row = row;                               //�к�
            this->column = column;                         //�к�
            this->value = value;                           //Ԫ��ֵ
        }
        else throw invalid_argument("ϡ�����Ԫ����Ԫ�����/����ŷ�������");  //�׳���Ч�����쳣
    }

    friend ostream& operator<<(ostream& out, Triple &t)   //�����Ԫ��
    {
        out<<"("<<t.row<<","<<t.column<<","<<t.value<<")";
        return out;
    }

    //������Ԫ��λ�ñȽ�������Ԫ��������С����Ԫ��ֵ�޹أ�Լ����Ԫ���������
    bool operator==(Triple &t)                            //�Ƚ���Ԫ���Ƿ���ȣ�ʶ����󣬽��Ƚϣ��С��У�
    {
        return this->row==t.row && this->column==t.column;
    }
    bool operator!=(Triple &t)
    {
        return !(*this==t);
    }

    bool operator>(Triple &t)                             //�Ƚ���Ԫ���С��Լ��������򣬽��Ƚϣ��С��У�
    {
        return this->row>t.row || this->row==t.row && this->column>t.column;     //������
    }
    bool operator>=(Triple &t)
    {
        return this->row>t.row || this->row==t.row && this->column>=t.column;
    }
    bool operator<(Triple &t)
    {
        return this->row<t.row || this->row==t.row && this->column<t.column;
    }
    bool operator<=(Triple &t)
    {
        return this->row<t.row || this->row==t.row && this->column<=t.column;
    }

    Triple symmetry()                                     //�������жԳ�Ԫ��
    {                                                     //������ִ�й��캯�����������캯������ִ������
        return Triple(this->column, this->row, this->value);
    }
};
