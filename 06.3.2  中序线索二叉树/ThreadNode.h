//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//6.3   ����������
//6.3.2   ��������������
//�����������Ķ�����������

template <class T>
class ThreadNode                                           //�����������Ķ����������࣬Tָ������Ԫ������
{
  public:
    T data;                                                //�����򣬱���Ԫ��
    ThreadNode<T> *left,*right;                            //ָ���򣬷ֱ�ָ�����Һ��ӽ��
    bool ltag,rtag;                                        //����������־��1���ֽ�

    //�����㣬dataָ��Ԫ�أ�left��rightָ��ֱ�ָ�����Ӻ��Һ��ӽ�㣬Ĭ�Ͽգ�
    //ltag��rtag�ֱ��ʾ����������־��Ĭ��0
    ThreadNode(T data, ThreadNode<T> *left=NULL, ThreadNode<T> *right=NULL, bool ltag=0, bool rtag=0)
    {
        this->data = data;
        this->left = left;
        this->right = right;
        this->ltag = ltag;
        this->rtag = rtag;
    }
 };
/*
   //�����㣬ָ��Ԫ�ء����Ӻ��Һ��ӽ��
    ThreadNode(T data, ThreadNode<T> *left=NULL, int ltag=0, ThreadNode<T> *right=NULL, int rtag=0)
        :data(data),left(left),ltag(ltag),right(right),rtag(rtag)
    {}

    //�����㣬ָ��Ԫ�ء����Ӻ��Һ��ӽ��
    ThreadNode(T data, ThreadNode<T> *left=NULL, ThreadNode<T> *right=NULL)
        :data(data),left(left),right(right)
    {
        this->ltag = this->rtag = 0;
    }


*/