//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����4.1�� �����ʽ��Բ�����Ƿ�ƥ�䡣

#include "MyString.h"                                      //�ַ�����
#include "SeqStack.h"                                      //˳��ջ��
//#include "LinkedStack.h"                                 //��ʽջ��

//���expstr���ʽ�е�����Բ�����Ƿ�ƥ�䣬��ƥ�䣬��û��������������������Ϣ
void printError(MyString &expstr)
{
    SeqStack<char> stack;                                  //������ջ
//    LinkedStack<char> stack;                               //������ջ
    for (int i=0; i<expstr.count(); i++)
        switch (expstr[i])
        {
            case '(': stack.push(expstr[i]);               //��������ջ
             //         cout<<stack;
                      break;
            case ')': if (stack.empty() || stack.pop()!='(')  //����������ʱ����ջ���жϳ�ջ�ַ��Ƿ�Ϊ������
                          cout<<"����(";
                //      cout<<stack;
        }
    if (!stack.empty())
        cout<<"����)";
    cout<<endl;
}

int main()
{
    MyString expstr[]={"((1+2)*(3+4))()", "((1+2)*(3+4))(", "((1+2)*(3+4)))"}; 
    for (int i=0; i<3; i++)
    {
        cout<<expstr[i]<<"��";
        printError(expstr[i]);
    }

    system("pause");
    return 0;
}
/*
�������н�����£�
((1+2)*(3+4))��   
((1+2)*(3+4))(��  ����)
((1+2)*(3+4)))��  ����(

*/

/*
/�ж�expstr���ʽ�е�Բ�����Ƿ�ƥ�䣬���ر��������Ϣ
char* isValid(char *expstr)
{
    SeqStack<char> stack;                                  //������ջ
    for (int i=0; expstr[i]!='\0'; i++)
        switch (expstr[i])
        {
            case '(': stack.push(expstr[i]);               //��������ջ
                      break;
            case ')': if (stack.empty() || stack.pop()!='(')  //����������ʱ����ջ
                          return "����(";                  //�жϳ�ջ�ַ��Ƿ�Ϊ������
        }

//    cout<<stack;
    if (stack.empty())
        return "";                                         //���ؿմ���ʾû�д���
    return "����)";
}*/