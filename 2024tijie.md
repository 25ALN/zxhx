## 西邮Linux兴趣小组2024纳新面试题
>学长寄语：长期以来，西邮 Linux 兴趣小组的面试题以难度之高名扬西邮校内。我们作为出题人也清楚的知道这份试题略有难度。请你动手敲一敲代码。别担心，若有同学能完成一半的题目，就已经十分优秀。其次，相比于题目的答案，我们对你的思路和过程更感兴趣，或许你的答案略有瑕疵，但你正确的思路和对知识的理解足以为你赢得绝大多数的分数。最后，做题的过程也是学习和成长的过程，相信本试题对你更加熟悉地掌握 C 语言一定有所帮助。祝你好运。我们东区逸夫楼 FZ103 见！

- 本题目只作为西邮 Linux 兴趣小组 2024 纳新面试的有限参考。
-为节省版面，本试题的程序源码省去了 #include 指令。
-本试题中的程序源码仅用于考察 C 语言基础，不应当作为 C 语言「代码风格」的范例。
-所有题目编译并运行于 x86_64 GNU/Linux 环境。
## 0. 聪明的吗喽
- 一个小猴子边上有 100 根香蕉，它要走过 50 米才能到家，每次它最多搬 50 根香蕉，（多了就拿不动了），它每走 1 米就要吃掉一根，请问它最多能把多少根香蕉搬到家里。

- （提示：他可以把香蕉放下往返走，但是必须保证它每走一米都能有香蕉吃。也可以走到 n 米时，放下一些香蕉，拿着 n 根香蕉走回去重新搬 50 根。）
>设猴子先走了x米，带了50根香蕉，走到x米处时，剩下了50-x根香蕉；  
走回去又需要x根香蕉，因此在x米处剩下50-2x根香蕉，再把起点处香蕉带到x米处，此时x米处一共有100-3x根香蕉；  
然后将这100-3x根香蕉带到终点吃掉了50-x根香蕉，终点处就剩下了50-2x根香蕉，且要满足100-3x<=50这个条件，最终结果就为***16***  
  
## 1. 西邮Linux欢迎你啊
- 请解释以下代码的运行结果。

```c
int main() {
    unsigned int a = 2024;
    for (; a >= 0; a--)
        printf("%d\n", printf("Hi guys! Join Linux - 2%d", printf("")));
    return 0;
}  
```  
>本题主要考察了printf的返回值，返回相应的字符数，从里向外依次输出依次返回，因此输出就为***Hi guys! Join Linux - 2024***一共要输出2024次  
>unsigned修饰的变量表示的范围更大，代表它是无符号类型的，不能表示正负，表示正数时范围会更大一点  
  
## 2. 眼见不一定为实
- 输出为什么和想象中不太一样？

- 你了解 sizeof() 和 strlen() 吗？他们的区别是什么？

```c
int main() {
    char p0[] = "I love Linux";
    const char *p1 = "I love Linux\0Group";
    char p2[] = "I love Linux\0";
    printf("%d\n%d\n", strcmp(p0, p1), strcmp(p0, p2));
    printf("%d\n%d\n", sizeof(p0) == sizeof(p1), strlen(p0) == strlen(p1));
    return 0;
}  
```  
>strcmp是一个字符串函数比较两个字符串中字符的ASCLL码大小直到‘\0’，大于则返回1,等于则返回0,小于则返回负数（两个字符ASCLL码的差值）；  
sizeof是一个关键字，输出相应变量所分配的字节数；  
p0是一个字符串数组，会自动在背后补一个‘\0’，p1是一个常量指针，p2也是一个字符串数组依旧会在结尾补一个‘\0’
__输出__ 
***0
0
0
1***

## 3. 1.1 - 1.0 != 0.1
- 为什么会这样，除了下面给出的一种方法，还有什么方法可以避免这个问题？

```c
int main() {
    float a = 1.0, b = 1.1, ex = 0.1;
    printf("b - a == ex is %s\n", (b - a == ex) ? "true" : "false");
    int A = a * 10, B = b * 10, EX = ex * 10;
    printf("B - A == EX is %s\n", (B - A == EX) ? "true" : "false");
}  
```
>浮点数在计算机中的存储是不精确的，因此不能直接进行比较；  
在比较浮点数时可以自行定义一个精度，当二者的差值的绝对值小于这个精度时就可认定二者相等  
本题是通过将数扩大使其没有小数部分再来进行比较  

## 4. 听说爱用位运算的人技术都不太差
- 解释函数的原理，并分析使用位运算求平均值的优缺点。

```c
int average(int nums[], int start, int end) {
    if (start == end)
        return nums[start];
    int mid = (start + end) / 2;
    int leftAvg = average(nums, start, mid);
    int rightAvg = average(nums, mid + 1, end);
    return (leftAvg & rightAvg) + ((leftAvg ^ rightAvg) >> 1);
}
```
>位运算可以在某些运算上大大提高计算的效率，比如乘上一个2的倍数数值，可以改用左移运算
x = x * 2;
x = x * 64;
//改为:
x = x << 1; // 2 = 2^1
x = x << 6; // 64 = 2^6
>位运算有时计算看起来比较繁琐，且会重复执行多次；
>在本题中若结果是小数则无法计算出精确的答案，并且本题只能计算数字个数为2^n时的平均数，每次将数分为两个部分求平均数，最终求平均数的平均数（分治）


## 5. 全局还是局部!!!
- 先思考输出是什么，再动动小手运行下代码，看跟自己想得结果一样不一样 >-<

```c
int i = 1;
static int j = 15;
int func() {
    int i = 10;
    if (i > 5) i++;
    printf("i = %d, j = %d\n", i, j);
    return i % j;
}
int main() {
    int a = func();
    printf("a = %d\n", a);
    printf("i = %d, j = %d\n", i, j);
    return 0;
}
```
>函数中局部变量会覆盖掉全局变量，因此在func函数中，i输出的值为11,返回值为11赋给了main函数中的a；
在main函数中i的值就是全局变量那个i的值，j也是如此，因此输出为
***i = 11, j = 15
a = 11
i = 1, j = 15***

## 6. 指针的修罗场：改还是不改，这是个问题
- 指出以下代码中存在的问题，并帮粗心的学长改正问题。

```c
int main(int argc, char **argv) {
    int a = 1, b = 2;
    const int *p = &a;
    int * const q = &b;
    *p = 3, q = &a;
    const int * const r = &a;
    *r = 4, r = &b;
    return 0;
}
```
>int *const p表示 *p所指的位置不能被改变，但 *p这个地址的数可以改变；
const int *p表示 *p这个地址不能被改变，但它所指向的位置可以随意 
__修改后__
```c
int main(int argc, char **argv) {
    int a = 1, b = 2;
    int *const p = &a;
    const int * q = &b;
    *p = 3, q = &a;
    int * r = &a;
    *r = 4, r = &b;
    return 0;
}
```
## 7. 物极必反？
- 你了解 argc 和 argv 吗，这个程序里的 argc 和 argv 是什么？

- 程序输出是什么？解释一下为什么。

```c
int main(int argc, char *argv[]) {
    while (argc++ > 0);
    int a = 1, b = argc, c = 0;
    if (--a || b++ && c--)
        for (int i = 0; argv[i] != NULL; i++)
            printf("argv[%d] = %s\n", i, argv[i]);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}
```  
>argc是传入函数参数的个数，argv是一个字符串的指针数组存储了文件名；
argc默认的初始值为1,进入循环后一直加到int类型的溢出值时终止循环；
对于逻辑运算符，从左向右进行运算，对于&&若左边的为false则不计算下一个操作数；对于||若左边的为true则不计算下一个操作数。
__输出__
***a = 0, b = -2147483646, c = -1***

## 8. 指针？数组？数组指针？指针数组？
-在主函数中定义如下变量：

```c
int main() {
    int a[2] = {4, 8};
    int(*b)[2] = &a;
    int *c[2] = {a, a + 1};
    return 0;
}
```
- 说说这些输出分别是什么？

```c
a, a + 1, &a, &a + 1, *(a + 1), sizeof(a), sizeof(&a)
*b, *b + 1, b, b + 1, *(*b + 1), sizeof(*b), sizeof(b)
c, c + 1, &c, &c + 1, **(c + 1), sizeof(c), sizeof(&c)
```
>a是一个数组里面有两个元素且都被初始化了
int(* b)[2]是一个数组指针，实质上是一个指针指向了数组中不同的元素，取a的地址让*b指向a这个数组
int *c[2]是一个指针数组，实质上是一个数组里面有2个指针，分别指向了不同的元素

## 9. 嘻嘻哈哈，好玩好玩
- 在宏的魔法下，数字与文字交织，猜猜结果是什么？

```c
#define SQUARE(x) x *x
#define MAX(a, b) (a > b) ? a : b;
#define PRINT(x) printf("嘻嘻，结果你猜对了吗，包%d滴\n", x);
#define CONCAT(a, b) a##b

int main() {
    int CONCAT(x, 1) = 5;
    int CONCAT(y, 2) = 3;
    int max = MAX(SQUARE(x1 + 1), SQUARE(y2))
    PRINT(max)
    return 0;
}
```
>##是一个符号连接操作符，可以将两个变量名组合在一起组成一个新的变量名；
因此x1=5,y2=3,SQUARE(x1 + 1)实际写出来是 5+1*5+1；
(a > b) ? a : b是一个三目运算符，若a>b满足则执行：左边的，不满足则执行右边的，因此最后的输出为
***嘻嘻，结果你猜对了吗，包11滴***

## 10. 我写的排序最快
- 写一个 your_sort 函数，要求不能改动 main 函数里的代码，对 arr1 和 arr2 两个数组进行升序排序并剔除相同元素，最后将排序结果放入 result 结构体中。

```c
int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
    int arr2[] = {2, 1, 4, 3, 9, 6, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    result result;
    your_sort(arr1, len1, arr2, len2, &result);
    for (int i = 0; i < result.len; i++) {
        printf("%d ", result.arr[i]);
    }
    free(result.arr);
    return 0;
}
```

```c
typedef Struct result{
    int aln[20];
};

typedef struct result
{
    int len;
    int *arr;
}result,*p;
int *your_sort(int arr1[], int len1, int arr2[], int len2, result *p)
{
    p->arr=(int *)malloc(sizeof(int)*15);
    int i,j,k=0,cnt=0;
   	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			 cnt=0;
			if(arr2[j]==arr1[i]){
				cnt=1;
				break;
			}	
		}
		if(cnt==0){
			*(p->arr+k)=arr1[i];
			k++;
		}
	}
	for(i=0;i<len2;i++){
		for(j=0;j<len1;j++){
			cnt=0;
			if(arr1[j]==arr2[i]){
				cnt=1;
				break;
			}
		}
		if(cnt==0){
			*(p->arr+k)=arr2[i];
			k++;
		}
	}
    for(int h1=0;h1<k;h1++){
        for(int h2=0;h2<=k-h2;h2++){
            if(*(p->arr+h2)>*(p->arr+h2+1)){
                int temp=*(p->arr+h2+1);
                *(p->arr+h2+1)=*(p->arr+h2);
                *(p->arr+h2)=temp;
            }
        }
    }
    p->len=k;
    return 0;
}
int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
    int arr2[] = {2, 1, 4, 3, 9, 6, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    result result;
    your_sort(arr1, len1, arr2, len2, &result);
    for (int i = 0; i < result.len; i++) {
        printf("%d ", result.arr[i]);
    }
    free(result.arr);
    return 0;
}

```
>



## 11. 猜猜我是谁
- 在指针的迷宫中，五个数字化身为神秘的符号，等待被逐一揭示。

```c
int main() {
    void *a[] = {(void *)1, (void *)2, (void *)3, (void *)4, (void *)5};
    printf("%d\n", *((char *)a + 1));
    printf("%d\n", *(int *)(char *)a + 1);
    printf("%d\n", *((int *)a + 2));
    printf("%lld\n", *((long long *)a + 3));
    printf("%d\n", *((short *)a + 4));
    return 0;
}
```
>定义了一个指针数组，里面存储了五个不指向任何类型的指针，每一个都占8个字节；
首先可以将上面的五个指针分为五个部分，每个部分都占8个字节，每个部分最左边为那个相应的数字，例如(void *)1所在的地址处为00 00 00 01
*((char *)a + 1))先进行了一个强制类型转换为char *类型，a此时为一个指针，将这个指针所指向的地址进行了加1,再指向了这个地址，char是一个字节，指向了第一个指针存储的00；
*(int *)(char *)a + 1)进行了两次强制类型转换，最终转化为（int *)类型，a先与 *结合指向了00 01然后再进行加1,结果就为2；
*((int *)a + 2))a先被强转为了（int *），将地址进行了+2,再与 *结合指向了这个地址，也就是00 02；
下面的以此类推，最后输出为
**0
2
2
4
2**

## 12. 结构体变小写奇遇记
- 计算出 Node 结构体的大小，并解释以下代码的运行结果。

```c
union data {
    int a;
    double b;
    short c;
};
typedef struct node {
    long long a;
    union data b;
    void (*change)( struct node *n);
    char string[0];
} Node;
void func(Node *node) {
    for (size_t i = 0; node->string[i] != '\0'; i++)
        node->string[i] = tolower(node->string[i]);
}

int main() {
    const char *s = "WELCOME TO XIYOULINUX_GROUP!";
    Node *P = (Node *)malloc(sizeof(Node) + (strlen(s) + 1) * sizeof(char));
    strcpy(P->string, s);
    P->change = func;
    P->change(P);
    printf("%s\n", P->string);
    return 0;
}
```
>在Node结构体内最大的类型所占字节数是8,由于结构体会进行内存对齐，因此一定为为8的整数倍，联合体的大小是其中最大成员的大小，因此Node的内存就是24
char string[0]为可伸缩数组，不占据结构体的空间；
tolower是一个字符串函数，可以将大写字母转换为小写字母，用strcpy函数将*s中的字符串复制到string中，下面再让change这个函数指针指向func这个函数，
最后调用函数将大写字母转换为小写字母后输出
__结果__
***welcome to xiyoulinux_group!***


## 13. GNU/Linux (选做)
__注：嘿！你或许对Linux命令不是很熟悉，甚至没听说过Linux。
但别担心，这是选做题，了解Linux是加分项，不了解也不扣分哦！__

- 你知道 ls 命令的用法与 / . ~ 这些符号的含义吗？
- 你知道 Linux 中权限 rwx 的含义吗？
- 请问你还懂得哪些与 GNU/Linux 相关的知识呢~
```
～ ：表示主目录，也就是当前登录用户的用户目录
/ ：是指根目录，就是所有目录最顶层的目录
. ：代表当前目录
r(Read，读取)：对文件而言，具有读取文件内容的权限；对目录来说，具有浏览目录的权限。
w(Write,写入)：对文件而言，具有新增,修改,删除文件内容的权限；对目录来说，具有新建，删除，修改，移动目录内文件的权限。
x(eXecute，执行)：对文件而言，具有执行文件的权限；对目录了来说该用户具有进入目录的权限。
```
- 结语

>🎉 恭喜你成功完成了所有挑战！\(^▽^)/！这是一项了不起的成就。👏
无论结果如何，相信这个过程已经让你对 C 语言和 Linux 有了更深入的了解。
记住，编程是一个持续学习的过程。
唯有脚踏实地，笃行不怠，方能拨云雾而见青天！