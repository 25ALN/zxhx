#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// typedef int (*Predicate)(int);
// int *filter(int *array, int length, Predicate predicate,
//             int *resultLength){
//                 int cnt=0;
//                 int *aln=(int *)malloc(sizeof(int *)*10);
//                 for(int i=0;i<length;i++){
//                     if(predicate(array[i])){
//                       aln[cnt]=array[i];
//                       cnt++;
//                     }
//                 }
//                 *resultLength=cnt;
//                 return aln;
//             }
// int isPositive(int num) { return num > 0; }
// int main(void) {
//     int array[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
//     int length = sizeof(array) / sizeof(array[0]);
//     int resultLength;
//     int *filteredNumbers = filter(array, length, isPositive,&resultLength);
//     for (int i = 0; i < resultLength; i++) {
//       printf("%d ", filteredNumbers[i]);
//     }
//     printf("\n");
//     free(filteredNumbers);
//     return 0;
// }

// struct Student {
//     char *name;
//     int age;
// };

// void initializeStudent(struct Student *student, const char *name,
//                        int age) {
//     student->name = (char *)malloc(strlen(name) + 1);
//     strcpy(student->name, name);
//     student->age = age;
// }
// void aln(struct Student *s1,struct Student *s2){
//     free(s1->name);
//     s1->name=(char*)(malloc(strlen(s2->name)+1));
//     if(s1->name!=NULL){
//     strcpy(s1->name,s2->name);
//     }
// }
// int main(void) {
//     struct Student s1, s2;
//     initializeStudent(&s1, "Tom", 18);
//     initializeStudent(&s2, "Jerry", 28);
//     //s1 = s2;
//     aln(&s1,&s2);
//     s1.age=s2.age;
//     printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
//     printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
//     free(s1.name);
//     free(s2.name);
//     return 0;
// }

// int average(int nums[], int start, int end) {
//     if (start == end)
//         return nums[start];
//     int mid = (start + end) / 2;
//     int leftAvg = average(nums, start, mid);
//     int rightAvg = average(nums, mid + 1, end);
//     return (leftAvg & rightAvg) + ((leftAvg ^ rightAvg) >> 1);
// }
// int main(){
// int n;
// scanf("%d",&n);
// int aln[n];
// for(int i=0;i<n;i++){
//     scanf("%d",&aln[i]);
// }
// printf("%d", average(aln,0,n-1));
//     return 0;
// }



// union data {
//     int a;
//     double b;
//     short c;
// };
// typedef struct node {
//     long long a;      
//     union data b;
//     void (*change)( struct node *n);
//     char string[0];
// } Node;
// void func(Node *node) {
//     for (size_t i = 0; node->string[i] != '\0'; i++)
//         node->string[i] = tolower(node->string[i]);
// }
// int main() {
//     const char *s = "WELCOME TO XIYOULINUX_GROUP!";
//     Node *P = (Node *)malloc(sizeof(Node) + (strlen(s) + 1) * sizeof(char));
//     strcpy(P->string, s);
//     P->change = func;
//     P->change(P);
//     printf("%s\n", P->string);
//     printf("%zu\n",sizeof(union data));
//     printf("%zu",sizeof(Node));
//     return 0;
// }

// int s(long long a){
//     int isprime=1;
//     if(a==2){
//         return isprime;
//     }
//     for(long long i=2;i<=sqrt(a);i++){
//         if(a%i==0){
//              isprime=0;
//              break;
//         }else{
//              isprime=1;
//         }
//     }
//     return isprime;
// }
// int main(){
//     long long n;
//     scanf("%lld",&n);
//     for(long long i=2;i<=sqrt(n);i++){
//         long long j=n-i;
//             if(n==i+j&&s(i)&&s(j)){
//                 printf("%lld=%lld + %lld ",n,i,j);
//                 break;
//             }
//     }
//     return 0;
// }

// int main(){
//    int aln[7],max=0;
//     for(int i=0;i<7;i++){
//        scanf("%d",&aln[i]);
//     }
//     for(int j=0;j<7;j++){
//        if(max<aln[j]){
//         max=aln[j];
//        }
//     }
//     printf("%d",max);
//     return 0;
// }

// int main(){
// int a,b;
// double sum=0;
//     scanf("%d %d",&a,&b);
//     for(int i=a;i<=b;i++){
//         sum+=(i*i+1/(i*1.0));
//     }
//     printf("%.6f",sum);
//     return 0;
// }

// int main(){
// int a,b,t,x,y,m;
// scanf("%d %d",&a,&b);
// x=a,y=b;
// while(b!=0){
//     t=a%b;
// 	a=b;
// 	b=t; 
// }
//  m=x*y/a;
// printf("%d,%d",a,m);
//     return 0;
// }

// double s(long long a){
//     if(a==1){
//         return a;
//     }else{
//         a=a*s(a-1);
//         return a;
//     }
// }
// int main(){
//     int n;
//     double sum=1;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//        sum+=1/(s(i)*1.0);
//     }
//     printf("%.8f",sum);
//     return 0;
// }

// int main(){
//     int i,n,sum=0,cnt=0;
//     scanf("%d",&n);
//     while(n>0){
//        sum+=n%10;
//        n/=10;
//        cnt++;
//     }
//   printf("%d %d",cnt,sum);
//     return 0;
// }

// int main(){
//     int n,h;
//     scanf("%d %d",&n,&h);
//     double t,sum=0;
//     for(int i=0;i<=n+2;n=1.0*n/2,t=1.0*n,i++){
//         sum+=(n+1.0*n/2);
//     }
//     printf("%.1f %.1f",sum,t);
//     return 0;
// }

// int main(){
//     int n,cnt=0;
//     scanf("%d",&n);
//     for(int i=1;i<=30;i++){
//         for(int j=1;j<=75;j++){
//             if(i*5+j*2+100-i-j==150&&cnt<n){
//                 printf("%d %d %d",i,j,100-i-j);
//                 if(cnt!=n-1){
//                     printf("\n");
//                 }
//                 cnt++;
//             }
//         }
//     }
//     return 0;
// }

// int k=0;
// void s(int z){
//     int aln[10000],cnt=0,sum=0;
//     for(int i=1;i<=z/2;i++){
//         if(z%i==0){
//             sum+=i;
//             aln[cnt]=i;
//             cnt++;
//         }
//     }
//     if(sum==z){
//         ++k;
//         if(k!=0&&k!=1){
//             printf("\n");
//         }
//         printf("%d = ",z);
//           for(int j=0;j<cnt;j++){
//             printf("%d",aln[j]);
//             if(aln[j]!=sum/2) printf(" ");
//             if(j!=cnt-1){
//                 printf("+ ");
//             }
//           }
//           sum=0;
//           cnt=0;
//     }
// }
// int main(){
//     int x,y,m=0;
//     scanf("%d %d",&x,&y);
//     for(int i=x;i<=y;i++){
//         s(i);
//     }
//     if(k==0){
//         printf("None");
//     }
//     return 0;
// }

// int s(int a){
//    int isprime=0;
//    if(a==2||a==1){
//     isprime=1;
//    }else{
//    for(int i=2;i<a;i++){
//       if(a%i==0){
//         isprime=0;
//         break;
//       }else{
//         isprime=1;
//       }
//    }
//    }
//    return isprime;
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     int t=n;
//     if(s(n)==1){
//         printf("error");
//     }else{
//     for(int j=2;j<=t;j++){
//         if(n%j==0&&s(j)==1){
//             while(n%j==0){
//             printf("%d",j);
//             if(n/j!=1){
//                 printf(" ");
//             }
//             n/=j;
//             }
//         }
//     }
//     }
//     return 0;
// }

// int main(){
//     int a,b,sum=0,cnt=0;
//     scanf("%d %d",&a,&b);
//     for(int i=a;i<=b;i++){
//         if(i<0){
//             printf("%5d",i);
//         }else{
//         printf("%5d",i);
//         }
//         cnt++;
//         sum+=i;
//         if(cnt==5){
//             printf("\n");
//             cnt=0;
//         }
//     }
//     if((b-a+1)%5==0)
//     printf("Sum = %d",sum);
//     else
//     printf("\nSum = %d",sum);
//     return 0;
// }

// int main(){
//     int h,n;
//     double sum=0,H,l=0;
//     scanf("%d %d",&h,&n);
//     H=(double)h;
//     for(int i=0;i<n;i++){
//         if(i==n-1){
//             sum+=(H);
//             H/=2;
//             break;
//         }
//         sum+=(H+H/2);
//         H/=2;
//     }
//     if(n==0){
//         printf("%.1f 0.0",sum);
//     }else{
//     printf("%.1f %.1f",sum,H);
//     }
//     return 0;
// }

// int k=0;
// int main(){
//     int n,sum=0,t;
//     scanf("%d",&n);
//     int x=pow(10,n-1);
//     int l=pow(10,n);
//     if(n==7){
//          for(int j=1500000;j<l;j++){
//             t=j;
//             while(t>0){
//            sum+=pow(t%10,n);
//            t/=10;
//             }
//            if(sum==j){
//             k++;
//             if(k!=1){
//                 printf("\n");
//             }
//             printf("%d",sum);
//             sum=0;
//             if(k==2){
//                 j+=5000000;
//             }else if(k==1){
//             j+=2440000;
//             }
//            }
//            sum=0;
//         }
//     }else{
//         for(int j=x;j<l;j++){
//             t=j;
//             while(t>0){
//            sum+=pow(t%10,n);
//            t/=10;
//             }
//            if(sum==j){
//             k++;
//             if(k!=1){
//                 printf("\n");
//             }
//             printf("%d",sum);
//             sum=0;
//            }
//            sum=0;
//         }
//     }
//     return 0;
// }

// int s(int a){
//    int isprime=0;
//    if(a==2||a==1){
//     isprime=1;
//    }else{
//    for(int i=2;i<a;i++){
//       if(a%i==0){
//         isprime=0;
//         break;
//       }else{
//         isprime=1;
//       }
//    }
//    }
//    return isprime;
// }
// int main(){
//     int n,cnt=0;
//     scanf("%d",&n);
//     for(int i=n-1;i>=sqrt(n);i--){
//      if(s(i)==1){
//         cnt++;
//         printf("%6d",i);
//         if(cnt==10){
//             break;
//         }
//      }
//     }
//     return 0;
// }

// int main(){
//     int n,x,sum=0,cnt=0;
//     scanf("%d",&n);
//     for(int i=1;i<=1000;i++){
//       x=i;
//       while(x>0){
//         sum+=x%10;
//         x/=10; 
//       }
//       if(sum==n){
//         printf("%8d",i);
//         cnt++;
//       }
//       if(cnt==6){
//         printf("\n");
//         cnt=0;
//       }
//       sum=0;
//     }
//     return 0;
// }

//菱形
// int main(){
//     int n;
//     char x='*';
//     scanf("%d",&n);
//     for(int i=1;i<=n;i+2){
//         printf("%*c ",n-i,x);
//         for(int j=1;j<=(n-i)/2;j++){
//             printf("* ");
//         }
//         printf("\n");
//     }
//     return 0;
// }

// int jiec(int n){
//     if(n==1){
//         return 1;
//     }else{
//         return n=n*jiec(n-1);
//     }
// }
// int main(){
//     int cnt=0;
//     double n,sum=1;
//     scanf("%lf",&n);
//     for(int i=2; ;i+2){
//      sum+=((1.0*(pow(-1,i/2)*pow(n,i)))/jiec(i)*1.0);
//      cnt++;
//      if((pow(n,i))/jiec(i)<0.00001){
//         break;
//      }
//     }
//     printf("cos(x)=%.6f\n",sum);
//     printf("count=%d",cnt);
//     return 0;
// }

// int main(){
//     char s[1000];
//     gets(s);
//     int len=strlen(s);
//     for(int i=0;i<len;i++){
//         if(s[i]>=65&&s[i]<=90){
//             if(s[i]==90){
//                 s[i]=97;
//             }else
//             s[i]+=33;
//         }else if(s[i]>=97&&s[i]<=122){
//             if(s[i]==122){
//                 s[i]=65;
//             }else
//             s[i]-=31;
//         }
//     }
//     for(int j=0;j<len;j++){
//         printf("%c",s[j]);
//     }
//     return 0;
// }

// int main(){
//     char ch=' ';
//     int aln[1000],i=0;
//     for(int z=0;z<1000;z++){
//         aln[z]=0;
//     }
//     while(ch!='.'){
//         scanf("%c",&ch);
//     if(ch!=' '){
//         aln[i]++;
//     }
//     if(ch==' '){
//         i++;
//     }
//     }
//     for(int j=0;j<i;j++){
//         printf("%d",aln[j]);
//         if(j!=i-1){
//             printf(" ");
//         }
//     }

//     return 0;
// }

// int main(){
//     int max,aln[10],t=100,n,i=0;
//     scanf("%d",&n);
//     while(n>0){
//      scanf("%d",&aln[i]);
//      i++;
//      n--;
//     }
//     max=aln[0];
//     for(int j=0;j<i;j++){
//        if(aln[j]>max){
//         max=aln[j];
//        }
//     }
//     for(int z=0;z<i;z++){
//         if(aln[z]==max&&t>=z){
//           t=z;
//         }
//     }
//     printf("%d %d",max,t);
//     return 0;
// }

// int main(){
//     int n,cnt=0;
//     scanf("%d",&n);
//     while(n>0){
//         n/=2;
//         cnt++;
//     }
//     printf("%d",32-cnt);
//     return 0;
// }

// struct strbuf {
//   int len;     
//   int alloc;   
//   char *buf;   
// };
// void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len){
//     strncat(sb->buf,(char*)data,len);
//     printf("%s",sb->buf);
// }
// int main(){
//     struct strbuf *sn;
//     char *str;
//     sn->buf="loveforvevr";
//     scanf("%s",str);    
//     int len=strlen(str);
//     strbuf_insert(sn,4,str,len);
//     return 0;
// }

int main(){
    char *s;
    scanf("%s",s);
    int len=strlen(s);
    for(int i=2;i<len;i++){
        *(s+i)=*(s+i+1);
    }
    *(s+len)='\0';
    printf("%s",s);
    return 0;
}