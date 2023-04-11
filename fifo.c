#include <stdio.h>

int main() {
    int frames, pages, i, j, k, flag, fault = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    int frame[frames];
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    int page[pages];
    printf("Enter the reference string: ");
    for(i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    j = 0;
    printf("\nReference String\tPage Frames\tFaults\n");
    for(i = 0; i < pages; i++) {
        printf("%d\t\t", page[i]);
        flag = 0;
        for(k = 0; k < frames; k++) {
            if(frame[k] == page[i]) {
                flag = 1;
            }
        }
        if(flag == 0) {
            frame[j] = page[i];
            j = (j + 1) % frames;
            fault++;
            for(k = 0; k < frames; k++) {
                printf("%d ", frame[k]);
            }
        }
        printf("\t\t%d", fault);
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", fault);
    return 0;
}