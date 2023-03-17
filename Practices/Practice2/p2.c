#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long ll;
typedef struct Task {
    char task_name[50];

    ll (*function)(int);

    int upperBound;
    int type; // 0: Normal Test; 1: Exponential or FactorialTest Test
} Task;

void merge(int a[], int start, int mid, int end);

void merge_sort_up_to_down(int a[], int start, int end);

ll linear_time(int n);

ll nlogn_time(int n);

ll quadratic_time(int n);

ll cubic_time(int n);

ll exponential_time(int n);

ll factorial_time(int n);

void generate_array(int *array, int n);


Task task_list[] = {
        {"Linear Time Test",      linear_time,      10000000, 0},
        {"Nlogn Time Test",       nlogn_time,       1000000,  0},
        {"Quadratic Time Test",   quadratic_time,   100000,   0},
        {"Cubic Time Test",       cubic_time,       1000,     0},
        {"Exponential Time Test", exponential_time, 29,       1},
        {"Factorial Time Test",   factorial_time,   12,       1}
};

clock_t start, finish;

int main() {
    FILE *file = fopen("c_result.csv", "w");
    srand(time(NULL));

    int task_num = sizeof(task_list) / sizeof(task_list[0]);
    int type_flag = -1;
    for (int i = 0; i < task_num; i++) {
        Task t = task_list[i];
        printf("running: %s\n", t.task_name);

        if (t.type == 0) {
            // normal test

            // table header
            if (type_flag != t.type) {
                type_flag = t.type;
                for (int n = 10; n <= t.upperBound; n *= 10)
                    fprintf(file, ",n=%d", n);
                fprintf(file, "\n");
            }
            // start test
            fprintf(file, "%s", t.task_name);
            for (int n = 10; n <= t.upperBound; n *= 10) {
                ll result = t.function(n);
                fprintf(file, ",%dms", result);
            }
            fprintf(file, "\n");
        } else {
            // Exponential or FactorialTest Test

            // table header
            if (type_flag != t.type) {
                type_flag = t.type;
                for (int n = 10; n <= t.upperBound; n += 1)
                    fprintf(file, ",n=%d", n);
                fprintf(file, "\n");
            }
            // start test
            fprintf(file, "%s", t.task_name);
            for (int n = 10; n <= t.upperBound; n += 1) {
                ll result = t.function(n);
                fprintf(file, ",%dms", result);
            }
            fprintf(file, "\n");
        }
    }
    fclose(file);
}

ll linear_time(int n) {
    int *array = malloc(n * sizeof(int));
    generate_array(array, n);
    start = clock();
    int max_int;
    for (int i = 0; i < n; i++)
        if (array[i] > max_int)
            max_int = array[i];
    finish = clock();
    free(array);
    return finish - start;
}

ll nlogn_time(int n) {
    int *array = malloc(n * sizeof(int));
    generate_array(array, n);
    start = clock();

    merge_sort_up_to_down(array, 0, n - 1);

    finish = clock();
    free(array);
    return finish - start;
}


ll quadratic_time(int n) {
    int *array = malloc(n * sizeof(int));
    generate_array(array, n);
    start = clock();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }

    finish = clock();
    free(array);
    return finish - start;
}

ll cubic_time(int n) {
    int *array = malloc(n * sizeof(int));
    generate_array(array, n);
    start = clock();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                array[(i + j + k) / 3] = rand();
            }
        }
    }

    finish = clock();
    free(array);
    return finish - start;
}

void exponential_time_res(int *a, int n) {
    if (n == 1) {
        a[0] = a[0] * 3;
        a[0]--;
        return;
    }
    exponential_time_res(a, n - 1);
    exponential_time_res(a, n - 1);
}

ll exponential_time(int n) {
    int *array = malloc(n * sizeof(int));
    generate_array(array, n);
    start = clock();

    exponential_time_res(array, n);

    finish = clock();
    free(array);
    return finish - start;
}

void factorial_time_res(int *a, int n) {
    if (n == 1) {
        ++a[0];
        return;
    }
    for (int i = 0; i < n; ++i) {
        factorial_time_res(a, n - 1);
    }
}

ll factorial_time(int n) {
    int *array = malloc(n * sizeof(int));
    generate_array(array, n);
    start = clock();

    factorial_time_res(array, n);

    finish = clock();
    free(array);
    return finish - start;
}

void generate_array(int *array, int n) {
    for (int i = 0; i < n; i++)
        array[i] = rand();
}


void merge(int a[], int start, int mid, int end) {
    int *tmp = (int *) malloc((end - start + 1) * sizeof(int));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= end) {
        tmp[k++] = a[j++];
    }

    for (i = 0; i < k; i++) {
        a[start + i] = tmp[i];
    }
    free(tmp);
    tmp = NULL;
}

void merge_sort_up_to_down(int a[], int start, int end) {
    if (a == NULL || start >= end) {
        return;
    }
    int mid = (end + start) / 2;
    merge_sort_up_to_down(a, start, mid);
    merge_sort_up_to_down(a, mid + 1, end);

    merge(a, start, mid, end);
}