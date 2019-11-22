//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����6.1���������Ĺ��졢���������롣

#include "BinaryTree.h"                                    //��������

int main()
{
                                                           //ͼ6.21��ʾ�������������������ȸ�����
    char prelist[] = {'A','B','D',NULL,'G',NULL,NULL,NULL,'C','E',NULL,NULL,'F','H'};
    BinaryTree<char> bitree(prelist, 14);
    cout<<bitree;                                          //����ȸ�����������У�������������
    bitree.inOrder();                                      //����и������������
    bitree.postOrder();                                    //�����������������
    bitree.insert(bitree.root->left,'X');                  //�������ӣ�ͼ6.20��a��
    bitree.insert(bitree.root->right,'Y',false);           //�����Һ��ӣ�ͼ6.20��b��
    bitree.insert('Z');                                    //�����
    cout<<bitree;
    
    bitree.preOrderTraverse();                             //7.  �����������ķǵݹ��㷨
    bitree.inOrderTraverse();
    bitree.levelOrder();                                   //8.  �������Ĳ�α���
    
    system("pause");
    return 0;
}

/*
�������н�����£�
�ȸ��������������:  A B D ��G �ġġ�C E �ġ�F H �ġġ�                 //��6.1
�и��������������:  D G B A E C H F 
����������������:  G D B E H F C A 
�ȸ��������������:  Z A B X D ��G �ġġġ�C E �ġ�Y ��F H �ġġġ�
�밴���������. . . 
����������: G D X B E H F Y C A Z 
*/
 


