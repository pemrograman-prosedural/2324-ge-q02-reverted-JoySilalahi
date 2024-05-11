// 12S23007 - Joy Valeda Silalahi 
// 12S23028 - Daniel Situmorang

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
  dorm *drm = malloc(sizeof(drm));
  student *std = malloc(sizeof(student_t));
  short totaldrm = 0;
  short totalstd = 0; 
 char baris[255];

 while(fgets(baris, 255, stdin)){
    baris[strcspn(baris, "\r\n")] = '\0';

    if ( strcmp(baris, "---") == 0 ) break;

char *token = strtok(baris, "#");

if ( strcmp(baris, "student-add") == 0 ) {
    char *_id = strtok(NULL, "#");
    char *_name = strtok(NULL, "#");
    char *_year = strtok(NULL, "#");
    if (strcmp(token, "male") == 0)
            {
                gender_t = GENDER_MALE;
            } 

            if (strcmp(token, "female") == 0)
            {
                gender_t = GENDER_FEMALE;
            }

            std[totalstd].gender = gender;
            std[totalstd].dorm = NULL;
            totalstd++;

}else if (strcmp(token, "dorm-add") == 0){
    char *_name = strtok(NULL, "#");
    unsigned short _capacity = atoi(strtok(NULL, "#"));
    Gender _geder = (strcmp(strtok(NULL, "#"), "male") == 0 ) ? GENDER_MALE : GENDER_FEMALE;
    drm = realloc(drm,(++totaldrm) * sizeof(dorm));
    drm[totaldrm - 1] = create_dorm(_name, _capacity, _gender);

}else if (strcmp(token, "assign-studnet") == 0){
    char *_id = strtok(NULL, "#");
    char *dorm_name= strtok(NULL, "#");
    short studentIdx = findStudentIdx(_id, std, totalstd);
    short newDormIdx = findDormIdx(dorm_name, drm, totaldrm);
    if (studentIdx >= 0 && newDormIdx >=0) assign-student(&std[studentIdx], &drm[dormIdx]);

}else if (strcmp(token, "move-student") == 0){
    char *_id = strtok(NULL, "#");
    char *dorm_name= strtok(NULL, "#");
    short studentIdx = findStudentIdx(_id, std, totalstd);
    short newDormIdx = findDormIdx(dorm_name, drm, totaldrm);
    if (studentIdx >= 0 && newDormIdx >=0) move-student(&std[sudentIdx], &drm[dormIdx]);

}else if (strcmp(token, "dorm-empty") == 0){
    char *dorm_name= strtok(NULL, "#");
    short x = findDormIdx(dorm_name, drm, totaldrm);
    if ( x >= 0)
        for (short i = 0; i < totalstd; i++){
            if (std[i].dorm) ! NULL &&  strcmp(std[i].dorm->name, dorm_name) == 0){
                unassign(&std[i], &drm[x]);
            }
         }
    }
 }
    free(drm);
    free(std);
    return 0;
}
