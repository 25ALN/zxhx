# 西邮Linux兴趣小组2022纳新面试题  
感谢 [Zhilu](https://github.com/L33Z22L11) 重新录入题目原件。好人一生平安。

- 本题目只作为`Xiyou Linux兴趣小组`2022纳新面试的有限参考。
- 为节省版面，本试题的程序源码省去了`#include`指令。
- 本试题中的程序源码仅用于考察C语言基础，不应当作为C语言「代码风格」的范例。
- 题目难度随机排列。
- 所有题目编译并运行于`x86_64 GNU/Linux`环境。

> 学长寄语：
> 长期以来，西邮Linux兴趣小组的面试题以难度之高名扬西邮校内。我们作为出题人也清楚的知道这份试题略有难度。请别担心。**若有同学能完成一半的题目，就已经十分优秀。** 其次，相比于题目的答案，我们对你的思路和过程更感兴趣，或许你的答案略有瑕疵，但你正确的思路和对知识的理解足以为你赢得绝大多数的分数。最后，做题的过程也是学习和成长的过程，相信本试题对你更加熟悉的掌握C语言的一定有所帮助。祝你好运。我们FZ103见！

Copyright © 2022 西邮Linux兴趣小组, All Rights Reserved.
本试题使用采用 [知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议](http://creativecommons.org/licenses/by-nc-sa/4.0/) 进行许可。  

## 0. 我的计算器坏了？！

>2^10 = 1024对应于十进制的4位，那么2^10000`对应于十进制的多少位呢?  
lg2=0.3010  
lg(2^10)=10lg2 位数=10log2+1=4  
位数=lg2^10000=10000lg2+1=3011

## 1. printf还能这么玩？

尝试着解释程序的输出。

```c
int main(void) {
    if ((3 + 2 < 2) > (3 + 2 > 2))
        printf("Welcome to Xiyou Linux Group\n");
    else
        printf("%d\n", printf("Xiyou Linux Group - 2%d", printf("")));
}  
```  
>对于if语句（3+2<2）为假返回0，（3+2>2）为真返回1，所以将会执行else里的语句  
printf的返回值是字符串的长度，从里向外依次进行，依次进行打印，  
最里面的printf打印""返回0，接着的printf打印20返回22，最外层的，  
打印22\n.  
 最后的输出为  
 __Xiyou Linux Group - 2022__ 


## 2. 你好你好你好呀！

- 程序的输出有点奇怪，请尝试解释一下程序的输出吧。
- 请谈谈对`sizeof()`及`strlen()`的理解吧。

```c
int main(void) {
    char p0[] = "Hello,Linux";
    char *p1 = "Hello,Linux";
    char p2[11] = "Hello,Linux";
    printf("p0 == p1: %d, strcmp(p0, p2): %d\n", p0 == p1, strcmp(p0, p2));
    printf("sizeof(p0): %zu, sizeof(p1): %zu, sizeof(*p2): %zu\n",
           sizeof(p0), sizeof(p1), sizeof(*p2));
    printf("strlen(p0): %zu, strlen(p1): %zu\n", strlen(p0), strlen(p1));
}  
```
>p0是一个数组里面存储了字符最后会自动补一个'\0',p1是一个char类型的指针，指向字符串，  
p2是一个规定了长度为11的数组，所以不会补\0  
p0与p1比较的是他们的地址，p0是整个数组的地址，p1指向字符串的首地址，依次二者不相等，返回值为0  
strcmp是依次比较两个字符串中字符的ASCLL码，遇到\0停止比较，等于则返回0，大于则是正数，小于为1个负数（等于相应字符ASCLL的差值），当读到p0的\0时，*p这个指针会指向一个随机的值，因此会返回一个负数  
***因此第一个printf输出为:***   
__p0 == p1: 0,strcmp(p0,p2):-1(也许是其他的负值)__  
sizeof(p0)是里面字符的大小，要记得有最后的\0，sizeof(p1)是指针所对应的大小，sizeof(*p2)是字符H  
对应的大小  
***因此第二个printf输出为:***  
__sizeof(p0): 12, sizeof(p1): 8, sizeof(*p2): 1__  
strlen返回的是字符串的长度遇到\0终止  
***因此第三个printf输出为:***  
__strlen(p0): 11, strlen(p1): 11__
 
 ## 3. 换个变量名不行吗？

请结合本题，分别谈谈你对C语言中「全局变量」和「局部变量」的「生命周期」理解。

```c
int a = 3;
void test() {
    int a = 1;
    a += 1;
    {
        int a = a + 1;
        printf("a = %d\n", a);
    }
    printf("a = %d\n", a);
}
int main(void) {
    test();
    printf("a= %d\n", a);
}
```
>第一个块里的a属于局部变量，未进行初始化，输出应是一个计算机中的随机值  
第二个printf的a是test函数里所定义的局部变量a输出值应为2  
主函数里未定义变量a，最后将会输出全局变量a的值3  
当局部变量与全局变量重名时局部变量的值会将全局变量的值覆盖  
生命周期 变量从创建到销毁的时间段  

## 4. 内存对不齐

`union`与`struct`各有什么特点呢，你了解他们的内存分配模式吗。

```c
typedef union {
    long l;
    int i[5];
    char c;
} UNION;
typedef struct {
    int like;
    UNION coin;
    double collect;
} STRUCT;
int main(void) {
    printf("sizeof (UNION) = %zu\n", sizeof(UNION)); 
    printf("sizeof (STRUCT) = %zu\n", sizeof(STRUCT));
}  
```  
>union里面的所有成员共享一块内存位置，而struct是每一个成员分别占用一个不同的内存  
>union的大小是其中最大成员的大小，而struct是所有成员大小的总和，但由于结构体会进行一个
内存对齐，会在成员间填充字节，所以struct的大小会更大一些  
***sizeof (UNION) = 20***  
***sizeof (STRUCT) = 40***  

## 5. Bitwise

- 请使用纸笔推导出程序的输出结果。
- 请谈谈你对位运算的理解。

```c
int main(void) {
    unsigned char a = 4 | 7;
    a <<= 3;
    unsigned char b = 5 & 7;
    b >>= 3;
    unsigned char c = 6 ^ 7;
    c = ~c;
    unsigned short d = (a ^ c) << 3;
    signed char e = -63;
    e <<= 2;
    printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, (char)d);
    printf("e: %#x\n", e);
}  
```  
>char a=4|7=0000 0100|0000 0111=0000 0111  
a<<=3=0011 1000  
char b=5&7=0000 0101|0000 0111=0000 0101  
b>>=3=0000 0000  
char c=6^7=0000 0110|0000 0111=0000 0001  
c=~c=1111 1110  
d=(a^c)=(0011 1000^1111 1110)=0000 0000 1100 0110  
d<<3=0000 0011 0001 1000(被强转为char了，所以输出8位)  
char e=0000 0001  
e<<=2 =0000 0100  
- ***A***   
***a: 56, b: 0, c: 254, d: 48***  
***e: 0x4***  

## 6. 英译汉

请说说下面数据类型的含义，谈谈`const`的作用。
1. `char *const p`。
2. `char const *p`。
3. `const char *p`。  
```  
char*const p 是指*p是一个常量字符指针，*p的地址不能改变  
char const*p *p所指的字符内容不能改变，*p本身可以改变  
const char *p 与char const *p作用相同 
  
```
## 7. 汉译英

请用变量`p`给出下面的定义:
1. 含有10个指向`int`的指针的数组。
2. 指向含有10个`int`数组的指针。
3. 含有3个「指向函数的指针」的数组，被指向的函数有1个`int`参数并返回`int`。  
```  
1.int *p[10];  
2.int (*p)[10];  
3.int （*p）[3](int);
    
```    
  ## 8. 混乱中建立秩序

你对排序算法了解多少呢?  
请谈谈你所了解的排序算法的思想、稳定性、时间复杂度、空间复杂度。

提示：动动你的小手敲出来更好哦~  
```c  
//冒泡排序
int main(){
int aln[10]={2,4,1,5,7,0,9,3,8,6};
for(int i=0;i<10;i++){
    for(int j=0;j<10-i;j++){
        if(aln[j]<aln[j+1]){
            int x=aln[j+1];
            aln[j+1]=aln[j];
            aln[j]=x;
        }
    }
}
for(int z=0;z<10;z++){
    printf("%d ",aln[z]);
}
    return 0;
}

//选择排序
int main(){
    int x;
    int aln[10]={4,5,0,3,9,7,6,8,2,1};
    for(int i=0;i<10;i++){
        int min=aln[i];
        x=i;
        for(int j=i+1;j<10;j++){
            if(min>aln[j]){
                min=aln[j];
                x=j;
            }
        }
        aln[x]=aln[i];
        aln[i]=min;
    }
    for(int z=0;z<10;z++){
        printf("%d ",aln[z]);
    }
    return 0;
}
   
 ```  
  ## 9. 手脑并用

请实现ConvertAndMerge函数：  
拼接输入的两个字符串，并翻转拼接后得到的新字符串中所有字母的大小写。

提示:你需要为新字符串分配空间。

```c
char* convertAndMerge(/*补全签名*/);
int main(void) {
    char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    char *str = convertAndMerge(words);
    printf("str = %s\n", str);
    free(str);
}
 
char* convertAndMerge(char aln[2][20]);
int main(void) {
    char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    char *str = convertAndMerge(words);
    printf("str = %s\n", str);
}
char* convertAndMerge(char aln[2][20]){
    char *result=(char*)malloc(sizeof(char)*50);
    strcpy(result,aln[0]);
    strcat(result,aln[1]);
    for(int i=0;i<50;i++){
        if(result[i]>='A'&&result[i]<='Z'){
            result[i]+=32;
        }else if(result[i]>='a'&&result[i]<='z'){
            result[i]-=32;
        }
    }
    return result;
    free(result);
}  
   
```  

 ## 10. 给你我的指针，访问我的心声

程序的输出有点奇怪，请尝试解释一下程序的输出吧。

```c
int main(int argc, char **argv) {
    int arr[5][5];
    int a = 0;
    for (int i = 0; i < 5; i++) {
        int *temp = *(arr + i);
        for (; temp < arr[5]; temp++) *temp = a++;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", arr[i][j]);
        }
    }
}
```  
先通过指针temp给二维数组arr依次进行赋值，然后从arr[0][0]开始到arr[4][4]  
进行比较，让a++，之后从arr[1][1]开始所以第二次a的赋值会从25开始以此内推  
__输出__  
0	1	2	3	4	
25	26	27	28	29	
45	46	47	48	49	
60	61	62	63	64	
70	71	72	73	74
>  
  
  
  ## 11. 奇怪的参数

你了解argc和argv吗？  
直接运行程序argc的值为什么是1？  
程序会出现死循环吗？

```c
#include <stdio.h>
int main(int argc, char **argv) {
    printf("argc = %d\n", argc);
    while (1) {
        argc++;
        if (argc < 0) {
            printf("%s\n", (char *)argv[0]);
            break;
        }
    }
}
```
>argc是命令行参数的个数，argv是一个字符串数组传入文件名  
argc默认的初始值为至少为1  
不会，argc会一直加到int的溢出值，会小于零最终终止循环并输出文件名
  
## 12. 奇怪的字符

程序的输出有点奇怪，请尝试解释一下程序的输出吧。

```c
int main(int argc, char **argv) {
    int data1[2][3] = {{0x636c6557, 0x20656d6f, 0x58206f74},
                       {0x756f7969, 0x6e694c20, 0x00000000}};
    int data2[] = {0x47207875, 0x70756f72, 0x32303220, 0x00000a32};
    char *a = (char *)data1;
    char *b = (char *)data2;
    char buf[1024];
    strcpy(buf, a);
    strcat(buf, b);
    printf("%s \n", buf);
}
```  
本题考察大小端的存储方式，在x86下采用小端的存储方式（低位放在低地址，高位放在高地址），下面强制类型转换，将date拆分成2个一组，例如data1[0][0]=0x636c6557即为63 6c 65 57再以此将这16进制依据相应的ASCLl码转换为对应字符，再利用字符串函数将其进行拼接  
__输出__   
***Welcome to Xiyou Linux Group 2022***

  
  ## 13. 小试宏刀

- 请谈谈你对`#define`的理解。
- 请尝试着解释程序的输出。

```c
#define SWAP(a, b, t) t = a; a = b; b = t
#define SQUARE(a) a *a
#define SWAPWHEN(a, b, t, cond) if (cond) SWAP(a, b, t)
int main() {
    int tmp;
    int x = 1;
    int y = 2;
    int z = 3;
    int w = 3;
    SWAP(x, y, tmp);
    printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
    if (x y) SWAP(x, y, tmp);
    printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
    SWAPWHEN(x, y, tmp, SQUARE(1 + 2 + z++ + ++w) == 100);
    printf("x = %d, y = %d\n", x, y, tmp);
    printf("z = %d, w = %d, tmp = %d\n", z, w, tmp);
}
```  
>#define是一个宏定义，在程序预编译时进行  
对于SQUARE(1 + 2 + z++ + ++w)，计算时应该是1 + 2 + z++ + ++w*1 + 2 + z++ + ++w，因为在宏定义时就没有打括号  
__输出__  
x = 2, y = 1, tmp = 1
x = 1, y = 2, tmp = 2
x = 2, y = 2
z = 5, w = 5, tmp = 2  
  
## 14. GNU/Linux命令 (选做)

你知道以下命令的含义和用法吗：

注：
嘿！你或许对Linux命令不是很熟悉，甚至你没听说过Linux。  
但别担心，这是选做题，不会对你的面试产生很大的影响！  
了解Linux是加分项，但不了解也不扣分哦！
- `ls`
- `rm`
- `whoami`

请问你还了解哪些GNU/Linux的命令呢。  
>ls 查看linux相关文件夹包含的文件，文件权限
rm  删除一个目录中的一个或多个文件或目录
whoami 显示当前有效的用户名称

> 恭喜你做到这里！你的坚持战胜了绝大多数看到这份试题的同学。  
> 或许你自己对答题的表现不满意,但别担心，请自信一点呐。  
> 坚持到达这里已经证明了你的优秀。  
> 还在等什么,快带上你的笔记本电脑，来FZ103面试吧!  