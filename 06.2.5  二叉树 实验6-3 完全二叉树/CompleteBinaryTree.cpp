//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//��ʵ��6-3�����������ʾ����ȫ�������ࡣ

#include "CompleteBinaryTree.h"                       //��ȫ��������

int main()
{
    char levellist[] = "ABCDEFGH";                   //ͼ6.17��ʾ��ȫ�������Ĳ�α�������
    CompleteBinaryTree<char> cbitree(levellist, 8);
    cbitree.preOrder();
    cbitree.inOrder();
    cbitree.postOrder();
    cout<<"��������������"<<cbitree.count()<<endl;
    cout<<"�������߶ȣ�"<<cbitree.height()<<endl<<endl;
    return 0;
}

/*
�������н�����£�
�ȸ��������������:  A B D H E C F G
�и��������������:  H D B E A F C G
����������������:  H D E B F G C A 
������������: 8
�������߶�: 4
����������:  H D E B F G C A 

*/
 
