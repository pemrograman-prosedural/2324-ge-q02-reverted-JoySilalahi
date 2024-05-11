#ifndef DORM_H
#define DORM_H

#include "gender.h"

struct dorm_t
{
    char name[20];
    unsigned short capacity;
    enum gender_t gender;
    unsigned short residents_num;
};

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender);

void dorm_print_all_detail(struct dorm_t *dorm, short d);
void dorm_empty(struct dorm_t *dorm, short *d, char *dorm_name);

#endif
