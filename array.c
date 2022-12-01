/**
 * 堆数组
 * 创建在堆上的数组
 * 2022.12.01.16:30
 * @copyright GNU GPL v2
 */

#include <stdio.h>
#include <stdlib.h>

int *create_array(int len)
{
    // calloc会将内存设置为0, malloc不会
    int *a = (int *)calloc(len ,sizeof(int));
    return a;
}

int main()
{
    int *array = create_array(10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }
    // 释放内存
    free(array);
    //printf("%d\n", array);
    // 弃用指针
    array = NULL;
    return 0;
}
