/*------------------------------------------------------------------------------------------------------------------------------------------
  Description : ����ADF7021�ļĴ����쳣���Ҹ��ӣ���������һ�����ñ�ֻҪ�����Ӧ���������ݣ����ɺϲ������յļĴ������ã��򵥷����ֱ�ۣ�
                ������ɺܺõ�Ӧ����STM32ƽ̨������λ������ֱ�ӵ���CMSIS�ı�׼�������磺
                GPIO_SetBits( ADF7021_MODULE_CE_M1 );
                GPIO_ResetBits( ADF7021_MODULE_PAC_M2 );
                ��ԭϵͳ������ADF7021������������M1��M2��׺��Ϊ����
                ������ʱֻ�ṩ���ͷ�ļ�������֮�����������������Ȥ���ṩ���ú����Թ��˴˲ο���
  Designer    : xudong  2010.2
                cnchip@163.com
                xudong@mail.com
------------------------------------------------------------------------------------------------------------------------------------------*/

#ifndef   _ADF7021_Module_H_
#define   _ADF7021_Module_H_

//---------------------------------------------------------------------------------------------------------------------------
//#define  BPS9600
//#define  BPS4800  // ������ղ����ʣ���������ʱ�õ��Ƕ˿��жϽ��գ��൱�����ģ��Ӳ���ӿڣ�������� ADF7021_Module.c ��Ҫ�õ�
//---------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//    �������и�ADF7021ģ����ص�Ӳ���ӿ�
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//#ifdef   BHS   // ������BHS�Ŀ������ϵ���ʱ��Ӳ����������

#define  ADF7021_MODULE_CE      GPIOB, GPIO_Pin_9
#define  ADF7021_MODULE_SLE     GPIOB, GPIO_Pin_8
#define  ADF7021_MODULE_SDATA   GPIOB, GPIO_Pin_5
#define  ADF7021_MODULE_SREAD   GPIOB, GPIO_Pin_4
#define  ADF7021_MODULE_SCLK    GPIOB, GPIO_Pin_3
//#define  ADF7021_MODULE_PAC     GPIOA, GPIO_Pin_5   // ģ���PAC��

//#define  ADF7021_MODULE_DATA    GPIOA, GPIO_Pin_6
//#define  ADF7021_MODULE_DCLK    GPIOA, GPIO_Pin_7



#else   // ����ʵ�ʲ�Ʒʱ��Ӳ������


//#define  ADF7021_MODULE_PAC     GPIOB, GPIO_Pin_12 // M1 ģ���PAC��
//#define  ADF7021_MODULE_PAC_M2     GPIOB, GPIO_Pin_2    // M2 ģ���PAC��

//#define  ADF7021_MODULE_CE      GPIOB, GPIO_Pin_1   // M1 ģ���CE��
//#define  ADF7021_MODULE_CE_M2      GPIOB, GPIO_Pin_0   // M2 ģ���CE��

/*
#define  ADF7021_MODULE_SDATA   GPIOB, GPIO_Pin_15
#define  ADF7021_MODULE_SREAD   GPIOB, GPIO_Pin_14
#define  ADF7021_MODULE_SREAD_PORT  GPIOB           // �Ժ��Ϊ���ƽṹ�Ķ��壬��ʼ�ĳ�����û��ͳһ���壬��Ϊ�ǡ������˿ڣ�ûע���������
#define  ADF7021_MODULE_SREAD_PORT_BIT  0x4000      // 2010-3-12 18:56:45
#define  ADF7021_MODULE_SCLK    GPIOB, GPIO_Pin_13
*/

//#define  ADF7021_MODULE_SLE_M1     GPIOB, GPIO_Pin_6  // ģ�� M1 ��SLE
//#define  ADF7021_MODULE_SLE_M2     GPIOB, GPIO_Pin_5  // ģ�� M2 ��SLE

/*
#define  ADF7021_MODULE_M1_DATA           GPIOA, GPIO_Pin_7   // M1 ģ����Ƶ������������
#define  ADF7021_MODULE_M1_DATA_PORT      GPIOA   // ����Ҫ�����ڶ�ȡʱ����϶�����ʹ��
#define  ADF7021_MODULE_M1_DATA_PORT_BIT  0x0080

#define  ADF7021_MODULE_M2_DATA           GPIOB, GPIO_Pin_11  // M2 ģ����Ƶ������������
#define  ADF7021_MODULE_M2_DATA_PORT      GPIOB   // ����Ҫ�����ڶ�ȡʱ����϶�����ʹ��
#define  ADF7021_MODULE_M2_DATA_PORT_BIT  0x0800
*/



/*
#define  ADF7021_MODULE_DCLK    GPIOA, GPIO_Pin_5  // ���ݵ�ʱ���ߣ�����MCU
#define  ADF7021_MODULE_DCLK_PORT  GPIOA
#define  ADF7021_MODULE_DCLK_PORT_BIT  0x0020

#define  ADF7021_MODULE_M1    EXTI_Line5   // ģ��M1������ʱ���������ţ��������жϣ��ٷ�ԭ�Ƿ��� platform_config.h �еġ�
#define  ADF7021_MODULE_M2    EXTI_Line6   // ģ��M2....  
*/


//#endif   // end BHS

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------






//--------------------- ADF7021 �Ĵ������ñ� ---------------------
// �����ԡ�ADF7021_REGx����ͷ�ģ�������ADF7021��Ӳ���Ĵ�����������صģ��ڳ����п�����Ҫд��7021�Ĵ�����

#define  XTAL_OR_TCXO_FREQUENCY      19.68   // ADF7021��Χ��ʯӢ����Ƶ��,��λ: MHz

//-- REG0
#define  ADF7021_REG0_MUXOUT              0  // R0_DB[31:29],��Χ 0 - 7
#define  ADF7021_REG0_UART_MODE           0  // R0_DB28��1:������UARTģʽ������� SPI ģʽ��Ҫ����R15[19:17]
                                             // datasheet�ϵ�˵���ƺ����󣬴���һ��ȷ��   2010-3-9 17:17:28
#define  ADF7021_REG0_TX_RX               1  // R0_DB27, 0:����ģʽ��1������ģʽ
#define  ADF7021_REG0_INTEGER_N          43  // R0_DB[26:19],��Χ 23 - 255  ����N COUNTER DIVIDE RATIO,���Ӱ����ƵƵ��
#define  ADF7021_REG0_FRACTIONAL_N      9258  // R0_DB[18:4], ��Χ 0 - 32767 ���ڷ���Ƶ��΢��


//-- REG1
#define  ADF7021_REG1_VCO_INDUCTOR        0  // R1_DB25  0���ڲ�VCO  1���ⲿVCO
#define  ADF7021_REG1_VCO_INDUCTOR_OFFSET 25

#define  ADF7021_REG1_VCO_CENTER_FREQ_ADJUST  0 // R1_DB[24:23]
#define  ADF7021_REG1_VCO_CENTER_FREQ_ADJUST_OFFSET 23

#define  ADF7021_REG1_VCO_BIAS           10  // R1_DB[22:19],��Χ 1 - 15,  VCO ƫ�õ���
                                             // ������˵ʹ���ڲ�VCOʱ������Ҫ���õ�0x8,����ʵ�ʲ��Է���7Ҳ���ԣ�������ʱƵ��ƫ�ƺܴ�

#define  ADF7021_REG1_RF_DIVIDE_BY_2      1  // R1_DB18  ֻ����1 ���� 0, ��Ӱ�쵽��Ƶ����Ƶ�ʣ��μ�����Ƶ�ʵ���ع�ʽ
#define  ADF7021_REG1_RF_DIVIDE_BY_2_OFFSET  18

#define  ADF7021_REG1_VCO_ENABLE          1  // R1_DB17  1:ʹ��VCO  0���ر�VCO
#define  ADF7021_REG1_VCO_ENABLE_OFFSET   17

#define  ADF7021_REG1_CP_CURRENT          2  // R1_DB[16:15], ��Χ 0 - 3��

#define  ADF7021_REG1_XTAL_BIAS           2  // R1_DB[14:13] ��Χ 0 - 3 �������𵴵�·��ƫ�õ������ã���ֵӰ���ϵ������ٶ�
#define  ADF7021_REG1_XTAL_BIAS_OFFSET    13

#define  ADF7021_REG1_OSC_ENABLE          1  // R1_DB12  ���ƾ��������Ŀ���
#define  ADF7021_REG1_OSC_ENABLE_OFFSET   12
                                             // ʵ�ʲ��Է��֣����ⲿʱ��ʱ���Ѵ�λ��0�������ܹر����Ƶ�ʣ����Ƿ���Ƶ�ʱ仯�ˣ�
                                             // ������433MHz��Ƶ�ʣ���Ϊ395MHz��
                                             // datasheet���Ѿ���ȷ˵����ʹ���ⲿʱ�ӣ���λҲ������1

#define  ADF7021_REG1_XTAL_DOUBLER         0  // R1_DB11  ֻ����1��������0  ����Ҳ��Ӱ�췢��Ƶ��
#define  ADF7021_REG1_XTAL_DOUBLER_OFFSET  11

#define  ADF7021_REG1_CLKOUT_DIVIDE        0  // R1_DB[10:7] ��Χ��0 - 15  ʵ�ʷ�Ƶϵ���� 0 - 30, 0�ǹرգ��ϵ縴λ��8�����ź�һ�㲻��
#define  ADF7021_REG1_CLKOUT_DIVIDE_OFFSET 7

#define  ADF7021_REG1_R_COUNTER            1  // R1_BD[6:4] ��Χ��1 - 7 �ϵ��ϵͳĬ����1�������7�����ս�Ӱ�쵽����Ƶ��
#define  ADF7021_REG1_R_COUNTER_OFFSET     4


//-- REG2
#define  ADF7021_REG2_TX_FREQUENCY_DEVIATION  32  // R2_DB[27:19] ����Χ��0 - 511  ���� FSK ����ƫ��Ƶ��
#define  ADF7021_REG2_TX_FREQUENCY_DEVIATION_OFFSET  19

#define  ADF7021_REG2_PA_LEVEL           63  // R2_DB[18:13],����������ʵģ���Чֵ�� 0 -63
#define  ADF7021_REG2_PA_LEVEL_OFFSET    13

#define  ADF7021_REG2_PA_BIAS             2

#define  ADF7021_REG2_PA_RAMP_RATE        5  // Ӧ�ò�Ӱ��ģ�������Ҫ��EMC
#define  ADF7021_REG2_PA_RAMP_RATE_OFFSET 8

#define  ADF7021_REG2_POWER_AMP_ON        1  // R2_DB[7],  ���ƹ����Ƿ��

#define  ADF7021_REG2_MODULATION_SCHEME   0  // R2_DB[6:4], ���õ���ģʽ
#define  ADF7021_REG2_MODULATION_SCHEME_OFFSET 4

//-- REG3
#define  ADF7021_REG3_AGC_CLK_DIVIDE      2   // R3_DB[31:26], ��Χ1 - 127,  datasheet�Ƽ�ֵ��10
#define  ADF7021_REG3_SEQUENCER_CLK_DIVIDE   197  // R3_DB[25:18] ,��Χ��1 - 255
#define  ADF7021_REG3_CDR_CLK_DIVIDE         64  // R3_DB[17:10], ��Χ��1 - 255  ���÷���ʱ�ӷ�Ƶϵ����
#define  ADF7021_REG3_CDR_CLK_DIVIDE_OFFSET   10
#define  ADF7021_REG3_DEMOD_CLK_DIVIDE        1   // R3_DB[9:6]����Χ��1 - 15  ���÷���ʱ�ӷ�Ƶϵ����
#define  ADF7021_REG3_DEMOD_CLK_DIVIDE_OFFSET  6


//-- REG11
#define  ADF7021_REG11_SYNC_BYTE_SEQUENCE          0x123456   // R11_DB[31:8],����ͬ���֣��������ֽ�
#define  ADF7021_REG11_SYNC_BYTE_SEQUENCE_OFFSET   8

#define  ADF7021_REG11_MATCHING_TOLERANCE          0          // R11_DB[7:6],��Χ 0 - 3
#define  ADF7021_REG11_MATCHING_TOLERANCE_OFFSET   6

#define  ADF7021_REG11_SYNC_BYTE_LENGTH            3          // R11_DB[5:4],��Χ 0 - 3 ������ͬ���ֵĳ���
#define  ADF7021_REG11_SYNC_BYTE_LENGTH_OFFSET     4


//-- REG12
#define  ADF7021_REG12_DATA_PACKET_LENGTH         1  // R12_DB[15:8],��Χ��1 - 255,����Ϊ0��Ч
#define  ADF7021_REG12_DATA_PACKET_LENGTH_OFFSET  8

#define  ADF7021_REG12_SWD_MODE          0              // R12_DB[7:6] ����Χ��0 - 3 ����SWD���ŵ�����ź�ģʽ
#define  ADF7021_REG12_SWD_MODE_OFFSET   6

#define  ADF7021_REG12_LOCK_THRESHOLD_MODE          0
#define  ADF7021_REG12_LOCK_THRESHOLD_MODE_OFFSET   4


//-- REG15
#define  ADF7021_REG15_CLK_MUX            7  // R15_DB[19:17] �������SPIģʽ�շ����ݣ���������Ϊ7,UARTģʽʱ����Ҫ���� 0���ǹر����
                                             // ʵ�ʲ���ʱ������д0�����ܹر����ʱ��
#define  ADF7021_REG15_CLK_MUX_OFFSET     17


//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
/*  ���мĴ��������ԼĴ�����ַΪ�����������ã���λȫ��0��Ҳ�����мĴ��������ñ�������д��  */
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
#define  R0_VALUE    ( \
                         0  \
                          | ( ADF7021_REG0_MUXOUT       << 29 ) \
                          | ( ADF7021_REG0_UART_MODE    << 28 ) \
                          | ( ADF7021_REG0_TX_RX        << 27 ) \
                          | ( ADF7021_REG0_INTEGER_N    << 19 ) \
                          | ( ADF7021_REG0_FRACTIONAL_N << 4  ) \
                     )

#define  R1_VALUE    ( \
	                       1 \
	                       | ( ADF7021_REG1_VCO_INDUCTOR   << ADF7021_REG1_VCO_INDUCTOR_OFFSET ) \
	                       | ( ADF7021_REG1_VCO_CENTER_FREQ_ADJUST << ADF7021_REG1_VCO_CENTER_FREQ_ADJUST_OFFSET ) \
	                       | ( ADF7021_REG1_VCO_BIAS       << 19 ) \
	                       | ( ADF7021_REG1_RF_DIVIDE_BY_2 << ADF7021_REG1_RF_DIVIDE_BY_2_OFFSET ) \
	                       | ( ADF7021_REG1_VCO_ENABLE     << ADF7021_REG1_VCO_ENABLE_OFFSET ) \
	                       | ( ADF7021_REG1_CP_CURRENT     << 15 ) \
	                       | ( ADF7021_REG1_XTAL_BIAS      << ADF7021_REG1_XTAL_BIAS_OFFSET ) \
	                       | ( ADF7021_REG1_OSC_ENABLE     << ADF7021_REG1_OSC_ENABLE_OFFSET ) \
	                       | ( ADF7021_REG1_XTAL_DOUBLER   << ADF7021_REG1_XTAL_DOUBLER_OFFSET ) \
	                       | ( ADF7021_REG1_CLKOUT_DIVIDE  << ADF7021_REG1_CLKOUT_DIVIDE_OFFSET ) \
	                       | ( ADF7021_REG1_R_COUNTER      << ADF7021_REG1_R_COUNTER_OFFSET ) \
                      )

#define  R2_VALUE    ( \
	                      2 \
                        | ( ADF7021_REG2_TX_FREQUENCY_DEVIATION << ADF7021_REG2_TX_FREQUENCY_DEVIATION_OFFSET ) \
                        | ( ADF7021_REG2_PA_LEVEL     << ADF7021_REG2_PA_LEVEL_OFFSET ) \
                        | ( ADF7021_REG2_PA_BIAS      << 11 ) \
                        | ( ADF7021_REG2_PA_RAMP_RATE << ADF7021_REG2_PA_RAMP_RATE_OFFSET  ) \
                        | ( ADF7021_REG2_POWER_AMP_ON << 7  ) \
                        | ( ADF7021_REG2_MODULATION_SCHEME << ADF7021_REG2_MODULATION_SCHEME_OFFSET ) \
                      )

#define  R3_VALUE    ( \
                         3 \
                         | ( ADF7021_REG3_AGC_CLK_DIVIDE       << 26 ) \
                         | ( ADF7021_REG3_SEQUENCER_CLK_DIVIDE << 18 ) \
                         | ( ADF7021_REG3_CDR_CLK_DIVIDE       << ADF7021_REG3_CDR_CLK_DIVIDE_OFFSET ) \
                         | ( ADF7021_REG3_DEMOD_CLK_DIVIDE     << ADF7021_REG3_DEMOD_CLK_DIVIDE_OFFSET ) \
                      )

#define  R11_VALUE    ( \
                        11 \
                        | ( ADF7021_REG11_SYNC_BYTE_SEQUENCE << ADF7021_REG11_SYNC_BYTE_SEQUENCE_OFFSET ) \
                        | ( ADF7021_REG11_MATCHING_TOLERANCE << ADF7021_REG11_MATCHING_TOLERANCE_OFFSET ) \
                        | ( ADF7021_REG11_SYNC_BYTE_LENGTH   << ADF7021_REG11_SYNC_BYTE_LENGTH_OFFSET   ) \
                      )

#define  R12_VALUE    ( \
                        12 \
                        | ( ADF7021_REG12_DATA_PACKET_LENGTH  << ADF7021_REG12_DATA_PACKET_LENGTH_OFFSET  ) \
                        | ( ADF7021_REG12_SWD_MODE            << ADF7021_REG12_SWD_MODE_OFFSET            ) \
                        | ( ADF7021_REG12_LOCK_THRESHOLD_MODE << ADF7021_REG12_LOCK_THRESHOLD_MODE_OFFSET ) \
                      )

#define  R15_VALUE    ( \
                        15 \
                        + ( ADF7021_REG15_CLK_MUX << ADF7021_REG15_CLK_MUX_OFFSET ) \
		                  )



//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//---------------------  ���������Ƶ�ʼ��㹫ʽ����������ʾʱʹ�ã�һ���ò��� ---------------------
//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
#if    ( ADF7021_REG1_XTAL_DOUBLER == 0 )
#define  PFD   (      XTAL_OR_TCXO_FREQUENCY / ADF7021_REG1_R_COUNTER )
#elif  ( ADF7021_REG1_XTAL_DOUBLER == 1 )
#define  PFD   (  2 * XTAL_OR_TCXO_FREQUENCY / ADF7021_REG1_R_COUNTER )
#endif

// ���¼���� RFOUT_FREQUENCY ����λ�� MHz
#if    ( ADF7021_REG1_RF_DIVIDE_BY_2 == 0 )
#define RFOUT_FREQUENCY                  (        PFD * ( ADF7021_REG0_INTEGER_N + ADF7021_REG0_FRACTIONAL_N / pow(2,15) ) )

#elif  ( ADF7021_REG1_RF_DIVIDE_BY_2 == 1 )
#define RFOUT_FREQUENCY                  (  0.5 * PFD * ( ADF7021_REG0_INTEGER_N + ADF7021_REG0_FRACTIONAL_N / pow(2,15) ) )
#endif
//---------------------------------------------------------------------------------------------------------

//---------------------  �������ݶ˿�ʱ��Ƶ�ʣ���SPIʱ��Ƶ�ʣ�  ---------------------
// ���¼���� DATA_CLK ����λ�� Hz  (��Ҫ���볣�õ�bps�������Ǻϣ������ϸ��Ĺ�ʽû�г��� pow(10,6) ���ϵ����Ӧ��û��Ӱ��
#define   DATA_CLK         ( pow(10,6) * XTAL_OR_TCXO_FREQUENCY / ( ADF7021_REG3_CDR_CLK_DIVIDE * ADF7021_REG3_DEMOD_CLK_DIVIDE * 32 ) )

//---------------------  ����FSK����Ƶ��ƫ�� ---------------------
//--- ���¼���� FDEV ��λ�� kHz �����й�ʽ���Ѿ�����˳�1000��ϵ�����Է���鿴
#if       ( ADF7021_REG1_RF_DIVIDE_BY_2 == 0 )
#define   FDEV    ( (       pow(10,3) * PFD * ADF7021_REG2_TX_FREQUENCY_DEVIATION )/ pow(2,16) )

#elif     ( ADF7021_REG1_RF_DIVIDE_BY_2 == 1 )
#define   FDEV    ( ( 0.5 * pow(10,3) * PFD * ADF7021_REG2_TX_FREQUENCY_DEVIATION )/ pow(2,16) )
#endif



//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------




//--------------------- �����Ǻ������� ---------------------
void adf7021_register_write( u32 reg_value, u8 SN );
u16 adf7021_register_read( u16 readback_mode, u8 SN );
void  adf7021_byte_send( u8  *p , u8 length);
void adf7021_register_config_for_send( void );
void adf7021_register_config_for_receive( u8 );

#endif   // end  _ADF7021_Module_H_
