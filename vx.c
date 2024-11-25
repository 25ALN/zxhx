#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

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
//     char ch[100];
//     int h=0,aln[1000],k=0,cnt=0;
    
//     for(int i=0; ;i++){
//        scanf("%c",&ch[i]);
//        if(ch[i]!=' '&&ch[i]!='.'){
//         cnt++;
//        }else if(cnt!=0&&ch[i]==' '||ch[i]=='.'){
//         if(k==0&&cnt!=0){
//             printf("%d",cnt);
//             k++;
//         }else if(cnt!=0){ 
//         printf(" %d",cnt);
//         k++;
//         }
//         cnt=0;
//        }
//        if(ch[i]=='.') break;  
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
//     if(n<0){
//     printf("0");
//     }else{
//     while(n>0){
//         n/=2;
//         cnt++;
//     }
//     printf("%d",32-cnt);
//     }
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


// int main(){
//     int a,b;
//     int aln[100][100];
//     scanf("%d",&a);
//     scanf("%d",&b);
//     for(int i=1;i<=a;i++){
//         for(int j=1;j<=b;j++){
//            printf("(%d,%d) ",i,j);
//         }
//         printf("\n");
//     }
//     return 0;
// }


// int main(){
//     int n,aln1,aln2,i=0;
//     scanf("%d",&n);
//     char name[4];
//     char *aln;
//     for(int i=0;i<n;i++){
//      scanf("%s %d %d",name,&aln1,&aln2);
//      if(aln1<15||aln1>20||aln2<50||aln2>70){
//               *(aln+i)=name;
//               i++;
//            }
//         }
//       for(int j=0;j<=i;j++){
//         if(j==0){
//           printf("%s",*(aln+j));
//         }else{
//          printf("\n%s",*(aln+j)); 
//         }
//       }
//     return 0;
// }

// int main() {
//     int n;
//     scanf("%d",&n);
//     char name[4];
//     int a,b;
//     char names[n][4];
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         scanf("%s %d %d", name, &a, &b);
//         if (a < 15 || a > 20 || b < 50 || b > 70) {
//             snprintf(names[count], sizeof(names[count]), "%s", name);
//             count++;  
//         }
//     }
//     for (int i = 0; i < count; i++) {
//         printf("%s\n", names[i]);
//     }
    
//     return 0;
// }

// int main(){
//     double da,s,xiao;
//     scanf("%lf %lf %lf",&da,&s,&xiao);
//     double x;
//     if(s==0){
//         x=da*2.455;
//     }else{
//         x=da*1.26;
//     }
//     if(x>xiao){
//         printf("%.2f T_T",x);
//     }else{
//         printf("%.2f ^_^",x);
//     }
//     return 0;
// }

// int main(){
//     int n;
//     scanf("%d",&n);
//     char aln[80][80],ch='A';
//     for(int i=0;i<2*n-1;i++){
//         if(i==0||i==2*n-2){
//             for(int j=0;j<2*n-1;j++){
//                 aln[i][j]=ch;
//             }
//         }
//         ch++;
//     }
//     return 0;
// }


// int main(){
//     char *s;
//     s=(char*)malloc(100*sizeof(char));
//     s="123\0132";
//     strncpy(s,"#",1);
//     printf("%s",s);
//     for(int i=0;*(s+i)!="#";i++){
//       if(*(s+i)=="\0"){
//         *(s+i)="A";
//       }
//     }
//     int len=strlen(s);
//     printf("%d",len);
//     return 0;
// }

// int main()
// {
//    FILE *fp = NULL;
 
//    fp = fopen("/tmp/test.txt", "w+");
//    fprintf(fp, "This is testing for fprintf...\n");
//    fputs("This is testing for fputs...\n", fp);
//    fclose(fp);
// }

// int s(int a){
//    int isprime=1;
//    if(a==1||a==2){
//       isprime=0;
//    }
//    for(int i=2;i<=sqrt(a);i++){
//       if(a%i==0){
//          isprime=1;
//          break;
//       }else isprime=0;
//    }
//    return isprime;
// }
// int main(){
//    int n;
//    scanf("%d",&n);
//    if(s(n)==0){
//       printf("是素数");
//    }else{
//       printf("不是素数");
//    }
//    return 0;
// }

// int main(){
//    int n;
//    char ch='A';
//    scanf("%d",&n);
//    int x=2*n-1;  //x=5
//    char aln[100][100];
//    for(int i=0;i<n;i++){
//       for(int j=i;j<x-i;j++){
//          aln[i][j]=ch;
//       }
//       for(int z=i+1;z<x-i-1;z++){                      
//          aln[z][i]=ch;
//          aln[z][x-1-i]=ch;
//       }
//       for(int h=i;h<x-i;h++){
//          aln[x-1-i][h]=ch;
//       }
//       ch++;
//    }
//    for(int k=0;k<n*2-1;k++){
//       for(int k1=0;k1<n*2-1;k1++){
//          printf("%c",aln[k][k1]);
//       }
//       printf("\n");
//    }
//    return 0;
// }

// int main(){
//     int n,aln[10],max,cnt=11;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&aln[i]);
//     }
//     max=aln[0];
//     for(int j=0;j<n;j++){
//        if(max<aln[j]){
//         max=aln[j];
//         cnt=j;
//        }
//     }
//     if(max==aln[0]) printf("%d 0",max);
//     else printf("%d %d",max,cnt);
//     return 0;
// }

// int main(){
//     int n,aln[100],key;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&aln[i]);
//     }
//     scanf("%d",&aln[n]);
//     int len=n+1;
//     for(int j=0;j<len;j++){
//         for(int h=0;h<len-j-1;h++){
//         if(aln[h]>aln[h+1]){
//             int t=aln[h];
//             aln[h]=aln[h+1];
//             aln[h+1]=t;
//         }
//         }
//     }
//     for(int z=0;z<len;z++){
//         printf("%d ",aln[z]);
//     }
//     return 0;
// }

// void swap(int *a,int *b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main(){
//     int n,aln[100],min,max,a=0,b=0;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//        scanf("%d",&aln[i]);
//     }
//     min=aln[0],max=aln[0];
//     for(int j=0;j<n;j++){
//        if(min>aln[j]) {
//         min=aln[j];
//         a=j;
//        }
//        if(max<aln[j]){
//         max=aln[j];
//         b=j;
//        } 
//     }
//     printf("min=%d max=%d\n",min,max);
//     printf("a=%d b=%d\n",a,b);
//     if(n==2){
//     swap(&aln[n-1],&aln[b]);
//     }else{
//     swap(&aln[0],&aln[a]);
//     max=aln[0];
//     for(int j=0;j<n;j++){
//        if(max<aln[j]){
//         max=aln[j];
//         b=j;
//        } 
//     }
//     swap(&aln[n-1],&aln[b]);
//     }
//     for(int z=0;z<n;z++){
//         printf("%d ",aln[z]);
//     }
//     return 0;
// }

// int main(){
//     int n,aln[100],a[100]={0},cnt=0;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&aln[i]);
//         a[aln[i]]=1;
//     }
//     for(int z=0;z<n;z++){
//         if(a[aln[z]]==1&&cnt!=0){
//             printf(" %d",aln[z]);
//             a[aln[z]]-=1;
//             cnt++;
//         }
//         if(a[aln[z]]==1&&cnt==0){
//             printf("%d",aln[z]);
//             a[aln[z]]-=1;
//             cnt++;
//         }
//     }
//     return 0;
// }


//pta5

// int main(){
//     int aln1[20]={0},aln2[20]={0},c[20]={0},a=0,cnt=0;
//     scanf("%d",&aln1[0]);
//     for(int i=1;i<=aln1[0];i++){
//       scanf("%d",&aln1[i]);
//     }
//     scanf("%d",&aln2[0]);
//     for(int j=1;j<=aln2[0];j++){
//       scanf("%d",&aln2[j]);
//     }
//     for(int k=1;k<=aln1[0];k++){
//         for(int o=1;o<=aln2[0];o++){
//             if(aln1[k]==aln2[o]){
//                 a=1;
//                 break;
//             }
//         }
//         if(a==0) {
//             c[cnt]=aln1[k];
//             cnt++;
//         }
//         a=0;
//     }
//     a=0;

//     for(int k=1;k<=aln2[0];k++){
//         for(int o=1;o<=aln1[0];o++){
//             if(aln2[k]==aln1[o]){
//                 a=1;
//                 break;
//             }
//         }
//         if(a==0) {
//             c[cnt]=aln2[k];
//             cnt++;
//         }
//         a=0;
//     }
//         for(int y=0;y<cnt;y++){
//         printf("%d ",c[y]);
//     }
//     printf("\n");
//     int pi=0,pp=0;
//     for(int p=0;p<cnt;p++){
//         for(int p1=p;p1<cnt;p1++){
//            if(c[p]==c[p1]&&p!=p1){
//              pi=1;
//              break;
//            }
//         }
//         if(pi==0&&pp==0){
//         printf("%d",c[p]);
//         pp++;
//         }else if(pi==0){
//             printf(" %d",c[p]);
//         }
//         pi=0;
//     }
//     return 0;
// }

// int main(){
//    int aln[10],sum=0;
//    for(int i=0;i<10;i++){
//       scanf("%d",&aln[i]);
//    }
//    for(int j=0;j<10;j++){
//       if(aln[j]%5==0){
//          sum+=aln[j];
//       }
//    }
//    printf("%d",sum);
//    return 0;
// }

// int main(){
//    int aln1[1000],aln2[1000]={1},x,i=0,max=0,len=0;
//    scanf("%d",&aln1[0]);
//    for(int i=1;i<=aln1[0];i++){
//       scanf("%d",&aln1[i]);
//    }
//    if(aln1[0]==1){
//     printf("%d %d",aln1[1],1);
//    }else{
//    len=aln1[0];
//    for(int j=1;j<=len;j++){
//       for(int z=1;z<=len;z++){
//         if(aln1[j]==aln1[z]&&j!=z){
//             aln2[j]++;
//         }
//       }
//    }
//    for(int k=1;k<=len;k++){
//     if(max<aln2[k]){
//         max=aln2[k];
//         x=k;
//     }
//    }
//    printf("%d %d",aln1[x],max+1);
//    }
//    return 0;
// }

// int main(){
//    int n,x,aln[20],cnt=0;
//    scanf("%d %d",&n,&x);
//    for(int i=0;i<n;i++){
//       scanf("%d",&aln[i]);
//    }
//    for(int j=0;j<n;j++){
//       if(aln[j]==x){
//          printf("%d",j);
//          break;
//       }
//       cnt++;
//    }
//    if(cnt==n) printf("Not Found");
//    return 0;
// }

// int main(){
//    int n,x,aln[1000]={0};
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//       scanf("%d",&aln[i]);
//    }
//    scanf("%d",&x);
//    aln[n]=x;
//    int len=n+1;
//    for(int j=0;j<len;j++){
//       for(int z=0;z<=len-j;z++){
//          if(aln[z]<aln[z+1]){
//             int t=aln[z+1];
//             aln[z+1]=aln[z];
//             aln[z]=t;
//          }
//       }
//    }
//    for(int h=0;h<len;h++){
//       printf("  %d",aln[h]);
//    }
//    return 0;
// }

// int main(){
//    char *s;
//    s=(char*)malloc(sizeof(char)*9998);
//    scanf("%s",s);
//    int len=strlen(s);
//    int aln[1000]={0};
//    for(int i=0;i<len;i++){
//       aln[s[i]]=1;
//    }
//    for(int j=0;j<len;j++){
//       if(aln[s[j]]==1){
//       printf("%c",s[j]);
//       aln[s[j]]-=100;
//       }
//    }
//    free(s);
//    return 0;
// }

// //二阶 fun1 
// int fun1(int arr[2][2],int i,int m,int n)
// {
//     int res2;
//     //i=0,n=1,m=0
//     res2=arr[i][m]*arr[i+1][n]-arr[i][n]*arr[i+1][m];
//     return res2;
//  } 
 
// //从三阶行列式中框选出二阶行列式 
// int (*cut(int arr2[3][3], int x, int y,int arr3[2][2]))[2] //x表示需要删除的行数，y表示需要删除的列数 
//  {
//      static int static_arr3[2][2];
     
//      int a=0;
//      int b=0;
//      int i,j;
     

//      for(i=0;i<3;i++){
//          if(i==x){
//              continue;
//         }
//         for(j=0;j<3;j++){
//              if(j==y){
//                 continue;
//              }
//         arr3[a][b]=arr2[i][j];
//         b++;
//         }
//     a++;
//     b=0; //处理完一行后，将索引重置为0 
//     if(a==2){
//         break;
//     } 
//     }
//     int (*arr4)[2]=static_arr3;
//     return arr4;
//  }

//  //三阶 fun2
// int fun2(int arr1[3][3])
//  {    int arrA[2][2],arrB[2][2],arrC[2][2];
//      cut(arr1,0,0,arrA); //分别表示出对应的二阶行列式 //  a00 a01 a02 
//     cut(arr1,0,1,arrB);                                   //  a10 a11 a12
//     cut(arr1,0,2,arrC);                                 //  a20 a21 a22
//      int n[3];
//      n[0]=fun1(arrA,1,1,2);        //j=0:m=1,n=2
//     n[1]=fun1(arrB,1,0,2);        //j=1:m=0,n=2
//     n[2]=fun1(arrC,1,0,1);        //j=2:m=0,n=1
    
    
//     int res3=0;
//     int j;
//      for(j=0;j<3;j++){
//          res3+=(int)pow(-1, j)*n[j]*arr1[0][j];
//      }
//     return res3;
     
//    }

// int reverse(int x) {
//     long long aln[32],len=0,num=0;
//      if(x==0||x>pow(2,31)-1||x<-pow(2,31)){
//         num=0;
//         return num;
//     }else if(x>0&&x<=pow(2,31)-1){
//         while(x>0){
//             aln[len]=x%10;
//             x/=10;
//             len++;
//         }
//     }else if(x<0&&x>=-pow(2,31)){
//         int f=-x;
//         while(f>0){
//             aln[len]=f%10;
//             f/=10;
//             len++;
//         }
//         for(int i=0;i<=len;i++){
//             aln[i]-=2*aln[i];
//         }
//     }
//     int k=0;
//     while(k<len){
//     num+=aln[k]*pow(10,len-k-1);
//     k++;
//     }
//     if(num==0||num>pow(2,31)-1||num<-pow(2,31)){
//         num=0;
//         return num;
//     }
//     return num;
// }

// int main(){
//     printf("%d",reverse(1534236469));
//     return 0;
// }

// int myAtoi(char* s) {
//     int len=strlen(s),aln[200],cnt=0;
//     for(int i=0;i<len-1;i++){
//         if(i==0&&s[i]>=48&&s[i]<=57&&s[i+1]>=48&&s[i+1]<=57){
//             aln[cnt]=(int)s[i]-48;
//             cnt++;
//         }else{
//             if(s[i]>=48&&s[i]<=57&&s[i+1]>=48&&s[i+1]<=57){
//                 aln[cnt]=(int)s[i]-48;
//                 cnt++;
//             }
//         }
//     }
//     int llg=0;
//     if(cnt==len){
//     aln[cnt]=(int)s[len]-48;
//     llg=cnt+1;
//     }
//     else {
//         llg=cnt;
//     }
//     int k=0;
//     int num=0;
//     whlie(k<llg){
//     num+=aln[k]*pow(10,llg-k);
//     k++;
//     }
//     return num;
// }

// int main(){
// int n=2;
// char s[2]={'a','b'};
// int stk[n + 1], top = 0;
//     for (int i = 0; i < n; i++) {
//         char ch ='a';
//         if (ch) {
//             if (top == 0 || stk[top - 1] != ch) {
//                 return 123;
//             }
//             top--;
//         } else {
//             stk[top++] = s[i];
//         }
//     }
//     return 123;
// }

int main(){
    int nums[]={1,5,4,2,9,9,9},numsSize=sizeof(nums)/sizeof(nums[0]);
    int slow=1,fast=1;
    for(;fast<numsSize;fast++){
        if(nums[fast]!=nums[fast-1]){
            nums[slow]=nums[fast];
            slow++;
        }
    }
    for(int j=0;j<slow;j++){
    printf("%d ",nums[j]);
    }
    return 0;
}

