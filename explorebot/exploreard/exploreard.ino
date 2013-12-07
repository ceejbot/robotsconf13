#define RIGHT_WHEEL 10
#define LEFT_WHEEL 11
#define GOBUTTON 9

#define PWM_MIDPOINT 128
#define SPEED 64

#define TERMBAUD 115200

//-------------------------------------------------------------

void setup()
{
	pinMode(RIGHT_WHEEL, OUTPUT);
	pinMode(LEFT_WHEEL, OUTPUT);
	pinMode(GOBUTTON, INPUT);

	Serial.begin(TERMBAUD);
	Serial.println("ExplorerBot test one.");
}

void loop()
{
	readSerialCommand();
}

//-------------------------------------------------------------

void omghelp(int ln)
{
	Serial.print("OMG HELP @");
	Serial.print(ln, DEC);
	Serial.println("!");
}
#define OMGHELP() omghelp(__LINE__)

void forward(int duration)
{
	Serial.println("forward");
	analogWrite(RIGHT_WHEEL, 150);
	analogWrite(LEFT_WHEEL, 200);
}

void reverse(int duration)
{
	Serial.println("reverse");
	analogWrite(RIGHT_WHEEL, 200);
	analogWrite(LEFT_WHEEL, 150);
}

void turnRight(int duration)
{
	Serial.println("right turn");
	analogWrite(RIGHT_WHEEL, 225);
	analogWrite(LEFT_WHEEL, 225);
	delay(duration);
	analogWrite(RIGHT_WHEEL, 0);
	analogWrite(LEFT_WHEEL, 00);
}

void turnLeft(int duration)
{
	Serial.println("left turn");
	analogWrite(LEFT_WHEEL, 150);
	analogWrite(RIGHT_WHEEL, 150);
	delay(duration);
	analogWrite(RIGHT_WHEEL, 0);
	analogWrite(LEFT_WHEEL, 00);
}

void zero()
{
	Serial.println("Hard stop.");
	analogWrite(RIGHT_WHEEL, 0);
	analogWrite(LEFT_WHEEL, 0);
}

void calibration()
{
	Serial.println("Writing 180 to each motor");
	analogWrite(RIGHT_WHEEL, 180);
	analogWrite(LEFT_WHEEL, 180);
}

void help()
{
	Serial.println('help:  WASD to move; z to panic stop.');
}

void trySpeeds()
{
	int i;
	for (i = 0; i < 180; i += 10)
	{
		Serial.print(i, DEC);
		Serial.println("!");
		analogWrite(LEFT_WHEEL, 180 - i);
		analogWrite(RIGHT_WHEEL, 180 + i);
		delay(5000);
	}
}

void readSerialCommand()
{
	if (Serial.available())
	{
		char command = Serial.read();

		switch (command)
		{
			case 'h':
				help();
				break;

			case 'w':
				forward(1000);
				break;

			case 's':
				reverse(1000);
				break;

			case 'a':
				turnLeft(750);
				break;

			case 'd':
				turnRight(750);
				break;

			case 'z':
				zero();
				break;

			case 'c':
				calibration();
				break;

			case 'e':
				trySpeeds();
				break;
		}
	}
}
