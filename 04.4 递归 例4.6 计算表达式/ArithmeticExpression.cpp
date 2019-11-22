//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����4.6�� �õݹ��㷨�����������ʽ��ֵ��

#include "MyString.h"                                      //�ַ����ࣨ����3�£�

class ArithmeticExpression                                 //�������ʽ��������������λ���㣩
{
  private:
    MyString expstr;                                       //��׺�������ʽ�ַ���
    int index;                                             //��ǰ�ַ����

    int term();                                            //���㡴�
    int factor();                                          //���㡴���ӡ�
    int constant();                                        //���㡴������

  public:
    ArithmeticExpression(MyString expstr="");              //���ַ��������������ʽ
    int intValue();                                        //�����������ʽ����������ֵ
};

ArithmeticExpression::ArithmeticExpression(MyString expstr)//�����������ʽ��expstrָ����׺���ʽ�ַ���
{
    this->expstr = expstr;
    this->index = 0;
}

//�����index��ʼ��һ�����ӣ��������ʽ����������ֵ�����н��жࡴ��Ӽ�����
int ArithmeticExpression::intValue()
{
    int value1 = term();                                   //���㡴���ò�����1
    while (this->index < expstr.count())                   //���жࡴ��ļӼ�����
    {
        char ch = expstr[this->index];
        if (ch=='+' || ch=='-')
        {   this->index++;
            int value2 = term();                           //���㡴���ò�����2
            //���½���������ļӼ����㣬ch�ǵó�����value2֮ǰ�������
            switch (ch)
            {   case '+': value1 += value2; break;         //value1�洢������
                case '-': value1 -= value2; break;
            }                
        }
        else
        {
//            cout<<"expstr["<<index<<"]="<<expstr[index]<<endl;
            break;                                         //����')'ʱ���������
        }
    }
    return value1;  
}

int ArithmeticExpression::term()       //�����index��ʼ��һ��������н��жࡴ���ӡ��ĳ˳�����
{
    int value1 = factor();                                 //���㡴���ӡ���ò�����1
    while (this->index < expstr.count())                   //���жࡴ���ӡ��ĳ˳�����
    {
        char ch = expstr[this->index];
        if (ch=='*' || ch=='/' || ch=='%')
        {   this->index++;
            int value2 = factor();                         //���㡴���ӡ���ò�����2
            switch (ch)                                    //�������ӡ����г˳�����
            {   case '*': value1 *= value2; break;
                case '/': value1 /= value2; break;
                case '%': value1 %= value2; break;
            }                
        }
        else 
        {
//            cout<<"expstr["<<index<<"]="<<expstr[index]<<endl;
            break;                                         //����')'��'+'��'-'ʱ�������ӡ�����
        }
    }
    return value1;  
}

//�����index��ʼ��һ�������ӡ������а�����()Ϊ����ӱ��ʽ����ӵݹ����
int ArithmeticExpression::factor()
{
    if (expstr[this->index]=='(')
    {   this->index++;                                     //����'('
        int value = intValue();                            //����()�����ڵ��ӱ��ʽ����ӵݹ����
        this->index++;                                     //����')'
        return value;
    }
    return constant(); 
}

int ArithmeticExpression::constant()                       //�����index��ʼ��һ����������
{
    if (this->index < expstr.count())
    {
        char ch=expstr[this->index];
        int sign=1;
        if (ch=='+' || ch=='-')
        {    sign = ch=='-' ? -1 : 1;                      //����λ����ס��������� 
             this->index++;                                //��������λ
        }
        int value=0;
        while (this->index < expstr.count() && expstr[index]>='0' && expstr[index]<='9')
            value = value*10+expstr[this->index++]-'0';    //value��ס��ǰ��õ�����ֵ
        if (value!=0)
            return value*sign;                             //�����з��ŵ�����ֵ
    }
//   throw Exception("\""+expstr.substring(this->index-1)+"\"����ת��������");
}
  
int main()
{
    MyString expstr="123+10*(50-45+15)/((35-25)*2-10)+(-11)";
    cout<<expstr<<"="<<ArithmeticExpression(expstr).intValue()<<endl;

    MyString expstrs[]={"123","+123","-123","(-123)",
                     "1+-2","1-+2","-1+((-2))","1+2+3","1*2*3","-1*-2*-3"};
    for (int i=0; i<10; i++)
        cout<<expstrs[i]<<"="<<ArithmeticExpression(expstrs[i]).intValue()<<endl;

    system("pause");
    return 0;
}    

/*
�������н�����£�
123+10*(50-45+15)/((35-25)*2-10)+(-11)=132
123=123
+123=123
-123=-123
(-123)=-123
1+-2=-1
1-+2=-1
-1+((-2))=-3
1+2+3=6
1*2*3=6
-1*-2*-3=-6

*/
