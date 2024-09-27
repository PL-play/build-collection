cmake_minimum_required(VERSION 3.16)
project(collection C)

set(CMAKE_C_STANDARD 11)

include_directories("include")

add_library(Collection STATIC src/list/array_list.c src/list/linked_list.c src/tree/binary_search_tree.c src/heap/binary_heap.c
        src/tree/avl_tree.c src/tree/rb_tree.c src/stack/stack_al.c src/tree/trie.c src/hashtable/hash_table.c src/hashtable/hash-int.c
        src/hashtable/hash-pointer.c src/hashtable/hash-string.c src/hashtable/compare-int.c src/hashtable/compare-pointer.c
        src/hashtable/compare-string.c src/hashtable/hash_set.c src/tree/b_tree.c src/queue/dqueue_ll.c src/stack/stack_ll.c
        src/tree/bp_tree_indisk.c src/tree/b_tree2.c src/unionfind/union_find.c src/queue/priority_queue.c src/hashtable/hash-double.c
        src/hashtable/sha256.c
)


target_include_directories(Collection PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# 安装
install(TARGETS Collection
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)


# 批量安装头文件目录
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)

# 获取 test 目录下的所有 .c 文件
file(GLOB test_files "${CMAKE_CURRENT_SOURCE_DIR}/test/*.c")

# 获取 help_test 目录下的所有 .c 文件
file(GLOB help_test_files "${CMAKE_CURRENT_SOURCE_DIR}/test/help_test/*.c")

# 遍历 test 目录下的所有 .c 文件
foreach (test_file ${test_files})
    # 获取文件名，不包含路径和扩展名
    get_filename_component(name ${test_file} NAME_WE)

    # 为每个可执行文件添加 test 文件和 help_test 目录下的文件
    add_executable(${name} ${test_file} ${help_test_files})

    target_link_libraries(${name}
                        Collection
                )
endforeach ()
