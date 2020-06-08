/*
 * 排序算法类
 * 实现作者：叶培楚
 * 邮箱：peichuye_123@163.com
 * 主要实现包括冒泡排序，选择排序，插入排序
 * 冒泡排序是指从尾到头，两两比较，将数值小的移动到前面；
 * 选择排序是从头到尾进行比较，记录一段区间中最小值，并将其移动到区间最前方；
 * 插入排序是边插入边排序，每次只比较相邻两个数值，并将前面小于当前值的数全部后移． （适用于记录数少，基本有序的序列）
*/

#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#define MAXSIZE 10

typedef struct SqList{
    SqList() {

    }
    SqList(int len) {
        length = len;
        r = new int[length];
    }
    ~SqList() {
        if (r != nullptr) {
            delete []r;
        }
    }
    int* r;
    int length;
}SqList;

class SortAlgorithm {
    public:
        SortAlgorithm();

        ~SortAlgorithm();

        // 冒泡排序初级版本
        bool BubbleSort(SqList* L);

        // 冒泡排序正宗版
        bool BubbleSortAuthentic(SqList* L);

        // 冒泡排序牛逼版
        bool BubbleSortNiubility(SqList* L);

        // 简单选择排序法
        bool SelectSort(SqList* L);

        // 直接插入排序法
        bool InsertSort(SqList* L);

        // 希尔排序
        bool ShellSort(SqList* L);

        // 堆排序
        bool HeapSort(SqList* L);

        // 归并排序：递归法
        bool MergeSortRecursion(SqList* L);

        // 归并排序：迭代法
        bool MergeSortIteration(SqList* L);

        // 快速排序法
        bool QuickSort(SqList* L);

        // 快速排序法优化版
        bool QuickSortOpt(SqList* L);

        // 交换表中指定两个位置的数值
        bool Swap(SqList* L, int s, int m);

        // 随机打散数组顺序
        bool ChangePosRandom(SqList* L);
    
    private:
        // 生成大顶堆
        bool HeadAdjust_(SqList* L, int s, int m);

        // 合并两个子序列
        bool Merge_(int SR[], int TR[], int begin, int mid, int end);

        // 将SR中相邻长度为s的子序列两两归并到TR[]中
        bool MergePass_(int SR[], int TR[], int step, int end);

        // 将原矩阵SR归并排序为TR
        bool MSort_(int SR[], int TR[], int begin, int end, int length);

        // 递归排序
        bool QSort_(SqList* L, int low, int high);

        // 递归排序优化版
        bool QSortOpt_(SqList* L, int low, int high);

        // 找出枢轴，将序列划分成两部分
        int Partition_(SqList* L, int low, int high);

        // 优化版：找出枢轴，将序列划分成两部分，采用三数取中法
        int PartitionOpt_(SqList* L, int low, int high);
};

#endif /* SORT_ALGORITHM_H */