//2.3.3   ˫����
//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//��ϰ2.7��  �ϲ���������ѭ��˫����

#include "CirDoublyList.h"                                 //ѭ��˫������

int main()
{
    CirDoublyList<char> lista("abcd",4), listb("xyz",3);
    lista += listb;
    cout<<"lista��"<<lista<<"listb��"<<listb;

    system("pause");
    return 0;
}

/*
�������н�����£�
lista��(a, b, c, d, x, y, z)
listb��()

*/