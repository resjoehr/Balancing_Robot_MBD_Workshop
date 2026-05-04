// Copyright Pololu Corporation.  For more information, see http://www.pololu.com/

/*! \file Balboa32U4.h
 *
 * \brief Main header file for the Balboa32U4 library.
 *
 * This file includes all the other headers files provided by the library.
 */

#pragma once

#ifndef __AVR_ATmega32U4__
#error "This library only supports the ATmega32U4.  Try selecting A-Star 32U4 in the Boards menu."
#endif

#include <FastGPIO.h>
#include <Balboa32U4Encoders.h>

// TODO: servo support

/*! \brief Turns the red user LED (RX) on or off.

@param on 1 to turn on the LED, 0 to turn it off.

The red user LED is on pin 17, which is also known as PB0, SS, and RXLED.  The
Arduino core code uses this LED to indicate when it receives data over USB, so
it might be hard to control this LED when USB is connected. */

inline bool usbPowerPresent()
{
    return USBSTA >> VBUS & 1;
}

/*! \brief Reads the battery voltage and returns it in millivolts.

If this function returns a number below 5500, the actual battery voltage might
be significantly lower than the value returned. */
inline uint16_t readBatteryMillivolts()
{
    const uint8_t sampleCount = 8;
    uint16_t sum = 0;
    for (uint8_t i = 0; i < sampleCount; i++)
    {
        sum += analogRead(A1);
    }

    // VBAT = 3 * millivolt reading = 3 * raw * 5000/1024
    //      = raw * 1875 / 128
    // The correction term below makes it so that we round to the
    // nearest whole number instead of always rounding down.
    const uint32_t correction = 64 * sampleCount - 1;
    return ((uint32_t)sum * 1875 + correction) / (128 * sampleCount);
}
