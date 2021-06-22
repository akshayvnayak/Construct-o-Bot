//You are allowed to define your own function to fulfill the requirement of tasks
//Dont change the name of following functions

/*
**
Team Id: #8004
* Author List: PRATHAM V BHOMKAR, CHENNAREDDY KRISHNA KUSHAL, AKSHAY V NAYAK, KARTHIK B S
* Filename: CB#8004_Task_1.1
* Theme: Construct-O-Bot (CB)
* Functions:int readSensors(void);
* Global Variables: None
*
*/

#include "CB_Task_1_Sandbox.h"

/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/

void forward_wls(unsigned char node)
{
	forward();
	int count = 0;		//count : variable to count the number of nodes
	int sensor;		//sensor : store the value returned by the function readSensors();
	while (true)
	{
		sensor = readSensors();
		forward();
		switch (sensor)
		{
		case -1:count++;
				velocity(150, 150);
				_delay_ms(380);
			stop();
			if (count == node)
			return;
			break;
		case 0:velocity(0,50);
			break;
		case 2:velocity(0, 120);
			break;
		case 3:velocity(120, 0);
			break;
		case 1: velocity(120, 120);
			break;
		}
		
	}
}
/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{
	
	forward();
	while (readSensors() != 2)
	{
		printf("Left");
		left();
	}
}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{
	forward();
	while (readSensors()!=3)
	{
		printf("Right");
		right();
		_delay_ms(50);
	}
}

/*
*
* Function Name: e_shape
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a e shape path on the arena
* Example Call: e_shape();
*/
void e_shape(void)
{
	int sensor = readSensors(); //sensor : store the value returned by the function readSensors();
	forward();
	_delay_ms(100);
	while (true)
	{
		sensor = readSensors();
		switch (sensor)
		{
		case 0: velocity(255, -70); //soft_right;
			break;
		case 1: velocity(255, 255); //forward();
			break;
		case 2:velocity(0, 150); //soft_left();
			break;
		case 3: velocity(150, 0); // soft_right;
		//default:
			break;
		}
	}
}

/*
**
Function Name: readSensors
* Input: void
* Output: int
* Logic: Use this function to get values from the sensor of the robot.
* Example Call: readSensors();
**
*/

int readSensors(void)
{
	unsigned char right_sensor, left_sensor, middle_sensor;
	left_sensor = ADC_Conversion(1);
	middle_sensor = ADC_Conversion(2);
	right_sensor = ADC_Conversion(3);
	printf("%d\t%d\t%d\n", left_sensor, middle_sensor, right_sensor);
	if (left_sensor == 0 && middle_sensor == 0 && right_sensor == 0)
		return 0;
	if (left_sensor == 0 && middle_sensor == 0 && right_sensor == 255)
		return 3;
	if (left_sensor == 0 && middle_sensor == 255 && right_sensor == 0)
		return 1;
	if (left_sensor == 0 && middle_sensor == 255 && right_sensor == 255)
		return 3;
	if (left_sensor == 255 && middle_sensor == 0 && right_sensor == 0)
		return 2;
	if (left_sensor == 255 && middle_sensor == 0 && right_sensor == 255)
		return 1;
	if (left_sensor == 255 && middle_sensor == 255 && right_sensor == 0)
		return 2;
	if (left_sensor == 255 && middle_sensor == 255 && right_sensor == 255)
		return -1;
}



/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{
	forward_wls(1);		// Uses white line sensors to go forward by the number of nodes specified
	right_turn_wls();	//Uses white line sensors to turn right until black line is encountered
	forward_wls(2);
	left_turn_wls();	//Uses white line sensors to turn left until black line is encountered
	forward_wls(2);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	_delay_ms(79);		//stops the program for 75 millisecond
	forward();
	_delay_ms(1800);
	forward_wls(1);
	left_turn_wls();
	forward_wls(3);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	_delay_ms(82);
	forward();
	_delay_ms(1800);
	forward_wls(1);
	right_turn_wls();
	forward_wls(2);
	left_turn_wls();
	forward_wls(1);
	stop();
	//_delay_ms(50000);		//stops for 50 seconds at the end point
	// Write your task 1.1 Logic here
}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{
	//write your task 1.2 logic here
}