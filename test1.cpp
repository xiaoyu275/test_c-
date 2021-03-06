#if 0
#include <iostream>
using namespace std;
//void (*signal (int sig, void (*func)(int)))(int); 
template <typename elemType>
class list
{
public :
    virtual void clear() = 0;
    virtual int length()const = 0;
    virtual void insert(int i, const elemType &x) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const elemType &x)const = 0;
    virtual elemType visit(int i)const = 0;
    virtual ~list(){}
};

template <typename elemType>
class seqList : public list<elemType>
{
private :
    elemType *data;                          
    int      currentLength;                
    int      maxSize;                           
    void     doubleSpace();                    

public :
    
    seqList(int initSize = 10);
    ~seqList() {;}//delete [] data;
    void clear() {currentLength = 0;}
    int length()const {return currentLength;}
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x)const;
    elemType visit(int i)const {return data[i];}
    void traverse()const;
};

template <typename elemType>
void seqList<elemType> :: doubleSpace()                 //扩容
{
   ;  
}

template <typename elemType>
seqList<elemType> :: seqList(int initSize)              //顺序表初始化
{
    ;
}

template <typename elemType>                            //在第i个位置插入元素
void seqList<elemType> :: insert(int i, const elemType &x)
{
   ;
}

template <typename elemType>
void seqList<elemType> :: remove(int i)
{
   ;
}

template <typename elemType>
int seqList<elemType> :: search(const elemType &x)const
{
    ;
}

template <typename elemType>
void seqList<elemType> :: traverse()const
{
    ;
}

int main(void)
{
    seqList<int> l;
    cout << "currentLength : " << l.length() << endl;
//    cout << "maxSize : " << l.maxSize << endl;
    l.insert(1, 1);
    l.insert(1, 2);
    l.insert(1, 3);
    cout << "currentLength : " << l.length() << endl;
//    cout << "maxSize : " << l.maxSize << endl;
    l.traverse();
    l.remove(1);
    l.traverse();
	return 0;
}
#elif 0
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
 
using namespace std;
 
template <class T>
class Stack { 
  private: 
    vector<T> elems;     // 元素 
 
  public: 
    void push(T const&);  // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const{       // 如果为空则返回真。
        return elems.empty(); 
    } 
}; 
 
template <class T>
void Stack<T>::push (T const& elem) 
{ 
    // 追加传入元素的副本
    elems.push_back(elem);    
} 
 
template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    // 删除最后一个元素
    elems.pop_back();         
} 
 
template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    // 返回最后一个元素的副本 
    return elems.back();      
} 
 /*
7
hello
Exception: Stack<>::pop(): empty stack
*/
int main() 
{ 
    try { 
        Stack<int>         intStack;  // int 类型的栈 
        Stack<string> stringStack;    // string 类型的栈 
 
        // 操作 int 类型的栈 
        intStack.push(7); 
        cout << intStack.top() <<endl; 
 
        // 操作 string 类型的栈 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}
#else
#include <iostream>
#include <string>
 
using namespace std;
 
template <typename T>
inline T const& Max (T const& a, T const& b) //& a是引用，对象是传入的参数 。不用&则会增加堆栈段的内存开销？
{ 
    return a < b ? b:a; 
} 
int main ()
{
 
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl; 
 
    double f1 = 13.5; 
    double f2 = 20.7; 
    cout << "Max(f1, f2): " << Max(f1, f2) << endl; 
 
    string s1 = "Hello"; 
    string s2 = "World"; 
    cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
 
   return 0;
}
#endif

                     