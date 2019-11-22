//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.3   ����������
//6.3.2   ��������������

#include <iostream>
using namespace std;
#include "ThreadNode.h"                                    //�����������Ķ�����������

template <class T>
class ThreadBinaryTree                                     //���������������࣬Tָ������Ԫ������
{
  public:
    ThreadNode<T> *root;                                   //ָ������

    ThreadBinaryTree();                                    //��������������� 
    ThreadBinaryTree(T prelist[], int n);                  //�Ա������������ȸ����й���һ����������������
    ~ThreadBinaryTree();                                   //��������

    bool empty();                                        //�ж��Ƿ�ն�����
    void inOrder();                                        //�и����������������������
//    friend ostream& operator<<<>(ostream& out, ThreadBinaryTree<T>&); //����ȸ�����������У�������������
    void preOrder();                                       //�ȸ����������������������
    void inOrderPrevious();                                //�и��������������
    void postOrderPrevious();                              //����������������

    ThreadNode<T>* parent(ThreadNode<T> *node);            //����node���ĸ�ĸ���
    void insert(T x);                                      //�����
    ThreadNode<T>* insert(ThreadNode<T> *parent, T x, bool leftChild=true); //���뺢�ӣ�Ĭ�ϲ�������
    void remove();                                         //ɾ����
    void remove(ThreadNode<T> *parent, bool leftChild);    //ɾ��parent��������Һ��ӽ��

  private:
    ThreadNode<T>* create(T prelist[], int n, int &i);     //�Ա������������ȸ�����������д���һ������
    void inThread(ThreadNode<T> *p, ThreadNode<T> *&front);  //������������p���Ϊ��������
    ThreadNode<T>* inNext(ThreadNode<T> *p);               //����p���и������µĺ�̽��
    ThreadNode<T>* preNext(ThreadNode<T> *p);              //����p���ȸ������µĺ�̽��
    ThreadNode<T>* inPrev(ThreadNode<T> *p);               //����p���и������µ�ǰ�����
    ThreadNode<T>* postPrev(ThreadNode<T> *p);             //����p�ں�������µ�ǰ�����
    void remove(ThreadNode<T> *p);                         //ɾ����p���Ϊ��������

    ThreadBinaryTree(T prelist[], T inlist[], int n);      //���ȸ����и����й�����������������
    ThreadNode<T>* create(T prelist[],  T inlist[], int preStart,int inStart, int n);//���ȸ����и����д���һ�������������������prelist[i]�����ظ����ָ��
    void removeRight(ThreadNode<T> *parent);               //ɾ��parent�����Һ��ӽ��
    void removeLeft(ThreadNode<T> *parent);                //ɾ��ָ�����parent�����ӽ��
};

template <class T>
ThreadBinaryTree<T>::ThreadBinaryTree()                    //���������������
{
    this->root = NULL;
}

template <class T>
bool ThreadBinaryTree<T>::empty()                        //�ж��Ƿ�ն�����
{
    return root==NULL;
}

template <class T>
ThreadBinaryTree<T>::ThreadBinaryTree(T prelist[], int n)//�Ա������������ȸ����й���һ����������������
{
    int i=0;
    this->root=create(prelist, n, i);
    ThreadNode<T>* front=NULL;
    inThread(this->root, front);                           //����������������
}

template <class T>
ThreadNode<T>* ThreadBinaryTree<T>::create(T prelist[], int n, int &i)//�Ա������������ȸ����д���һ���������㷨ͬBinaryTree
{
    ThreadNode<T> *p=NULL;
    if (i<n)
    {
        T elem = prelist[i];
        i++;
        if (elem!=NULL)
        {
            p = new ThreadNode<T>(elem);
            p->left = create(prelist, n, i);
            p->right = create(prelist, n, i);
        }
    }
    return p;
}

//2.  ������������������
//������������p���Ϊ����������frontָ��p��ǰ����� 
template <class T>
void ThreadBinaryTree<T>::inThread(ThreadNode<T>* p, ThreadNode<T>* &front)
{
    if (p!=NULL)
    {
        inThread(p->left, front);                          //����������p��������

        if (p->left==NULL)                                 //��p��������Ϊ��
        {
            p->ltag=1;                                     //�������������
            p->left = front;                               //����p��leftΪָ��ǰ��front������
        }
        if (p->right==NULL)                                //��p��������Ϊ��
            p->rtag=1;                                     //�������������
        if (front!=NULL && front->rtag) 
            front->right=p;                                //����ǰ��front��rightΪָ����p������
               
        front=p;
        inThread(p->right, front);                         //����������p��������
    }
}

//3.  �и����������������������
template <class T>
ThreadNode<T>* ThreadBinaryTree<T>::inNext(ThreadNode<T> *p) //����p���и������µĺ�̽��
{                                     
    if (p->rtag==1)                                        //��������Ϊ��
        p=p->right;                                        //��p->right��ָ��p��̽�������
    else
    {
        p=p->right;                                        //����������
        while (p->ltag==0)                                 //Ѱ������ߵĺ�����
            p=p->left;
    }
    return p;
}

template <class T>
void ThreadBinaryTree<T>::inOrder()                        //�и�������������������������ǵݹ��㷨
{
    cout<<"�и����������������������:  ";   
    ThreadNode<T> *p=this->root;
    while (p!=NULL && p->ltag==0)                          //Ѱ�Ҹ�������ߵĺ����㣬����һ�����ʽ��
        p=p->left;  
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=inNext(p);                                       //����p���и������µĺ�̽��
    }
    cout<<endl;
}    

//4.  �ȸ����������������������
template <class T>
ThreadNode<T>* ThreadBinaryTree<T>::preNext(ThreadNode<T> *p) //����p���ȸ������µĺ�̽��
{
    if (p->ltag==0)                                        //���������ǿ�
        p=p->left;                                         //������p�ĺ�̽��
    else                                                   //���򣬺�������ֵܻ�ĳ���������ȵ��Һ���
    {
        while (p->rtag==1 && p->right!=NULL)               //�������������ϣ�Ѱ��ĳ����������
            p=p->right; 
        p=p->right;                                        //�������ĳ���������ȵ��Һ���
    }
    return p;
}

template <class T>
void ThreadBinaryTree<T>::preOrder()             //�ȸ�������������������������ǵݹ��㷨
{
    cout<<"�ȸ����������������������:  ";   
    ThreadNode<T> *p=this->root;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=preNext(p);                            //����p���ȸ������µĺ�̽��
    }
    cout<<endl;
}

//��6��ϰ��
//���ȸ����и����й�������������������nָ�����г���
template <class T>
ThreadBinaryTree<T>::ThreadBinaryTree(T prelist[], T inlist[], int n)
{                                                
    root = create(prelist, inlist, 0, 0, n);
    ThreadNode<T>* front=NULL;
    inThread(root, front);                                 //����������������
}
    //���ȸ����и����д���һ�������������������prelist[i]�����ظ����ָ��
template <class T>
ThreadNode<T>* ThreadBinaryTree<T>::create(T prelist[],  T inlist[], int preStart,int inStart, int n)
{
    ThreadNode<T> *p=NULL;
    if (n>0)
    {
        T elem=prelist[preStart];                          //�����ֵ
        p = new ThreadNode<T>(elem);                       //�������
        int i=0;
        while (i<n && elem!=inlist[inStart+i])             //���и������в��Ҹ�ֵ����λ��
            i++;
        p->left = create(prelist, inlist, preStart+1, inStart, i);           //����������
        p->right = create(prelist, inlist, preStart+i+1, inStart+i+1, n-1-i);//����������
    }
    return p;
}

//��˼����6-4�� ��p������и������µ�ǰ����㣬���и������������������������
    //����p���и������µ�ǰ�����
template <class T>
ThreadNode<T>* ThreadBinaryTree<T>::inPrev(ThreadNode<T> *p)
{
    if (p->ltag==1)
        p=p->left;                                         //��������Ϊ�գ�p->left����ָ��pǰ����������
    else                                                   //���������ǿ�
    {
        p=p->left;                                         //����������
        while (p->rtag==0)                                 //�ҵ����ұߵĺ�����
            p=p->right;
    }
    return p;
}

template <class T>
void ThreadBinaryTree<T>::inOrderPrevious()                //�и����򣨷��򣩱��������������������ǵݹ��㷨
{
    cout<<"�и����������������������������:  ";   
    ThreadNode<T> *p=this->root;
    while (p!=NULL && p->rtag==0)                          //Ѱ�Ҹ������ұߵĺ�����
        p=p->right;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=inPrev(p);                                       //����p���и������µ�ǰ�����
    }
    cout<<endl;
}    

//��˼����6-5����p����ں�������µ�ǰ����㣬����������������������������
template <class T>
ThreadNode<T>* ThreadBinaryTree<T>::postPrev(ThreadNode<T> *p)   //����p�ں�������µ�ǰ�����
{
    if (p->rtag==0)
        p=p->right;                                        //�Һ�����p��ǰ�����
    else                                                   //����ǰ����ĳ���������ȵ�����
    {
        while (p->ltag==1 && p->left!=NULL)                //Ѱ��ĳ����������
            p=p->left;
        p=p->left;                                         //������ǰ�����
    }
    return p;
}

template <class T>
void ThreadBinaryTree<T>::postOrderPrevious()              //������򣨷��򣩱��������������������ǵݹ��㷨
{
    cout<<"������������������������������:  ";   
    ThreadNode<T> *p=this->root;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=postPrev(p);                                     //����p�ں�������µ�ǰ�����
    }
    cout<<endl;
}
    
//5.  ��������
template <class T>
ThreadBinaryTree<T>::~ThreadBinaryTree()                   //��������
{
    cout<<"������������������: ";
    remove(this->root);
    cout<<endl;
}

//������p���Ϊ���������������������ĵݹ��㷨
template <class T>
void ThreadBinaryTree<T>::remove(ThreadNode<T> *p)
{
    if (p!=NULL)
    {
        if (p->ltag==0)
            remove(p->left);
        if (p->rtag==0)
            remove(p->right);
        cout<<p->data<<" ";                                //��ʾ�������Ĵ���
        delete p;
    }
}

//ʵ��6
//6. ��ĸ���

//7. ������
template <class T>
void ThreadBinaryTree<T>::insert(T x)                      //������Ϊ�����
{
    if (root==NULL)
        root=new ThreadNode<T>(x,NULL,NULL,1,1);
    else
    {
        ThreadNode<T> *p=root;
        while (p!=NULL && p->rtag==0)                      //Ѱ��ԭ�������ұ�������p���������ʽ��
            p=p->right;
        root=new ThreadNode<T>(x,root,NULL,0,1);
        p->right=root;                                     //�޸�p�ĺ������
    }
}

    //����x��Ϊparent���ĺ��ӽ�㣬��leftChildΪtrue��Ĭ�ϣ����������ӣ���������Һ��ӣ����ز���ĺ��ӽ��
template <class T>
ThreadNode<T>* ThreadBinaryTree<T>::insert(ThreadNode<T> *parent, T x, bool leftChild)
{
    ThreadNode<T> *q=NULL;
    if (leftChild)                                          //��������
    {
        q=new ThreadNode<T>(x, p->left, p, p->ltag, 1);
        p->left=q;
        p->ltag = 0;
        if (q->ltag==0)
        {
            ThreadNode<T> *prev=inPrev(q);                 //prev��q���и������µ�ǰ��
            prev->right=q;                                 //�޸�ǰ�����prev�ĺ������
        }
    }
    else                                                   //�����Һ���
    {
        q=new ThreadNode<T>(value, p, p->right,1, p->rtag);
        p->right=q;
        p->rtag=0;
        if (q->rtag==0)
        {
            ThreadNode<T> *succ=inNext(q);                 //succ��q���и������µĺ��
            succ->left=q;                                  //�޸ĺ�̽��succ��ǰ������
        }
    }
    return q;
}

//8.ɾ�����
    //ɾ��ָ�����parent��������Һ��ӽ�㣬��leftChildΪtrue��ɾ�����ӣ�����ɾ���Һ���
    //�㷨���Ҹ���4�����
template <class T>
void ThreadBinaryTree<T>::remove(ThreadNode<T> *parent, bool leftChild)
{
    if (root==NULL || parent==NULL || leftChild && parent->ltag==1 || !leftChild && parent->rtag==1)
        return;
    ThreadNode<T> *q=NULL;
    if (leftChild && parent->ltag==0)                      //ɾ��p�ķǿ����ӽ��
    {
        q=parent->left;                                    //q�Ǵ�ɾ�����
        if (q->ltag==1 && q->rtag==1)                      //q��Ҷ�ӽ��
        {
            parent->left = q->left;
            parent->ltag=1;
        }
        else if (q->ltag==0 && q->rtag==1)                 //q��1�Ƚ�㣬ֻ������
        {
            parent->left = q->left;                        //��q�����Ӷ���q��p->rtagδ��
            inPrev(q)->right=q->right;                     //�޸�qǰ�����inPrev(q)�ĺ������
        }
        else if (q->ltag==1 && q->rtag==0)                 //q��1�Ƚ�㣬ֻ���Һ���
        {
            parent->left = q->right;                       //��q���Һ��Ӷ���q��p->rtagδ��
            inNext(q)->left=q->left;                       //�޸�q��̽��inNext(q)��ǰ������
        }
        else if (q->ltag==0 && q->rtag==0)                 //q��2�Ƚ�㣬������Ҳ���Һ���
        {
            parent->left = q->left;                        //��q�����Ӷ���q��p->rtagδ��
            ThreadNode<T> *prev=inPrev(q);                 //prev��q���и������µ�ǰ��
            prev->right=q->right;                          //�޸�qǰ�����prev�ĺ������
            prev->rtag=0;
            inNext(q)->left=prev;                          //�޸�q��̽��inNext(q)��ǰ������
        }
    }
    else if (!leftChild && p->rtag==0)                     //ɾ��p�ķǿ��Һ��ӽ��q
    {
        q=parent->right;                                   //q�Ǵ�ɾ�����
        if (q->ltag==1 && q->rtag==1)                      //q��Ҷ�ӽ��
        {
            parent->right = q->right;
            parent->rtag=1;
        }
        else if (q->ltag==0 && q->rtag==1)                 //q��1�Ƚ�㣬ֻ������
        {
            parent->right = q->left;                       //��q�����Ӷ���q��p->rtagδ��
            inPrev(q)->right=q->right;                     //�޸�qǰ�����inPrev(q)�ĺ������
        }
        else if (q->ltag==1 && q->rtag==0)                 //q��1�Ƚ�㣬ֻ���Һ���
        {
            parent->right = q->right;                      //��q���Һ��Ӷ���q��p->rtagδ��
            inNext(q)->left=p;                             //�޸�q��̽��inNext(q)��ǰ������
        }
        else if (q->ltag==0 && q->rtag==0)                 //q��2�Ƚ�㣬������Ҳ���Һ���
        {
            parent->right = q->left;                       //��q�����Ӷ���q��p->rtagδ��
            ThreadNode<T> *prev=inPrev(q);                 //prev��q���и������µ�ǰ��
            prev->right=q->right;                          //�޸�qǰ�����prev�ĺ������
            prev->rtag=0;
            inNext(q)->left=prev;                          //�޸�q��̽��inNext(q)��ǰ������
        }
    }
    delete q;
}

    //ɾ��ָ�����parent���Һ��ӽ�㣬�ϲ�4�������Ҷ�㷨
template <class T>
void ThreadBinaryTree<T>::removeRight(ThreadNode<T> *parent)
{
    if (root==NULL || parent==NULL || parent->rtag==1)     //��parent���Һ��ӣ���ɾ��
        return;
    ThreadNode<T> *q=p->right;                             //qΪ��ɾ�����
    if (q->ltag==0)                                        //q������
    {
        parent->right = q->left;                           //��q�����Ӷ���q��p->rtagδ��
        ThreadNode<T> *prev=inPrev(q);                     //prevָ��q���и������µ�ǰ��
        prev->right=q->right;                              //�޸�ǰ�����prev�ĺ������
        prev->rtag=q->rtag;
        if (q->rtag==0)                                    //qҲ���Һ��ӣ�q��2�Ƚ��
            inNext(q)->left=prev;                          //�޸�q��̽��inNext(q)��ǰ������
    }
    else                                                   //q����ֻ���Һ��ӵ�1�Ƚ�㣬����Ҷ�ӽ��
    {
        parent->right = q->right;                          //��q���Һ��ӣ���������������q
        parent->rtag = q->rtag;
        if (q->rtag==0)                                    //q���Һ���û������
            inNext(q)->left=parent;                        //�޸�q��̽��inNext(q)��ǰ������
    }
    delete q;
}

    //ɾ��ָ�����p�����ӽ��
template <class T>
void ThreadBinaryTree<T>::removeLeft(ThreadNode<T> *parent)
{
    if (root==NULL || parent==NULL || p->ltag==1)          //��p�����ӣ���ɾ��
        return;
    ThreadNode<T> *q=parent->left;                         //qΪ��ɾ�����
    if (q->ltag==0)                                        //q������
    {
        parent->left = q->left;                            //��q�����Ӷ���q��parent->rtagδ��
        ThreadNode<T> *prev=inPrev(q);                     //prevָ��q���и������µ�ǰ��
        prev->right=q->right;                              //�޸�ǰ�����prev�ĺ������
        prev->rtag=q->rtag;
        if (q->rtag==0)                                    //qҲ���Һ��ӣ�q��2�Ƚ��
            inNext(q)->left=prev;                          //�޸�q��̽��inNext(q)��ǰ������
    }
    else                                                   //q����ֻ���Һ��ӵ�1�Ƚ�㣬����Ҷ�ӽ��
    {
        if (q->rtag==1)                                    //q��Ҷ�ӽ��
        {
            parent->left = q->left;                        //��q��ǰ����������q
            parent->ltag = 1;
        }
        else                                               //q��ֻ���Һ��ӵ�1�Ƚ��
        {
            parent->left = q->right;                       //��q���Һ��Ӷ���q
            inNext(q)->left=q->left;                       //�޸�q��̽��inNext(q)��ǰ������
        }
    }
    delete q;
}

