//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.2.5   �������Ķ�������ʵ��
//�������Ķ�����������

template <class T>
class BinaryNode                                           //�������Ķ����������࣬Tָ������Ԫ������
{
  public:
    T data;                                                //�����򣬴洢����Ԫ��
    BinaryNode<T> *left,*right;                            //ָ���򣬷ֱ�ָ�����Һ��ӽ��

    //�����㣬dataָ��Ԫ�أ�left��rightָ��ֱ�ָ�����Ӻ��Һ��ӽ�㣬Ĭ�Ͽ�
    BinaryNode(T data, BinaryNode<T> *left=NULL, BinaryNode<T> *right=NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    bool isLeaf()
    {
        return this->left==NULL && this->right==NULL;
    }
};
