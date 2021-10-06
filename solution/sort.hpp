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
#include <map>
#include <cmath>

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

//===------------------------- [mergeSort] --------------------------------===//
// 把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行
//===----------------------------------------------------------------------===//
template <typename T>
std::string mergeSortRecursive(std::vector<T> &vec, int begin, int end) {
  if (begin >= end) {
    return std::string();
  }
  int mid = begin + ((end - begin) >> 1);
  mergeSortRecursive(vec, begin, mid);
  mergeSortRecursive(vec, mid + 1, end);

  int i = begin;
  int j = mid + 1;
  int k = 0;

  std::vector<T> tmp(end - begin + 1);
  while (i <= mid && j <= end) {
    tmp[k++] = vec[i] < vec[j] ? vec[i++] : vec[j++];
  }
  while (i <= mid) {
    tmp[k++] = vec[i++];
  }
  while (j <= end) {
    tmp[k++] = vec[j++];
  }
  for (i = begin, k = 0; i <= end; ++i, ++k) {
    vec[i] = tmp[k];
  }
  return __func__;
}

template <typename T>
std::string mergeSortIterative(std::vector<T> &vec) {
  int len = vec.size();
  // width: 每次排序序列的长度，每次排序两个width长度的序列，然后将其合并
  for (int width = 1; width < len; width *= 2) {
    for (int i = 0; i < len; i += 2 * width) {
      int begin1st = i;
      int end1st = std::min(begin1st + width - 1, len - 1);
      int begin2nd = end1st + 1;
      int end2nd = std::min(begin1st + 2 * width - 1, len - 1);

      std::vector<T> tmp(end2nd - begin1st + 1);
      int            k = 0;
      while (begin1st <= end1st && begin2nd <= end2nd) {
        tmp[k++] = vec[begin1st] < vec[begin2nd] ? vec[begin1st++] : vec[begin2nd++];
      }
      while (begin1st <= end1st) {
        tmp[k++] = vec[begin1st++];
      }
      while (begin2nd <= end2nd) {
        tmp[k++] = vec[begin2nd++];
      }

      for (k = 0; k < tmp.size(); ++k) {
        vec[k + i] = tmp[k];
      }
    }
  }
  return __func__;
}

//===------------------------- [shellSort] --------------------------------===//
// 1. 希尔排序是将待排序的数组元素 按下标的一定增量分组 ，分成多个子序列
// 2. 然后对各个子序列进行直接插入排序算法排序
// 3. 然后依次缩减增量再进行排序，直到增量为1时，进行最后一次直接插入排序
//===----------------------------------------------------------------------===//
template <typename T>
std::string shellSort(std::vector<T> &vec) {
  int len = vec.size();
  int gap = 1;
  while (gap < len / 3) {
    gap = gap * 3 + 1;
  }

  while (gap >= 1) {
    for (int i = gap; i < len; ++i) {
      for (int j = i; j - gap >= 0; j -= gap) {
        if (vec[j - gap] > vec[j]) {
          std::swap(vec[j - gap], vec[j]);
        } else {
          break;
        }
      }
    }
    gap /= 3;
  }
  return __func__;
}

//===------------------------- [countSort] --------------------------------===//
// 1. 找出待排序的数组中最大和最小的元素
// 2. 统计数组中每个值为 i 的元素出现的次数，存入数组 C 的第 i 项
// 3. 对所有的计数累加（从 C 中的第一个元素开始，每一项和前一项相加）
// 4. 反向填充目标数组：将每个元素 i 放在新数组的第 C[i] 项，每放一个元素就将 C[i] 减去 1
//===----------------------------------------------------------------------===//
template <typename T>
std::string countSort(std::vector<T> &vec) {
  T min = *std::min_element(vec.begin(), vec.end());
  T max = *std::max_element(vec.begin(), vec.end());

  std::map<T, int> hashMap; // val -> count
  for (auto val : vec) {
    hashMap[val]++;
  }

  int k = 0;
  for (auto &[val, cnt] : hashMap) {
    while (cnt--) {
      vec[k++] = val;
    }
  }
  return __func__;
}

//===------------------------- [bucketSort] -------------------------------===//
// 1. 设置一个定量的数组当作空桶子。
// 2. 寻访序列，并且把项目一个一个放到对应的桶子去。
// 3. 对每个不是空的桶子进行排序。
// 4. 从不是空的桶子里把项目再放回原来的序列中。
//===----------------------------------------------------------------------===//
template <typename T>
std::string bucketSort(std::vector<T> &vec) {
  T min = *std::min_element(vec.begin(), vec.end());
  T max = *std::max_element(vec.begin(), vec.end());

  std::vector<std::vector<T>> buckets((max - min) / vec.size() + 1);

  for (auto &val : vec) {
    int num = (val - min) / vec.size();
    buckets[num].push_back(val);
  }

  auto &&iter = vec.begin();
  for (auto &bucket : buckets) {
    std::sort(bucket.begin(), bucket.end());
    std::copy(bucket.begin(), bucket.end(), iter);
    std::advance(iter, bucket.size());
  }
  return __func__;
}

//===------------------------- [radixSort] --------------------------------===//
// 一种多关键字的排序算法，可用桶排序实现。
//===----------------------------------------------------------------------===//
template <typename T>
std::string radixSort(std::vector<T> &vec) {
  T   max = *std::max_element(vec.begin(), vec.end());
  int maxLen = std::to_string(max).size();

  std::vector<std::vector<T>> buckets(10);

  for (int i = 0; i < maxLen; ++i) {
    for (auto &val : vec) {
      // 只能排序非负数
      int num = static_cast<int>(val / std::pow(10, i)) % 10;
      buckets[num].push_back(val);
    }

    auto &&iter = vec.begin();
    for (auto &bucket : buckets) {
      std::copy(bucket.begin(), bucket.end(), iter);
      std::advance(iter, bucket.size());
      bucket.clear(); // 每次需清空桶内元素
    }
  }
  return __func__;
}

void testSort() {
  fmtRun("Run Sort Test", Color::kBlue);

  srand((unsigned int)time(NULL));
  std::string      sortName;
  std::vector<int> vec;

  for (int i = 0; i < 20; ++i) {
    vec.push_back(rand() % (501));
  }

  fmtOut("Unsorted elements:", Color::kGreen);
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;

  // sortName = bubbleSort(vec);
  // sortName = selectSort(vec);
  // sortName = insertSort(vec);

  // sortName = quickSortRecursive(vec, 0, vec.size() - 1);
  // sortName = quickSortIterative(vec);

  // sortName = heapSort(vec);

  // sortName = mergeSortRecursive(vec, 0, vec.size() - 1);
  // sortName = mergeSortIterative(vec);

  // sortName = shellSort(vec);

  // sortName = countSort(vec);
  // sortName = bucketSort(vec);
  sortName = radixSort(vec);

  fmtOut("After [" + sortName + "]:", Color::kGreen);
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;
}

} // namespace solution
} // namespace dtl

#endif // SORT_HPP
