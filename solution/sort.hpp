//===--------------------------- solution/sort.hpp - [tinyDTL] ------------------------------------------*- C++ -*-===//
// Brief :
//  Impl of all sorting algorithms
//  DTL目前还没有实现，所以使用的是STL里面的容器算法，后续完善
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(SORT_HPP)
#define SORT_HPP

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>

namespace dtl {
namespace solution {

//===--------------------------- [bubbleSort] -----------------------------===//
// [无序区，有序区]：从无序区通过交换找出最大元素放到有序区
// 1. 比较相邻的元素。如果第一个比第二个大，交换
// 2. 对后续元素重复1，一趟完成后，最大元素到了有序区末尾
// 3. 重新从头扫描，除了最后一个已经找出的最大元素
//===----------------------------------------------------------------------===//
template <typename T>
std::string bubbleSort(std::vector<T> &vec) {
  int  len = vec.size();
  bool sorted = false; // 在某一趟没有发生元素交换，则可判定序列已经有序

  for (int i = 0; i < len - 1 && !sorted; ++i) {
    sorted = true;
    for (int j = 0; j < len - 1 - i; ++j) {
      if (vec[j] > vec[j + 1]) {
        sorted = false;
        std::swap(vec[j], vec[j + 1]);
      }
    }
  }
  return __func__;
}

//===------------------------- [selectSort] -------------------------------===//
// [有序区，无序区]：在无序区里选择一个最小元素放到有序区后面
//===----------------------------------------------------------------------===//
template <typename T>
std::string selectSort(std::vector<T> &vec) {
  int len = vec.size();
  for (int i = 0; i < len - 1; ++i) {
    int minIdx = i;
    for (int j = i + 1; j < len; ++j) {
      if (vec[j] < vec[minIdx]) {
        minIdx = j;
      }
    }
    if (minIdx != i) {
      std::swap(vec[i], vec[minIdx]);
    }
  }
  return __func__;
}

//===------------------------- [insertSort] -------------------------------===//
// [有序区，无序区]：将无序区的第一个元素插入到有序区的合适位置
// 1. 第一个元素开始，该元素认为有序
// 2. 取出下一个元素，在有序序列中从后向前扫描
// 3. 如果该元素大于新元素，将该元素后移一位
// 4. 找到有序区中小于等于该元素的位置，插入新元素
// 5. 重复 2~4
//===----------------------------------------------------------------------===//
template <typename T>
std::string insertSort(std::vector<T> &vec) {
  int len = vec.size();
  for (int i = 1; i < len; ++i) {
    for (int j = i; j > 0; --j) {
      if (vec[j - 1] > vec[j]) {
        std::swap(vec[j - 1], vec[j]);
      } else {
        break;
      }
    }
  }
  return __func__;
}

//===------------------------- [quickSort] --------------------------------===//
// 1. 选取第一个数为基准
// 2. 将小于第一个数的元素交换到左边，大于第一个数的元素交换到右边
// 3. 对左右子区间重复以上操作
//===----------------------------------------------------------------------===//
template <typename T>
std::string quickSortRecursive(std::vector<T> &vec, int begin, int end) {
  if (begin >= end) {
    return std::string();
  }
  int left = begin;
  int right = end;
  T   key = vec[left];

  while (left < right) {
    while (left < right && vec[right] >= key) {
      right--;
    }
    if (left < right) {
      vec[left++] = vec[right];
    }
    while (left < right && vec[left] <= key) {
      left++;
    }
    if (left < right) {
      vec[right--] = vec[left];
    }
  }
  vec[left] = key;
  (void)quickSortRecursive(vec, begin, left - 1);
  (void)quickSortRecursive(vec, left + 1, end);
  return __func__;
}

template <typename T>
std::string quickSortIterative(std::vector<T> &vec) {
  std::stack<std::pair<int, int>> stk;
  stk.push(std::make_pair(0, vec.size() - 1));

  while (!stk.empty()) {
    auto range = stk.top(); // 此处不能用 auto& range 去接收，自己可以理解一下，top() 返回的是引用
    stk.pop();

    int left = range.first;
    int right = range.second;
    if (left >= right) {
      continue;
    }

    T key = vec[left];
    while (left < right) {
      while (left < right && vec[right] >= key) {
        right--;
      }
      if (left < right) {
        vec[left++] = vec[right];
      }
      while (left < right && vec[left] <= key) {
        left++;
      }
      if (left < right) {
        vec[right--] = vec[left];
      }
    }
    vec[left] = key;
    stk.push(std::make_pair(range.first, left - 1));
    stk.push(std::make_pair(left + 1, range.second));
  }
  return __func__;
}

//===------------------------- [heapSort] ---------------------------------===//
// [最大堆，有序区]：从堆顶把根卸出来放在有序区之前，再恢复堆。
//===----------------------------------------------------------------------===//
template <typename T>
void adjustHeap(std::vector<T> &vec, int begin, int len) {
  int parent = begin;
  int son = 2 * parent + 1;

  while (son < len) {
    if (son + 1 < len && vec[son + 1] > vec[son]) {
      son++;
    }
    if (vec[parent] > vec[son]) {
      break;
    } else {
      std::swap(vec[parent], vec[son]);
      parent = son;
      son = 2 * parent + 1;
    }
  }
}

template <typename T>
std::string heapSort(std::vector<T> &vec) {
  // 初始化堆
  for (int i = vec.size() / 2 - 1; i >= 0; --i) {
    adjustHeap(vec, i, vec.size());
  }

  // 交换元素，调整堆
  for (int i = vec.size() - 1; i > 0; --i) {
    std::swap(vec[0], vec[i]);
    adjustHeap(vec, 0, i);
  }
  return __func__;
}

void testSort() {
  fmtRun("Run Sort Test", Color::kBlue);

  srand((unsigned int)time(NULL));
  std::string      sortName;
  std::vector<int> vec;

  for (int i = 0; i < 20; ++i) {
    vec.push_back((rand() % (41)) - 10);
  }

  fmtOut("Unsorted elements:", Color::kGreen);
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;

  // sortName = bubbleSort(vec);
  // sortName = selectSort(vec);
  // sortName = insertSort(vec);

  // sortName = quickSortRecursive(vec, 0, vec.size() - 1);
  // sortName = quickSortIterative(vec);

  sortName = heapSort(vec);

  fmtOut("After [" + sortName + "]:", Color::kGreen);
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;
}

} // namespace solution
} // namespace dtl

#endif // SORT_HPP
