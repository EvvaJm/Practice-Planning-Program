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
        scanf(" %49[^\n]", drills[i].name);
        printf("What is the planned time for this drill? ");
        scanf("%lf", drills[i].plannedTime);
        printf("What is the minimum amount of time that can be altted for this drill?");
        scanf("%lf", drills[i].minTime);
        printf("What is the maximum amount of time that can be altted for this drill?");
        scanf("%lf", drills[i].maxTime);
    }

    for (int i = 0; i < numOfDrills; i++) {

    
        
    }
    
    

    return 0;
}
