# C语言



## 1. main函数的使用

- c语言代码中必须包含main函数，main函数是程序的入口，main有且仅有一个

    - ```c
    int main() //int 整型
    {
      return 0;//0 整数
    }
    ```

- 编译 + 链接 --> 可执行程序

- `.h ` 头文件 (函数的声明、类型的声明、 头文件的包含)

- `.c`  源文件（函数实现）

- 函数如果不写返回值类型, 默认返回int类型, 如果写了返回类型,但是不return, 则自动返回最后一条语句的返回值

- 在函数参数列表中写void可以明确拒绝传入的参数

- main函数实际上是有参数的

    - ```c
    int main(int argv, char* argvv[], char *envp[]){
        return 0;
    }
    ```

    -

### 案例

```c
#include <stdio.h> //头文件，std 标准，i input，o output
int  main()
{
  printf("hello world\n") //printf 库函数，用于打印
    return 0;
}
```



## 2. 数据类型

- char 			字符数据类型
- short           短整型
- int                整型
- long             长整型
- long long    更长的整型
- float            单精度浮点数
- double       双精度浮点数

==浮点数存在四舍五入， 不能用肉眼看见数数值来计算， 因为浮点数在内存中有可能不能精确保存==

> 例如浮点数存储`12.45`
>
> 内存中可能存储的是`12.454959353489732...`

```c
printf("%d\n",100)  //%d 指定打印格式为 整型
printf（"%d\n",sizeof(char)）//sizeof()在内存中所占空间的大小
  printf（"%zu\n",sizeof(char)） //%zu zu是size返回的值，z是sizeof，u是unsigned 无符号，
```

```c
#include <stdio.h>
int main()
{
    printf("%zu\n",sizeof(char));
    printf("%zu\n",sizeof(short));
    printf("%zu\n",sizeof(int));
    printf("%zu\n",sizeof(long));
    printf("%zu\n",sizeof(long long));
    printf("%zu\n",sizeof(float));
    printf("%zu\n",sizeof(double));
        return 0;
}

output:(单位：比特位)
1
2
4
8
8
4
8
```

> 指针变量占用内存空间:
>
> - x86环境为4个字节
> - x64环境为8个字节

计算机中的单位：

bit

byte = 8 bit

kb = 1024 byte

mb = 1024 kb

gb

tb

pm



```c
int main()
{
  int age = 20;
  short num = 13;
  double price = 32.5;
  return 0;
}
```







```c
#include <stdio.h>
int a = 100;
int main()
{
  int a = 10;
  printf("a=%d",a)//a=10，局部优先
}
//不建议把全局变量和局部变量写成相同的名字
```



```c

```

## 3. 变量、常量

### 3.1 定义变量的方法

==定义变量时, 同时初始化,如果不初始化, 那么变量默认为一个随机值==

```c
#include <stdio.h>
int main()

{

// 定义变量 (同时初始化)

short age = 20;//年龄

int hight  =180;//身高

double wight = 88.5;//体重

return 0;

}

```



### 3.2 变量的分类

> 变量命名:
>
> - 见名知意
> - 有字母、数字、下划线，不能有特殊字符，不能以数字开头
> - 变量名不能是关键字

#### 局部变量

- 大括号内定义的变量
- 作用域仅在`{}`括号内

#### 全局变量

- 大括号外定义的变量
- 作用域为整个工程
- 具有外部链接属性
- 少用 (不安全)

==在同一个作用域内, 变量名不可重复, 在使用时, 如果局部和全局变量名同名, 则局部优先==

```c
#include <stdio.h>
int global = 2019;//全局变量
int main()
{
    int local = 2018;//局部变量
    int global = 2020;//局部变量
    printf("global = %d\n", global);
    return 0;
}
```



#### 案例

> 计算两个整数的和, (用户输入)

```c
#define _CRT_SECURE_NO_WARNINGS //报错: 'scanf': This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.则在四一行加上
#include <stdio.h>
int main()
{
  int num_1 = 0;
  int num_2 = 0;
  //输入函数
  scanf("%d %d",&num_1,&num_2);//& 指向的是该变量的内存地址空间
  int sum = num_1 + num_2;
  //输出函数
  printf("%d\n",sum);
  return 0;
}
```



#### 变量的作用域和生命周期

- 作用域: 变量可以使用的区域

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    int main()
    {
        {
            int a = 10;
            print("a=%d\n", a);
        }
        printf("a=%d\n", a);//error C2065: “a”: 未声明的标识符
    }
    //C:\Users\Administrator\Desktop\C\test\test\test\add.c(9,23): error C2065: “a”: 未声明的标识符
    ```

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    int main()
    {
         int a = 10;
        {
            printf("a=%d\n", a);
        }
        printf("a=%d\n", a);
    }
    //a = 10
    //a = 10
    ```

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    int a = 10;//全局变量
    void test()
    {
        printf("test-->%d\n", a);
    }
    int main()
    {
        test();
        {
            printf("a=%d\n", a);
        }
        printf("a=%d\n", a);
    }
    //test-->10
    //a=10     
    //a=10   
    ```

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    //外部调用,需要先声明
    //声明来自外部的变量
    extern int a;
    void test()
    {
        printf("test-->%d\n", a);
    }
    int main()
    {
        test();
        {
            printf("a=%d\n", a);
        }
        printf("a=%d\n", a);
    }
    ```



- 生命周期:

  > 作用域内变量被创建, 离开作用域时, 变量的生命结束

    - 局部变量: 进入作用域生命周期开始, 出作用域生命周期结束
    - 全局变量: 整个程序的生命周期

### 3.3 常量

- 字面常量
- `const`修饰的常变量
- #defind定义的标识符常量
- 枚举常量



#### 字面常量

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	//字面常量
	30;
	2.44;
	'w';//字符常量
	"abc";//字符串常量
	printf("%d\n", a);
	return 0;
}
//10
```



#### const修饰的常变量

> 在c语言中, const修饰的变量本质是变量, 但是不能被修改, 有常量的属性, 不可被修改

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	//const修饰的常变量
	const int a = 10;
	a = 20;//error C2166: 左值指定 const 对象
	
	printf("%d\n", a);
	return 0;
}
//C:\Users\Administrator\Desktop\C\test\tets7_8\tets7_8\test.c(12,2): error C2166: 左值指定 const 对象
```

验证: 此时的n仍然是变量

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	const int n = 10;
	int arr[n] = {0};//error C2057: 应输入常量表达式
	return 0;
}

//1>C:\Users\Administrator\Desktop\C\test\tets7_8\tets7_8\test.c(6,10): error C2057: 应输入常量表达式
//1>C:\Users\Administrator\Desktop\C\test\tets7_8\tets7_8\test.c(6,11): error C2466: 不能分配常量大小为 0 的数组
```



#### #defind定义的标识符常量

```c
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100//标识符常量
#define STR "abc"//标识符常量
#include <stdio.h>
int main()
{
	printf("%d\n", MAX);
	int a = MAX;
	printf("%d\n", a);
	printf("%s\n", STR);
    MAX = 200;//error C2106: “=”: 左操作数必须为左值
	return 0;
}
//1>C:\Users\Administrator\Desktop\C\test\tets7_8\tets7_8\test.c(11,2): error C2106: “=”: 左操作数必须为左值
```



#### 枚举常量

> 枚举默认从0开始, 可通过打印输出

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//枚举常量
enum Color
{
	//枚举常量
	RED,//常量符号
	GREEN,
	BLUE
};
int main()
{
	//使用: 向内存申请空间
	enum Color c = RED;
    printf("%d\n", c);
	RED = 20;//error C2106: “=”: 左操作数必须为左值
	return 0;
}
//1>C:\Users\Administrator\Desktop\C\test\tets7_8\tets7_8\test.c(15,2): error C2106: “=”: 左操作数必须为左值
```



## 4. 字符串、转义符、注释

### 4.1 字符串

> C语言中没有字符串类型

> C语言中的字符串结束标志是一个`\0`的转义字符, 在计算字符串长度的时候`\0`是结束标志, 不算作字符串内容
>
> 如果要单独输出`\0`需要分别输入,并使用转义符`'\\','0'`

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    'e';//字符常量
    char c = 'q';//字符变量
    "mielgo";// 字符串常量
    
    char arr1[] = "abcd";//char型的数组, 里面能放的字符根据后面的字符串确定,也可以在[]内通过数字指定
    //向内存申请空间时, 会放入 a b c d \0 
    //在内存中呈现为:   ...其他内存空间...a b c d \0...其他内存空间...
    //字符串的结束标志为\0
    
    char arr2[] = {'a','b','c','d'};
    //向内存申请空间时, 会放入 a b c d 
    //在内存中呈现为:   ...其他内存空间...a b c d...其他内存空间...\0(匹配到其他内存空间的字符)...其他内存空间...
    
    char arr3[] = {'a','b','c','d','\0'};
    //添加字符串的结束标志\0
    
    char arr4[] = {'\\','0','\0'};
    
    printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);
    printf("%s\n", arr4);
    return 0;
}
//abcd    
//abcd烫烫烫烫烫烫烫烫abcd
//abcd 
```

- `strlen()`求字符串长度的一个函数

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>
  #include <String.h>//获取字符串长度的头文件
  
  int main()
  {
      char arr1[] = "abcd";//char型的数组, 里面能放的字符根据后面的字符串确定,也可以在[]内通过数字指定
      char arr2[] = { 'a','b','c','d' };
      char arr3[] = { 'a','b','c','d','\0' };
      char arr4[] = { '\\','0','\0' };
      int len = strlen(arr1);//获取字符串的长度,String length
      printf("%d\n", len);//4
      return 0;
  }
  //4
  ```



### 4.2转义符
> 转变原来字符的意思
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    printf("abcn");
    printf("abc\n");//\n表示换行
    printf("abc\0def");//\0表示结束标志, \0后面的不会被打印
    return 0;
}
//abcn

//abc
//

//abc
```


#### 转义字符表格

| 转义字符         | 释义                                                         |
| ---------------- | ------------------------------------------------------------ |
| \?               | 在书写连续多个问号时使用, 防止它们被解析为三字母词           |
| \\'              | 用于表示字符常量                                             |
| \\"              | 用于表示一个字符串内部的双引号                               |
| \\\              | 用于表示一个反斜杠, 防止它被解析为一个转义字符               |
| \a               | 警告字符, 蜂鸣                                               |
| \b               | 退格符                                                       |
| \f               | 进纸符                                                       |
| \n               | 换行                                                         |
| \r               | 回车                                                         |
| \t               | 水平制表符                                                   |
| \v               | 垂直制表符                                                   |
| \ddd   (d为数字) | ddd表示1~3个八进制的数字,  如: \130      将转换为十进制      |
| \xdd   (d为数字) | dd表示2个十六进制2数字, 如: \x30 将输出  0     将转换为十进制 |

>  三字母词:`??)`在早期会被解析为`]`



#### 打印字符串
| 符号 | 作用                                           |
| ---- | ---------------------------------------------- |
| %d   | 打印整型    打印一个有符号的整数 ,打印的是原码 |
| %c   | 打印字符                                       |
| %s   | 打印字符串                                     |
| %f   | 打印float类型的数据                            |
| %lf  | 打印double类型的数据                           |
| %zu  | 打印sizeof的返回值                             |
| %p   | 打印十六进制地址  `&变量名`, &为取地址符       |

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    printf("%c\n",'\'');
    printf("\"\n");
    printf("abc\n");
    printf("%s\n","abc");
    printf("abc\\0ef\n");
    printf("\a");
    printf("%c\n",'\130');
    printf("%c\n",'\x30');
    printf("c:\test\628\test.c")//14  \t为一个制表符,\62为一个八进制字符(8不在八进制中, 所以只有\62会被识别为一个字符)
    return 0;
}
//'
//"      
//abc    
//abc    
//abc\0ef
//X    
//0
//14
```



### 4.3 注释

> 梳理思路、对复杂的代码进行解释

- `//单行内容`

- `/*多行内容*/`

## 5. 语句

语句:

- 表达式语句
- 函数调用语句
- 控制语句
    - 控制程序的执行流程, 以实现程序的各种结构方式, 它们由特定的雨具定义符组成, c语言有三类九种控制语句:
        - 条件判断语句 (分支语句): `if`,  `swich`
        - 循环执行语句:  `do while`,  `while`,  `for`
        - 转向语句:  `break`,  `goto`,  `continue`,  `return`
- 复合语句
- 空语句

> ==C语言中`0`表示假, `非0`表示真==

### 5.1 选择语句

> 条件为真, 则执行条件后的语句
>
> 如果if后只有一条语句,可以不写`{}`, 有多条语句则必须写`{}`

>  不加`{}`默认控制一条语句



#### if

```c
if(表达式){
    代码块语句;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    if (3 == 5){
        printf("ok\n");
        printf("yse\n");
    }
    return 0;
}
//条件不成立, 无输出
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 10;
    if (a = 5)//此时是赋值操作, 条件非0为真, 恒成立   若是判断,建议写为 if (5 == a),如若少了一个"="会报错
        printf("ok\n");
    return 0;
}
//ok
```



#### if - else

```c
if (表达式){
    代码块语句1;
}
else{
    代码块语句2;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int input = 0;
    printf("请输入");
    scanf("%d", &input);
    if (input == 1)
    {
        printf("输入的是一");
    }
    else
    {
        printf("输入的不是一");
    }

    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0;
   int b = 2;
   if(a == 1)
       if(b == 2)
           printf("ok");
   else //else就近匹配if, 而不受空格影响
       printf("no");
    return 0;
}
//无输出
```



#### if - else if

```c
if (表达式1){
    代码块语句1;
}
else if (表达式2){
    代码块语句2;
}
else{
    代码块语句3;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int age = 16;
    if (age < 12){
        printf("儿童");
    }else if(age < 18){
        printf("未成年");
    }else{
        printf("成年");
    }
    return 0;
}
//未成年
```



###### 练习

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    printf("请输入数字:\n");
    int num = 0;
    int b = 2;
    //获取用户输入
    scanf("%d", &num);
    //判断一个数是否为奇数
    if (num % 2 == 0) {
        printf("偶数\n");
    }
    else {
        printf("奇数\n");
    }
    printf("输出1-100之间的奇数: \n");
    num = 0;
    while (num <= 100) {
        if (num % 2 == 1) {
            printf("%d ", num);
        }
        num++;
    }

    return 0;
}
//请输入数字:
//12
//偶数
//输出1-100之间的奇数:
//1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 //89 91 93 95 97 99 

```


----
#### switch

> 可以嵌套使用

>  多分支, 单选择 (列表单选)

> switch根据后面整型表达式的值决定匹配那个case, 通过break跳出语句执行, 可以多个case匹配同一个语句, (多个case后只加一个break)
>
> (字符也是整型, 因为存储的是它的ascii码值)

```c
swith(整型表达式){ //变量
    //语句项;
    //case语句;
    case 整型常量表达式:  //入口
    	语句;
    break;  //出口
}
```
##### default子句
> 如果表达式的值与所有子句都不匹配, 程序并不会报错,如果此时想接收这个不定的值做处理, 那么需要在语句列表中加一条defaul子句 (在case的位置)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    switch (num) {
        case 1:
            printf("正确");
            break;
        case 2:
            printf("错误");
            break;
        case 3:
            printf("不确定");
            break;
        default:
            printf("输入错误");
    }

    return 0;
}

```








### 5.2 循环语句
> break可终止所有循环
> continue可终止当前一次循环, 继续下一次循环

> `scanf ` 和  `getchar` 都是从缓冲区里面读取数据
>
> - scanf()函数接收输入数据时，遇以下情况结束一个数据的输入：
    >
    >   (1)遇空格、“回车”、“跳格”键；
    >
    >   (2)遇宽度结束；
    >
    >   (3)遇非法输入。
>
> - ==`scanf`  获取输入的时候以`\n`作为结尾, 但是不读取`\n`, (如过后面有读取操作,那么就会读取到这个`\n`,  作为字符存储起来),  如果想去掉这个`\n`  需要使用`getchar`获取`\n`==
> - `getchar`特性: 获取字符时, 每次只读取一个, 它返回的是ASCII码，所以只要是[ASCII码表](https://so.csdn.net/so/search?q=ASCII码表&spm=1001.2101.3001.7020)里有的字符它都能读取出来

- ```c
  #define _CRT_SECURE_NO_WARNINGS
  //输出字符
  #include <stdio.h>
  
  int main() {
      int ch = getchar();//获取输入的字符  返回值是int  以回车键(\n)为结尾
      printf("%c\n",ch);//输出ch
      putchar(ch);//输出ch
      return 0;
  }
  ```

    - scanf获取到\n结束

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  
  #include <stdio.h>
  //scanf获取到\n结束
  int main() {
      char password[20] = {0};
      printf("请输入密码:");
      scanf("%s", password);//使用\n(回车键)结束输入, 此\n会保存在输入缓冲区, 可能造成异常, 需要使用getchar()获取该\n
      getchar();//读取末尾的\n
      printf("请确认密码(Y/N)");
      int ret = getchar();
      if('Y' == ret){
          printf("YES\n");
      } else{
          printf("NO\n");
      }
      return 0;
  }
  
  ```

    - scanf获取到空格结束

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  
  #include <stdio.h>
  //scanf获取到空格结束
  int main() {
      char password[20] = {0};
      printf("请输入密码:");
      scanf("%s", password);//使用\n(回车键)结束输入
      getchar();//读取末尾的\n
      int ch = 0;
      while(ch = getchar() != '\n'){//获取到\n以前的所有字符
          ;//不进行操作
      }
      printf("请确认密码(Y/N)");
      int ret = getchar();
      if('Y' == ret){
          printf("YES\n");
      } else{
          printf("NO\n");
      }
      return 0;
  }
  
  ```



#### while

>  先判断后执行

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i = 0;
    while (i < 10)
    {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
//1
//2
//3
//4
//5
//6
//7
//8
//9
```

- 只打印数字字符

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//只打印数字字符
int main() {
   char ch = '\0';
    //printf("%d\n", ch);//\n为10
   while((ch = getchar()) != EOF){
       //printf("%d\n", ch);//\n 为10
       if (ch < '0' || ch > '9'){
           continue;
       }
       putchar(ch);
   }
    return 0;
}
```



#### for

```c
for ( init; condition; increment )
{
   statement(s);
}

for(表达式1; 表达式2; 表达式3){
    循环语句;
}
表达式1: 初始化循环变量
表达式2: 循环条件
表达式3: 循环变量改变
```

- 输出1-10的数字

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int i = 0;
    for (i; i <= 10; i++) {
        printf("%d ", i);
    }
    return 0;
}
//0 1 2 3 4 5 6 7 8 9 10 
```

- 终止

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//终止
int main() {
    int i = 0;
    for (i; i <= 10; i++) {
        if(i == 5) break;//如果i为5就终止循环
        printf("%d ", i);
    }
    return 0;
}
//0 1 2 3 4 
```

- 跳过本次

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//跳过本次
int main() {
    int i = 0;
    for (i; i <= 10; i++) {
        if(i == 5) continue;//如果i为5就停止本次循环,进行下一次
        printf("%d ", i);
    }
    return 0;
}
//0 1 2 3 4 6 7 8 9 10 
```
- 死循环
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//死循环
int main() {
    int i = 0;
    while (i <= 10) {
        if (i == 5)
            continue;
        printf("%d ", i);
        i++;
    }
    return 0;
}
```

==break和continue在for中与switch中的作用一样, 作用域在当前循环==

- 不可在for循环的循环体内改变循环变量, 防止for循环失去控制
- 建议for语句的循环控制变量的取值采用"前闭后开区间"的写法
    - 建议`for( i=0; i<10; i++)`  此时10再次有循环10次的意思

> 死循环

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//死循环
int main() {
    for(;;){//for循环的判断部分省略意味着这个判断部分会恒成立
        printf("执行\n");
    }
    return 0;
}
```

- 可以使用多个变量

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
    int x, y;
    for (x = 0, y = 0; x <= 3 && y <= 3; ++x, y++) {//for循环的判断部分省略意味着这个判断部分会恒成立
        printf("%d %d\n", x, y);
    }
    return 0;
}
```



#### do - while
> 先执行后判断

```c
do{
    循环语句;
}while(表达式);
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int a = 0;
    do {
        a++;
        printf("%d ", a);
    } while (a < 10);
    return 0;
}
//1 2 3 4 5 6 7 8 9 10 
```

#### 练习

- 计算阶乘

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    //双循环
    int main() {
        int i = 1;
        int sum = 0;
        for (i = 1; i <= 10; i++) {
            int j = 0;
            int num = 1;
            for (j = 1; j <= i; j++) {
                num = num * j;
                //printf("%d\n", num);
            }
            sum += num ;
            printf("%d\n",sum);
        }
        return 0;
    }
    
    ```

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    //单循环
    int main() {
        int sum = 0;
        int i = 0;
        int num = 1;
        for (i = 1; i <= 10; i++) {
            num = num * i;//1 2 6 24 阶乘
            sum += num;//增加上一次阶乘的值
            printf("%d\n", sum);
        };
        return 0;
    }
    
    ```

- 逐渐显示字符 (有遮挡)

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    #include <string.h>
    #include <windows.h>
    
    int main() {
        char arr1[] = "welcom to bit!!!!";
        char arr2[] = "#################";
        int left = 0;
        int right = strlen(arr2) - 1;//int right = sizeof(arr1)/sozeof(arr1[0])-2
        while (left <= right) {
            arr2[left] = arr1[left];
            arr2[right] = arr1[right];
            printf("%s\n", arr2);
            Sleep(1000);//毫秒
            system("cls");//清空屏幕  system是一个库函数, 可以执行系统命令
            left++;
            right--;
        }
        return 0;
    }
    ```

- 用户登录

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    #include <string.h>
    #include <windows.h>
    
    int main() {
        int i = 0;
        char password[20] = {0};//数组名就是地址,使用时可以不取地址
        for (i = 0; i < 3; i++) {
            printf("清输入密码");
            scanf("%s", password);
            if (strcmp(password, "abcd") == 0) {//判断字符串相等不能使用==,而应使用库函数: strcmp  返回值为0表示相等
                printf("登录成功\n");
                break;
            } else {
                printf("密码错误\n");
            }
    
        }
        if (i == 3) {
            printf("三次密码均输入错误, 退出程序\n");
        }
        return 0;
    }
    ```

- 猜数字游戏

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>
    #include <time.h>
    
    void menu() {
        printf("****************************************\n");
        printf("**************** 1. play ***************\n");
        printf("**************** 0. exit ***************\n");
        printf("****************************************\n");
    }
    
    void game() {
        int guess = 0;
        //产生一个随机数
        int ret = rand() % 100 + 1;//生成随机数 取模为0+1 - 99+1
        printf("%d\n", ret);
    
        while (1) {
            printf("请猜数字 > ");
            scanf("%d", &guess);
            if (guess < ret) {
                printf("猜小了\n");
            } else if (guess > ret) {
                printf("猜大了\n");
            } else {
                printf("猜对了\n");
                break;
            }
        }
    }
    
    int main() {
        int input = 0;
        srand((unsigned int) time(NULL));//随机数生成的来源  指针为空(指向的地址为0)
        do {
            menu();
            printf("请选择 >");
            scanf("%d", &input);
            switch (input) {
                case 1:
                    game();
                    break;
                case 0:
                    printf("退出游戏\n");
                    break;
                default:
                    printf("选择错误\n");
                    break;
            }
        } while (input);//0为假, 条件不成立, 退出循环
    
        return 0;
    }
    ```



#### goto

- 不常用, 尽量少使用

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//不正常的用法
int main() {
    again:
    printf("OK\n");
    printf("YES\n");
    goto again;
    return 0;
}
```

- 正确用法

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
  for(...){
      for(...){
          if(...){
                goto error;//可以快速跳转, 一次跳出多层循环, 可自由跳转
          }
      }
  }
    error:
    if(...){
        //处理错误
    }
    return 0;
}
```

- 自动关机 (go to)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //shutdown -s -t 60  设置60秒后自动关机
    //shutdown -a 取消关机
    char input[20] = {0};//不需要取地址,数组就是地址
    system("shutdown -s -t 6000");//关机
    again:
    printf("请注意,你的电脑将在60秒后关机,输入\"否\",可取消关机\n");
    scanf("%s",input);
    if(strcmp(input,"否") == 0){
        system("shutdown -a");//取消关机
        printf("自动关机已取消\n");
    } else{
        goto again;
    }
    return 0;
}
```



- 自动关机 (while)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //shutdown -s -t 60  设置60秒后自动关机
    //shutdown -a 取消关机
    char input[20] = {0};//不需要取地址,数组就是地址
    system("shutdown -s -t 6000");//关机
    while (1){
        printf("请注意,你的电脑将在60秒后关机,输入\"否\",可取消关机\n");
        scanf("%s",input);
        if(strcmp(input,"否") == 0){
            system("shutdown -a");//取消关机
            printf("自动关机已取消\n");
            break;
        }
    }
    return 0;
}
```

> debug是调试版本
>
> release是发布版本





## 算法

### 折半查找 (二分查找)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//查找数字
int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int i = 0;
    int k = 0;
    printf("请输入:\n");
    scanf("%d" ,&k);
    int sz = sizeof(arr) / sizeof(arr[0]);//获取数组个数 9个
    int left = 0;//左下标
    int right = sz - 1;//右下标
    while(left <= right){
        //int mid = (left + right) / 2;//获取中间的下标
        int mid = left + (right - left) / 2;//避免溢出
        if(arr[mid] < k){//判断输入是否比中间的大
            left = mid + 1;
        }else if(arr[mid] > k){//判断输入是否比中间的小
            right = mid - 1;
        }else{
            printf("找到了,下标是:  %d\n",mid);
            break;
        }
    }
    if(left > right){
        printf("找不到");
    }
    return 0;
}

```













## 7. 函数

### 7.1 函数是什么

>  *函数是一组一起执行一个任务的语句。每个 C 程序都至少有一个函数，即主函数* **main()** *，所有简单的程序都可以定义其他额外的函数。*

- 分类

    - 库函数

        - I/O函数  <stdio.h>...

        - 字符串操作函数  <string .h>...

        - 字符操作函数

        - 内存操作函数

        - 时间/日期操作函数

        - 数学函数

        - 其他库函数

        - >[函数库资料](https://cplusplus.com/reference/cstring/strcpy/?kw=strcpy)

            - 案例一

            - ```c
            //函数原型
            strcpy  (String copy)
            char * strcpy ( char * destination, const char * source );
            char指针 复制字符串  char指针  目的地  修饰   char指针   来源地
        ```

              ```c
              #define _CRT_SECURE_NO_WARNINGS
              
              #include <stdio.h>
              #include <string.h>
              
              int main() {
                  char arr1[20] = {0};
                  char arr2[] = "hello bit";
                  strcpy(arr1,arr2);
                  printf("%s\n",arr1);//复制字符串
                  //char * strcpy ( char * destination, const char * source );//函数原型
                  return 0;
              }
              //hello bit
              ```


        ​      
      
      - 案例二
      
      - ```c
        //函数原型
        memset (memory set)
        void * memset ( void * ptr, int value, size_t num );
        void指针 函数名   void指针 元素1  int值    无符号整型 
        //从ptr的第一个字节开始, 往后的num个字节, 设置为value
        ```
      
        ```c
        #define _CRT_SECURE_NO_WARNINGS
        
        #include <stdio.h>
        #include <string.h>
        
        int main() {
            char arr[] = "hello world";
            memset(arr,'x',5);
            printf("%s\n",arr);
            return 0;
        }
        //xxxxx world
        ```
      
        ```c
        #define _CRT_SECURE_NO_WARNINGS
        
        #include <stdio.h>
        #include <string.h>
        
        int main() {
            char arr[] = "hello world";
            memset(arr+6,'x',3);
            printf("%s\n",arr);
            return 0;
        }
        //hello xxxld
        ```





- 自定义函数





### 7.2 库函数

> 库函数的使用必须包含`#include`对应的头文件

查询地址:

- MSDN
- [cplusplus.com](https://cplusplus.com)
- [C reference - cppreference.com](https://en.cppreference.com/w/c)
- [C 参考手册 - cppreference.com](https://zh.cppreference.com/w/c)



### 7.3 自定义函数

> 高内聚, 低耦合

````c
return_type function_name( parameter list )
{
   body of the function;
}
返回值类型 函数名(参数列表){
    函数体;
}

//函数
int Add(int x, int y) 
{
    int z = 0;
    z = x + y;
    return z;
}
```
````

- 找出两个数值的最大值

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int get_max(int a, int b){//函数定义
    return (a > b ? a : b);//三目运算
}
int main() {
    int a = 0;
    int b = 0;
    scanf("%d %d",&a,&b);//输入的时候以空格分割
    int m = get_max(a,b);//获取最大值  函数调用
    printf("%d", m);
    return 0;
}
```

- 交换值 (需要使用地址)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void swap(int* px, int* py){//自定义函数  传入内存地址(指针)
    int c = 0;
    c = *px;//交换的是地址对应的值 z = a
    *px = *py;//a = b
    *py = c;//b = a

}
//当实战参传递给形参的时候, 形参是实参的一份临时拷贝,有自己的独立空间
//对形参的修改不会影响实参
int main() {
    int a = 0;
    int b = 0;
    scanf("%d %d",&a,&b);//输入的时候以空格分割
    printf("交换前: a为%d, b为%d\n",a,b);
    swap(&a,&b);//传入内存地址(指针)
    printf("交换后: a为%d, b为%d\n", a,b);
    return 0;
}
//12 56
//交换前: a为12, b为56 
//交换后: a为56, b为12
```

==通过形参对实参进行修改的时候, 需要传入地址==



### 7.4 函数参数

> **实际参数**
>
> - 真实传给函数的参数
> - 可以是常量、变量、表达式、函数等
> - 无论实参是何种类型的值，在进行函数调用时，他们都必须有确定的值，以便把这些值传递给形参
>
> **形式参数**
>
> - 形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化（分配内存单元），所以叫形式参数
> - 形式参数在函数调用完成后就自动销毁了，因此形式参数只有在函数中有效



### 7.5 函数调用

> **传值调用**
>
> - 函数的形参和实参分别占用不同的内存块, 对形参的修改不会影响实参
>
> **传址调用**
>
> - 传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式
> - 这种传参方式可以让函数黑函数外边的变量建立起真正的联系, 也就是函数内部可以直接操作函数外部的变量



```c
define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
//传值调用
void swap1(int x, int y){//传入一个值  xy是ab的一份地址拷贝, 有自己的内存地址, xy的改变不会影响ab的值
    int c = 0;
    c = x;//z = a
    x = y;//a = b
    y = c;//b = a

}
//传址调用
void swap2(int* px, int* py){//传入一个地址(指针) px和py直接存入ab的地址(建立了联系), xy的改变会影响ab的值
    int c = 0;
    c = *px;//交换地址对应的值 z = a
    *px = *py;//a = b
    *py = c;//b = a

}

int main() {
    int a = 0;
    int b = 0;
    scanf("%d %d",&a,&b);//输入的时候以空格分割
    printf("交换前: a为%d, b为%d\n",a,b);
    swap1(a,b);//传值调用
    printf("sw1交换后: a为%d, b为%d\n", a,b);
    swap2(&a,&b);//传址调用
    printf("sw2交换后: a为%d, b为%d\n", a,b);
    return 0;
}
```



### 练习

- 判断一个数是不是素数

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    #include <time.h>
    #include <math.h>
    int is_prime(int n){
        int j = 0;//除数 2 ~ i-1
        //如果他不是素数, 那么一定可以写做两个数的积, 这两个乘数中一定有一个数字是小于等于这个数的平方根的
        for (j = 2; j <= sqrt(n); j++) {  //sqr(num)  开平方,  sqrt是一个数学库
            if ((n % j) == 0) {//有余数才是素数  ==0 表示这个数字能被整除,不是素数
                return 0;//返回 0 表示不是素数
            }
        }
        return 1;//返回 1 表示是素数
    }
    
    int main() {
        int i = 0;
        int cont = 0;
        for (i = 100; i <= 200; i+=1) {
            if (is_prime(i)) {
                printf("%d是素数\n", i);
                cont++;
            }
        }
        printf("\ncount = %d",cont);
        return 0;
    }
    ```

- 判断一年是不是闰年

    - > - 能被4整除, 并且不能被100整除是闰年
      >
      > - 能被400整除是闰年

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    #include <time.h>
    #include <math.h>
    
    int main() {
       int year = 0;
        for (year = 1000; year <= 2000; year++) {
            //判断
            if(year % 4 == 0){
                if(year % 100 != 0){
                    printf("%d\n",year);
                }
            }
            if(year % 400 == 0){
                printf("%d\n",year);
            }
        }
        return 0;
    }
    ```

    - 函数写法

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    #include <time.h>
    #include <math.h>
    
    int is_leap_year(int y){
        if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)) {
            return 1;//是闰年
        } else{
            return 0;// 不是闰年
        }
    }
    int main() {
        int year = 0;
        for (year = 1000; year <= 2000; year++) {
            //判断
            if(is_leap_year(year)){
                printf("%d ",year);
            }
        }
        return 0;
    }
    ```



- 实现一个整型有序数组的二分查找

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    
    #include <stdio.h>
    
    //二分查找函数
    int binary_search(int arr[], int k, int sz) {//arr[]是一个指针 (传递的是首元素的地址, 是一个指针变量, 而不是拷贝, 为了避免空间浪费)
        //在函数内部计算一个函数参数部分的数组的元素个数是不靠谱的
        //找到了返回下标
        //找不到返回-1
        int left = 0;
        int right = sz - 1;
    
        while (left <= right){
            int mid = left + (right-left) / 2;
            if(arr[mid] < k){
                left = mid + 1;
            } else if(arr[mid] > k){
                right = mid -1;
            } else{
                return mid;//找到了,返回下标
            }
        }
        return -1;//找不到
    }
    
    int main() {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int k = 7;
        
        int sz = sizeof(arr) / sizeof(arr[0]);//元素个数
        int ret = binary_search(arr,k,sz);//数组传递的是首元素的地址
        if (ret == -1) {
            printf("找不到");
        } else {
            printf("找打了,下标是%d", ret);
        }
        return 0;
    }
    ```

      ==数组传参, 实际上传递的是首元素的地址 (指针), 通过地址访问这个数组, 而不是把整个数组拷贝了一份, 这样可以避免内存空间的浪费==

- 写一个函数, 每调用一次num就增加一

- 方法一

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  
  #include <stdio.h>
  #include <stdbool.h>
  
  
  void Add(int *p) {
      (*p)++;
  }
  
  int main() {
      int num = 0;
      Add(&num);
      printf("%d\n", num);
      Add(&num);
      printf("%d\n", num);
      Add(&num);
      printf("%d\n", num);
      return 0;
  }
  ```

- 方法二

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  
  #include <stdio.h>
  #include <stdbool.h>
  
  int Add(int n) {
      return n + 1;//++n也可以,先计算后赋值
  }
  
  int main() {
      int num = 0;
      num = Add(num);
      printf("%d\n", num);
      num = Add(num);
      printf("%d\n", num);
      num = Add(num);
      printf("%d\n", num);
      return 0;
  }
  ```



### 7.6 函数的嵌套调用和链式访问

> 函数和函数之间可以根据实际的需求进行组合, 也就是互相调用

#### 嵌套调用

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  
  #include <stdio.h>
  #include <stdbool.h>
  
  void new_line(){
      printf("he\n");
  }
  
  void thrree_line(){
      int i = 0;
      for (i = 0; i < 3; i++) {
          new_line();//嵌套调用
      }
  }
  
  int main() {
    thrree_line();
      return 0;
  }
  ```

> 不能嵌套定义
>
> ```c
  > int Add(int x,int y){
  >     return x + y;
  >     int Sub(int x,int y){//嵌套定义
  >         return x - y;
  >     }
  > }
  > ```

#### 链式访问
> 把一个数的返回值作为其他函数的参数

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
int main() {
    int len = strlen("abcd");
    printf("%d\n",len);
    printf("%d\n",strlen("abcd"));//链式访问
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    printf("%d", printf("%d", printf("%d", 43)));//printf会返回打印的字符个数
    return 0;
}
//4321
```



### 7.7 函数的声明和定义

#### 函数的声明

- 告诉编译器函数叫什么, 参数类型是什么, 返回值类型是什么, 但是具体是不是存在, 函数声明解决不了.
- 函数的声明一般出现在函数的使用之前, 要满足***先声明后使用***
- 函数的声明一般要放在头文件中
- 头文件的声明就类似于把头文件拷贝过来的作用

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//函数声明
int Add(int,int);//int Add(int x, int y)  形参可以省略

int main() {
   int a = 0;
   int b = 0;
   scanf("%d %d",&a,&b);
   //加法
   int sum = Add(a,b);
    printf("%d\n",sum);
    return 0;
}

//函数定义
int Add(int x, int y){
    return x + y;
}
```



#### 函数的定义

- 函数的具体实现, 交代函数的功能实现

- `.h`为头文件



### 7.8 函数递归

> - 函数自己调用自己
> - 递进、回归
    >   - 函数递进使用后, 会依次回归到之前没有执行的语句, 依次执行, 直至整个递归完成
> - 大事化小
> - 只需使用少量的程序就可以描述出解题过程所需要的重复计算, 大大减少了代码量

#### 递归的两个必要条件

> 避免栈溢出

- 存在限制条件, 当满足这个条件的时候, 递归不再继续
- 每次递归调用之后, 越来越接近这个限制条件



#### 练习

- 一串数字, 单独输出

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void print(unsigned int n) {
    if (n > 9) {//         1234 t,               123 t,                12 t,              1 f,
        print(n / 10);//调用print,并传入123,   调用print,并传入12,    调用print,并传入1
    }
    printf("%d ", n % 10);//1 ,   2 ,   3 ,   4 ,

}

int main() {
    unsigned int a = 0;
    scanf("%d",&a);//1234
    print(a);
    return 0;
}
```

- 不创建临时变量, 求字符串的长度

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int my_strlen(char* str){//str指向a的地址
    if(*str != '\0'){
        return 1 + my_strlen(str + 1);//不能使用str++(先赋值后计算), ++str虽然可以,但是有副作用(当前的str值会改变)
    } else{
        return 0;
    }
}

int main() {
    int len = my_strlen("abcd");//字符串传递时, 传递的是a的地址, 和数组类似 [a b c d \0]
    printf("%d\n",len);
    return 0;
}

```



### 7.9递归与迭代

#### 练习

- 求n的阶乘, 不考虑溢出

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//递归实现
int fac(int n) {//1
    if (n >= 1) {//t  t
        return n * fac(n-1);//
    } else{
        return 1;
    }
}
//迭代方式
int a_fac(int n){
    int i = 0;
    int ret = 1;
    for(i = 1; i <= n; i++){
        ret *= i;
    }
    return ret;
}

int main() {
    int a = 0;
    while (1){
        printf("输入 >");
        scanf("%d", &a);
        int num = fac(a);
        printf("%d\n", num);
    }
    return 0;
}
```

- 求第n个斐波那契数, (不考虑溢出)  -- 递归

  > 与前两面的数字的和相加

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//递归
int fib(int n){
    if ( n <= 2){
        return 1;
    } else{
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int a = 0;
    while (1){
        printf("输入 >");
        scanf("%d",&a);
        int num = fib(a);
        printf("%d\n",num);
    }

    return 0;
}
```

> 在使用`fib`这个函数的时候, 如果我们要计算50这个斐波那契数字的时候特别耗费时间
>
> 使用`factorial`函数求 10000 的阶乘 (不考虑结果的正确性), 程序会崩溃



- 求第n个斐波那契数, (不考虑溢出)  -- 迭代

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//
int fib(int n){//4
    int a = 1;
    int b = 1;
    int c = 1;
    while (n >= 3){
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int main() {
    int a = 0;
        printf("输入 >");
        scanf("%d",&a);
        int num = fib(a);
        printf("%d\n",num);


    return 0;
}
```

> 择优选用

> ***问题:***
>
> 在使用`factorial`函数的时候, 如果你的参数比较大, 就会保报错: `stack overflow (栈溢出)`
>
> - 系统分配给程序的栈空间是有限的, 但是如果出现了死循环, 或者(死递归) , 这样有可能导致一直开辟栈空间, 最终产生栈空间耗尽的情况,  这样的现象我们称为`栈溢出`
>
> ***解决:***
>
> - 将递归改为非递归
> - 使用`static`对象替代`nonstatic`局部对象,
    >   - 在递归函数设计中, 可以使用`static`对象替代`nonstatic`局部对象 (栈对象), 这不仅可以减少每次递归调用和返回时产生和释放`nonstatic`对象的开销, 而且`static`对象还可保存递归调用的中间状态, 并且可让各个调用层所访问





> 递归的经典问题:
>
> - 汉诺塔问题
> - 青蛙跳台阶问题










## 8. 数组

> 定义:一组相同类型元素的集合

- 数组的声明: `类型 数组名 [数组长度] = {元素1,元素2,...元素n};`
    - 数组长度可以不指定
- 通过下标取值, 数组下标从0开始

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    //定义数组长度时, 必须使用常量
    int arr[] = { 1,2,3,4,5,6,7,8,9 };//定义int类型的数组,并初始化, 存入数字1-9,自动识别数组长度
    int a = 10;
    printf("%d\n",arr[a]);
    printf("%d\n", arr[8]);//数组下标从0开始,访问第9个元素,需要输入8
    return 0;
}
```

### 8.1 一维数组的创建和初始化

- 数组的创建

    - 数组是一组相同类型元素的集合

  ```c
  数组类型  数组名 [数组大小(常量表达式)]
      int  arr[8]
  ```

  > 在c99之前, `[]`中要给一个常量才行, 不能使用变量, c99标准支持了变长数组的概念

  ```c
  //变长数组
  int n = 10;
  scanf("%d",&n);
  int arr[n];//变长数组不能初始化
  ```



- 数组初始化

  > 在创建数组的同时给数组的内容一些合理的初始值 (初始化)

  ```c
  int arr1[10] = {1,2,3};//不完全初始化,其他元素默认为0,char数组也一样
  int arr2[] = {1,2,3,4};
  int arr3[5] = {1,2,3,4,5};//完全初始化
  char arr4[3] = {'a',98,'c'};
  char arr5[] = {'a','b','c'};
  char arr6[] = "abcdef";
  char arr7[10] = {'a','b','c'};//a b c 0 0 0 0 0 0 0
  char arr8[10] = "abc";//a b c \0 0 0 0 0 0 0 0 
  ```

    - 数组在创建的时候如果想不指定数组的确定大小,就得初始化
    - 数组的元素个数根据初始化的内容来确定

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  
  #include <stdio.h>
  
  int main() {
     int n = 10;
     int arr[] = {1,2,3,4,5,6,7,8,9,10};
      int sz = sizeof(arr) / sizeof(arr[0]);
      int i = 0;
      for(i = 0;i < sz; i++){
          printf("%d ",arr[i]);
      }
      return 0;
  }
  ```


### 8.2 一维数组的使用

- 数组是通过下标来访问的,下标从0开始
- 数组大小可以通过计算得到

  ```c
  int arr[10];
  int sz = sizeof(arr) / sizeof(arr[0]);//数组的总占用的空间大小除以它一个元素所占用空间的大小
  ```



### 8.3 一维数组在内存中的存储

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//打印数组每个元素的地址
int main() {
    int n = 10;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for (i = 0; i < sz; i++) {
        printf("&arr[%d]%p\n", i, &arr[i]);
    }
    return 0;
}
//&arr[0]000000D74B4FFAF8
//&arr[1]000000D74B4FFAFC
//&arr[2]000000D74B4FFB00
//&arr[3]000000D74B4FFB04
//&arr[4]000000D74B4FFB08
//&arr[5]000000D74B4FFB0C
//&arr[6]000000D74B4FFB10
//&arr[7]000000D74B4FFB14
//&arr[8]000000D74B4FFB18
//&arr[9]000000D74B4FFB1C
```
- 内存
```c
//内存地址            十六进制值
0x000000039C4FFA68  01 00 00 00  ....//下标为0的元素
0x000000039C4FFA6C  02 00 00 00  ....//下标为1的元素  与上下差4个字节
0x000000039C4FFA70  03 00 00 00  ....
0x000000039C4FFA74  04 00 00 00  ....
0x000000039C4FFA78  05 00 00 00  ....
0x000000039C4FFA7C  06 00 00 00  ....
0x000000039C4FFA80  07 00 00 00  ....
0x000000039C4FFA84  08 00 00 00  ....
0x000000039C4FFA88  09 00 00 00  ....
0x000000039C4FFA8C  0a 00 00 00  ....
//数组在内存中是连续存放的
```

- 随着数组下标的增长, 元素的地址也在有规律地递增, 所以***数组在内存中是连续存放的***

| 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

​        低地址                ------------------------------------------------------------------------------------------------------------------------------------------------------->>>                       高地址



### 8.4 二维数组的创建和初始化

- 二维数组的创建

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//打印数组每个元素的地址
int main() {
    //数组的创建
    int arr1[3][4];//3行4列
    //1 2 3 4
    //2 3 4 5
    //3 4 5 6
    char arr2[3][4];
    double arr3[2][4];
    return 0;
}

```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//打印数组每个元素的地址
int main() {
    //数组的创建
    int arr1[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
    //1 2 3 4
    //2 3 4 5
    //3 4 5 6
    int arr2[3][4] = { {1,2},{3,4},{5,6} };//分组
    //1 2 0 0
    //3 4 0 0
    //5 6 0 0
    return 0;
}
//arr1
//01 00 00 00   02 00 00 00   03 00 00 00   04 00 00 00   │ ················ │
//02 00 00 00   03 00 00 00   04 00 00 00   05 00 00 00   │ ················ │
//03 00 00 00   04 00 00 00   05 00 00 00   06 00 00 00   │ ················ │

//arr2
//01 00 00 00   02 00 00 00   00 00 00 00   00 00 00 00   │ ················ │
//03 00 00 00   04 00 00 00   00 00 00 00   00 00 00 00   │ ················ │
//05 00 00 00   06 00 00 00   00 00 00 00   00 00 00 00   │ ················ │
```



- 二维数组的初始化

```c
//二维数组可以省略行,但是列的元素个数必须标明
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//打印数组每个元素的地址
int main() {
    int arr1[][4] = { {1,2,3,4},{3,4} };//分组
    //1 2 3 4
    //3 4 0 0 
    int arr2[][4] = { 1,2,3,4,5,6 };
    //1 2 3 4
    //5 6
        return 0;
}
```





### 8.5 二维数组的使用

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
    int arr1[3][4] = {1,2,3,4,2,3,4,5,3,4,5,6};//分组
    //1 2 3 4
    //2 3 4 5
    //3 4 5 6
        return 0;
}
```

| 下标 | 0    | 1    | 2    | 3    |
| ---- | ---- | ---- | ---- | ---- |
| 0    | 1    | 2    | 3    | 4    |
| 1    | 2    | 3    | 4    | 5    |
| 2    | 3    | 4    | 5    | 6    |

```C
#define _CRT_SECURE_NO_WARNINGS
//遍历输出
#include <stdio.h>
int main() {
    int arr[3][4] = {1,2,3,4,2,3,4,5,3,4,5,6};//分组
    //1 2 3 4
    //2 3 4 5
    //3 4 5 6
    int i = 0;
    for (i = 0; i < 3; i++) {
        int j = 0;
        
        for (j = 0; j < 4; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
        return 0;
}
//1 2 3 4 
//2 3 4 5
//3 4 5 6
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
    int arr[3][4] = {1,2,3,4,2,3,4,5,3,4,5,6};//分组
    //1 2 3 4
    //2 3 4 5
    //3 4 5 6
    arr[2][0] = 12;//修改值
    int i = 0;
    for (i = 0; i < 3; i++) {
        int j = 0;
        
        for (j = 0; j < 4; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
        return 0;
}
```

> 二维数组可以理解为一维数组的数组



### 8.6 二维数组在内存中的使用

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
    int arr[3][4] = {1,2,3,4,2,3,4,5,3,4,5,6};//分组
    //1 2 3 4
    //2 3 4 5
    //3 4 5 6
    int i = 0;
    for (i = 0; i < 3; i++) {
        int j = 0;
        for (j = 0; j < 4; j++) {
            printf("&arr[%d][%d] = %p\n",i,j,&arr[i][j]);
        }
    }
    return 0;
}
//&arr[0][0] = 0000009062dff690      相差4个字节 连续存放 
//&arr[0][1] = 0000009062dff694
//&arr[0][2] = 0000009062dff698
//&arr[0][3] = 0000009062dff69c
//&arr[1][0] = 0000009062dff6a0
//&arr[1][1] = 0000009062dff6a4
//&arr[1][2] = 0000009062dff6a8
//&arr[1][3] = 0000009062dff6ac
//&arr[2][0] = 0000009062dff6b0
//&arr[2][1] = 0000009062dff6b4
//&arr[2][2] = 0000009062dff6b8
//&arr[2][3] = 0000009062dff6bc
```

- 可以看作是一个一维数组

  ```c
  arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}//二维数组
  //内存:1 2 3 4 5 6 7 8 9 10 11 12
  arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12}//一维数组
  //内存:1 2 3 4 5 6 7 8 9 10 11 12
  //内存中的体现是完全一样的, 只是访问形式不同
  ```

==二维数组的列内容是必须的, 因为只有知道了列 (一行有几个元素) 才能放入元素, (固定一行元素的个数后, 其余未放入的元素只需往后放)==



### 8.7 数组越界

- 数组的下标是有范围限制的
- 数组的下标是从`0`开始的,如果数组有`n`个元素, 最后一个元素的下标就是`n-1`
- 所以数组的下标如果小于`0`, 或者大于`n-1`, 就是数组越界访问了, 超出了数组合法空间的访问
- C语言本身不做下标越界检查, 编译器也不一定报错, 但是编译器不报错也不意味着程序就是正确的
- ***所以写程序时最好自己做越界的检查***

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//一维数组
int main() {
    int arr[] = { 1,2,3,4,5,6, };//末尾下标为5
    int i = 0;
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
//编译器不报错
//1 2 3 4 5 6 -858993460 -858993460 -858993460 -858993460
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//二维数组
int main() {
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int i = 0;
    for (i = 0; i < 3; i++) {
        int j = 0;
        for (j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    return 0;
}
//编译器不报错
//1 2 3 4 5 5 6 7 8 9 9 10 11 12 -858993460
```



### 8.8 数组作为函数参数

- 冒泡排序

  > ***两个相邻的元素进行比较***
  >
  > 9 8 7 6 5 4 3 2 1
  >
  > 8 9 7 6 5 4 3 2 1
  >
  > 8 7 9 6 5 4 3 2 1
  >
  > 8 7 6 9 5 4 3 2 1
  >
  > 8 7 6 5 9 4 3 2 1
  >
  > 8 7 6 5 4 9 3 2 1
  >
  > 8 7 6 5 4 3 9 2 1
  >
  > 8 7 6 5 4 3 2 9 1
  >
  > 8 7 6 5 4 3 2 1 9
  >
  > 7 8 6 5 4 3 2 1 9
  >
  > ......
  >
  > 1 2 3 4 5 6 7 8 9

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//冒泡排序 ?
//升序
//mielgo
void bubble_sort1(int arr[], int sz) {  //数组传参: 1.数组 (int arr[])  2.指针(int* arr)   无论什么传参形式,函数得到的都是一个指针(首元素的地址)
    int i = 0;
    //一个数的排序趟数
    for (i = 0; i < sz - 1; i++) { //i不可大于8否则会越界
        if (arr[i] > arr[i + 1]) {
            int a = 0;
            a = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = a;

            //输出
            int j = 0;
            for (j = 0; j < sz; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");

            //8 7 6 5 4 3 2 1 0 9  10
            //判断当前是否为能支持排序的最大值
            //7 6 5 4 3 2 1 0 8 9  10
            //如果下一个数是末尾, 或者下一个数大于上一个数字
            if (arr[i + 1] == arr[sz - 1] || (arr[i + 1]) > arr[i - 1]) {
                bubble_sort1(arr, sz);//递归
            }
        }
    }
}
//t
void bubble_sort2(int arr[], int sz) {
    //趟数
    int i = 0;
    for (i = 0; i < sz - 1; i++) {
        //一趟冒泡排序
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                //交换
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


int main() {
    int arr[] = { 9, 8,324, 7, 6, 5, 4, 8989,3, 2, 1, 0,89,66,45,76,423,2123,222 };
    int sz = sizeof(arr) / sizeof(arr[0]);//10
    bubble_sort1(arr, sz);//数组传参直接给数组名即可

    //打印
    int i = 0;
    for (i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

```

- //数组传参: 1.数组 (int arr[])  2.指针(&arr)   无论什么传参形式,函数得到的都是一个指针(首元素的地址)
- 数组名是什么?

> 数组名是什么:
>
> > 一维数组
>
> - 数字名能表示首元素的地址(绝大多数情况)
> - 两个意外:
    >   - sizeof(数组名) 这里的数组名表示整个数组, 计算的是整个数组的大小, 单位是字节
>   - &数组名, 这里的数组名表示的是整个数组, 取出的是整个数组的地址
>
> ```c
> #define _CRT_SECURE_NO_WARNINGS
> 
> #include <stdio.h>
> //一维数组
> int main() {
>     int arr[10];
>     printf("%p\n", arr);//arr就是首元素的地址
>     printf("%p\n", arr+1);
>     
>     printf("-----------------\n");
>     printf("%p\n", &arr[0]);//首元素的地址
>     printf("%p\n", &arr[0]+1);
>     
>     printf("-----------------\n");
>     printf("%p\n", &arr);//整个一维数组的地址
>     printf("%p\n", &arr+1);
>     
>     printf("-----------------\n");
>     int n = sizeof(arr);
>     printf("%d\n", n);
> 
> 
>     return 0;
> }
> //000000e4685ffbc0    
> //000000e4685ffbc4       间隔4
> //-----------------
> //000000e4685ffbc0
> //000000e4685ffbc4       间隔4
> //-----------------
> //000000e4685ffbc0
> //000000e4685ffbe8       间隔40
> //-----------------
> //40
> ```
>
>
>
> > 二维数组
>
> ```c
> #define _CRT_SECURE_NO_WARNINGS
> 
> #include <stdio.h>
> //二维数组
> 
> // 1 2 3 4 此行为首元素地址 16字节
> // 2 3 4 5
> // 3 4 5 6
> // 二维数组中,首元素的地址是第一行的地址,即arr[1][x]
> int main() {
>     int arr[3][4];
>     int sz = sizeof(arr); //数组总大小: 3行 * 4列 * 4字节 = 48
>     printf("%p\n", arr);//arr就是首元素的地址,
>     printf("%p\n", arr + 1);
>     printf("-----------------\n");
>     printf("%p\n", &arr[0]);//首元素的地址
>     printf("%p\n", &arr[0] + 1);
>     printf("-----------------\n");
> 
>     printf("%p\n", &arr);//整个二维数组的地址
>     printf("%p\n", &arr + 1);
>     printf("-----------------\n");
>     printf("%d\n", sz);
> 
>     printf("-----------------\n");
>     printf("%p\n", sizeof(arr) / sizeof(arr[0]));// 数组总大小48字节 / 第一行的数组名16字节  = 3
>     printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));//第一行的大小16字节 / 第一个第一个元素大小 4字节  = 4
>     return 0;
> }
> 
> //00000052607ff820
> //-----------------
> //00000052607ff810
> //00000052607ff840
> //-----------------
> //48
> //-----------------
> //0000000000000003
> //4
> ```
>
>



### 8.9 案例



#### 三指棋



#### 扫雷游戏






## 9. 操作符

### 9.1 算术操作符

- +
- -
- *
- /
- % 余数

> 除了`%`操作符之外,其他的几个操作符可以用作整数和浮点数
>
> 对于`/`操作符, 如果两个操作符都为整数, 执行整数除法, 而只要有浮点数执行的就是浮点数除法
>
> `%`操作符的两个而操作数必须是整数, 返回的是整除之后的余数,

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a = 7 / 2;//除号两端都是整数的时候,执行的是整数除法,如果两端有一个浮点数,就执行浮点数除法
    float b = 7.0 / 2;//两端有至少一个浮点数,执行浮点数除法
    int c = 7 % 2;//取模操作符的两端必须是整数
    printf("%d\n", a);
    printf("%.1f\n", b);//小数点后面打印一位
    printf("%.2f\n", b);//小数点后面打印两位
    printf("%d\n", c);
    return 0;
}

//3
//3.5 
//3.50
//1  
```



### 9.2 移位操作符

> 移动的是二进制位
>
> 移位操作符的操作数需要是正数
>
> 操作数只能是整数

- <<  左移操作符
    - 左移有乘二的效果

- \>>  右移操作符

  > 移位方式取决于编译器, 多数都是算术右移

    - 算术移位
        - 右边丢弃, 左边补原符合位

    - 逻辑移位
        - 右边丢弃, 左边补零

> 左移

```c
#include <stdio.h>
//正数
int main() {
    int a = 7;
    int b = a << 1;//左移操作符
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    return 0;
}
//a=7
//b=14
//a不变
```

```c
#include <stdio.h>
//负数
int main() {
    int a = -7;
    int b = a << 1;//左移操作符
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    return 0;
}
//a=-7
//b=-14
```

> 右移

```c
#include <stdio.h>
//正数
int main() {
    int a = 7;
    int b = a >> 1;//右移操作符
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    return 0;
}
//a=7
//b=3
```

```c
#include <stdio.h>
//负数
int main() {
    int a = -7;
    int b = a >> 1;//左移操作符
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    return 0;
}
//a=-7
//b=-4
```



#### 二进制

- 整数的二进制有三种
    - 原码
    - 反码
    - 补码
- 正整数的原码、反码、补码相同
- 负整数的源码、反码、补码需要计算

```c
// 7
7 为正整数
二进制: 111
//1*4 + 1*2 + 1*1 = 4+2+1 = 7
//二进制序列
//00000000 00000000 00000000 00000111  ---原码
//00000000 00000000 00000000 00000111  ---反码
//00000000 00000000 00000000 00000111  ---补码
//第一位是高位, 符号位, 为0表示它是正数, 为一表示为负数


//-7
-7为负数
二进制:
//10000000 00000000 00000000 00000111  ---原码
//反码: 原码的符号位不变, 其他位按位取反  
//11111111 11111111 11111111 11111000  ---反码
//补码: 反码加一
//11111111 11111111 11111111 11111001  ---补码

//整数(正数和负数)在内存中存储的是二进制补码
```

> 左移

```c
//正数
位移操作移的是内存中的补码
//7
左移
//00000000000000000000000000000111  ---反码
//00000000000000000000000000001110  ---左移一位, 左边丢弃, 右边补零
//8*1 + 4*1 + 2*1 + 1*0 = 8+4+2 = 14  

```

```c
//负数
//-7
//反码: 原码的符号位不变, 其他位按位取反  
//11111111111111111111111111111001  ---补码
//11111111111111111111111111110010  ---左移一位, 左边丢弃, 右边补零
//11111111111111111111111111110001  ---补码减一得到反码
//10000000000000000000000000001110  ---反码按位取反得到原码, 符号位不变
//-(8*1 + 4*1 + 2*1 + 1*0) = -(8+4+2+0) = -14 
```

> 右移 (算术移位)

```c
//正数
//7
//00000000000000000000000000000111  ---补码
//00000000000000000000000000000011  ---右边丢弃, 左边补原符号位
//2*1 + 1*1 = 2+1 = 3
```

```c
//负数
//-7
//11111111111111111111111111111001  ---补码
//算术移位
//11111111111111111111111111111100  ---补码, 右边丢弃, 左边补原符号位
//11111111111111111111111111111011  ---补码减一得到反码
//10000000000000000000000000000100  ---反码按位取反得到原码, 符号位不变
//-(4*1 + 2*0 + 2*0) = -(4+0+0) = -4
```



### 9.3 位操作

- &  按 (二进制) 位与
    - 按位与: 两个对应为同时为 1 结果才为 1
- ^   按 (二进制) 位异或
    - 按位异或: 相同为 0 ,不同为 1
    - 异或操作符支持交换律 (交换位置结果不变)(a+b = b+a; a*b = b\*a)
- |   按 (二进制) 位或
    - 按位或: 两个对应位只要有一个为 1 结果就为 1 , 两个同时为 0 才为零

```c
#include <stdio.h>
//&  按位与
int main() {
    int a = 3;
    int b = -5;
    int c = a & b;//
    printf("c = %d", c);
    return 0;
}
//c = 3

//a的二进制补码
//00000000000000000000000000000011  ---3的原码、反码、补码相同
//b的二进制补码
//10000000000000000000000000000101  --- -5的原码
//11111111111111111111111111111010  ---反码: 符号位不变, 其他位按位取反
//11111111111111111111111111111011  ---补码: 反码加一

//按位与: 两个对应为同时为 1 结果才为 1
//00000000000000000000000000000011  --- 3的补码
//11111111111111111111111111111011  --- 5 的补码
//00000000000000000000000000000011  ---按位与的结果
//%d: 打印一个有符号的整数
//正数源码、补码、反码相同
//00000000000000000000000000000011
//2*1 + 1*1 = 3
```

```c
#include <stdio.h>
//按位或
int main() {
    int a = 3;
    int b = -5;
    int c = a | b;//
    printf("c = %d", c);
    return 0;
}
//c = -5

//a的二进制补码
//00000000000000000000000000000011  ---3的原码、反码、补码相同
//b的二进制补码
//10000000000000000000000000000101  --- -5的原码
//11111111111111111111111111111010  ---反码: 符号位不变, 其他位按位取反
//11111111111111111111111111111011  ---补码: 反码加一

//按位或: 两个对应位只要有一个为 1 结果就为 1 , 两个同时为 0 才为零
//00000000000000000000000000000011  ---3的补码
//11111111111111111111111111111011  ---5的补码
//11111111111111111111111111111011  ---按位或的结果

//符号位为负, 补需要计算
//11111111111111111111111111111011  ---补码
//11111111111111111111111111111010  ---反码: 补码减一
//10000000000000000000000000000101  ---原码: 符号位不变, 其他位按位取反
//-(4*1 + 2*0 + 1*1) = -(4+1) = -5
```

==%d: 打印一个有符号的整数 ,打印的是原码==

```c
#include <stdio.h>
//按位或
int main() {
    int a = 3;
    int b = -5;
    int c = a ^ b;//
    printf("c = %d", c);
    return 0;
}
//c = -8

//a的二进制补码
//00000000000000000000000000000011  ---3的补码
//b的二进制补码
//10000000000000000000000000000101  --- -5的原码
//11111111111111111111111111111010  ---反码: 符号位不变, 其他位按位取反
//11111111111111111111111111111011  ---补码: 反码加一

//按位异或: 相同为 0 ,不同为 1 
//00000000000000000000000000000011  ---3的补码
//11111111111111111111111111111011  ---5的补码
//11111111111111111111111111111000  ---按位异或的结果

//符号位为负, 结果需要计算
//11111111111111111111111111111000  ---补码
//11111111111111111111111111110111  ---反码: 补码减一
//10000000000000000000000000001000  ---补码: 符号位不变, 其他位按位取反
//-(8*1 + 4*0 + 2*0 + 1*0) = -(8+0+0+0) = -8
```

- 不创建临时变量, 进行两个数的交换

```c
#include <stdio.h>
//按位或
int main() {
    int a = 3;
    int b = 5;
    //只适用于整型
    printf("交换前 a = %d,b = %d\n",a,b);
    a = a ^ b;// 3 ^ 5 = 6
    b = a ^ b;// 6 ^ 5 = 3
    a = a ^ b;// 6 ^ 3 = 5
    printf("交换后 a = %d,b = %d\n",a,b);
    return 0;
}
//3 ^ 3 = 0  -->  a ^ a = 0
//异或:相同为0, 不同为1
//011
//011
//000
//0 ^ 5 = 5  -->  0 ^ a = a
//000
//101
//101

//3 ^ 3 ^ 5 = 5
//3 ^ 5 ^ 3 = 5
//011 --3
//101 --5
//110
//011 --3
//101
//异或操作符支持交换律 (交换位置结果不变)
//实际开发中使用的都是创建临时变量, 交换两个数的值
```

- 求一个整数存储在内存中的二进制中 1 的个数
    - 存在内存的是补码: 求补码二进制中 1 的个数

```c
#include <stdio.h>
//按位或
int main() {
    int a = ;
    int i = 0;
    int c = 0;
    int d = 0;
    for(i = 0;i<=32;i++){
        d = a & 1;
        if(d != 0){
            c = c + d;
        }
        a = a >> 1;
    }
    printf("%d",c);
    return 0;
}
//按位与: 两个对应为同时为 1 结果才为 1
//00000000000000000000000000000011 --3 依次左移
//00000000000000000000000000000001
//00000000000000000000000000000001 --结果为一, 记作统计次数
```



### 9.4 赋值操作

- = 赋值

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
        int a = 10;//初始化
        a = 20;//赋值
        a = a + 10;//a=30
        a += 10;//同a = a + 10   a=40
        return 0;
    }
    ```

> 复合赋值

- +=
- -=
- */
- /=
- ^=
- |=
- \>>=
- <<=

> 连续赋值

```c
#include <stdio.h>
//按位或
int main() {
    int a = 10;
    int x = 0;
    int y = 20;
    a = x = y + 1;//连续赋值  不建议这样写,可读性差
    printf("%d",a);
    return 0;
}

```

> +=

```c
#include <stdio.h>
//按位或
int main() {
    int a = 10;
    a += 5;//a = a + 5
    printf("%d",a);
    return 0;
}
```

>  \>\>=

```c
#include <stdio.h>
//按位或
int main() {
    int a = 7;
    a >>= 1;//a = a >> 1

    printf("%d",a);
    return 0;
}
//0111 --7
//0011 --3
```





### 9.5 单目操作符

> !   \+    \-    &    sizeof   ~    --    ++    *   (类型)

> c语言中`0`为假, 非`0`为真

> 只有一个操作数的操作
>
> a + b有两个操作数, 所以数双目操作符

- ! 逻辑反操作

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	int flag = 0;//0为假
    	if (!flag)
    	{
    		printf("output");
    	}
    }
    //output
    ```

- \-  负值

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	int a = -10;
    	int b = +a;//+ 表示什么都不变
    	int c = -a;
    	printf("%d\n", a);
    	printf("%d\n", b);
    	printf("%d\n", c);
    }
    //-10
    //-10
    //10
    ```

- \+  正值

    - ```c
    #include <stdio.h>
    
    int main() {
        int a = 7;
        int b = -7;
        a = +a;
        b = +b;//正号对于负数值没有影响
        printf("%d\n", a);
        printf("%d\n", b);
        int c = 3;
        int d = -3;
        c = -c;
        d = -d;
        printf("%d\n", c);
        printf("%d\n", d);
    
        return 0;
    }
    //7
    //-7
    //-3
    //3 
    ```

- &  取地址

    - 使用`%p`格式打印

    - ```c
    #include <stdio.h>
    
    int main() {
        int a = 7;//int类型占用4个字节
        printf("%p\n", &a);//取出a的地址 &a为a的起始地址(首位一个字节的地址)
        int* p = &a;//p用于存放a的地址, p就是指针,存放的a是int类型, 所以指针p是int类型
        return 0;
    }
    //00000071b23ffcac
    ```



- sizeof  操作数的类型长度 （以字节为单位）

  > sizeof是操作符, 不是函数
  >
  > strlen是库函数, 是用来求字符串长度的

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
        int a = 10;//int类型占用4个字节 00000000 00000000 00000000 00000000
        int arr[10] = { 0 };//10个int
    
        printf("%d\n", sizeof(a));//a所占内存的大小, 单位是字节  
        printf("%d\n", sizeof a);
        // 计算的是变量所占内存空间的大小
        // 计算类型所创建的变量占据内存空间的大小
        printf("%d\n", sizeof(int));//int类型所所创建的变量占内存空间的大小
        
        printf("%d\n", sizeof(arr));//计算的是整个数组的大小,单位是字节
        printf("%d\n", sizeof(arr[0]));//计算的是数组单个元素的大小,单位是字节
        printf("%d\n", sizeof(arr) / sizeof(arr[0]));//10 数组的元素个数
    }
    //4
    //4
    //4
    //40
    //4
    //10
    ```

- ~  对一个数的二进制按位取反

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>
  
  int main()
  {
      int a = 0;
      //~ 按位取反
      //00000000 00000000 00000000 00000000  -- 补码(正数的源码、补码、反码相同)
      
      //11111111 11111111 11111111 11111111  -- ~a的补码
      //11111111 11111111 11111111 11111110  -- 反码: 补码减一
      //10000000 00000000 00000000 00000001  -- 原码: 补码保留符号位, 按位取反
      printf("%d\n", ~a);//打印的是原码
      return 0;
  }
  //-1
  ```

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>
  
  int main()
  {
      int a = 3;
      //~ 按位取反
      //00000000 00000000 00000000 00000011  -- 补码(正数的源码、补码、反码相同)
  
      //11111111 11111111 11111111 11111100  -- ~a的补码
      //11111111 11111111 11111111 11111011  -- 反码: 补码减一
      //10000000 00000000 00000000 00000100  -- 原码: 补码保留符号位, 按位取反
      printf("%d\n", ~a);//打印的是原码
      return 0;
  }
  //-4
  ```

  > 把特定的位该为1

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>
  
  int main()
  {
      int a = 13;
      //~ 按位取反
      //00000000 00000000 00000000 00001101  -- 补码(正数的源码、补码、反码相同)
      //把00001101改成00001111
      //按位或 |
      //00000000 00000000 00000000 00001101   ---- a = 13
      //00000000 00000000 00000000 00000010   ---- 1
      //1 << 1     1的二进制向左移动1位
      //00000000 00000000 00000000 00001111   ---- 15
       a |= (1 << 1); //a = a | (1 << 1)
  
      printf("%d\n", a);//打印的是原码
      return 0;
  }
  //15
  ```

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>
  
  int main()
  {
      int a = 13;
      //~ 按位取反
      //00000000 00000000 00000000 00001101  -- 补码(正数的源码、补码、反码相同)
      //效果:a = 29
      //--------------------------把00001101改成00011101----------------------
      //00000000 00000000 00000000 00000010   ---- 或
      //按位或 |
      //00000000 00000000 00000000 00001101   ---- a = 13
      //00000000 00000000 00000000 00000010   ---- 1
      
      //1 << 4     1的二进制向左移动4位
      //00000000 00000000 00000000 00000001   ---- 1位
      //00000000 00000000 00000000 00010000   ---- 左移4位
      
      //或: 两个对应位只要有一个为 1 结果就为 1 , 两个同时为 0 才为 0
      //00000000 00000000 00000000 00001101  -- 补码
      //00000000 00000000 00000000 00010000   ----左移后的二进制
      //00000000 00000000 00000000 00011101   ----29
      // 16*1 + 8*1 + 4*1 + 2*0 + 1*1 = 16+8+4+0+1 = 29
      //过程:
      //1按位左移4位 --> 按位或 原数--> 得到
       a |= (1 << 4); //a = a | (1 << 1)
      printf("a = %d\n", a);//打印的是原码
      
      
      //此时 a = 29, 改回13
      //--------------------------把00011101改成00001101----------------------
      //按位与: 两个对应位只要有一个为 0 结果就为 0 , 两个同时为 1 才为1
      //00000000 00000000 00000000 00011101   ----29
      //11111111 11111111 11111111 11101111   ----需要按位与的二进制 (下面操作)
      //00000000 00000000 00000000 00001101   ----按位与的结果
  
      //获得按位与的二进制
      //00000000 00000000 00000000 00010000   ----按位取反 (下面操作)
      //11111111 11111111 11111111 11101111   ----获得按位与的二进制
  
      //1<<4
      //00000000 00000000 00000000 00000001   ----1
      //00000000 00000000 00000000 00010000   ----1左移4位
      //过程:
      //1按位左移4位 --> 按位取反 --> 按位与 原数--> 得到
      a &= ~(1 << 4);
      printf("a = %d\n", a);
      
      return 0;
  }
  
  //a = 29
  //a = 13
  ```



- --  前置、后置 --

  ```c
  #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>
  
  int main()
  {
      int a1 = 10;
      int a2 = 10;
  
      int b = a1--;//先使用, 后--   b=a1  a1=a1-1
      printf("b = %d\n", b);//10
      printf("a1 = %d\n", a1);//9
  
  
      int c = --a2;//先--, 后使用   a2=a2-1  b=a2
      printf("c = %d\n", c);//9
      printf("a2 = %d\n", a2);//9
  
  }
  //b = 10
  //a1 = 9
  //c = 9
  //a2 = 9
  ```



- ++ 前置、后置 ++

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
        int a1 = 10;
        int a2 = 10;
    
        int b = a1++;//先使用, 后++   b=a1  a1=a1+1
        printf("b = %d\n", b);//10
        printf("a1 = %d\n", a1);//10
    
    
        int c = ++a2;//先++, 后使用   a2=a2+1  b=a2
        printf("c = %d\n", c);//11
        printf("a2 = %d\n", a2);//11
        printf("a2 = %d\n",a2--);
        printf("a2 = %d\n", a2);
    }
    //b = 10
    //a1 = 11
    //c = 11
    //a2 = 11
    //a2 = 11
    //a2 = 10
    ```

      ```c
      #define _CRT_SECURE_NO_WARNINGS
      #include <stdio.h>
      
      int main()
      {
          int a = 10;
        a = a++ + ++a;// a++ = 使用a=10 自增a=11         使用a=11    ++a = 11+1 = 12   10 + 12 = 22
          printf("%d",a);
      }
      //22
      ```



- \*  间接访问操作符（解引用操作符）

  > 配合指针使用         `&   *`
  >
  > ```c
  > #define _CRT_SECURE_NO_WARNINGS
  > #include <stdio.h>
  > 
  > int main()
  > {
  >     int a = 10;
  >   int* p = &a;//p存的是一个指针(a的内存地址)
  >     printf("十六进制数值 = %p\n",*p);//*p 通过p的指针,找到它所存的对象  打印十六进制数值
  >     printf("十六进制地址 = %p\n",p);// 打印十六进制地址
  >     
  >     *p = 20;//解地址操作符 通过指针去改a的值
  >     printf("十六进制数值 = %p\n",*p);//  打印十六进制数值
  >     printf("十六进制地址 = %p\n",p);//打印十六进制地址
  >     printf("a = %d\n",*p);//输出整型
  > }
  > //十六进制数值 = 000000000000000a
  > //十六进制地址 = 000000fb8b5ffd04
  > //十六进制数值 = 0000000000000014
  > //十六进制地址 = 000000fb8b5ffd04
  > //a = 20
  > ```

- (类型)  强制类型转换

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	int a = (int)3.14;//字面浮点数, 编译器默认理解为double类型
    	printf("%d\n", a);//
    }
    //3
    ```



> 练习

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void test1(int arr[]) { //传入的是第一个元素的内存地址 (指针)
    printf("%d\n", sizeof(arr));//4或8   x86环境为4
}
void test2(char ch[]) {//传入的是第一个元素的内存地址 (指针)  指针变量都是4或8
    printf("%d\n", sizeof(ch));
}
int main()
{
    int arr[10] = { 0 };
    char ch[10] = { 0 };
    printf("%d\n", sizeof(arr));//40
    printf("%d\n", sizeof(ch));//10
    test1(arr);//40
    test2(ch);//10
    return 0;
}
//40
//10
//4
//4
```



### 9.6 关系操作符

- \>

- \>=

- \<

- \<=

- !=  不等于

- ==  等于

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	int a = 10;
        //0表示假, 非0表示真
    	if (a = 3) {//此时是赋值运算  if条件恒成立
    		printf("%d\n",a);//3
    	}
    	int b = 10;
    	if (b == 3)//条件为假, 不执行{}内的代码
    	{
    		printf("%d\n", b);
    	}
    }
    ```

      > 字符串不能使用 `==` 比较相等,
      >
      > - "abc" == "def"
      > - 实际比较的是 `a` 的地址和 `d` 的地址
      > - 使用 `strcmp` 库函数比较

### 9.7 逻辑操作符

- `&&` 逻辑与
    - 只要有一个为假, 则为假
- `||` 逻辑或
    - 只要有一个为真, 则为真

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;//if中0为假
	
	if (a && b) //逻辑与, 见false则false
	{
		printf("ok\n");
	}
	if (c || a)//逻辑或, 见true则true
	{
		printf("yes");
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a = 3;
    int b = 5;
    int c = a && b;//逻辑与的结果为真, 真为1, 否则为0
    printf("%d",c);
    return 0;
}
//1
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = a || b;
    printf("%d",c);
    return 0;
}
//1
```

> 练习

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i = 0;
    int a = 0;
    int b = 2;
    int c = 3;
    int d = 4;
    i = a++ && ++b && d++;//使用a=0  自增a=1  a为0时逻辑与必定为假, 不再运算b的值, 且不再进行其余操作

    printf("a=%d b=%d c=%d d=%d",a,b,c,d); //a=1 b=2 c=3 d=4
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i = 0;
    int a = 0;
    int b = 2;
    int c = 3;
    int d = 4;
    i = a++ || ++b || d++;//使用a=0  自增a=1  b=3   前两个逻辑为真,或运算的结果必定为真,不再进行后面的运算
    
    printf("a=%d b=%d c=%d d=%d",a,b,c,d); //a=1 b=3 c=3 d=4
    return 0;
}
```



### 9.10 条件操作符

> 三目操作符

- `exp1 ? exp2 : exp3`

- 表达式1 **?**  表达式2 **:** 表达式3

-    真             执行              X

-    假                X               执行

- ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	int a = 10;
    	int b = 20;
    	int c = a > b ? a : b;
    	printf("%d\n", c);
    	return 0;
    }
    //20
    ```



### 9.11 逗号表达式

> 逗号隔开的一串表达式
>
> 特点: 从左向右一次计算, 整个表达式的结果是最后一个表达式的结果

- exp1, exp2, exp3, ...expN

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	int a = 10;
    	int b = 20;
    	int c = 0;
    	int d = (c = a - 2, a = b + c, c - 3);
    	printf("%d\n", d);
    	return 0;
    }
    //
    ```

      ```c
      #define _CRT_SECURE_NO_WARNINGS
      #include <stdio.h>
      
      int main()
      {
          int a = 0;
          int b = 0;
          while (a = a + 1, b = b + a, b < 10 && a<5) {
              printf("output\n");
          }
          return 0;
      }
      //output
      //output
      //output
      ```





### 9.12 下标引用、函数调用和结构成员

- `[]`  下标引用操作数

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
        int arr[10] = { 1,2,3,4,5,6,7,8,9 };//[]定义语法, 不是操作符  初始化
        printf("%d\n", arr[3]);//arr和3是[]的操作数, []是下标引用操作符
        6[arr] = 10;
        arr[7] = 20;
    
        //arr[7] --> *(arr+7) --> *(7+arr) -->7[arr]
        //arr是数组首元素的地址
        //*(arr+7)跳过七个元素, 指向第八个元素,下标为7
        *(arr+8) = 30;
        *(arr+9) = 40;
    
        for(int i = 0;i<10;i++){
            printf("arr[%d] = %d\n",i,arr[i]);
        }
        return 0;
    }
    //4
    //arr[0] = 1 
    //arr[1] = 2 
    //arr[2] = 3 
    //arr[3] = 4 
    //arr[4] = 5 
    //arr[5] = 6 
    //arr[6] = 10
    //arr[7] = 20
    //arr[8] = 30
    //arr[9] = 40
    ```

- `() `  函数调用操作符

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    int Add(int x,int y)
    {
    	return x  +y;
    }
    int main()
    {
    	int sum = Add(2, 3);//()是函数调用操作符, Add 、2、3都是()的操作符
    	printf("%d\n", sum);
    	return 0;
    }
    ```

      ```c
      #define _CRT_SECURE_NO_WARNINGS
      #include <stdio.h>
      int  Add(int a,int b){//函数定义
          return a+b;
      }
      int main()
      {
          int a = 10;
          int b = 20;
          int c = Add(a,b);//函数调用操作符  操作数是Add,a,b  函数调用最少有一个操作数
          //sizeof a 的括号可以省略, 所以它不是函数
          printf("%d",c);
          return 0;
      }
      //30
      ```

> 结构成员操作符

- `.`        结构体`.`成员名
- `->`        结构体指针`->` 成员名

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Stu{
    char name[20];
    int age ;
    double score;
};
void set_stu(struct Stu* ps){
//    strcpy((*ps).name,"lisa") ;
//    (*ps).age = 20;
//    (*ps).score = 100.0;
   //上面的   *(ps).age 等价于 ps->age
    strcpy(ps->name,"lisa");
    ps->age = 20;//->的左边是结构体指针, 通过箭头找到它的成员
    ps->score = 100.0;
}
void print_stu(struct Stu ss){
    printf("%s %d %lf\n",ss.name,ss.age,ss.score);// . 的左边是结构体对象, 通过点找到它的成员
}
int main()
{
    struct Stu s ={0};
    set_stu(&s);
    print_stu(s);
    return 0;
}
//lisa 20 100.000000
```





## 10. 关键字

### 10.1 数据类型关键字

**A 基本数据类型（5个）**

- void：声明函数无返回值或无参数，声明无类型指针，显式丢弃运算结果
- char：字符型类型数据，属于整型数据的一种
- int：整型数据，通常为编译器指定的机器字长
- float：单精度浮点型数据，属于浮点数据的一种
- double：双精度浮点型数据，属于浮点数据的一种

**B 类型修饰关键字（4个）**

- short：修饰int，短整型数据，可省略被修饰的int。
- long：修饰int，长整形数据，可省略被修饰的int。
- signed：修饰整型数据，有符号数据类型
- unsigned：修饰整型数据，无符号数据类型

**C 复杂类型关键字（5个）**

- struct：结构体声明
- union：共用体声明
- enum：枚举声明
- typedef：声明类型别名、类型重命名
- sizeof：得到特定类型或特定类型变量的大小

**D 存储级别关键字（6个）**

- auto：指定为自动变量，由编译器自动分配及释放。通常在栈上分配。所有的局部变量都是auto类型的，所以可以省略
- static：指定为静态变量，分配在静态变量区，修饰函数时，指定函数作用域为文件内部
- register：指定为寄存器变量，建议编译器将变量存储到寄存器中使用，也可以修饰函数形参，建议编译器通过寄存器而不是堆栈传递参数
- extern：指定对应变量为外部变量，即在另外的目标文件中定义，可以认为是约定由另外文件声明的对象的一个“引用“
- const：与volatile合称“cv特性”，指定变量不可被当前线程/进程改变（但有可能被系统或其他线程/进程改变）
- volatile：与const合称“cv特性”，指定变量的值有可能会被系统或其他进程/线程改变，强制编译器每次从内存中取得该变量的值

### 10.2 流程控制关键字

**A 跳转结构（4个）**

- return：用在函数体中，返回特定值（或者是void值，即不返回值）
- continue：结束当前循环，开始下一轮循环
    - `for`, `while`, `do while`  搭配用
- break：跳出当前循环或switch结构
    - `for`, `while`, `do while`  搭配用
- goto：无条件跳转语句

**B 分支结构（5个）**

- if：条件语句
- else：条件语句否定分支（与if连用）
- switch：开关语句（多重分支语句）
- case：开关语句中的分支标记
    - `switch...case...`  经常一起用
- default：开关语句中的“其他”分治，可选。

**C 循环结构（3个）**

- for：for循环结构，for(1;2;3)4;的执行顺序为1->2->4->3->2...循环，其中2为循环条件
- do：do循环结构，do 1 while(2);的执行顺序是1->2->1...循环，2为循环条件
- while：while循环结构，while(1) 2;的执行顺序是1->2->1...循环，1为循环条件

以上循环语句，当循环条件表达式为真则继续循环，为假则跳出循环。

------

补充：

C语言中没有 string ，要想在C语言中使用字符串，就要在头文件里定义#include<string.h>（引用）而字符串在c++里的定义是#include<string>；在C/C++中使用字符串也就是定义时不一样，其他的都一样。string 是字符串，char是单个的字符。string相当于一个容器，char可以放在里面。string有结束符，char是没有的。string是c++里的，不是c里的。用string存储字符串时，不用设定字符串的长度，而char要设定。还有就是，string有很强很方便的功能，比如可以方便的赋值，方便的比较大小。





### typedef

>  类型定义 (类型重命名)

- `typedef 符号类型(修饰) 类型名 新名字 `

- typedef vs #define
    - **#define** 是 C 指令，用于为各种数据类型定义别名，与 **typedef** 类似，
    - 但是它们有以下几点不同：
        - **typedef** 仅限于为类型定义符号名称，**#define** 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
        - **typedef** 是由编译器执行解释的，**#define** 语句是由预编译器进行处理的。

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef unsigned int uint;//类型重命名
int main()
{
	unsigned int num = 0;
	uint  num2 = 1;//重命名类型的使用
	printf("%d\n", num);
	printf("%d\n", num2);
	return 0;
}
```



### static

> 修饰变量和函数
>
> - 修饰局部变量,  称为静态局部变量   改变***内存位置***
> - 修饰全局变量,  称为静态全局变量  改变***链接属性***   感觉就是作用域变小了
> - 修饰函数,  称为静态函数   改变***链接属性***   感觉就是作用域变小了

局部变量

---

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//修饰局部变量

//void 无返回值
void test()
{
    //静态局部变量
    static int a = 1;//static修饰局部变量的时候, 局部变量即便出了作用域, 也不销毁, 只有程序退出时, 静态局部变量才销毁. 本质上是static修饰局部变量的时候改变了变量的存储位置, 影响了变量的生命周期 (和程序的生命周期相同).
    a++;
    printf("%d\n", a);
}
int main()
{
    //修饰局部变量
    int i = 0;
    while (i < 10)
    {
        test();
        i++;
    }
    //修饰全局变量
    //修饰函数
    return 0;
}
```

全局变量

----

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//文件一:test.c
//修饰全局变量

//声明外部符号
extern int g_val;


int main()
{
    printf("%d\n",g_val);
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
//文件二: add.c
//全局变量
static int g_val = 2022;//static修饰全局变量的时候, 它的外部连接属性, 就变成了内部链接属性,其他源文件(fileName.c)就不能再使用这个全局变量了
```

函数

---

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//修饰函数
int Add(int x,int y)
{
    return x + y;
}


int main()
{
    int a = 10;
    int b = 20;
    int z = Add(a,b);
    printf("%d\n",z);
    return 0;
}
```

函数 (外部调用)

---

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//修饰函数
//文件一: test.c
//声明外部函数
extern int Add(int x,int y);
int main()
{
    int a = 10;
    int b = 20;
    int z = Add(a,b);
    printf("%d\n",z);
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
//函数
//文件二: add.c
static int Add(int x,int y)//static修饰函数的时候, 它的外部连接属性, 就变成了内部链接属性,其他源文件(fileName.c)就不能再使用这个函数了
{
    return x + y;
}
```



### register

> 寄存器

电脑上的存设备 (速度, 空间, 价格 )

- 寄存器 (集成到CPU上的) (极快, 极小, 极高)

- 高速缓存 (cache) (较快, 较小, 较高)
- 内存  (快, 小, 高)
- 硬盘  (慢, 大, 便宜)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
   //寄存器变量
    register int num = 3;//建议3存放在寄存器中
    return 0;
}
```



### define

> 定义常量和宏

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//define定义标识符常量
#define NUM 100
int main() {
    printf("%d\n", NUM);
    int n = NUM;
    printf("%d\n",n);
    int arr[NUM] = {0};
    printf("%d\n",arr[0]);
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//define定义宏
//宏是有参数
#define ADD(x,y) ((x)+(y))
//宏名 (参数) (宏体)
//宏是完成替换的, 参数是无类型, 参数替换为宏体
//运行时为  int c = ((a)+(b));

int main() {
    int a = 10;
    int b = 20;
    int c = ADD(a,b);
    printf("%d\n", c);
    return 0;
}
```



## 11 指针

### 11.1 内存

> 内存是电脑上特别重要的存储器, 计算机中程序的运行是在内存中进行的
>
> 所以, 为了有效地使用内存, 就把内存划分为一个个小的内存单元,每个内存单元的大小是***一个字节***,
>
> 为了能够有效地访问到内存的每个单元, 会给内存单元进行编号, 这些编号被称为***内存单元的地址***    地址也被称为==指针==
>
> 存放指针 (地址) 的变量就是指针变量

> 32位电脑
>
> 地址线: 1/0
>
> 32位电脑有32根地址线
>
> 地址序列:
>
> - 00000000 00000000  00000000 00000000   32位
>
> - ......
>
> - 11111111 11111111 11111111 11111111  32位
>
> 字节:
>
> 4,294,967,296    BYTE
>
> 4,194,304   KB
>
> 4,096   MB
>
> 4  GB

| 内存     | 地址       |
| -------- | ---------- |
| 一个字节 | 0xFFFFFFFF |
| 一个字节 | 0xFFFFFFFE |
| 一个字节 | 0xFFFFFFFD |
| 一个字节 | 0xFFFFFFFC |
| ......   | ......     |
| ......   | ......     |
| 一个字节 | 0x00000002 |
| 一个字节 | 0x00000001 |
| 一个字节 | 0x00000000 |

- 变量创建在内存中, (在内存中分配空间), 每个内存单元都有地址, 所以变量也是有地址的

    - ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    int main() {
        int  a = 10;//向内存申请4个字节, 存储10, 第一个字节就是变量的地址
        &a;//取地址操作
        int* p = &a;// int* 说明p是int*类型,  * 说明p是指针变量,  int 说明p指向的对象是int类型
        //p就是指针变量
        printf("%p\n",p);//十六进制地址
        printf("%p\n", &a);//十六进制地址
        *p = 20;//* 解引用操作符, 通过p中存放的地址,找到p所指向的对象, *p就是p指向的对象
        printf("%d\n",a);//20
    
        char ch = 'w';
        char* pc = &ch;// char* 说明p是char*类型,  * 说明p是指针变量,  char 说明p指向的对象是char类型
        //pc就是指针变量
        printf("%p\n",pc);//十六进制地址
        return 0;
    }
    ```

    - 指针就是地址, 指针变量就是用来存放地址的

### 11.2 指针变量大小

- 无论是什么类型, 创建的都是指针变量, 指针变量是用来存放地址的,
- 一个指针变量大小取决于一个地址存放需要多大空间
- 32位机器上的地址:  32 bit位 - 4 byte
- 64位机器上的地址:  64 bit位 - 8 byte
- 指针变量的大小

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    printf("%zu\n", sizeof(int*));
    printf("%zu\n", sizeof(short*));
    printf("%zu\n", sizeof(char*));
    printf("%zu\n", sizeof(float*));
    printf("%zu\n", sizeof(double*));
    return 0;
}
//64位机器
//8
//8
//8
//8
//8

//32位机器
//4
//4
//4
//4
//4
```



## 12. 结构体

- 结构体使得C语言能够描述复杂类型
- 类似于面向对象的 "类"
- 结构体是把一些单一类型组合在一起的做法

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Stu {
    //结构体成员
    char name[20];
    int age;
    char sex[10];
    char tele[12];
};
void print(struct Stu* ps)//ps是Stu类型的指针地址  需要传入一个地址
{
    printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tele);//*ps 获取ps的指针地址
    //结构体指针变量->成员变量
    printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->tele);//ps指向对象的成员
};
int main() {
    //初始化
    struct Stu s = { "zhangsan",20,"man","12345678901" };
    print(&s);//取地址操作
    //printf("%s %d %s %s\n", s.name, s.age, s.sex, s.tele);//对象打点获取结构体成员具体值  结构体对象 . 成员名
    return 0;
}
```





| 栈区                                                         | 堆区                                                        | 静态区                                  |
| ------------------------------------------------------------ | ----------------------------------------------------------- | --------------------------------------- |
| ==存放==<br />局部变量 (超出作用域时销毁)<br />函数的形参<br />每一次函数的调用都会在栈区申请空间 | 动态内存管理<br />malloc<br />free<br />calloc<br />realloc | 静态变量 (程序退出时销毁)<br />全局变量 |

> 函数栈帧的创建和销毁
>
> [栈和栈帧](https://www.bilibili.com/video/BV1FY411J7s7/?from=seopage)
>
> [CPU眼里的：{函数括号} | 栈帧 | 堆栈 | 栈变量](https://zhuanlan.zhihu.com/p/77663680)



## 13 表达式求值

> 表达式求值的顺序一部分是由操作符的优先级和结合性决定的
>
> -
>
> 同样有些表达式的操作数在求值的过程中可能需要转换为其他类型

### 13.1 隐式类型转换

> C的整型算术运算总是至少以缺省 (默认) 整型类型的精度来进行的
>
> 为了获得这个精度, 表达式中的字符和短整型操作数在使用之前被转换为普通整型, 这种转换称为***整型提升***

> 整型提升的意义:
>
> 表达式的整型运算要在CPU的相应运算器件内执行, CPU内整型运算器 (ALU) 的操作数的字节长度一般就是int的字节长度, 同时也是CPU的通用寄存器的长度
>
> 因此, 即使两个char类型相加, 在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度
>
> 通用CPU(General-PurposeCPU) 是难以直接实现两个8比特字节直接相加运算的 (虽然机器指令中可能有这种字节相加指令), 所以,  表达式中各种长度可能小于int长度的整型值, 都必须先转换为int或unsigned int, 然后才能送入CPU去执行运算
>
> - 整型提升是按照变量数据类型的符号位来提升的

```c
int main(){
    char c = -1;//-1是整数, 占用32个比特位
    //10000000 00000000 00000000 00000001 ---原码  (内存中存的是补码)
    //11111111 11111111 11111111 11111110 ---符号位不变,其他位按位取反
    //11111111 11111111 11111111 11111111 ---补码:反码加一
    //char 类型只有一个字节 存的二进制(补码)是末尾的一个字节(低8个比特位) 
    // 11111111
    //整型提升
    //因为char是有符号的char, 第一位识别为符号位, 高位补充符号位  补1
    //11111111 11111111 11111111 11111111 ---char -1的整型提升
    //有符号整型提升
    
    char b = 1; 
    //整数的原码补码反码相同
    //char的二进制(补码)有八个比特位
    //00000001
    //因为char是无符号的char, 第一位识别为符号位, 高位补充符号位 补0
    //00000000 00000000 00000000 00000001
    //无符号整型提升
    
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    char a = 5;
    char b = 126;
    char c = a + b;
    printf("%d",c);
    //a的原码
    //00000000 00000000 00000000 00000101
    //存入char
    //00000101

    //126的原码
    //00000000 00000000 00000000 01111110
    //存入char
    //01111110

    //相加
    //00000101 --a=5
    //01111110 --b=126
    //表达式中的字符和短整型操作数在使用之前被转换为普通整型,---整型提升
    //00000000 00000000 00000000 00000101
    //00000000 00000000 00000000 01111110
    //00000000 00000000 00000000 10000011
    //存入char c
    //10000011

    //%d输出整型  原码,   ---整型提升
    //第一位识别为符号位, 并在高位补充符号位
    //11111111 11111111 11111111 10000011  --补码
    //11111111 11111111 11111111 10000010  --反码: 补码减一
    //10000000 00000000 00000000 01111101  --原码: 反码按位取反,符号位不变
    //-(2^8*0 + 2^7*1 + 2^6*1 + 2^5*1 + 2^4*1 + 2^3*1 + 2^2*1 + 2^1*0 + 2^0*1)  = -(64 + 32 + 16 + 8 + 4 + 0 + 1) = -125
    //整型输出
    //

    return 0;
}
```

```c
#include <stdio.h>

int main() {
    char a = 0xb6;//发生整型提升
    short b = 0xb600;//发生整型提升
    int c = 0xb6000000;
    if(a == 0xb6){
        printf("a");
    }
    if(b == 0xb600){
        printf("b");
    }
    if(c == 0xb6000000){
        printf("c");
    }
    return 0;
}
//c
```

```c
#include <stdio.h>

int main() {
    char a1 = 0xb6;//发生整型提升
    //a的二进制: 10110110
    //整型提升: 11111111 11111111 11111111 10110110

    unsigned char a2 = 0xb6;//发生整型提升,但是是无符号的, 高位补零
    //00000000 00000000 00000000 010110110

    short b = 0xb600;//发生整型提升
    int c = 0xb6000000;
    if(a1 == 0xb6){
        printf("a1");
    }
    if(a2 == 0xb6){
        printf("a2\n");
    }
    if(b == 0xb600){
        printf("b");
    }
    if(c == 0xb6000000){
        printf("c");
    }
    return 0;
}
```

```c
#include <stdio.h>

int main() {
    char c = 1;
    printf("%u\n",sizeof (c));//无运算
    printf("%u\n",sizeof (+c));//整型提升后参与运算
    printf("%u\n",sizeof (-c));//整型提升后参与运算
    return 0;
}
//1
//4
//4
```

### 13.2 算术转换

> 如果某个操作符的各个操作数属于不同的类型, 那么除非其中一个操作数转换为另一个操作数的类型, 否则操作就无法进行, 下面的层次体系称为***寻常算术转换***
>
> ```c
> long double 
> double
> float
> unsigned long int 
> long ing 
> unsigned int 
> int
> ```
>
> - 向上转换
> - 如果某个操作数的类型在上面这个列表中排名较低, 那么首先要转换为另一个操作数的类型后执行运算
>
> > 警告:
> >
> > 但是算术转换要合理, 要不然有一些潜在的问题
> >
> > ```c
> > #include <stdio.h>
> > 
> > int main() {
> >     float f = 3.14;
> >     int num =  f;
> >     printf("num=%d\nf=%f",num,f);
> >     return 0;
> > }
> > //num=3     
> > //f=3.140000
> > 
> > ```



### 13.3 操作符的属性

> 复杂表达式的求值有三个影响因素
>
> 1. 操作符的优先级
> 2. 操作符的结合性
> 3. 是否控制求值顺序
>
> 两个相邻的操作符先执行哪一个? 取决于他们的优先级, 如果两者的优先级相同, 那么取决于他们的结合性,

### 结合性和优先级表格



<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<div id="arc-body">
    所谓优先级就是当一个表达式中有多个运算符时，先计算谁，后计算谁。这个其实我们在小学学算术的时候就学过，如<code>1+4÷2</code>。<br>
    <br>
    但是C语言中的运算符已经远不止四则运算中的加减乘除了，还有其他很多运算符。当它们出现在同一个表达式中时先计算谁后计算谁呢？所以本节还是有必要讲一下的。最后我还会将所有运算符展示出来，然后告诉你哪个优先级高、哪个优先级低。<br>
    <br>
    首先不需要专门记忆，也没有必要。因为作为初学者，哪个优先级高、哪个优先级低我们很难记住。就算死记硬背记住了，时间长不用也会忘记。所以当一个表达式中有多个运算符时，如果不知道哪个优先级高哪个优先级低就查一下优先级表，附录E有一个运算符优先级表。此外用的时间长了自然而然就记住了，这样记才会记得深刻。<br>
    <br>
    而且事实上在编程的时候也不需要考虑优先级的问题。因为如果不知道优先级高低的话，加一个括号就可以了，因为括号<code>(
    )</code>的优先级是最高的。比如前面的程序中：
    <p class="info-box">
        k = (j&gt;i) &amp;&amp; (8==i);</p>
    根据运算符的优先级，这条语句完全可以写成：
    <p class="info-box">
        k = j&gt;i &amp;&amp; 8==i;</p>
    但是第一种写法别人一看就知道先计算谁后计算谁。<br>
    <br>
    而且加圆括号也是一种编程规范，因为程序不只是写给自己看。<br>
    <br>
    此外运算符还有“目”和“结合性”的概念，这个很简单。“目”就是“眼睛”的意思，一个运算符需要几个数就叫“几目”。比如加法运算符<code>+</code>，要使用这个运算符需要两个数，如
    3+2。对<code>+</code>而言，3 和 2 就像它的两只眼睛，所以这个运算符是双目的。<br>
    <br>
    C语言中大多数的运算符都是双目的，也有单目和三目的。单目运算符比如逻辑非，如<code>!1</code>，它就只有一只眼睛，所以是单目的。整个C语言中只有一个三目运算符，即条件运算符<code>?
    :</code>。这个稍后讲到条件语句的时候再介绍。关于“目”大家了解一下就行了。<br>
    <br>
    那么“结合性”是什么呢？上面讲的优先级都是关于优先级不同的运算符参与运算时先计算谁后计算谁。但是如果运算符的优先级相同，那么先计算谁后计算谁呢？这个就是由“结合性”决定的。<br>
    <br>
    比如<code>1+2×3÷4</code>，乘和除的优先级相同，但是计算的时候是从左往右，即先计算乘再计算除，所以乘和除的结合性就是从左往右。就是这么简单！<br>
    <br>
    C语言中大多数运算符的结合性都是从左往右，只有三个运算符是从右往左的。一个是单目运算符，另一个是三目运算符，还有一个就是双目运算符中的赋值运算符<code>=</code>。双目运算符中只有赋值运算符的结合性是从右往左的，其他的都是从左往右。运算符的“结合性”也不要死记，在不断使用中就记住了。
    <h2>
        运算符优先级和结合性一览表</h2>
    <table>
        <tbody>
        <tr>
            <th>
                <p>
                    优先级</p>
            </th>
            <th>
                <p>
                    运算符</p>
            </th>
            <th>
                <p>
                    名称或含义</p>
            </th>
            <th>
                <p>
                    使用形式</p>
            </th>
            <th>
                <p>
                    结合方向</p>
            </th>
            <th>
                <p>
                    说明</p>
            </th>
        </tr>
        <tr>
            <td rowspan="4">
                <p>
                    1</p>
            </td>
            <td>
                <p>
                    []</p>
            </td>
            <td>
                <p>
                    数组下标</p>
            </td>
            <td>
                <p>
                    数组名[常量表达式]</p>
            </td>
            <td rowspan="4">
                <p>
                    左到右</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    ()</p>
            </td>
            <td>
                <p>
                    圆括号</p>
            </td>
            <td>
                <p>
                    (表达式)<br>
                    函数名(形参表)</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    .</p>
            </td>
            <td>
                <p>
                    成员选择（对象）</p>
            </td>
            <td>
                <p>
                    对象.成员名</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    -&gt;</p>
            </td>
            <td>
                <p>
                    成员选择（指针）</p>
            </td>
            <td>
                <p>
                    对象指针-&gt;成员名</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td rowspan="9">
                <p>
                    2</p>
            </td>
            <td>
                <p>
                    -</p>
            </td>
            <td>
                <p>
                    负号运算符</p>
            </td>
            <td>
                <p>
                    -表达式</p>
            </td>
            <td rowspan="9">
                <p>
                    右到左</p>
            </td>
            <td>
                <p>
                    单目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    (类型)</p>
            </td>
            <td>
                <p>
                    强制类型转换</p>
            </td>
            <td>
                <p>
                    (数据类型)表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    ++</p>
            </td>
            <td>
                <p>
                    自增运算符</p>
            </td>
            <td>
                <p>
                    ++变量名<br>
                    变量名++</p>
            </td>
            <td>
                <p>
                    单目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    --</p>
            </td>
            <td>
                <p>
                    自减运算符</p>
            </td>
            <td>
                <p>
                    --变量名<br>
                    变量名--</p>
            </td>
            <td>
                <p>
                    单目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    *</p>
            </td>
            <td>
                <p>
                    取值运算符</p>
            </td>
            <td>
                <p>
                    *指针变量</p>
            </td>
            <td>
                <p>
                    单目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    &amp;</p>
            </td>
            <td>
                <p>
                    取地址运算符</p>
            </td>
            <td>
                <p>
                    &amp;变量名</p>
            </td>
            <td>
                <p>
                    单目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    !</p>
            </td>
            <td>
                <p>
                    逻辑非运算符</p>
            </td>
            <td>
                <p>
                    !表达式</p>
            </td>
            <td>
                <p>
                    单目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    ~</p>
            </td>
            <td>
                <p>
                    按位取反运算符</p>
            </td>
            <td>
                <p>
                    ~表达式</p>
            </td>
            <td>
                <p>
                    单目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    sizeof</p>
            </td>
            <td>
                <p>
                    长度运算符</p>
            </td>
            <td>
                <p>
                    sizeof(表达式)</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td rowspan="3">
                <p>
                    3</p>
            </td>
            <td>
                <p>
                    /</p>
            </td>
            <td>
                <p>
                    除</p>
            </td>
            <td>
                <p>
                    表达式 / 表达式</p>
            </td>
            <td rowspan="3">
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    *</p>
            </td>
            <td>
                <p>
                    乘</p>
            </td>
            <td>
                <p>
                    表达式*表达式</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    %</p>
            </td>
            <td>
                <p>
                    余数（取模）</p>
            </td>
            <td>
                <p>
                    整型表达式%整型表达式</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td rowspan="2">
                <p>
                    4</p>
            </td>
            <td>
                <p>
                    +</p>
            </td>
            <td>
                <p>
                    加</p>
            </td>
            <td>
                <p>
                    表达式+表达式</p>
            </td>
            <td rowspan="2">
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    -</p>
            </td>
            <td>
                <p>
                    减</p>
            </td>
            <td>
                <p>
                    表达式-表达式</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td rowspan="2">
                <p>
                    5</p>
            </td>
            <td>
                <p>
                    &lt;&lt;</p>
            </td>
            <td>
                <p>
                    左移</p>
            </td>
            <td>
                <p>
                    变量&lt;&lt;表达式</p>
            </td>
            <td rowspan="2">
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    &gt;&gt;</p>
            </td>
            <td>
                <p>
                    右移</p>
            </td>
            <td>
                <p>
                    变量&gt;&gt;表达式</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td rowspan="4">
                <p>
                    6</p>
            </td>
            <td>
                <p>
                    &gt;</p>
            </td>
            <td>
                <p>
                    大于</p>
            </td>
            <td>
                <p>
                    表达式&gt;表达式</p>
            </td>
            <td rowspan="4">
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    &gt;=</p>
            </td>
            <td>
                <p>
                    大于等于</p>
            </td>
            <td>
                <p>
                    表达式&gt;=表达式</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    &lt;</p>
            </td>
            <td>
                <p>
                    小于</p>
            </td>
            <td>
                <p>
                    表达式&lt;表达式</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    &lt;=</p>
            </td>
            <td>
                <p>
                    小于等于</p>
            </td>
            <td>
                <p>
                    表达式&lt;=表达式</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td rowspan="2">
                <p>
                    7</p>
            </td>
            <td>
                <p>
                    ==</p>
            </td>
            <td>
                <p>
                    等于</p>
            </td>
            <td>
                <p>
                    表达式==表达式</p>
            </td>
            <td rowspan="2">
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    !=</p>
            </td>
            <td>
                <p>
                    不等于</p>
            </td>
            <td>
                <p>
                    表达式!= 表达式</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    8</p>
            </td>
            <td>
                <p>
                    &amp;</p>
            </td>
            <td>
                <p>
                    按位与</p>
            </td>
            <td>
                <p>
                    表达式&amp;表达式</p>
            </td>
            <td>
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    9</p>
            </td>
            <td>
                <p>
                    ^</p>
            </td>
            <td>
                <p>
                    按位异或</p>
            </td>
            <td>
                <p>
                    表达式^表达式</p>
            </td>
            <td>
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    10</p>
            </td>
            <td>
                <p>
                    |</p>
            </td>
            <td>
                <p>
                    按位或</p>
            </td>
            <td>
                <p>
                    表达式|表达式</p>
            </td>
            <td>
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    11</p>
            </td>
            <td>
                <p>
                    &amp;&amp;</p>
            </td>
            <td>
                <p>
                    逻辑与</p>
            </td>
            <td>
                <p>
                    表达式&amp;&amp;表达式</p>
            </td>
            <td>
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    12</p>
            </td>
            <td>
                <p>
                    ||</p>
            </td>
            <td>
                <p>
                    逻辑或</p>
            </td>
            <td>
                <p>
                    表达式||表达式</p>
            </td>
            <td>
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    双目运算符</p>
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    13</p>
            </td>
            <td>
                <p>
                    ?:</p>
            </td>
            <td>
                <p>
                    条件运算符</p>
            </td>
            <td>
                <p>
                    表达式1? 表达式2: 表达式3</p>
            </td>
            <td>
                <p>
                    右到左</p>
            </td>
            <td>
                <p>
                    三目运算符</p>
            </td>
        </tr>
        <tr>
            <td rowspan="11">
                <p>
                    14</p>
            </td>
            <td>
                <p>
                    =</p>
            </td>
            <td>
                <p>
                    赋值运算符</p>
            </td>
            <td>
                <p>
                    变量=表达式</p>
            </td>
            <td rowspan="11">
                <p>
                    右到左</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    /=</p>
            </td>
            <td>
                <p>
                    除后赋值</p>
            </td>
            <td>
                <p>
                    变量/=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    *=</p>
            </td>
            <td>
                <p>
                    乘后赋值</p>
            </td>
            <td>
                <p>
                    变量*=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    %=</p>
            </td>
            <td>
                <p>
                    取模后赋值</p>
            </td>
            <td>
                <p>
                    变量%=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    +=</p>
            </td>
            <td>
                <p>
                    加后赋值</p>
            </td>
            <td>
                <p>
                    变量+=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    -=</p>
            </td>
            <td>
                <p>
                    减后赋值</p>
            </td>
            <td>
                <p>
                    变量-=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    &lt;&lt;=</p>
            </td>
            <td>
                <p>
                    左移后赋值</p>
            </td>
            <td>
                <p>
                    变量&lt;&lt;=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    &gt;&gt;=</p>
            </td>
            <td>
                <p>
                    右移后赋值</p>
            </td>
            <td>
                <p>
                    变量&gt;&gt;=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    &amp;=</p>
            </td>
            <td>
                <p>
                    按位与后赋值</p>
            </td>
            <td>
                <p>
                    变量&amp;=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    ^=</p>
            </td>
            <td>
                <p>
                    按位异或后赋值</p>
            </td>
            <td>
                <p>
                    变量^=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    |=</p>
            </td>
            <td>
                <p>
                    按位或后赋值</p>
            </td>
            <td>
                <p>
                    变量|=表达式</p>
            </td>
            <td>
                &nbsp;
            </td>
        </tr>
        <tr>
            <td>
                <p>
                    15</p>
            </td>
            <td>
                <p>
                    ,</p>
            </td>
            <td>
                <p>
                    逗号运算符</p>
            </td>
            <td>
                <p>
                    表达式,表达式,…</p>
            </td>
            <td>
                <p>
                    左到右</p>
            </td>
            <td>
                <p>
                    &nbsp;</p>
            </td>
        </tr>
        </tbody>
    </table>
    <br>
    上表中可以总结出如下规律：
    <ol>
        <li>
            结合方向只有三个是从右往左，其余都是从左往右。
        </li>
        <li>
            所有双目运算符中只有赋值运算符的结合方向是从右往左。
        </li>
        <li>
            另外两个从右往左结合的运算符也很好记，因为它们很特殊：一个是单目运算符，一个是三目运算符。
        </li>
        <li>
            C语言中有且只有一个三目运算符。
        </li>
        <li>
            逗号运算符的优先级最低，要记住。
        </li>
        <li>
            此外要记住，对于优先级：算术运算符 &gt; 关系运算符 &gt; 逻辑运算符 &gt; 赋值运算符。逻辑运算符中“逻辑非 !”除外。
        </li>
    </ol>
    <h2>
        一些容易出错的优先级问题</h2>
    上表中，优先级同为1 的几种运算符如果同时出现，那怎么确定表达式的优先级呢？这是很多初学者迷糊的地方。下表就整理了这些容易出错的情况：<br>
    <br>
    <table>
        <tbody>
        <tr>
            <th>
                优先级问题
            </th>
            <th>
                表达式
            </th>
            <th>
                经常误认为的结果
            </th>
            <th>
                实际结果
            </th>
        </tr>
        <tr>
            <td>
                . 的优先级高于 *（-&gt; 操作符用于消除这个问题）
            </td>
            <td>
                *p.f
            </td>
            <td>
                p 所指对象的字段 f，等价于：<br>
                (*p).f
            </td>
            <td>
                对 p 取&nbsp;f&nbsp;偏移，作为指针，然后进行解除引用操作，等价于：<br>
                *(p.f)
            </td>
        </tr>
        <tr>
            <td>
                [] 高于 *
            </td>
            <td>
                int *ap[]
            </td>
            <td>
                ap&nbsp;是个指向&nbsp;int&nbsp;数组的指针，等价于：<br>
                int (*ap)[]
            </td>
            <td>
                ap&nbsp;是个元素为&nbsp;int&nbsp;指针的数组，等价于：<br>
                int *(ap [])
            </td>
        </tr>
        <tr>
            <td>
                函数 () 高于 *
            </td>
            <td>
                int *fp()
            </td>
            <td>
                fp&nbsp;是个函数指针，所指函数返回&nbsp;int，等价于：<br>
                int (*fp)()
            </td>
            <td>
                fp 是个函数，返回&nbsp;int*，等价于：<br>
                int* ( fp() )
            </td>
        </tr>
        <tr>
            <td>
                == 和 != 高于位操作
            </td>
            <td>
                (val&nbsp;&amp;&nbsp;mask != 0)
            </td>
            <td>
                (val&nbsp;&amp;mask) != 0
            </td>
            <td>
                val &amp;&nbsp;(mask != 0)
            </td>
        </tr>
        <tr>
            <td>
                == 和 != 高于赋值符
            </td>
            <td>
                c = getchar() != EOF
            </td>
            <td>
                (c = getchar()) != EOF
            </td>
            <td>
                c = (getchar() != EOF)
            </td>
        </tr>
        <tr>
            <td>
                算术运算符高于位移 运算符
            </td>
            <td>
                msb &lt;&lt;&nbsp;4 + lsb
            </td>
            <td>
                (msb &lt;&lt;&nbsp;4) + lsb
            </td>
            <td>
                msb &lt;&lt;&nbsp;(4 + lsb)
            </td>
        </tr>
        <tr>
            <td>
                逗号运算符在所有运 算符中优先级最低
            </td>
            <td>
                i = 1, 2
            </td>
            <td>
                i = (1,2)
            </td>
            <td>
                (i = 1),&nbsp;2
            </td>
        </tr>
        </tbody>
    </table>
    <br>
    这些容易出错的情况，希望读者好好在编译器上调试调试，这样印象会深一些。一定要多调试，光靠看代码，水平是很难提上来的。调试代码才是最长水平的。
</div>
</body>
</html>


> ```c
> #include <stdio.h>
> 
> int main() {
>     //表达式的求值部分由操作符的优先级决定
>     a*b + c*d + e*f;
>     return 0;
> }
> 
> ```
>
> > 在计算的时候,由于 `*` 比 `+` 的优先级高, 只能保证 `*` 的计算比 `+` 早, 但是优先级并不能决定第三个 `*` 一定比第一个 `+` 早执行
> >
> > 所以表达式的计算机顺序可能是:
> >
> > ```c
> > a*b
> > c*d
> > a*b + c*d
> > e*f
> > a*b + c*d + e*f
> > //路径不唯一,如果这些变量是表达式,且值会相互影响,那么就无法保证结果的唯一性
> > ```
> >
> > ```c
> > #include <stdio.h>
> > 
> > int main() {
> >     int c = 2;
> >     int d = c + --c;// -- 的优先级高于 +
> >    //如果还没有计算 --c 的时候就把 c=2 存入了寄存器
> >    //2 + 1 = 3
> >    //如果计算了 --c 才存入
> >    //1 + 1 = 2
> >     printf("%d", d);
> >     return 0;
> > }
> > ```
> >
> > ```c
> > #define _CRT_SECURE_NO_WARNINGS
> > #include <stdio.h>
> > 
> > int main() {
> >     int i = 10;
> >     i = i-- - --i * (i = -3) * i++ + ++i;
> >     printf("%d", i);
> >     return 0;
> > }
> > //不同编译器的结果不同
> > //-128
> > //-95
> > //-86
> > //-63
> > //4
> > //21
> > //22
> > //30
> > //36
> > //42
> > ```
> >
> > ```c
> > #include <stdio.h>
> > int fun(){
> >     static int count = 1;
> >     return ++count;
> > }
> > int main() {
> >   int answer;
> >   answer = fun() - fun() * fun();
> >   //如果先调用第一个fun() 2 - 3 * 4 = 10
> >   //如果先调用第二个fun() 4 - 2 * 3 = -2
> >   printf("%d",answer);
> >     return 0;
> > }
> > ```
> >
> > ```c
> > #include <stdio.h>
> > 
> > int main() {
> >     int a = 1;
> >     int b = (++a) + (++a) + (++a);
> >     //前两个++a先计算,然后再计算他们的和,最后计算最后一个++a 再计算它们的和
> >     // 3 + 3 + 4 = 10
> >     //所有的依次++a后, 保留最后的++a结果进行计算
> >     //4 + 4 + 4 = 12
> >     printf("%d", b);
> >     return 0;
> > }
> > //栈帧中存储的寄存器变量，例如指令寄存器（64位环境中用 rip 表示，32为环境中用 eip 表示）、堆栈基指针寄存器（64位环境用 rbp 表示，32位环境用 ebp 表示）
> > //反汇编
> > //    int a = 1;
> > //00007FF712BF189B  mov         dword ptr [rbp+4],1     把1放入[rbp+4]里面                 rbp是一个64位环境的寄存器, 里面存放的是地址   rbp+4 也是一个地址 , 这个地址指向的是a 存放的是int a的值
> > //    int b = (++a) + (++a) + (++a);
> > //00007FF712BF18A2  mov         eax,dword ptr [rbp+4]   把eax移动到[rbp+4]地址里(a的指针)   eax=1
> > //00007FF712BF18A5  inc         eax                     把eax增加1                        eax=2       (INC指令只有1个操作数，它将指定的操作数的内容加1，再将结果送回到该操作数。INC指令将影响SF,AF,ZF,PF,OF标志位，但是不影响CF标志位。)
> > //00007FF712BF18A7  mov         dword ptr [rbp+4],eax   把eax放到rbp-8(a的地址)里面去  此时 a=2
> > //00007FF712BF18AA  mov         eax,dword ptr [rbp+4]   把rbp+4放到eax里面去               eax=2----?
> > //00007FF712BF18AD  inc         eax                     把eax增加1                        eax=3
> > //00007FF712BF18AF  mov         dword ptr [rbp+4],eax   把eax放到rbp-8(a的地址)里面去  此时 a=3
> > //00007FF712BF18B2  mov         eax,dword ptr [rbp+4]   把rbp+4放到eax里面去               eax=3----?
> > //00007FF712BF18B5  inc         eax                     把eax增加1                        eax=4
> > //00007FF712BF18B7  mov         dword ptr [rbp+4],eax   把eax放到rbp-8(a的地址)里面去  此时 a=4
> > //00007FF712BF18BA  mov         eax,dword ptr [rbp+4]   把rbp+4放到eax里面去               eax=4----?
> > //00007FF712BF18BD  mov         ecx,dword ptr [rbp+4]   把rbp+4放到ecx里面去               ecx=4
> > //00007FF712BF18C0  add         ecx,eax                 把ecx和eax相加 ecx=ecx+eax         ecx=8
> > //00007FF712BF18C2  mov         eax,ecx                 把ecx放入eax里面                   eax=8
> > //00007FF712BF18C4  add         eax,dword ptr [rbp+4]   把rbp+4和eax的值相加 eax=[rbp+4]+eax   eax=12
> > //00007FF712BF18C7  mov         dword ptr [rbp+24h],eax 把eax放到rbp+24h里面               [rbp+4]=12
> > 
> > //eax/ebx/ecx/edx是寄存器
> > ```
> >
> >
> >
> > ==写代码的时候, 要保证所写的代码只有唯一的执行路径, 要简化代码==




## 14 案例

### 随机数

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int num() {
    int guess = 0;
    int ran = rand() % 101 + 100;//生成100 - 200的数字  取余101可以生成0-100的数字
    printf("生成的随机数是%d\n", ran);
}
int main() {
    int input = 0;
    srand((unsigned int) time(NULL));//根据系统时间生成一个随机数
    int i = 0;
    num();
    return 0;
}
```



### 生成数字

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
   int i = 0;
    for (i = 100; i <= 200; i++) {
        printf("%d\n",i);
    }
    return 0;
}
```



### 打印素数

> 素数只能被`i` 和它自己整除
>
> - 数字7
    >   - 2/3/4/5/6都不能将他它整除
>   - 7是素数
> - 2 ~ i-1除以这个数,如果不能整除, 那它就是素数

- 原理

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int i = 0;
    int cont = 0;//总计
    for (i = 100; i <= 200; i++) {
        //printf("%d\n", i);
        //素数判断
        int flag = 1;//是一便是素数
        int j = 0;//除数 2 ~ i-1
        for (j = 2; j <= i - 1; j++) {
            if ((i % j) == 0) {//有余数才是素数  ==0 表示这个数字能被整除,不是素数
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cont++;
            printf("%d是素数\n", i);
        }
    }
    printf("\ncount = %d",cont);
    return 0;
}
```

- 优化 1

  > 如果他不是素数, 那么一定可以写做两个数的积, 这两个乘数中一定有一个数字是小于等于这个数的平方根的
  >
  > sqr(num)  开平方
  >
  > -  16
       >
       >   - ```c
  >     16 = 2*8    4*4  
  >     64 = 2*32   4*16   8*8  
  >     28 = 2*14  4*7
  >     也就是16可以被 2/4/8 整除, 其中4平方根
  >     64可以被 2/4/8/16/32 整除,其中8为平方根
  >     28可以被 2/4/7/14整除, 其中平方根为5.29....
  >     可以说小于平方根的某个数必定乘以大于平方根的某个数
  >     所以判断是否为质数可以从平方根为分界线,不必 2~i-1 全部进行运算
  >     ```
  >
  >   - m = a*b
  >
  >   - a和b中一定有一个数字是<=sqr(m)
>
>

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
    int i = 0;
    int cont = 0;
    for (i = 100; i <= 200; i++) {
        //printf("%d\n", i);
        //素数判断
        int flag = 1;//是一便是素数
        int j = 0;//除数 2 ~ i-1
        //如果他不是素数, 那么一定可以写做两个数的积, 这两个乘数中一定有一个数字是小于等于这个数的平方根的
        for (j = 2; j <= sqrt(i); j++) {  //sqr(num)  开平方,  sqrt是一个数学库
            if ((i % j) == 0) {//有余数才是素数  ==0 表示这个数字能被整除,不是素数
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cont++;
            printf("%d是素数\n", i);
        }
    }
    printf("\ncount = %d", cont);
    return 0;
}
```

- 优化 2

  > 在源头上, 偶数除了2以外都能被2和另一个不同的数整除, 所以不会是质数

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
    int i = 0;
    int cont = 0;
    for (i = 100; i <= 200; i+=1) {//只生成奇数
        //printf("%d\n", i);
        //素数判断
        int flag = 1;//是一便是素数
        int j = 0;//除数 2 ~ i-1
        //如果他不是素数, 那么一定可以写做两个数的积, 这两个乘数中一定有一个数字是小于等于这个数的平方根的
        for (j = 2; j <= sqrt(i); j++) {  //sqr(num)  开平方,  sqrt是一个数学库
            if ((i % j) == 0) {//有余数才是素数  ==0 表示这个数字能被整除,不是素数
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cont++;
            printf("%d是素数\n", i);
        }
    }
    printf("\ncount = %d",cont);
    return 0;
}
```



### 判断是不是闰年

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
   int year = 0;
    for (year = 1000; year <= 2000; year++) {
        //判断
        if(year % 4 == 0){
            if(year % 100 != 0){
                printf("%d\n",year);
            }
        }
        if(year % 400 == 0){
            printf("%d\n",year);
        }
    }
    return 0;
}
```

- 优化

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
    int year = 0;
    for (year = 1000; year <= 2000; year++) {
        //判断
        if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
            printf("%d ", year);
        }
    }
    return 0;
}
```







## 错误

### 栈溢出 (Stack overflow)





## 资料

