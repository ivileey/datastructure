//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����2.2��������Ϣ����ͳ������ҡ�
//ѧ����Ϣ

#include <iostream>
using namespace std;
#include "string.h"

struct Student
{
    char name[20];                                         //����
    double score;                                          //ĳ�ſγ̳ɼ�
    friend ostream& operator<<(ostream& out, Student &stu) //�������������
    {
        out<<"("<<stu.name<<","<<stu.score<<")";
        return out;
    }
    //����==��ϵ��������Ƚ�����Student�����Ƿ���ȣ�����Ϊ���Ƚ�name���ⰴnameʶ��Student����
    bool operator==(Student &stu)
    {
        return strcmp(this->name,stu.name)==0;   //����string.h�к����Ƚ������Ƿ����
                //����this->name==stu.name����Ϊ�Ƚ��ַ������׵�ַ�Ƿ����
    }
};

/*
    //����>=��ϵ��������Ƚ�����Student�����С������Ϊ�Ƚ�Student��score��Ĵ�С
    bool operator>=(Student &stu)
    {
        return this->score >= stu.score;
    }
    bool operator<(Student &stu)                           //����<��ϵ�����
    {
        return this->score < stu.score;
    }
*/