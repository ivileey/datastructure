//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.5.3   ���ĸ�ĸ�����ֵ�����ʵ��
//���ĸ�ĸ�����ֵ���������

template <class T>
class TreeNode                                             //���ĸ�ĸ�����ֵ��������࣬Tָ������Ԫ������
{
  public:
    T data;                                                //������
    TreeNode<T> *parent, *child, *sibling;                 //ָ���򣬷ֱ�ָ��ĸ�����ӡ��ֵܽ��

    //�����㣬�����ֱ�ָ��Ԫ�ء���ĸ��㡢���ӽ����ֵܽ��
    TreeNode(T data, TreeNode<T> *parent=NULL, TreeNode<T> *child=NULL, TreeNode<T> *sibling=NULL)
    { 
        this->data = data;
        this->parent = parent;
        this->child = child;
        this->sibling = sibling;
    }
};
