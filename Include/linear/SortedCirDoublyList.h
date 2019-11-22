//2.3.3   ˫����
//4.  ����ѭ��˫����

#include "CirDoublyList.h"                                 //ѭ��˫������
//����
template <class T>
class SortedCirDoublyList : public CirDoublyList<T>        //�����������ѭ��˫�����࣬�̳д�ͷ����ѭ��˫������
{
  public:
    SortedCirDoublyList(){}                                //�����˫�����Զ�ִ��CirDoublyList<T>()
    SortedCirDoublyList(T values[], int n);                 //������ָ�������ṩԪ�ص�˫������

    DLinkNode<T>* insert(T x);                             //�����㣬����Ԫ�ش�С�����ں���λ��
    void removeFirst(T key);                               //ɾ���״γ��ֵĹؼ���ֵΪkey���

    //��9������
    SortedCirDoublyList(HSLinkedList<T> &list);  //������캯�����ɵ�����list��������ѭ��˫����ֱ�Ӳ�������
    void merge(SortedCirDoublyList<T> &list);    //�鲢��������ѭ��˫���� 
    SortedCirDoublyList(CirDoublyList<T> list); //������췽������ѭ��˫����list��������ѭ��˫�������������㷨
    void quickSort(DLinkNode<T> *begin, DLinkNode<T> *end);//һ�˿�������begin��endָ�����еĿ�ʼ������㣬�ݹ��㷨
};
//    ~SortedCirDoublyList(){}                     //���ܼ̳л��������������Զ�ִ��~CirDoublyList<T>()

template <class T>
SortedCirDoublyList<T>::SortedCirDoublyList(T values[], int n)  //������ָ�������ṩԪ�ص�˫����
{                                                //�˴��Զ�ִ��CirHDLinkedList<T>()������ͷ���
    for (int i=0; i<n; i++)   
        this->insert(values[i]);
}

template <class T>
DLinkNode<T>* SortedCirDoublyList<T>::insert(T x)//�����㣬����Ԫ�ش�С�����ں���λ�ã�T��������>�����
{
    DLinkNode<T> *p=this->head->prev, *q=NULL;
    if (p!=head && x > p->data)                  //���ֵ������ͷ���֮ǰ������������β��T��������>�����
    {
        q = new DLinkNode<T>(x, p, this->head);  //������head���֮ǰ��p���֮��
        this->head->prev = q;
        p->next = q;
    }
    else
    {   p=this->head->next;
        while (p!=this->head && x > p->data)     //Ѱ�Ҳ���λ�ã������ڵ�ֵ���֮ǰ��T��������>�����
            p = p->next;
        q = new DLinkNode<T>(x, p->prev, p);     //������p���֮ǰ
        p->prev->next = q;
        p->prev = q;
    }
    return q;
}

//ɾ���״γ��ֵ�ֵΪx��㣬�������ɹ�����true��T��������>��==�����
template <class T>
bool SortedCirDoublyList<T>::remove(T x)
{
    DLinkNode<T> *p=this->head->next;
    while (p!=this->head && x > p->data)         //Ѱ�Ҵ�ɾ����㣬T��������>�����
        p = p->next;
    if (x == p->data)                            //ɾ��p��㣬T��������==�����
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return true;
    }
    return false;
}

//��9������
//������캯�����ɵ�����list��������ѭ��˫����ֱ�Ӳ������������㷨
template <class T>
SortedCirDoublyList<T>::SortedCirDoublyList(HSLinkedList<T> &list)
{                       //�˴��Զ�ִ�л����Ĭ�Ϲ��캯����������ѭ��˫����
    DLinkNode<T> *p=this->head;
    for (Node<T> *q=list.head->next;  q!=NULL;  q=q->next) 
    {           //��list�������н������������Ʋ��뵽this�������У�����q->dataֵ�Ĵ�С��������λ��
        DLinkNode<T> *t;
        if (p!=this->head && q->data > p->data)
        {
            while (p!=this->head && q->data > p->data)     //q->data�ϴ�p�����
                p = p->next;
            t = new DLinkNode<T>(q->data, p->prev, p);     //t������p���֮ǰ
            p->prev->next = t;
            p->prev = t;
        }
        else
        {
            while (p!=this->head && q->data < p->data)     //q->data��С��p��ǰ��
                p = p->prev;
            t = new DLinkNode<T>(q->data, p, p->next);     //t������p���֮��
            p->next->prev = t;
            p->next = t;
        }
        p=t;
    }
}

//������췽������ѭ��˫����list��������ѭ��˫�������������㷨
template <class T>
SortedCirDoublyList<T>::SortedCirDoublyList(CirDoublyList<T> list)  
{   //�˴��Զ�ִ�л����Ĭ�Ϲ��캯��CirDoublyList<T>()��list�ѻ��ʵ�ʲ�������������
    DLinkNode<T> *tmp=this->head;
    this->head = list.head;                           //this��ò���list�����������
    list.head=tmp;                                    //���õ�����listΪ��
    quickSort(this->head->next, this->head->prev);
}    
//һ�˿�������begin��endָ�����еĿ�ʼ������㣬�ݹ��㷨
template <class T>
void SortedCirDoublyList<T>::quickSort(DLinkNode<T> *begin, DLinkNode<T> *end)
{
    if (begin!=end && begin!=end->next)                    //�ų��պ͵�����������
    {
        DLinkNode<T> *front=begin, *rear=end;
        T vot=front->data;                                 //��һ��ֵ��Ϊ��׼ֵ
        while (front!=rear)                                //һ������
        {
            while (front!=rear && rear->data >vot)         //�Ӻ���ǰѰ�ҽ�Сֵ
                rear=rear->prev;
            if (front!=rear)
            {   front->data = rear->data;                  //��СԪ����ǰ�ƶ�
                front=front->next;
            }
            while (front!=rear && front->data < vot)       //��ǰ���Ѱ�ҽϴ�ֵ
                front=front->next;
            if (front!=rear)
            {   rear->data = front->data;                  //�ϴ�Ԫ������ƶ�
                rear=rear->prev;
            }
        }
        front->data=vot;                                   //��׼ֵ��������λ��
        quickSort(begin, rear->prev);                      //ǰ�������������򣬵ݹ����
        quickSort(front->next, end);                       //��������������򣬵ݹ����
    }
}

//�鲢��������ѭ��˫������list�����н��鲢����ǰ����ѭ��˫�����У��ϲ�������list��
template <class T>
void SortedCirDoublyList<T>::merge(SortedCirDoublyList<T> &list)  
{
    DLinkNode<T> *p=this->head->next;
    DLinkNode<T> *q=list.head->next;
    while (p!=this->head && q!=list.head)
        if (p->data < q->data)                        //�Ƚ���������ǰ���ֵ
            p = p->next;
        else                                          //��q�����뵽���֮ǰ
        {   q->prev = p->prev;
            p->prev->next = q;
            p->prev = q;
            q = q->next;
            q->prev->next = p;
        }
    if (q!=list.head)                                 //��list������ʣ���㲢�뵱ǰ����β
    {
        this->head->prev->next = q;
        q->prev = this->head->prev;
        while (q->next!=list.head)
            q = q->next;
        q->next = this->head;
        this->head->prev = q;
    }
    list.head->next = list.head;                      //�ϲ�������listΪ��
    list.head->prev = list.head;
}
