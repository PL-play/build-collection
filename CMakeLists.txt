cmake_minimum_required(VERSION 3.16)
project(collection C)

set(CMAKE_C_STANDARD 11)

include_directories("include")

# 添加静态库 ZCollection
add_library(ZCollection STATIC src/list/array_list.c src/list/linked_list.c src/tree/binary_search_tree.c src/heap/binary_heap.c
        src/tree/avl_tree.c src/tree/rb_tree.c src/stack/stack_al.c src/tree/trie.c src/hashtable/hash_table.c src/hashtable/hash-int.c
        src/hashtable/hash-pointer.c src/hashtable/hash-string.c src/hashtable/compare-int.c src/hashtable/compare-pointer.c
        src/hashtable/compare-string.c src/hashtable/hash_set.c src/tree/b_tree.c src/queue/dqueue_ll.c src/stack/stack_ll.c
        src/tree/bp_tree_indisk.c src/tree/b_tree2.c src/unionfind/union_find.c src/queue/priority_queue.c src/hashtable/hash-double.c
        src/hashtable/sha256.c
)

target_include_directories(ZCollection PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# 安装库和头文件
install(TARGETS ZCollection
        EXPORT ZCollectionTargets           # 导出目标到 ZCollectionTargets
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

# 批量安装头文件目录
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)

# 生成并安装 ZCollectionConfig.cmake 文件
include(CMakePackageConfigHelpers)

# 配置 ZCollectionConfig.cmake 文件
configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/ZCollectionConfig.cmake.in" # 输入模板
        "${CMAKE_CURRENT_BINARY_DIR}/ZCollectionConfig.cmake"          # 输出配置文件
        INSTALL_DESTINATION lib/cmake/ZCollection                      # 安装路径
)

# 安装 ZCollectionConfig.cmake
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/ZCollectionConfig.cmake"
        DESTINATION lib/cmake/ZCollection
)

# 生成 ZCollectionTargets.cmake 文件以导出库信息
install(EXPORT ZCollectionTargets        # 现在导出的 ZCollectionTargets 是有效的
        FILE ZCollectionTargets.cmake
        NAMESPACE ZCollection::
        DESTINATION lib/cmake/ZCollection
)

# 导出 ZCollectionTargets，使其可在构建过程中使用
export(EXPORT ZCollectionTargets
        FILE "${CMAKE_CURRENT_BINARY_DIR}/ZCollectionTargets.cmake"
        NAMESPACE ZCollection::
)

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
            ZCollection
    )
endforeach ()
