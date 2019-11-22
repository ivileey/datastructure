//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//5.1.2   ��ά����
//����5.1��  �����ࡣ

#include "Matrix.h"                                        //������

int main()
{
    const int M=3, N=4; 
    Matrix mata(M, N, 0);                                  //����������Ԫ��Ϊ0
    mata.set(0,0,1);
    mata.set(M-1,N-1,1);                                   //{1,0,0,0,0,1};

    int table[M*N]={1,2,3,4,5,6,7,8,9};
    Matrix matb(M, N, table);                              //������������һά���飨������

//    int table[M*N]={1,2,3,4,5,6,7,8,9};
//    Matrix matb(M,N,&table2[0][0]);                        //������󣬶�ά����ת��Ϊһά���飨������
    cout<<"A "<<mata<<"B "<<matb;

    //��˼����5-1����������
    Matrix matc(M-1,N-1); 
    matc=mata+matb;                                        //��ִ��+����ִ�и�ֵ(����)
    cout<<"C=A+B��C "<<matc<<endl;
    mata+=matb;
    cout<<"A+=B��A "<<mata<<endl;
    cout<<"C==A��"<<(matc==mata)<<endl;
    cout<<"C==B��"<<(matc==matb)<<endl;

    Matrix matd(M,M,0);
    cout<<"D "<<matd;
    cout<<"D �������Ǿ���"<<matd.isUpTriangular()<<endl;
    cout<<"D �ǶԳƾ���"<<matd.isSymmetric()<<endl<<endl;
    matd = mata.transpose();                               //��ֵ�����ƣ�����
    cout<<"D = A��ת�ã�D "<<matd;
    cout<<"D �������Ǿ���"<<matd.isUpTriangular()<<endl;
    cout<<"D �ǶԳƾ���"<<matd.isSymmetric()<<endl;

    system("pause");
    return 0;
}

/*
�������н������:
A ����3��4����
1  0  0  0  
0  1  0  0  
0  0  1  0  
B ����3��4����
1  2  3  4  
5  6  7  8  
9  0  0  0  
A + B =����3��4����
2  2  3  4  
5  7  7  8  
9  0  1  0  

A += B��A����3��4����
2  2  3  4  
5  7  7  8  
9  0  1  0  

C���(B)��C==B��1
D ����3��3����
0  0  0  
0  0  0  
0  0  0  
D �������Ǿ���1
D �ǶԳƾ���1

D = A��ת�ã�D����4��3����
2  5  9  
2  7  0  
3  7  1  
4  8  0  
D �������Ǿ���0
D �ǶԳƾ���0


*/
