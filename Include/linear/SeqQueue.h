//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//4.2.2   ˳�����
//3. ˳��ѭ��������

#include <iostream>
using namespace std;

template <class T>
class SeqQueue                                             //˳��ѭ��������
{
  private:
    T *element;                                            //��̬����洢���е�����Ԫ��
    int length;                                            //���е���������
    int front, rear;                                       //������β�±�

  public:
    SeqQueue();                                            //����ն���
    ~SeqQueue();                                           //�������� 

    bool empty();                                          //�ж��Ƿ�ն���
    void enqueue(T x);                                     //���
    T dequeue();                                           //���ӣ����ض�ͷԪ��
    friend ostream& operator<<<>(ostream& out, SeqQueue<T> &que); //�������
};

template <class T>
SeqQueue<T>::SeqQueue()                                    //����ն���
{
    this->length = 32;                                     //Ĭ����������
    this->element = new T[this->length];
    this->front = this->rear = 0;                          //���ÿն���
}

template <class T>
SeqQueue<T>::~SeqQueue()                                   //��������
{
    delete []this->element;
}

template <class T>
bool SeqQueue<T>::empty()                                  //�ж϶����Ƿ�Ϊ�գ����շ���true
{
    return this->front==this->rear;
}

template <class T>
void SeqQueue<T>::enqueue(T x)                             //��ӣ�β���룬O(1)
{
    if (front==(rear+1) % length)                          //������������������������
    {
        T *temp = this->element;  
        this->element = new T[this->length*2];
        int j=0;
        for (int i=front;  i!=rear;  i=(i+1)%length)       //������Ԫ�ش���������Ԫ��
            this->element[j++] = temp[i];
        this->front = 0;
        this->rear = j;
        this->length *=2;
    }
    this->element[this->rear] = x;
    this->rear = (rear+1) % length;
}

template <class T>
T SeqQueue<T>::dequeue()                                   //���ӣ����ض�ͷԪ�أ������п����׳��쳣��ͷɾ����O(1)
{
    if (!empty())
    {
        T x = this->element[front];
        this->front = (front+1) % length;
        return x;
    }
    throw out_of_range("�ն��У�����ִ�г��Ӳ���");
}

template <class T>
ostream& operator<<(ostream& out, SeqQueue<T> &que)        //�������
{
    out<<"SeqQueue: (";
    for (int i=que.front;  i!=que.rear;  i=(i+1) % que.length)
        out<<que.element[i]<<" ";
    out<<")"<<endl;
    return out;
}
