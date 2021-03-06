
### 排序算法

排序的依据是关键字之间的大小关系,那么,对于同一个记录集合,针对不同的关键字进行排序,可以得到不同序列.
    
多个关键字的排序最终可以转换为单个关键字的排序.
    
> 稳定排序: 排序前,x和y的索引是x在前y在后,在x==y的情况下,排序的结果,仍然需要x在前y在后.反之则是不稳定排序.

> 排序算法的性能主要受3个方面的影响:  
1. 时间性能: 高效率的内排序方法应该是具有尽可能少的关键字比较次数和尽可能少的记录移动次数；
2. 辅助空间: 执行算法所需要的辅助存储空间；
3. 算法的复杂性: 算法过于复杂也会影响排序的性能.

> 内排序分为: 插入排序, 交换排序, 选择排序和归并排序.


#### 冒泡排序

> 冒泡排序是一种交换排序，它的基本思想是：两两比较相邻记录的关键字，如果反序则交换，知道没有反序的记录为止．

> 冒泡排序复杂度分析：
1. 最好的情况是排序的表本身就是有序的，那么我们比较次数只需n-1次，没有数据交换，时间复杂度是O(n)；
2. 最坏的情况是待排序表是逆序的情况，此时需要比较 $\sum_{i=2}^{n}(i-1) = 1 + 2 + 3 + \dots + (n - 1) = \frac{n(n-1)}{2}$　次．并作同等量级的记录移动．因此总的时间复杂度为$O(n^2)$.


#### 简单选择排序

> 简单选择排序法就是通过n-i次关键字间的比较，从n-i+１个记录中选出关键字最小的记录，并和第i个记录交换之．

> 特点：交换移动数据次数相当少．

> 复杂度分析：简单选择排序无论最好还是最坏情况，其比较次数都是一样多的，第$i$趟排序需要进行n-i次关键字的比较，此时需要比较　$\sum_{i=2}^{n}(n-1) = (n - 1) + \dots + 3 + 2 + 1 = \frac{n(n-1)}{2}$　次.　而在数据交换上，最好的时候是０次，最坏的时候是n-1次．最终的时间复杂度为$O(n^2)$.


#### 直接插入排序

> 直接插入排序的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的，记录数增１的有序表．

> 大体思路：给定一个数组，从数组第一个数开始，与第二个数进行比较，若第二个数比较小，则将第一个数右移，第二个数拷贝到第一个数的位置里面．以此类推．
    公式描述: $arr = [6, 5, 2, 1, 4]$，假设第 $k$ 数比第 $k-1$ 个数要小，即 $arr[k] < arr[k-1]$，则备份第 $k$ 个数$arr[k]$，同时将前面比 $arr[k]$ 小的数 $arr[k-1],arr[k-2], ...$ 全部右移．最后再在前面插入 $arr[k]$．

> 时间复杂度分析：
1. 最好的情况：待排序的表本身就是有序的，因此只需比较前后两个数值的大小，总共比较 
        $(n-1)\sum_{i=2}^{n}1 = n -1$次，并且不需要移动，时间复杂度为 $O(n)$．
2. 最坏的情况：待排序表是逆序的情况，此时需要比较 $\sum_{i=2}^{n}i = 2 + 3 + \ldots + n = \frac{(n-2)(n-1)}{2}$次，而记录移动的次数也达到了最大值 $\sum_{i=2}^{n}(i+1) = \frac{(n+4)(n-1)}{2}$ 次．
3.  平均的情况：按照上述的分析，算其平均值，得到平均比较和移动次数均为 $\frac{n^{2}}{4}$
次．因此直接插入排序法的时间复杂度为 $O(n^2)$．

> 结论：同样的$O(n^2)$复杂度，直接插入排序法比冒泡和简单选择排序的性能要好一点．


#### 希尔排序

> 采用跳跃分割的策略：将相距某个＂增量＂的记录组合成一个子序列，这样才能保证在子序列内分别进行直接插入排序后得到的结果是基本有序而不是局部有序的．

> 由于记录是跳跃式的移动，因此希尔排序并不是一种稳定的排序方法．

> 希尔排序的时间复杂度是 $O(n^{3/2})$, 要好于直接排序的 $O(n^2)$．


#### 堆排序

> 堆是具有下列性质的完全二叉树：每个节点的值都大于或等于其左右孩子节点的值，称为大顶堆；或每个节点的值都小于或等于其左右孩子节点的值，称为小顶堆。

> 如果按照层序遍历的方式给节点从１开始编号，则节点之间满足如下关系：
    $$\forall 1 \leq i \leq [\frac{n}{2}]$$　满足
    $$k_{i} \geq k_{2i}, k_{i} \geq k_{2i+1} $$　或
    $$k_{i} \leq k_{2i}, k_{i} \leq k_{2i+1} $$
    上述中 $\frac{n}{2}$ 表示的意思是，对于根节点而言，其不包含双亲；而对于$i > 1$,其对半的节点表示其双亲。
    而下标 $i$ 中的双亲子女关系就是对下标 $2i, 2i+1$。

> 堆排序：利用堆（假设利用大顶堆）进行排序的方法。它的基本思想是，将待排序的序列构造成一个大顶堆。此时，整个序列的最大值就是堆顶的根节点。将它移走（其实就是将其与堆数组的末尾元素交换，此时末尾元素就是最大值），然后将剩余的n-1个系列重新构成一个堆，这样就会得到n个元素中的次小值。如此反复执行，便能得到一个有序序列了。

> 堆排序的时间复杂度分析：
1. 堆排序的运行时间主要小号在初始构建堆和重建堆时的反复筛选上。
2. 在构建堆的过程，因为我们是完全二叉树从最下层最右边的非终端节点开始构建，将它和其孩子进行比较和若有必要的互换，对于每个非终端节点来说，其实最多进行两次比较和互换操作，因此整个构建堆的时间复杂度为 $O(n)$。
3. 在正式排序时，第$i$次取堆顶记录重建堆需要用 $O(logi)$ 的时间（完全二叉树的某个节点到根节点的距离为$([log_{2}i] + 1)$，并且需要取 $n-1$ 次堆顶记录，因此，重建堆的时间复杂度为 $O(nlogn)$。
4. 由于堆排序对原始记录的排序状态并不敏感，因此它无论是最好、最坏和平均时间复杂度均为 $O(nlogn)$。这在性能上显然要远远好过冒泡、简单选择、直接插入的 $O(n^2)$　的时间复杂度。
5. 另外，由于初始构建堆所需的比较次数较多，因此，它并不适合待排序序列个数较少的情况。


#### 归并排序

> 归并排序就是利用归并的思想实现的排序方法．它的原理是假设初始序列含有n个记录，则可以看成是n个有序的子序列，每个子序列的长度为１，然后两两归并，得到[n/2]（[x]表示不小于x的最小整数）个长度为２或１的有序子序列；再两两归并，．．．，如此重复，直到得到一个长度为n的有序序列为止，这种排序方法称为２路归并排序．

递归法：
> 归并排序时间复杂度分析：
1. 一趟归并需要将SR[1],...,SR[n]中相邻的长度为h的有序序列进行两两归并，并将结果放到TR[1]~TR[n]中，这需要将待排序序列中的所有记录扫描一遍，因此耗费O(n)时间．而由完全二叉树的深度可知，整个归并排序需要执行$[log_{2}n]$次，因此总的时间复杂度为O(nlogn)，而且这是归并排序算法中最好，最坏，平均的时间性能．
2. 归并排序在归并过程中需要与原始记录序列同样数量的存储空间存放归并结果以及递归深度为$log_{2}n$的栈空间，因此空间复杂度为$O(n+logn)$.
3. 由于归并排序需要两两比较，不存在跳跃，因此是一种稳定的排序方法．
4. 总之，归并排序是一种比较占用内存，但却效率高而且稳定的算法．

迭代法：
>　归并排序时间复杂度分析：
1. 避免了递归时深度为$log_{2}n$的栈空间，空间只是用到申请归并临时用的TR数组，因此空间复杂度为$O(n)$,并且避免递归也在时间性能上有一定的提升．
2. 使用归并排序时，尽量考虑使用非递归的方法．


#### 快速排序

> 快速排序的基本思想是：通过一趟排序将待排记录分割成独立的两部分，其中一部分记录的关键字均比另一部分记录的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序的目的．

> 快速排序中，关键字的比较和交换是跳跃进行的，因此，快速排序是一种不稳定的排序方法．

> 时间复杂度分析：
1. 最优情况：时间复杂度为$O(nlogn)$，此时每次取得的轴心使得划分都是非常均匀的，因此每次都能顺利折半．
2. 最坏情况：时间复杂度为$O(n^2)$，此时完全顺序或逆序，需要逐一比较．

> 改进方向：修改上述轴心选取方式，利用三数取中法．即取三个关键字先进行排序，将中间数作为枢轴，一般是取左端，右端和中间三个数．