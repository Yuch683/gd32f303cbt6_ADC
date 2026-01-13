#include "SPI.h"

void SPI_Init()
{
	spi_parameter_struct SPI1_Init_Struct;
	
	rcu_periph_clock_enable(RCU_AF);
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_SPI0);
	
	SPI1_Init_Struct.device_mode											= SPI_MASTER;
  SPI1_Init_Struct.trans_mode												= SPI_TRANSMODE_FULLDUPLEX;
  SPI1_Init_Struct.frame_size 											= SPI_FRAMESIZE_8BIT;
  SPI1_Init_Struct.nss                     	        = SPI_NSS_SOFT;
  SPI1_Init_Struct.endian	                          = SPI_ENDIAN_MSB;
  SPI1_Init_Struct.clock_polarity_phase	            = SPI_CK_PL_LOW_PH_1EDGE;
  SPI1_Init_Struct.prescale	  											= SPI_PSC_256;
	
	spi_init(SPI0, &SPI1_Init_Struct);
	spi_enable(SPI0);/*-Ê¹ÄÜSPI0-*/

}
