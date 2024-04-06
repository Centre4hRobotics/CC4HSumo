#pragma once

/**
 * Class to access the drive motors of the Sumo robot
 */
class DriveMotors
{
public:
    /**
     * Construct the DriveMotors class (no arguments)
     */
    DriveMotors();

    /**
     * Arcade Drive method, where the motion of the robot is specified by 
     * a speed and steering.
     * 
     * @param speed: The robot's forwards/backwards speed [-1.0..1.0]. Forward is positive.
     * @param steer: The robot's rotation rate [-1.0..1.0]. Clockwise is positive.
     */
    void drive(double speed, double steer);

    /**
     * Set left and right motor speeds directly
     * */
    void setMotorSpeeds(double leftSpeed, double rightSpeed);

    /**
     * Stop the motors (same as drive(0, 0))
     */
    void stop();
private:
    void setMotorSpeed(int motor, double speed);
};

