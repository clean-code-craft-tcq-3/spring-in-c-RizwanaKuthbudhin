#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    
    int i=0;
    
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    if(setlength == 0)
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
    }
    else
    {
        s.average = 0;
        s.min = s.max = numberset[i];
        
        for (i=0; i<setlength; i++)
        {
            s.average += numberset[i];
            if(numberset[i] < s.min) s.min =numberset[i];
            if(numberset[i] > s.max) s.max =numberset[i];
        }
        s.average /= setlength;
    }
    return s;
}

void emailAlerter()
{
    emailAlertCallCount++;
}
void  ledAlerter()
{
    ledAlertCallCount++;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
{
    if(computedStats.max > maxThreshold)
    {
        alerters[0]();
        alerters[1]();
    }
}
