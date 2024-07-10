#include<iostream>
using namespace std;
#include "add.h"
int main()
{
	cout << "hello" << endl;  //打印内容
	//变量的作用：方便管理内存空间
	int a = 10;	
	int b = sizeof(a);
	cout << "a=" << a <<"b="<< b << endl;
	cout << "a\n" << "b" << endl;

	add(100, 900);

	int arr[] = { 1,2,3 };
	int* p = arr;
	cout << *(++p) << endl;  //p[1] == arr[1]

	system("pause");
	return 0;
}

/*
	#define 宏常量
	#define day 7    (day就代表7)  要修改只能在#define day 7这里修改值，若day = 10 这样修改不可行

	const修饰变量  （在变量前加关键字const,表示修饰该变量为常量不可被修改）
	const int a = 10;
	a = 7 (这样修改也不可行)

	C++ 区分大小写

	数据类型存在意义:给变量分配合理的内存空间（不同数据类型，取值范围不同，超出范围会输出错误）
	整型有:short、int、long、long long

	sizeof关键字:可以统计数据类型所占空间的大小
	语法:sizeof(数据类型/变量)

	实型（浮点型）:用于表示小数
	float(单精度):占4个字节  有效数字范围:7位有效数字
	float f1=3.14f; 加f是为了区分float跟double 不加f默认为double类型

	double(双精度):占8个字节  有效数字范围:15-16位有效数字
	目前在c++中最多只能显示6位有效数字，若要全显示还需要其他额外配置

	科学计数法：float f = 3e2;//3*10^2
	float f = 3e-2;//3*0.1^2(10的-2次方)

	字符型:用于显示单个字符（char c = 'c';）占1个字节
	注意：字符型变量并不是把字符本身存放到内存中存储，而是将对应的ASCII编码存放到存储单元
	cout<<(int)c<<endl; 把c强转为int类型，可以打印出c的ASCII码值;

	转义字符:

	字符串型:
	C语言风格字符串:char 变量名[] = "字符串值";  下标可以取对应值  string a = "ABC"  ,a[1] == B

	C++风格字符串: string 变量名 = "字符串值"; (使用的时候要包含头文件 #include<string>)

	布尔类型bool（占1个字节）（非零为真）
	bool只有两个值
	ture ---真（本质是1）
	false --假（本质是0）
	bool flag = ture;
	cout<<flag<<endl;  // 1

	数据的输入
	关键字:cin
	语法:cin >> 变量; 这样就可以输入数据到变量内

	string str = "hello";
	cout<<"请赋值："<<endl;
	cin >> str;			//输入world
	cout <<str<<endl;    //world

	运算符

	else if

	三目运算符：表达式1 ？ 表达式2 : 表达式3;
	在C++中三目运算符返回的是变量，可以继续赋值
	例如：int a=10,b=20;
		(a>b?a:b) = 100;    此时b = 100,因为a>b不成立，返回b 然后把100赋值给b

	switch语句

	rand()生成一个随机数 ，rand()%100+1 生成一个0-100的随机数

	在嵌套循环中使用break，会退出内层循环，执行下一次外层循环
	continue,跳过本次循环中尚未执行的语句，继续执行下一次循环

	goto语句
	语法:goto 标记;如果标记存在，执行到goto语句时，会跳转到标记的位置执行下面的程序
	例如：cout<<1<<endl;
			goto FLAG;
			cout<<2<<endl;
			cout<<3<<endl;
			FLAG:
			cout<<4<<endl;

	2和3都不会打印，只会打印1和4

	数组
	打印地址要用&符号，数组名除外

	元素逆置
	int arr[] = {1,3,2,5,4};
	int start = 0;				起始下标
	int end = sizeof(arr)/sizeof(arr[0])-1   末尾下标
	int tmp;

	while(start>end)
	{
		tmp = arr[start];
		arr[strat] = arr[end];
		arr[end]  = tmp;
		start++;
		end--;
	}
	for(int i = 0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		cout << arr[i] << endl;
	}

	冒泡排序
	int [2][3] = {1,2,3,4,5,6}
	二维数组的首元素地址是第一行，arr = arr[0],arr和arr[1]之间相差12个字节

	函数的分文件编写
	1，创建.h后缀名的文件
	2，创建.cpp后缀名的文件
	3，在头文件中声明函数定义
	4，在源文件中写函数的定义

	指针:在32位操作系统下，不管什么类型的指针都占4个字节

	int * p = NULL;空指针（0）（用于初始化）不可以进行访问（0~255是系统占用的）

	！！！
	const修饰常量
	int a = 10;
	const int *p = &a;(特点:指针指向不可以改，指针指向的值可以改)——常量指针
	int* const p = &a;(特点:指针指向可以改，指针指向的值不可以改)——指针常量
	const int* const p = &a;(特点:指针指向和指向的值都不可以改) 


	指针访问数组
	int arr[] = {1,2,3,4,5};
	int* p = arr;
	for(int i = 0 ;i<5;i++)
	{
		cout<<*p<<endl;
		p++;
	}

	指针和函数
	void add(int *p1,int *p2)
	{
		int tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}

	int main()
	{
		int a=10,b=20;
		add(&a,&b);
		//地址传递可以影响实参的值（修饰）
	}


	结构体
	struct Student
	{
		string name;  //姓名
		int age;	  //年龄
		int score;	  //分数
	}

	int main()
	{
		// 结构体变量创建
		struct Student s1;
		// 赋值
		s1.name = "张三";
		//也可以这样整体赋值
		struct Student s2 = {"张三",21,99};

		// 结构体变量创建时，struct可以省略，定义的时候不可用省略
		
		// 结构体数组
		struct Student arr[] ={{"张三",21,78},{"王二",23,99},{"小明",22,90}};
		//还可以修改(修改小明的信息)
		arr[2].name = "小红";	

		//结构体指针
		struct Student *p = &s2;
		p->name就可以访问了;


		结构体嵌套结构体
		struct Student
		{
			string name;  //姓名
			int age;	  //年龄
			int score;	  //分数
		}

		struct teacher
		{
			int id;
			int age;
			string name;
			struct Student stu;
		}

		int main()
		{
			//创建老师
			struct teacher t;
			t.id = 1000;
			t.stu.age = 20;
		}


		结构体做函数参数
		struct Student
		{
			string name;  //姓名
			int age;	  //年龄
			int score;	  //分数
		}

		//打印结构体函数
		//值传递
		void print1(struct Student s)
		{	
			s.name = "小明"；
			cout<<s.name<<endl;
		}
		//地址传递
		void print2(struct Student *s)  （如果在struct Student *s前面加一个const
										   ,const struct Student *s,那么结构体内容不能被修改
											防止误操作）
		{
			s->name = "小明";
			cout<<s.name<<endl;
		}
		int main()
		{
			//创建学生结构体变量
			struct Student stu;
			stu.name = "小红";
			stu.age = 20;
			stu.score = 99;
			print1(s);
			print2(&s);
		}
		//值传递和地址传递的区别
		值传递不会改变结构体本身，而地址传递会改变结构体本身

		值传递虽然可行但是不建议使用，因为太占内存，推荐使用地址传递（只占四个字节）
		指针的目的是为了节省空间

		string name = "ABC";
		stu.name = "tom_";
		stu.name+=name[0];    // stu.name————tom_A(拼接)

		随机数种子(这样才能使随机数每次执行都不一样，达到正真的随机，随时间而改变)
		srand((unsigned int)time()NULL);(要加头文件#include<Ctime>)
*/		