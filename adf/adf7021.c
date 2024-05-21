void ADF_WriteReg(uint32_t val)
{
	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
	HAL_Delay(0);

	HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
	HAL_Delay(0);

	for(uint8_t i=0; i<32; i++)
	{
		HAL_GPIO_WritePin(SDATA_GPIO_Port, SDATA_Pin, (val>>(31-i))&1);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
	}

	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 1);
	HAL_GPIO_WritePin(TEST2_GPIO_Port, TEST2_Pin, 1);
	for(uint16_t i=0; i<100; i++)
		asm("NOP");
	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
	HAL_GPIO_WritePin(TEST2_GPIO_Port, TEST2_Pin, 0);
	for(uint16_t i=0; i<100; i++)
		asm("NOP");
}

void ADF_SetFreq(uint32_t freq, uint8_t rx)
{
	uint8_t i=0;
	uint16_t f=0;

	if(rx)
		freq-=100000;	//IF correction

	i=freq/(12288000/(3*2));
	f=10*(freq-i*(12288000/(3*2)))/625;

	ADF_WriteReg((i<<19)|(f<<4)|(rx<<27));
}

float ADF_GetRSSI(void)
{
	uint32_t val=0x147;
	uint16_t rv=0;

	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
	HAL_Delay(0);

	HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
	HAL_Delay(0);

	for(uint8_t i=0; i<9; i++)
	{
		HAL_GPIO_WritePin(SDATA_GPIO_Port, SDATA_Pin, (val>>(8-i))&1);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
	}

	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 1);
	for(uint16_t i=0; i<100; i++)
		asm("NOP");

	//readback
	for(uint8_t i=0; i<16+1; i++)
	{
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");

		if(i)
		{
			rv|=((((SREAD_GPIO_Port->IDR)>>7)&1)<<(16-i));
		}

		for(uint16_t i=0; i<100; i++)
			asm("NOP");
	}

	HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
	for(uint16_t i=0; i<100; i++)
		asm("NOP");
	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
	for(uint16_t i=0; i<100; i++)
		asm("NOP");
	HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);

	uint8_t lna_gain=(rv>>9)&3;
	uint8_t filter_gain=(rv>>7)&3;
	uint8_t rdb=rv&0x7F;
	float gain_corr=0.0;

	if(lna_gain==2 && filter_gain==2)
		gain_corr=0.0;
	else if(lna_gain==1)
	{
		if(filter_gain==2)
			gain_corr=24.0;
		else if(filter_gain==1)
			gain_corr=38.0;
		else
			gain_corr=58.0;
	}
	else if(lna_gain==0 && filter_gain==0)
		gain_corr=86.0;

	return -130.0+((float)rdb+gain_corr)/2.0;
}

uint16_t ADF_GetChipVersion(void)
{
	uint32_t val=0x1C7;
	uint16_t rv=0;

	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
	HAL_Delay(0);

	HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
	HAL_Delay(0);

	for(uint8_t i=0; i<9; i++)
	{
		HAL_GPIO_WritePin(SDATA_GPIO_Port, SDATA_Pin, (val>>(8-i))&1);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
	}

	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 1);
	for(uint16_t i=0; i<100; i++)
		asm("NOP");

	//readback
	for(uint8_t i=0; i<16+1; i++)
	{
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);
		for(uint16_t i=0; i<100; i++)
			asm("NOP");

		if(i)
		{
			rv|=((((SREAD_GPIO_Port->IDR)>>7)&1)<<(16-i));
		}

		for(uint16_t i=0; i<100; i++)
			asm("NOP");
	}

	HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 1);
	for(uint16_t i=0; i<100; i++)
		asm("NOP");
	HAL_GPIO_WritePin(SLE_GPIO_Port, SLE_Pin, 0);
	for(uint16_t i=0; i<100; i++)
		asm("NOP");
	HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, 0);

	return rv;
}

//example ADF7021 init
HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 0);
HAL_Delay(100);
HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, 1);

HAL_Delay(100);
chip_rev=ADF_GetChipVersion();
if(chip_rev==0x2104)	//OK?
	HAL_GPIO_WritePin(COS_GPIO_Port, COS_Pin, 1);

ADF_WriteReg((uint32_t)0x0003B|((uint32_t)0x3243<<8));	//SWD (0x3B) syncword: 0x3243
HAL_Delay(2-1);
ADF_WriteReg((uint32_t)0x0010C|(uint32_t)1<<8);			//DPL (0x10C)
HAL_Delay(2-1);
ADF_WriteReg((uint32_t)0x5770B4); //0x5770B4
HAL_Delay(2-1);
ADF_WriteReg((uint32_t)0x01ED5);	//coarse cal ON
HAL_Delay(2-1);
ADF_WriteReg((uint32_t)0x505EBA6|(uint32_t)1<<4);			//0x505EBA6
HAL_Delay(10-1);
//((uint32_t)0x007);
//HAL_Delay(2-1);
//ADF_WriteReg((uint32_t)0x0008);
//HAL_Delay(2-1);
ADF_WriteReg((uint32_t)0x9|(uint32_t)40<<4|(uint32_t)70<<11);//|((uint32_t)1<<18)|((uint32_t)2<<20)|((uint32_t)2<<22)); //manual gain - max
HAL_Delay(2-1);
ADF_WriteReg((uint32_t)0x3296556B);
HAL_Delay(2-1);
ADF_WriteReg((uint32_t)0x003BD);

ADF_WriteReg((uint32_t)0x475031);
HAL_Delay(2-1);

ADF_WriteReg((uint32_t)0x29ECA093);	//CDR=40
//ADF_WriteReg((uint32_t)(0x29ECA093&(~(0xFF<<10)))|1<<10);	//CDR=1 for DAC test
HAL_Delay(2-1);

//ADF_SetFreq(439425000, 1);	//SR5ND
//ADF_SetFreq(439350000, 1);	//SR5WA
//ADF_SetFreq(438625000, 1);	//SR5WP
//ADF_SetFreq(439000000, 1);	//SR5WZ
//ADF_SetFreq(439075000, 0);	//SR5MS
ADF_SetFreq(439075000, 0);
//ADF_WriteReg(((uint32_t)212<<19)|((uint32_t)13184<<4));
//ADF_WriteReg(((uint32_t)177<<19)|((uint32_t)64<<4));
HAL_Delay(2-1);

uint8_t pwr=63;	//1=-16dBm, 63=+13dBm
ADF_WriteReg((uint32_t)0x00D018B2|(0<<30)|(pwr<<13));	//4FSK raw
//ADF_WriteReg((uint32_t)0x00D018F2|(0<<30)|(pwr<<13));	//4FSK + RC filter
HAL_Delay(2-1);

ADF_WriteReg((uint32_t)0x0000000F|(1<<8));	//1:TX carrier, 2:+f_i, 3:-f_i
//ADF_WriteReg((uint32_t)(14|(1<<4)|(0<<21)));	//test DAC EN, no DAC gain