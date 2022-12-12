#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Create function to display person
// Create function to go to study (change status & set index)
// Create function to expelled from study (change status)
// Create Person global object (me)

enum Gender
{
  Men = 1,
  Women = 2,
  Apache_Helicopter = 3
};

typedef struct Person
{
  char *firstName;
  char *lastName;
  uint16_t indexNumber;
  bool isStudent;
  enum Gender gender;
} Person;

void displayPerson(Person *x)
{
  printf("\nName: %s", x->firstName);
  printf("\nLast Name: %s", x->lastName);
  if (x->isStudent)
    printf("\nIndex number of student: %d", x->indexNumber);
  else
    printf("\nNot a student");
  switch (x->gender)
  {
  case 1:
    printf("\nGender: Man");
    break;
  case 2:
    printf("\nGender: Woman");
    break;
  case 3:
    printf("\nGender: Apache Helicopter");
    break;
  default:
    break;
  }
}

void makeStudent(Person *x)
{
  if (x->isStudent)
    printf("\nAlready a student!");
  else
  {
    x->isStudent = true;
    srand(time(NULL));
    x->indexNumber = rand() + 1;
  }
}

void unmakeStudent(Person *x)
{
  if (!x->isStudent)
    printf("\nAlready not a student!");
  else
  {
    x->isStudent = false;
    x->indexNumber = 0;
  }
}

int main(void)
{
  Person student_tymek = {"Tymek", "Staszek", 0, false, 1};
  displayPerson(&student_tymek);
  makeStudent(&student_tymek);
  displayPerson(&student_tymek);
  unmakeStudent(&student_tymek);
  displayPerson(&student_tymek);
  // Create Person loacal object (my-best-friend)
  // tests...
  // display (me)
  // display (my-best-friend)
  return 0;
}