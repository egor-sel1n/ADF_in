#include  "main.h"
#include  "ADF7021_Module.h"


static void delay( void )    // Լ2ms��������ʱ��  2009-11-25 18:27:38
{
  u16 i;
  for (i=0; i < 3000; i++);   // ԭ����3000��
}

/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : �������������ײ�Ĳ�������������ADF7021�ĸ��Ĵ���д������
|                   1��ADF7021�ĸ��Ĵ������Ȳ���һ�����˺����ڻ��Զ��趨��Ӧ�ĳ��ȣ���˴���Ĳ���һ��Ϊ32bit����λ���룬��λ�����ԣ�
|                      ʵ�ʲ��Է��֣�Ӧ����ȫ��ͳһ����32bit.  2010-3-1 15:46:38
|                   2���Ĵ�����ַ�Ѿ���ʵ�εĵ���λ���ˣ�������뵥���ļĴ�����Ų�����
| Input          : ��д�ļĴ���ֵ��ADF7021�ı��
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
					GPIO_SetBits( ADF7021_MODULE_CE_M1 );  // 10us �󼴿�����
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_SetBits( ADF7021_MODULE_CE_M2 );  // 10us �󼴿�����
			    break ;

		default:
			    ;
	}

	delay();
	// �������ٵȴ�1ms + 10us ���ȶ�ʱ�䣬�����漰CE�����ȣ��������
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
		//if( ( reg_value & 0x80000000 ) == 0x10000000 )  // �������ȷ������λ,֮ǰ�������䲻�У����¶˿��øߵ����ִ�в��� 2010-3-17 15:26:10
		if( reg_value & 0x80000000 )  // �������ȷ������λ
		{
			GPIO_SetBits( ADF7021_MODULE_SDATA );
		}
			else
			{
				GPIO_ResetBits( ADF7021_MODULE_SDATA );
			}
		
		delay();
		// ����Ҫ��֤ 10ns ����ʱ�󣬲�������ʱ���źŵ�������
		
		GPIO_SetBits( ADF7021_MODULE_SCLK ); delay(); // Ӧ���ٳ���10ns   
		reg_value <<= 1; // ����һλ
		GPIO_ResetBits( ADF7021_MODULE_SCLK );
	}
	delay();
	// ��֤10ns ��ʱ

	switch( SN )
	{
		case  ADF7021_SN1:
					GPIO_SetBits( ADF7021_MODULE_SLE_M1 );    delay(); // �����ڲ��Ĵ�������֤20ns����ʱ
					GPIO_ResetBits( ADF7021_MODULE_SLE_M1 );
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_SetBits( ADF7021_MODULE_SLE_M2 );    delay(); // �����ڲ��Ĵ�������֤20ns����ʱ
					GPIO_ResetBits( ADF7021_MODULE_SLE_M2 );
			    break ;

		default:
			    ;
	}
}


/*------------------------------------------------------------------------------
| Description    : �������������ײ�Ĳ����������Ǵ�ADF7021�ĸ��Ĵ�����������
                   1��ADF7021�ĸ��Ĵ������Ȳ���һ�����˺����ڻ��Զ��趨��Ӧ�ĳ��ȣ���˶���������һ��Ϊ32bit����λ���룬��λ�Զ����㣻
                   2���ƺ�����ÿ���Ĵ��������Զ�����������������ֻ������4��ֵ���μ�P54��˵����
                   3������֤����0x1c7,0x1d7,0x1e7,0x1f7,�����Զ���0x2104����4�������ĸ�����ADF7021��R7�Ĵ���
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
	GPIO_SetBits( ADF7021_MODULE_SDATA );   // ���ܲ���Ҫ


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


	GPIO_ResetBits( ADF7021_MODULE_SREAD );   // �������û��ʵ��ִ�У���Ϊ�ö˿��Ѿ�������Ϊ������  2010-3-12 18:45:23
	
	GPIO_SetBits( ADF7021_MODULE_SCLK );  // ��һ��SCLK������
	delay();  // ��ʵʱ��̣ܶ�10ns����
	GPIO_ResetBits( ADF7021_MODULE_SCLK );
	GPIO_ResetBits( ADF7021_MODULE_SDATA );   // �˺�һֱ���ֵ�
	
	switch( SN )
	{
		case  ADF7021_SN1:
					GPIO_SetBits( ADF7021_MODULE_SLE_M1 );  // ���ָߣ�ֱ��������
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_SetBits( ADF7021_MODULE_SLE_M2 );  // ���ָߣ�ֱ��������
			    break ;

		default:
			    ;
	}

	delay();  // 10ns����
	
	GPIO_SetBits( ADF7021_MODULE_SCLK );  // ���Ժ�ʼ�����½�����Ч   ��ʵ�������غ����ݼ��ͳ�...
	
	for( i = 0; i < 16 ; i++ )
	{
		read_buf <<= 1;
		
		#ifdef  BHS
		temp = GPIO_ReadInputData( GPIOA );
		#else
		temp = GPIO_ReadInputData( ADF7021_MODULE_SREAD_PORT );  // �������˿�16bit
		#endif

		#ifdef  BHS
		if(temp & 0x08 )  // ȡPA3
		#else
		if(temp & ADF7021_MODULE_SREAD_PORT_BIT )  // ȡ PB14
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
					GPIO_ResetBits( ADF7021_MODULE_SLE_M1 );  // ����
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_ResetBits( ADF7021_MODULE_SLE_M2 );  // ����
			    break ;

		default:
			    ;
	}

	GPIO_ResetBits( ADF7021_MODULE_SCLK );
	
	//return ( read_buf & 0xffff );   // ��Ϊ���ǵ��Ĵ��������32bit�ģ���0x2104ʱ��16λ�ģ����Ը�16λ����
	return read_buf;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : �ú�������ͨ��ADF7021��TxRxDATA �� TxRxCLK ��֧���ŷ������ݣ�
|                  �ú����Ĳ������ַ���ָ�룬���ϲ㺯������Ҫ���͵��������ݼ���ʽ���˺���ֻ��������ݷ��ͳ�ȥ
|                  
|                   
| Input          : �����͵�����ָ�뼰Ҫ���͵����ֽ���
| Output         : TxRxDATA ������ TxRxCLK �ṩ��ʱ�ӷ�������
| Return         : ֱ�ӷ��ͣ�û�з���
| Designer       :  xudong  2010.3.11
------------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef  SEND  //����Ƿ��ͷ������������ĺ����������������

static void delay_sim_spi( void )   // ����רΪģ���SPIд����ʱ�������κγ��򶼲�Ӧ�õ��ã�
{
  u16 i;

  #ifdef    BHS
  for (i=0; i < 800; i++);

  #else
  for (i=0; i < 80; i++);  // ��ʹ�� STM32F103C6T6 �ڲ���RC����ʱ�����ã����ֵ�ܹؼ��������������
  
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
		while( ( GPIO_ReadInputData( GPIOA ) & 0x0080 ) == 0x0080 )   ;  // ���PA7���ߵ�ƽ�Ļ������ȴ�

		#else
		while( ( GPIO_ReadInputData( ADF7021_MODULE_DCLK_PORT ) & ADF7021_MODULE_DCLK_PORT_BIT ) == ADF7021_MODULE_DCLK_PORT_BIT ) ;
		                                     // ���PA5���ߵ�ƽ�Ļ������ȴ�
		#endif

		if( ( buf_send & 0x80 ) == 0x80 )
		{
			GPIO_SetBits( ADF7021_MODULE_DATA );    // ���� 1
		}
			else
			{
				GPIO_ResetBits( ADF7021_MODULE_DATA );  // ���� 0
			}
		
		buf_send <<= 1;
		
		if( ( ( i + 1 ) % 8 ) == 0 )  // ���һ���ֽ��Ƿ������
		{
			p++; // ָ���������һ�������͵��ֽ�
			buf_send = *p;  // ���·��ͻ�������
		}
		
		// �����Ѿ��ͳ����ʵ���ʱ���Ծ���ƥ��ʱ���źţ�
		// ֱ����ʱ����һ���ߵ�ƽ�������������õ�����ġ��ߵ�ƽ�ȴ�����ָ������������ʱ�ӵ�ƥ����ƽ��ǳ�����
		// ���ݶ˿���Ҫ��ʱ�ӵ��½��ذ��µ������ͳ���ADF7021����ʱ�ӵ������ز�������
		delay_sim_spi();  // 
	}
}


/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : ���ͷ�ֱ�ӵ��ô˺��������������ADF7021�����ù���
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

	GPIO_SetBits( ADF7021_MODULE_PAC );  // ����ģ�鵽����״̬������ģ�����ӵ�һ�����ƶ�

	buf = R1_VALUE ;
	adf7021_register_write( buf );

	buf = R3_VALUE ;
	adf7021_register_write( buf );

	buf = R0_VALUE ;
	adf7021_register_write( buf );

	buf = R2_VALUE ;
	adf7021_register_write( buf );
	//----  ���￪ʼ����Ƶ�ź����

	buf = R15_VALUE ;
	adf7021_register_write( buf );   // û��ɶ����
}

#endif  // end SEND

/*------------------------------------------------------------------------------------------------------------------------------------------
| Description    : ���շ�ֱ�ӵ��ô˺��������������ADF7021�����ù���
|                  
|
|
| Input          : ģ��ı�ţ�����ֵ�� ADF7021_SN1 ���� ADF7021_SN2
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
					GPIO_SetBits( ADF7021_MODULE_CE_M1 );  // 10us �󼴿�����
			    break ;
			    
		case  ADF7021_SN2:
					GPIO_SetBits( ADF7021_MODULE_CE_M2 );  // 10us �󼴿�����
			    break ;

		default:
			    ;
	}
	delay(); // �ȴ�������ɣ���ʵ�ܿ�ģ����յ��������

	GPIO_ResetBits( ADF7021_MODULE_PAC_M1 );  // ����ģ��ȫ�ǽ��գ���ʱ��������
	GPIO_ResetBits( ADF7021_MODULE_PAC_M2 );

	buf = R1_VALUE ;
	adf7021_register_write( R1_VALUE, SN );  // ��ȷ��ֵ�� 0x575011
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
					adf7021_register_write( 0x95FF380, SN ); /// 433�����ã� 0x95FF380  426�����ã� 0x95A42A0
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
| Description    : ����Ŀһ��ֻ�漰ADF7021�����ݽ���
|                  ���ݽ��ղ���ADF7021��ʱ���ź��������жϵķ�ʽ�������жϺ��������������
|
|
| Input          : 
| Output         : 
| Return         : �޷���
| Designer       : xudong@engineer.com  2010.3.11  ��������ʱ�Է��� stm32f10x_it.c �У���ȥ����鿴
------------------------------------------------------------------------------------------------------------------------------------------*/
