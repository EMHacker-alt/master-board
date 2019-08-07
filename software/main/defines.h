#ifndef DEFINES_H
#define DEFINES_H

#include <stdint.h>

	struct sensor_data {
		uint16_t status;
		uint16_t timestamp;
		int32_t position[2];
		int16_t velocity[2];
		int16_t current[2];
		uint16_t coil_resistance[2];
		uint16_t adc[2];
	} __attribute__((packed));

	struct command_data {
		uint16_t mode;
		int32_t position[2];
		int16_t velocity[2];
		int16_t current[2];
		uint16_t kp[2];
		uint16_t kd[2];
		uint16_t isat;
	} __attribute__((packed));


	struct wifi_eth_packet_command {
	    struct command_data command[CONFIG_N_SLAVES];
	    uint16_t command_index;
	} __attribute__ ((packed));

	struct wifi_eth_packet_sensor {
	    struct sensor_data sensor[CONFIG_N_SLAVES];
	    uint8_t IMU[18]; //TODO create the appropriate struct
	    uint16_t sensor_index;
	    uint16_t packet_loss;
	} __attribute__ ((packed));

#endif