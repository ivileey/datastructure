//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//ϰͼ4.3��c����ѭ��˫������Ϊ��Ա����ʵ�ֶ��С�

#include "CirDoublyList.h"                                 //ѭ��˫������

template <class T>
class DoublyQueue                                          //��ʽ������
{
  private:
    CirDoublyList<T> list;                                 //ʹ��ѭ��˫����洢����Ԫ��

  public:
    //ʹ��Ĭ�Ϲ��캯����Ĭ����������

    bool empty()                                           //�ж��Ƿ�ն��У�O(1)
    {
        return list.empty();
    }

    void enqueue(T x)                                      //��ӣ�O(1)
    {
        list.insert(x);                                    //��ѭ��˫����������xԪ�ؽ�㣬O(1)
    }  

    T dequeue()                                            //���ӣ����ض�ͷԪ�أ������п����׳��쳣��O(1)
    {
        if (!empty())
             return list.remove(0);                        //ɾ����ͷ��㣬���ض�ͷԪ�أ�O(1)
        throw out_of_range("�ն��У�����ִ�г��Ӳ���");
    }

    friend ostream& operator<<(ostream& out, DoublyQueue<T> &que) //�������
    {
        out<<"DoublyQueue:  "<<que.list;
        return out;
    }
};
