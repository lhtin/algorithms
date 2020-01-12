/**
 * Sorting Algorithm
 * by 01nomagic at 20200111
 */
#include <iostream>
#include <string>
#include <utility>
using namespace std;

void printArr (const int arr[], int len) {
  cout << "[";
  for (int i = 0; i < len; i += 1) {
    if (i > 0) {
      cout << ", ";
    }
    cout << arr[i];
  }
  cout << "]";
}
void printSortName (const string& funcName) {
  cout << " >>" << funcName << ">> ";
}
typedef void (*Sort) (int arr[], int len);
void run (Sort sort) {
  int arr[8] = {6, 5, 3, 1, 8, 7, 2, 4};
  printArr(arr, 8);
  sort(arr, 8);
  printArr(arr, 8);
  cout << endl;
}

/** Simple Sorts **/

// https://en.wikipedia.org/wiki/Insertion_sort
// 插入排序，稳定排序，时间复杂度：最坏n*(n-1)，最好n，不过交换的次数过多
// 算法描述：依次将待排序列表的第一个元素归入到已排序列表的最后一个元素，然后从已排序列表的最后一个元素开始，比较其跟前一个元素的大小，小于则交换位置，然后继续跟跟前面的元素比较，直到到达了最前面或者大于等于前面的元素。
void InsertionSort (int arr[], int len) {
  printSortName(__func__);
  for (int i = 0; i < len; i += 1) {
    for (int j = i; j > 0; j -= 1) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      } else {
        break;
      }
    }
  }
}

// https://en.wikipedia.org/wiki/Selection_sort
// 选择排序，稳定排序，时间复杂度：最坏和最好都是n*(n-1)，交换的次数最少，但是比较的次数最多
// 算法描述：依次从待排序列表中找出最小值，然后跟待排序列表的第一个元素交换，交换完之后将第一个元素归入已排序列表，直到待排序列表为空。
void SelectionSort (int arr[], int len) {
  printSortName(__func__);
  for (int i = 0; i < len; i += 1) {
    int min = arr[i];
    int minAt = i;
    // 遍历后面的元素，找出比第一个元素小的元素
    for (int j = i + 1; j < len; j += 1) {
      if (arr[j] < min) {
        min = arr[j];
        minAt = j;
      }
    }

    if (i != minAt) {
      // 找到了就交换
      swap(arr[minAt], arr[i]);
    }
  }
}

// https://en.wikipedia.org/wiki/Merge_sort
// 归并排序，稳定排序，时间复杂度稳定在nlogn，空间复杂度n
// 算法描述：
//   1. 将两个已排序列表合并成一个。从两个列表的第一个元素开始比较，如果第一个列表的元素小于等于第二个列表的元素，则将第一个列表的元素添加到结果列表的后面，否则将第二个列表的元素添加到结果列表的后面。直到一个列表的所有元素都添加到了结果列表后，将另一个列表的剩余元素依次添加到结果列表的后面
//   2. 递归的将待排序列表分割成两个待排序列表，然后分别对这两个待排序列表递归排序。如果待排序列表只有一个元素，则认为已经排好序。
void _MergeSort (int arr[], int temp[], int start, int end) {
  if (start == end) {
    // 只有一个元素时直接返回
    return;
  }
  int start1 = start;
  int start2 = start + (end - start + 1) / 2;
  int end1 = start2 - 1;
  int end2 = end;

  // 递归归并排序
  _MergeSort(arr, temp, start1, end1);
  _MergeSort(arr, temp, start2, end2);

  int at = start1;
  int at1 = start1;
  int at2 = start2;
  while (true) {
    if (arr[at1] <= arr[at2]) {
      temp[at] = arr[at1];
      at += 1;
      if (at1 == end1) {
        for (int i = at2; i <= end2; i += 1) {
          temp[at] = arr[i];
          at += 1;
        }
        break;
      } else {
        at1 += 1;
      }
    } else {
      temp[at] = arr[at2];
      at += 1;
      if (at2 == end2) {
        for (int i = at1; i <= end1; i += 1) {
          temp[at] = arr[i];
          at += 1;
        }
        break;
      } else {
        at2 += 1;
      }
    }
  }
  for (int i = start; i <= end; i += 1) {
    arr[i] = temp[i];
  }
}
void MergeSort (int arr[], int len) {
  printSortName(__func__);
  int temp[len];
  _MergeSort(arr, temp, 0, len - 1);
}

// https://en.wikipedia.org/wiki/Heapsort
// https://en.wikipedia.org/wiki/Heap_(data_structure)
// 堆数据结构：最大二叉堆(max binary heap)指父节点大于子节点的二叉树结构
// 堆排序算法：
//   1. 构造一个最大堆
//   2. 将根节点与最后的子节点交换然后移除最后的子节点，并让剩余堆维持成一个最大堆，直到剩余堆为空，则移除的所有子节点从小到达排好了顺序
void _ToMaxHeap (int *arr, int len) {
  for (int i = 0; i < len; i += 1) {
    int child = i;
    while (child > 0) {
      int parent = (int)((child - 1) / 2);
      if (arr[parent] < arr[child]) {
        swap(arr[child], arr[parent]);
        child = parent;
      } else {
        break;
      }
    }
  }
}
void HeapSort (int arr[], int len) {
  printSortName(__func__);
  _ToMaxHeap(arr, len);
  // 依次将最大值与堆的最右子节点交换
  for (int i = len - 1; i >= 0; i -= 1) {
    swap(arr[i], arr[0]);
    _ToMaxHeap(arr, i);
  }
}

// https://en.wikipedia.org/wiki/Quicksort
// 快速排序，不稳定，平均nlogn，最坏n*n
int partition (int arr[], int start, int end) {
  int i = start, j = end;
  int mid = (int)(start + (end - start) / 2);
  int pivot = arr[mid];
  while (true) {
    while (arr[i] < pivot) {
      i += 1;
    }
    while (arr[j] > pivot) {
      j -= 1;
    }
    if (i >= j) {
      return j;
    } else {
      swap(arr[i], arr[j]);
    }
  }
}
void _QuickSort (int arr[], int start, int end) {
  if (start >= end) {
    return;
  }
  int p = partition(arr, start, end);
  _QuickSort(arr, start, p - 1);
  _QuickSort(arr, p + 1, end);
}
void QuickSort (int arr[], int len) {
  printSortName(__func__);
  _QuickSort(arr, 0, len - 1);
}

// https://en.wikipedia.org/wiki/Shellsort
// 希尔排序：插入排序的改进版，不稳定排序，平均nlogn，最坏n*n
void _InsertionSortWithGap (int arr[], int len, int gap, int start) {
  // InsertionSort的变体，增加gap和start参数，用于指定具体给哪些元素排序
  for (int i = start; i < len; i += gap) {
    for (int j = i; j > start; j -= gap) {
      if (arr[j] < arr[j - gap]) {
        swap(arr[j], arr[j - gap]);
      } else {
        break;
      }
    }
  }
}
void ShellSort (int arr[], int len) {
  printSortName(__func__);
  for (int gap = len / 2; gap >= 1; gap /= 2) {
    for (int i = 0; i < gap; i += 1) {
      _InsertionSortWithGap(arr, len, gap, i);
    }
  }
}

int main () {

  run(InsertionSort);
  run(SelectionSort);
  run(MergeSort);
  run(HeapSort);
  run(QuickSort);
  run(ShellSort);

  return 0;
}




