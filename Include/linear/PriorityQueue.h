//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//4.3   ���ȶ���

#include "SortedSinglyList.h"                              //�������������ࣨ��2�£�
//#include "SortedCirDoublyList.h"                  //�����������ѭ��˫������

template <class T>
class PriorityQueue                                       //���ȶ����࣬Ԫ�ذ����ȼ���������
{
  private:
    SortedSinglyList<T> list;                              //ʹ����������洢����Ԫ��
//    SortedCirDoublyList<T> list; 

  public:
    //����ն��У�ascָ������true��Ĭ�ϣ�����false����list(asc)����ִ�г�Ա����list�Ĺ��캯��SortedSinglyList(asc)
    PriorityQueue(bool asc=true):list(asc){}
//    ~PriorityQueue(){}                                     //������ִ��~SortedSinglyList()

    bool empty();                                        //�ж��Ƿ�ն���
    void enqueue(T x);                                     //���
    T dequeue();                                           //����
    friend ostream& operator<<<>(ostream& out, PriorityQueue<T> &que); //�������
};

template <class T>
bool PriorityQueue<T>::empty()                           //�ж��Ƿ�ն���
{
    return this->list.empty();
}

template <class T>
void PriorityQueue<T>::enqueue(T x)                        //���
{
    this->list.insert(x);                                  //����������룬��xԪ�ش�Сȷ������λ��
}  

template <class T>
T PriorityQueue<T>::dequeue()                              //���ӣ����ض�ͷԪ�أ������п����׳��쳣 
{
    if (!empty())
    {
        T x = this->list.get(0);                           //ȡ�ö�ͷԪ��
        this->list.removeFirst(x);
        return x;
    }
    throw out_of_range("�ն��У�����ִ�г��Ӳ���");
}

template <class T>
ostream& operator<<(ostream& out, PriorityQueue<T> &que)   //�������
{
    out<<"PriorityQueue:  "<<que.list;
    return out;
}
