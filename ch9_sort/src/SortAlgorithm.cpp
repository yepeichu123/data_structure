#include "SortAlgorithm.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

SortAlgorithm::SortAlgorithm() {

}

SortAlgorithm::~SortAlgorithm() {

}

// 冒泡排序初级版本
bool SortAlgorithm::BubbleSort(SqList* L) {
    if (L == nullptr) {
        return false;
    }

    for (int i = 0; i < L->length; i++) {
        for (int j = i + 1; j < L->length; j++) {
            if (L->r[i] > L->r[j]) {
                if (!Swap(L, i, j) ) {
                    return false;
                }
            }
        }
    }
    return true;
}

// 冒泡排序正宗版
bool SortAlgorithm::BubbleSortAuthentic(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    int n = L->length;
    for (int i = 0; i < n; ++i) {
        for (int j = n -2; j >= i; --j) {
            if (L->r[j] > L->r[j+1]) {
                if (!Swap(L, j, j+1)) {
                    return false;
                }
            }
        }
    }
}

// 冒泡排序牛逼版
bool SortAlgorithm::BubbleSortNiubility(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    int n = L->length;
    bool flag = true;
    for (int i = 0; i < n && flag; ++i) {
        flag = false;
        for (int j = n - 2; j >= i; --j) {
            if (L->r[j] > L->r[j + 1]) {
                if (!Swap(L, j, j+1)) {
                    return false;
                }
                flag = true;
            }
        }
    }
    return true;
}

// 简单选择排序法
bool SortAlgorithm::SelectSort(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    if (L->length <= 0) {
        return false;
    }
    int n = L->length;
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = n-1; j >= i; --j) {
            if (L->r[j] < L->r[min]) {
                min = j;
            }
        }
        if (!Swap(L, i, min)) {
            return false;
        }
    }
}

// 直接插入排序法
bool SortAlgorithm::InsertSort(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    if (L->length <= 0) {
        return false;
    }

    int n = L->length;
    for (int i = 1; i < n; ++i) {
        // 每次只比较一次数
        if (L->r[i] < L->r[i - 1]) {
            int temp = L->r[i];
            // 比较当前id前的其他参数是否比当前值大，若是，则集体右移．
            // 若不是或者达到索引极限，则退出循环
            int j = i - 1;
            for (; L->r[j] > temp && j >= 0; --j) {
                L->r[j+1] = L->r[j];   
            }
            // 将当前值插入适合的位置
            L->r[j+1] = temp;
        }
    }
    return true;
}

// 希尔排序
bool SortAlgorithm::ShellSort(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    if (L->length <= 0) {
        return false;
    }
    int i, j;
    int increament = L->length;
    do {
        // 类似于插入排序，但是不是顺序插入，而是跳跃插入
        increament = increament / 3 + 1;
        for (i = increament; i < L->length; ++i) {
            if (L->r[i] < L->r[i - increament]) {
                int temp = L->r[i];
                // 数据右移
                for (j = i - increament; j >= 0 && L->r[j] > temp; j -= increament) {
                    L->r[j + increament] = L->r[j];
                }
                // 更新左值
                L->r[j + increament] = temp;
            }
        }
    }
    while (increament > 1); // 表明increament == 1的时候跳出循环
}

// 堆排序
bool SortAlgorithm::HeapSort(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    if (L->length <= 0) {
        return false;
    }
    // 构建大顶堆
    for (int i = (L->length)/2; i >= 0; --i) {
        HeadAdjust_(L, i, L->length-1);
    }
    cout << "We construct a big top heap:" << endl;
    for (int i = 0; i < L->length; ++i) {
        cout << L->r[i] << " ";
    }
    cout << endl;

    for (int i = L->length - 1; i >= 1; --i) {
        // 交换堆顶和末尾值
        Swap(L, 0, i);
        // 剩余数构建新的大顶堆
        HeadAdjust_(L, 0, i-1);
        cout << "i = " << i << ": " << endl;
        for (int j = 0; j < L->length; ++j) {
            cout << L->r[j] << " ";
        }
        cout << endl;
    }
}

// 归并排序：递归法
bool SortAlgorithm::MergeSortRecursion(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    if (L->length <= 0) {
        return false;
    }
    return MSort_(L->r, L->r, 0, L->length-1, L->length);
}

// 归并排序：迭代法
bool SortAlgorithm::MergeSortIteration(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    if (L->length <= 0) {
        return false;
    }
    // 申请与序列等长的临时空间
    int* TR = new int[L->length];
    // 步长
    int step = 1;
    // 开始迭代
    while (step < L->length) {
        // 第一步：将序列中的数值按照两两归并存到TR中
        // 第二步：步长翻倍，从原先的只需排序两个数，到需要排序四个数
        // 第三步：步长继续翻倍，此时排序八个数
        // ．．．
        // 总结来看，就是从最小的单元不断的排序合并，最终形成越来越大的两个数组，最后将这两个数组合并
        // 有意思的是，下列的语句是将数值在两个容器中不断倒来倒去．
        MergePass_(L->r, TR, step, L->length-1);
        step = step * 2;
        MergePass_(TR, L->r, step, L->length-1);
        step = step * 2;
    }
    if (TR != nullptr)
        delete []TR;
    return true;
}

// 快速排序法
bool SortAlgorithm::QuickSort(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    if (L->length < 0) {
        return false;
    }

    return QSort_(L, 0, L->length-1);
}

// 快速排序法优化版
bool SortAlgorithm::QuickSortOpt(SqList* L) {
    if (L == nullptr) {
        return false;
    }
    if (L->length < 0) {
        return false;
    }

    return QSortOpt_(L, 0, L->length-1);
}

// 交换数据
bool SortAlgorithm::Swap(SqList* L, int s, int m) {
    if (L == nullptr) {
        return false;
    }
    if (s < 0 || s > L->length ||
        m < 0 || m > L->length) {
        return false;
    }

    int temp = L->r[s];
    L->r[s] = L->r[m];
    L->r[m] = temp;

    return true;
}

// 随机改变数组顺序
bool SortAlgorithm::ChangePosRandom(SqList* L) {
    if (L == nullptr || L->length == 0) {
        return false;
    }
    int n = L->length;
    for (int i = n - 1; i >= 0; --i) {
        if (!Swap(L, i, rand()%n)) {
            return false;
        }
    }
    return true;
}

bool SortAlgorithm::HeadAdjust_(SqList* L, int s, int m) {
    if (L == nullptr) {
        return false;
    }
    if (s < 0 || s > L->length ||
        m < 0 || m > L->length) {
        return false;
    }
    int temp;
    temp = L->r[s];
    for (int j = 2 * s; j <= m; j *= 2) {
        // 左子树小于右子树，取右子树，否则取左子树
        if (j < m && L->r[j] < L->r[j+1]) {
            ++j;
        }
        // 当前节点比其左右子树都大，不需要修改
        if (temp >= L->r[j]) {
            break;
        }
        // 交换位置
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp;

    return true;
}

// 合并两个子序列
bool SortAlgorithm::Merge_(int SR[], int TR[], int begin, int mid, int end) {
    if (SR == nullptr || TR == nullptr) {
        return false;
    }
    if (begin < 0 || end < 0 ) {
        return false;
    }
    // 按大小关系逐步插入新数组中
    int k = 0, j = 0;
    for (j = mid + 1, k = begin; begin <= mid && j <= end; ++k) {
        if (SR[begin] < SR[j]) {
            TR[k] = SR[begin++];
        }
        else {
            TR[k] = SR[j++];
        }
    }
    // 到最后，前半部分的数组仍有数未插入目标数组中，显然这部分是最大的，因此放到数组最后
    if (begin <= mid) {
        for (int l = 0; l <= mid - begin; ++l) {
            TR[k+l] = SR[begin+l];
        }
    }
    // 同理，若前半部分插完了，后半部分还有剩余，也放到数组最后．
    else {
        for (int l = 0; l <= end - mid; ++l) {
            TR[k+l] = SR[j+l];
        }
    }

    // cout << "After merging." << endl;
    // for (int i = 0; i <= end; ++i) {
        // cout << TR[i] << " ";
    // }
    // cout << endl;
    return true;
}

// 将SR中相邻长度为s的子序列两两归并到TR[]中
bool SortAlgorithm::MergePass_(int SR[], int TR[], int step, int end) {
    if (SR == nullptr || TR == nullptr) {
        return false;
    }
    if (step < 0 || end < 0 ) {
        return false;
    }

    // 这一步执行两两归并，得到两两有序的序列
    int i = 0;
    while (i <= end - 2 * step + 1) {
        // 比如step = 1: 0-1, 2-3, 4-5, ...
        // 比如step = 2: 0-3, 4-7, 8-11, ...
        // 比如step = 3: 0-5, 6-11, ...
        Merge_(SR, TR, i, i+step-1, i+2*step-1);
        i = i + 2 * step;
    }
    // 若是数组有９个元素，则
    // step = 1: i=8跳出循环，并且8 < 8-1+1不满足，则执行else语句，将末尾数赋值
    // step = 2: i=8跳出循环，并且8 < 8-2+1不满足，则执行else语句，将末尾数赋值
    // ...
    // 若最后剩两个数组，此时步长step已经不满足循环条件，于是只能执行if语句，将最后两个数组合并．
    if (i < end - step + 1) {
        Merge_(SR, TR, i, i+step-1, end);
    }
    else {
        for (int j = i; j <= end; ++j) {
            TR[j] = SR[j];
        }
    }
    return true;
}

// 将原矩阵SR归并排序为TR
bool SortAlgorithm::MSort_(int SR[], int TR[], int begin, int end, int length) {
    if (SR == nullptr || TR == nullptr) {
        return false;
    }
    if (begin < 0 || begin >= length ||
         end < 0 || end >= length) {
        return false;
    }

    // 由于输入和输出是同一个数组，为了防止覆盖，需要申请一个新的内存空间用于暂时存放数据．
    int TR2[length];
    // 递归终止条件，将数组分割成原子时，不可再分
    if (begin == end) {
        TR[begin] = SR[begin];
    }
    // 每次都折半递归，直到终止条件为止
    // 得到的结果是:1->2->4->8->...->2n
    // 于是可以从前后两部分的数组中，由2->4->8这样进行归并排序
    else {
        int mid = (begin + end) / 2;
        MSort_(SR, TR2, begin, mid, length);
        MSort_(SR, TR2, mid+1, end, length);
        Merge_(TR2, TR, begin, mid, end);
    }
    return true;
}

// 递归排序
bool SortAlgorithm::QSort_(SqList* L, int low, int high) {
    if (L == nullptr) {
        return false;
    }
    if (L->length < 0) {
        return false;
    }
    if (low < 0 || low >= L->length ||
         high < 0 || high >= L->length) {
        return false;
    }

    int pivot = 0;
    if (low < high) {
        // 找出轴心，将数据划分成两部分，前半部分均小于轴心，后半部分均大于轴心
        pivot = Partition_(L, low, high);

        // 对前半部分进行递归排序
        QSort_(L, low, pivot-1);

        // 对后半部分进行递归排序
        QSort_(L, pivot+1, high-1);
    }
    return true;
}

// 递归排序优化版
bool SortAlgorithm::QSortOpt_(SqList* L, int low, int high) {
    if (L == nullptr) {
        return false;
    }
    if (L->length < 0) {
        return false;
    }
    if (low < 0 || low >= L->length ||
         high < 0 || high >= L->length) {
        return false;
    }

    int pivot = 0;
    if (low < high) {
        // 找出轴心，将数据划分成两部分，前半部分均小于轴心，后半部分均大于轴心
        pivot = PartitionOpt_(L, low, high);

        // 对前半部分进行递归排序
        QSortOpt_(L, low, pivot-1);

        // 对后半部分进行递归排序
        QSortOpt_(L, pivot+1, high-1);
    }
    return true;
}

// 找出枢轴，将序列划分成两部分
int SortAlgorithm::Partition_(SqList* L, int low, int high) {
    if (L == nullptr) {
        return false;
    }
    if (L->length < 0) {
        return false;
    }
    if (low < 0 || low >= L->length ||
         high < 0 || high >= L->length) {
        return false;
    }

    int pivotkey;
    pivotkey = L->r[low];
    while (low < high) {
        // 从后往前逐个遍历，只要发现比参考值小的，则交换
        while (low < high && L->r[high] >= pivotkey) {
            --high;
        }
        Swap(L, low, high);
        // 从前往后逐个遍历，只要发现比参考值大的，则交换
        while (low < high && L->r[low] <= pivotkey) {
            ++low;
        }
        Swap(L, low, high);
    }

    return low;
}

// 优化版：找出枢轴，将序列划分成两部分，采用三数取中法
int SortAlgorithm::PartitionOpt_(SqList* L, int low, int high) {
    if (L == nullptr) {
        return false;
    }
    if (L->length < 0) {
        return false;
    }
    if (low < 0 || low >= L->length ||
         high < 0 || high >= L->length) {
        return false;
    }

    int pivotkey;
    int mid = low + (high - low) / 2;
    if (L->r[low] > L->r[high]) {
        Swap(L, low, high);
    }
    if (L->r[mid] > L->r[high]) {
        Swap(L, high, mid);
    }
    if (L->r[mid] > L->r[low]) {
        Swap(L, mid, low);
    }
    pivotkey = L->r[low];

    while (low < high) {
        // 从后往前逐个遍历，只要发现比参考值小的，则交换
        while (low < high && L->r[high] >= pivotkey) {
            --high;
        }
        L->r[low] = L->r[high];
        // 从前往后逐个遍历，只要发现比参考值大的，则交换
        while (low < high && L->r[low] <= pivotkey) {
            ++low;
        }
        L->r[high] = L->r[low];
    }
    L->r[low] = pivotkey;

    return low;
}