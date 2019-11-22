//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//8.3   ����������ķֿ����
//����8.1�� �����������ѯC++�ؼ��֡�
//��ϰ8.2�� ���������������ѯC++�ؼ��֡�

#include <iostream>
using namespace std;
#include "MyString.h"                                      //�ַ����ࣨ��3�£�
#include "SortedSeqList.h"                                 //����˳�����2�£�

   //�ؼ��ֱ�
MyString keywords[]={"auto","bool","break","case","catch","char","class","const","const_cast",
    "continue","default","delete","do","double","dynamic_cast","else","enum","explicit","extern","false","float","for","friend",
    "goto","if","inline","int","long","mutable","namespace","new","operator","private","protected","public",
    "register","reinterpret_cast","return","short","signed","sizeof","static","static_cast","struct","switch","template",
    "this","throw","true","try","typedef","typeid","typename","union","unsigned","using","virtual","void","volatile","while"};

class IndexItem                                            //��������
{
  public:
    char first;                                            //�ؼ��ֵ����ַ�
    int begin, end;                                        //���ַ���ͬ�Ĺؼ��ֿ��������еĿ�ʼ�������±�

    IndexItem(char first=' ', int begin=0, int end=0)      //���캯��
    {
        this->first = first;
        this->begin = begin;
        this->end = end;
    }
    friend ostream& operator<<(ostream& out, IndexItem &item)//����������ַ���
    {
        out<<"("<<item.first<<","<<item.begin<<","<<item.end<<")";
        return out;
    }
    bool operator==(IndexItem &item)                       //Լ����������ȹ������ַ���ͬ
    {
        return this->first==item.first;
    }
    bool operator<(IndexItem &item)                        //Լ��������Ƚϴ�С���򣺰����ַ��Ƚϴ�С
    {
        return this->first<item.first;
    }
    bool operator>(IndexItem &item) 
    {
        return this->first>item.first; 
    }
    bool operator>=(IndexItem &item) 
    {
        return this->first>=item.first;
    }
};

//Ϊ�ؼ�������˳���list����������indexlist
void create(SortedSeqList<MyString> &list, SortedSeqList<IndexItem> &indexlist) 
{
    int begin=0;
    while (begin<list.count())
    {
        char first = list[begin][0];                       //list[begin]�ַ��������ַ�
        int i=0;                                           //��Ԫ�ؼ���
        while (begin+i<list.count() && list[begin+i][0]==first) //Ѱ�ҿ�������
            i++;
        indexlist.insert(IndexItem(first,begin,begin+i-1));//�����һ���������
        begin += i;                                        //��һ�鿪ʼ���
    }
}
//�ж�str�Ƿ�ΪC++�ؼ��֡�����������indexlist�н��ж��ַ����һ��str���ַ���Ӧ�������
//���ڹؼ�������˳���list��ָ����Χ�ڽ��ж��ַ�����
bool isKeyword(MyString str, SortedSeqList<MyString> &list, SortedSeqList<IndexItem> &indexlist)
{
    int i = indexlist.binarySearch(IndexItem(str[0],0,0));  //���������
    return i!=-1 && list.binarySearch(str, indexlist[i].begin, indexlist[i].end)>=0;
}

//˼����8-1
//��ϰ8.2�� ���������������ѯC++�ؼ��֡�

//Ϊ�ؼ�������˳���list��������������indexlist
void createExpand(SortedSeqList<MyString> &list, SortedSeqList<IndexItem> &indexlist) 
{
    char first = 'a';
    int begin=0;
    while (begin<list.count())
    {
        int i=0;                                           //��Ԫ�ؼ���
        while (begin+i<list.count() && list[begin+i][0]==first) //Ѱ�ҿ�������
            i++;
        if (i==0)
            indexlist.insert(IndexItem(first,-1,-1));      //����һ��������
        else
        {
            indexlist.insert(IndexItem(first,begin,begin+i-1));//�����һ���������
            begin += i;                                    //��һ�鿪ʼ���
        }
        first++;                                           //��һ�����ַ�
    }
}

//�ж�str�Ƿ�ΪC++�ؼ��֡��ȼ���str���ַ���Ӧ����������������indexlist�е���ţ���������
//���ڹؼ��ֱ�list��ָ����Χ�ڽ��ж��ַ�����
bool isKeywordExpand(MyString str, SortedSeqList<MyString> &list, SortedSeqList<IndexItem> &indexlist)
{
    int i = str[0]-'a';                                    //���ַ���Ӧ���������ţ�O(1)
    if (i<0 || i>indexlist.count())
         return false;
    IndexItem item = indexlist[i];                         //������
    int begin=item.begin;                                  //��ÿ鿪ʼ���
    if (begin==-1)
        return false;
    return list.binarySearch(str, begin, item.end)>=0;     //���ַ����ҹؼ��ֱ��ָ����Χ
}

int main() 
{
    SortedSeqList<MyString> list(keywords,60);             //�ؼ�������˳���
//    cout<<"����"<<list.getCount()<<"���ؼ���\n"<<list;
    SortedSeqList<IndexItem> indexlist;                    //��������
    create(list, indexlist);                               //����������
    cout<<"����������������"<<indexlist.count()<<endl<<indexlist;
    MyString str[]={"auto","and","false","length","while","why"};
    for (int i=0; i<6; i++)
        cout<<str[i]<<(isKeyword(str[i],list,indexlist)?"":"��")<<"�ǹؼ���\n";

    //˼����8-1��ϰ8.2
    SortedSeqList<IndexItem> indexlist2;                   //��������
    createExpand(list,indexlist2);                         //��������������
    cout<<"\n��������������������"<<indexlist2.count()<<endl<<indexlist2;
    for (int i=0; i<6; i++)
        cout<<str[i]<<(isKeywordExpand(str[i],list,indexlist2)?"":"��")<<"�ǹؼ���\n";

    system("pause");
    return 0;
}

/*
�������н�����£�
����������������19
((a,0,0), (b,1,2), (c,3,8), (d,9,12), (e,13,16), (f,17,20), (g,21,21), (i,22,24), (l,25,25), (m,26,26), (n,27,27), (o,28,28), (p,29,31), (r,32,33), (s,34,40), (t,41,46), (u,47,48), (v,49,51), (w,52,52))
(m,26,26)? (e,13,16)? (b,1,2)? (a,0,0)? auto? auto�ǹؼ���
(m,26,26)? (e,13,16)? (b,1,2)? (a,0,0)? auto? and���ǹؼ���
(m,26,26)? (e,13,16)? (g,21,21)? (f,17,20)? float? false? false�ǹؼ���
(m,26,26)? (e,13,16)? (g,21,21)? (i,22,24)? (l,25,25)? long? length���ǹؼ���
(m,26,26)? (s,34,40)? (u,47,48)? (v,49,51)? (w,52,52)? while? while�ǹؼ���
(m,26,26)? (s,34,40)? (u,47,48)? (v,49,51)? (w,52,52)? while? why���ǹؼ���

��������������������23
((a,0,0), (b,1,2), (c,3,8), (d,9,12), (e,13,16), (f,17,20), (g,21,21), (h,-1,-1), (i,22,24), (j,-1,-1), (k,-1,-1), (l,25,25), (m,26,26), (n,27,27), (o,28,28), (p,29,31), (q,-1,-1), (r,32,33), (s,34,40), (t,41,46), (u,47,48), (v,49,51), (w,52,52))
auto? auto�ǹؼ���
auto? and���ǹؼ���
float? false? false�ǹؼ���
long? length���ǹؼ���
while? while�ǹؼ���
while? why���ǹؼ���


*/
