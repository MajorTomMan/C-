#include <iostream>
using namespace std;

/* 错误的交换函数代码 */
void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
// 错误在哪? 因为该函数运行到最后一行后,系统会将该函数的所占空间释放
// 因此交换后的数据随着函数的空间释放便一起被释放了,并且该函数没有返回值或者没有使用指针,故无法修改实际参数的数据
/* 正确的交换函数代码 */
void swap_fixed(int *x, int *y)
{
    int temp=*x;
    *x = *y;
    *y = temp;
}

/* 返回值是该数组中和target相同的个数 */
template <class T>
int Count(T *arr, int length, T target)
{
    int index = 0;
    int count = 0;
    do
    {
        if (*arr != target)
        {
            ;
        }
        else
        {
            count++;
        }
        index++;
        arr++;
    } while (index != length);
    return count;
}

/* 填充空数组 */
template <class T>
void Fill(T *arr, int length, T value)
{
    int index = 0;
    while (index != length)
    {
        *arr = value;
        arr++;
        index++;
    }
}

/*     n-1
    计算∑ a[i]*b[i]的返回值
       i=0
*/
template <class T>
/* 非递归方式实现 */
T inner_product(T *a, T *b, int length)
{
    int index = 0;
    T sum = 0;
    do
    {
        sum += (*a++) * (*b++);
        index++;
    } while (index != length);
    return sum;
}
template <class T>
/*  递归方式实现 */
T inner(T a[], T b[], T n)
{
    if (n == 0)
    {
        return a[n] * b[n];
    }
    return a[n] * b[n] + inner(a, b, n - 1);
    ;
}
// 一点小吐槽 递归之前是真的一点都摸不着头脑,
// 但是看到一本算法书上写按数学归纳法的角度看,一下就豁然开朗了,
// 做点笔记  完全递归形式需要两点要求满足
// 第一是基础部分即 函数f(x)必须满足输入与其运算后输出的结果一一对应
// 举个例子 定义一个函数  f(n) 若其为求阶乘函数 则 f(1)=1 f(2)=1*2 f(3)=1*2*3.....直到f(10)=10*9*8*7*6*5*4*3*2*1
// 该函数可抽象为f(10)=10*f(9) f(9)=f(8)*9 以此类推 直至 f(2)=f(1)*2 f(1)=1
// 用数学语言将其一般化可化为一个分段函数      { n            n<=1}
//                                    f(x)=
//                                          { n*f(n-1)     n>1 }
// 第二点 递归部分 右侧函数必须保证其至少有一个参数小于左侧表达式使其可以进行下去不进入死循环
// 依然还是以阶乘为例 若n>1的情况下 n*f(n) 则 f(10)=10*f(10)=10*10*f(10)........
// 直接导致进入毫无意义的死循环
// 故总结如下 第一 要有一个明确的结束条件 第二 要找到函数之间的递推关系才能写出正确的递归解决方法
// 递归本质还是个栈,要理解这一点并结合上面几点便不难掌握递归了

template <class T>
/* 使a[i]=value+i  */
void itoa(T *a, int length, T value)
{
    int index = 0;
    while (index != length)
    {
        *a++ = value + index;
        index++;
    }
}
template <class T>
/* 检查是否有序(按从小到大)  */
//    (按从小到大)
bool is_sorted(T *a, int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] <= a[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout << "Hello, world!"
         << "\n";
    int x = 5, y = 6;
    swap(x, y);
    cout << "错误的交换结果:x:" << x << " y:" << y << "\n";
    swap_fixed(&x, &y);
    cout << "正确的交换结果:x:" << x << " y:" << y << "\n";
    int length = 5;
    int arr[length] = {2, 4, 5, 2, 4};
    int test_a[length] = {5, 4, 3, 2, 1};
    int test_b[length] = {1, 2, 3, 4, 5};
    cout << "该数组中2的个数为:" << Count(arr, length, 2) << endl;
    Fill(arr, length, 7);
    itoa(arr, length, 8);
    for (int index = 0; index != length; index++)
    {
        cout << "该数组中第" << index << "个的数据为:" << arr[index] << endl;
    }
    cout << "两个数组各项相乘的总和为:" << inner(test_a, test_b, length - 1) << "\n";
    for (int index = 0; index != length; index++)
    {
        cout << "该数组中第" << index << "个的数据为:" << arr[index] << endl;
    }
    int array[length] = {2, 4, 5, 2, 4};
    // 1代表true 0代表false
    cout << "该数组是否有序:" << is_sorted(array, length) << endl;
    getchar();
    return 0;
}
