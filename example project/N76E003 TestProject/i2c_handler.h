/*
	i2c Handler for Nuvoton N76E003 microcontrollers
	Written by Tirdad Sadri Nejad

	keeping my name written here on this header motivates me for such efforts.
	
	tirdad_ms@hotmail.com
*/


#define I2C_PRSC 9; 									// Reset Value is 9. I2C clock = Fsys/4*(I2CLK+1)
// for 16MHz default CPU_FREQ		9:400KHz	39:100KHz	 19:200KHz
	
/*i2c_init initalizes the I2C peripheral (default pins)*/
void i2c_init();

/*i2c_write writes a byte into I2C Data Register. returns 0 if arbitration is lost or NACKED*/
bit i2c_write(uint8_t iData);

/*i2c_restart transmits a repeated Start signal AND a Slave address. returns 0 if arbitraition is lost or Slave Address NACKED*/
bit i2c_restart(uint8_t iAdd);

/*i2c_start transmits a start signal AND a Slave address. returns 0 if arbitraition is lost or Slave Address NACKED*/
bit i2c_start(uint8_t iAdd);

/*i2c_stop transmits a stop signal*/
void i2c_stop();

/*i2c_read reads one byte from I2C Data Register. if ack=1, will send ACK for next recieve. if ack=0, will send a NACK to end reception*/
uint8_t i2c_read(uint8_t ack);