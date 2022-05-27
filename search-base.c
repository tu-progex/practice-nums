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

// 課題(1): リニアサーチ
// num[0]~nums[nelm-1]の中にqがあるか検索し，あれば1，なければ0をreturnする
int linear_search (int q, int nums[], int nelm)
{
  // ここを演習で作成する(1)
}

// 課題(2): バイナリサーチ
// num[0]~nums[nelm-1]の中にqがあるか検索し，あれば1，なければ0をreturnする
// ただし，nums[]は事前に昇順に並び換えられているものとする
int binary_search (int q, int nums[], int nelm)
{
  // ここを演習で作成する(2)
}

int main (int argc, char *argv[]) {
  // 探したい整数をqにセット
  int q;
  if (argc<2) {
    printf ("探したい整数が指定されていません\n");
    printf ("%s 100 のように何か数を指定して実行してください\n", argv[0]);
    return 1;
  } else {
    q = atoi (argv[1]);
  }
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

  printf ("数列の中に%dがあるか探します\n", q);
  double t1 = get_current_time();  // 探索開始時刻

  //// 重要：この時点で，qには探したい数，nelmには要素の数，nums[0]~nums[n-1]には読み込んだ数列が入っている
  int kekka;
  // 重要：下2行のうちどちらかのみを//を置かずに残す
  kekka = linear_search (q, nums, nelm);
  // kekka = binary_search (q, nums, nelm);
  //// 重要：この時点でkekkaには0（qがnums[]から見つからなかった場合），1（見つかった場合）が入っている

  double t2 = get_current_time();  // 探索終了時刻
  if (kekka != 0) {
    printf ("見つかりました\n");
  } else {
    printf ("見つかりませんでした\n");  
  }
  printf ("処理にかかった時間: %f 秒\n", t2-t1);
  free (nums);
  return 0;
}