#include "dorm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct dorm_t create_dorm(char *_name, unsigned short _capacity, 
                            enum gender_t _gender)
{
    struct dorm_t dorm;
    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.gender = _gender;

    return dorm;
}

void dorm_print_all(struct dorm_t *_dorm,
                                short _dorm_size) 
{
    for (short i = 0; i < _dorm_size; i++)
    {
        if (_dorm[i].gender == 0)
        {
            printf("%s|%d|male\n", _dorm[i].name, _dorm[i].capacity);
        }

        if (_dorm[i].gender == 1)
        {
            printf("%s|%d|female\n", _dorm[i].name, _dorm[i].capacity);
        }
    }
}

void dorm_print_all_detail(struct dorm_t *_dorm, 
                                short _dorm_size)
{
    for (short i = 0; i < _dorm_size; i++)
    {
        if (_dorm[i].gender == 0)
        {
            printf("%s|%d|male|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        }

        if (_dorm[i].gender == 1)
        {
            printf("%s|%d|female|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        }        
    }
}