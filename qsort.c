/*
 * 標準ライブラリ関数qsortを使ってみる
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h> // strtol のエラー判定用
#include <string.h> // strerror(errno) のため

// qsort は、比較用に二つのconst voidポインタをとり、int で正負 (1 / -1には限定されない) か0を返す関数へのポインタを引数にとる
// 2引数が指すデータの大小関係を比較しそれによって正負か0（=等しい）かを返す関数を用途に応じて設計する
// 以下では、わかりやすくするために型変換を1行ずつ実行している

int comp_int(const void *x0, const void *x1)
{
    const int *p0 = x0; // x0 is interpreted as a pointer to an integer
    const int y0 = *p0; // y0 is the int value that exists at p0
    //  const int y0 = *(int*)x0;  // The above can be written in one line.
    
    const int *p1 = x1;
    const int y1 = *p1;
    //  const int y1 = *(int*)x1;
    
    if (y0 > y1) return 1;
    if (y0 < y1) return -1;
    return 0;
}

// 上記の関数は以下のように書いてもよい
// （実際には正負 と 0 の情報だけを用いているため）
/*
  int comp_int(const void *x0, const void *x1)
  {
  return *(int*)x0 - *(int*)x1;
  }
*/


/* strtol と エラー判定を一つの関数に入れておく*/
int load_int(const char *str)
{
    errno = 0;
    char *e;
    long n = strtol(str,&e,10);
    
    // エラーチェック
    if (errno == ERANGE){
	fprintf(stderr, "%s: %s\n", str, strerror(errno));
	exit(EXIT_FAILURE);
    }
    if( *e != '\0'){
	fprintf(stderr, "%s: an irregular character '%c' is detected.\n",str,*e);
	exit(EXIT_FAILURE);
    }
    return (int)n;
}


int main(int argc, char **argv)
{
    if(argc != 2){
	fprintf(stderr, "usage: %s <number of elements>\n",argv[0]);
	exit(EXIT_FAILURE);
    }
    
    int n = load_int(argv[1]);
    
    int *v = (int*) malloc(sizeof(int) * n);
    errno = 0;
    if (v == NULL){
	fprintf(stderr, "Error: %s\n",strerror(errno));
	exit(EXIT_FAILURE);
    }
    
    for(int i = 0 ; i < n ; i++){
	v[i] = rand()%1024;// 0 - 1023 で値を入れる
    }
    
    // sort前表示
    printf("[");
    for(int i = 0 ; i < n ; i++){
	printf("%d ",v[i]);
    }
    printf("]\n");
    
    // qsort実行
    qsort(v, n, sizeof(int), comp_int);
    
    // sort後表示
    for (int i = 0; i < n; i++) {
	printf("v[%d] = %d\n", i, v[i]);
    }
    
    free(v);
    return 0;
}
