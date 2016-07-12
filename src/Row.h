#ifndef ROW_H
#define ROW_H
#include <Arduino.h>
#include <inttypes.h>
#include <config_keybrd.h>
#include <Key.h>

/* Row is an abstract base class.
*/
class Row
{
    private:
        Key *const *const ptrsKeys;             //array of Key pointers
        virtual void keyWasPressed();
    protected:
        read_pins_t debounced;                  //bitwise, 1 means pressed, 0 means released
        void pressRelease(const uint8_t readPinCount, const read_pins_t debouncedChanged);
    public:
        Row(Key *const ptrsKeys[]) : ptrsKeys(ptrsKeys), debounced(0) { }
        virtual void process()=0;
};
#endif
