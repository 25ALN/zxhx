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
    struct strbuf *sb=(char*)malloc(alloc*sizeof(char));
}
// 将字符串填充到 sb 中，长度为 len，容量为 alloc
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc){
     
}
int main(){
    struct strbuf sb;
    return 0;
}