#include "prstlib/sensors.h"

#include <zephyr/logging/log.h>

#include "prstlib/adc.h"
#include "prstlib/led.h"
#include "prstlib/macros.h"

LOG_MODULE_REGISTER(sensors, CONFIG_PRSTLIB_LOG_LEVEL);

int prst_sensors_read_all(prst_sensors_t *sensors) {
  RET_IF_ERR(prst_adc_batt_read(&sensors->batt));
  RET_IF_ERR(prst_temp_read(&sensors->temp));
  RET_IF_ERR(prst_adc_soil_read(sensors->batt.adc_read.voltage, &sensors->soil1));
  
  return 0;
}