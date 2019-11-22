//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//4.2.3   ��ʽ����

#include <iostream>
using namespace std;
#include "Node.h"                                          //���������ࣨ��2�£�

template <class T>
class LinkedQueue                                          //��ʽ������
{
  private:
    Node<T> *front, *rear;                                 //front��rear�ֱ�ָ����׺Ͷ�β���

  public:
    LinkedQueue();                                         //����ն���
    ~LinkedQueue();                                        //����

    bool empty();                                          //�ж��Ƿ�ն���
    void enqueue(T x);                                     //���
    T dequeue();                                           //����
    friend ostream& operator<<<>(ostream& out, LinkedQueue<T> &que); //�������
};

template <class T>
LinkedQueue<T>::LinkedQueue()                              //����ն���
{
    this->front = this->rear = NULL;
}

template <class T>
LinkedQueue<T>::~LinkedQueue()                             //��������
{
    Node<T> *p=this->front, *q;
    while (p!=NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    this->front = this->rear = NULL;
}

template <class T>
bool LinkedQueue<T>::empty()                               //�ж��Ƿ�ն���
{
    return this->front==NULL && this->rear==NULL;
}

template <class T>
void LinkedQueue<T>::enqueue(T x)                          //��ӣ�O(1)
{
    Node<T> *q = new Node<T>(x);
    if (empty())
        this->front = q;                                   //�նӲ���
    else 
        rear->next = q;                                    //����β����
    this->rear = q;
}  

template <class T>
T LinkedQueue<T>::dequeue()                                //���ӣ����ض�ͷԪ�أ������п����׳��쳣��O(1)
{
    if (!empty())
    {
        T x = front->data;                                 //ȡ�ö�ͷԪ��
        Node<T> *p=front;
        this->front = front->next;                         //ɾ����ͷ���
        delete p;
        if (this->front==NULL)                             //�ն���ʱ����ָ��ͬ��
           this->rear = NULL;
        return x;
    }
    throw out_of_range("�ն��У�����ִ�г��Ӳ���");
}

template <class T>
ostream& operator<<(ostream& out, LinkedQueue<T> &que)     //�������
{
    out<<"LinkedQueue:  (";
    for (Node<T> *p=que.front;  p!=NULL;  p=p->next)
    {
        out<<p->data;        
        if (p->next!=NULL)
            cout<<", ";
    }
    out<<")"<<endl;
    return out;
}
