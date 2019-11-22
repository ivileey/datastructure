//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//3.2.3   �ַ�����

#include <iostream>
using namespace std;
#include <string.h>        //����strlen(s)�󴮳��Ⱥ���
//Լ�����ڱ�֤��ȷǰ���£��ɶ�char*ʹ��string.h�к���

class MyString                                             //�ַ����࣬//����������������࣬���ܱ��̳�
{
  private:                                                 //˽�г�Ա
    char *element;                                         //��̬�ַ�����
    int length;                                            //��������
    int n;                                                 //������
    void init(char *s="", int length=32);                  //��ʼ����������ָ����ֵ������

  public:
    MyString(char *s="", int length=32);                   //���촮����sָ��char*��������lengthָ������
    MyString(char ch);                                     //���촮����chָ���ַ���ֵ
    MyString(MyString &str);                               //�������캯�������
    MyString& operator=(MyString &str);                    //����=��ֵ����������
    MyString& operator=(char *str);                        //֧�ָ�ֵΪ�ַ�������
    ~MyString();                                           //��������

    bool empty();                                          //�жϴ��Ƿ�Ϊ��
    int count();                                           //���ش�����
    char& operator[](int i);                               //�����±�����������õ�i����0�����ַ�
    friend ostream& operator<<(ostream& out, MyString &s); //����<<����������

    bool operator==(MyString &str);                        //����==��������Ƚ������Ƿ����
    bool operator!=(MyString &str);                        //����!=��������Ƚ������Ƿ����
    bool operator<(MyString &str);                         //����<��������Ƚ�������С
    bool operator<=(MyString &str);
    bool operator>(MyString &str);
    bool operator>=(MyString &str);
    void reverse();                                        //����ǰ����ת��Huffman�㷨��

    MyString substring(int i, int len);                    //���شӵ�i���ַ���ʼ����Ϊlen���Ӵ�
    MyString substring(int i);                             //���شӵ�i���ַ���ʼ����β���Ӵ�
    void insert(int i, MyString &str);                     //�ڵ�i���ַ�������str��
    void insert(int i, char ch);                           //����ch��Ϊ��i���ַ�
    void insert(int i, char* str);                         //�ڵ�i���ַ�������str��
    void operator+=(MyString &str);                        //���أ�=��������ڵ�ǰ��֮������str��
    void operator+=(char ch);                              //���أ�=��������ڵ�ǰ��֮������ch�ַ�
    void operator+=(char *str);                            //���أ�=��������ڵ�ǰ��֮������str��
    MyString operator+(MyString &str);                     //���أ�����������ص�ǰ����str���Ӻ�Ĵ�
    void remove(int i, int len);                           //ɾ���ӵ�i���ַ���ʼ����Ϊlen���Ӵ�
    void remove(int i);                                    //ɾ���ӵ�i���ַ���ʼ����β���Ӵ�

    //3.3   ����ģʽƥ��
    int search(MyString &pattern, int start=0);            //���ص�ǰ���д�start��ʼ�׸���ģʽ��patternƥ����Ӵ����
    void removeFirst(MyString &pattern);                   //ɾ�������׸���patternƥ����Ӵ�
    void removeAll(MyString &pattern);                     //ɾ�����а�����������patternƥ����Ӵ�
    void replaceFirst(MyString &pattern, MyString &str);   //�������׸���patternƥ����Ӵ��滻Ϊstr
    void replaceAll(MyString &pattern, MyString &str);     //������������patternƥ����Ӵ��滻Ϊstr

   //ϰ����ϰ3.2
    void trim();                                           //ɾ�������пո�ϰ��.2

    //ʵ��3
    void uppercase();                                      //�����е�Сд��ĸת���ɴ�д��ĸ

  private:
    //3.3   ����ģʽƥ��
    void getNext(int next[]);                              //����ģʽ��pattern�Ľ���next����
};

//1. �ַ����Ļ�������
//��1�����졢����
void MyString::init(char *s, int length)                   //��ʼ������sָ����ֵ��lengthָ����Ĭ�ϣ���������
{
    this->n = strlen(s);                                   //���s�����ȣ�strlen(s)������string.h��
    this->length = (n*2)>length ? (n*2) : length;          //ָ������������ȡn*2��length���ֵ
    this->element = new char[this->length];                //�����ַ�����
    for (int i=0; s[i]!='\0'; i++)                         //����s�ַ�����strcpy(*,*)����
       this->element[i] = s[i]; 
    this->element[this->n] = '\0'; 
}
//���촮����sָ����ֵ������char*���͵��ַ���������lengthָ��������������Ĭ��ֵ
MyString::MyString(char *s, int length) 
{
    this->init(s, length);
//    cout<<s<<endl;
}
MyString::MyString(char ch)                                //���촮����chָ���ַ���ֵ
{
    this->init("");
    this->n = 1;
    this->element[0] = ch; 
    this->element[1] = '\0'; 
}
MyString::MyString(MyString &str)                          //�������캯�������
{
    this->init(str.element);
}
MyString& MyString::operator=(MyString &str)               //����=��ֵ����������
{
    this->~MyString();                                     //���������������ͷ�element����ռ�
    this->init(str.element);                               //ȫ��������������ռ�
    return *this;
}
MyString& MyString::operator=(char *str)                   //����=��ֵ����������
{
    this->~MyString();                                     //���������������ͷ�element����ռ�
    this->init(str);                                       //ȫ��������������ռ�
    return *this;
}

MyString::~MyString()                                      //��������
{
//    cout<<"MyString����"<<*this<<"��n="<<count<<"��length="<<length<<endl;
    delete []this->element;
}

//��˼����3-1��
//��2���пա������ȡ�����ʹ�ȡ�ַ�
bool MyString::empty()                                   //�жϴ��Ƿ�Ϊ��
{
    return this->n==0;
}
int MyString::count()                                      //���ش�����
{
    return this->n;
}

//�����±�����������õ�i��0��i<n�����ַ�����i<0��i��n�����׳��쳣
char& MyString::operator[](int i)
{
    if (i>=0 && i<this->n)
        return this->element[i];                           //����Ԫ������
    throw out_of_range("����iָ��Ԫ����ų�����Χ");       //�׳�C++ STL��ΧԽ���쳣
}

ostream& operator<<(ostream& out, MyString &str)           //����<<����������
{
    out<<"\""<<str.element<<"\"";                          //�����֧�����ַ�ָ����ʽ����ַ�����
    return out;
}

//��ϰ3.1��  
//��6����ϵ���㣬char֧��==��!=��>��>=��<��<=����
bool MyString::operator==(MyString &str)                   //����==��������Ƚ��������Ƿ����
{
    if (this==&str)                                        //ָ��Ƚϣ���������������ͬһ��ʵ��ʱ
        return true;
    if (this->n != str.n)                                  //���¿������������Ƚ����߳����Ƿ���ȣ����Ƚ���������
        return false;
    for (int i=0; i<this->n; i++)                          //�Ƚ��������������ַ��Ƿ��Ӧ���
        if (this->element[i] != str.element[i])
            return false;
    return true;
}
bool MyString::operator!=(MyString &str)                   //����!=��������Ƚ��������Ƿ����
{
    return !(*this==str);
}

bool MyString::operator<(MyString &str)                    //����<��������Ƚ���������С
{
    if (this==&str)                                        //ָ��Ƚϣ���������������ͬһ��ʵ��ʱ
        return false;
    int i=0;
    while (i<this->n && i<str.n)
        if (this->element[i]==str.element[i])              //��Ӧ�ַ����ʱ�����Ƚ�
            i++;
        else
            return this->element[i]<str.element[i];        //���׸�������ַ�ȷ�������Ĵ�С
    return this->n < str.n;                        //����ǰ�����ַ���Ӧ��ȣ���Ҫ�ȳ��ȡ�*this���϶�ʱ����1���������ȳ�
}   

bool MyString::operator<=(MyString &str)                   //����<=��������Ƚ���������С
{
    if (this==&str)                                        //ָ��Ƚϣ���������������ͬһ��ʵ��ʱ
        return true;
    int i=0;
    while (i<this->n && i<str.n)
        if (this->element[i]==str.element[i])                    //��Ӧ�ַ����ʱ�����Ƚ�
            i++;
        else
            return this->element[i]<str.element[i];
    return this->n <= str.n;                       //�����ȳ���*this���϶�ʱ����1
}   

bool MyString::operator>(MyString &str)                    //����>��������Ƚ��������Ĵ�С
{
    return !(*this <= str);
}

bool MyString::operator>=(MyString &str)                   //����>=��������Ƚ��������Ĵ�С
{
    return !(*this < str);
}

void MyString::reverse()                                   //����ǰ����ת��Huffman�㷨��
{
    for (int i=0; i<n/2; i++)
    {
        char temp = this->element[i];                      //�����ַ�
        this->element[i] = element[n-1-i]; 
        this->element[n-1-i] = temp;
    }
}

//2.  ���Ӵ��Ĳ���
//��1�����Ӵ�
//���شӵ�i��0��i<n�����ַ���ʼ����Ϊlen��>=0�����Ӵ���len�ݴ���i+len>������n��
//���Ƶ���β����i<0��i��n����len<0���׳��쳣
MyString MyString::substring(int i, int len)
{
    if (i>=0 && i<n && len>=0)
    {
        if (len>n-i)                                       //len�ݴ�
            len=n-i;                                       //i+len��ൽ��β
        MyString sub;                                      //�����մ�����
        sub.n = len;                                       //��len=0���򷵻ؿմ�
        for (int j=0; j<len; j++)
            sub.element[j] = this->element[i+j];
        sub.element[len]='\0';
        return sub;                                        //ִ��MyString�Ŀ������캯��
    }
    else
        throw out_of_range("����iָ���ַ���Ż�len������Χ");//�׳�C++ STL��ΧԽ���쳣
}
MyString MyString::substring(int i)                        //���شӵ�i���ַ���ʼ����β���Ӵ�
{
    return substring(i, this->n-i+1);
}

//��2�����봮
//�ڵ�i����0�����ַ�������str����i�ݴ���i<0����������ǰ����i��n�����������
void MyString::insert(int i, MyString &str) 
{
    if (str.n==0)  return;                                 //��strΪ�մ����򲻲���
    if (i<0)  i=0;                                         //����λ��i�ݴ���ǰ
    if (i>n)  i=n;                                         //���
    char *temp = this->element;
    if (this->length <= this->n+str.n)                     //����ǰ�����ַ�����ռ䲻�㣬����������
    {
        this->length = (this->n+str.n+1)*2;                //ָ����������
        this->element = new char[this->length];            //���������ַ�����ռ�
        for (int j=0; j<i; j++)                            //���Ƶ�ǰ��ǰi-1���ַ�
            this->element[j] = temp[j];
    }
    for (int j=this->n; j>=i; j--)                         //��i��ʼ����β���Ӵ�������'\0'������ƶ��������ǴӺ���ǰ
        this->element[j+str.n] = temp[j];                  //�ƶ������ǲ��봮����
    if (temp!=this->element)
        delete[] temp;                                     //�ͷ�ԭ����ռ�
    for (int j=0; j<str.n; j++)                            //����str��
        this->element[i+j] = str.element[j];
    this->n += str.n;
}
void MyString::insert(int i, char ch)                      //����ch��Ϊ��i���ַ���i���Խ���ݴ�
{
    this->insert(i, MyString(ch));
}
void MyString::insert(int i, char* str)                    //�ڵ�i���ַ�������str��������i���Խ���ݴ�
{
    this->insert(i, MyString(str));
}

//��˼����3-2�����Ӵ�
//����+=��������ڵ�ǰ��֮������str��*this += str���ı䵱ǰ��
void MyString::operator+=(MyString &str)
{
    this->insert(this->n, str);
}
void MyString::operator+=(char ch)                      //����ch�ַ�
{
    insert(this->n, MyString(ch));
}
void MyString::operator+=(char* str)                    //����str����ϰ��3
{
    insert(this->n, MyString(str));
}

//����+����������������������´���result=*this+str�����ı䵱ǰ��*this
MyString MyString::operator+(MyString &str)
{
    MyString result(*this);                                //���Ƶ�ǰ��*this��ִ��MyString�Ŀ������캯��
    result.insert(this->n, str);
    return result;                                         //���ش�����ִ��MyString�Ŀ������캯��
}

//��3�� ɾ���Ӵ�
//ɾ���ӵ�i��0��i<n�����ַ���ʼ����Ϊlen��>0�����Ӵ�����i��len������Ч���򲻲�����
//len�ݴ���i+len>������n����ɾ������β
void MyString::remove(int i, int len)
{
    if (i<0 || i>=this->n || len<0)
        return;
    if (len>n-i)                                           //len�ݴ���i+len>������n����ɾ������β
        len = n-i;
    for (int j=i+len; j<=n; j++)                           //��i+len��ʼ����β���Ӵ�������'\0'����ǰ�ƶ�len���ַ�
        this->element[j-len] = element[j];
    this->n -= len;
}
void MyString::remove(int i)                               //ɾ���ӵ�i����0�����ַ���ʼ����β���Ӵ�
{
    remove(i, this->n-i);
}


//3.3 ����ģʽƥ��
//3.3.1   Brute-Force�㷨

//�����ڵ�ǰ����start��0��start<n����ʼ�׸���ģʽ��patternƥ����Ӵ���ţ�ƥ��ʧ��ʱ���أ�1
/*int MyString::search(MyString &pattern, int start)
{
    int i=start, j=0;                                      //i��j�ֱ�ΪĿ�괮��ģʽ����ǰ�ַ��±�
    int len=0;                                             //lenͳ���ַ��Ƚϴ���
    while (i<this->n)
    {
        len++;
        if (this->element[i]==pattern.element[j])          //����ǰ���ַ���ȣ�������ȽϺ����ַ�
        {   i++;
            j++;
        }
        else                                               //����i��j���ݣ�������һ��ƥ��
        {   i=i-j+1;                                       //Ŀ�괮�±�i�˻ص��¸�ƥ���Ӵ����
            j=0;                                           //ģʽ���±�j�˻ص�0
        }
        if (j==pattern.n)                                  //һ��ƥ�������ƥ��ɹ�
            return i-j;                                    //����ƥ���Ӵ����
    }
//    cout<<"\n�ַ��Ƚϴ�����"<<len<<endl;
    return -1;                                             //ƥ��ʧ��ʱ���أ�1
}*/

//2.  ģʽƥ��Ӧ��
//��1��ɾ���Ӵ�
void MyString::removeFirst(MyString &pattern)              //ɾ�������׸���patternƥ����Ӵ�
{
    remove(search(pattern), pattern.n);                     //����remove(i,n)����
}
/*
void MyString::removeAll(MyString &pattern)                //ɾ������������patternƥ����Ӵ�������ƶ��㷨
{
    int start=0;
    do
    {
        start=search(pattern, start);
        remove(start, pattern.n);                          //����remove(i,n)����
    } while (start!=-1);
}*/

//ɾ������������patternƥ����Ӵ����Ľ����ַ��ƶ�һ���㷨
void MyString::removeAll(MyString &pattern)
{
    int i=this->search(pattern), k=i;                       //iΪ�׸���patternƥ���Ӵ����
    while (k!=-1)                                          //ÿѭ��һ�Σ�ɾ��һ��ƥ���Ӵ�
    {
        int j=k+pattern.n;                                 //jΪƥ���Ӵ�֮����ַ��±�
        k=this->search(pattern, j);                         //kΪ��j��ʼ���ҵ��¸�ƥ���Ӵ����
        while (k>0 && j<k || k<0 && j<=n)                  //��j��k-1֮��������ַ���ǰ�ƶ���i��ʼ��
            this->element[i++] = element[j++];
//        cout<<*this<<endl;
    }
    if (i!=-1)
        this->n = i-1;                                     //����Ŀ�괮����
}

//��2���滻�Ӵ�
//�������׸���patternƥ����Ӵ��滻Ϊstr
void MyString::replaceFirst(MyString &pattern, MyString &str) 
{
    int start=search(pattern);  
    if (start!=-1)
    {
        remove(start, pattern.n);
        insert(start, str);
    }
}
//������������patternƥ����Ӵ��滻Ϊstr
void MyString::replaceAll(MyString &pattern, MyString &str)
{
    int start=search(pattern);
    while (start!=-1)
    {
        remove(start, pattern.n);
        insert(start, str);
        start = search(pattern, start+str.n);         //���滻�Ӵ�����һ���ַ���ʼ�ٴβ���ƥ���Ӵ�
    }
}

//3.3.2   KMPģʽƥ���㷨
//�����ڵ�ǰ����start��0��start<n����ʼ�׸���ģʽ��patternƥ����Ӵ���ţ�ƥ��ʧ��ʱ���أ�1
int MyString::search(MyString &pattern, int start)
{
    int *next = new int[pattern.n];
    pattern.getNext(next);                                 //���ģʽ����next����
//        cout<<"next[]: ";
//        for (int h=0; h<pattern.n; h++)
//            cout<<next[h]<<"  ";

    int i=start, j=0;                                      //i��jΪĿ�괮��ģʽ����ǰ�ַ����
    int len=0;                                             //lenͳ���ַ��Ƚϴ���
    while (i<this->n)
    {
        if (j!=-1) len++;
//            cout<<"\ni="<<i<<"  j="<<j<<"  n="<<n;
        if (j==-1 || this->element[i]==pattern.element[j])
        {
            i++;                                           //�����ȽϺ����ַ�
            j++;
        }
        else
            j=next[j];                                     //ȷ��ģʽ���´αȽ��ַ����
        if (j==pattern.n)                                  //һ�˱ȽϽ�����ƥ��ɹ�
            return i-j;                                    //����ƥ����Ӵ����
    }
//        cout<<"\ncount="<<n<<endl;
    return -1;
}

/*
//���ģʽ��pattern��next���飨δ�Ľ�������ǰ��*thisΪpattern
void MyString::getNext(int next[])
{
    next[0]=-1;
    int j=0, k=-1;
    while (j<this->n-1)                                    //next���鳤��Ϊpattern.n
        if (k==-1 || element[j]==element[k])
        {
            j++;
            k++;
            next[j]=k;                                     //�д��Ľ���Ҳ��next[++j]=++k;
//            cout<<"j="<<j<<", k="<<k<<", next["<<j<<"]="<<k<<endl;
        }
        else
        {
//            cout<<"k=next["<<k<<"]=";
            k=next[k];
//            cout<<k<<endl;
        }
}*/

//���ģʽ��pattern��next���飨�Ľ�������ǰ��*thisΪpattern
void MyString::getNext(int next[])
{
    next[0]=-1;
    int j=0, k=-1;
    while (j<this->n-1)                                    //next���鳤��Ϊpattern.n
        if (k==-1 || element[j]==element[k])
        {
            j++;
            k++;
            if (element[j]!=element[k])                    //�Ľ�֮��
                next[j]=k;
            else
                next[j]=next[k]; 
        }
        else
            k=next[k];
}

//ϰ�����3��ϰ3.2
void MyString::trim()                                      //ɾ���������е����пո��ַ���O(n)
{
    int i=0;
    while (element[i]!=' ' && element[i]!='\0')            //Ѱ�ҵ�1���ո�
        i++;                                               //i��ס��1���ո��±�
    for (int j=i+1; element[j]!='\0'; j++)
        if (element[j]!=' ')
            element[i++] = element[j];                     //�ǿո��ַ���ǰ�ƶ����ո��ַ�λ��
    n = i;
    element[n] = '\0';
//    element[i] = element[j];                             //Ҳ��
}

//ʵ��3
void MyString::uppercase()                                 //�����е�Сд��ĸת���ɴ�д��ĸ
{
    for (int i=0; i<n; i++)
        if (element[i]>='a' && element[i]<='z')            //Сд��ĸ
            element[i] -= 'a'-'A';                         //ת���ɴ�д��ĸ
}