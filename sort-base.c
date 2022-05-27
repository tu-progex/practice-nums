#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 現在時刻を取得する．精度はナノ秒（ns），返す値の単位は秒（s）
double get_current_time (void) {
  struct timespec tp;
  clock_gettime(CLOCK_REALTIME, &tp);
  return (tp.tv_sec+(double)tp.tv_nsec/1000/1000/1000);
}

// 要素数nelmの数列numsの値を全て表示する
void print_nums (int *nums, int nelm)
{
  for (int i=0; i<nelm; i++) {
      printf ("%d ", nums[i]);
  }
  printf ("\n");
}

// 課題8: バブルソート
// num[0]~nums[nelm-1]を昇順に並び換える
int bubble_sort (int nums[], int nelm)
{
  // ここを演習で作成する
}

// 課題9: クイックソート
// num[0]~nums[nelm-1]を昇順に並び換える
int quick_sort (int nums[], int nelm)
{
  // ここを演習で作成する
}

int main (void) {
  // 標準入力から数列を読み込む
  int nelm=0;        // 配列の要素数 
  int *nums;         // 配列の先頭要素へのポインタ
  int sz=1;          // 確保した配列のサイズ
  nums = (int*) malloc(sizeof(int)*sz);
  while (1) {
    int n;
    int flag = scanf("%d", &n);
    if (flag == EOF) { break; }
    // nums[]のサイズが足りなくなったら倍にする
    if (sz<=nelm) {
        sz *= 2;
        nums = (int*) realloc(nums, sizeof(int)*sz);
    }
    nums[nelm] = n;
    nelm++;
  }
  printf ("読み込み終了: 要素数は%d\n", nelm);
  // この下の行の//を外すと、読み込み後に数列を表示
  // print_nums(nums, nelm);

  printf ("数列を昇順に並び換えます\n");
  double t1 = get_current_time();  // 開始時刻

  //// 重要：この時点で，nelmには要素の数，nums[0]~nums[n-1]には読み込んだ数列が入っている
  // 重要：下2行のうちどちらかのみを//を置かずに残す
  bubble_sort (nums, nelm);
  // quick_sort (nums, nelm);

  double t2 = get_current_time();  // 終了時刻
  print_nums(nums, nelm);
  printf ("処理にかかった時間: %f 秒\n", t2-t1);
  free (nums);
  return 0;
}