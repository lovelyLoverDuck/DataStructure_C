# include <stdio.h>
# define MAX_SIZE 12


void inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;

    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i]; 
        for (j = i - gap; j >= first && list[j] > key; j = j - gap) {
            list[j + gap] = list[j]; 
        }

        list[j + gap] = key;
    }

    for (i = 0; i < MAX_SIZE; i++)
        printf("%d\t", list[i]);
    printf("\n================================================================\n");

}

void shell_sort(int list[], int n) {
    int i, gap;

    for (gap = n / 2; gap > 0; gap = gap / 2) 
    {
        if ((gap % 2) == 0)
            gap++;
       
            for (i = 0; i < gap; i++)                
                inc_insertion_sort(list, i, n - 1, gap);
            

    }
}

void main() {
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE] = { 7, 19, 24, 13, 31, 8 ,82, 18, 44, 63, 5, 29 };

    // 셸 정렬 수행
    shell_sort(list, n);

    // 정렬 결과 출력
    for (i = 0; i < n; i++) 
        printf("%d\t", list[i]);
    
}