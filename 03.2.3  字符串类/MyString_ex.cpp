//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//3.2.3   �ַ�����

#include "MyString.h"                   //˳����

int main() 
{
    const int N=6;
    MyString str[N]={MyString("abc"), MyString("abc"), MyString("axbc"),MyString("abcdef"),MyString(""),MyString()};
    for (int i=0; i<N; i++)
        cout<<str[i]<<endl;

    MyString s1(str[3]), s2=str[2], s3, s4;                //���
    s3=str[3];                                             //��ֵ�������Ҫ���ݣ����·���
    s4="wxyz";
    cout<<"s1��"<<s1<<"\ns2��"<<s2<<"\ns3��"<<s3<<"\ns4��"<<s4<<endl;
/*
    for (int i=1; i<5; i++)
        cout<<str[0]<<" < "<<str[i]<<" �� "<<(str[0]<str[i])<<endl;
    for (int i=1; i<5; i++)
        cout<<str[0]<<" <= "<<str[i]<<" �� "<<(str[0]<=str[i])<<endl;
    for (int i=1; i<5; i++)
        cout<<str[0]<<" > "<<str[i]<<" �� "<<(str[0]>str[i])<<endl;
    for (int i=1; i<5; i++)
        cout<<str[0]<<" >= "<<str[i]<<" �� "<<(str[0]>=str[i])<<endl;
*/
    //2.  ���Ӵ��Ĳ���
    //��1�����Ӵ�
    cout<<s1<<".substring(0,9)="<<s1.substring(0,9)<<endl;
    cout<<s1<<".substring(3)="<<s1.substring(3)<<endl;
//    cout<<s1<<".substring(-1,9)="<<s1.substring(-1,9)<<endl;
//    cout<<s1<<".substring(0,-9)="<<s1.substring(0,-9)<<endl;

    //��2�����봮
//    s3.insert(4, s3.substring(3));                               //Ҫ����
/*    s1.insert(2, s2);                                              //������
    cout<<"���봮��s1��"<<s1<<endl;

    //��3�����Ӵ�
    cout<<"\""<<s1<<"\"+\""<<s2<<"\"=\""<<(s1+s2)<<"\""<<endl;  //Ҫ����
    s1+=s2;                                                     //Ҫ����
    cout<<"\""<<s1<<"\"+=\""<<s2<<"\"=\""<<s1<<"\""<<endl;
 
    //��4�� ɾ���Ӵ�
    cout<<"\""<<s1<<"\".remove(2, 9); ";
    s1.remove(2, 9);                                              //ɾ������β
    cout<<"s1��\""<<s1<<"\""<<endl;
*/

    system("pause");
    return 0;
}
/*
�������н�����£�
abc
abc
axbc
abcdef


s1��abc
s2��abc
s3��axbc
s3��abcdef
abc < abc �� 0
abc < axbc �� 1
abc < abcdef �� 1
abc <  �� 0
abc <= abc �� 1
abc <= axbc �� 1
abc <= abcdef �� 1
abc <=  �� 0
abc > abc �� 0
abc > axbc �� 0
abc > abcdef �� 0
abc >  �� 1
abc >= abc �� 1
abc >= axbc �� 0
abc >= abcdef �� 0
abc >=  �� 1
MyString����abcdef��count=6��length=7
"abcdef".substring(0,9)="abcdef"
MyString����abcdef��count=6��length=12
MyString����def��count=3��length=6
"abcdef".substring(3)="def"
MyString����def��count=3��length=6
�밴���������. . . 
MyString����abcdef��count=6��length=12
MyString����abc��count=3��length=6
MyString����abc��count=3��length=6
MyString������count=0��length=6
MyString������count=0��length=6
MyString����abcdef��count=6��length=12
MyString����axbc��count=4��length=8
MyString����abc��count=3��length=6
MyString����abc��count=3��length=6
*/
