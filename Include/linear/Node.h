//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//2.3.2   ������
//1.����������

template <class T>
class Node                                       //���������࣬Tָ������Ԫ������
{
  public:
    T data;                                      //�����򣬱�������Ԫ��
    Node<T> *next;                               //��ַ��ָ���򣩣�ָ���̽��

    Node()                                       //�����㣬data��δ��ʼ��
    {
        this->next = NULL;                       //ָ�븳ֵ
    }
    Node(T data, Node<T> *next=NULL)             //�����㣬dataָ������Ԫ�أ�nextָ����̽���ַ��Ĭ�Ͽ�ֵ
    {
        this->data = data;                       //ִ��T��=��ֵ����
        this->next = next;                       //ָ�븳ֵ
    }
};

//��ϰ2.3��  �����������������ۡ�
//����Ҫ������������~Node()����Ϊ����û�ж�̬����洢�ռ䣬��������ڵ�����Ĳ����С�
/*
template <class T>
Node<T>::Node(Node<T> node)        //Ĭ�Ͽ������캯��Ϊǳ����
{
    this->data = node.data; 
    this->next = node.next;
}*/
