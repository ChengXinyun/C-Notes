1. 头文件中的防卫式声明

   `#ifndef __NAME__`

   `#define __NAME__`

   `#endif`

2. `*inline*`

   函数若在函数体类定义完成，便自动成为`inline`候选人，但是编译器不一定会将其变成`inline`，取决于函数的复杂程度，编译器是否会将其变成`inline`，如果是非常简单的函数，会成为`inline`函数。

3. 访问级别（access level）

   public，protected，private

4. 构造函数

   默认参数

   

   写法：初始化+赋值

   初值列/初始列

   `: re(r), im(i){}`

   

   重载构造函数：有默认值的函数可能与其他的重载的函数发生冲突

   构造函数放在private里面：单例模式（Singleton）

5. 重载

   几个同名的重载函数编译后的实际名称取决于编译器给他的名字。

6. 常量成员函数 `const`

   不会改变数据

   `double real() const { return re;}`

   `const complex c1(2,1)` 

   `cout << c1.real();`

   如果上一行不加 `*const*` ，会报错

7. 参数传递

   pass by value：

   pass by reference：

   参数传递，尽量传引用，速度快，可以更改；

   如果不需要更改，使用  `const`。

8. 返回值传递

   return by value

   return by reference：

    传递者无需知道接收者是以reference形式接受

   返回的如果是local object，不能return by reference。局部变量在函数结束后，空间被释放。

9. reference

   `注意: sizeof(rx) == sizeod(x),&x == &rx, 但是引用在内部的实现为指针，因此这些都是编译器制作的假象。`

   ```c++
   double x = 5.0;
   double &rx = x;
   cout << sizeof(rx) << endl;// 输出：8
   cout << sizeof(x) << endl;// 输出：8 
   cout << &x << endl;// 0x6ffe00
   cout << &rx << endl;// 0x6ffe00
   ```

10. 友元函数

   自由取得friend的private成员；

   相同class的各个objects互为友元。

11. 操作符重载

    - 成员函数

        this

      `c3 += c2 += c1;`一连串的使用

      返回值类型的设计，不能是void。

    -    非成员函数

      没有this

      `c2 = c1 + c2;` 

    -  << 重载

      `ostream& operate << (ostream& os, const complex& x){`

      ​	`return os << '(' << real(x) << ','<<imag(x)<< ')';`

      `}`

12. 临时对象 (temp object)

    `typename();`

13. 拷贝构造函数

    拷贝赋值 ： = 符号重载

    `inline String& String::operator=(const String& str){`

    ​	`if(this == &str)	return *this;`//检测自我赋值

    ​	`delete[] m_data;`

    ​	`m_data = new char[strlen(str.m_data) + 1];`

    ​	`strcpy(m_data, str.m_data);`

    ​	`return *this;`

    `}`

    如果没有检测自我赋值，第一件事是delete，如果

    a = a；

    a 指向的空间会被释放，然后就找不到了！！

    带指针的类必须含有拷贝构造和拷贝赋值；

    不然的话可能会造成内存泄漏；

14. 浅拷贝：别名，内存泄漏

    深拷贝

15. stack 栈：存在于某作用域的一块内存空间

    static静态：整个程序结束之后

    全局：整个程序结束之后

    heap 堆：由操作系统提供的一块`globle`内存空间，程序可动态分配

16. new 和delete

    - new：先分配空间，再调用构造函数

      `Complex* pc = new Complex(1,2);`

      `Complex *pc;`

      `void *mem = operator new(sizeof(Complex));//分配内存，调用malloc`

      `pc = static_cast<Complex*>(mem);//转型`

      `pc->Complex::Complex(1,2);//调用构造函数`

    

    - delete：先调用析构函数，再释放内存空间

      `Complex::~Complex(pc);//释放内部分配的内存空间`

      `operator delete(pc);//内部调用free(ps)，释放本身`

      

    - 重载::operator new, ::operator delete, ::operator new[], ::operator delete[]

       :: 表示全局作用域；

       重载单个类里面的new和delete；

17. ![image-20210412225524427](/pic/image-20210412225524427.png)

    `vc`中，调试模式下会多出`32bit`，然后上下各有一个cookie表示该块空间的大小，最后一位为1表示分配出去的；

    动态分配所得的内存空间

    动态分配所得的数组

    delete[] p;//唤起3次析构函数

    delete p;//唤起一次析构函数

    如果对数组的析构，用的是delete p，内存泄漏的部分可能是是在类里面分配的内存空间;

    ![image-20210412230516252](/pic/image-20210412230516252.png)

18. static

    - 静态成员函数没有this指针，只能去处理静态数据，普通成员函数隐藏含有一个this指针参数；

    - 静态数据在类的外面要定义：

      `double Account::m_rate = 8.0;`

    - 调用static函数的方式：
      通过object调用或者通过class name调用；

    - 单例模式：
      `class A{`

      ​	`private:`

      ​		`A();`

      ​		`A(const A& rhs);`		

      ​		`static A a;`		

      ​	`public:`

      ​		`static A& getInstance(return a;);`

      ​		`setup(){}`

      `}`

      `A::getInstance().setup();`

      改进为以下的写法：如果没有人使用这个单例，它就不会存在；只要有人使用了这个单例，他才会出现，并且只有这一份；

      `class A{`

      ​	`private:`

      ​		`A();`

      ​		`A(const A& rhs);`			

      ​	`public:`

      ​		`static A& getInstance(){`

      ​			`static A a;`

      ​			`return a;`			

      ​		`};`

      ​		`setup(){}`

      `}`

      `A::getInstance().setup();`

19. `cout`
    - `ostream`
    - << 操作符重载

20. 类模板（class template）

    `template<typename T>`

21. 函数模板（function template）

    - 标准库中的算法
    - min，sort，max

22. 成员模板（member template）

    模板的成员里面含有模板

    `stl`中的构造函数中有使用；

    `template<typename _TP>`

    `class shared_ptr:public __shared_ptr<_TP>{`

    ​	`template<typename _TP1>`

    ​	`explicit shared_ptr(_TP1* __p):__shared_ptr<_TP>(__p){}`

    `};`

    `Base1*ptr = new Derived1;`

    `shared_ptr<Base1> sptr(new Derived1);`

23. specialization 模板特化

    `// 泛化`

    `template <class Key>`

    `struct hash{};`

    `// 特化`

    `template<>`

    `struct hash<char>{`

    ​	`size_t operator() (char x) const {	return x;	}`

    `};`

    `template<>`

    `struct hash<int>{`

    ​	`size_t operator() (int x) const {	return x;	}`

    `};`

    `template<>`

    `struct hash<long>{`

    ​	`size_t operator() (long x) const {	return x;	}`

    `};`

    `// 使用,如果有特化的版本，使用特化的模板`

    `cout << hash<long>()(1000);`

24. 模板偏特化

    - 个数的偏：模板参数

      多个参数绑定其中个数，从左到右

    - 范围上的偏

      `template <typename T>`

      `class C{...};`

      `template <typename U>`

      `class C<U*>{...};`

      `C<string> obj1;`

      `C<string*> obj2;`

25. 模板模板参数:grey_question:

    容器需要多个模板参数

    ![image-20210415190521433](/pic/image-20210415190521433.png)

     

26. `namespace`

    `namespace std{`

    `}`

    `using namespace std;`

    `using std::cout;`

27. 继承，复合，委托

    - 继承

      - public,private,protected;

      - 继承关系下的构造和析构

        - 构造由内而外，先调用Base()的默认构造函数，然后才执行自己；

          `Derived::Derived():Base()(){};`

        - 析构由外而内

          `Derived::~Derived(){... ~Base()}`

        - 父类的析构函数必须是virtual，否则会出现未定义行为；

    - 复合

      一个类包含另一个类的成员；

      适配器模式；

      `Container->Component;`

      复合关系下的构造和析构

      - 构造由内而外，先调用Component的默认构造函数，然后才执行自己；

        `Container::Container():Component(){};`

      - 析构由外而内

        `Container::~Container(){... ~Component()}`

    - 委托(Composition by reference)

      一个类包含指向另一个类的指针；

      `Handle/Body(pImpI)`

28. 虚函数

    - non-virtual函数：不希望子类override它；

      `int objectID() const;`

    - virtual函数：希望子类重新定义(override,覆写)它，已经有默认定义；

      `virtual void error(const std::string& msg);`

    - 纯虚函数(pure virtual)：希望子类一定要重新定义，并且对它没有默认定义；

      `virtual void draw() const = 0`

    - 将操作延缓到子类执行：模板方法设计模式；

      ![image-20210413165033430](/pic/image-20210413165033430.png)

29. 继承和组合一起使用下的构造和析构

    - 父类中包含其他复合对象

      `class Component{`
      	`public:`
      		`Component(){`
      			`cout << "Component construct"<<endl;`
      		`}`
      		`~Component(){`
      			`cout << "Component desconstruct"<<endl;`
      		`}`
      `};`

      `class Base{`
      	`public:`
      		`Base(){`
      			`cout << "Base construct"<<endl;`
      		`}`
      		`~Base(){`
      			`cout << "Base desconstruct"<<endl;`
      		`}`
      	`private:`
      		`Component component;`
      `};`

      `class Derived:public Base{`
      	`public:`
      		`Derived(){`
      			`cout << "Derived construct"<<endl;`
      		`}`
      		`~Derived(){`
      			`cout << "Derived desconstruct"<<endl;`
      		`}`
      `};`

      结果输出为：

      `Component construct`
      `Base construct`
      `Derived construct`
      `Derived desconstruct`
      `Base desconstruct`
      `Component desconstruct`

    - 子类中包含一个复合对象

      `class Component{`
      	`public:`
      		`Component(){`
      			`cout << "Component construct"<<endl;`
      		`}`
      		`~Component(){`
      			`cout << "Component desconstruct"<<endl;`
      		`}`
      `};`

      `class Base{`
      	`public:`
      		`Base(){`
      			`cout << "Base construct"<<endl;`
      		`}`
      		`~Base(){`
      			`cout << "Base desconstruct"<<endl;`
      		`}`
      `};`

      `class Derived:public Base{`
      	`public:`
      		`Derived(){`
      			`cout << "Derived construct"<<endl;`
      		`}`
      		`~Derived(){`
      			`cout << "Derived desconstruct"<<endl;`
      		`}`
      	`private:`
      		`Component component;`
      `};`

      结果输出为：

      `Base construct`
      `Component construct`
      `Derived construct`
      `Derived desconstruct`
      `Component desconstruct`
      `Base desconstruct`

30. 委托+继承

    组合模式

    观察者模式

    Prototype 

31. explicit

    - 转换函数（conversion function）

      没有返回类型，应该加上`const`，函数名`double()`;

      `operator double() const{`

      ​	`return (double)(m_numerator/m_denominator);`

      `}`

      `Fraction f(3,5);`

      `double d = 4 + f;//调用operator double()将f转为0.6`

    - `non-explicit-one-argument ctor`

      可以将别种类型转换为该类型；

      `Fraction(int num, int den = 1):m_numerator(num), m_denominator(den){}`

      `Fraction f(3,5);`

      `Fraction d2 = f + 4;//调用non-explicit ctor将4转为Fraction(4,1)，然后调用operator +；`

    - 如果上述

      `Fraction(int num, int den = 1):m_numerator(num), m_denominator(den){}`

      和

      `operator double() const{ return (double)(m_numerator/m_denominator);}`

      同时存在，然后`Fraction d2 = f + 4;`会报错，编译器无法知道

      - 将4转化为fraction，然后operator +相加
      - 将f转化为double，与4相加后，再转化成fraction

      这两种方式；

    - 加上explicit后，只能在构造函数的时候才能调用此构造函数。

      `Fraction f(3,5);`

      `Fraction d2 = f + 4;//4无法通过构造函数转换成fraction`

32. pointer-like classes

    - 智能指针：`shared_ptr`

      - *操作符重载

        `T& operator* () const{	return *px;	}`

      - ->重载，特殊：->作用下去得到的结果继续作用下去

        `T* operator-> () const{	return px;	}`

    - 迭代器：

      - *操作符重载

        `reference operator* () const{	return (*node).data;	}`

      - ->重载

        `pointer operator-> () const {	return &(operator* ());	}`

33. function-like classes,仿函数

    - 在class中对()进行重载
    - 继承奇特的父类:question:

34. c++ 标准库

    - 容器 / 数据结构
    - 迭代器
    - 算法 

35. `variadic templates` 数量不定的模板参数

    `#include <iostream>`

    `using namespace std;`

    `void print(){`
    	`cout << "后面的一个package为空的时候调用的函数" << endl;`
    `}`
    `template <typename T, typename... Types>` 
    `void print(const T& firstArg, const Types&... args){`
    	`cout << firstArg << endl;`
    	`print(args...);`
    	`cout << sizeof...(args) << endl;// 后面模板参数的个数；` 
    `}`

    `int main(){`
    	`std::cout << __cplusplus << std::endl; // 201103，编译器支持的c++版本`
    	`print(7.5,"hello",377, 42);`
    `}`

    输出为：

    `201103`
    `7.5`
    `hello`
    `377`
    `42`
    `后面的一个package为空的时候调用的函数`
    `0`
    `1`
    `2`
    `3`

36. `auto`

37. `for`

    `for(int i:{2,3,4,5,5,6,7,8}){`

    ​	`cout << i << endl;`

    `}`

38. 对象模型

    - `vptr`
    - `vtbl`

    - `this`
    - `动态绑定Dynamic Binding`

39. 常量成员函数

    `const 放在成员函数的函数体之前，表示这个函数不会修改类的数据成员`

    `void test(int x) const {...}`

    对象能否调用成员函数：

    - `对象是const，成员函数也是const；`

      可以调用

    - `对象是const，成员函数不是const；`

      不能调用，如果print()不是const，则下面的代码会报错；

      ```c++
      const String str("hello world");
      str.print();
      ```

    - `对象不是const，成员函数是const；`

      可以调用

    - `对象不是const，成员函数也不是const；`

      可以调用

    `const 属于函数签名，加与不加是重载；`

    `当成员函数的 const 和 non-const版本同时存在，const object只能调用const版本，non-const object只能调用 non-const版本；`