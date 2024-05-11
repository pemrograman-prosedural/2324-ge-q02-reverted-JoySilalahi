#include "dorm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dorm_print_all_detail(struct dorm_t *dorm, short d) {
    for (short i = 0; i < d; i++) {
        printf("%s|%d|%s|%d\n", dorm[i].name, dorm[i].capacity, gender_str(dorm[i].gender), dorm[i].residents_num);
    }
}

void dorm_empty(struct dorm_t *dorm, short *d, char *dorm_name) {
    for (short i = 0; i < *d; i++) {
        if (strcmp(dorm[i].name, dorm_name) == 0) {
            dorm[i].residents_num = 0;
            break;
        }
    }
}

