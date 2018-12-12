#include <iostream>
 
using namespace std;
//using std::cout;
//using namespace namespace_name1;
//using namespace namespace_name1::namespace_name2;
 // 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}
namespace namespace_name1 {
   // 代码声明
   namespace namespace_name2 {
      // 代码声明
   }
}
class Box
{
   public:
      double length;         // 长度
      double breadth;        // 宽度
      double height;         // 高度
      static int objectCount;
 //构造函数 第一次初始化
 	Box(void){
	 	length=1;
		breadth=1;
		height=1;
		width=2;
		private_test=3;
		objectCount++; // 每次创建对象时增加 1
		 cout << "Box_0 Object is being created" << endl;
	}
	      // 构造函数定义
  Box(double l, double b, double h)
  {
     cout <<"Constructor called." << endl;
     length = l;
     breadth = b;
     height = h;
  }
	Box(double i);
	Box( const Box &obj); 	 // 拷贝构造函数
	~Box();
	  int compare(Box box)//this use
      {
       //  return this->getVolume() > box.getVolume();
      }
	   static int getCount()
      {
         return objectCount;
      }
      // 重载 + 运算符，用于把两个 Box 对象相加
      Box operator+(const Box& b)// 如果不是类成员函数，则两个函数入口参数Box operator+(const Box&, const Box&);
      {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }      // 成员函数声明
      double getVolume(void);
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );
	  void display1(void){
		cout <<"Box_display:"<<length <<breadth<<height<<width<<private_test<<*ptr<<endl;
	  }
	  void display2(void);
	  
	  virtual getVolume2(void){//基类中使用virtual,否则使用继承子类函数也是调用基类的函数
	  	cout << "BOX getVolume2:"<<length * breadth * height<<endl;
	  }
	  //virtual int xx() = 0;//= 0 告诉编译器，函数没有主体，该虚函数是纯虚函数
	 // virtual int getVolume3() = 0;//抽象类定义一个接口，具体由子类实现  报错待解决
	  
  protected:
      double width;
  private:
  		double private_test;
		int *ptr;
};
//多继承 ，分隔即可 // 派生类
class SmallBox:private Box // SmallBox 是派生类 默认是 private 继承 struct 中默认 public 继承：3#6#9#
{
   public:
   	SmallBox(double i){
		Box();//4#5#
		height=i;	
		width=i;//基类中的非私有成员都称为子类的私有成员private Box
		//private_test=i;错误，基类的private成员不能被派生类访问private Box。
		 cout << "SmallBox_i Object is being created" << endl;
	}
      void setSmallWidth( double wid );
      double getSmallWidth( void );
	  getVolume2(void){//派生类中不使用virtual
	  	cout << "SmallBox getVolume2:"<<length * breadth * height<<endl;
	  }
//	  int getVolume3(void){//派生类中不使用virtual
//	  	cout << "SmallBox getVolume3:"<<length * breadth * height<<endl;
//		return 0;
//	  }
};


 
// 子类的成员函数
double SmallBox::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox::setSmallWidth( double wid )
{
    width = wid;
}
// 成员函数定义
// 初始化类 Box 的静态成员
int Box::objectCount = 0;
//Box::Box(double i):length(i),breadth(i)
Box::Box(double i)
{
	length=i;
	breadth=i;
	height=i;
	width=i;
	private_test=i;
//	ptr = new int;// 为指针分配内存
//	*ptr=i;
	 cout << "Box_i Object is being created" << endl;
}
Box::Box(const Box &obj)
{
	length=obj.length;
	breadth=obj.breadth;
	height=obj.height;
	width=obj.width;
	private_test=obj.private_test;
//	ptr = new int;// 为指针分配内存
//	*ptr=*obj.ptr;
	 cout << "Box_obj Object is being created" << endl;
}

Box::~Box(void)
{
	length=0;
	breadth=0;
	height=0;
	width=0;
	private_test=0;
//	delete ptr;//释放内存 出问题
	 cout << "Box Object is deleted" << endl;
}
void Box::display2( void )
{
	cout <<"Box_display2:"<<length<<endl<<breadth<<endl<<height<<endl<<width<<endl<<private_test<<endl;//<<endl<<*ptr
    //return *ptr;
}

double Box::getVolume(void)
{
    return length * breadth * height;
}
 
void Box::setLength( double len )
{
    length = len;
}
 
void Box::setBreadth( double bre )
{
    breadth = bre;
}
 
void Box::setHeight( double hei )
{
    height = hei;
}

void display(Box obj)
{
    obj.display2();
}

/*
Box_0 Object is being created
Box_0 Object is being created
Box1 volume:210
Box2 volume:1560
Box_0 Object is being created
Box_0 Object is being created
Box Object is deleted
SmallBox_i Object is being created
Width of box : 5
Box_obj Object is being created
Box_display2:6
7
5
2
3
1963060099
Box Object is deleted
Box_obj Object is being created
Box Object is deleted
Box Object is deleted
Box Object is deleted
Box Object is deleted
*/
// 程序的主函数
int main( )
{
//	int *ptr = new int;// 为指针分配内存
//	*ptr=3;
//	cout <<"ptr:"<<*ptr<<endl;
//	delete ptr;
//	cout <<"ptr:"<<*ptr<<endl;
   Box Box1;                // 声明 Box1，类型为 Box	1# 7#
   Box Box2;                // 声明 Box2，类型为 Box	2#	8#
   double volume = 0.0;     // 用于存储体积
	// Box1.fun();
   // box 1 详述
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // box 2 详述
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   // box 1 的体积
   volume = Box1.getVolume();
   cout << "Box1 volume:" << volume <<endl;
 
   // box 2 的体积
   volume = Box2.getVolume();
   cout << "Box2 volume:" << volume <<endl;

   SmallBox box(6);//3#6#9#
 	//box.fun();
   // 使用成员函数设置宽度
   box.setSmallWidth(5.0);
   cout << "Width of box : "<< box.getSmallWidth() << endl;
   //cout << "Width of box : "<< box.width<<box.private_test << endl;错误，protected/private成员不能在类外访问

   display(Box1);// 这里也调用了拷贝构造函数
    Box Box5 = Box1; // 这里也调用了拷贝构造函数 

  Box Box3(1.1,2,5);    // Declare box1
   Box Box4(2.3,6.2,9.2);    // Declare box2
 
   if(Box3.compare(Box4))
   {
      cout << "Box4 is smaller than Box3" <<endl;
   }
   else
   {
      cout << "Box4 is equal to or larger than Box3" <<endl;
   }

    Box *ptrBox;                // Declare pointer to a class.
    ptrBox = &Box3;
	cout << "Volume of Box3: " << ptrBox->getVolume() << endl;
	cout << "Total objects: " << Box::objectCount << endl;
	cout << "Final Stage Count: " << Box::getCount() << endl;

	   // 把两个对象相加，得到 Box6
   Box  Box6 = Box1 + Box2;
   cout << "Volume of Box6 : " << Box6.getVolume() <<endl;

  	Box1.getVolume2();
 	box.getVolume2();
//	  box.getVolume3();

   // 调用第一个命名空间中的函数
   first_space::func();
   
   // 调用第二个命名空间中的函数
   second_space::func(); 
   return 0;
}
                                                                                                                                                                                                                                                                                                                       