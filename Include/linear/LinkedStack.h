//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//4.1.3   ��ʽջ
//�õ�������Ϊ��Ա����ʵ��ջ��

#include "SinglyList.h"                                    //�������ࣨ��2�£�

template <class T>
class LinkedStack                                          //��ʽջ��
{
  private:
    SinglyList<T> list;                                    //ʹ�õ�����洢ջԪ��

  public:
    LinkedStack(){}                                        //Ĭ�Ϲ����ջ��ִ��SinglyList<T>()����ʡ��
    ~LinkedStack(){}                                       ///Ĭ��������ִ��~SinglyList<T>()����ʡ��
    bool empty()                                           //�ж��Ƿ��ջ
    {
        return this->list.empty();
    }

    void push(T x)                                         //��ջ
    {
        this->list.insert(0, x);                           //������ͷ����Ԫ��x
    }  

    T pop()                                                //��ջ������ջ��Ԫ�أ���ջ�����׳��쳣
    {
        if (!empty())
            return this->list.remove(0);                   //������ͷɾ��������ջ��Ԫ��
        throw logic_error("��ջ������ִ�г�ջ����");
    }

    T get()                                                //����ջ��Ԫ�أ�δ��ջ������ջ�����׳��쳣
    {
        if (!empty())
            return this->list.get(0);
        throw logic_error("��ջ�����ܻ��ջ��Ԫ��"); 
    }

    friend ostream& operator<<<>(ostream& out, LinkedStack<T>&stack) //���ջ
    {
        out<<"LinkedStack: "<<stack.list;
        return out;
    }
};
