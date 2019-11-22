//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.2.5   �������Ķ�������ʵ��
//��������

#include <iostream>
using namespace std;

#include "BinaryNode.h"                                    //�������Ķ�����������
#include "MyString.h"                                      //�ַ����ࣨ��3�£�
#include "SeqStack.h"                                      //˳��ջ����4�£�
//#include "LinkedStack.h"                                   //��ʽջ����4�£�
#include "SeqQueue.h"                                      //˳��ѭ�����У���4�£�
#include "LinkedQueue.h"                                   //��ʽ���У���4�£�

template <class T>
class BinaryTree                                           //��������
{
  public:
    BinaryNode<T> *root;                                   //ָ������

    BinaryTree();                                          //����ն����� 
    BinaryTree(T prelist[], int n);                        //�Ա������������ȸ����й���һ�ö�����
    BinaryTree(MyString genlist);                          //�Թ�����ʾ���������
    ~BinaryTree();                                         //��������

    bool empty();                                          //�ж��Ƿ�ն�����
    friend ostream& operator<<<>(ostream& out, BinaryTree<T>&); //����ȸ�����������У�������������
    void inOrder();                                        //����и������������
    void postOrder();                                      //�����������������

    BinaryNode<T>* insert(T x);                            //����Ԫ��x��Ϊ�����
    BinaryNode<T>* insert(BinaryNode<T> *p, T x, bool leftChild=true); //����x��Ϊp��������Һ���
    void remove(BinaryNode<T> *p, bool leftChild);         //ɾ��p�������������
    void remove();                                         //ɾ������㣬ɾ��������
    void printGenList();                                   //����������Ĺ�����ʾ
    void inOrderTraverse();                                //�и���������������ķǵݹ��㷨
    void levelOrder();                                     //����������Ĳ�α�������

  private:
    BinaryNode<T>* create(T prelist[], int n, int &i);     //�Ա������������ȸ��������д�������
    BinaryNode<T>* create(MyString &genlist, int &i);      //�Թ�����ʾ����һ������
    void preOrder(BinaryNode<T> *p);                       //�ȸ����������p���Ϊ��������
    void inOrder(BinaryNode<T> *p);                        //�и����������p���Ϊ��������
    void postOrder(BinaryNode<T> *p);                      //������������p���Ϊ��������
    void remove(BinaryNode<T> *p);                         //ɾ����p���Ϊ��������
    void printGenList(BinaryNode<T> *p);                   //�����p���Ϊ���������Ĺ�����ʾ
    //����ADT���̲ĵ�157ҳ


    //���µ�6��ʵ����6-1
  public:
    BinaryTree(T prelist[], T inlist[], int n);            //���ȸ����и����й��������

    int count();                                           //���ض������Ľ�����
    int height();                                          //���ض������ĸ߶�
    BinaryNode<T>* search(T key);                          //�����ȸ���������״γ��ֵĹؼ���Ϊkey��㣬T��������==����
    BinaryNode<T>* parent(BinaryNode<T> *node);            //����node���ĸ�ĸ���

    void leaf();                                           //�������Ҷ�ӽ��
    int leafCount();                                       //���ض�������Ҷ�ӽ����
    bool replace(T key, T x);                              //���״γ��ֵĹؼ���Ϊkey���ֵ�滻Ϊx
    void replaceAll(T key, T x);                           //�����йؼ���Ϊkey�Ľ��ȫ���滻Ϊx

    int operator==(BinaryTree<T> &bitree);                 //����==��������Ƚ����ö������Ƿ���ȣ�T��������==����
    BinaryTree(BinaryTree<T> &bitree);                     //�������캯�������
    BinaryTree<T>& operator=(BinaryTree<T> &bitree);       //����=��ֵ����������
    void preOrderTraverse();                               //�ȸ���������������ķǵݹ��㷨
    int getLevel(T x);                                     //����x������ڵĲ��
    bool isCompleteBinaryTree();                           //�ж��Ƿ���ȫ������
    //����
    void traverseGenList();                                //�Թ�����ʾ�����������ʹ��ջ�ķǵݹ�����㷨
    bool isSorted();                                       //�ж�һ�ö������Ƿ�Ϊ����������

  private:
    BinaryNode<T>* create(T prelist[], T inlist[], int preStart, int inStart, int n);  //���ȸ����и����д���һ������

    int count(BinaryNode<T> *p);                           //������p���Ϊ��������������
    int height(BinaryNode<T> *p);                          //������p���Ϊ���������߶�
    BinaryNode<T>* search(BinaryNode<T> *p, T key);        //����pΪ���������в����״γ��ֵ�ֵΪkey�Ľ��
    BinaryNode<T>* parent(BinaryNode<T> *p, BinaryNode<T> *node);

    void leaf(BinaryNode<T> *p);                           //�����p���Ϊ��������������Ҷ�ӽ��
    int leafCount(BinaryNode<T> *p);                       //������p���Ϊ����������Ҷ�ӽ�����
    void replaceAll(BinaryNode<T> *p, T key, T x);         //����pΪ����������ʵ��ȫ���滻
    bool equals(BinaryNode<T> *p, BinaryNode<T> *q);       //�ж���p��q���Ϊ�������������Ƿ����
    BinaryNode<T>* copy(BinaryNode<T> *p);                 //������p�����Ӷ�����
    int getLevel(BinaryNode<T> *p, int i, T x);            //����p��㣨���Ϊi��Ϊ������������x������ڵĲ��


    //��8��ϰ��
    bool isSorted(BinaryNode<T>* p);             //�ж�һ�ö������Ƿ�Ϊ����������

};

template <class T>
BinaryTree<T>::BinaryTree()                                //����ն�����
{
    this->root = NULL;
}

template <class T>
bool BinaryTree<T>::empty()                              //�ж��Ƿ�ն�����
{
    return this->root==NULL;
}

//3.  ���������ȸ����и��ͺ����������㷨
template <class T>
ostream& operator<<<>(ostream& out, BinaryTree<T> &btree)  //����ȸ�����������У�������������
{
    out<<"�ȸ��������������:  ";   
    btree.preOrder(btree.root);                            //�����ȸ���������������ĵݹ麯��
    out<<endl; 
    return out;
}
template <class T>
void BinaryTree<T>::preOrder(BinaryNode<T> *p)             //�ȸ����������p���Ϊ�����������ݹ麯��
{
    if (p==NULL)                                           //����������
        cout<<"��";                                        //����ս����
    else
    {
        cout<<p->data<<" ";                                //�����ǰ���Ԫ��
        preOrder(p->left);                                 //���ȸ��������p�����������ݹ����
        preOrder(p->right);                                //���ȸ��������p�����������ݹ����
    }
}

template <class T>
void BinaryTree<T>::inOrder()                              //�и��������������
{
    cout<<"�и��������������:  ";   
    this->inOrder(root);                                   //�����и���������������ĵݹ麯��
    cout<<endl;   
}
template <class T>
void BinaryTree<T>::inOrder(BinaryNode<T> *p)              //�и����������p���Ϊ�����������ݹ麯��
{
    if (p!=NULL)
    {
        inOrder(p->left);                                  //���и��������p�����������ݹ����
        cout<<p->data<<" ";
        inOrder(p->right);                                 //���и��������p�����������ݹ����
    }
}

template <class T>
void BinaryTree<T>::postOrder()                            //����������������
{
    cout<<"����������������:  ";   
    this->postOrder(root);                                 //���ú����������������ĵݹ麯��
    cout<<endl;   
}
template <class T>
void BinaryTree<T>::postOrder(BinaryNode<T> *p)            //������������p���Ϊ�����������ݹ麯��
{
    if (p!=NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<" ";
    }
}


//4. ������������
//����Ԫ��x��Ϊ����㣬ԭ�������Ϊ�����ӣ����ز������ַ��
template <class T>
BinaryNode<T>* BinaryTree<T>::insert(T x)
{
    return this->root = new BinaryNode<T>(x, this->root, NULL);
}
//    void insertRoot(T x);             	//����������ˣ���Ϊ���������������Ҫ��������insert()

//����x��Ϊparent������/�Һ��ӣ�ԭparent����/�Һ�����Ϊx������/�Һ��ӣ����ز������ַ��
//��parentΪ�գ��򲻲��룻leftChildָ������Һ��ӣ�ȡֵΪtrue�����ӣ�Ĭ�ϣ���false���Һ��ӣ�
template <class T>
BinaryNode<T>* BinaryTree<T>::insert(BinaryNode<T> *parent, T x, bool leftChild)
{
    if (parent==NULL)
        return NULL;
    if (leftChild)                                         //����x�����Ϊparent����/�Һ���
        return parent->left = new BinaryNode<T>(x, parent->left, NULL);
    return parent->right = new BinaryNode<T>(x, NULL, parent->right);
}    

//5. ɾ������
template <class T>
BinaryTree<T>::~BinaryTree()                               //��������
{
    cout<<"����������: ";
    this->remove(this->root);
    cout<<endl;
}
template <class T>
void BinaryTree<T>::remove()                               //ɾ������㣬ɾ��������
{
    this->remove(this->root);
}

//ɾ��parent�����������������leftChildΪtrue��ɾ��������������ɾ����������
template <class T>
void BinaryTree<T>::remove(BinaryNode<T> *parent, bool leftChild)
{
    if (parent!=NULL)
        if (leftChild)
        {
            remove(parent->left);                          //ɾ��������
            parent->left = NULL;
        }
        else
        {
            remove(parent->right);                         //ɾ��������
            parent->right = NULL;
        }
}

template <class T>
void BinaryTree<T>::remove(BinaryNode<T> *p)               //ɾ����p���Ϊ��������������������
{
    if (p!=NULL)
    {
        remove(p->left);
        remove(p->right);
        cout<<p->data<<" ";                                //��ʾɾ�����Ĵ���
        delete p;                                          //�ͷŽ��ռ�õĴ洢�ռ�
    }
}

//6. ���������

//�����������prelist����ָ���������������������ȸ��������У�nָ�����г���
template <class T>
BinaryTree<T>::BinaryTree(T prelist[], int n)
{
    int i=0;
    this->root = this->create(prelist, n, i);
}
//�Ա������������ȸ����У���i��ʼ������һ����prelist[i]Ϊ�������������ظ���㣬�ݹ��㷨
template <class T>
BinaryNode<T>* BinaryTree<T>::create(T prelist[], int n, int &i)  
{
    BinaryNode<T> *p=NULL;
    if (i<n)
    {
        T elem = prelist[i];
        i++;
        if (elem!=NULL)                                    //����elem!='^'����ΪT��һ����char
        {
            p = new BinaryNode<T>(elem);                   //�������
            p->left = create(prelist, n, i);               //�������������ݹ����
            p->right = create(prelist, n, i);              //�������������ݹ����
        }
    }
    return p;
}
//����6.1���������Ĺ��졢���������롣


//����6.2�� �������Ĺ�����ʾ��

template <class T>
void BinaryTree<T>::printGenList()                         //����������Ĺ�����ʾ�ַ���
{
    this->printGenList(root);
    cout<<endl;
}
//�����p���Ϊ����һ�������Ĺ�����ʾ�ַ������ȸ�����������ݹ��㷨
template <class T>
void BinaryTree<T>::printGenList(BinaryNode<T> *p)
{
    if (p==NULL)
        cout<<"��";                                        //�����������ʾ
    else
    {
        cout<<p->data;
        if (p->left!=NULL || p->right!=NULL)               //��Ҷ�ӽ��
        {
            cout<<"(";
            printGenList(p->left);                         //������������ݹ����
            cout<<",";
            printGenList(p->right);                        //������������ݹ����
            cout<<")";
        }
    }
}

//�Թ�����ʾ�����������genlistָ��������������ʾ�ַ���
//T������MyString���͵Ĺ��캯��
template <class T>
BinaryTree<T>::BinaryTree(MyString genlist)
{
    int i=0;
    this->root = this->create(genlist, i);
}

//�Թ�����ʾ�ַ�������i��ʼ������һ����genlist[i]Ϊ�������������ظ���㣬�ݹ��㷨
template <class T>
BinaryNode<T>* BinaryTree<T>::create(MyString &genlist, int &i)  
{
    if (genlist[i]=='^')                                   //����'^'
    {
        i++;
        return NULL;
    }
    int n=0;
    char ch;
    while (i<genlist.count() && (ch=genlist[i+n]) && ch!='(' && ch!=',' && ch!=')')
        n++;
    MyString str=genlist.substring(i,n);                   //��ô�i��ʼ����Ϊn���Ӵ�
    i+=n;
    BinaryNode<T> *p = new BinaryNode<T>(str);             //����Ҷ�ӽ��
    if (genlist[i]=='(')
    {
        i++;                                               //����'('
        p->left = create(genlist, i);                      //����������
        i++;                                               //����','
        p->right = create(genlist, i);                     //����������
        i++;                                               //����')'
    }
    return p;
}

//7.  �����������ķǵݹ��㷨
template <class T>
void BinaryTree<T>::preOrderTraverse()                     //�ȸ���������������ķǵݹ��㷨
{
    cout<<"�ȸ�����������ǵݹ飩��  ";
    SeqStack<BinaryNode<T>*> stack;                        //������ջ��Ԫ��Ϊ����ַ
    BinaryNode<T> *p = this->root;
    while (p!=NULL || !stack.empty())                    //p�ǿջ�ջ�ǿ�ʱ
        if (p!=NULL)
        {
            cout<<p->data<<" ";                            //���ʽ��
            stack.push(p);                                 //p����ַ��ջ
            p = p->left;                                   //����������
        }
        else                                               //pΪ����ջ�ǿ�ʱ
        {
            p = stack.pop();                               //pָ���ջ���
            p = p->right;                                  //����������
        }
    cout<<endl;
}    

template <class T>
void BinaryTree<T>::inOrderTraverse()                      //�и���������������ķǵݹ��㷨
{
    cout<<"�и�����������ǵݹ飩��  ";
    SeqStack<BinaryNode<T>*> stack;                        //������ջ��Ԫ��Ϊ����ַ
//    LinkedStack<BinaryNode<T>*> stack;                     //����һ����ջ
    BinaryNode<T> *p = this->root;
    while (p!=NULL || !stack.empty())                    //p�ǿջ�ջ�ǿ�ʱ
        if (p!=NULL)
        {
            stack.push(p);                                 //p�����ջ
            p = p->left;                                   //����������
        }
        else                                               //pΪ����ջ�ǿ�ʱ
        {
            p = stack.pop();                               //pָ���ջ���
            cout<<p->data<<" ";                            //���ʽ��
            p = p->right;                                  //����������
        }
    cout<<endl;
}    

//8.   �������Ĳ�α���
template <class T>
void BinaryTree<T>::levelOrder()                           //����α���������
{ 
    cout<<"��α�����  ";
//    SeqQueue<BinaryNode<T>*> que;                //����һ���ն���
    LinkedQueue<BinaryNode<T>*> que;                       //����һ���ն���
    BinaryNode<T> *p = this->root;                         //�����û�����
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        if (p->left!=NULL)    
            que.enqueue(p->left);                          //p�����ӽ�����
        if (p->right!=NULL)
            que.enqueue(p->right);                         //p���Һ��ӽ�����
        p = que.empty() ? NULL : que.dequeue();            //pָ����ӽ���NULL
    }
    cout<<endl;
}

//����ʵ��6-1
#include "BinaryTree.h"                                    //��������

//�����������prelist��inlist����ֱ�ָ���ȸ����и��������У�nָ�����г���
template <class T>
BinaryTree<T>::BinaryTree(T prelist[], T inlist[], int n)
{
    this->root = this->create(prelist, inlist, 0, 0, n);
}
//���ȸ����и����й����Ӷ��������ȸ������д�prelist�����preStart��ʼ�������������
//prelist[preStart]���и������д�inlist�����inStart��ʼ��nָ�������г��ȣ����ظ�����ַ
template <class T>
BinaryNode<T>* BinaryTree<T>::create(T prelist[],  T inlist[], int preStart,int inStart, int n)
{
    BinaryNode<T> *p=NULL;
    if (n>0)
    {
        T elem=prelist[preStart];                          //�����ֵ
        p = new BinaryNode<T>(elem);                       //�������
        int i=0;
        while (i<n && elem!=inlist[inStart+i])             //���и������в��Ҹ�ֵ����λ��
            i++;
        p->left = create(prelist, inlist, preStart+1, inStart, i);           //����������
        p->right = create(prelist, inlist, preStart+i+1, inStart+i+1, n-1-i);//����������
    }
    return p;
}

//���ڱ����Ĳ���
template <class T>
int BinaryTree<T>::count()                                 //���ض������Ľ�����
{
    return this->count(this->root);
}

template <class T>
int BinaryTree<T>::count(BinaryNode<T> *p)                 //������p���Ϊ��������������
{
    if (p==NULL)
        return 0;
    return 1+count(p->left)+count(p->right);
}

template <class T>
int BinaryTree<T>::height()                                //���ض������ĸ߶�
{
   return this->height(root);
}

template <class T>
int BinaryTree<T>::height(BinaryNode<T> *p)                //������p���Ϊ���������߶ȣ�����������
{
   if (p==NULL)
       return 0;
   int lh = height(p->left);                               //�����������ĸ߶�
   int rh = height(p->right);                              //�����������ĸ߶�
   return (lh>=rh) ? lh+1 : rh+1;                          //�������������߶Ƚϴ�ֵ��1
}

template <class T>
BinaryNode<T>* BinaryTree<T>::search(T key)                //�����״γ��ֵĹؼ���Ϊkey���
{
    return this->search(this->root, key);
}

//����p���Ϊ���������в����״γ��ֵĹؼ���Ϊkey��㣬���ؽ���ַ����δ�ҵ�����NULL
//T��������==���ȸ���������㷨
template <class T>
BinaryNode<T>* BinaryTree<T>::search(BinaryNode<T> *p, T key)
{
    BinaryNode<T> *find=NULL;                    //���ز��ҽ��
    if (p!=NULL)
    {
        if (p->data==key)                        //T��������==
            return p;                            //���ҳɹ������ؽ���ַ
        find = search(p->left, key);             //���������в��ң�findָ���ҵ���㣬�ݹ����
        if (find==NULL)                          //������������δ�ҵ�
            find = search(p->right, key);        //��������������в��ң��ݹ����
    }
    return find;                                 //���ز��ҽ��
}

//����node���ĸ�ĸ����ַ����������δ�ҵ���nodeΪ��������NULL
template <class T>
BinaryNode<T>* BinaryTree<T>::parent(BinaryNode<T> *node)
{
    if (root==NULL || node==NULL || node==root)
        return NULL; 
    return parent(root, node);
}
//����pΪ���������в��Ҳ�����node���ĸ�ĸ����ַ
template <class T>
BinaryNode<T>* BinaryTree<T>::parent(BinaryNode<T> *p, BinaryNode<T> *node)
{
    BinaryNode<T> *find=NULL;
    if (p!=NULL)
    {
        if (p->left==node || p->right==node) 
            return p;
        find = parent(p->left, node);
        if (find==NULL)
            find = parent(p->right, node);
    }
    return find;
}

template <class T>
void BinaryTree<T>::leaf()                                 //�������Ҷ�ӽ��
{
    leaf(root);
}

//�����p���Ϊ��������������Ҷ�ӽ�㡣�ȸ���������㷨���и��������������㷨Ҳ�ɣ����һ��
template <class T>
void BinaryTree<T>::leaf(BinaryNode<T> *p)
{
    if (p!=NULL)
    {
        if (p->left==NULL && p->right==NULL)
            cout<<p->data<<" ";
        leaf(p->left);
        leaf(p->right);
    }
}

template <class T>
int BinaryTree<T>::countLeaf()                             //���ض�������Ҷ�ӽ����
{
    return countLeaf(root);
}

template <class T>
int BinaryTree<T>::countLeaf(BinaryNode<T> *p)             //������p���Ϊ����������Ҷ�ӽ�����
{
    if (p==NULL)
        return 0;
    if (p->left==NULL && p->right==NULL)
        return 1;
    return countLeaf(p->left)+countLeaf(p->right);
}

template <class T>
bool BinaryTree<T>::replace(T key, T x)                    //���״γ��ֵĹؼ���Ϊkey���ֵ�滻Ϊx
{
    BinaryNode<T> *find = search(key);                     //���ҹؼ���Ϊkey�Ľ��
    if (find!=NULL)
        find->data = x;                                    //�滻���Ԫ��ֵ
    return find!=NULL;    
}

template <class T>
void BinaryTree<T>::replaceAll(T key, T x)                 //�����йؼ���Ϊkey�Ľ��ȫ���滻Ϊx
{
    replaceAll(root, key, x);
}

template <class T>
void BinaryTree<T>::replaceAll(BinaryNode<T> *p, T key, T x)//����pΪ����������ʵ��ȫ���滻
{
    if (p!=NULL)
    {
        if(p->data==key) 
            p->data = x;                   	               //�滻
        replaceAll(p->left, key, x);
        replaceAll(p->right, key, x);
    }
}
template <class T>
int BinaryTree<T>::getLevel(T x)                           //����x������ڵĲ�Σ���������δ���ҵ�x����-1
{ 
    if (root==NULL)
        return -1;
    return getLevel(root, 1, x);                           //������Ĳ��Ϊ1
}

template <class T>
int BinaryTree<T>::getLevel(BinaryNode<T> *p, int i, T x)  //����p��㣨���Ϊi��Ϊ������������x������ڵĲ��
{
    if (p!=NULL)
    {
        if (p->data==x) 
            return i;                                      //���ҳɹ�
        int level = getLevel(p->left, i+1, x);             //������������
        if (level!=-1)
            return level;
        return getLevel(p->right, i+1, x);                 //�������������в���
    }
    return -1;                                             //���Ҳ��ɹ�
}

//���ö������Ĳ���
template <class T>
int BinaryTree<T>::operator==(BinaryTree<T> &bitree)       //�Ƚ����ö������Ƿ���ȣ����������==
{
    return equals(this->root, bitree.root);
}

template <class T>
bool BinaryTree<T>::equals(BinaryNode<T> *p, BinaryNode<T> *q)  //�ж���p��q���Ϊ�������������Ƿ����
{
    return p==NULL && q==NULL || p!=NULL && q!=NULL && p->data==q->data && 
           equals(p->left, q->left) && equals(p->right, q->right);//�ݹ麯��
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &bitree)           //���������֪bitree���������
{
    this->root = copy(bitree.root);
}

template <class T>
BinaryNode<T>* BinaryTree<T>::copy(BinaryNode<T> *p)       //������p�����Ӷ������������½��Ӷ������ĸ����
{
    BinaryNode<T> *q=NULL;
    if (p!=NULL)                                           //�ǿ�ʱ�������
    {
        q = new BinaryNode<T>(p->data);
        q->left = copy(p->left);                           //�������������ݹ����
        q->right = copy(p->right);                         //�������������ݹ����
    }
    return q;                                              //���ؽ��������ĸ����
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> &bitree)   //��ֵ����������������=
{
    destroy(this->root);
    this->root = copy(bitree.root);
    return *this;
}



//�������δд

template <class T>
bool BinaryTree<T>::isCompleteBinaryTree()                 //�ж�һ�ö������Ƿ�����ȫ������
{
    if (this->root==NULL)                                  //��������ȫ������
        return true;
    SeqQueue<BinaryNode<T>*> que;                          //����һ���ն���
//    LinkedQueue<BinaryNode<T>*> que;
    BinaryNode<T> *p=this->root;
    cout<<"��α�����";
    while (p->left!=NULL)                //2�Ƚ����������ӽ����ӣ�Ѱ�ҵ�һ����2�Ƚ��
    {
        cout<<p->data<<" ";
        que.enqueue(p->left);     
        if (p->right!=NULL)
            que.enqueue(p->right);
        p = que.dequeue();
    }
//    cout<<"��1�Ȼ�Ҷ�ӽ�㣺"<<p->data<<"��";              //ѭ��ֹͣʱ��p->left==NULL && p��1�Ȼ�Ҷ�ӽ��
    if (p->right!=NULL)                   //p���������ն����������գ�ȷ������
        return false;
    cout<<"���У�";
    while (!que.isEmpty())                                 //���������Ƿ���Ҷ�ӽ��
    {
        cout<<p->data<<" ";
        if (p->left!=NULL || p->right!=NULL)               //���ַ�Ҷ�ӣ�ȷ������
            return false;
        p = que.dequeue();
    }
    return true;
}


