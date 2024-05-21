
//1: config ADF7021
//     Please reference ADF7021_Module.h and ADF7021 technical manual for detail config data.

	#ifdef   SEND
		adf7021_register_config_for_send();
	
		// test send
		for(i = 0; i < 10 ; i++)
		{
			adf7021_byte_send( buf_send, 20 );
			{
				delay(); // look for on the oscillograph
			}
		}
	#else
		adf7021_register_config_for_receive( ADF7021_SN1 );
		adf7021_register_config_for_receive( ADF7021_SN2 );
	#endif
	
//2:Enable interrupt

//3:receive data and decode
//  Please reference EXTI9_5_IRQHandler function of in the stm32f10x_it.c
	

//by Planck
//2013.11.29

