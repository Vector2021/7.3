#include<iostream>
using namespace std;

//ʵ�ֵ���ģ�͵Ĳ��裺
//1 ���캯��˽�л�
//2 ���Ӿ�̬˽�еĵ�ǰ���ָ�����
//3 �ṩһ����̬�Ķ���ӿڣ��������û���õ�������

class A {
private:
	A() {
		a = new A;
	}
//�ṩ��̬������������ӿ�
public:
	static A* GetInstace() {
		return a;
	}
// ���þ�̬˽�еĵ�ǰ��ָ��
private:
	static A* a;
};

//static ��Ա�����ʼ��
A* A::a = NULL;

//������Ϊ����ʽ�Ͷ���ʽ

//����ʽ
class Singleton_lazy {
private:
	Singleton_lazy(){}
	static Singleton_lazy* getInstance()
	{                                //Ϊʲô������ʽ�أ� ��Ϊֻ����ȥ��getInstance()ʱ�Ż�newһ�����������Ҳ������Ҫ��ʱ��Ŵ���
		if (pSingleton == NULL) {
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}
private:
	static Singleton_lazy* pSingleton;
};
//�����ʼ����̬��Ա����
Singleton_lazy* Singleton_lazy::pSingleton = NULL;


//����ʽ
class Singleton_hungry {
private:
	Singleton_hungry() { cout << "���Ƕ�������!" << endl; } // ��main()����ִ��֮ǰ�ʹ��������ˣ����Խж񺺣�
	static Singleton_hungry* getInstance()
	{                                
	  return pSingleton;  //����ʽ�����ﲻ��Ҫ�жϣ�ֱ��return��
	}
private: 
	static Singleton_hungry* pSingleton;
};
//�������ʼ����ʱ��new����
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;

int main() {
	//A a;   //A* a = new A
	//A::GetInstace();

	cout << "main()����ִ��..." << endl;
	return 0;
}