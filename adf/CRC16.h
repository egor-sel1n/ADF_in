#ifndef   _CRC16_H_
#define   _CRC16_H_

u16  CRC16_modbus(u8 *puchMsg, u16 usDataLen ) ;
u16  CRC16_2(u8 *puchMsg, u8 usDataLen , u8 *data2 , u8 length2) ;
u16  CRC16_WCT(u8 *puchMsg, u16 usDataLen ) ;

#endif
