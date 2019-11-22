//10.1.3   ̰�ķ�
//��С����
#include "SeqList.h"                                       //˳����ࣨ��2�£�
#include "Comparator.h"                                    //�Ƚ��������� 

template <class T>
class MinHeap                                              //��С���࣬T��������>�����
{
  private:
    SeqList<T> list;                                       //ʹ��˳���洢��С��Ԫ��
    Comparator<T> *comp;                                   //�Ƚ�������ָ�� 

    void sift(int parent);                                 //����parentΪ����������������С��
    
  public:
    MinHeap(Comparator<T> *comp=NULL)                      //�������С�ѣ�compָ���Ƚ�������ָ��
    {                                                      //�˴�ִ��SeqList<T>()��˳�������ΪĬ��ֵ
        this->comp = comp;
    }
    MinHeap(T value[], int n, Comparator<T> *comp=NULL)    //������С�ѣ�value�����ṩԪ��
    {                                                      //�˴��Զ�ִ��SeqList<T>()
        this->comp = comp;
        for (int i=0; i<n; i++)
            this->insert(value[i]);                        //����Ԫ�ز�����С��
    }
    ~MinHeap(){}                                           //�����������Զ�ִ��~SeqList<T>()����ʡ��

    bool empty()                                           //�ж��Ƿ�ն�
    {   
        return this->list.empty();
    }
    int count()                                            //������С��Ԫ�ظ���
    {
        return this->list.count();
    }
    friend ostream& operator<<(ostream& out, MinHeap<T> &heap)//�����С�ѣ���ʽΪ��(,)��
    {
        out<<heap.list;
        return out;
    }
    void insert(T x);                                      //��x���뵽��С����
    T removeMin();                                         //������Сֵ��ɾ������㲢����Ϊ��С��
};


template <class T>
void MinHeap<T>::insert(T x)                               //��x���뵽��С����
{
    this->list.insert(x);                                  //����С��������Ԫ�أ�˳���β����Ԫ�أ�˳����Զ�����������
    for (int i=this->count()/2-1; i>=0; i=(i-1)/2)         //���¶��ϵ������Ӷ�����Ϊ��С��
    {
        sift(i);        
        if(i==0)
            break;
    }
//    cout<<*this;
}

//����parentΪ����������������С�ѣ�T��������>
template <class T>
void MinHeap<T>::sift(int parent)
{
    if (this->empty())
        return;

    int child = 2*parent+1;                                //childΪ������parent��������
    T key = this->list[parent];                            //��õ�parent��Ԫ�ص�ֵ
    while (child < this->count())                          //�ؽ�Сֵ���ӽ������ɸѡ
    {
        if (child<this->count()-1)
        {
            T left=list[child], right=list[child+1];       //���Һ��ӽ��ֵ
            if (comp!=NULL ? comp->compare(left, right)>0 : left>right)
                  //��compָ�벻�գ���*comp�Ƚ�������Ƚ�T�����С������ִ��T��>����
            child++;                                       //childΪ���Һ��ӵĽ�С��
        }
        if (comp!=NULL ? comp->compare(key, list[child])>0 : key>list[child])
        {                                                  //����ĸ���ֵ�ϴ�
            list[parent] = list[child];                    //���ӽ���еĽ�Сֵ����
            parent = child;                                //parent��child����һ��
            child = 2*parent+1;
        }
        else break;
    }
    this->list[parent] = key;                              //��ǰ������ԭ��ֵ�������λ��
}

template <class T>
T MinHeap<T>::removeMin()                                  //������СֵԪ�أ�������ɾ������㲢����Ϊ��С��
{
     if (this->empty())
        return NULL;
     T x = this->list[0];                                  //�����С�Ѹ����Ԫ��
     list[0] = list[this->count()-1];                      //�����λ��Ԫ���Ƶ�������ɾ����
     this->list.remove(this->count()-1);                   //˳���βɾ���������Զ���1
     sift(0);                                              //������ֵ�³�����С�ѵĺ���λ��
     return x;
}
