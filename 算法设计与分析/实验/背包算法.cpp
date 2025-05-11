#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 结构体定义：客户请求
struct Request {
    int time;       // 服务时间
    int ddl;        // 期望完成时间
    int begin;      // 实际开始时间
    int end;        // 实际完成时间
};

// 比较函数，按照期望完成时间排序
int compare(const void *a, const void *b) {
    const struct Request *req1 = (const struct Request *)a;
    const struct Request *req2 = (const struct Request *)b;
    return req1->ddl - req2->ddl;
}

// 快速排序函数
void quicksort(struct Request req[], int low, int high) {
    if (low < high) {
        int pivot = low;
        int i = low;
        for (int j = low + 1; j <= high; ++j) {
            if (req[j].ddl < req[pivot].ddl) {
                i++;
                // Swap req[i] and req[j]
                struct Request temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
        // Swap req[i] and req[pivot]
        struct Request temp = req[i];
        req[i] = req[pivot];
        req[pivot] = temp;

        // Recursively sort the two halves
        quicksort(req, low, i - 1);
        quicksort(req, i + 1, high);
    }
}

// 计算最小延迟调度的最大延迟时间，并输出服务顺序
int minimum_delay_schedule(struct Request req[], int requestNum) {
    quicksort(req, 0, requestNum - 1);

    int maxDelay = 0;
    int current_time = 0;

    for (int i = 0; i < requestNum; ++i) {
        int service_time = req[i].time;
        int ddl = req[i].ddl;

        int start_time = (current_time <= ddl - service_time) ? ddl - service_time : current_time;

        int completion_time = start_time + service_time;

        int delay = (completion_time > ddl) ? completion_time - ddl : 0;
        if (delay > maxDelay) {
            maxDelay = delay;
        }

        current_time = completion_time;

        req[i].begin = start_time;
        req[i].end = completion_time;

        printf("%d ", i + 1);
    }

    printf("\n");

    return maxDelay;
}

// 主函数，处理输入和输出
int main() {
    struct Request req[MAX_SIZE]; // 客户请求数组
    int requestNum; // 请求数量

    printf("输入请求数量: ");
    scanf("%d", &requestNum);

    if (requestNum > MAX_SIZE) {
        printf("请求数量过多\n");
        return 0;
    }

    // 输入每个请求的时间和期望完成时间
    for (int i = 0; i < requestNum; ++i) {
        printf("请求 %d 的时间和期望完成时间: ", i + 1);
        scanf("%d %d", &req[i].time, &req[i].ddl);
    }

    // 调用最小延迟调度函数
    int min_max_delay = minimum_delay_schedule(req, requestNum);

    // 输出服务顺序
    printf("服务顺序: ");
    for (int i = 0; i < requestNum; ++i) {
        printf("%d ", i + 1);
    }
    printf("\n");

    // 输出最小的最大延迟时间
    printf("最小的最大延迟: %d\n", min_max_delay);

    return 0;
}
