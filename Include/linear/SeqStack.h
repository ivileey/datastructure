//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//4.1.2  ˳��ջ��
//��3�棬ʹ��˳�����Ϊջ�ĳ�Ա����ʵ��ջ��

#include "SeqList.h"                                       //˳����ࣨ��2�£�

template <class T>
class SeqStack                                             //˳��ջ��
{
  private:
    SeqList<T> list;                                       //ʹ��˳���洢ջԪ��

  public:
    SeqStack(){}                                           //Ĭ�Ϲ����ջ��ִ��SeqList<T>()��Ĭ����������ʡ��
    ~SeqStack(){}                                          ///Ĭ��������ִ��~SeqList<T>()����ʡ��
    bool empty()                                           //�ж��Ƿ��ջ
    {
        return this->list.empty();
    }

    void push(T x)                                         //��ջ
    {
        this->list.insert(x);                              //˳���β����Ԫ��x���Զ���������
    }  

    T pop()                                                //��ջ������ջ��Ԫ�أ���ջ�����׳��쳣
    {
        if (!empty())
            return this->list.remove(list.count()-1);      //˳���βɾ��������ջ��Ԫ��
        throw logic_error("��ջ������ִ�г�ջ����");       //�׳��߼������쳣
    }

    T get()                                                //����ջ��Ԫ�أ�δ��ջ������ջ�����׳��쳣
    {
        if (!empty())
            return this->list.get(list.count()-1);         //ִ��T�Ŀ������캯��
        throw logic_error("��ջ�����ܻ��ջ��Ԫ��"); 
    }

    friend ostream& operator<<<>(ostream& out, SeqStack<T>&stack) //���ջ
    {
        out<<"SeqStack: "<<stack.list;
        return out;
    }
};
