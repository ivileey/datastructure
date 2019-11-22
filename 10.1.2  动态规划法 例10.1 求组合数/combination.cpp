//10.1.2   ��̬�滮��
//����10.1�����ö�̬�滮�����������
//����10.2�����û��ݷ���ָ�����ϵ������Ӽ���
//����10.3�����û��ݷ������n��Ԫ����ѡ��m����������ϡ�

#include <iostream>
using namespace std;

//����10.1�����ö�̬�滮�����������
//�� ���η��������
int combine(int m, int n)                                  //���������Cmn�����β��Եݹ��㷨
{
    if (n>0 && (m==0 || m==n))                             //�߽�������ֱ�ӽ�����⣬û�еݹ����
        return 1;
    if (m>0 && n>m)                                        //��һ��ֽ��2�������⣬�ݹ���ã����ظ�������ϲ���Ľ�
        return combine(m-1, n-1) + combine(m, n-1); 
    throw invalid_argument("�������������");            //�׳���Ч�����쳣
}

//�� ��̬�滮���������
int** createYanghui(int n)                                 //��n��������ǣ����������εĶ�̬��ά�����׵�ַ
{
    if (n<=0)
        return NULL;
    int **yanghui = new int*[n];                           //����n��һά����(n��)��Ԫ������Ϊint*
    for (int i=0; i<n; i++)
    {
        yanghui[i] = new int[i+1];                         //Ϊÿ������i+1��Ԫ�ص�һά���飬����Ϊint
        yanghui[i][0] = yanghui[i][i] = 1;                 //ÿ����βֵΪ1
        for (int j=1; j<i; j++)        
            yanghui[i][j] = yanghui[i-1][j-1]+yanghui[i-1][j];
                                 //��i��j��Ԫ��Ϊ����һ�У�i-1��ǰ����Ԫ�أ�j-1��j��֮��
    }
    return yanghui;                                        //���ض�ά�����׵�ַ
}

void print(int **yanghui, int n)                           //��������εĶ�̬��ά����
{
    cout<<"������ǣ�"<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
            cout<<yanghui[i][j]<<" ";
        cout<<endl;
    }
}

int combination(int** yanghui, int m, int n)               //��������Ƕ�ά�����������Cmn���أ�O(1)
{
    if (n>0 && (m==0 || m==n))
        return 1;
    if (m>0 && n>m && yanghui!=NULL)
        return yanghui[n][m];
    throw invalid_argument("�������������");            //�׳���Ч�����쳣
}

//����10.2�����û��ݷ���ָ�����ϵ������Ӽ���
template <class T>
void printSubset(T set[], int n)                           //���set���ϣ�n��Ԫ�أ��������Ӽ�
{
    bool *x = new bool[n];                                 //��ֵΪtrue
    printSubset(set, n, 0, x);
    cout<<endl;
}

template <class T>
void printSubset(T set[], int n, int i, bool x[])          //�ݹ����
{
    if (i<n)
    {
        x[i]=false;
        printSubset(set, n, i+1, x);
        x[i]=true;
        printSubset(set, n, i+1, x);
    }
    else
        printX(set, n, x);
}

template <class T>
void printX(T set[], int n, int x[])                      //���set��һ���⣬��ʽΪ��(,)�����Ӽ�����ʽΪ��{,}��
{
    cout<<"(";                                           //���set��һ���⣬��ʽΪ��(,)��
    if (n>0)
    {
        cout<<x[0];
        for (int i=1; i<n; i++)
            cout<<","<<x[i];
    }
    cout<<") ";
}

template <class T>
void printX(T set[], int n, bool x[])                      //���set��һ���⣬��ʽΪ��(,)�����Ӽ�����ʽΪ��{,}��
{
    cout<<"{";                                             //���set��һ���Ӽ�����ʽΪ��{,}��
    bool first=true;
    for (int i=0; i<n; i++)
        if (x[i])
        {
            if (!first)
                cout<<",";
            else
                first = !first;
            cout<<set[i];
        }
    cout<<"} ";
}

//����10.3�����û��ݷ������n��Ԫ����ѡ��m��Ԫ�ص�������ϡ�
template <class T>
void printCombined(T set[], int m, int n)                  //�����set���ϵ�n��Ԫ����ѡ��m��Ԫ�ص��������
{
    bool *x = new bool[n];                                 //һ��nԪ�飬��ֵȫΪtrue��������
    printCombined(set, m, n, x, 0, 0);
    cout<<endl;
}

//��set���ϵ�n��Ԫ����ѡ��m��Ԫ�ص�������ϣ�x[]��ʾһ��nԪ�飨�����������ݹ����
//��x[i]Ԫ��ֵ��0��i<n��j����x[]��ȡֵΪ1��Ԫ�ظ�����0��j<m��Լ������
template <class T>
void printCombined(T set[], int m, int n, bool x[], int i, int j)
{
    if (i<n)
    { 
        if (j+n-i>m)                                       //�޽��֦������j��ʣ��n-i��ѡ����ܵõ���ʱ����������
        {
            x[i]=false;                                    //������ȡֵ
            printCombined(set, m, n, x, i+1, j);           //��x[i+1]Ԫ��ֵ��jû�䣬�ݹ����
        }
        if (j<m)                                           //Լ����֦����������Լ������ʱ����������
        {
            x[i]=true;                                     //������ȡֵ
            printCombined(set, m, n, x, i+1, j+1);         //��x[i+1]Ԫ��ֵ��j+1���ݹ����
        }
    }
    else
        printX(set, n, x);                                 //�ݹ����������һ���Ӹ���Ҷ�ӵ�·�����õ�һ�������
}

//�������ݣ���
//��set���ϵ�n��Ԫ����ѡ��m��Ԫ�ص�������ϣ�x[]��ʾһ��nԪ�飨��������
//��x[i]Ԫ��ֵ��0��i<n��j����x[]��ȡֵΪ1��Ԫ�ظ�����0��j<m��Լ������
template <class T>
void combine(T set[], int m, int n)                  //�����set���ϵ�n��Ԫ����ѡ��m��Ԫ�ص��������
{
    int *x = new int[n];                                 //һ��nԪ�飬δ��ʼ����������
    int i=0;
    while (i<n)
    { 
        int j=0;
        if (j+n-i>m)                                       //�޽��֦������j��ʣ��n-i��ѡ����ܵõ���ʱ����������
        {
            x[i++]=0;                                    //������ȡֵ
        }
        if (j<m)                                           //Լ����֦����������Լ������ʱ����������
        {
            x[i++]=1;                                     //������ȡֵ
            j++;         //��x[i+1]Ԫ��ֵ��j+1���ݹ����
        }
        else
            i--;
        if (i==n)
            printX(set, n, x);                             //����һ���Ӹ���Ҷ�ӵ�·�����õ�һ�������
    }
    cout<<endl;
}
/*
        if (x[i]<=n)
            if (i==n)                            //���һ����
            {
                count++;
                print(n);
            }
            else x[++i]=0;
        else i--;
    }
}
*/
int main()
{
/*    //��10.1 �� ��̬�滮���������
    int m=2, n=5;
    int** yanghui = createYanghui(n+1);
    print(yanghui, n+1);
    cout<<"�����combination("<<m<<","<<n<<")="<<combination(yanghui, m, n)<<endl;
*/

    //10.1.4 ���ݷ� ͼ10.12�Ӽ�
    //��˼����10-1�����һ�����ϣ�n��Ԫ�أ��������Ӽ���
    int n=4;
    char set[]={'A','B','C','D','E'};
    bool x[]={1,1,1,1,1}; 
    printX(set, n, x);
    cout<<"���ϵ������Ӽ���";
    printSubset(set, n);

    //����10.3�����û��ݷ������n��Ԫ����ѡ��m����������ϡ�
    int** yanghui = createYanghui(n+1);                    //���n+1��������ǣ�����10.1
    for (int m=0; m<=n; m++)
    {
        cout<<"C("<<m<<","<<n<<")="<<combination(yanghui, m, n)<<"����ϣ�";  //��������ǻ������� ������10.1
        printCombined(set, m, n);                           //�ݹ����
//����        combine(set, m, n);                                 //��������
    }

    system("pause");
    return 0;
}


/*
������ǣ�
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 

{A,B,C} ����
�����Ӽ���{} {C} {B} {B,C} {A} {A,C} {A,B} {A,B,C} 
C(3,0)=1����ϣ�{} 
C(3,1)=3����ϣ�{C} {B} {A} 
C(3,2)=3����ϣ�{B,C} {A,C} {A,B} 
C(3,3)=1����ϣ�{A,B,C} 


{A,B,C,D} ����
�����Ӽ���{} {D} {C} {C,D} {B} {B,D} {B,C} {B,C,D} {A} {A,D} {A,C} {A,C,D} {A,B} {A,B,D} {A,B,C} {A,B,C,D} 
C(4,0)=1����ϣ�{} 
C(4,1)=4����ϣ�{D} {C} {B} {A} 
C(4,2)=6����ϣ�{C,D} {B,D} {B,C} {A,D} {A,C} {A,B} 
C(4,3)=4����ϣ�{B,C,D} {A,C,D} {A,B,D} {A,B,C} 
C(4,4)=1����ϣ�{A,B,C,D} 

{A,B,C,D,E} ����
�����Ӽ���{} {E} {D} {D,E} {C} {C,E} {C,D} {C,D,E} {B} {B,E} {B,D} {B,D,E} {B,C} {B,C,E} {B,C,D} {B,C,D,E} {A} {A,E} {A,D} {A,D,E} {A,C} {A,C,E} {A,C,D} {A,C,D,E} {A,B} {A,B,E} {A,B,D} {A,B,D,E} {A,B,C} {A,B,C,E} {A,B,C,D} {A,B,C,D,E} 
C(5,0)=1����ϣ�{} 
C(5,1)=5����ϣ�{E} {D} {C} {B} {A} 
C(5,2)=10����ϣ�{D,E} {C,E} {C,D} {B,E} {B,D} {B,C} {A,E} {A,D} {A,C} {A,B} 
C(5,3)=10����ϣ�{C,D,E} {B,D,E} {B,C,E} {B,C,D} {A,D,E} {A,C,E} {A,C,D} {A,B,E} {A,B,D} {A,B,C} 
C(5,4)=5����ϣ�{B,C,D,E} {A,C,D,E} {A,B,D,E} {A,B,C,E} {A,B,C,D} 
C(5,5)=1����ϣ�{A,B,C,D,E} 


*/


