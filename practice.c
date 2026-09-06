// This is being used to plan and test the logic for an app I'm building 

/* This is a mock design for a program designed for coaches to be able to enter a practice plan and run the practice. The program automatically  
adjusts the time of the remaining drills in a practice based on the actual time it takes to complete each drill before it. This will help
prevent coaches from being left with extra time at the end of practices and not knowing what to do, or from having no time at the end of a practice
to complete their last drill. */


#include <stdio.h>

// stores the information for each drill 
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


// Loops through the array of drills and collects the information for each drill 
struct Drill drills[numOfDrills];

for (int i = 0; i < numOfDrills; i++) {
printf("Drill %d\n", i + 1);

printf("What is the drill name? ");
scanf(" %49[^\n]", drills[i].name);

printf("What is the planned time for this drill? ");
scanf("%lf", &drills[i].plannedTime);

printf("What is the minimum amount of time that can be allotted for this drill? ");
scanf("%lf", &drills[i].minTime);

printf("What is the maximum amount of time that can be allotted for this drill? ");
scanf("%lf", &drills[i].maxTime);
}

// sets each drill rank to zero
for (int i = 0; i < numOfDrills; i++) {
drills[i].rank = 0;
}

// prints each drill entered in order 
for (int i = 0; i < numOfDrills; i++) {
printf("\nYour drills:\n");

for (int j = 0; j < numOfDrills; j++) {
printf("%d. %s", j + 1, drills[j].name);

if (drills[j].rank != 0) {
printf(" - Rank %d", drills[j].rank);
}

printf("\n");
}

int rank;
int validRank = 0;

// collects the importance of each drill 
while (validRank == 0) {
printf("\nWhat is the importance/rank of %s? (1-%d): ",
drills[i].name, numOfDrills);
scanf("%d", &rank);

// prevents an error of a negative rank or rank greater than the number of drills being entered
if (rank < 1 || rank > numOfDrills) {
printf("Error! Please enter a number between 1 and %d.\n",
numOfDrills);
}
else {
int drillWithRank = -1;

for (int j = 0; j < numOfDrills; j++) {
if (drills[j].rank == rank) {
drillWithRank = j;
}
}

// prevents 2 drills from being given the same rank
if (drillWithRank == -1) {
drills[i].rank = rank;
validRank = 1;
}
else {
printf("\nError! Rank %d is already assigned to %s.\n",
rank, drills[drillWithRank].name);

int choice;

// if 2 drills are given the same rank this lets the user choose what to do 
printf("Would you like to change %s's ranking?\n",
drills[drillWithRank].name);
printf("1. Yes\n");
printf("2. No\n");
printf("Choose: ");
scanf("%d", &choice);

if (choice == 1) {
int newRank;
int validNewRank = 0;

while (validNewRank == 0) {
printf("What should %s's new rank be? (1-%d): ",
drills[drillWithRank].name, numOfDrills);
scanf("%d", &newRank);

if (newRank < 1 || newRank > numOfDrills) {
printf("Error! Please enter a number between 1 and %d.\n",
numOfDrills);
}
else {
int newRankTaken = 0;

for (int j = 0; j < numOfDrills; j++) {
if (drills[j].rank == newRank &&
j != drillWithRank) {
newRankTaken = 1;
}
}

if (newRankTaken == 1) {
printf("Error! Rank %d is already being used.\n",
newRank);
}
else {
drills[drillWithRank].rank = newRank;
validNewRank = 1;
}
}
}
}
else {
printf("Okay. Please choose a different rank for %s.\n",
drills[i].name);
}
}
}
}
}

struct Drill temp;

for (int i = 0; i < numOfDrills - 1; i++) {
for (int j = i + 1; j < numOfDrills; j++) {
if (drills[j].rank < drills[i].rank) {
temp = drills[i];
drills[i] = drills[j];
drills[j] = temp;
}
}
}

// prints the final order of the drills 
printf("\nFinal practice order:\n");

for (int i = 0; i < numOfDrills; i++) {
printf("%d. %s\n", i + 1, drills[i].name);
}

return 0;
}
