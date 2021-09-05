#include "contiki.h"
#include "sys/etimer.h"

#include "virtual-sensor.h"

#include <stdio.h>

PROCESS(sensor_node,"Sensor reading Node");
AUTOSTART_PROCESSES(&sensor_node);

static struct etimer timer;

PROCESS_THREAD(sensor_node, ev, data)
{
   PROCESS_BEGIN();

    etimer_set(&timer, 5 * CLOCK_SECOND);

    while(1){
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));

        float temperature_reading = read_temperature();
        printf("Temperature reading: %.2f C\n", temperature_reading); //hacemos una prueba para saber si el codigo esta funcionando 
        
        float humidity_reading = read_humidity();
        printf("Humidity reading: %.2f %%\n", humidity_reading); //ponemos doble porcentaje para que el formato ponga en porcentaje 

        etimer_reset(&timer); //reseteamos el timer para que cada 5 segundos nos muestre mediciones de temperatura y humedad 
    }

   PROCESS_END();

}