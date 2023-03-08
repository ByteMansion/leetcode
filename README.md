[Solutions to Leetcode Problems](#solutions-to-leetcode-problems)

[Prerequisite](#prerequisite)

[Knowledge Base](#knowledge-base)

[Compilation](#compilation)

[Quick Access](#quick-access)


# Solutions to Leetcode Problems
This repo is aimed at documenting solutions to Leetcode problems or online judge problems in interview.
Another repo also includes hundreds of solutions, but it is a large projects and not
convenient to find a specific solution.

## Prerequisite
This project provides an easy way to compile all source files: `CMake`. After compilation, a new folder `bin` is created and all executables are saved under this folder.

Therefore, the prerequisite of this repo is: compilation is dependant on [CMake](https://cmake.org/).

Of course, this prerequisite is recommended, instead of necessary. [Compilation](#compilation) will give another trivial way to compile a source file.

## Knowledge Base
This part provides some brief introductions to typical data structures and classical algorithms.

1. [Dynamic Programming](./knowledge/Dynamic_Programming.md)
2. 树状数组（ToDo）


## Compilation
### Compile All

Execute `build.sh` script:

```bash
$ ./build.sh
```
### Compile One

If `CMake` isn't installed, you must compile the source code one by one using `g++`. Standard `C++17` is recommended. For example:

```bash
$ g++ -std=c++17 array/leetcode53.cpp -o leetcode53
```

## Quick Access
|No.|Leetcode Problems|Solutions|Related Knowledge|
|-|-|-|-|
|*|[Offer 45 把数组排成最小的数](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/)|[solution](./string/offer45.cpp)||
|*|[Offer 51 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)|[solution](./array/offer51.cpp)|merge sort|
|*|[Mianshi 17 Smallest K LCCI](https://leetcode-cn.com/problems/smallest-k-lcci/)|[solution](./array/sort/mianshi17.cpp)|quick sort|
|*|HUAWEI 机试 随机数去重和排序|[solution](./interview/huawei1.cpp)||
|*|HUAWEI 机试 十六进制转换为十进制|[solution](./interview/huawei2.cpp)||
|*|HUAWEI 机试 饮料瓶|[solution](./interview/huawei4.cpp)||
|*|HUAWEI 机试 最少交换次数|[solution](./interview/huawei3.cpp)||
|*|HUAWEI 机试 免单统计|[solution](./interview/huawei5.cpp)||
|*|HUAWEI 机试 字符串分隔|[solution](./interview/huawei6.cpp)||
|*|HUAWEI 机试 句子逆序|[solution](./interview/huawei7.cpp)||
|*|HUAWEI 机试 最大时间|[solution](./interview/huawei8.cpp)||
|*|eBay 机试 Zigzag Sort & Type ID|[solution](./interview/eBay.cpp)||
|*|商汤科技 机试 两个链表的第一个公共节点|[solution](./interview/sensetime.cpp)||
|2|[Leetcode 2 Add Two Numbers](https://leetcode-cn.com/problems/add-two-numbers/)|[solution](./linkedlist/leetcode2.cpp)|reverse linked list|
|3|[Leetcode 3 Longest Substring Without Repeating Characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)|[solution](./string/leetcode3.cpp)|sliding window|
|4|[Leetcode 4 Median of Two Sorted Arrays](https://leetcode.cn/problems/median-of-two-sorted-arrays/)|[solution](array/leetcode4.cpp)|binary search|
|5|[Leetcode 5 Longest Palindrom Substring](https://leetcode-cn.com/problems/longest-palindromic-substring/)|[solution](./string/leetcode5.cpp)|dynamic programming|
|8|[Leetcode 8 Atoi](https://leetcode-cn.com/problems/string-to-integer-atoi/)|[solution](./string/leetcode8.cpp)|DFA, Deterministic Finite Automation|
|14|[Leetcode 14 Longest Common Prefix](https://leetcode-cn.com/problems/longest-common-prefix/)|[solution](./string/leetcode14.cpp)||
|21|[Leetcode 21 Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)|[solution](linkedlist/leetcode21.cpp)|linked list|
|28|[Leetcode 28 Find the Index of the First Occurrence in a String](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)|[solution](string/leetcode28.cpp)|KMP|
|31|[Leetcode 31 Next Permutation](https://leetcode.com/problems/next-permutation/)|[solution](./array/permutation/leetcode31.cpp)||
|33|[Leetcode 33 Search in Rotated Sorted Array](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)|[solution](array/leetcode33.cpp)|binary search|
|34|[Leetcode 34 Find First and Last Position of Element in Sorted Array](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)|[solution](array/leetcode34.cpp)|binary search|
|46|[Leetcode 46 Permutations](https://leetcode.com/problems/permutations/)|[solution](./array/permutation/leetcode46.cpp)||
|47|[Leetcode 47 Permutations II](https://leetcode.com/problems/permutations-ii/)|[solution](./array/permutation/leetcode47.cpp)||
|53|[Leetcode 53 Maximum Subarray](https://leetcode-cn.com/problems/maximum-subarray/)|[solution](./array/leetcode53.cpp)|dynamic programming|
|64|[Leetcode 64 Minimum Path Sum](https://leetcode-cn.com/problems/minimum-path-sum/)|[solution](./array/leetcode64.cpp)|dynamic programming|
|65|[Leetcode 65 Valid Number](https://leetcode-cn.com/problems/valid-number/)|[solution](./string/leetcode65.cpp)|DFA, Deterministic Finite Automation|
|70|[Leetcode 70 Climbing Stirs](https://leetcode.com/problems/climbing-stairs/)|[solution](./number/leetcode70.cpp)|dynamic programming|
|76|[Leetcode 76 Minimum Window Substring](https://leetcode-cn.com/problems/minimum-window-substring/)|[solution](./string/leetcode76.cpp)||
|79|[Leetcode 79 Word Search](https://leetcode-cn.com/problems/word-search/)|[solution](./array/leetcode79.cpp)||
|81|[Leetcode 81 Search in Rotated Sorted Array II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)|[solution](array/leetcode81.cpp)|binary search|
|92|[Leetcode 92 Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)|[solution](./linkedlist/leetcode92.cpp)||
|94|[Leetcode 94 Binary Tree Inorder Traversal](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)|[solution](./tree/leetcode94.cpp)|**inorder traversal**|
|95|[Leetcode 95 Unique Binary Search Trees II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)|[solution](./tree/leetcode95.cpp)|recursive method|
|96|[Leetcode 96 Unique Binary Search Trees](https://leetcode-cn.com/problems/unique-binary-search-trees/)|[solution](./tree/leetcode96.cpp)|dynamic programming|
|98|[Leetcode 98 Validate Binary Search Tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)|[solution](./tree/leetcode98.cpp)|inorder traversal|
|112|[Leetcode 112 Path Sum](https://leetcode-cn.com/problems/path-sum/)|[solution](./tree/leetcode112.cpp)|postorder traversal|
|120|[Leetcode 120 Triangle](https://leetcode-cn.com/problems/triangle/)|[solution](./array/leetcode120.cpp)|dynamic programming|
|121|[Leetcode 121 Best Time to Buy and Sell Stock](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)|[solution](./array/leetcode121.cpp)||
|122|[Leetcode 122 Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)|[solution](./array/leetcode122.cpp)|greedy method|
|135|[Leetcode 135 Candy](https://leetcode-cn.com/problems/candy/)|[solution](./array/leetcode135.cpp)|greedy algorithm|
|142|[Leetcode 142 Linked List Cycle II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)|[solution](linkedlist/leetcode142.cpp)|two pointers|
|144|[Leetcode 144 Binary Tree Preorder Traversal](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)|[solution](./tree/leetcode144.cpp)|**preorder traversal**|
|145|[Leetcode 145 Binary Tree Postorder Traversal](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)|[solution](./tree/leetcode145.cpp)|**postorder traversal**|
|147|[Leetcode 147 Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/)|[solution](linkedlist/leetcode147.cpp)|insertion sort of linked list|
|148|[Leetcode 148 Sort List](https://leetcode-cn.com/problems/sort-list/)|[solution](./linkedlist/leetcode148.cpp)|merge sort of linked list|
|153|[Leetcode 153 Find Minimum in Rotated Sorted Array](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)|[solution](array/leetcode153.cpp)|binary search|
|154|[Leetcode 154 Find Minimum in Rotated Sorted Array](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)|[solution](./array/leetcode154.cpp)|binary search|
|167|[Leetcode 167 Two Sum II](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)|[solution](array/leetcode167.cpp)|two pointers|
|206|[Leetcode 206 Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)|[solution](./linkedlist/leetcode206.cpp)||
|209|[Leetcode 209 Minimum Size Subarray Sum](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)|[solution](./array/leetcode209.cpp)|sliding window|
|214|[Leetcode 214 Shortest Palindrome](https://leetcode.cn/problems/shortest-palindrome/)|[solution](./string/leetcode214.cpp)|KMP, Manacher|
|215|[Leetcode 215 Kth Largest Element in An Array](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)|[solution](./array/sort/leetcode215.cpp)|heap sort/quick sort|
|235|[Leetcode 235 Lowest Common Ancestor of a Binary Search Tree](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)|[solution](./tree/leetcode235.cpp)|recursive method|
|315|[Leetcode 315 Count of Smaller Numbers After Self](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)|[solution](./array/leetcode315.cpp)|merge sort|
|322|[Leetcode 322 Coin Change](https://leetcode-cn.com/problems/coin-change/)|[solution](./array/leetcode322.cpp)|dynamic progreamming|
|347|[Leetcode 347 Top K Frequent Elements](https://leetcode-cn.com/problems/top-k-frequent-elements/)|[solution](./array/leetcode347.cpp)|quick sort/heap sort|
|350|[Leetcode 350 Intersection of Two Arrays II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)|[solution](./array/leetcode350.cpp)||
|392|[Leetcode 392 Is Subsequence](https://leetcode.com/problems/is-subsequence/)|[solution](./string/leetcode392.cpp)||
|406|[Leetcode 406  Queue Reconstruction by Height](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)|[solution](./array/leetcode406.cpp)||
|409|[Leetcode 409 Longest Palindrom](https://leetcode-cn.com/problems/longest-palindrome/)|[solution](./string/leetcode409.cpp)||
|435|[Leetcode 435 Non-overlapping Intervals](https://leetcode-cn.com/problems/non-overlapping-intervals/)|[solution](./array/leetcode435.cpp)|greedy algorithm|
|445|[Leetcode 445 Add Two Numbers II](https://leetcode-cn.com/problems/add-two-numbers-ii/)|[solution](./linkedlist/leetcode445.cpp)||
|452|[Leetcode 452 Minimum Number of Arrows to Burst Balloons](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/)|[solution](./array/leetcode452.cpp)|greedy algorithm|
|455|[Leetcode 455 Assign Cookies](https://leetcode-cn.com/problems/assign-cookies/)|[solution](./array/leetcode455.cpp)|greedy algorithm|
|523|[Leetcode 523 Continuous Subarray Sum](https://leetcode.cn/problems/continuous-subarray-sum/)|[solution](array/leetcode523.cpp)||
|524|[Leetcode 524 Longest Word in Dictionary through Deleting](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)|[solution](string/leetcode524.cpp)||
|538|[Leetcode 538 Convert BST to Greater Tree](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)|[solution](./tree/leetcode538.cpp)||
|540|[Leetcode 540 Single Element in a Sorted Array](https://leetcode-cn.com/problems/single-element-in-a-sorted-array/)|[solution](array/leetcode540.cpp)|binary search|
|572|[Leetcode 572 Subtree of Another Tree](https://leetcode-cn.com/problems/subtree-of-another-tree/)|[solution](./tree/leetcode572.cpp)||
|605|[Leetcode 605 Can Place Flowers](https://leetcode-cn.com/problems/can-place-flowers/)|[solution](./array/leetcode605.cpp)|greedy method|
|633|[Leetcode 633 Sum of Square Numbers](https://leetcode-cn.com/problems/sum-of-square-numbers/)|[solution](number/leetcode633.cpp)|two pointers|
|665|[Leetcode 665 Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/)|[solution](array/leetcode665.cpp)|greedy method|
|680|[Leetcode 680 Valid Palindrome II](https://leetcode-cn.com/problems/valid-palindrome-ii/)|[solution](string/leetcode680.cpp)|two pointers|
|718|[Leetcode 718 Maximum Length of Repeated Subarray](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)|[solution](./array/leetcode718.cpp)|dynamic programming|
|746|[Leetcode 746 Min Cost Climbing Stirs](https://leetcode.com/problems/min-cost-climbing-stairs/)|[solution](./array/leetcode746.cpp)|dynamic programming|
|756|[Leetcode 756 Pyramid Transition Matrix](https://leetcode-cn.com/problems/pyramid-transition-matrix/)|[solution](string/leetcode756.cpp)||
|763|[Leetcode 763 Pertition Labels](https://leetcode-cn.com/problems/partition-labels/)|[solution](./string/leetcode763.cpp)|greedy algorithm|
|792|[Leetcode 792 Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/)|[solution](./string/leetcode792.cpp)||
|875|[Leetcode 875 Koko Eating Bananas](https://leetcode-cn.com/problems/koko-eating-bananas/)|[solution](./array/leetcode875.cpp)|binary search|
|992|[Leetcode 992 Subarrays with K Different Integers](https://leetcode-cn.com/problems/subarrays-with-k-different-integers/)|[solution](./array/leetcode992.cpp)|sliding window|
|996|[Leetcode 996 Number of Squareful Arrays](https://leetcode.com/problems/number-of-squareful-arrays/)|[solution](./array/permutation/leetcode996.cpp)||

