//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.3.3   ˫����
//1. ˫��������

template <class T>
class DoubleNode                                           //˫�������࣬Tָ������Ԫ������
{
  public:
    T data;                                                //�����򣬱���Ԫ��
    DoubleNode<T> *prev, *next;                            //��ַ��ָ���򣩣��ֱ�ָ��ǰ�����ͺ�̽��

    DoubleNode()                                           //�����㣬data��δ��ʼ��
    {
        this->prev = this->next = NULL;
    }
    //�����㣬dataָ������Ԫ�أ�prevָ��ǰ������ַ��nextָ����̽���ַ��Ĭ�Ͽ�ֵ
    DoubleNode(T data, DoubleNode<T> *prev=NULL, DoubleNode<T> *next=NULL)
    {
        this->data = data;                                 //ִ��T��=��ֵ����
        this->prev = prev;
        this->next = next;
    }
};

//ϰ��2
//����Ҫ������������~DoubleNode()��
/*
//������������
template <class T>
class DoubleNode : public Node<T>                      //˫�������࣬�̳е���������
{
    DoubleNode<T> *prev;                               //ָ��ǰ������ָ����
};

//�ȼ����������£�
template <class T>
class DoubleNode                                       //˫��������
{
    T data;                                           //�̳л���ĳ�Ա����
    Node<T> *next;                                    //�̳л���ĳ�Ա��������ָ������������ʹ���
    DoubleNode<T> *prev;
};*/
