//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����2.3����������������

#include "SinglyList.h"                                    //��������

int main()
{
    SinglyList<char> lista("abc",3), listb("xy",2);        //����������
    lista += listb;                                        //��listb������lista֮��
    cout<<"lista��"<<lista<<"listb��"<<listb;              //���������

    system("pause");
    return 0;
}

/*
�������н�����£�
��1�����ò���
lista��(a, b, c, x, y) 
listb��()


��2�����������ǳ����
(a, b, c, x, y) 
()                                                   //���д�

��3��������������
����~SinglyList ()
lista��(a, b, c, x, y)
listb��(x, y)
����~SinglyList (x, y)
����~SinglyList (a, b, c, x, y)


*/
