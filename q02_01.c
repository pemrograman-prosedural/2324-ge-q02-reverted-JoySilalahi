#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    char command[100];
    short loop = 0;
    struct student_t *std = malloc(100 * sizeof(struct student_t));
    struct dorm_t *dorm = malloc(100 * sizeof(struct dorm_t));
    short s = 0; // student_size
    short d = 0; // dorm_size
    short idS, idD = 0;
    while (loop != 1)
    {
        command[0] = '\0';
        short k = 0;
        while (1 == 1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            
            if (i == '\r')
            {
                continue;
            }
            
            command[k] = i;
            command[++k] = '\0';
        }

        char *token = strtok(command, "#");

        if (strcmp(token, "student-add") == 0)
        {
            short gender;
            token = strtok(NULL, "#");
            strcpy(std[s].id, token);
            token = strtok(NULL, "#");
            strcpy(std[s].name, token);
            token = strtok(NULL, "#");
            strcpy(std[s].year, token);
            token = strtok(NULL, "#");
            if (strcmp(token, "male") == 0)
            {
                gender = GENDER_MALE;
            } 

            if (strcmp(token, "female") == 0)
            {
                gender = GENDER_FEMALE;
            }
            
            std[s].gender = gender;
            std[s].dorm = NULL;
            s++;
        }

        if (strcmp(token, "dorm-add") == 0)
        {
            short gender;
            token = strtok(NULL, "#");
            strcpy(dorm[d].name, token);
            token = strtok(NULL, "#");
            dorm[d].capacity = atoi(token);
            token = strtok(NULL, "#");
            if (strcmp(token, "male") == 0)
            {
                gender = GENDER_MALE;
            } 

            if (strcmp(token, "female") == 0)
            {
                gender = GENDER_FEMALE;
            }
            
            dorm[d].gender = gender;
            dorm[d].residents_num = 0;
            d++;
        }


        if (strcmp(token, "student-print-all-detail") == 0)
        {
            student_print_all_detail(std, s);
        }

        if (strcmp(token, "dorm-print-all-detail") == 0)
        {
            dorm_print_all_detail(dorm, d);
        }
        
        if (strcmp(token, "assign-student") == 0)
        {
            char *id = strtok(NULL, "#");
            char *id_dorm = strtok(NULL, "#");
            for (short i = 0; i < s; i++)
            {
                if (strcmp(std[i].id, id) == 0)
                {
                    idS = i;
                    break;
                }
            }
            for (short i = 0; i < d; i++)
            {
                if (strcmp(dorm[i].name, id_dorm) == 0)
                {
                    idD = i;
                    break;
                }
            }
            
            assign_student(&std[idS], &dorm[idD], id, id_dorm);
        }
        
        if (strcmp(token, "dorm-empty") == 0)
        {
            char *dorm_name = strtok(NULL, "#");
            dorm_empty(dorm, &d, dorm_name);
        }
        
        if (strcmp(token, "---") == 0)
        {
            loop = 1;
        }
    }
    
    return 0;
}

