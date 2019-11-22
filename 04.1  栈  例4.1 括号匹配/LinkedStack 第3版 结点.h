//4.1.3   ��ʽջ
//��3����壬ʹ�õ���������Ϊ��Ա����ʵ��ջ��

#include <iostream>
using namespace std;
#include "Node.h"                                         //���������ࣨ����2�£�

template <class T>
class LinkedStack                                         //��ʽջ��
{
  private:
    Node<T> *top;                                         //ָ��ջ������ָ��

  public:
    LinkedStack();                                        //�����ջ
    ~LinkedStack();                                       //����
    bool empty();                                       //�ж��Ƿ��ջ
    void push(T x);                                       //��ջ
    T pop();                                              //��ջ
    T get();                                              //����ջ��Ԫ�أ�δ��ջ
    friend ostream& operator<<<>(ostream& out, LinkedStack<T> &stack); //���ջ
};

template <class T>
LinkedStack<T>::LinkedStack()                              //�����ջ
{
    this->top = NULL;                                      //û��ͷ���
}

template <class T>
LinkedStack<T>::~LinkedStack()                             //��������
{
    Node<T> *p=this->top, *q;
    while (p!=NULL)
    {   q = p;
        p = p->next;
        delete q;
    }
    this->top = NULL;
}

template <class T>
bool LinkedStack<T>::empty()                             //�ж��Ƿ��ջ
{
    return this->top==NULL;
}

template <class T>
void LinkedStack<T>::push(T x)                             //��ջ��ͷ����
{
    this->top = new Node<T>(x, this->top);                 //x�����Ϊ�µ�ջ�����
}  

template <class T>
T LinkedStack<T>::pop()                                    //��ջ������ջ��Ԫ�أ���ջ�����׳��쳣
{
    if (!empty())
    {
        T x = this->top->data;                             //ͷɾ��
        Node<T> *p=this->top;
        this->top = this->top->next;
        delete p;                                          //ɾ��ԭջ�����
        return x;                                          //����ԭջ��Ԫ��
    }
    throw out_of_range("��ջ�����ܳ�ջ");
}

template <class T>
T LinkedStack<T>::get()                                    //����ջ��Ԫ�أ���ջ�����׳��쳣
{
    if (!empty())
        return this->top->data;
    throw out_of_range("��ջ�����ܻ��ջ��Ԫ��"); 
}

template <class T>
ostream& operator<<(ostream& out, LinkedStack<T> &stack)   //���ջ
{
    out<<"LinkedStack: (";
    for (Node<T> *p=stack.top;  p!=NULL;  p=p->next)
    {
        out<<p->data;
        if (p->next!=NULL)
            cout<<", ";
    }
    out<<")"<<endl;
    return out;
}
