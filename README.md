# AnimatedValues
C++ library for PlatformIO, for having a value following an animation sequence

## Typical application

```cpp
//include stuff
//...
#include "AnimatedBool.hpp"

#define MY_LED_PIN whatever

AnimatedBool beat = AnimatedBool::createAnimation('*', ".*.*......") // blink twice

// interrupt to update led status 10 times per second
void onTimerLed() {
    digitalWrite(MY_LED_PIN, beat.run() ? HIGH : LOW)
}
```
