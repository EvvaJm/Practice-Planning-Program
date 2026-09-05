#include <stdio.h>

int main () {

int numOfDrills;

printf("How many drills will your practice have?");
scanf("%d", &numOfDrills);

struct drills [numOfDrills];
  
  
struct Drill {
    char name [50];
    double plannedTime;
    double minTime;
    double maxTime;
    int rank;
    duble actualTime;
};
  
  for (int i = 0; i <= numOfDrills, i++) {
    printf("Drill %d\n", i);
    pritf ("What is the drill name?");
  } 
  
return 0;
}
