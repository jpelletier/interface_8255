#pragma once

#include <Arduino.h>

#define USE_CODE_INTERRUPTS

#ifdef USE_CODE_INTERRUPTS
#include <CircularBuffer.h>
#endif

void intf_8255_init();

byte ReadFrom8255();
void WriteTo8255(byte value);
