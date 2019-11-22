//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����4.4�� ���̰����ȼ����ȹ���

//#include "MyString.h"                                      //�ַ�����
#include "PriorityQueue.h"                                 //���ȶ�����

struct Process                                             //����
{
    char* name;                                            //������
    int priority;                                          //���ȼ�

    friend ostream& operator<<(ostream& out, Process &p)
    {
        out<<"("<<p.name<<","<<p.priority<<")";
        return out;
    }
    bool operator==(Process &p)                            //�Ƚ����������Ƿ���ȣ����ڲ���ʱʶ�����
    {
        return this->name==p.name && this->priority==p.priority;
    }
    bool operator!=(Process &p)
    {
        return !(*this==p);
    }
    bool operator>(Process &p)                             //�Ƚ��������̴�С��Լ�������ŶӴ���
    {
        return priority > p.priority;
    }
    bool operator>=(Process &p)
    {
        return priority >= p.priority;
    }
    bool operator<(Process &p)
    {
        return priority < p.priority;
    }
    bool operator<=(Process &p)
    {
        return priority <= p.priority;
    }
};

int main()
{
//    Process pro={"A",4};

    const int N=6;
    Process pro[N]={{"A",4},{"B",3},{"C",5},{"D",4},{"E",1},{"F",10}};     //��������
    PriorityQueue<Process> que(false);                            //���ȶ��У�����ָ������
    cout<<"��ӽ��̣�";
    for (int i=0; i<N; i++)
    {
        que.enqueue(pro[i]); 
        cout<<pro[i]<<" ";
    }

    cout<<"\n���ӽ��̣�";
    while (!que.empty()) 
        cout<<que.dequeue()<<" "; 
    cout<<endl;

    system("pause");
    return 0;
}
    
/*
�������н�����£�
��ӽ��̣�(A,4) (B,3) (C,5) (D,4) (E,1) (F,10) 
���ӽ��̣�(F,10) (C,5) (A,4) (D,4) (B,3) (E,1) 

*/

