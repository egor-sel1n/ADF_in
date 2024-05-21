#include  "main.h"
#include  "ADF7021_Module.h"


static void delay( void )    // 约2ms不到的延时。  2009-11-25 18:27:38
{
  u16 i;
  for (i=0; i < 3000; i++);   // 原来是3000，
}

/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : 这个函数用于最底层的操作，作用是向ADF7021的各寄存器写入数据
|                   1、ADF7021的各寄存器长度并不一样，此函数内会自动设定对应的长度，因此传入的参数一律为32bit，低位对齐，高位将忽略；
|                      实际测试发现，应该是全部统一发送32bit.  2010-3-1 15:46:38
|                   2、寄存器地址已经在实参的低四位上了，因此无须单独的寄存器序号参数；
| Input          : 待写的寄存器值、ADF7021的编号
| Output         : 
| Return         : 
| Designer       :  xudong  2010.2
------------------------------------------------------------------------------------------------------------------------------------------*/
void adf7021_register_write( u32 reg_value, u8 SN )
{
	u8 i;
	
	switch( SN )
	{
		case  ADF7021_SN1:
					GPIO_SetBits( ADF7021_MODULE_CE_M1 );  // 10us 后即可启动
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_SetBits( ADF7021_MODULE_CE_M2 );  // 10us 后即可启动
			    break ;

		default:
			    ;
	}

	delay();
	// 这里至少等待1ms + 10us 的稳定时间，可能涉及CE启动等，详见资料
	switch( SN )
	{
		case  ADF7021_SN1:
			    GPIO_ResetBits( ADF7021_MODULE_SLE_M1 );
			    break ;
			    
		case  ADF7021_SN2:
			    GPIO_ResetBits( ADF7021_MODULE_SLE_M2 );
			    break ;

		default:
			    ;
	}
	GPIO_ResetBits( ADF7021_MODULE_SCLK );
	
	for( i = 0; i < 32 ; i++ )
	{
		//if( ( reg_value & 0x80000000 ) == 0x10000000 )  // 总是首先发送最高位,之前用这个语句不行，导致端口置高的语句执行不到 2010-3-17 15:26:10
		if( reg_value & 0x80000000 )  // 总是首先发送最高位
		{
			GPIO_SetBits( ADF7021_MODULE_SDATA );
		}
			else
			{
				GPIO_ResetBits( ADF7021_MODULE_SDATA );
			}
		
		delay();
		// 这里要保证 10ns 的延时后，才能有有时钟信号的上升沿
		
		GPIO_SetBits( ADF7021_MODULE_SCLK ); delay(); // 应至少持续10ns   
		reg_value <<= 1; // 左移一位
		GPIO_ResetBits( ADF7021_MODULE_SCLK );
	}
	delay();
	// 保证10ns 延时

	switch( SN )
	{
		case  ADF7021_SN1:
					GPIO_SetBits( ADF7021_MODULE_SLE_M1 );    delay(); // 锁入内部寄存器，保证20ns的延时
					GPIO_ResetBits( ADF7021_MODULE_SLE_M1 );
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_SetBits( ADF7021_MODULE_SLE_M2 );    delay(); // 锁入内部寄存器，保证20ns的延时
					GPIO_ResetBits( ADF7021_MODULE_SLE_M2 );
			    break ;

		default:
			    ;
	}
}


/*------------------------------------------------------------------------------
| Description    : 这个函数用于最底层的操作，作用是从ADF7021的各寄存器读出数据
                   1、ADF7021的各寄存器长度并不一样，此函数内会自动设定对应的长度，因此读出的数据一律为32bit，低位对齐，高位自动补零；
                   2、似乎不是每个寄存器都可以读，初步来看读操作只适用于4个值：参见P54的说明；
                   3、经验证，用0x1c7,0x1d7,0x1e7,0x1f7,均可以读到0x2104，这4个参数的根据是ADF7021的R7寄存器
| Input          : 
| Output         : 
| Return         : 
------------------------------------------------------------------------------*/
u16 adf7021_register_read( u16 readback_mode, u8 SN )
{
	u8 i;
	u16  temp, read_buf = 0;
	
	adf7021_register_write( readback_mode, SN );  // Enable Readback
	
	GPIO_ResetBits( ADF7021_MODULE_SCLK );
	GPIO_SetBits( ADF7021_MODULE_SDATA );   // 可能不需要


	switch( SN )
	{
		case  ADF7021_SN1:
					GPIO_ResetBits( ADF7021_MODULE_SLE_M1 );
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_ResetBits( ADF7021_MODULE_SLE_M2 );
			    break ;

		default:
			    ;
	}


	GPIO_ResetBits( ADF7021_MODULE_SREAD );   // 这个估计没有实际执行，因为该端口已经被设置为了输入  2010-3-12 18:45:23
	
	GPIO_SetBits( ADF7021_MODULE_SCLK );  // 第一个SCLK上升沿
	delay();  // 其实时间很短，10ns即可
	GPIO_ResetBits( ADF7021_MODULE_SCLK );
	GPIO_ResetBits( ADF7021_MODULE_SDATA );   // 此后一直保持低
	
	switch( SN )
	{
		case  ADF7021_SN1:
					GPIO_SetBits( ADF7021_MODULE_SLE_M1 );  // 保持高，直到读结束
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_SetBits( ADF7021_MODULE_SLE_M2 );  // 保持高，直到读结束
			    break ;

		default:
			    ;
	}

	delay();  // 10ns即可
	
	GPIO_SetBits( ADF7021_MODULE_SCLK );  // 这以后开始读，下降沿有效   其实是上升沿后数据即送出...
	
	for( i = 0; i < 16 ; i++ )
	{
		read_buf <<= 1;
		
		#ifdef  BHS
		temp = GPIO_ReadInputData( GPIOA );
		#else
		temp = GPIO_ReadInputData( ADF7021_MODULE_SREAD_PORT );  // 读整个端口16bit
		#endif

		#ifdef  BHS
		if(temp & 0x08 )  // 取PA3
		#else
		if(temp & ADF7021_MODULE_SREAD_PORT_BIT )  // 取 PB14
		#endif
		{
			read_buf |= 0x01;
		}
		
		GPIO_ResetBits( ADF7021_MODULE_SCLK );
		delay();
		GPIO_SetBits( ADF7021_MODULE_SCLK );
	}
	
	switch( SN )
	{
		case  ADF7021_SN1:
					GPIO_ResetBits( ADF7021_MODULE_SLE_M1 );  // 结束
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_ResetBits( ADF7021_MODULE_SLE_M2 );  // 结束
			    break ;

		default:
			    ;
	}

	GPIO_ResetBits( ADF7021_MODULE_SCLK );
	
	//return ( read_buf & 0xffff );   // 因为考虑到寄存器最多是32bit的，读0x2104时是16位的，所以高16位清零
	return read_buf;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : 该函数用于通过ADF7021的TxRxDATA 及 TxRxCLK 两支引脚发送数据，
|                  该函数的参数是字符型指针，由上层函数决定要发送的数据内容及格式，此函数只负责把数据发送出去
|                  
|                   
| Input          : 待发送的数据指针及要发送的总字节数
| Output         : TxRxDATA 将根据 TxRxCLK 提供的时钟发送数据
| Return         : 直接发送，没有返回
| Designer       :  xudong  2010.3.11
------------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef  SEND  //如果是发送方，则编译下面的函数，否则无须理睬

static void delay_sim_spi( void )   // 这是专为模拟从SPI写的延时函数，任何程序都不应该调用；
{
  u16 i;

  #ifdef    BHS
  for (i=0; i < 800; i++);

  #else
  for (i=0; i < 80; i++);  // 当使用 STM32F103C6T6 内部的RC振荡器时的设置，这个值很关键，不可随意更改
  
  #endif
}

void  adf7021_byte_send( u8  *p , u8 length)
{
	u8 buf_send ;
	u16 i;
	
	buf_send = *p;
	
	for( i = 0 ; i < ( length * 8 ) ; i++ )
	{
		#ifdef  BHS
		while( ( GPIO_ReadInputData( GPIOA ) & 0x0080 ) == 0x0080 )   ;  // 检测PA7，高电平的话继续等待

		#else
		while( ( GPIO_ReadInputData( ADF7021_MODULE_DCLK_PORT ) & ADF7021_MODULE_DCLK_PORT_BIT ) == ADF7021_MODULE_DCLK_PORT_BIT ) ;
		                                     // 检测PA5，高电平的话继续等待
		#endif

		if( ( buf_send & 0x80 ) == 0x80 )
		{
			GPIO_SetBits( ADF7021_MODULE_DATA );    // 发送 1
		}
			else
			{
				GPIO_ResetBits( ADF7021_MODULE_DATA );  // 发送 0
			}
		
		buf_send <<= 1;
		
		if( ( ( i + 1 ) % 8 ) == 0 )  // 检测一个字节是否发送完毕
		{
			p++; // 指针调整到下一个待发送的字节
			buf_send = *p;  // 更新发送缓存数据
		}
		
		// 数据已经送出，适当延时，以尽量匹配时钟信号，
		// 直接延时到下一个高电平，这样可以利用到上面的“高电平等待”的指令，这样处理后与时钟的匹配估计将非常完美
		// 数据端口需要在时钟的下降沿把新的数据送出，ADF7021将在时钟的上升沿采样数据
		delay_sim_spi();  // 
	}
}


/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : 发送方直接调用此函数即可完成所有ADF7021的配置工作
|                  
|
|
| Input          : 
| Output         : 
| Return         : 
| Designer       : xudong  2010.3.11
------------------------------------------------------------------------------------------------------------------------------------------*/
void adf7021_register_config_for_send( void )
{
	u32 buf ;

	GPIO_SetBits( ADF7021_MODULE_PAC );  // 设置模块到发送状态，这是模块增加的一个控制端

	buf = R1_VALUE ;
	adf7021_register_write( buf );

	buf = R3_VALUE ;
	adf7021_register_write( buf );

	buf = R0_VALUE ;
	adf7021_register_write( buf );

	buf = R2_VALUE ;
	adf7021_register_write( buf );
	//----  这里开始有射频信号输出

	buf = R15_VALUE ;
	adf7021_register_write( buf );   // 没起到啥作用
}

#endif  // end SEND

/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : 接收方直接调用此函数即可完成所有ADF7021的配置工作
|                  
|
|
| Input          : 模块的编号，可能值是 ADF7021_SN1 或者 ADF7021_SN2
| Output         : 
| Return         : NONE
| Designer       : xudong  2010.3.11
------------------------------------------------------------------------------------------------------------------------------------------*/
void adf7021_register_config_for_receive( u8 SN )
{
	u32 buf ;
	
	switch( SN )
	{
		case  ADF7021_SN1:
					GPIO_SetBits( ADF7021_MODULE_CE_M1 );  // 10us 后即可启动
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_SetBits( ADF7021_MODULE_CE_M2 );  // 10us 后即可启动
			    break ;

		default:
			    ;
	}
	delay(); // 等待启动完成，其实很快的，保险点吧先这样

	GPIO_ResetBits( ADF7021_MODULE_PAC_M1 );  // 两个模块全是接收，暂时这样处理
	GPIO_ResetBits( ADF7021_MODULE_PAC_M2 );

	buf = R1_VALUE ;
	adf7021_register_write( R1_VALUE, SN );  // 正确的值： 0x575011
	//adf7021_register_write( 0x85D082 );

	#ifdef  BPS9600
	adf7021_register_write( 0x2B144123, SN );
	#endif
	
	#ifdef  BPS4800
	adf7021_register_write( 0x2B148123, SN );
	#endif
	
	adf7021_register_write( 0x00003155, SN );
	
	delay();
	delay();
	delay();
	delay();

	buf = R11_VALUE ;
	adf7021_register_write( buf, SN );

	buf = R12_VALUE ;
	adf7021_register_write( buf, SN );

	switch( SN )
	{
		case  ADF7021_SN1:
					adf7021_register_write( 0x9597280, SN );
			    break ;
			    
		case  ADF7021_SN2:
					//buf = R0_VALUE ;
					adf7021_register_write( 0x95FF380, SN ); /// 433的配置： 0x95FF380  426的配置： 0x95A42A0
			    break ;

		default:
			    ;
	}
	delay();
	
	#ifdef   BPS9600
	adf7021_register_write( 0x80A00004, SN );
	#endif
	
	#ifdef   BPS4800
	adf7021_register_write( 0x80500004, SN );
	#endif

}

/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : 本项目一般只涉及ADF7021的数据接收
|                  数据接收采用ADF7021的时钟信号上升沿中断的方式，进入中断后必须立即读数据
|
|
| Input          : 
| Output         : 
| Return         : 无返回
| Designer       : xudong@engineer.com  2010.3.11  本函数暂时仍放在 stm32f10x_it.c 中，请去那里查看
------------------------------------------------------------------------------------------------------------------------------------------*/
