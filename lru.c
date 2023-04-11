#include <stdio.h>

int main() {
    int n, m, pages[100], frames[10], temp[10], page_faults = 0, flag1, flag2, i, j, k, pos, max, fault, recent = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &m);
    for (i = 0; i < m; ++i) {
        frames[i] = -1;
    }
    for (i = 0; i < n; ++i) {
        flag1 = flag2 = 0;
        for (j = 0; j < m; ++j) {
            if (frames[j] == pages[i]) {
                page_faults--;
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0) {
            for (j = 0; j < m; ++j) {
                if (frames[j] == -1) {
                    page_faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0) {
            flag1 = 0;
            for (j = 0; j < m; ++j) {
                temp[j] = -1;
                for (k = i - 1; k >= 0; --k) {
                    if (frames[j] == pages[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }
            for (j = 0; j < m; ++j) {
                if (temp[j] == -1) {
                    pos = j;
                    flag1 = 1;
                    break;
                }
            }
            if (flag1 == 0) {
                max = temp[0];
                pos = 0;
                for (j = 1; j < m; ++j) {
                    if (temp[j] > max) {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            page_faults++;
        }
        printf("\nAfter %d page reference(s):", i + 1);
        for (j = 0; j < m; ++j) {
            printf(" %d", frames[j]);
        }
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}