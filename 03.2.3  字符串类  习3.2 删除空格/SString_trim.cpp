//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//��ϰ3.2��  ɾ���������пո�

#include "MyString.h"                   //˳����
using namespace std;

int main() 
{
    MyString str("   a bc d  e  f  xyz");
    cout<<str<<"��count="<<str.count()<<endl;
    str.trim();

//    trim(str);
    cout<<str<<"��count="<<str.count()<<endl;

//    str.removeAll(" ");
//    cout<<"str.removeAll(" ")="<<str<<endl;

    system("pause");
    return 0;
}

/*
����������н�����£�
abcdefxyz
*/

/*??
void trim(MyString &str)                          //ɾ��str�������пո��ַ�
{
    int n=str.length(), i=0;                     //n��ô�����
    while (i<n)
        if (str.charAt(i)!=' ')                  //�ǿո�
            i++;
        else
        {
            str.remove(i,1);                     //ɾ���ո�
            n--;
        }
}*/