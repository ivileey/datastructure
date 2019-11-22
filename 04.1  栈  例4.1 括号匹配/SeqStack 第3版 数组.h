//4.1.2  ˳��ջ��
//��3����壬ʹ��������Ϊջ�ĳ�Ա����ʵ��ջ��

#include <iostream>
using namespace std;

template <class T>
class SeqStack                                             //˳��ջ��
{
  private:
    T *element;                                            //��̬����洢ջ������Ԫ��
    int length;                                            //��������
    int top;                                               //ջ��Ԫ���±�

  public:
    SeqStack();                                            //�����ջ
    ~SeqStack();                                           //�������� 

    bool empty();                                        //�ж��Ƿ��ջ
    void push(T x);                                        //��ջ
    T pop();                                               //��ջ
    T get();                                               //����ջ��Ԫ�أ�δ��ջ
    friend ostream& operator<<<>(ostream& out, SeqStack<T> &stack);    //���ջ
};

template <class T>
SeqStack<T>::SeqStack()                                    //�����ջ
{
    this->length = 64;                                     //��������ȡĬ��ֵ
    this->element = new T[this->length];
    this->top = -1;
}

template <class T>
SeqStack<T>::~SeqStack()                                   //��������
{
    delete []this->element;
}

template <class T>
bool SeqStack<T>::empty()                                //�ж�ջ�Ƿ�Ϊ�գ����շ���true
{
    return this->top==-1;
}

template <class T>
void SeqStack<T>::push(T x)                                //��ջ��β����
{
    if (this->top==this->length-1)                         //��ջ������������������
    {
        T *temp = this->element;  
        this->element = new T[this->length*2];             //��������һ���������������
        for (int i=0; i<this->length; i++)                 //��������Ԫ�أ�O(n)
            this->element[i] = temp[i];
        this->length *=2;
    }
    this->top++;
    this->element[this->top] = x;
}

template <class T>
T SeqStack<T>::get()                                       //����ջ��Ԫ�أ�δ��ջ����ջ�����׳��쳣
{
    if (!empty())
        return this->element[top];                         //ִ��T�Ŀ������캯��
    throw out_of_range("��ջ�����ܻ��ջ��Ԫ��");          //�׳��쳣
}

template <class T>
T SeqStack<T>::pop()                                       //��ջ������ջ��Ԫ�أ���ջ�����׳��쳣��βɾ��
{
    if (!this->empty())
        return this->element[this->top--];                 //��ȡ����ֵ����top--
    throw out_of_range("��ջ������ִ�г�ջ����");          //�׳��쳣
}

template <class T>
ostream& operator<<(ostream& out, SeqStack<T> &stack)      //���ջ
{
    out<<"SeqStack: (";
    for (int i=0; i<stack.top; i++)
        out<<stack.element[i]<<", ";
    if (!stack.empty())
        out<<stack.element[stack.top];
    out<<")\n";
    return out;
}
