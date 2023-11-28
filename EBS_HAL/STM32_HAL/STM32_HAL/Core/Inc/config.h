/*
 * config.h
 *
 *  Created on: 2023年8月17日
 *      Author: ROG
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

//#define EBS_TEST
#define FRONT_AIR
#define BACK_AIR

#define _oa_ratio_id         0
#define _release_max_oil_id  1
#define _max_air_id          2
#define _min_air_id          3
#define _lose_oil_id         4
#define _error_max_cnt_id    5
#define _front_air_id        6
#define _back_air_id         7

extern uint32_t _oa_ratio; // 油压-气压比
extern uint32_t _release_max_oil; // 制动释放时允许的最高油压
extern uint32_t _max_air;
extern uint32_t _min_air;
extern uint32_t _lose_oil;
extern uint32_t _error_max_cnt;
extern uint32_t _front_air;
extern uint32_t _back_air;
#endif /* INC_CONFIG_H_ */
