//�����ݽṹ��C++�棩����3�棩�� ���ߣ�Ҷ����
//3.3   ����ģʽƥ��

#include "MyString.h"                             //�ַ�����

int main() 
{
    //3.3.1   Brute-Force�㷨
//    MyString target("ababdabcd"), pattern("abc");          //C++��3��ͼ3.8��ƥ��
//    MyString target("ababdabc"), pattern("abc");         //C++��3��ͼ3.8��ƥ��
//    MyString target("ababdacab"), pattern("abc");        //C++��3��ͼ3.8����ƥ��
//    MyString target("abbabaaba"), pattern("aba");
//    MyString target("aaaaaa"), pattern("aab");
//    MyString target("aaabaaab"), pattern("aaaa");        //ϰ����ͼ3.2
//    cout<<target<<".search("<<pattern<<")="<<target.search(pattern)<<endl;

/*    //ɾ���Ӵ�
    MyString target("ababccdefabcabcgh"), pattern("abc"),target2(target);      //C++��3��ͼ3.9��ƥ��
//    MyString target("ababccdefabcabcgh"), pattern("ac"),target2(target);       //û��ƥ���Ӵ����򲻲���������remove(int i, int n)�����׳��쳣
//    MyString target("aaa"), pattern("a"),target2(target);
//    MyString target(""), pattern("a"),target2(target);
    cout<<target<<".removeFirst("<<pattern<<")=";
    target.removeFirst(pattern);
    cout<<target<<endl;
    cout<<target2<<".removeAll("<<pattern<<")=";
    target2.removeAll(pattern);
    cout<<target2<<endl;

    //�滻�Ӵ�
/*    MyString target("ababccdefabcabcgh"), pattern("abc"),replacement("wxyz"); //C++��3��ͼ3.9��ƥ��
//    MyString target("abbabaabaabac"), pattern("aba"), replacement("wxyz");
//    MyString target("aaa"), pattern("a"), replacement("aaa");
    cout<<target<<".replaceFirst("<<pattern<<", "<<replacement<<")=";
    target.replaceFirst(pattern, replacement);
    cout<<target<<endl;
    cout<<target<<".replaceAll("<<pattern<<", "<<replacement<<")=";
    target.replaceAll(pattern, replacement);
    cout<<target<<endl;
*/

    //3.3.2 KMP
//    MyString target="abdabcabbabcabc", pattern="abcabcaad";  //ͼ3.11��ִ��MyString(char *str)���캯��
//    MyString target="aaaaaba", pattern="aabaabc";                //����
//    MyString target="aaaaaaaaaba", pattern="abcabcaaa";                //"abcabcaaa" ϰ3-9
//    MyString target="aaaaaaaaaaabdabcabbabcabc", pattern="abcabdabcabcaa";
//    MyString target="aaaaaaaaaaabdabcabbabcabc", pattern="aaaabaaabc";
//    cout<<target<<".index("<<pattern<<")="<<target.index(pattern)<<endl;
//    cout<<target<<".index("<<pattern<<")="<<target.index("aab")<<endl;


    //2011��ϰ���� ϰ3.3  2012-7-27
/*    //ɾ���Ӵ�
    MyString target("ababccdefabcabcgh"), pattern("abc");   //ϰͼ3-3
//    MyString target="aaaababaaabaab", pattern="aaba";       //ɾ��������"aaaababaaabaab".removeAll("aaba")="aabaab"
    cout<<target<<".removeAll("<<pattern<<")=";
    target.removeAll(pattern);
    cout<<target<<"��target.length()="<<target.length()<<endl;

    //�滻�Ӵ� 
//    MyString target("aabab"), pattern("a"), replacement("aba");   //�滻������"aabab".replaceAll("a", "aba")="abaabababab"
//    MyString target("aabcabcdbcd"), pattern("abc"), replacement("abcabc");   //�滻������"aabcabcdbcd".replaceAll("abc", "abcabc")="aabcabcabcabcdbcd"
/*    MyString target("aabcabcdbcd"), pattern("abc"), replacement("xyz");   //�滻������"aabcabcdbcd".replaceAll("abc", "xyz")="axyzxyzdbcd"
    cout<<target<<".replaceAll("<<pattern<<", "<<replacement<<")=";
    target.replaceAll(pattern, replacement);
    cout<<target<<endl;    */                         

    system("pause");
    return 0;
}

/*
�������н�����£�
//BF
count=8
"abbabaaba".index("aba")=3

count=12
"aaaaab".index("aab")=3

count=12
"aaaaaa".index("aab")=-1                       //�������Ƚ�m*(n-m+1)=12�Σ�O(n*m)

count=3
"aaaaaa".index("aaa")=0                        //���������Ƚ�3��


//�滻�Ӵ�
target="abbabaabaabac"                         
target.replace("aba", "xy"),    target="abbxyabaabac"
target.replaceAll("aba", "xy"), target="abbxyxyxyc"
  
target="aaa"                         
target.replaceAll("a", "ab"),   target="ababab" 
  
//ɾ���Ӵ�
target="abbabaabaxyabac"                         
target.remove("aba"),    target="abbabaxyabac"
target.removeAll("aba"), target="abbxyc"

//KMP
next[]:  -1 0 0 -1 0 0 
count=17
"abdabcabbabcabc".indexOf("abcabc")=9            //ͼ4.11

next[]:  -1 -1 1 
count=9
"aaaaab".indexOf("aab")=3;                       //������O(n+m)

*/

/*
KMP.index("aabcbabcaabcaababc", "abcaababc")=9   //����Т��
nextk[]: -1 0 0 0 1 1 2 1 2 
next[]:  -1 0 0 -1 1 0 2 0 0 
KMP.count=20

KMP.index("aaabaaaab", "aaaab")=4                //��ε��
nextk[]: -1 0 1 2 3 
next[]:  -1 -1 -1 -1 3 
KMP.count=9

KMP.index("aabaaab", "aaab")=3
nextk[]: -1 0 1 2 
next[]:  -1 -1 -1 2 
KMP.count=7

KMP.index("abbabaaba", "aba")=3                 //BF����
nextk[]: -1 0 0 
next[]:  -1 0 -1 
KMP.count=6

*/
