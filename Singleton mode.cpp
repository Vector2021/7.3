#include<iostream>
using namespace std;

//实现单例模型的步骤：
//1 构造函数私有化
//2 增加静态私有的当前类的指针变量
//3 提供一个静态的对外接口，可以让用户获得单例对象

class A {
private:
	A() {
		a = new A;
	}
//提供静态方法，即对外接口
public:
	static A* GetInstace() {
		return a;
	}
// 设置静态私有的当前类指针
private:
	static A* a;
};

//static 成员类外初始化
A* A::a = NULL;

//单例分为懒汉式和饿汉式

//懒汉式
class Singleton_lazy {
private:
	Singleton_lazy(){}
	static Singleton_lazy* getInstance()
	{                                //为什么叫懒汉式呢？ 因为只有你去调getInstance()时才会new一个对象出来；也就是需要的时候才创建
		if (pSingleton == NULL) {
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}
private:
	static Singleton_lazy* pSingleton;
};
//类外初始化静态成员变量
Singleton_lazy* Singleton_lazy::pSingleton = NULL;


//饿汉式
class Singleton_hungry {
private:
	Singleton_hungry() { cout << "我是饿汉构造!" << endl; } // 在main()函数执行之前就创建对象了；所以叫恶汉；
	static Singleton_hungry* getInstance()
	{                                
	  return pSingleton;  //饿汉式在这里不需要判断，直接return；
	}
private: 
	static Singleton_hungry* pSingleton;
};
//在类外初始化的时后new对象；
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;

int main() {
	//A a;   //A* a = new A
	//A::GetInstace();

	cout << "main()函数执行..." << endl;
	return 0;
}