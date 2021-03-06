#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
using namespace std;
//auto c++11特性
void test_string(void)
{
//	string s1 ; //正确 当把string对象和字符面值及字符串面值混在一条语句中使用时，必须确保+的两侧的运算对象至少有一个是string
//	string s4 = "hello" + ", " + s1; //错误
//	string s5 =  "hello "+s1  + ", "; //改一下顺序，s1放前头，正确了，注意理解=号右边的运算顺序
//	string s6 = s1 + "hello " + "afafa "; //改一下顺序，s1放前头，正确了，注意理解=号右边的运算顺序
    string s1;//初始化字符串，空字符串
    string s2 = s1; //拷贝初始化，深拷贝字符串
    string s3 = "I am Yasuo"; //直接初始化，s3存了字符串
    string s4(10, 'a'); //s4存的字符串是aaaaaaaaaa
    string s5(s4); //拷贝初始化，深拷贝字符串
    string s6("I am adfa"); //直接初始化
    string s7 = string(6, 'c'); //拷贝初始化，cccccc

    //string的各种操作
    string s8 = s3 + s6;//将两个字符串合并成一个
    s3 = s6;//用一个字符串来替代另一个字符串的对用元素
	cout << "input..." << endl;

    cin >> s1;//cin读入字符串时，遇到空白就停止读取
    
	string str1;
	getline(cin, str1);
	cout <<"getline:"<< str1 << endl;

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;
    cout << s8 << endl;
    cout << "s7 size = " << s7.size() << endl; //字符串长度，不包括结束符
    cout << (s2.empty() ? "This string is empty" : "This string is not empty") << endl;
	cout << (s4.empty() ? "This string is empty" : "This string is not empty") << endl;
	cout << (s5.empty() ? "This string is empty" : "This string is not empty") << endl;
	for (int i = 0; i < s3.size(); i++)
	{
	    cout << s3[i] << endl;
	    s3[i] = 's';
	}
	cout << s3 << endl;
	
	string str("hi sysu");
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
	    cout << *it << endl;
	}

//	for (string::const_iterator it = str2.begin(); it != str2.end(); it++)
//	{
//		cout << *it << endl;
//		*it = 'l'; //这是错误的，不能写
//	}
	string sq("heoolo sdaa ss");
	cout << sq.find("aa", 0) << endl; //返回的是子串位置。第二个参数是查找的起始位置，如果找不到，就返回string::npos
	if (sq.find("aa1", 0) == string::npos)
	{
		cout << "找不到该子串！" << endl;
	}
}
template <typename T>
void showvector(vector<T> v)
{
    for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)//typename 要加 不然报错
    {
        cout << *it;
    }
    cout << endl;
}
void test_vector(void)
{
	#if 1
//	CBox box1 ={78.0,24.0,18.0}; 改成 CBox box1 (78.0,24.0,18.0)
//	或者开启编译选项 -std=c++11
	
	vector<int> v1;//如果vector的元素类型是int，默认初始化为0；如果vector元素类型为string，则默认初始化为空字符串。
//	vector<father> v2;
	vector<string> v3;
	vector<vector<int> > v4;  //注意空格。这里相当于二维数组int v4[n][n];
	vector<int> v5 = {1,2,3,4,5}; //v5  {1,2,3,4,5};列表初始化,注意使用的是花括号 c98不支持
	vector<string> v6 = {"hi","my","name","is","lee"};// c98不支持 所以加上-std=c++11
	vector<int> v7(5, -1); //初始化为-1,-1,-1,-1,-1。第一个参数是数目，第二个参数是要初始化的值
	vector<string> v8(3, "hi");
	vector<int> v9(10); //默认初始化为0
	vector<int> v10(4); //默认初始化为空字符串

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);//被加在数组尾部
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << endl;
		v1[i] = 100;//只能对已存在的元素进行赋值或者修改操作
		cout << v1[i] << endl;
	}
//	vector<string> v6 = { "hi","my","name","is","lee" };
	cout << "v6_test"<<endl;

	for (vector<string>::iterator iter = v6.begin(); iter != v6.end(); iter++)
	{
		cout << *iter << endl;
		//下面两种方法都行
//		cout << (*iter).empty() << endl;
		cout << iter->empty() << endl; 
	}
	cout << "v6_test2"<<endl;
	for (vector<string>::reverse_iterator iter = v6.rbegin(); iter != v6.rend(); iter++)
	{
		cout << *iter << endl;
	}
	cout << "v6_test3"<<endl;
    v6.resize(3);  //重新调整vector容量大小
    showvector(v6);
	cout << "v5_test"<<endl;
//    vector<int> v5 = { 1,2,3,4,5 }; //列表初始化,注意使用的是花括号
    cout << v5.front() << endl; //访问第一个元素
    cout << v5.back() << endl; //访问最后一个元素

    showvector(v5);
    v5.pop_back(); //删除最后一个元素
    showvector(v5);
    v5.push_back(6); //加入一个元素并把它放在最后
    showvector(v5);
    v5.insert(v5.begin()+1,9); //在第二个位置插入新元素
    showvector(v5);
    v5.erase(v5.begin() + 3);  //删除第四个元素
    showvector(v5);
    v5.insert(v5.begin() + 1, 7,8); //连续插入7个8
    showvector(v5);
    v5.clear(); //清除所有内容
    showvector(v5);
#endif

}
template <typename T>
void showset(set<T> v)
{
    for (typename std::set<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}
void test_set()//它跟vector的唯一区别就是，set里面的元素是有序的且唯一的，只要你往set里添加元素，它就会自动排序
{
   set<int> s1{9,8,1,2,3,4,5,5,5,6,7,7 }; //自动排序，从小到大,剔除相同项 // c98不支持 所以加上-std=c++11
    showset(s1);
    set<string> s2{ "hello","sysy","school","hello" }; //字典序排序
    showset(s2);
    s1.insert(9); //有这个值了，do nothing
    showset(s1);
    s2.insert("aaa"); //没有这个字符串，添加并且排序
    showset(s2);
}
/*
list是一个双向链表，而单链表对应的容器则是foward_list。
list即双向链表的优点是插入和删除元素都比较快捷，缺点是不能随机访问元素
*/
template <typename T>
void showlist(list<T> v)
{
    for (typename std::list<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}
void test_list(void)
{
	list<int> l1{ 1,2,3,4,9,5,6,10,7 };
    showlist(l1);
	l1.sort();
	showlist(l1);
    list<double> l2;
	showlist(l2);
    list<char> l3(10);
	showlist(l3);
    list<int> l4(5, 10); //将元素都初始化为10
    showlist(l4);
}
void showmap(map<string, int> v)
{
    for (map<string, int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->first << "  " << it->second << endl;  //注意用法，不是用*it来访问了。first表示的是key，second存的是value
    }
    cout << endl;
}
void test_map(void)
{
    map<string, int> m1; //<>里的第一个参数表示key的类型,第二个参数表示value的类型
    m1["Kobe"] = 100;
    m1["James"] = 99;
    m1["Curry"] = 98;

    string s("Jordan");
    m1[s] = 90;

    cout << m1["Kobe"] << endl;
    cout << m1["Jordan"] << endl;
    cout << m1["Durant"] << endl; //不存在这个key，就显示0

    m1.erase("Curry");//通过关键字来删除
    showmap(m1);
    m1.insert(pair<string, int>("Harris", 89)); //也可以通过insert函数来实现增加元素
    showmap(m1);

	if (m1.count("Lee"))
	{
	    cout << "Lee is in m1!" << endl;
	}
	else
	{
	    cout << "Lee do not exist!" << endl;
	}
	
	m1.clear(); //清空全部
}
int main()
{
	
//	test_string();
//	test_vector();
//	test_set();
//	test_list();
	test_map();
//    system("pause");
    return 0;
}

                                                                                                                             
     
              