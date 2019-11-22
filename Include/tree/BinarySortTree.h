//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//8.5.1   ����������

#include "BinaryTree.h"                                    //��������Ķ������ࣨ��6�£�

//�����������࣬�̳ж������࣬T��������==��!=��<�����
template <class T>
class BinarySortTree : public BinaryTree<T>
{
  public:
    BinarySortTree(){}                                     //����ն�����������Ĭ��ִ��BinaryTree<T>()
    BinarySortTree(T values[], int n);                     //��values����Ԫ�ع���һ�ö���������
    ~BinarySortTree(){}                                    //����������Ĭ��ִ��~BinaryTree<T>()����ʡ��

    T* search(T key);                                      //���ҹؼ���ΪkeyԪ�أ�����Ԫ�ص�ַ
    void insert(T key);                                    //����keyԪ�أ�������ؼ����ظ�Ԫ��
    void remove(T key);                                    //ɾ���ؼ���Ϊkey���
};

template <class T>
BinarySortTree<T>::BinarySortTree(T values[], int n)       //��values����Ԫ�����β��빹��һ�ö���������
{                                                          //Ĭ��ִ��BinaryTree<T>()
    for (int i=0; i<n; i++)
        this->insert(values[i]);                           //��Ԫ�ز��뵽��ǰ�Ķ�����������
} 

//���ҹؼ���ΪkeyԪ�أ������ҳɹ�������Ԫ�ص�ַ�����򷵻�NULL��T��������!=��<���ǵݹ��㷨
//���ǻ����search(T key)����������ֵ��ͬ��
template <class T>
T* BinarySortTree<T>::search(T key)
{
    BinaryNode<T> *p=this->root;
    while (p!=NULL && p->data!=key)                        //���Ҿ���һ���Ӹ�������·�����ǵݹ飬T��������!=
    {
//        cout<<p->data<<"? ";                             //��ʾ���Ҿ����Ľ��ֵ����ʡ��
        if (key < p->data)                                 //��key��С��T��������<
            p = p->left;                                   //����������
        else
            p = p->right;                                  //����������
    }
    return p==NULL ? NULL : &p->data;
}

//����keyԪ�أ�������ؼ����ظ�Ԫ�أ�T��������==��<���ǵݹ��㷨
//���ǻ����insert(x)�������insert(p, x, leftChild)���뺢�ӽ�㺯���������б�ͬ
template <class T>
void BinarySortTree<T>::insert(T key)
{
    if (this->root==NULL)
        this->root = new BinaryNode<T>(key);               //���������
    BinaryNode<T> *p=this->root, *parent=NULL;
    while (p!=NULL)                                        //����ȷ������λ��
    {
        if (p->data==key)                                  //���ҳɹ���������ؼ����ظ�Ԫ�� 
            return;   
        parent = p;
        if (key < p->data)
            p=p->left;
        else
            p=p->right;
    }    
    if (key < parent->data)                                //����key�����Ϊparent����/�Һ���
        parent->left = new BinaryNode<T>(key);
    else
        parent->right = new BinaryNode<T>(key);
}  

//ɾ���ؼ���ΪkeyԪ�ؽ�㡣�����Ҳ��ɹ�����ɾ�����ǵݹ��㷨
//���ǻ����remove()ɾ������remove(p,leftChild)ɾ�����������������б�ͬ��
template <class T>
void BinarySortTree<T>::remove(T key)
{
    BinaryNode<T> *p=this->root, *parent=NULL;
    while (p!=NULL && p->data!=key)                        //���ҹؼ���ΪkeyԪ�ؽ��
    {
        parent = p;                                        //parent��p�ĸ�ĸ���
        if (key < p->data)
             p=p->left;
         else  p=p->right; 
    }
    if (p!=NULL && p->left!=NULL && p->right!=NULL)        //�ҵ���ɾ�����p��p��2�Ƚ��
    {
        BinaryNode<T> *insucc = p->right;                  //Ѱ��p���и������µĺ�̽��insucc
        parent = p;                
        while (insucc->left!=NULL)
        {
            parent = insucc;                
            insucc = insucc->left;
        }
        p->data = insucc->data;                  	       //�ú�̽��ֵ�滻p���ֵ
        p = insucc;                                        //֮��ɾ��ԭp�ĺ�̽��insucc��ת��Ϊɾ��1��0�Ƚ��
    }
    if (p!=NULL && parent==NULL)                           //p�Ǹ���㣬��p==root��ɾ�������
    {
        if (p->left!=NULL)
            this->root = p->left;
        else  this->root = p->right;
        delete p;
        return;
    }
    if (p!=NULL && p==parent->left)                        //p��1�Ȼ�Ҷ�ӽ�㣬p��parent������
        if (p->left!=NULL)
            parent->left = p->left;                        //��p������������
        else  parent->left = p->right;
    if (p!=NULL && p==parent->right)                       //p��1�Ȼ�Ҷ�ӽ�㣬p��parent���Һ���
        if (p->left!=NULL)
            parent->right = p->left;
        else  parent->right = p->right;
    delete p;
}    
    
    //��֧�ָ����insertRoot()��insertChild()��removeChild()���������串�ǲ��׳��쳣��ʡ��


/*
    //��8��ϰ��
/*    BinaryNode<T>* searchNode(T x);                        //����ֵΪx�Ľ��
    BinaryNode<T>* insertNode(T x);                        //�����㣬�ݹ��㷨
  private:
    BinaryNode<T>* insert(BinaryNode<T> *p, T x);          //��x���뵽��pΪ����������
    BinaryNode<T>* searchNode(BinaryNode<T> *p, T x);  

//��8��ϰ�⣬�ݹ��㷨������δ����
template <class T>
BinaryNode<T>*  BinarySortTree<T>::insertNode(T x)   //�����㣬������ؼ����ظ��Ľ��
{
    if (this->root==NULL)
        return this->root=new BinaryNode<T>(x);
    return insert(this->root, value);            //����x����rootΪ���Ķ�����������
}

template <class T>
BinaryNode<T>* BinarySortTree<T>::insert(BinaryNode<T> *p, T x)  //��x���뵽��pΪ����������
{
    BinaryNode<T>* q=NULL; 
    if (p->data==x)
        return NULL;                             //������ؼ����ظ��Ľ�� 

    if (value < p->data)
        if (p->left==NULL)
        {
            q = new BinaryNode<T>(value);        //����Ҷ�ӽ����Ϊp������
            p->left = q;
            return q;
        }
        else
            return insert(p->left, value);       //��value���뵽p����������
    else
        if (p->right==NULL)
        {
            q = new BinaryNode<T>(value);
            p->right = q;                        //����Ҷ�ӽ����Ϊp���Һ���
            return q;
        }
        else
            return insert(p->right, value);      //��value���뵽p����������
}

//����ֵΪx�Ľ�㣬�����ҳɹ����ؽ�㣬���򷵻�NULL
template <class T>
BinaryNode<T>* BinarySortTree<T>::searchNode(T x)
{
    return searchNode(root, x);
}

//����pΪ���������в���ֵΪx�Ľ�㣬�ݹ��㷨
template <class T>
BinaryNode<T>* BinarySortTree<T>::searchNode(BinaryNode<T> *p, T x)  
{
    if (p!=NULL && p->data!=x)
    {
        cout<<p->data<<"? ";
        if (x < p->data)
            return searchNode(p->left, x);       //���������в���
        return searchNode(p->right, x);          //���������в���
    }
    return p;                                    //������������ȣ����ҳɹ�
}


*/