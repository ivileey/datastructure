//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.5.3   ���ĸ�ĸ�����ֵ�����ʵ��
//��ĸ�����ֵ�����洢������

#include <iostream>
using namespace std;
#include "TreeNode.h"                                      //���ĺ����ֵ���������
#include "MyString.h"                                      //�ַ����ࣨ��������3�£�

//ADT??
//��ɾ����
template <class T>
class Tree                                                 //��ĸ�����ֵ�����洢�����࣬Tָ������Ԫ������
{
  public:
    TreeNode<T> *root;                                     //ָ������

    Tree();                                                //Ĭ�Ϲ������ 
    Tree(MyString prelist[], int n);                       //�Ժ������ʾ��������T������MyString���͵Ĺ��캯��
    ~Tree();                                               //Ĭ����������
    friend ostream& operator<<<>(ostream& out, Tree<T>&);  //������ĺ������ʾ�ַ������ȸ����������
    void postOrder();                                      //������ĺ�������������

    //ϰ��6
    bool empty();                                          //�ж��Ƿ����
    int count();                                           //�������Ľ�����
    int height();                                          //�������ĸ߶�
    int childCount(TreeNode<T> *p);                        //����p���ĺ��ӽ����
    TreeNode<T>* getChild(TreeNode<T> *p, int i);          //����p���ĵ�i������
    TreeNode<T>* getLastChild(TreeNode<T> *p);             //����p�������һ������
    TreeNode<T>* getLastSibling(TreeNode<T> *p);           //����p�������һ���ֵ�
    TreeNode<T>* search(T key);                            //�����״γ��ֵĹؼ���Ϊkey���

    TreeNode<T>* insertRoot(T x);                          //�����
    TreeNode<T>* insertChild(TreeNode<T> *p, T x, int i);  //����xԪ����Ϊp���ĵ�i�����ӽ�㣬���ز�����
    TreeNode<T>* insertSibling(TreeNode<T> *p, T x, int i);//����xԪ����Ϊp���ĵ�i���ֵܽ�㣬���ز�����
    TreeNode<T>* insertLastSibling(TreeNode<T> *p, T x);   //����x��Ϊp�������һ���ֵܽ��
    TreeNode<T>* insertLastChild(TreeNode<T> *p, T x);     //����x��Ϊp�������һ������

    Tree(Tree<T> &Tree);                                   //�������캯�������
    Tree<T>& operator=(Tree<T> &Tree);                     //����=��ֵ������������
    TreeNode<T>* insertChild(TreeNode<T> *p, Tree<T> &subtree, int i);//����subtree������������Ϊp�ĵ�i����0��������
    void printGenList();                                   //�������ɭ�֣��Ĺ�����ʾ
    Tree(MyString genlist);                                //�Թ�����ʾ��������T������MyString��Ĺ��캯��

  private:
    void preOrder(TreeNode<T> *p, int i);                  //�ȸ����������p���Ϊ��������
    void postOrder(TreeNode<T> *p);                        //������������p���Ϊ��������
    void remove(TreeNode<T> *p);                           //ɾ����p���Ϊ��������

    //ϰ��6
    int count(TreeNode<T> *p);                          //������p���Ϊ��������������
    int height(TreeNode<T> *p);                            //������p���Ϊ���������߶ȣ�����������
    TreeNode<T>* search(TreeNode<T> *p, T key);
    void printGenList(TreeNode<T> *p);                     //�����pΪ���������Ĺ�����ʾ
    TreeNode<T>* copy(TreeNode<T> *p);                     //������p��������

//    TreeNode<T>* insertSibling(TreeNode<T> *p, T x, int i);   //����value��Ϊp������һ���ֵܽ��
//bool isChild(TreeNode<T> *p, TreeNode<T> *node)   	//�ж�node�Ƿ���p�ĺ��ӽ��
//    void removeChild(TreeNode<T> *p, int i)               	//ɾ����p�ĵ�i������Ϊ��������
//void clear()                                      	//ɾ����

};

template <class T>
Tree<T>::Tree()                                            //�������
{
    root = NULL;
}

template <class T>
bool Tree<T>::empty()                                      //�ж��Ƿ����
{
    return root==NULL;
}

//��1�� ���ı��� 
template <class T>
ostream& operator<<(ostream& out, Tree<T> &tree)           //������ĺ������ʾ�ַ���
{
    out<<"���ĺ������ʾ��\n";   
    tree.preOrder(tree.root, 0);
    return out;
}
//�ȸ����������pΪ��������������iָ�����Ĳ�Σ����i��tab���������ݹ��㷨
template <class T>
void Tree<T>::preOrder(TreeNode<T> *p, int i)
{
    if (p!=NULL)
    {
        for (int j=0; j<i; j++)
            cout<<"\t";
        cout<<p->data<<endl;
        preOrder(p->child, i+1);
        preOrder(p->sibling, i);
    }
}

//˼���� �μ�
template <class T>
void Tree<T>::postOrder()                                  //������������
{
    cout<<"���ĺ�������������:  ";   
    this->postOrder(root);
    cout<<endl;   
}
template <class T>
void Tree<T>::postOrder(TreeNode<T> *p)                    //������������pΪ�����������ݹ��㷨
{
    if (p!=NULL)
    {
        postOrder(p->child);
        cout<<p->data<<" ";
        postOrder(p->sibling);
    }
}

//˼���� �μ�
template <class T>
Tree<T>::~Tree()                                           //��������
{
    cout<<"������: ";
    remove(this->root);
    cout<<endl;
}

template <class T>
void Tree<T>::remove(TreeNode<T> *p)                       //ɾ����p���Ϊ��������������������
{
    if (p!=NULL)
    {
        remove(p->child);
        remove(p->sibling);
        cout<<p->data<<" ";                                //��ʾ�������Ĵ��򣬿�ʡ��
        delete p;
    }
}

//��2�� �Ժ������ʾ��������ɭ�֣�
//�Ժ������ʾ��������prelist����洢һ�����ĺ������ʾ���У�nΪprelist���鳤�ȡ�
//T������MyString���͵Ĺ��캯�������ֵȥ��������\tǰ׺���ǵݹ��㷨
template <class T>
Tree<T>::Tree(MyString prelist[], int n)
{
    this->root = NULL;
    if (n<=0)
        return;
    this->root = new TreeNode<T>(prelist[0]);              //���������
    TreeNode<T> *p = this->root;
    int len=0;                                             //p����'\t'ǰ׺����

    for (int i=1; i<n; i++)                                //��prelist[i]������Ϊɭ�������һ�����������һ������
    {   int j=0;
        while (j<prelist[i].count() && prelist[i][j]=='\t')   //ͳ��prelist[i]����'\t'ǰ׺����
            j++;

        prelist[i].remove(0,j);                            //ɾ��prelist[i]���д�0��ʼ��j���ַ�����ȥ������j��'\t'ǰ׺
        if (j==len+1)                                      //prelist[i]��ǰһԪ�ض�һ��'\t'ǰ׺
        {   p->child = new TreeNode<T>(prelist[i],p,NULL,NULL);   //������Ϊp�ĵ�0������
            p = p->child;
            len++;
            continue;
        }
        while (len > j)                                    //prelist[i]��ǰһԪ�ص�'\t'�٣�p����Ѱ�Ҳ���λ��
        {   p=p->parent;                                   //p����һ��
           len--;
        }
        p->sibling = new TreeNode<T>(prelist[i],p->parent,NULL,NULL);//ǰ׺������ͬ��������Ϊp�����¸��ֵ�
        p = p->sibling;
    }
}


//ʵ��6-11
template <class T>
int Tree<T>::count()                                       //�������Ľ�����
{
    return this->count(this->root);
}
template <class T>
int Tree<T>::count(TreeNode<T> *p)                         //������p���Ϊ�����������������㷨ͬ������
{
    if (p==NULL)
        return 0;
    return 1+count(p->child)+count(p->sibling);
}

template <class T>
int Tree<T>::childCount(TreeNode<T> *p)                    //����p���ĺ��ӽ����
{
    int i=0;
    if (p!=NULL)
        for (p=p->child;  p!=NULL;  p=p->sibling)
            i++;
    return i;
}

template <class T>
int Tree<T>::height()                                      //�������ĸ߶�
{
   return this->height(this->root);
}
template <class T>
int Tree<T>::height(TreeNode<T> *p)                        //������p���Ϊ���������߶ȣ�����������
{
   if (p!=NULL)
   {
       int lh = height(p->child)+1;
       int rh = height(p->sibling);
       return (lh>=rh) ? lh : rh;
   }
   return 0;
}

//���ң��㷨ͬ������
template <class T>
TreeNode<T>* Tree<T>::search(T value)            //�����״γ��ֵ�ֵΪvalue���
{
    return search(root, value);
}

    //����pΪ���������в��ң��ȸ������������ֵΪvalue�Ľ�㣬�����״γ��ֽ��ָ�룬��δ�ҵ�����NULL
template <class T>
TreeNode<T>* Tree<T>::search(TreeNode<T> *p, T value)
{
    TreeNode<T> *find=NULL;                      //�����ҵ����
    if (p!=NULL)
    {
        if (p->data==value) 
            return p;                            //���ҳɹ������ؽ��ָ��
        find = search(p->child, value);          //���������в��ң�findָ���ҵ���㣬�ݹ����
        if (find==NULL)                          //������������δ�ҵ�
            find = search(p->sibling, value);    //��������������в��ң��ݹ����
    }
    return find;                                 //���ز��ҽ��
}

template <class T>
TreeNode<T>* Tree<T>::getChild(TreeNode<T> *p, int i)      //����p���ĵ�i������
{
    if (p==NULL || p->child==NULL)                         //pû�к���
        return NULL;
    p=p->child;                                            //p���ﺢ�ӽ��
    p = p->child;
    for (int j=1;  j<=i;  j++)
        p = p->sibling;
    return p;
}

//���ؽ��
template <class T>
TreeNode<T>* Tree<T>::getLastSibling(TreeNode<T> *p)       //����p�������һ���ֵ�
{
    if (p==NULL || p->sibling==NULL) 
        return NULL;                                       //pû���ֵ�ʱ������NULL
    while (p->sibling!=NULL)                               //p�����ֵ����������һ������
        p = p->sibling;
    return p; 
}

template <class T>
TreeNode<T>* Tree<T>::getLastChild(TreeNode<T> *p)         //����p�������һ������
{
    if (p==NULL || p->child==NULL)                         //pû�к���
        return NULL;
    p=p->child;                                            //p���ﺢ�ӽ��
    if (p->sibling==NULL)
        return p;
    return this->getLastSibling(p);                        //����p�������һ���ֵ�
}


//����xԪ����Ϊ����㣬ԭ�������Ϊx�ĺ��ӽ�㣬���ز�����
template <class T>
TreeNode<T>* Tree<T>::insertRoot(T x)
{
    return this->root = new TreeNode<T>(x, NULL, this->root);
}

//����x��Ϊp�������һ���ֵܽ��
template <class T>
TreeNode<T>* Tree<T>::insertLastSibling(TreeNode<T> *p, T x)
{
    if (p==NULL) 
        return NULL;
    if (p->sibling!=NULL)                                  //��p���ֵ�ʱ
        p=this->getLastSibling(p);                         //p�������һ���ֵ�
    return p->sibling = new TreeNode<T>(x, p->parent);     //����xΪp���ֵܣ����ز�����
}

//����x��Ϊp�������һ�����ӽ��
template <class T>
TreeNode<T>* Tree<T>::insertLastChild(TreeNode<T> *p, T x)
{
    if (p==NULL)
        return NULL;
    if (p->child==NULL)                                    //��pû�к���ʱ
       return p->child = new TreeNode<T>(x, p);            //����x��Ϊp�ĺ��ӣ����ز�����
    return this->insertLastSibling(p->child, x);           //��p�к���ʱ������x��Ϊp���ӽ������һ���ֵ�
}

//����xԪ����Ϊp���ĵ�i���ֵܽ�㣬���ز����㡣
//��i��0ʱ������x��Ϊp������һ���ֵܽ�㣻��i����p�����ֵܸ���ʱ������x��Ϊp�������һ���ֵܽ��
template <class T>
TreeNode<T>* Tree<T>::insertSibling(TreeNode<T> *p, T x, int i)
{
    if (p==NULL)
        return NULL;
    for (int j=0;  j<i && p->sibling!=NULL;  j++)
        p = p->sibling;
    return p->sibling = new TreeNode<T>(x, p->parent, NULL, p->sibling); //����x��Ϊp���¸��ֵ�
}

//����xԪ����Ϊp���ĵ�i�����ӽ�㣬���ز����㡣
//��i��0ʱ������x��Ϊp���ĵ�0�����ӽ�㣻��i����p���ĺ��Ӹ���ʱ������x��Ϊp�������һ�����ӽ��
template <class T>
TreeNode<T>* Tree<T>::insertChild(TreeNode<T> *p, T x, int i)
{
    if (p==NULL)
        return NULL;
    if (p->child==NULL || i<=0)                            //����x��Ϊp���ĵ�0������
    {
        p->child = new TreeNode<T>(x, p, NULL, p->child);  //����x��Ϊp���ĵ�i����1��������
        return p->child;
    }
    p = p->child;
//    for (int j=1;  j<i && p->sibling!=NULL;  j++)
//        p = p->sibling;
    return insertSibling(p, x, i);//->sibling = new TreeNode<T>(x, p->parent, NULL, p->sibling); //����x��Ϊp���¸��ֵ�
}


//���
template <class T>
Tree<T>::Tree(Tree<T> &tree)                               //���������֪��Tree������
{
    this->root = copy(tree.root);
}

template <class T>
TreeNode<T>* Tree<T>::copy(TreeNode<T> *p)                 //������p��������
{                                                          //�����½������ĸ����
    TreeNode<T> *q=NULL;
    if (p!=NULL)                                           //�ǿ�ʱ�������
    {
        q = new TreeNode<T>(p->data, q);
        q->child = copy(p->child);                         //�������������ݹ����
        q->sibling = copy(p->sibling);                     //�������������ݹ����
    }
    return q;                                              //���ؽ��������ĸ����
}

template <class T>
Tree<T>& Tree<T>::operator=(Tree<T> &tree)                 //����=��ֵ����������
{
    destroy(this->root);
    this->root = copy(tree.root);
    return *this;
}

//������ʾ
template <class T>
void Tree<T>::printGenList()                                 //�Թ�����ʾ�����
{
    cout<<"���Ĺ�����ʾ��\n";
    printGenList(root);
    cout<<endl;
}

template <class T>
void Tree<T>::printGenList(TreeNode<T> *p)                 //�����p���Ϊ���������Ĺ�����ʾ
{
    if (p!=NULL)
    {
        cout<<p->data;
        if (p->child!=NULL)
        {
            cout<<"(";                                     //������()���
            printGenList(p->child);                        //����������ݹ����
            cout<<")";
        }
        if (p->sibling!=NULL)
        {
            cout<<",";                                     //����֮���Զ��ŷָ�
            printGenList(p->sibling);                      //�������ֵ��������ݹ����
        }
    }
}


