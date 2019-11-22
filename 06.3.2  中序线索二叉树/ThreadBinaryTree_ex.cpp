//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.3   ����������
//6.3.2   ��������������
//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//��ϰ6.1�����������������������ֱ��ȸ����и���������������

#include "ThreadBinaryTree.h"                         //����������������

int main()
{                                                      //ͼ6.25��ʾ�������������������ȸ���������
    char prelist[] = {'A','B','D',NULL,NULL,'E','G',NULL,NULL,NULL,'C','F',NULL,'H',NULL,NULL,'K'};
    ThreadBinaryTree<char> tbitree(prelist, 17);      //������������������
    tbitree.inOrder();                                //�и��������
    tbitree.preOrder();                               //�ȸ��������
    tbitree.inOrderPrevious();                        //�и������������ǰ����
    tbitree.postOrderPrevious();                      //��������������ǰ����

    system("pause");
    return 0;
}

/*
�������н�����£�
//����
�и����������������������:  C B X F E G H D W A Y J M L K N Z I O 
�ȸ����������������������:  A B C X D E F G H W I Z J Y K L M N O 
�и����򣨷��򣩱�����������������:  O I Z N K L M J Y A W D H G E F X B C 
������򣨷��򣩱�����������������:  A I O Z J K N L M Y B X D W E G H F C 
������������������: C F H G E W D X B Y M L N K J Z O I A 

*/ 
/*
���µ�3��δ����
    char prelist[] = {'A','B','C',NULL,NULL,'D','E','F',NULL,NULL,'G',NULL,'H',NULL,NULL,NULL,
                          'I','J',NULL,'K','L','M',NULL,NULL,NULL,'N',NULL,NULL,'O'};
    ThreadBinaryTree<char> tbitree(prelist, 29);      //������������������
    //����
//    ThreadBinaryTree<char> tbitree;                   //��������������������
    tbitree.insertRoot('A');                          //�����
    tbitree.insert(tbitree.root->left->right, 'W', false);//����D���Һ���W
    tbitree.insert(tbitree.root->left, 'X', false);     //����B���Һ���X
    tbitree.insert(tbitree.root->right->left, 'Y');     //����J���Һ���Y
    tbitree.insert(tbitree.root->right, 'Z');           //����I���Һ���Z

    //ɾ��
//    ThreadBinaryNode<char> *p=tbitree.insert(tbitree.root->left, 'M', false);//����B���Һ���M
    tbitree.remove(tbitree.root->left,false);         //ɾ��B���Һ���X
    tbitree.remove(tbitree.root->left->right,false);  //ɾ��D���Һ���W
    tbitree.remove(tbitree.root->left,false);         //ɾ��B���Һ���D

/*
    //ɾ���Һ���
//    char prelist[] = {'A','B','C',NULL,NULL,'X','D','E',NULL,NULL,'F',NULL,'G',NULL,NULL,'H','I','J',NULL,NULL,NULL,'K',NULL,NULL,'L'};                                                
    char prelist[] = "ABC\0\0XDE\0\0F\0G\0\0HIJ\0\0\0K\0\0L";      //����                                          
    ThreadBinaryTree<char> tbitree(prelist, 25);
    tbitree.removeRightChild(tbitree.root->left->left);  //ɾ��C���Һ��ӣ�û�У���ɾ��
    tbitree.removeRightChild(tbitree.root->left);                //ɾ��B���Һ���X��X��2�Ƚ��
    tbitree.removeRightChild(tbitree.root->left->right->right);  //ɾ��F���Һ���G��G��ֻ���Һ��ӵ�1�Ƚ��
    tbitree.removeRightChild(tbitree.root->left->right->right->right);   //ɾ��H���Һ���K��K��0�Ƚ��
    tbitree.removeRightChild(tbitree.root->left->right->right);  //ɾ��F���Һ���H��H��ֻ�����ӵ�1�Ƚ��

    //ɾ������
    char prelist[] = "AB\0\0CXDE\0\0F\0G\0\0HIJ\0\0\0K\0\0L";      //����                                          
    ThreadBinaryTree<char> tbitree(prelist, 25);
    tbitree.removeLeftChild(tbitree.root->left);           //ɾ��B�����ӣ�û�У���ɾ��
    tbitree.removeLeftChild(tbitree.root->right);          //ɾ��C������X��X��2�Ƚ��
    tbitree.removeLeftChild(tbitree.root->right->left);    //ɾ��D������E��E��0�Ƚ��
    tbitree.removeLeftChild(tbitree.root->right);          //ɾ��C������D��D��ֻ���Һ��ӵ�1�Ƚ��
    tbitree.removeLeftChild(tbitree.root->right->left->right->right);  //ɾ��H������I��I��ֻ�����ӵ�1�Ƚ��
/*
    tbitree.remove(tbitree.root->left);           //ɾ��B�����ӣ�û�У���ɾ��
    tbitree.remove(tbitree.root->right);          //ɾ��C������X��X��2�Ƚ��
    tbitree.remove(tbitree.root->right->left);    //ɾ��D������E��E��0�Ƚ��
    tbitree.remove(tbitree.root->right);          //ɾ��C������D��D��ֻ���Һ��ӵ�1�Ƚ��
    tbitree.remove(tbitree.root->right->left->right->right);  //ɾ��H������I��I��ֻ�����ӵ�1�Ƚ��

    tbitree.inOrder();                                //�и��������
    tbitree.preOrder();                               //�ȸ��������
    tbitree.inOrderPrevious();                        //�и������������ǰ����
    tbitree.postOrderPrevious();                      //��������������ǰ����
*/


//??
//    ThreadBinaryNode<char> *node = tbitree.root->left->right->right;    //
/*    ThreadBinaryNode<char> *node = tbitree.root->right->left->left;       
    ThreadBinaryNode<char> *parent = tbitree.getParent(node);
    cout<<node->data<<"�ĸ�ĸ�����";
    if (parent==NULL)
        cout<<"NULL"<<endl;
    else
        cout<<parent->data<<endl;
*/
//����6.4
/*
#include "ThreadBinaryTree.h"                         //����������������

int main()
{
    char prelist[] = "PHEJLKACFG";                         //10
    char inlist[] = "EHLJPAFCKG";                          //���ELJHFCAGKP
    ThreadBinaryTree<char> tbitree(prelist, inlist,10);    //���ȸ����и����д�����������������
    tbitree.inOrder();                                     //�и��������
    tbitree.preOrder();                                    //�ȸ��������
    tbitree.inOrderPrevious();                             //�и������������ǰ����
    tbitree.postOrderPrevious();                           //��������������ǰ����

    system("pause");
    return 0;
}

/*
�������н�����£�
*/