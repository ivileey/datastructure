//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//��ʵ��6-3�����������ʾ����ȫ�������ࡣ

#include "BinaryTree.h"                                    //��������

template <class T>
class CompleteBinaryTree : public BinaryTree <T>           //���������ʾ����ȫ�������࣬�̳ж�������
{
  private:
    BinaryNode<T>* create(T levellist[], int n, int i);    //������levellist[i]Ϊ����һ������

  public:
    CompleteBinaryTree(T levellist[], int n);              //�Բ�����й�����ȫ������


};
 
//����ȫ�������Ĳ�����й�����ȫ��������levellistָ���������
template <class T>
CompleteBinaryTree<T>::CompleteBinaryTree(T levellist[], int n)
{
    this->root = create(levellist, n, 0);                  //������levellist[0]Ϊ����һ�ö�����
}

//������levellist[i]Ϊ����һ������
template <class T>
BinaryNode<T>* CompleteBinaryTree<T>::create(T levellist[], int n, int i)
{
    BinaryNode<T> *p = NULL;
    if (i<n)
    {
        p = new BinaryNode<T>(levellist[i]);
        p->left = create(levellist, n, 2*i+1);
        p->right = create(levellist, n, 2*i+2);
    }
    return p;
}
