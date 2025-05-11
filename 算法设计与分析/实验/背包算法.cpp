#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// �ṹ�嶨�壺�ͻ�����
struct Request {
    int time;       // ����ʱ��
    int ddl;        // �������ʱ��
    int begin;      // ʵ�ʿ�ʼʱ��
    int end;        // ʵ�����ʱ��
};

// �ȽϺ����������������ʱ������
int compare(const void *a, const void *b) {
    const struct Request *req1 = (const struct Request *)a;
    const struct Request *req2 = (const struct Request *)b;
    return req1->ddl - req2->ddl;
}

// ����������
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

// ������С�ӳٵ��ȵ�����ӳ�ʱ�䣬���������˳��
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

// ��������������������
int main() {
    struct Request req[MAX_SIZE]; // �ͻ���������
    int requestNum; // ��������

    printf("������������: ");
    scanf("%d", &requestNum);

    if (requestNum > MAX_SIZE) {
        printf("������������\n");
        return 0;
    }

    // ����ÿ�������ʱ����������ʱ��
    for (int i = 0; i < requestNum; ++i) {
        printf("���� %d ��ʱ����������ʱ��: ", i + 1);
        scanf("%d %d", &req[i].time, &req[i].ddl);
    }

    // ������С�ӳٵ��Ⱥ���
    int min_max_delay = minimum_delay_schedule(req, requestNum);

    // �������˳��
    printf("����˳��: ");
    for (int i = 0; i < requestNum; ++i) {
        printf("%d ", i + 1);
    }
    printf("\n");

    // �����С������ӳ�ʱ��
    printf("��С������ӳ�: %d\n", min_max_delay);

    return 0;
}
