//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����2.1��ʹ��˳������Լɪ�����⡣

#include "SeqList.h"                                       //˳�����
//#include "SinglyList.h"                                    //��������
//#include "CirDoublyList.h"                                 //ѭ��˫������


//����Josephus������⣬����ָ�������ȡ���ʼλ�á�������ʹ��˳���
void josephus(int number, int start, int distance)
{
    SeqList<char> list;                                    //����˳������ִ���޲ι��캯����ָ��˳���Ĭ������
    int i=0;
    for (i=0; i<number; i++)
        list.insert('A'+i);                                //��˳���������Ԫ�أ�O(1)
    cout<<"Josephus��("<<number<<","<<start<<","<<distance<<")��"<<list;    //���˳���

    i = start;                                             //������ʼλ��
    while (list.count()>1)                                 //����һ��Ԫ��ʱѭ����O(1)
    {
        i = (i+distance-1) % list.count();                 //����ʱ��ѭ�����ɱ仯��˳���ɿ����ǻ��νṹ
        cout<<"ɾ��"<<list.remove(i)<<"��"<<list;          //ɾ��ָ��λ��Ԫ�أ�O(n)
    }
    cout<<"����������"<<list[0]<<endl;                     //list[0]���Ԫ�أ�O(1)
}

/*//����Josephus������⣬����ָ�������ȡ���ʼλ�á�������ʹ�õ�����ѭ��˫����
void josephus(int number, int start, int distance)
{
//    SinglyList<char> list;                                 //�����յ�����
    CirDoublyList<char> list;                              //������ѭ��˫����
    int i;
    for (i=number-1; i>=0; i--)
        list.insert(0, 'A'+i);                             //������ͷ���룬O(1)
    cout<<"Josephus��("<<number<<","<<start<<","<<distance<<")��"<<list;

    i = start;                                             //������ʼλ��
    while (list.getCount()>1)                              //����һ��Ԫ��ʱѭ����O(1)
    {
        i = (i+distance-1) % list.getCount();              //����ʱ��ѭ�����ɱ仯��˳���ɿ����ǻ��νṹ
        cout<<"ɾ��"<<list.remove(i)<<"��"<<list;          //ɾ��ָ��λ��Ԫ�أ�O(n)
    }
    cout<<"����������"<<list.get(0)<<endl;                 //get(0)��õ�һ��Ԫ�أ�O(1)
}*/

int main()
{
    josephus(5,0,2);
//    josephus(10,0,2);
//    josephus_set(5,0,2);
    system("pause");
    return 0;
}

/*
�������н�����£�
Josephus��(5,0,2)�� (A, B, C, D, E) 
ɾ��B�� (A, C, D, E)
ɾ��D�� (A, C, E)
ɾ��A�� (C, E)
ɾ��E�� (C)
����������C 
*/

/* ˳���ɾ��Ԫ���㷨�����ÿ�λ��
void josephus_set(int number, int start, int distance)     //���Լɪ��
{                                                          //����ָ�������ȡ���ʼλ�á�����
    SeqList<char> jose(number);                            //����˳�������Ϊnumber
    int i=0;
    for (i=0; i<number; i++) 
        jose.insert('A'+i);                                //��˳���������Ԫ��
    cout<<"Լɪ��("<<number<<","<<start<<","<<distance<<")��"<<jose;
//   jose.print();                                          //���Լɪ��������Ԫ��

    i = start-1;                                           //������ʼλ��
    int count = jose.length();
    while (count>1)                                        //����һ������ʱѭ��
    {
        int j=0;
        while (j<distance) 
        {
            i = (i+1) % jose.length();                     //����ʱ��ѭ�����ɱ仯
            if (jose.get(i)!=' ')
                j++;
        }
        cout<<"ɾ��"<<jose.get(i)<<"��";
        jose.set(i, ' ');                                  //�Կո��ʾ��λ��Ԫ��Ϊ��
        count--;
        cout<<jose;//.print();
    }

    i=0;                                                   //Ѱ�����һ��Ԫ��
    while (i<jose.length() && jose.get(i)==' ')
        i++;
    cout<<"����������"<<jose.get(i)<<endl;
}*/

/*
�������н�����£�
     josephus_set(5,0,2);
�������н�����£�
Լɪ��(5,0,2)��list: (A, B, C, D, E) 
ɾ��B��list: (A,  , C, D, E)
ɾ��D��list: (A,  , C,  , E)
ɾ��A��list: ( ,  , C,  , E)
ɾ��E��list: ( ,  , C,  ,  )
����������C 
*/