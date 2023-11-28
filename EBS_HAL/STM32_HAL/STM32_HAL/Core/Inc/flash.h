/*
 * flash.h
 *
 *  Created on: 2023��11��3��
 *      Author: ROG
 */
#ifndef __FLASH_H
#define __FLASH_H

#include "main.h"

#define SN 			            0x08010000
#define PN 			            0x08010010


void WriteFlash();
void ReadFlash();
uint32_t getFlashInitCode();

#endif
