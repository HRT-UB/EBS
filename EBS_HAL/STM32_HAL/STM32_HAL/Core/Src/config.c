/*
 * config.c
 *
 *  Created on: 2023年8月17日
 *      Author: ROG
 */

#include "main.h"
#include "config.h"
uint32_t _oa_ratio = 3; // 油压-气压比
uint32_t _release_max_oil = 600; // 制动释放时允许的最高油压
uint32_t _max_air = 800;
uint32_t _min_air = 450;
uint32_t _lose_oil = 300;
uint32_t _error_max_cnt = 3;
uint32_t _front_air = 1;
uint32_t _back_air = 1;

