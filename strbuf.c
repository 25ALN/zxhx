#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include "assert.h" 

struct strbuf {
  int len;     
  int alloc;   
  char *buf;   
};
// 初始化 sb 结构体，容量为 alloc
void strbuf_init(struct strbuf *sb, size_t alloc){
    sb=(struct strbuf*)malloc(alloc*sizeof(char));
}
// 将字符串填充到 sb 中，长度为 len，容量为 alloc
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc){
    sb->buf=(char*)str;
}
// 释放 sb 结构体的内存
void strbuf_release(struct strbuf *sb){
  free(sb);
}
// 交换两个 strbuf
void strbuf_swap(struct strbuf *a, struct strbuf *b){
  struct strbuf temp=*a;
  *a=*b;
  *b=temp;
}
// 将 sb 中的原始内存取出，并将 sz 设置为其 alloc 大小
char *strbuf_detach(struct strbuf *sb, size_t *sz){
  free(sb);
  *sz=sb->alloc;
  return sb->buf;
}
// 比较两个 strbuf 的内存是否相同
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second){
   if(memcmp(first,second,first->len)){
    return 0;
   }else if(memcmp(first,second,second->len)){
    return 0;
   }
   return (memcmp(first,second,first->len));
}
// 清空 sb
void strbuf_reset(struct strbuf *sb){
  strncpy(sb->buf,"\0",1);
  sb->len=0;
  sb->alloc=0;
}

//part 2 

// 确保在 len 之后 strbuf 中至少有 extra 个字节的空闲空间可用。
void strbuf_grow(struct strbuf *sb, size_t extra){
  if(sb->alloc-sb->len<0){
    sb->buf=(char *)realloc(sb->buf,sizeof(char)*extra);
  }
}
// 向 sb 追加长度为 len 的数据 data。
void strbuf_add(struct strbuf *sb, const void *data, size_t len){
  strncpy(sb->buf,(char*)data,len);
}
// 向 sb 追加一个字符 c。
void strbuf_addch(struct strbuf *sb, int c){
  strbuf_add(sb,&c,1);
}
// 向 sb 追加一个字符串 s。
void strbuf_addstr(struct strbuf *sb, const char *s){
  strncpy(sb->buf,s,strlen(s));
}
// 向一个 sb 追加另一个 strbuf 的数据。
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2){
  strncpy(sb->buf,sb2->buf,strlen(sb2->buf));
}
// 设置 sb 的长度 len。
void strbuf_setlen(struct strbuf *sb, size_t len){
  sb->len=len;
}
// 计算 sb 目前仍可以向后追加的字符串长度。
size_t strbuf_avail(const struct strbuf *sb){
   int x=sb->alloc-sb->len;
   return x;
}
// 向 sb 内存坐标为 pos 位置插入长度为 len 的数据 data。
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len){
   strncpy(sb->buf+pos,(char*)data,len);
}

//pare 2c

// 去除 sb 缓冲区左端的所有空格、制表符和'\t'字符。
void strbuf_ltrim(struct strbuf *sb){
    for(int i=0;i<sb->len;i++){
      if(*(sb->buf+i)==' '||*(sb->buf+i)=='\t'){
        *(sb->buf+i)='\0';
      }
}
}
// 去除 sb 缓冲区右端的所有空格、制表符和'\t'字符。
void strbuf_rtrim(struct strbuf *sb){
  for(int i=sb->alloc;i>=sb->len;i--){
    if(*(sb->buf+i)==' '||*(sb->buf+i)=='\t'){
        *(sb->buf+i)='\0';
      }
  }
}
// 删除 sb 缓冲区从 pos 坐标开始长度为 len 的内容。
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len){
  for(int i=pos;i<len;i++){
    *(sb->buf+i)=*(sb->buf+i+len);
  }
  *(sb->buf+len)='\0';
}
// 将文件描述符为 fd 的所有文件内容追加到 sb 中。sb 增长 hint ? hint : 8192 大小。
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint){
       char ch;
       hint=(sb, hint ? hint : 8192);
       sb->buf=(char*)realloc(sb->buf,sb->alloc+sizeof(char)*hint);
       FILE *fp=fdopen(fd,"r");
       while((ch=fgetc(fp)!=EOF)){  
            strbuf_addch(sb,ch);
       }
       return (ch=fgetc(fp));
}
// 将文件句柄为 fp 的一行内容（抛弃换行符）读取到 sb。
int strbuf_getline(struct strbuf *sb, FILE *fp){
    char ch;
    while((ch=fgetc(fp))!='\n'){
       strbuf_addch(sb,ch);
    }
    return strlen(sb->buf);
}
/**
* @brief 将指定长度的字符串按切割字符切割成多个 strbuf
*
* @param str 要切割的字符串
* @param len 字符串的长度
* @param terminator 切割字符
* @param max 最大切割数量（可选）
* @return struct strbuf** 指向 struct strbuf 的指针数组，数组的最后一个元素为 NULL
*
* @note 函数将字符串 str 根据切割字符 terminator 切割成多个 strbuf，并返回结果。可选参数 max 用于限定最大切割数量。
*/
struct strbuf** strbuf_split_buf(const char* str, size_t len, int terminator, int max){
  struct strbuf **a=(struct strbuf **)malloc(sizeof(struct strbuf*)*(max+1));
  int end=1,begin=0;
  char*ap;
  ap=(char*)malloc(sizeof(char)*len);
  for(int i=0;i<len;i++){
    if(str[i]==(char)terminator){
      end=i-1;
      strbuf_add(a[i],str+begin,end-begin);
      begin=i+1;
    }
    a[i]=NULL;
  }
  free(ap);
  free(*a);
  return a;
}
bool strbuf_begin_judge(char* target_str, const char* str, int strlen){
     int len=0;
     for(int i=0;*(target_str+i)!='\0';i++){
          len++;
     }
     if(memcmp(target_str,str,len)==0) return true;
     else return false; 
}
/**
* @brief 获取目标字符串的指定子串
*
* @param target_buf 目标字符串
* @param begin 开始下标（包含）
* @param end 结束下标（不包含）
* @param len target_buf 的长度
* @return char* 指向获取的子串的指针，如果参数不合法则返回 NULL
*
* @note 下标从0开始，[begin, end)表示左闭右开区间
*/
char* strbuf_get_mid_buf(char* target_buf, int begin, int end, int len){
    char *ch;
    for(int i=begin;i<end;i++){
       ch[i]=*(target_buf+i);
    }
    return ch;
}
int main() {
  struct strbuf sb;
  strbuf_init(&sb, 10);
  strbuf_attach(&sb, "xiyou", 5, 10);
  assert(strcmp(sb.buf, "xiyou") == 0);
  strbuf_addstr(&sb, "linux");
  assert(strcmp(sb.buf, "xiyoulinux") == 0);
  strbuf_release(&sb);
  return 0;
}