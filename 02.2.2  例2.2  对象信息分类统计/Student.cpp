//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����2.2��������Ϣ����ͳ������ҡ�

#include "Student.h"                                       //ѧ����Ϣ�ṹ
#include "SeqList.h"                                       //˳�����

//����ͳ��stulist���Ա�Ԫ����Ϣ���ֶ���Ϣ����grade���飬nָ��grade���鳤�ȣ�ͳ�ƽ������result����
void groupCount(SeqList<Student> &list, int grade[], int n, int result[])
{
    for (int i=0; i<list.count(); i++)
    {
        Student stu = list[i];                             //���list�ĵ�i��Ԫ�أ�ִ��StudentĬ�ϵ�=
        for (int j=0; j<n-1; j++)
            if (stu.score>=grade[j] && stu.score<grade[j+1]) //�ж�stu��Χ
            {   result[j]++;
                break;
            }
    }
}

int main()
{
    Student group[]={{"����",85},{"����",75},{"��ǿ",90},{"֣С��",80},{"����ŵ",60},{"����",65},{"��С��",70}}; 
    SeqList<Student> list(group,7);                        //��ָ�����鹹��˳���
    int grade[]={0,60,70,80,90,100};                       //ָ���ֶ���Ϣ
    const int N=5; 
    int result[N]={0};                                     //���ͳ�ƽ��
    char* str[]={"������","����","�е�","����","����"};    //�ַ�������ָ����������
    groupCount(list, grade, 6, result);                    //����ͳ��
    cout<<"ѧ�����ϣ�"<<list;                              //ִ��Student��<<
    cout<<"��"<<list.count()<<"�ˣ��ɼ�ͳ�ƣ�";
    for (int i=0; i<N; i++)
        cout<<str[i]<<result[i]<<"�ˣ�";
    cout<<endl;
    Student key={"֣С��",0};                              //�����ؼ���ֵ������Ԫ�أ��ṩ�������������ṩname��
    cout<<"����"<<key<<"�����"<<list[list.search(key)]<<endl;

    system("pause");
    return 0;
}
/*
�������н�����£�
ѧ�����ϣ�((����,85), (����,75), (��ǿ,90), (֣С��,80), (����ŵ,60), (����,65), (��С��,70))
��7�ˣ��ɼ�ͳ�ƣ�������0�ˣ�����2�ˣ��е�2�ˣ�����2�ˣ�����1�ˣ�
����(֣С��,0)�����(֣С��,80)
*/

/*
#include "SinglyLinkedList.h"                         //��������
double average(SeqList<Student> &stulist)                 	//��ƽ��ֵ
{
    int n=stulist.length();                      	//˳�����
    double sum=0;
    for (int i=0; i<n; i++)
         sum += stulist.get(i).score;            	//�˴�get(i)����Student�ṹ����
    return n>0 ? sum/n: 0;                      	//����0��Ԫ�ؽ�����������Ϊ0����
}
double average(SinglyLinkedList<Student> &stulist)    //��ƽ��ֵ
{
    int n=stulist.length();                           //��������
    if (n>0)
    {
        double sum=0;
        for (int i=0; i<n; i++)
             sum += stulist.get(i).score;             //�˴�get(i)����Student�ṹ����
        return sum/n;
    }
    return 0.0;                                       //����0��Ԫ�صĽ�����������Ϊ0����
}
*/


