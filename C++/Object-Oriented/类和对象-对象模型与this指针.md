
## 成员变量和成员函数分开存储

在C++中，类内的变量和函数分开存，只有非静态变量才占对象空间。
**静态变量 / 函数（属于类 不属于任一对象）或 非静态函数 都不占对象空间**
**如果是空对象也占用1字节的空间，为了标记自己的位置**

```C++
class Person {
public:
	Person() {
		mA = 0;
	}
	int mA;
	static int mB; 

	void func() {
		cout << "mA: " << this->mA << endl;
	}
	static void sfunc() {
	}
};

int main() {
	cout << sizeof(Person) << endl; 
	return 0;
}
```


## this指针

每一个非静态函数只产生一份函数实例
e.g. 同类型的对象共用一块代码

那这一块代码如何区分是谁调用自己？
**函数内隐含了this指针，指向函数所属的对象**

this指针的用途：
*  当形参和类里变量同名时，可用this指针来区分
*  **返回对象本身**时可使用return *this（非静态成员函数）
实现链式编程，不断写`对象.行为.行为...`
```C++
class Person {
public:
	Person(int age) {
		this->age = age; // 区分类里变量和形参
	}

	Person& PersonAddPerson(Person p) {
		this->age += p.age;
		//返回对象本身
		return *this;
	}

	int age;
};

void test01() {
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	cout << "p2.age = " << p2.age << endl;
}

int main() {
	test01();
	return 0;
}
```

## 空指针访问成员函数

C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

如果用到this指针，需要加以判断保证代码的健壮性

**示例：**

```C++
//空指针访问成员函数
class Person {
public:

	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl;
	}

public:
	int mAge;
};

void test01()
{
	Person * p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

## const修饰成员函数

**常函数：**

* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改

**常对象：**

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数

**示例：**

```C++
class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}

	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	void ShowPerson() const {
		//const Type* const pointer;
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
	}

	void MyFunc() const {
		//mA = 10000;
	}

public:
	int m_A;
	mutable int m_B; //可修改 可变的
};


//const修饰对象  常对象
void test01() {

	const Person person; //常量对象  
	cout << person.m_A << endl;
	//person.mA = 100; //常对象不能修改成员变量的值,但是可以访问
	person.m_B = 100; //但是常对象可以修改mutable修饰成员变量

	//常对象访问成员函数
	person.MyFunc(); //常对象不能调用const的函数

}

int main() {

	test01();

	system("pause");

	return 0;
}
```



