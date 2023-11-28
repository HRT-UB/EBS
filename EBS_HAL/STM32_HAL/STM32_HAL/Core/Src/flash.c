/*
 * flash.c
 *
 *  Created on: 2023��11��3��
 *      Author: ROG
 */


#include "flash.h"
#include "config.h"
#include "usart.h"
uint32_t startAddress;
uint32_t endAddress;
//FLASHд������
void WriteFlash()
{
    startAddress = SN;
    HAL_FLASH_Unlock();
    FLASH_EraseInitTypeDef f;
    f.TypeErase = FLASH_TYPEERASE_PAGES;
    f.PageAddress = startAddress;
    f.NbPages = 1;
    uint32_t PageError = 0;
    HAL_FLASHEx_Erase(&f, &PageError);
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, init_code) == HAL_OK) // д��flash��ʼ��
	{
		startAddress +=4;
	}
	else {
		u3_printf("12312\r\n");
		HAL_FLASH_Lock();
		return;
	}
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, _oa_ratio) == HAL_OK)
	{
		startAddress +=4;
	}
	else {
		HAL_FLASH_Lock();
		return;
	}
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, _release_max_oil) == HAL_OK)
	{
		startAddress +=4;
	}
	else {
		HAL_FLASH_Lock();
		return;
	}
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, _max_air) == HAL_OK)
	{
		startAddress +=4;
	}
	else {
		HAL_FLASH_Lock();
		return;
	}
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, _min_air) == HAL_OK)
	{
		startAddress +=4;
	}
	else {
		HAL_FLASH_Lock();
		return;
	}
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, _lose_oil) == HAL_OK)
	{
		startAddress +=4;
	}
	else {
		HAL_FLASH_Lock();
		return;
	}
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, _error_max_cnt) == HAL_OK)
	{
		startAddress +=4;
	}
	else {
		HAL_FLASH_Lock();
		return;
	}
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, _front_air) == HAL_OK)
	{
		startAddress +=4;
	}
	else {
		HAL_FLASH_Lock();
		return;
	}
	if(HAL_FLASH_Program(TYPEPROGRAM_WORD, startAddress, _back_air) == HAL_OK)
	{
		startAddress +=4;
	}
	else {
		HAL_FLASH_Lock();
		return;
	}
    //4����סFLASH
	HAL_FLASH_Lock();
}

//FLASH��ȡ����
void ReadFlash()
{
	startAddress = SN;
	init_code = *(__IO uint32_t*)(startAddress);
	startAddress += 4;
	_oa_ratio = *(__IO uint32_t*)(startAddress);
	startAddress += 4;
	_release_max_oil = *(__IO uint32_t*)(startAddress);
	startAddress += 4;
	_max_air = *(__IO uint32_t*)(startAddress);
	startAddress += 4;
	_min_air = *(__IO uint32_t*)(startAddress);
	startAddress += 4;
	_lose_oil = *(__IO uint32_t*)(startAddress);
	startAddress += 4;
	_error_max_cnt = *(__IO uint32_t*)(startAddress);
	startAddress += 4;
	_front_air = *(__IO uint32_t*)(startAddress);
	startAddress += 4;
	_back_air = *(__IO uint32_t*)(startAddress);
}
uint32_t getFlashInitCode() {
	startAddress = SN;
	return  *(__IO uint32_t*)(startAddress);
}