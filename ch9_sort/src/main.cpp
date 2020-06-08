#include <iostream>
#include "SortAlgorithm.h"

using namespace std;

void TestBubbleSort(SqList* List, SortAlgorithm* my_sort);

void TestSelectSort(SqList* List, SortAlgorithm* my_sort);

void TestInsertSort(SqList* List, SortAlgorithm* my_sort);

void TestShellSort(SqList* List, SortAlgorithm* my_sort);

void TestHeapSort(SqList* List, SortAlgorithm* my_sort);

void TestMergeSort(SqList* List, SortAlgorithm* my_sort);

void TestQuickSort(SqList* List, SortAlgorithm* my_sort);

int main(int argc, char** argv) {

    SortAlgorithm* my_sort = new SortAlgorithm();
    SqList* List = new SqList();
    List->length = 11;
    List->r = new int[List->length];

    cout << "Before sorting." << endl;
    for (int i = 0; i < List->length; ++i) {
        List->r[i] = List->length - i;
        cout << List->r[i] << " ";
    }
    cout << endl;

    cout << endl;
    // test bubble
    TestBubbleSort(List, my_sort);

    cout << endl;
    // test select sort
    TestSelectSort(List, my_sort);

    cout << endl;
    // test insert sort
    TestInsertSort(List, my_sort);

    cout << endl;
    // test shell sort
    TestShellSort(List, my_sort);

    cout << endl;
    // test Heap sort
    TestHeapSort(List, my_sort);

    cout << endl;
    // test Merge sort
    TestMergeSort(List, my_sort);

    cout << endl;
    // test Quick sort
    TestQuickSort(List, my_sort);

    delete my_sort;
    delete List;
    
    return 0;
}

void TestBubbleSort(SqList* List, SortAlgorithm* my_sort) {
    cout << "********************TestBubbleSort*************************" << endl;
    // 冒泡排序初级版本
    bool flag = my_sort->BubbleSort(List);
    if (flag) {
        cout << "After BubbleSort." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "BubbleSort failed." << endl;
    }

    // 随机改变位置
    flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }

    // 冒泡排序正宗版
    flag = my_sort->BubbleSortAuthentic(List);
    if (flag) {
        cout << "After BubbleSortAuthentic." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "BubbleSortAuthentic failed." << endl;
    }

    // 随机改变位置
    flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }

    // 冒泡排序牛逼版
    flag = my_sort->BubbleSortNiubility(List);
    if (flag) {
        cout << "After BubbleSortNiubility." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "BubbleSortNiubility failed." << endl;
    }

    cout << "*************************Finished**************************" << endl;
}

void TestSelectSort(SqList* List, SortAlgorithm* my_sort) {
    cout << "********************TestSelectSort*************************" << endl;
    // 随机改变位置
    bool flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }
    
    // 选择排序
    flag = my_sort->SelectSort(List);
    if (flag) {
        cout << "After SelectSort." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "SelectSort failed." << endl;
    }

    cout << "*************************Finished**************************" << endl;
}

void TestInsertSort(SqList* List, SortAlgorithm* my_sort) {
    cout << "********************TestInsertSort*************************" << endl;
    // 随机改变位置
    bool flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }
    
    // 选择排序
    flag = my_sort->InsertSort(List);
    if (flag) {
        cout << "After SelectSort." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "InsertSort failed." << endl;
    }

    cout << "*************************Finished**************************" << endl;
}

void TestShellSort(SqList* List, SortAlgorithm* my_sort) {
    cout << "********************TestShellSort*************************" << endl;
    // 随机改变位置
    bool flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }
    
    // 选择排序
    flag = my_sort->ShellSort(List);
    if (flag) {
        cout << "After ShellSort." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "ShellSort failed." << endl;
    }

    cout << "*************************Finished**************************" << endl;
}

void TestHeapSort(SqList* List, SortAlgorithm* my_sort) {
    cout << "********************TestHeapSort*************************" << endl;
    // 随机改变位置
    bool flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }
    
    // 选择排序
    flag = my_sort->HeapSort(List);
    if (flag) {
        cout << "After HeapSort." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "HeapSort failed." << endl;
    }

    cout << "*************************Finished**************************" << endl;
}

void TestMergeSort(SqList* List, SortAlgorithm* my_sort) {
    cout << "********************TestMergeSort*************************" << endl;
    // 随机改变位置
    bool flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }
    
    // 合并排序迭代法
    flag = my_sort->MergeSortRecursion(List);
    if (flag) {
        cout << "After MergeSortRecursion." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "MergeSortRecursion failed." << endl;
    }

    // 随机改变位置
    flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }
    
    // 合并排序迭代法
    flag = my_sort->MergeSortIteration(List);
    if (flag) {
        cout << "After MergeSortIteration." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "MergeSortIteration failed." << endl;
    }

    cout << "*************************Finished**************************" << endl;
}

void TestQuickSort(SqList* List, SortAlgorithm* my_sort) {
    cout << "********************TestQuickSort*************************" << endl;
    // 随机改变位置
    bool flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }
    
    // 合并排序迭代法
    flag = my_sort->QuickSort(List);
    if (flag) {
        cout << "After QuickSort." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "QuickSort failed." << endl;
    }

    // 随机改变位置
    flag = my_sort->ChangePosRandom(List);
    if (flag) {
        cout << "After random changing." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "random changing failed." << endl;
    }
    
    // 合并排序迭代法
    flag = my_sort->QuickSortOpt(List);
    if (flag) {
        cout << "After QuickSortOpt." << endl;
        for (int i = 0; i < List->length; ++i) {
            cout << List->r[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "QuickSortOpt failed." << endl;
    }

    cout << "*************************Finished**************************" << endl;
}
