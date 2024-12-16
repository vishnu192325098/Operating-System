#include <stdio.h>

void bestfit(int mp[], int p[], int m, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (mp[i] >= p[j]) {
            printf("\n%d fits in %d", p[j], mp[i]);
            mp[i] -= p[j++];
            i = -1; // Restart to find the best fit
        }
    }
    for (int i = j; i < m; i++) {
        printf("\n%d must wait for its process", p[i]);
    }
}

void rsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void firstfit(int mp[], int p[], int m, int n) {
    sort(mp, n);
    sort(p, m);
    bestfit(mp, p, m, n);
}

void worstfit(int mp[], int p[], int m, int n) {
    rsort(mp, n);
    sort(p, m);
    bestfit(mp, p, m, n);
}

int main() {
    int m, n, mp[20], p[20], ch;

    printf("Number of memory partitions: ");
    scanf("%d", &n);

    printf("Number of processes: ");
    scanf("%d", &m);

    printf("Enter the memory partitions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &mp[i]);
    }

    printf("Enter process sizes:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    printf("1. First Fit\t2. Best Fit\t3. Worst Fit\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            firstfit(mp, p, m, n);
            break;
        case 2:
            bestfit(mp, p, m, n);
            break;
        case 3:
            worstfit(mp, p, m, n);
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}

