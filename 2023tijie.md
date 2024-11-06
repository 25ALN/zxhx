## 0.鼠鼠我啊，要被祸害了
- 有 1000 瓶水，其中有一瓶有毒，小白鼠只要尝一点带毒的水，24 小时后就会准时死亡。
- 至少要多少只小白鼠才能在 24 小时内鉴别出哪瓶水有毒？  
>可以将水每次对半分，一开始将所有水瓶用二进制进行编号，将第一位为1的倒入少量到编号为1的一瓶新水中，直到第10位，现在有了十瓶水，用十只鼠鼠去喝这十瓶水，若鼠鼠没了，将相应的位数记为0,反之为1,最后再组合起来  
***10只***  
  
## 1.先预测一下~
- 按照函数要求输入自己的姓名试试~  
```c
char *welcome() {
 // 请你返回自己的姓名
}
int main(void) {
 char *a = welcome();
 printf("Hi, 我相信 %s 可以面试成功!\n", a);
 return 0;
}  
  
char *welcome() {
    char *name="名字";
   return name;
}
int main(void) {
 char *a = welcome();
 printf("Hi, 我相信 %s 可以面试成功!\n", a);
 return 0;
}  
```  
>定义了一个指针指向一个名字，然后将这个指针返回给函数  
  
##  2. 欢迎来到Linux兴趣小组
- 有趣的输出，为什么会这样子呢~

```c
int main(void) {
    char *ptr0 = "Welcome to Xiyou Linux!";
    char ptr1[] = "Welcome to Xiyou Linux!";
    if (*ptr0 == *ptr1) {
      printf("%d\n", printf("Hello, Linux Group - 2%d", printf("")));
    }
    int diff = ptr0 - ptr1;
    printf("Pointer Difference: %d\n", diff);
}  
```  
>*ptr1和*ptr0会指向字符的首地址，也就都是‘H’，所以将执行if语句，里面是printf的嵌套，从里向外依次返回字符的个数，并依次进行打印  
>下面将ptr0与ptr1的地址进行相减，会得到一个地址的差值  
  
##  3. 一切都翻倍了吗
- 请尝试解释一下程序的输出。
- 请谈谈对sizeof()和strlen()的理解吧。
- 什么是sprintf()，它的参数以及返回值又是什么呢？
```c
int main(void) {
    char arr[] = {'L', 'i', 'n', 'u', 'x', '\0', '!'}, str[20];
    short num = 520;
    int num2 = 1314;
    printf("%zu\t%zu\t%zu\n", sizeof(*&arr), sizeof(arr + 0),
           sizeof(num = num2 + 4));
    printf("%d\n", sprintf(str, "0x%x", num) == num);
    printf("%zu\t%zu\n", strlen(&str[0] + 1), strlen(arr + 0));
}  
```  
>先&arr对这个数组取地址，然后又指向了这个地址；  
arr是一整个数组，在+0以后变成了一个指针，在64位下占8个字节，32位4个； 
sizeof是静态运算符，最后会输出num所占的字节大小，short类型4个字节；  
sprintf是一个将其他数据类型转化为字符串的函数，它的返回值是字符串的长度，  sprintf(str, "0x%x", num)将short类型的变量，格式化为一个字符串，它再与num比较时用的是字符所对应的ASCLL码，因此二者不相等,返回0；  
strlen会输出字符串的长度，&str[0]取出了一个地址然后进行加1，arr是整个数组的地址也就算首地址+0以后变成了一个指针 
>sizeof将会输出变量所分配的字节数  
***输出***  
7	8	2
0
4	5



## 4. 奇怪的输出
- 程序的输出结果是什么？解释一下为什么出现该结果吧~

```c
int main(void) {
    char a = 64 & 127;
    char b = 64 ^ 127;
    char c = -64 >> 6;
    char ch = a + b - c;
    printf("a = %d b = %d c = %d\n", a, b, c);
    printf("ch = %d\n", ch);
}  
```  
>本题主要考察了位运算（首先要将数据全部化为二进制的形式）,&是与运算（两边同时为1时结果为1否则为0），|是或运算（两边只要有一个为1就为1反之为0），>>和<<是左移和右移运算符（移动相应的位数），^是异或运算符（相同为0,不相同为1），～是一个单目运算符，对数据进行取反（0变1，1变0）  
***优先级***：（从高到低）~,<<,>>,&,^,|  
-64应用补码形式表示，char类型的范围是-128～127，按照上述规则运算得输出
a = 64 b = 63 c = -1
ch = -128
  
##  5. 乍一看就不想看的函数
- “人们常说互联网凛冬已至，要提高自己的竞争力，可我怎么卷都卷不过别人，只好用一些奇技淫巧让我的代码变得高深莫测。”

- 这个func()函数的功能是什么？是如何实现的？

```c
int func(int a, int b) {
    if (!a) return b;
    return func((a & b) << 1, a ^ b);
}
int main(void) {
    int a = 4, b = 9, c = -7;
    printf("%d\n", func(a, func(b, c)));
}  
```  
>(a & b) << 1, a ^ b)是一种使用位运算计算两数和一种算法，所以func是一个运用递归求和的函数，当a=0时二者的和直接就为b否则就开始求和  
***输出***  
__6__  
  
 ## 6. 自定义过滤
- 请实现filter()函数：过滤满足条件的数组元素。

- 提示：使用函数指针作为函数参数并且你需要为新数组分配空间。

```c
typedef int (*Predicate)(int);
int *filter(int *array, int length, Predicate predicate,
            int *resultLength); /*补全函数*/
int isPositive(int num) { return num > 0; }
int main(void) {
    int array[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
    int length = sizeof(array) / sizeof(array[0]);
    int resultLength;
    int *filteredNumbers = filter(array, length, isPositive,
                                  &resultLength);
    for (int i = 0; i < resultLength; i++) {
      printf("%d ", filteredNumbers[i]);
    }
    printf("\n");
    free(filteredNumbers);
    return 0;
}
```
>需要返回一块内存，让新函数在这内存里面有一个新的数组

***代码实现如下***  
```c
typedef int (*Predicate)(int);
int *filter(int *array, int length, Predicate predicate,
            int *resultLength){
                int cnt=0;
                int *aln=(int *)malloc(sizeof(int *)*10);
                for(int i=0;i<length;i++){
                    if(predicate(array[i])){
                      aln[cnt]=array[i];
                      cnt++;
                    }
                }
                *resultLength=cnt;
                return aln;
            }
int isPositive(int num) { return num > 0; }
int main(void) {
    int array[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
    int length = sizeof(array) / sizeof(array[0]);
    int resultLength;
    int *filteredNumbers = filter(array, length, isPositive,&resultLength);
    for (int i = 0; i < resultLength; i++) {
      printf("%d ", filteredNumbers[i]);
    }
    printf("\n");
    free(filteredNumbers);
    return 0;
}
```  

## 7. 静…态…
- 如何理解关键字static？
- static与变量结合后有什么作用？
- static与函数结合后有什么作用？
- static与指针结合后有什么作用？
- static如何影响内存分配？  
>1.这是一个用来修饰变量和函数的关键字，改变其作用域和生命周期；  
2.将变量变为一个存储在静态区的全局变量，使其在程序运行的整个过程都在；  
3.静态函数不能被其他文件所引用，只能在声明他的文件中可见；  
4.指针本质上是一个变量，所以与指针结合后与变量一样的作用 ； 
>5.会将相应的变量存储在静态区，使其在整个函数的运行过程中都存在
  
## 8. 救命！指针！
- 数组指针是什么？指针数组是什么？函数指针呢？用自己的话说出来更好哦，下面数据类型的含义都是什么呢？

```c
int (*p)[10];
const int* p[10];
int (*f1(int))(int*, int);  
```  
>int (*p)[10]是一个数组指针，实际上是一个指针指向了数组中不同的成员；  
const int* p[10]是一个指针数组，实际上是一个数组里面存储了多个指针，且前面有const修饰，表示数组里面的指针不可再指向其他的元素改变其他元素的值；  
int (*f1(int))(int*, int)是一个函数指针，f1是函数名称，函数里面有一个int类型的变量和一个int类型的指针  
  
## 9. 咋不循环了
- 程序直接运行，输出的内容是什么意思？

```c
int main(int argc, char* argv[]) {
    printf("[%d]\n", argc);
    while (argc) {
      ++argc;
    }
    int i = -1, j = argc, k = 1;
    i++ && j++ || k++;
    printf("i = %d, j = %d, k = %d\n", i, j, k);
    return EXIT_SUCCESS;
}  
```  
>argc是名令行传入参数的个数，argv是字符类型的指针数组传入文件名  
argc默认的初始值为1,当argc加到int类型的溢出值时，便为负数终止循环  
下面进行了一个判断,&&的优先级比||高，只要i，j都不为0就会进行++，k不为0也进行++  
***输出***  
0 1 2
  
## 10. 到底是不是TWO
```c
#define CAL(a) a * a * a
#define MAGIC_CAL(a, b) CAL(a) + CAL(b)
int main(void) {
  int nums = 1;
  if(16 / CAL(2) == 2) {
    printf("I'm TWO(ﾉ>ω<)ﾉ\n");
  } else {
    int nums = MAGIC_CAL(++nums, 2);
  }
  printf("%d\n", nums);
}  
``` 
>16 / CAL(2)实际表示出来就是（16/2 * 2 * 2）,结果为32,因此执行else语句，在这里面又重新定义了一个变量nums，它的作用域仅仅在else语句里，所以最后输出的nums就等于1  
  
## 11. 克隆困境
- 试着运行一下程序，为什么会出现这样的结果？

- 直接将s2赋值给s1会出现哪些问题，应该如何解决？请写出相应代码。

```c
struct Student {
    char *name;
    int age;
};

void initializeStudent(struct Student *student, const char *name,
                       int age) {
    student->name = (char *)malloc(strlen(name) + 1);
    strcpy(student->name, name);
    student->age = age;
}
int main(void) {
    struct Student s1, s2;
    initializeStudent(&s1, "Tom", 18);
    initializeStudent(&s2, "Jerry", 28);
    s1 = s2;
    printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
    printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
    free(s1.name);
    free(s2.name);
    return 0;
}  
```
>在对结构体s1和s2中name是一个指针，在令s1=s2时使name指向了同一个地方，当释放掉其中一个内存时另外一个会变成一个野指针有一定的安全隐患，应当重新为s1的name指针分配一块内存再进行赋值  
```c  
struct Student {
    char *name;
    int age;
};

void initializeStudent(struct Student *student, const char *name,
                       int age) {
    student->name = (char *)malloc(strlen(name) + 1);
    strcpy(student->name, name);
    student->age = age;
}
void aln(struct Student *s1,struct Student *s2){
    free(s1->name);
    s1->name=(char*)(malloc(strlen(s2->name)+1));
    if(s1->name!=NULL){
    strcpy(s1->name,s2->name);
    }
}
int main(void) {
    struct Student s1, s2;
    initializeStudent(&s1, "Tom", 18);
    initializeStudent(&s2, "Jerry", 28);
    //s1 = s2;
    aln(&s1,&s2);
    s1.age=s2.age;
    printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
    printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
    free(s1.name);
    free(s2.name);
    return 0;
}  

```    
##  12. 你好，我是内存
- 作为一名合格的C-Coder，一定对内存很敏感吧~来尝试理解这个程序吧！

```c
struct structure {
    int foo;
    union {
      int integer;
      char string[11];
      void *pointer;
    } node;
    short bar;
    long long baz;
    int array[7];
};
int main(void) {
    int arr[] = {0x590ff23c, 0x2fbc5a4d, 0x636c6557, 0x20656d6f,
                 0x58206f74, 0x20545055, 0x6577202c, 0x6d6f636c,
                 0x6f742065, 0x79695820, 0x4c20756f, 0x78756e69,
                 0x6f724720, 0x5b207075, 0x33323032, 0x7825005d,
                 0x636c6557, 0x64fd6d1d};
    printf("%s\n", ((struct structure *)arr)->node.string);
}
```
>首先涉及到了结构体内存对齐，结构体内最长类型为8个字节因此向8对齐，union本来大小为11,对齐后变为了16；
(struct structure *)arr是将arr强转为了一个结构体指针，并且指向了node中的字符串数组，又因为对齐数为8,int是四个字节，所以应从第三个数开始输出；
还应注意大小段字节序的问题，在x86下计算机采用小段存储，即小位在低地址，高位在高地址；
最后char将int截断为四个部分，依据ASCLL码进行输出。
**Welcome to XUPT , welcome to Xiyou Linux Group [2023]**

## 13. GNU/Linux (选做)
- 注：嘿！你或许对Linux命令不是很熟悉，甚至你没听说过Linux。但别担心，这是选做题，了解Linux是加分项，但不了解也不扣分哦！

- 你知道cd命令的用法与 / . ~ 这些符号的含义吗？
- 请问你还懂得哪些与 GNU/Linux 相关的知识呢~
cd：改变当前工作目录的命令，切换到指定的路径
～ ：表示主目录，也就是当前登录用户的用户目录
/ ：是指根目录，就是所有目录最顶层的目录
. 代表当前目录

结语

恭喜你攻克所有难关！迎难而上的决心是我们更为看重的。
来到这里的人已是少数，莫踌躇在成功的门槛前。
自信一点，带上你的笔记本电脑，来东区逸夫楼FZ103面试吧！

