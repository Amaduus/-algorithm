#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <string.h>
typedef struct {
    int num;
    int value;
}p;
p a[100010];
int b[100010];
int n = 0, m = 0;
void quick_sort(int l, int r)
{
    if (l >= r) return;
    int mid = a[l + r >> 1].num;
    int i = l - 1, j = r + 1;
    while (i < j) {
        do ++i; while (mid > a[i].num);
        do --j; while (mid < a[j].num);

        if (i < j)
        {
            p t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}
int findl(x)
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid].num >= x)  r = mid;
        else l = mid + 1;
    }
    if (a[l].num >= x)
        return l;
    else return n + 1;//³¬ÏÞ
}
int findr(x)
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid].num <= x)  l = mid;
        else r = mid - 1;
    }
    if (a[l].num <= x)
        return l;
    else return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].num, &a[i].value);
    quick_sort(1, n);
    //È¥ÖØ
    int j = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[j].num == a[i].num)  a[j].value += a[i].value;
        else  a[++j] = a[i];
    }
    n = j;
    for (int i = 1; i <= n; i++)  b[i] = b[i - 1] + a[i].value;
    while (m--)
    {

        int l, r;

        scanf("%d%d", &l, &r);  getchar();
        l = findl(l);
        r = findr(r);
        printf("%d\n", b[r] - b[l - 1]);
    }
    return 0;
}