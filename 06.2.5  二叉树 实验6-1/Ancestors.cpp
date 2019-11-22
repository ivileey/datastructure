//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//06.2.5  ������ ˼����6-2 ���ڱ����Ĳ���
//��2�桾��6.2��  �����������ָ�������������Ƚ�㡣
//��ʵ��6-1��ʵ��BinaryTree�����ȸ����и����й���������Ĳ�����
//��ʵ��6-1��  ���һ�ö�����������Ҷ�ӽ�㼰Ҷ�ӽ�������

#include "BinaryTree_ʵ��6-1.h"                            //��������

template <class T>
void printAncestors(BinaryTree<T> &bitree, T key)          //���bitree�������йؼ���Ϊkey�����������Ƚ��
{
    BinaryNode<T> *find = bitree.search(key);              //����
    if (find==NULL)
        cout<<"δ�ҵ�"<<value<<endl;
    else
    {
        BinaryNode<T> *parent = bitree.parent(find);
        cout<<key<<"�����Ƚ����";
        while (parent!=NULL)
        {
            cout<<parent->data<<" ";
            parent = bitree.parent(parent);
        }
        cout<<endl;
    }
}

int main()
{
    char preorder[] = "ABDGCEFH";                          //ͼ6.18��a����ʾ���������ȸ����к��и�����
    char inorder[] = "DGBAECHF";
    BinaryTree<char> bitree(preorder, inorder, 8);         //���ȸ����к��и����й��������

    cout<<bitree;                                          //����ȸ�����������У�������������
    bitree.inOrder();
    bitree.postOrder();
    cout<<"��������������"<<bitree.count()<<endl;
    cout<<"�������߶ȣ�"<<bitree.height()<<endl;
    cout<<"Ҷ�ӽ�㣨"<<bitree.countLeaf()<<"������";
    bitree.leaf();
    cout<<endl;

    printAncestors(bitree, 'H');                           //���bitree�������йؼ���Ϊkey�����������Ƚ��
    bitree.levelOrder();                                   //����α���������
    cout<<endl;

    char prelist2[] = {'A','B',NULL,NULL,'C'};
    BinaryTree<char> bitree2(prelist2, 5);
    find = bitree2.search('A');
    cout<<"����Z��Ϊ "<<find->data<<" ������\n";
    BinaryNode<char>*q=bitree2.insert(find, 'Z');
    cout<<bitree2;
    bitree2.inOrder();
    bitree2.postOrder();
    cout<<"��������������"<<bitree2.count()<<endl;
    cout<<"�������߶ȣ�"<<bitree2.height()<<endl;

    cout<<"ɾ��"<<find->data<<" ��������\n";
    bitree2.remove(find, false);
    cout<<bitree2;
    bitree2.inOrder();
    bitree2.postOrder();

    system("pause");
    return 0;
}

/*
�������н�����£�
�ȸ��������������:  A B D G C E F H 
�и��������������:  D G B A E C H F 
����������������:  G D B E H F C A 
��������������8
�������߶ȣ�4
H�����Ƚ����F C A 
��α�����  A B C D E F G H 

����Z��Ϊ A ������
�ȸ��������������:  A Z B C 
�и��������������:  B Z A C 
����������������:  B Z C A 
��������������4
�������߶ȣ�3
ɾ��A ��������
C �ȸ��������������:  A Z B 
�и��������������:  B Z A 
����������������:  B Z A 
����������: B Z A 
����������: G D B E H F C A 


*/
