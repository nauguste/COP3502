//Naseem Auguste
//COP3502

//Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
typedef struct
{
    char LastName[50];
    int Assignment, Final, Total;
    int *Quizzes;
}Student;


//Function
Student * readData(FILE * ifp, int * noOfRecords, int * noOfQuiz)
{
    int i, j;

    //Scan in values for N and M
    fscanf(ifp, "%d %d", noOfRecords, noOfQuiz);

    //Allocate memory for number of Students
    Student * StudentPTR = (Student *)malloc(*noOfRecords * sizeof(Student));

    //Allocate memory for the Quizzes & Scan in Student Quizzes, Names and Assignments
    for(i = 0; i < *noOfRecords; i++)
    {
        StudentPTR[i].Quizzes = (int *)malloc(*noOfQuiz *sizeof(int));
        StudentPTR[i].Total = 0;

        fscanf(ifp, "%s %d", StudentPTR[i].LastName, &StudentPTR[i].Assignment);
        for(j = 0; j < *noOfQuiz; j++)
        {
            fscanf(ifp, "%d", &StudentPTR[i].Quizzes[j]);
            StudentPTR[i].Total += StudentPTR[i].Quizzes[j];
        }
        fscanf(ifp, "%d", &StudentPTR[i].Final);
        StudentPTR[i].Total += StudentPTR[i].Assignment + StudentPTR[i].Final;
    }
    return StudentPTR;
}


int main()
{
  //Declarations
  FILE * ifp, * ofp;
  ifp = fopen("input.txt", "r");
  ofp = fopen("output.txt","w");

  if((ifp =fopen("input.txt","r"))==NULL)
  {
    printf("Error opening file\n");
    exit(1);
  }

  int i = 0, j = 0, noOfRecords, noOfQuiz;
  int HighestScore = 0, HighestScorer = 0;
  Student * StudentPTR = readData(ifp, &noOfRecords, &noOfQuiz);

  //File Input and Output Open



  //Function Call
  readData(ifp, &noOfRecords, &noOfQuiz);

  printf("Displaying Student Details\n\n");
  //Print Names and Scores
  printf("Last\tTotal\n");
  printf("-----------------------\n");

  for (i = 0; i < noOfRecords; i++)
    printf("%s  %d\n", (StudentPTR+i) -> LastName, (StudentPTR[i]).Total);

  //Find best performing student
  for( i = 0; i < noOfRecords; i++)
  {
      if (StudentPTR[i].Total > HighestScore)
      {
          HighestScore = StudentPTR[i].Total;
          HighestScorer = i;
      }
  }
  printf("\nThe Highest Scoring Student is...\n");
  printf("%s  %d\n", StudentPTR[HighestScorer].LastName,StudentPTR[HighestScorer].Total);
  fprintf(ofp,"%s %d\n", StudentPTR[HighestScorer].LastName,StudentPTR[HighestScorer].Total);

  for(i = 0; i < noOfRecords; i++)
    free(StudentPTR[i].Quizzes);
  free(StudentPTR);

  fclose(ifp);
  fclose(ofp);

  return 0;
}

