#ifndef _STRBUF_H
#define _STRBUF_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct strbuf {
    int len;
    int alloc;
    char *buf;
};

void strbuf_init(struct strbuf *sb, size_t alloc);
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc);
void strbuf_release(struct strbuf *sb);
void strbuf_swap(struct strbuf *a, struct strbuf *b);
char *strbuf_detach(struct strbuf *sb, size_t *sz);
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second);
void strbuf_reset(struct strbuf *sb);

void strbuf_grow(struct strbuf *sb, size_t extra);
void strbuf_add(struct strbuf *sb, const void *data, size_t len);
void strbuf_addch(struct strbuf *sb, int c);
void strbuf_addstr(struct strbuf *sb, const char *s);
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2);
void strbuf_setlen(struct strbuf *sb, size_t len);
size_t strbuf_avail(const struct strbuf *sb);
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len);

void strbuf_rtrim(struct strbuf *sb);
void strbuf_ltrim(struct strbuf *sb);
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len);

ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint);
int strbuf_getline(struct strbuf *sb, FILE *fp);

struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max);
bool strbuf_begin_judge(char *target_str, const char *str, int strnlen);
char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len);
#endif

// 初始化 sb 结构体，容量为 alloc
void strbuf_init(struct strbuf *sb, size_t alloc){
  sb->alloc=alloc;
  sb->len=0;
  sb->buf=(char*)malloc(alloc);
  sb->buf[sb->len] = '\0';
}
// 将字符串填充到 sb 中，长度为 len，容量为 alloc
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc){
    sb->buf=(char*)str;
    sb->len=len;
    sb->alloc=alloc;
}
// 释放 sb 结构体的内存
void strbuf_release(struct strbuf *sb){
  if(sb->buf!=NULL){
  free(sb->buf);
  }
  sb->buf=NULL;
  sb->alloc=0;
  sb->len=0;
}
// 交换两个 strbuf
void strbuf_swap(struct strbuf *a, struct strbuf *b){
  struct strbuf temp=*a;
  *a=*b;
  *b=temp;
}
// 将 sb 中的原始内存取出，并将 sz 设置为其 alloc 大小
char *strbuf_detach(struct strbuf *sb, size_t *sz){
  *sz=sb->alloc;
  return sb->buf;
}
// 比较两个 strbuf 的内存是否相同
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second){
   return strcmp(first->buf,second->buf);
}
// 清空 sb
void strbuf_reset(struct strbuf *sb){
  //if(sb->buf!=NULL) free(sb->buf);
  sb->buf[sb->len]='\0';
  sb->len=0;
}

//part 2 

// 确保在 len 之后 strbuf 中至少有 extra 个字节的空闲空间可用。
void strbuf_grow(struct strbuf *sb, size_t extra){
  if(sb->alloc-sb->len<extra){
        sb->buf=(char*)realloc(sb->buf,sb->alloc+extra+1);
        sb->alloc += extra;
  }
}
// 向 sb 追加长度为 len 的数据 data。
void strbuf_add(struct strbuf *sb, const void *data, size_t len){
  strbuf_grow(sb, len + 1);
  memcpy(sb->buf + sb->len, data, len);
  sb->buf[sb->len += len] = '\0';
}
// 向 sb 追加一个字符 c。
void strbuf_addch(struct strbuf *sb, int c){
  strbuf_add(sb,&c,1);
}
// 向 sb 追加一个字符串 s。
void strbuf_addstr(struct strbuf *sb, const char *s){
  strbuf_add(sb,s,strlen(s));
}
// 向一个 sb 追加另一个 strbuf 的数据。
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2){
  strbuf_add(sb,sb2->buf,sb2->len);
}
// 设置 sb 的长度 len。
void strbuf_setlen(struct strbuf *sb, size_t len){
  sb->len=len;
  sb->buf[len]='\0';
}
// 计算 sb 目前仍可以向后追加的字符串长度。
size_t strbuf_avail(const struct strbuf *sb){
   int exlen=sb->alloc-sb->len-1;                                                                                                                                                                                                                                        
   return exlen;
}
// 向 sb 内存坐标为 pos 位置插入长度为 len 的数据 data。
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len){
    strbuf_setlen(sb, sb->len + len+1);
    memmove(sb->buf + pos + len, sb->buf + pos, sb->len - pos);
    memcpy(sb->buf + pos, data, len);
}

//pare 2c

// 去除 sb 缓冲区左端的所有空格、制表符和'\t'字符。
void strbuf_ltrim(struct strbuf *sb){
    while((*(sb->buf)==' '||sb->buf[0]=='\t'))
    {                                                        
      sb->buf=(char*)memmove(sb->buf,sb->buf+1,sb->len-1);
      sb->len--;
    }
}
// 去除 sb 缓冲区右端的所有空格、制表符和'\t'字符。
void strbuf_rtrim(struct strbuf *sb){
    while((sb->buf[(sb->len)-1]==' '||sb->buf[(sb->len)-1]=='\t')&&sb->buf[(sb->len)-1]!='\0')
    {                                                        
      sb->buf[(sb->len)-1]='\0';
      sb->len--;
    }
}
// 删除 sb 缓冲区从 pos 坐标开始长度为 len 的内容。
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len){
  memmove(sb->buf+pos,sb->buf+pos+len,sb->len-pos-len);
  sb->len-=len;
  sb->buf[sb->len]='\0';
}
// 将文件描述符为 fd 的所有文件内容追加到 sb 中。sb 增长 hint ? hint : 8192 大小。
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint){
    strbuf_grow(sb, hint ? hint : 8192);
    FILE *fp = fdopen(fd, "r");
    for (char ch; (ch = fgetc(fp)) != EOF;) strbuf_addch(sb, ch);
    return sb->len;
}
// 将文件句柄为 fp 的一行内容（抛弃换行符）读取到 sb。
int strbuf_getline(struct strbuf *sb, FILE *fp){
    char ch;
    while((ch=fgetc(fp))!='\n'&&ch!=EOF&&ch!='\r'){
       strbuf_addch(sb,ch);
    }
    return sb->len;
}

struct strbuf** strbuf_split_buf(const char* str, size_t len, int terminator, int max){
struct strbuf**a=(struct strbuf**)malloc((max+1)*sizeof(struct strbuf*));
    for (int pos = 0, flag = 0, n = 0; pos <= len && n < max; pos++) {
        while (str[flag] == terminator) pos = flag++ + 2;
        if (pos == len || pos > flag && str[pos] == terminator) {
            a[n] = (struct strbuf *) malloc(sizeof(struct strbuf));
            strbuf_init(a[n],0);
            strbuf_add(a[n], str + flag, pos - flag);
            while (str[pos] == terminator) flag = pos++;
            a[++n] = NULL;
        }
    }
    return a;
}
bool strbuf_begin_judge(char* target_str, const char* str, int strlen){
     int i;
    for(i=0;i<strlen;i++){
      if(str[i]=='\0') break;
      if(target_str[i]!=str[i])return false;
    }
    return true;
}
char* strbuf_get_mid_buf(char* target_buf, int begin, int end, int len){
    if(begin<0||end>len||end<begin)return NULL;
    char*back=(char*)malloc(sizeof(char)*(end-begin+1));
    memcpy(back,target_buf+begin,end-begin);
    back[end-begin]='\0'; 
    return back;
}
