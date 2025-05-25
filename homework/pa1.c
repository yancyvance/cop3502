#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 255
#define GRADE_STRING_SIZE 3
#define INPUT_FILE_NAME "pa1_data.txt"

// COP 3502C Summer 2025
// Student Name: TODO_your_name_here
// File Name: pa1_yoursurname.c
// Note: Rename to use your actual surname. File name should be in lowercase.
// You must remove any whitespaces or dashes from your surname.
// Note: DO NOT modify or remove TODO comments as it will interfere 
// with the grading system.


typedef struct Course_s {
    char *code;                     // course code; dynamic string
    int credit;                     // credit hours of this course
    char *grade;                    // grade obtained; dynamic string
} Course;

typedef struct Student_s {
    char *name;                     // student's complete name; dynamic string
    int course_count;               // number of courses this student has in the list
    Course **list_of_courses;       // list of courses; dynamic array of pointers to course
} Student;


// function prototypes defined here
// the function definitions are located below the main function
Student ** create_new_list_of_students(int);
void add_student_to_list(Student **, int, Student *);
void destroy_list_of_students(Student **, int);
Student * create_student(char *, int);
void destroy_student(Student *);
Course ** create_new_list_of_courses(int);
void destroy_list_of_courses(Course **, int);
Course * create_course(char *, int, char *);
void add_course_to_list(Student *, int, Course *);
void destroy_course(Course *);
double compute_gpa(Student *);
void introduce_class(Student **, int);
void introduce(Student *);
double get_points(char *);
void clear_buffer_file(FILE *);
void trim_string(char *);


int main(void) {
    // read the input file
    FILE *ifile = fopen(INPUT_FILE_NAME, "r");
    
    // check if the file was opened
    if(ifile == NULL) {
        // if there was a problem, simply return a 1
        printf("There was a problem opening the file. Abort!\n");
        return 1;
    }
    
    // read number of students from file
    int student_count;
    fscanf(ifile, "%d", &student_count);
    
    clear_buffer_file(ifile);
    
    // create a dynamic list of students with given size
    Student **student_list = create_new_list_of_students(student_count);
    
    // temporary variable holders for the name and count
    // as well as course information
    char name[MAX_STRING_SIZE];
    int course_count;
    char course_code[MAX_STRING_SIZE];
    int credit;
    char grade[GRADE_STRING_SIZE];
    
    // iterate through the list
    for(int i = 0; i < student_count; i++) {
        // read one line for the name
        fgets(name, MAX_STRING_SIZE, ifile);
        
        // trim
        trim_string(name);
        
        // get the course count
        fscanf(ifile, "%d", &course_count);
        
        clear_buffer_file(ifile);
        
        // create a student
        Student *student = create_student(name, course_count);
        
        // read the next few lines
        
        for(int j = 0; j < course_count; j++) {
            fscanf(ifile, "%s%d%s\n", course_code, &credit, grade);
            
            // add the current course to the current student's list of courses
            add_course_to_list(student, j, create_course(course_code, credit, grade));
        }
        
        // add the current student to the list of students
        add_student_to_list(student_list, i, student);
    }
    
    // close the input file
    fclose(ifile);
    
    // introduce all the students in the list
    introduce_class(student_list, student_count);
    
    // destroy the list and properly deallocate
    // all dynamic memory
    destroy_list_of_students(student_list, student_count);

    return 0;
}


Student ** create_new_list_of_students(int student_count) {
    // TODO 1 BEGIN
    // TODO: Allocate memory for a list of student 
    // pointers (size: student_count). Return the pointer
    // to the newly allocated list.


    
    // TODO 1 END
}


void add_student_to_list(Student **list_of_students, int pos, Student *student) {
    // TODO 2 BEGIN
    // TODO: Add the given student to the specified 
    // position in the list_of_students array.



    // TODO 2 END
}


void destroy_list_of_students(Student **list_of_students, int student_count) {
    // TODO 3 BEGIN
    // TODO: Free the memory for each student in the 
    // list, then free the student list itself.
    


    // TODO 3 END
}


Student * create_student(char *name, int course_count) {
    // TODO 4 BEGIN
    // TODO: Allocate and initialize a Student struct.
    // Dynamically copy the name and create space for the course list.



    // TODO 4 END
}


void destroy_student(Student *student) {
    // TODO 5 BEGIN
    // TODO: Free the memory for the student's name 
    // and course list, then free the student.
    
    
    
    // TODO 5 END
}


Course ** create_new_list_of_courses(int course_count) {
    // TODO 6 BEGIN
    // TODO: Allocate memory for a list of course 
    // pointers (size: course_count). Return the pointer
    // to the newly allocated list.



    // TODO 6 END
}


void add_course_to_list(Student *student, int pos, Course *course) {
    // TODO 7 BEGIN
    // TODO: Add the given course to the student's 
    // list_of_courses at the specified index.



    // TODO 7 END
}


void destroy_list_of_courses(Course **list_of_courses, int course_count) {
    // TODO 8 BEGIN
    // TODO: Free each course in the list, then 
    // free the list of course pointers.
    
    // individually iterate and deallocate
    for(int i = 0; i < course_count; i++) {
        destroy_course(*(list_of_courses+i));
    }
    
    // destroy the list itself
    free(list_of_courses);
    // TODO 8 END
}


Course * create_course(char *code, int credit, char *grade) {
    // TODO 9 BEGIN
    // TODO: Allocate and initialize a Course struct.
    // Dynamically copy the course code and grade. Store the credit value.



    // TODO 9 END
}


void destroy_course(Course *course) {
    // TODO 10 BEGIN
    // TODO: Free the memory allocated for the course 
    // code and grade, then free the course.
    


    // TODO 10 END
}


double compute_gpa(Student *student) {
    // TODO 11 BEGIN
    // TODO: Calculate GPA by converting grades to 
    // points and averaging weighted by credit hours.
    


    // TODO 11 END
}


void introduce_class(Student **list_of_students, int student_count) {
    // Have each student from the list introduce themselves
    for(int i = 0; i < student_count; i++) {
        introduce(list_of_students[i]);
    }
}


void introduce(Student *student) {
    // Print the student's name and their GPA 
    // rounded to two decimal places.
    printf("%s %.2f\n", student->name, compute_gpa(student));
}


double get_points(char *grade) {
    // Convert the letter grade to grade points 
    // based on the provided grade scale.
    if( strcmp(grade, "A") == 0 )  return 4.0;
    else if( strcmp(grade, "A-") == 0 ) return 3.75;
    else if( strcmp(grade, "B+") == 0 ) return 3.25;
    else if( strcmp(grade, "B") == 0 ) return 3.0;
    else if( strcmp(grade, "B-") == 0 ) return 2.75;
    else if( strcmp(grade, "C+") == 0 ) return 2.25;
    else if( strcmp(grade, "C") == 0 ) return 2.0;
    else if( strcmp(grade, "C-") == 0 ) return 1.75;
    else if( strcmp(grade, "D+") == 0 ) return 1.25;
    else if( strcmp(grade, "D") == 0 ) return 1.0;
    else if( strcmp(grade, "D-") == 0 ) return 0.75;
    
    return 0.0;
}


void clear_buffer_file(FILE *ifile) {
    // helper function that clears the file buffer
    int c;
    while( (c = fgetc(ifile)) != '\n' && c != EOF );
}


void trim_string(char *str) {
    // helper function that will remove the extra new line
    // begin at location right before
    // the null terminator of the string
    int len = strlen(str) - 1;

    // from the right, keep moving to the left;
    // continue doing so until what you see right
    // now is not a newline character anymore
    while(len > 0) {
        // stop moving to the left once you don't
        // see a newline character anymore
        if(str[len] != '\n' && str[len] != '\r')
            break;

        len--;
    }

    // len is currently pointing at the
    // last character right before a newline
    // therefore, it should be immediately
    // followed by the null character
    str[len+1] = '\0';
}
