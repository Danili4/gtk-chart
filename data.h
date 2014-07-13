#ifndef __DATA_H__
#define __DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct battery_data battery_t;

struct battery_data {
float volt[8];
float min_volt;
float max_volt;
float avr_volt;

float temp[4];
float min_temp;
float max_temp;

float ins_current;
float avr_curent;
char  balance_task;
char  flags;
};

#ifdef __cplusplus
}
#endif

#endif
