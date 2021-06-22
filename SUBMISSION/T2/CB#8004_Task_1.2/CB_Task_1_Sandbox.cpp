//You are allowed to define your own function to fulfill the requirement of tasks
//Dont change the name of following functions

/*
**
Team Id: #8004
* Author List: PRATHAM V BHOMKAR, CHENNAREDDY KRISHNA KUSHAL, AKSHAY V NAYAK, KARTHIK B S
* Filename: CB#8004_Task_1.2
* Theme: Construct-O-Bot (CB)
* Functions:readSensors(void),forward_wls(unsigned char),forward_wls_white(unsigned char node),forward_wls1(unsigned char node),forward_wls_zz(void),forward_wls3(int secs),left_turn_wls(void),left_turn_wls_white(void),left_turn_wls_white_(void),right_turn_wls(void),right_turn_wls_white(void),right_turn_wls_white_(void),Task_1_2(void)
* Global Variables: None
*
*/

#include "CB_Task_1_Sandbox.h"

#include<time.h>  // To use time() function

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
				velocity(180, 180);
				_delay_ms(380);
			stop();
			if (count == node)
			return;
			break;
		case 0:velocity(0,50);
			break;
		case 2:velocity(50, 140);
			break;
		case 3:velocity(140, 50);
			break;
		case 1: velocity(170, 170);
			break;
		}
		
	}
}



/*
*
* Function Name: forward_wls_white
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of white nodes specified in white line in between black area
* Example Call: forward_wls_white(2); //Goes forward by two white nodes nodes
*
*/

void forward_wls_white(unsigned char node)
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
		case 0:count++;
			velocity(180, 180);
			_delay_ms(380);
			stop();
			if (count == node)
				return;
			break;
		case -1:velocity(0, 100);
			break;
		case 3:velocity(0, 120);
			break;
		case 2:velocity(120, 0);
			break;
		case 10: velocity(120, 120);
			break;
		case 1: stop();
			return;
			break;
		}

	}
}


/*
*
* Function Name: forward_wls1
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of white nodes specified in black line in between white area
* Example Call: forward_wls1(1); //Goes forward by one white node
*
*/

void forward_wls1(unsigned char node)
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
		case 0:count++;
			velocity(105, 105);
			_delay_ms(380);
			stop();
			if (count == node)
				return;
			break;
		case 2:velocity(0, 110);
			break;
		case 3:velocity(110, 0);
			break;
		case 1: velocity(92, 92);
			break;
		}

	}
}


/*
*
* Function Name: forward_wls_zz
* Input: void
* Output: void
* Logic: Moves forward in a zig zag manner untill a black line is detected
* Example Call: forward_wls_zz(); //Goes in a zig zag pattern untill a black line is detected
*
*/

void forward_wls_zz(void)
{
	forward();
	_delay_ms(2500);
	velocity(255, 235);
	_delay_ms(1850);
	while (readSensors() == 0) 
	{
		velocity(180, 255);
	}
}


/*
*
* Function Name: forward_wls3
* Input: secs
* Output: void
* Logic: Uses white line sensors to go forward for the number of seconds specified
* Example Call: forward_wls3(2); //Goes forward for two seconds
*
*/

void forward_wls3(int secs)
{
	forward();
	time_t seconds = secs;	//Assign the given argument to seconds variable.
	time_t startTime = time(NULL);  //Assign current time to startTime
	int sensor;		//sensor : store the value returned by the function readSensors();
	while (time(NULL) - startTime < seconds)	//This while loop runs for the nummber of seconds given
	{
		sensor = readSensors();
		forward();
		switch (sensor)
		{
		case 2:velocity(30, 110);
			break;
		case 3:velocity(110, 30);
			break;
		case 1: velocity(100, 100);
			break;
		case 10:return;
		case -1: velocity(50, 0);
			break;
		case 0:velocity(0, 50);
		}
	}
}

/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns left until black line is encountered
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
* Function Name: left_turn_wls_white
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until white line is encountered by left line sensor
* Example Call: left_turn_wls_white(); //Turns left until white line is encountered
*
*/
void left_turn_wls_white(void)
{

	forward();
	left();
	_delay_ms(200);
	while (readSensors() != 3)
	{
		printf("Left");
		left();
	}
}


/*
*
* Function Name: left_turn_wls_white_
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until white line is encountered by middle line sensor
* Example Call: left_turn_wls_white_(); //Turns left until white line is encountered. This function called before placing an object to H5.
*
*/
void left_turn_wls_white_(void)
{

	forward();
	left();
	_delay_ms(200);
	while (readSensors() != 10)
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
	}
}


/*
*
* Function Name: right_turn_wls_white
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until white line is encountered by right line sensor
* Example Call: right_turn_wls_white(); //Turns right until white line is encountered
*/
void right_turn_wls_white(void)
{
	forward();
	right();
	_delay_ms(400);
	while (readSensors() != 2)
	{
		printf("Right");
		right();
	}
}


/*
*
* Function Name: right_turn_wls_white_
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until white line is encountered by middle line sensor
* Example Call: right_turn_wls_white_(); //Turns right until white line is encountered. This function is called before placing an object in H5.
*/

void right_turn_wls_white_(void)
{
	forward();
	right();
	_delay_ms(200);
	while (readSensors() != 10)
	{
		printf("Right");
		right();
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
		return 10;
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
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	pick();//red
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls1(1);
	forward_wls_zz();
	forward_wls(2);
	place();
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	pick();//green
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls1(1);
	forward_wls_zz();
	forward_wls(2);
	place();
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	pick();//black
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls3(3);
	forward_wls_zz();
	forward_wls(2);
	place();
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	pick();//blue
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(3);
	left_turn_wls();
	forward_wls1(1);
	forward_wls_zz();
	forward_wls(2);
	place();
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	pick();//red
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(3);
	left_turn_wls();
	forward_wls3(3);
	forward_wls_zz();
	forward_wls(2);
	place();
	left_turn_wls();
	forward_wls(1);
	forward_wls3(3);
	forward_wls_zz();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	pick();//pink
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(3);
	right_turn_wls();
	forward_wls1(1);
	forward_wls_zz();
	forward_wls(2);
	place();
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	pick();//brown
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(3);
	right_turn_wls();
	forward_wls3(4);
	forward_wls_zz();
	forward_wls(2);
	place();
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(1);
	pick();//black
	left_turn_wls();
	forward_wls(1);
	left_turn_wls();
	forward_wls(3);
	left_turn_wls();
	forward_wls3(3);
	forward_wls_white(1);
	left_turn_wls_white_();
	forward();
	_delay_ms(230);
	stop();
	place();
	right_turn_wls_white();
	forward_wls_white(1);
	forward_wls(1);
	left_turn_wls();
	forward_wls(5);
	left_turn_wls();
	forward_wls(1);
	pick();//brown
	left_turn_wls();
	forward_wls(1);
	right_turn_wls();
	forward_wls(5);
	right_turn_wls();
	forward_wls3(3);
	forward_wls_white(1);
	right_turn_wls_white_();
	forward();
	_delay_ms(280);
	stop();
	place();
	//_delay_ms(10000);
	
	
	//write your task 1.2 logic here
}