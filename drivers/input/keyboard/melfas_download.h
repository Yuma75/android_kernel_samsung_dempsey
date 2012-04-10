//------------------------------------------------------------------
#ifndef __MELFAS_FIRMWARE_DOWNLOAD_H__
//============================================================
typedef char				INT8;

#ifndef FALSE
#ifndef NULL
//============================================================

// Selection of i2c function ( This must be 1 )
// Disable downlaoding, if module version does not match.
// If 'enable download command' is needed ( Pinmap dependent option ).
// For printing debug information. ( Please check 'printing function' )
// For delay function test. ( Disable after Porting is finished )

// Set 1 if Enabled.

//----------------
//----------------
//----------------
//----------------

#define TKEY_I2C_SCL_SET_HIGH()					gpio_direction_output(_3_TOUCH_SCL_28V, 1);						//OT_SCL_HIGH()
#define TKEY_I2C_SDA_SET_HIGH()					gpio_direction_output(_3_TOUCH_SDA_28V, 1);						//OT_SDA_HIGH()
#define TKEY_I2C_SCL_SET_OUTPUT()					//s3c_gpio_cfgpin(_3_TOUCH_SCL_28V, GPIO_OUTPUT);					//OT_SCL_SET_OUTPUT()
#define TKEY_I2C_SDA_SET_OUTPUT()					//s3c_gpio_cfgpin(_3_TOUCH_SDA_28V, GPIO_OUTPUT);						//OT_SDA_SET_OUTPUT()

#define TKEY_I2C_SET_LOW()							TKEY_I2C_SCL_SET_LOW();  		\

#define TKEY_I2C_INIT()                     		TKEY_I2C_SET_HIGH();			\
#define TKEY_I2C_CLOSE()                     		TKEY_I2C_SET_LOW();		//		\

#define MCSDL_DELAY_1MS								10
#define MCSDL_DELAY_25MS							25000

#define MELFAS_DISABLE_BASEBAND_ISR()				____HERE!_____				//disable_isr()
#define MELFAS_ROLLBACK_BASEBAND_ISR()				____HERE!_____				//
#else
#define MELFAS_DISABLE_BASEBAND_ISR()											//Nothing
#define MELFAS_ROLLBACK_BASEBAND_ISR()											//Nothing
#endif

#define MELFAS_TRANSFER_LENGTH					64		// Program & Read flash block size

//----------------------------------------------------
#define MCSDL_RET_WRONG_MODE_ERROR				0xF0
//------------------------------
#define MCSDL_MDS_ENTERING_ISP_MODE_ACK_1		0x55
//------------------------------
//------------------------------

#define MCSDL_I2C_SLAVE_ADDR_ORG				0x7E							// Original Address
#define MCSDL_I2C_SLAVE_ADDR_SHIFTED			(MCSDL_I2C_SLAVE_ADDR_ORG<<1)	// Adress after sifting.
#define MCSDL_I2C_SLAVE_READY_STATUS			0x55
#define MCSDL_ISP_PROGRAM_TIMING_VALUE_0		0x00
#define MCSDL_ISP_ERASE_TIMING_VALUE_0			0x01

int mcsdl_download_binary_data(void);			// with binary type .c   file.
#if MELFAS_ENABLE_DELAY_TEST					// For initial porting test.


