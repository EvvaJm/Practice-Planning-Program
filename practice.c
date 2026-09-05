#include <stdio.h>

struct Drill {
    char name[50];
    double plannedTime;
    double minTime;
    double maxTime;
    int rank;
    double actualTime;
};

int main(void) {
    int numOfDrills;

    printf("How many drills will your practice have? ");
    scanf("%d", &numOfDrills);

    struct Drill drills[numOfDrills];

    for (int i = 0; i < numOfDrills; i++) {
        printf("Drill %d\n", i + 1);
        printf("What is the drill name? ");
        scanf("%49s\n", drills[i].name);
        printf("What is the planned time for this drill? ");
        scanf("%49s", drills[i].name);
    }

    return 0;
}
