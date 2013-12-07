#define MOTOR1 10
#define MOTOR2 11
#define GOBUTTON 9

#define TERMBAUD 115200

//-------------------------------------------------------------

void setup()
{
    pinMode(MOTOR1, OUTPUT);
    pinMode(MOTOR2, OUTPUT);
    pinMode(GOBUTTON, INPUT);

    Serial.begin(TERMBAUD);
    Serial.println("ExplorerBot test one.");
}

void loop()
{
    readSerialCommand();
}

//-------------------------------------------------------------

void runMotor(int level)
{
    if (level < 0)
        level = 0;
    else if (level > 255)
        level = 255;

    analogWrite(MOTOR1, 255 + level);
    analogWrite(MOTOR2, 255 - level);
}

void move()
{
    Serial.println("moving");
    runMotor(45);
}

void stop()
{
    Serial.println("stopping");
    runMotor(0);
}

void zero()
{
    Serial.println("Hard stop.");
    analogWrite(MOTOR1, 0);
    analogWrite(MOTOR2, 0);
}

void help()
{
    Serial.println("OMG HELP!");
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

            case 'g':
                move();
                break;

            case 's':
                stop();
                break;

            case 'z':
                zero();
                break;
        }
    }
}
