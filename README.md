# build-collection
# 集合库 (C语言实现)
本项目是一个基于C语言实现的集合数据结构库，提供了常用的集合类数据结构，如哈希表、堆、列表、队列、栈、树等。
## 目录结构
```
include/                       # 头文件目录
│
├── hashtable/                  # 哈希表相关实现
│   ├── compare-int.h           # 整型比较函数
│   ├── compare-pointer.h       # 指针比较函数
│   ├── compare-string.h        # 字符串比较函数
│   ├── hash-double.h           # double类型的哈希函数
│   ├── hash-int.h              # 整型的哈希函数
│   ├── hash-pointer.h          # 指针的哈希函数
│   ├── hash-string.h           # 字符串的哈希函数
│   ├── hash_set.h              # 哈希集合实现
│   ├── hash_table.h            # 哈希表实现
│   ├── hash_table_m.h          # 模板哈希表实现
│   └── sha256.h                # SHA256哈希函数
│
├── heap/                       # 堆相关实现
│   └── binary_heap.h           # 二叉堆实现
│
├── list/                       # 列表相关实现
│   ├── array_list.h            # 动态数组列表实现
│   ├── array_list_m.h          # 动态数组列表模板实现
│   ├── linked_list.h           # 链表实现
│   └── linked_list_m.h         # 链表模板实现
│
├── queue/                      # 队列相关实现
│   ├── dqueue_ll.h             # 双端链表队列实现
│   └── priority_queue.h        # 优先队列实现
│
├── stack/                      # 栈相关实现
│   ├── stack_al.h              # 基于数组的栈实现
│   └── stack_ll.h              # 基于链表的栈实现
│
├── tree/                       # 树结构相关实现
│   ├── avl_tree.h              # AVL树实现
│   ├── b_tree.h                # B树实现
│   ├── b_tree2.h               # B树（第二版）实现
│   ├── binary_search_tree.h    # 二叉搜索树实现
│   ├── bp_tree_indisk.h        # B+树（磁盘优化版）实现
│   ├── rb_tree.h               # 红黑树实现
│   └── trie.h                  # 字典树实现
│
└── unionfind/                  # 并查集相关实现
    └── union_find.h            # 并查集实现

```


## 支持的数据结构

1. **哈希表 (Hashtable)**
    - 提供对整数、字符串、指针等类型的哈希和比较函数，支持哈希集合和哈希表的实现。

2. **堆 (Heap)**
    - 支持二叉堆，用于实现优先级队列等数据结构。

3. **列表 (List)**
    - 动态数组列表与链表，支持不同类型数据的存储与管理。

4. **队列 (Queue)**
    - 提供双端链表队列与优先级队列的实现。

5. **栈 (Stack)**
    - 包括基于数组和链表的栈实现。

6. **树 (Tree)**
    - 多种树结构，包括AVL树、B树、B+树、二叉搜索树、红黑树和字典树，适用于不同的存储和检索需求。

7. **并查集 (Union-Find)**
    - 并查集结构，用于解决动态连通性问题。

## 贡献
如果你想为此项目做贡献，欢迎提交 pull request 或者创建 issue。
## 许可证
本项目基于 MIT License 许可证。
