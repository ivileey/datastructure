//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//����6.2�� �������Ĺ�����ʾ��

#include "BinaryTree.h"                                    //��������

int main()
{
//    BinaryTree<MyString> bitree("AAA(BB,CC)");                 //����������
    BinaryTree<MyString> bitree("A(B(D(^,G),^),C(E,F(H,^)))");  //�����������ͼ6.21��ʾ�������Ĺ�����ʾ
    bitree.printGenList(); 

    cout<<bitree;                                          //����ȸ�����������У�������������
    bitree.inOrder();                                      //����и������������
    bitree.postOrder();                                    //�����������������
//    bitree.traverseGList(); 
	system("pause");
    return 0;
}

/*
�������н�����£�
A(B(D(^,G),^),C(E,F(H,^)))

*/
/*
//�Թ�����ʾ����һ�����������������ֵ��genlist[i]�����ظ�����ַ���ݹ��㷨
BinaryNode<char>* createGenList(char *genlist, int &i)
{
    BinaryNode<char> *p=NULL;
    if (genlist[i]>='A' && genlist[i]<='Z')                //�Դ�д��ĸ��ʾԪ��
    {
        p = new BinaryNode<char>(genlist[i++]);            //����Ҷ�ӽ��
        if (genlist[i]=='(')
        {
            i++;                                           //����'('
            p->left = createGenList(genlist, i);           //��������������++i
            i++;                                           //����','
            p->right = createGenList(genlist, i);          //����������
            i++;                                           //����')'
        }
    }
    if (genlist[i]=='^')
        i++;                                               //����'^'
    return p;
}

void createGenList(BinaryTree<char> &bitree, char genlist[]) //�Թ�����ʾ���������
{
    int i=0;
    bitree.root = createGenList(genlist, i);               //���õݹ��㷨
}*/

//#include "SeqStack.h"                            //˳��ջ
//#include "LinkedStack.h"                         //��ʽջ
/*??/*δ��� 2012��3��29��
//�ǵݹ��㷨��ʹ��ջ
void createGList(BinaryTree<char> &bitree, char glist[])   //�Թ�����ʾ���������
{
    bitree.root = NULL;                                    //�����ն�����
    SeqStack<BinaryNode<T>*> stack;              //����һ����ջ
    int i=0;
    BinaryNode<T> *p = root;
    while (p!=NULL || !stack.isEmpty())          //p�ǿջ�ջ�ǿ�ʱ
        if (p!=NULL)
        {
            cout<<p->data<<" ";                  //���ʽ��
            stack.push(p);                       //p�����ջ
            p = p->left;                         //����������
        }
        else                                     //pΪ����ջ�ǿ�ʱ
        {
            p = stack.pop();                     //pָ���ջ���
            p = p->right;                        //����������
        }
    cout<<endl;
    int i=0;
    BinaryNode<char> *p=NULL;
    if (glist[i]>='A' && glist[i]<='Z')                    //��д��ĸ
    {
        p = new BinaryNode<char>(glist[i++]);              //�������
        if (glist[i]=='(')
        {
            i++;                                           //����(
            p->left = createGList(glist, i);               //������������������++i
            i++;                                           //����,
            p->right = createGList(glist, i);              //��������������
            i++;                                           //����)
        }
    }
    if (glist[i]=='^')
        i++;                                               //����^
    return p;
}*/
