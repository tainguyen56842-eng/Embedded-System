#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

#define GPIO_CHIP_NAME "gpiochip0";
#define GPIO_LINE_OFFSET 17;
#define CONSUMER "blink_example"

int main(void){
	struct gpiod_chip *chip;
	struct gpiod_line *line;
	int ret;
	
	//1.Open the GPIO chip character device
	chip = gpiod_chip_open_by_name(GPIO_CHIP_NAME);
	if(!chip){
		perror("Failed to open GPIO chip");
		return 1;
	}
	
	//2.Get the specific line handle for GPIO 17
	line = gpiod_chip_get_line(chip,GPIO_LINE_OFFSET);
	if(!line){
		perror("Failed to get GPIO line");
		gpio_chip_close(chip);
		return 1;
	}

	//3.request the line as an OUTPUT ,starting at LOW
	ret = gpio_line_request_output(line,CONSUMER,0);
	if(ret <0){
		perror("Failed to request line as output");
		gpiod_chip_close(chip);
		return 1;
	}
	printf("Blinking GPIO %d. Press Ctrl+C to exit.\n", GPIO_LINE_OFFSET);

	//4.Infinite bilink loop
	while(1){
		//Turn LED ON (HIGH)
		gpiod_line_set_value(line,1);
		sleep(1);
		//turn LED OFF (LOW);
		//
		gpiod_line_set_value(line,0);
		sleep(1);
	}
	gpio_line_release(line);
	gpio_chip_close(chip);
	return 0;
}
	



