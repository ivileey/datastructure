//�����ݽṹ��C++�棩����3�棩ϰ������ʵ��ָ���� ���ߣ�Ҷ����
//ϰ1.1 ������

#include <iostream>
using namespace std;
class Complex                                              //������
{
  private:
    double real, imag;                                     //ʵ�����鲿imaginary

  public:
    Complex(double real=0,double imag=0);                  //���캯�����ṩ�޲ι��캯��
    Complex(const Complex&);                               //Ĭ�Ͽ������캯��
    ~Complex();                                            //Ĭ����������

    void set(double real, double imag);                    //���ø�������ĳ�Ա����
    friend ostream& operator<<(ostream&, const Complex&);  //��������������
    Complex& operator=(const Complex&);                    //Ĭ�ϸ�ֵ����
    Complex& operator+=(const Complex&);                   //�Ӹ�ֵ
    Complex operator+(const Complex&) const;               //������ӣ������´�������
    bool operator==(const Complex&) const;                 //�Ƚϵ�ǰ���������c�Ƿ����
    bool operator!=(const Complex&) const;                 //�Ƚ϶����Ƿ����
};

Complex::Complex(double real, double imag)                 //���캯��������������ȱʡ
{
    this->set(real, imag);
//    this->real = real;
//    this->imag = imag;
}
Complex::~Complex()                                        //Ĭ����������
{
    cout<<"����~Complex() "<<*this;
}

void Complex::set(double real, double imag)                //���ø�������ĳ�Ա����
{
    this->real = real;
    this->imag = imag;
}

Complex& Complex::operator=(const Complex &c)              //Ĭ�ϸ�ֵ���㣬*this=c
{
    this->set(c.real, c.imag);
    return *this;
}
Complex::Complex(const Complex &c)                         //Ĭ�Ͽ������캯�������ƶ�������
{
//    this->set(c.real, c.imag);                 //Ҳ��
//    this->real = c.real;                       //Ҳ��
//    this->imag = c.imag;
	*this=c;                                               //ִ�и�ֵ����
}

ostream& operator<<(ostream &out, const Complex &c)        //����������������cout<<c
{
    out<<"("<<c.real<<"+"<<c.imag<<"i)";
    return out;
}

Complex& Complex::operator+=(const Complex &c)             //�Ӹ�ֵ��*this+=c���ı䵱ǰ����-=�㷨����
{
 //   this->real += c.real;
 //   this->imag += c.imag;
    this->set(this->real+c.real, this->imag+c.imag);
    return *this;
}
/*
Complex Complex::operator+(const Complex &c) const         //������ӣ�*this+c�������´�������û�иı䵱ǰ����
{ 
    return Complex(this->real+c.real, this->imag+c.imag);  //���ض���û��ִ�п������캯��
//    return new Complex(this->real+c.real, this->imag+c.imag); //��������ܽ����� 1 �ӡ�Complex *��ת��Ϊ��double��
}*/
Complex Complex::operator+(const Complex &c) const         //������ӣ�*this+c�������������ض��󣬵���+=�㷨
{ 
    Complex temp(*this);                                   //ִ�п������캯��
    temp+=c;
    return temp;                                           //���ض�����ִ�п������캯�������ƾֲ�����������temp
}

bool Complex::operator==(const Complex &c) const           //�Ƚϵ�ǰ���������c�Ƿ���ȣ�*this==c
{
    return this->real==c.real && this->imag==c.imag;
}
bool Complex::operator!=(const Complex &c) const           //�Ƚϵ�ǰ���������c�Ƿ���ȣ�*this!=c
{
    return !(*this==c);
}

/*
bool Complex::operator==(const Complex &c) const           //�Ƚϵ�ǰ���������c�Ƿ���ȣ�*this==c
{
    return this==&c                                        //��������������ͬһ��ʵ��ʱ
           || this->real==c.real && this->imag==c.imag;
}*/