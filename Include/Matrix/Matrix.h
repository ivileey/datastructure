//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//5.1   ����
//����5.1��  �����ࡣ
//ʵ����ѧ����ľ�����Ĵ洢�����㡣7.2.1   ͼ���ڽӾ����ʾ��ʵ�� ��
//����ֻдͼ�๻�õĺ���������������Ϊ˼���⡣
//����������ṩ�����������ܣ�ͼ���ã���Ϊ��ͼ��û��Ȩ�޶Ծ����еĶ�ά������������ռ䡣

#include <iostream>
using namespace std;
#include <iomanip>                                         //����setw(6)���������ʽ

class Matrix                                               //������
{
  private:
    int rows, columns;                                     //��������������
    int **element;                                         //��̬��ά���飬�洢����Ԫ��

    void init(int rows, int columns);                      //����rows��columns�ж�ά���飬δ��ʼ��
    void init(int rows, int columns, int x);               //����rows��columns�ж�ά���飬Ԫ��Ϊx
    void copy(Matrix &mat);                                //����mat��������Ԫ�ص���ǰ����

  public:
    Matrix(int rows=0);                                    //����rows�׷���
    Matrix(int rows, int columns);                         //����rows��columns�о���Ԫ��δ��ʼ��
    Matrix(int rows, int columns, int x);                  //����rows��columns�о���Ԫ��ֵΪx
    Matrix(int rows, int columns, int values[]);           //���������valuesһά�����ṩԪ��
//����    Matrix(int rows, int columns, int **mat);               //�Զ�ά���鹹����󣬲��У�����ʶ��int*��int**
    Matrix(Matrix &mat);                                   //�������캯���������ʵ��5
//??    Matrix(int rows, int columns, Matrix &mat);         //�������7.5.2 Floyd�㷨�ã�
    Matrix& operator=(Matrix &mat);                        //����=��ֵ��������Զ����ݣ�ʵ��5
    ~Matrix();                                             //��������

    friend ostream& operator<<(ostream& out, Matrix&);     //�������������Ԫ��
    void set(int i, int j, int x);                         //���õ�i��j��Ԫ��ֵΪx
    void setRowsColumns(int rows, int columns);            //���þ������������Զ�����
    //˼����5-1
    int getRows();                                         //���ؾ�������
    int getColumns();                                      //���ؾ�������
    int get(int i, int j);                                 //���ص�i��j��Ԫ��ֵ
    //���Ͻ̲ĵ�5�£���7����

    //����ʵ��5
    bool operator==(Matrix &mat);                          //�Ƚ�����ͬ�׾����Ƿ����
    void operator+=(Matrix &mat);                          //��ǰ������mat�������
    Matrix operator+(Matrix &mat);                         //���ص�ǰ������mat��Ӻ�ľ���
//    void operator*=(Matrix &mat);                          //��ǰ������mat������ˣ�δʵ��
//    Matrix operator*(Matrix &mat);                         //���ص�ǰ������mat��˺�ľ���
    Matrix transpose();                                    //���ص�ǰ�����ת�þ���
    bool isUpTriangular();                                 //�жϵ�ǰ�����Ƿ�Ϊ�����Ǿ���
    bool isSymmetric();                                    //�жϵ�ǰ�����Ƿ�Ϊ�Գƾ���
};

//��1������������
void Matrix::init(int rows, int columns)                   //����rows��columns�ж�ά���飬δ��ʼ��
{
    if (rows>=0 && columns>=0)
    {
        this->rows = rows;
        this->columns = columns;
//        this->element = new int[rows][columns];          //�����
        this->element = new int*[rows];              //������洢����Ϣ��һά���飨rows�У���Ԫ������Ϊint*
        for (int i=0; i<rows; i++) 
            this->element[i] = new int[columns];     //��Ϊÿ������һά���飨columns��Ԫ�أ���Ԫ������Ϊint
    }
    else  throw invalid_argument("�����л�����Ϊ�����쳣");//�׳���Ч�����쳣
}
void Matrix::init(int rows, int columns, int x)            //����rows��columns�ж�ά���飬Ԫ��Ϊx
{
    this->init(rows, columns);
    for (int i=0; i<rows; i++)                             //��ʼ������Ԫ��Ϊx
        for (int j=0; j<columns; j++) 
            this->element[i][j] = x;
}

Matrix::Matrix(int rows)                                   //����rows�׷���Ԫ��δ��ʼ��
{
    this->init(rows, rows);
}
Matrix::Matrix(int rows, int columns)                      //����rows��columns�о���Ԫ��δ��ʼ��
{
    this->init(rows, columns);
}
Matrix::Matrix(int rows, int columns, int x)               //����rows��columns�о���Ԫ��Ϊx
{
    this->init(rows, columns, x);
}

//�������valuesһά�����������ṩrows��columns�о���Ԫ��
Matrix::Matrix(int rows, int columns, int values[])
{
    this->init(rows, columns);
    for (int i=0; i<rows; i++)
        for (int j=0; j<columns; j++)
            this->element[i][j] = values[i*columns+j];
}

Matrix::~Matrix()                                          //��������
{
    for (int i=0; i<rows; i++)                             //�ͷŶ�̬��ά����ռ�õ��ڴ�ռ�
        delete(this->element[i]);                          //���ͷ�ÿ�е�һά����
    delete(this->element);                                 //����ͷŴ洢����Ϣ��һά����
}

//��2��������������Ժ������ȡԪ��
int Matrix::getRows()                                      //���ؾ�������
{
    return this->rows;
}
int Matrix::getColumns()                                   //���ؾ�������
{
    return this->columns;
}

int Matrix::get(int i, int j)                              //���ص�i��j��Ԫ��ֵ//����[][]�±�δ�ɹ�����
{
    if (i>=0 && i<rows && j>=0 && j<columns) 
        return this->element[i][j];
    throw out_of_range("����Ԫ�ص��л������Խ���쳣");
}

void Matrix::set(int i, int j, int x)                      //���õ�i��j��Ԫ��ֵΪx
{
    if (i>=0 && i<rows && j>=0 && j<columns) 
        this->element[i][j] = x;
    else throw out_of_range("����Ԫ�ص��л������Խ���쳣");
}

//��3�����
ostream& operator<<(ostream& out, Matrix &mat)             //�����������Ԫ��
{
    out<<"����"<<mat.rows<<"��"<<mat.columns<<"����"<<endl;
    for (int i=0; i<mat.rows; i++)
    {
        for (int j=0; j<mat.columns; j++)
            out<<setw(6)<<mat.element[i][j];               //setw(6)���������ʽ��ÿ����ռ��6��
        out<<"\n";
    }
    return out;
}

//���þ�������������rows��columns����ָ�����������ϴ��򽫾������ݣ�������ԭ����Ԫ�ء����Ӳ���δ��ʼ��
//����7.2.1��ͼ���ڽӾ���
void Matrix::setRowsColumns(int rows, int columns)
{
    if (rows > this->rows || columns > this->columns)      //����ָ���������������ϴ�ʱ
    {
        int rowsold = this->rows, columnsold=this->columns;
        int **temp = this->element;
        this->init(rows, columns);                         //����rows��columns�о���
        for (int i=0; i<rowsold; i++)                      //����ԭ����Ԫ��
            for(int j=0; j<columnsold; j++)
                this->element[i][j] = temp[i][j];
        
        for (int i=0; i<rowsold; i++)                      //�ͷ�ԭ��̬��ά����ռ�õ��ڴ�ռ�
            delete(temp[i]);
        delete(temp);
    }
}
//���Ͻ̲ĵ�5�£���7����


//����ʵ��5
//��4�����ơ���������ֵ
void Matrix::copy(Matrix &mat)                             //����mat��������Ԫ�ص���ǰ����
{
    for (int i=0; i<mat.rows; i++) 
        for(int j=0; j<mat.columns; j++)
            this->element[i][j] = mat.element[i][j];
}

Matrix::Matrix(Matrix &mat)                                //�������캯�������
{
    this->init(mat.rows, mat.columns);                     //����rows��columns�о���洢�ռ�
    this->copy(mat);                                       //����mat��������Ԫ�ص���ǰ������������������ͬ
}
/*//����
Matrix::Matrix(int rows, int columns, Matrix &mat)         //���ؿ������캯���������ͼ���ã����ݣ�����7.5.2 Floyd�㷨�ã�
{
    this->init(rows, columns);                             //�������rows��columns�д洢�ռ䣬Ԫ��δ����ֵ
    this->copy(mat);                                       //����mat����
}*/

Matrix& Matrix::operator=(Matrix &mat)                     //��������=��ֵ��������Զ�����
{
    if (this->rows < mat.rows || this->columns < mat.columns)//��ֵΪ�������ʱ����Ҫ����
    {
         this->~Matrix();                                  //���������������ͷ�element����ռ�
         this->init(mat.rows, mat.columns);
    }
    for (int i=0; i<this->rows; i++)                       //����mat��������Ԫ�ص���ǰ����
        for(int j=0; j<this->columns; j++)
            this->element[i][j] = mat.element[i][j];
    return *this;                                          //���ص�ǰ��������
}

//ʵ��5����������
bool Matrix::operator==(Matrix &mat)                       //�Ƚ�����ͬ�׾����Ƿ����
{
    if (this->rows!=mat.rows || this->columns!=mat.columns)
        return false;
    
    for (int i=0; i<this->rows; i++)
        for (int j=0; j<this->columns; j++)
             if (this->element[i][j]!=mat.element[i][j])
                 return false;
    return true;
}

void Matrix::operator+=(Matrix &mat)                       //��ǰ������mat������ӣ�*this+=mat
{
    if (this->rows==mat.rows && this->columns==mat.columns)
        for (int i=0; i<mat.rows; i++)
            for (int j=0; j<mat.columns; j++)
                this->element[i][j] += mat.element[i][j];
    else throw invalid_argument("�������������ͬ���������");  //�׳���Ч�����쳣
}

Matrix Matrix::operator+(Matrix &mat)                      //���ص�ǰ������mat��Ӻ�ľ���*this+mat
{
    if (this->rows==mat.rows && this->columns==mat.columns)
    {
        Matrix temp(*this);                                //ִ�����
        temp += mat;
        return temp;                                       //ִ�����
    }
    throw invalid_argument("�������������ͬ���������");  //�׳���Ч�����쳣
}

Matrix Matrix::transpose()                                 //���ص�ǰ�����ת�þ���
{
    Matrix trans(this->columns, this->rows);               //�����վ���
    for (int i=0; i<this->rows; i++)
        for (int j=0; j<this->columns; j++)
            trans.element[j][i]=this->element[i][j]; 
    return trans;                                          //ִ�����
}

bool Matrix::isUpTriangular()                              //�жϵ�ǰ�����Ƿ�Ϊ�����Ǿ���
{
    if (this->rows!=this->columns)
        return false;
    for (int i=0; i<this->rows; i++)
        for (int j=0; j<i; j++)
            if (this->element[i][j]!=0)                    //������Ԫ��ӦΪ0
                return false;
    return true;
}

bool Matrix::isSymmetric()                                //�жϵ�ǰ�����Ƿ�Ϊ�Գƾ���
{
    if (this->rows!=this->columns)
        return false;
    for (int i=0; i<this->rows; i++)
        for (int j=0; j<i; j++)
            if (this->element[i][j]!=this->element[j][i])
                 return false;
    return true;
}


/*
    void fill(int value);                                  //��������Ԫ��ֵΪvalue
    void toTranspose();                                      //����ǰ����ת�ã�����Ҫ�ˣ���ȻҪ�����¾���
û��ʵ������[][]    
//������
   int& operator()(int i,int j)                     //���غ�������()�����
    {
       return this->element[i][j];
    }

int Matrix::saddlePoint()       //���ذ���ֵ
{
}
*/