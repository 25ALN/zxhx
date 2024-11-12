#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
     strncpy(sb->buf,(char*)str,alloc);
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
  free(sb);
}

//part 2 

// 确保在 len 之后 strbuf 中至少有 extra 个字节的空闲空间可用。
void strbuf_grow(struct strbuf *sb, size_t extra){
     sb->alloc+=extra;
}
// 向 sb 追加长度为 len 的数据 data。
void strbuf_add(struct strbuf *sb, const void *data, size_t len){
  strncpy(sb->buf,(char*)data,len);
}
// 向 sb 追加一个字符 c。
void strbuf_addch(struct strbuf *sb, int c){
  strcpy(sb->buf,(char)c);
}
// 向 sb 追加一个字符串 s。
void strbuf_addstr(struct strbuf *sb, const char *s){
  strcpy(sb->buf,s);
}
// 向一个 sb 追加另一个 strbuf 的数据。
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2){
  strcpy(sb->buf,sb2->buf);
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
      strncpy(sb->buf+pos,data,len);
}

//pare 2c

// 去除 sb 缓冲区左端的所有空格、制表符和'\t'字符。
void strbuf_ltrim(struct strbuf *sb){
    for(int i=0;i<sb->len;i++){
      if(*(sb->buf+i)==' '||*(sb->buf+i)=='\t'){
        *(sb->buf+i)=NULL;
      }
}
}
// 去除 sb 缓冲区右端的所有空格、制表符和'\t'字符。
void strbuf_rtrim(struct strbuf *sb){
  for(int i=sb->alloc;i>=sb->len;i--){
    if(*(sb->buf+i)==' '||*(sb->buf+i)=='\t'){
        *(sb->buf+i)=NULL;
      }
  }
}
// 删除 sb 缓冲区从 pos 坐标开始长度为 len 的内容。
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len){
  for(int i=pos;i<=len;i++){
    *(sb->buf+i)="";
  }
}
int main(){
  struct strbuf sb;
  return 0;
}
