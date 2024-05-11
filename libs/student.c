#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */
char *gender_to_text(enum gender_t _gender)
{
    char *gender;
    switch (_gender)
    {
        case GENDER_MALE:
            gender = "male";
            break;
        case GENDER_FEMALE:
            gender = "female";
            break;
    }

    return gender;
}

void student_print_all(struct student_t *_student, short _student_size) 
{
    for (short i = 0; i < _student_size; i++)
    {
        printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, gender_to_text(_student[i].gender));
    }
}

void student_print_all_detail(struct student_t *_student, short _student_size)
{
    for (short i = 0; i < _student_size; i++)
    {
        if (_student[i].dorm == NULL)
        {
            printf("%s|%s|%s|%s|unassigned\n", _student[i].id, _student[i].name, _student[i].year, gender_to_text(_student[i].gender)); 
        } else {
            printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, gender_to_text(_student[i].gender), _student[i].dorm->name);
        }  
    }
}

void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name) 
{
    if (_dorm->residents_num < _dorm->capacity){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *_tempDorm, char *id, char *dorm_name)
{
    if (_dorm->residents_num < _dorm->capacity){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_num += 1;
            _tempDorm->residents_num -= 1;
        }
    }
}

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t std;
    strcpy(std.id, _id);
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    std.gender = _gender;

    return std;
}
