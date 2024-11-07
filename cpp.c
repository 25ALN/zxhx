#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

                             //第一章
// 1
// int main(){
//     double m;
//     scanf("%lf",&m);
//     printf("%.2f",m*2.54);
//     return 0;
// }

                        //第二章
     //5
// void br(){
//     printf("Brazil,Russia");
// }
// void ic(){
//     printf("India,China");
// }
// int main(){
//     br();
//     printf(",");
//     ic();
//     printf("\n");
//     ic();
//     printf("\n");
//     br();
//     return 0;
// }       
    //7
// void s(){
//     printf("Smile!");
// }
// int main(){
//     s(),s(),s();
//     printf("\n");
//     s(),s();
//     printf("\n");
//     s();
//     return 0;
// }
//       8                 
// void one_three(){
//     printf("one\n");
// }
// void two(){
//     printf("two\n");
// }
// int main(){
//     printf("starting now:\n");
//     one_three();
//     two();
//     printf("three\ndone!");
//     return 0;
// }
//                   第三章
//  2
// int main(){
//     int x;
//     scanf("%d",&x);
//     printf("%c",x);
//     return 0;
// }
//  4
// int main(){
//     float x;
//     printf("Enter a floating-point value: ");
//     scanf("%f",&x);
//     printf("fixed-point notation: %.6f\n",x);
//     printf("exponential notation: %e\n");
//     printf("p notation: %a");  //16进位制p计数法
//     return 0;
// }
//  5
// int main(){
//     double x=3.156e+7;
//     double year;
//     scanf("%lf",&year);
//     printf("%e秒",x*year);
//     return 0;
// }
//  8
// int main(){
//     int cup;
//     printf("请输入杯数");
//     scanf("%d",&cup);
//     printf("%.2f品脱\n",(1.0*cup)/2);
//     printf("%d盎司\n",cup*8);
//     printf("%d大汤勺\n",cup*16);
//     printf("%d茶勺",cup*48);
//     return 0;
// }
//                   第四章
// 2
// int main(){
//     char *name;
//     scanf("%s",name);
//     int len=strlen(name);
//     printf("my name is \"%s\"\n",name);
//     printf("my name is \"%20s\"\n",name);
//     printf("my name is \"%-20s\"\n",name);
//     printf("my name is \"%*s\"\n",len+3,name);
//     return 0;
// }
// 6
// int main(){
//     char *name1,*name2;
//     scanf("%s %s",name1,name2);
//     int len1=strlen(name1);
//     int len2=strlen(name2);
//     printf("%s %s\n",name1,name2);
//     printf("%*d %*d\n",len1,len1,len2,len2);
//     printf("%-*d %-*d",len1,len1,len2,len2);
//     return 0;
// }
// 7
// #include <float.h>
// int main(){
//     double x=1.0/3.0;
//     float y=1.0/3.0;
//     printf("x=%.6f\n",x);
//     printf("x=%.12f\n",x);
//     printf("y=%.6f\n",y);
//     printf("y=%.12f\n",y);
//     printf("%d %d",FLT_DIG,DBL_DIG);
//     return 0;
// }
//   不一致，精度不一样
// 8
// #define galun 3.785
// #define yli 1.609
// int main(){
//     double a,b;
//     scanf("%lf %lf",&a,&b);
//     printf("%.1f %.1f",a*galun,b*yli/100);
//     return 0;
// }
//                   第五章
// 1
// #define minute 60
// int main(){
//     int time;
//     scanf("%d",&time);
//     while(time>0){
//         scanf("%d",&time);
//         printf("%d小时%d分钟",time/minute,time%minute);
//     }
//     return 0;
// }
// 2
// int main(){
//     int n;
//     scanf("%d",&n);
//     int i=n;
//     while(i<=n+10){
//         printf("%d ",i);
//         i++;
//     }
//     return 0;
// }
// 6
// int main(){
//     int time,t,i=1,sum=0;
//     scanf("%d",&time);
//     while(i<=time){
//         t=i;
//         sum+=t*t;
//         i++;
//     }
//     printf("一共赚了%d",sum);
//     return 0;
// }
// 9
// void Temperatures(double x){
//     const double s=32.0;
//     const double k=273.16;
//     double sheshidu=5.0/9.0*(x-s);
//     double kaishi=sheshidu+k;
//     printf("摄氏温度是%.2f\n",sheshidu);
//     printf("开氏温度是%.2f\n",kaishi);
// }
// int main(){
//     double huashi;
//     while(scanf("%lf",&huashi)==1){
//     printf("华氏温度是%.2f\n",huashi);
//     Temperatures(huashi);
//     }
//     return 0;
// }
//                   第六章
// 4
// int main(){
//     char letter=0;
//     int number;
//     scanf("%d",&number);
//     for(int i=0;i<number;i++){
//         for(int j=0;j<=i;j++){
//             printf("%c",'A'+letter);
//             letter++;
//         }
//         printf("\n");
//     }
//     return 0;
// }
// 5
// int main(){
//     char letter;
//     scanf("%c",&letter);
//     int kongge=letter-65,aln[52],i,j;
//     for(int kg=0;kg<52;kg++){
//         aln[kg]=32;
//     }
//     for(int z=0;z<letter-65;z++){
//         for(i=0;i<=z;i--){
//         printf("%c",aln[i]);
//       }
//         for(j=0;j<=letter-65-i;j++){
//         printf("%c",'A'+j);
//       }
//         for(int k=0;k<letter-65-i;k++){
//         printf("%c",'A'+j-k);
//       }
//       printf("\n");
//     }
//     return 0;
// }
// 12
// int main(){
//     int n;
//     double sum1=0,sum2=1;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//        sum1+=1/(i*1.0);
//     }
//     if(n!=1){
//     for(int j=2;j<=n;j++){
//        if(j%2==0){
//         sum2-=1/(j*1.0);
//        } else{
//         sum2+=1/(j*1.0);
//        }
//     }
//     }
//     printf("%f\n%f",sum1,sum2);
//     return 0;
// }
// 14
// int main(){
//     double aln1[8],aln2[8],sum=0;
//     for(int i=0;i<8;i++){
//         scanf("%lf",&aln1[i]);
//         sum+=aln1[i];
//         aln2[i]=sum;
//     }
//     for(int j=0;j<8;j++){
//         printf("%f ",aln1[j]);
//     }
//     printf("\n");
//     for(int k=0;k<8;k++){
//         printf("%f ",aln2[k]);
//     }
//     return 0;
// }
// 18
// int main(){
//     int i=5,cnt=0,x=1;
//     while(i<150){
//        i-=x;
//        i*=2;
//        x++;
//        cnt++;
//     }
//     printf("%d %d",cnt,i);
//     return 0;
// }
//                   第七章
// 6
// int main(){
//     int s,q='#';
//     int cnt=0;
//     while((s=getchar())!='#'){
//     if(s=='e'&&q=='i'){
//         cnt++;
//     }
//     q=s;
//     }
//     printf("ei出现了%d次",cnt);
//     return 0;
// }
// 7
// #define basic 10.00
// int main(){
//     int time;
//     double money,rest;
//     scanf("%d",&time);
//     if(time>40){
//     money=time*1.5*basic;
//     }else{
//         money=time*basic;
//     }
//     rest=money;
//     if(rest<=300){
//         money=rest*0.85;
//     }else if(rest>300&&rest<=450){
//         money=300*0.85+(rest-300)*0.8;
//     }else if(rest>450){
//         money=300*0.85+150*0.8+(rest-450)*0.75;
//     }
//     printf("%f",money);
//     return 0;
// }

// 9
// int aln(int a){
//     int isprime=1;
//     if(a==2){
//         return isprime;
//     }
//     for(int i=2;i<=sqrt(a);i++){
//         if(a%i==0){
//             isprime=0;
//             break;
//         }else{
//             isprime=1;
//         }
//     }
//     return isprime;
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     for(int i=2;i<=n;i++){
//        if(aln(i)==1){
//         printf("%d ",i);
//        }
//     }
//     return 0;
// }

//                   第八章
// 2
// int main(){
// char s;
// int cnt=0;
// while(scanf("%c",&s)!=EOF){
// printf("%c ",s);
// printf("%d ",s);
// cnt++;
// if(cnt%10==0){
//     printf("\n");
// }
// }
//     return 0;
// }

// 6
// #define STOP '#'
// int get_first(void);
// int main(void)
// {
//     int ch;
//     printf("Please enter some characters ('#' to quit):\n");
//     while ((ch = get_first()) != STOP)
//     {
//         printf("Result: %c\n", ch);
//         printf("You can enter again ('#' to quit):\n");
//     }
//     printf("Done.\n");
//     return 0;
// }
// int get_first(void)
// {
//     int ch;
//     do
//     {
//         ch = getchar();
//     } while (isspace(ch));
//     while (getchar() != '\n')
//         continue;
//    return ch;
// }
    
// 8
// int main(){
//     char x;
//     printf("please enter the operation of your choice:\n");
//     printf("a.add            s.subtract\n");
//     printf("m.multiply       d.divide\n");
//     printf("q.quit\n");
//     while(1){
//         x=getchar();
//          if(x=='a'){
//             printf("Enter first number: ");
//             double n1,n2;
//             while(scanf("%lf",&n1)!=1)
//             printf("%s is not a number",(char)n1);
//             printf("Enter second number: ");
//             while(scanf("%lf",&n2)!=1)
//             printf("%s is not a number",(char)n1);
//             printf("%f\n",n1+n2);
//          }else if(x=='s'){
//             printf("Enter first number: ");
//             double n1,n2;
//             scanf("%lf",&n1);
//             printf("Enter second number: ");
//             scanf("%lf",&n2);
//             printf("%f\n",n1-n2);
//          }else if(x=='m'){
//             printf("Enter first number: ");
//             double n1,n2;
//             scanf("%lf",&n1);
//             printf("Enter second number: ");
//             scanf("%lf",&n2);
//             printf("%f\n",n1*n2);
//          }else if(x=='d'){
//             printf("Enter first number: ");
//             double n1,n2;
//             scanf("%lf",&n1);
//             printf("Enter second number: ");
//             scanf("%lf",&n2);
//             if(n2==0){
//                 printf("Enter a number other than 0\n");
//                 scanf("%lf",&n2);
//             }
//             printf("%f\n",n1/n2);
//          }else if(x=='q'){
//             printf("bye");
//             break;
//          }
//     printf("please enter the operation of your choice:\n");
//     printf("a.add            s.subtract\n");
//     printf("m.multiply       d.divide\n");
//     printf("q.quit\n");
//     }
//     return 0;
// }    

//                   第九章
// 3
// void chline(char ch,int i,int j){
//     for(int z=0;z<i;z++){
//         for(int h=0;h<j;h++){
//             printf("%c",ch);
//         }
//         printf("\n");
//     }

// }
// int main(){
//     int i=0,j=0,cnt=0;
//     char ch;
//     printf("please enter your favorite char");
//     ch=getchar();
//     printf("你想要几行第几列");
//     scanf("%d %d",&i,&j);
//     chline(ch,i,j);
//     return 0;
// }

// 5
// void max(double *x,double *y){
//     double max;
//     if(x-y<=0){
//       max=*y;
//     }else{
//         max=*x;
//     }
//     *y=max,*x=max;
// }
// int main(){
//     double a,b;
//     scanf("%lf %lf",&a,&b);
//     max(&a,&b);
//     printf("%f %f",a,b);
//     return 0;
// }

// 11
// int main(){
//     int n,cnt=0,t=0,y=1;
//     printf("how much number do you want:");
//     scanf("%d",&n);
//     for(int i=1;cnt<n;cnt++){
//        printf("%d ",i);
//         t = i + y, i = y, y = t;
//     }
//     return 0;
// }

//                   第十章
// 5
// void compare(double *s,int cnt){
//     double max=0,min=0;
//       for(int i=0;i<cnt-1;i++){
//         if(s[i+1]>s[i]){
//             max=s[i+1];
//         }
//         if(s[i+1]<s[i]){
//             min=s[i+1];
//         }
//       }
//       printf("差值为%f",max-min);
// }
// int main(){
//     int cnt=0;
//     double aln[100];
//     printf("enter q to quit\n");
//     for(int i=0; ;i++){
//        if(scanf("%lf",&aln[i])==1){
//          cnt++;
//        }else break;
//     }
//     compare(aln,cnt);
//     return 0;
// }

// 11
// #define x 3
// #define y 5
// void print(int (*aln1)[y]){
//     for(int i=0;i<3;i++){
//         for(int j=0;j<5;j++){
//            printf("%d ",aln1[i][j]);
//         }
//         printf("\n");
//     }
// }
// void change(int (*aln2)[y]){
//     for(int i=0;i<3;i++){
//         for(int j=0;j<5;j++){
//            aln2[i][j]*=2;
//            printf("%d ",aln2[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main(){
//     int aln[x][y];
//     for(int i=0;i<x;i++){
//         for(int j=0;j<y;j++){
//            scanf("%d",&aln[i][j]);
//         }
//     }
//     print(aln);
//     change(aln);
//     return 0;
// }

// 13
void average(double (*aln)[5]){
    int cnt=1;
    double sum=0,asum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
           sum+=aln[i][j];
           asum+=aln[i][j];
        }
        printf("%d group average is %.2f\n",cnt,sum/5);
        sum=0,cnt++;
    }
    printf("all numbers'average is %.2f\n",asum/15);
}
void max(double (*aln)[5]){
    double max=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
           if(aln[i][j+1]<aln[i][j]){
            max=aln[i][j];
           }
        }
    }
    printf("the max number is %.2f",max);
}
int main(){
    printf("please three group number,every group has 5 number:");
    double aln[3][5];
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
           scanf("%lf",&aln[i][j]);
        }
    }
 
    return 0;
}
