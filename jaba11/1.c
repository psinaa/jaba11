#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>
#define NMax 99

int a1()
{
    float A[10];
    float temp;
    int i;
    float sum = 0.0;
    for (i = 0; i < 10; i++) {
        printf("\nA[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
        printf("| индекс %d| исходное значение %.0f| новое значение %.0f",i,A[i], A[i]*A[i]);
        sum += A[i];
        printf("\nСреднее арифметическое:%.1f\n", sum / 10);
    }
}
float func(float x)
{
    return  pow(2.0, x) - 2.0 * pow(x, 2.0) - 1.0;
}

int a2()
{
    float interval = 2.0;
    float array_result[NMax];
    float sum_minus = 0.0;
    float sum_plus = 0.0;
    int count_minus = 0;
    int count_plus = 0;
    for (int i = 0; i < NMax; i++)
    {
        float num = func(interval);
        if (num < 0.0)
        {
            sum_minus += num;
            count_minus += 1;
        }
        else
        {
            sum_plus = sum_plus + num;
            count_plus++;
        }
        array_result[i] = num;
        interval += 2.0 / 98.0;
    }
    printf("Массив: Сумма минуc: %f\n"
        "Сумма плюс: %f\n"
        "Число отрицательных: %d \n"
        "Число положительных: %d\n"
        "Среднее %f\n", sum_minus, sum_plus, count_minus, count_plus, sum_plus / count_plus);

    return 0;
}
int a3()
{
    int* a;
    int i, n;
    printf("Введите кол-во чисел массива: ");
    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
    float summa = 0;
    for (int i = 1; i < n - 1; i++)
    {
        summa += a[i];
    }
    printf("Сумма: %10.3f", summa);
    return 0;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    a1();
    a2();
    a3();
}