#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calculate_average(int array[], int length) {
    float sum = 0;
    for(int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / length;
}

int main() {
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);
    
    int *Ui = (int*)malloc(n * sizeof(int));
    int *Vi = (int*)malloc(m * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &Ui[i]);
    }
    
    for(int i = 0; i < m; i++) {
        scanf("%d", &Vi[i]);
    }
    
    // Sort the processing times
    qsort(Ui, n, sizeof(int), compare);
    qsort(Vi, m, sizeof(int), compare);
    
    // Calculate the average processing times
    float average_time_step_1 = calculate_average(Ui, n);
    float average_time_step_2 = calculate_average(Vi, m);
    
    // Calculate the theoretical minimum time
    float theoretical_min_time_per_material = average_time_step_1 + average_time_step_2;
    float total_min_time = theoretical_min_time_per_material * k;
    
    printf("Theoretical Minimum Total Time: %.2f\n", total_min_time);
    
    free(Ui);
    free(Vi);
    
    return 0;
}
