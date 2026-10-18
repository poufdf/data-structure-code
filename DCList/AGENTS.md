# DCList

带哨兵位（哑元）的双向循环链表 C 语言实现，使用 Visual Studio 2022 构建。

## 构建

```
msbuild DCList\DCList.vcxproj /p:Configuration=Debug /p:Platform=x64
```

产物在 `DCList\x64\Debug\DCList.exe`。

## 测试

没有测试框架——`test.c` 就是一个简单的 `main()` 函数，直接运行 exe 即可测试：

```
DCList\x64\Debug\DCList.exe
```

## 架构要点

- `DCListInit()` 创建哨兵结点，`data = -1`，空表时 `prev` 和 `next` 指向自身。
- `DCListGetElem` 下标从 0 开始，越界直接 `assert`。
- 所有操作都依赖有效哨兵指针，内部用 `assert` 而非错误返回值。
- `.c` 文件顶部需要 `#define _CRT_SECURE_NO_WARNINGS` 来抑制 MSVC 警告。
- 数据类型硬编码为 `int`（头文件 `DCLDataType`）。
- 无外部依赖，无 CI，无 lint/format 配置。
