#pragma once

/**
 * Class to access the on-board buttons and switches of the JSumo Shield
 */
class SumoBoard 
{
public:
    /**
     * Construct the SumoBoard object
     */
    SumoBoard();

    /**
     * Wait until Start Button is pressed then return.
     */
    void waitForStartButton();

    /**
     * Set state of LED 1
     */
    void setLed1(bool on);

    /**
     * Set state of LED 2
     */
    void setLed2(bool on);

private:
    
};