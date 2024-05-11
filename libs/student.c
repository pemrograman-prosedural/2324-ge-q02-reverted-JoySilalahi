#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void student_print_all_detail(struct student_t *students, short size) {
    for (short i = 0; i < size; i++) {
        printf("%s|%s|%s|%s|", students[i].id, students[i].name, students[i].year, students[i].gender == GENDER_MALE ? "male" : "female");
        if (students[i].dorm != NULL) {
            printf("%s\n", students[i].dorm->name);
        } else {
            printf("unassigned\n");
        }
    }
}

void assign_student(struct student_t *student, struct dorm_t *dorm, char *student_id, char *dorm_name) {
    student->dorm = dorm;
    dorm->residents_num++;
}
