//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����4.2�� ʹ��ջ������ʽ��ֵ��

#include "MyString.h"                                      //�ַ�����
#include "SeqStack.h"                                      //˳��ջ��
#include "LinkedStack.h"                                   //��ʽջ��

//��expstr��ʾ����׺���ʽת��Ϊ��׺���ʽ������MyString����
MyString toPostfix(MyString &expstr)
{
//    SeqStack<char> stack;                                  //�����ջ
    LinkedStack<char> stack;
    MyString postfix("", expstr.count()*2);                //��׺���ʽ�ַ���
    int i=0;
    while (i<expstr.count())
        switch (expstr[i])
        {
            case '+':                                      //�������������������ջ��Ԫ�رȽ�
            case '-': while (!stack.empty() && stack.get()!='(')
                          postfix += stack.pop();          //��ջ�ַ����ӵ���׺���ʽ��
                      stack.push(expstr[i++]);             //��ǰ�������ջ
                      break;
            case '*':                                      //����*��/�����
            case '/': while (!stack.empty() && (stack.get()=='*' || stack.get()=='/'))
                          postfix += stack.pop();
                      stack.push(expstr[i++]);
                      break;
            case '(': stack.push(expstr[i++]);             //���������ţ���ջ
                      break;
            case ')': { char out = stack.pop();             //���������ţ���ջ
                      while (!stack.empty() && out!='(') //�жϳ�ջ�ַ��Ƿ�Ϊ������
                      {   postfix += out;
                          out = stack.pop();
                      }
                      i++;
                      break;}
            default:                                       //��������ʱ�����뵽��׺���ʽ
                      while (i<expstr.count() && expstr[i]>='0' && expstr[i]<='9')
                          postfix += expstr[i++];     
                      postfix += ' ';                      //��׺���ʽ�ַ�������ֵ֮���Կո�ָ�
        }
    while (!stack.empty())
        postfix += stack.pop();
    return postfix;                                        //����MyString����ִ��MyString�Ŀ������캯��
}

int toValue(MyString &postfix)                             //�����׺���ʽ��ֵ
{
    SeqStack<int> stack;                                   //������ջ
//    LinkedStack<int> stack;                                //������ջ
    int value=0;
    for (int i=0; i<postfix.count(); i++)                  //�������׺���ʽ�е��ַ�
        if (postfix[i]>='0' && postfix[i]<='9')            //���������ַ�
        {
            value=0;
            while (postfix[i]!=' ')                        //�����ַ���ת��Ϊ������ֵ
                value = value*10 + postfix[i++]-'0';
            stack.push(value);                             //��������ջ
        }
        else
            if (postfix[i]!=' ')
            {
                int y = stack.pop();                       //��ջ����������
                int x = stack.pop();
                switch (postfix[i])                        //����������ֱ����
                {
                    case '+': value = x+y;  break;
                    case '-': value = x-y;  break;
                    case '*': value = x*y;  break;
                    case '/': value = x/y;  break;         //����
                }
                stack.push(value);                         //��������ջ
            } 
    return stack.pop();                                    //����������
}

int main()
{
//    MyString expstr("1+2*(3-4)+5");                              //ͼ4.7
//    MyString expstr("121+10*(53-49+20)/((35-25)*2+10)+11");      //��4.2
    MyString expstr="121+10*(53-49+20)/((35-25)*2+10)+11";         //��4.2��Ҳ�ɣ� MyString��������=(char*)
//    MyString expstr("121+10*(53-49+20)/((35-25)*2+10)+(-11)");   //��4.2��û��ʶ��������

    MyString postfix = toPostfix(expstr);                  //ִ��MyString��=����� 
    cout<<"expstr=  "<<expstr<<endl;
    cout<<"postfix= "<<postfix<<endl;
    cout<<"value=   "<<toValue(postfix)<<endl;

    system("pause");
    return 0;
}
/*
�������н�����£�
expstr=  121+10*(53-49+20)/((35-25)*2+10)+11
postfix= 121 10 53 49 -20 +*35 25 -2 *10 +/+11 +
value=   140

*/
