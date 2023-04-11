#include <stdio.h>
#include <stdbool.h>

int main() {
    int frames, pages, faults = 0, next = 0, k = 0, max, farthest, flag1, flag2, hit = 0;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    int frame[frames], ref[pages];
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    printf("Enter the reference string: ");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    for (int i = 0; i < pages; i++) {
        flag1 = flag2 = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == ref[i]) {
                flag1 = flag2 = 1;
                hit++;
                break;
            }
            if (frame[j] == -1) {
                faults++;
                frame[j] = ref[i];
                flag2 = 1;
                break;
            }
        }
        if (flag1 == 0 && flag2 == 0) {
            faults++;
            max = -1;
            for (int j = 0; j < frames; j++) {
                for (k = i + 1; k < pages; k++) {
                    if (frame[j] == ref[k]) {
                        if (k > max) {
                            max = k;
                            farthest = j;
                        }
                        break;
                    }
                }
                if (k == pages) {
                    farthest = j;
                    break;
                }
            }
            frame[farthest] = ref[i];
        }
        printf("\n");
        for (int j = 0; j < frames; j++) {
            printf("%d\t", frame[j]);
        }
    }
    printf("\nTotal Page Faults = %d", faults);
    printf("\nTotal Page Hits = %d", hit);
    return 0;
}
