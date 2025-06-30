#define MAX_SIZE 100
int m_act = 0;
void solution(int s[], int e[], int a[], int n) {
    int p_end = 0;
    for (int i = 0; i < n; i++) {
        for (int min = e[i], min_index = i; (e[j] <= min); j++) {
            if (e[j] < min) {
                min = e[j];
                min_index = j;
            }
        }
        int temp = s[i]; s[i] = s[min_index]; s[min_index] = temp;
        temp = e[i]; e[i] = e[min_index]; e[min_index] = temp;
        temp = a[i]; a[i] = a[min_index]; a[min_index] = temp;
        solution[0] = a[0];
        m_act = e[0];
        for (int i = 0; i < n; i++) {
            if (s[i] > p_end) {
                p_end = e[i];
                solution[m_act++] = a[i];
            }
        }
    }
}
int main() {
    int start[MAX_SIZE], end[MAX_SIZE], act[MAX_SIZE], n = 0;
    printf("Enter the number of activities(max 100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter start and end time for activity %d: ", i+1);
        scanf("%d %d", &start[i], &end[i]);
        act[i] = i+1;
    }
    activity(start, end, act, n);
    printf("Selected activities are:");
    for (int i = 0; i < m_act; i++) {
        printf(" %d", solution[i]);
    }
    printf("\n");
    return 0;
}