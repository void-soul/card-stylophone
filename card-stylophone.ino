/*

该项目使用基本音调功能来演奏音符。

在下面的主循环函数中，我们可以通过更改未注释的函数来选择你想要的按键行为。如果你了解基本编程，还可以编写自己的！

该项目使用函数tone生成声音，使用pitches.h库定义不同音符的频率。该代码还包括一个称为readCapacitivePin的函数，用于测量引脚上的电容。

*/
#include "pitches.h"

int notelength  = 20;//音符长度
int outputpin   = 9;//音频输出引脚
int capacitance = 8;//电容测量引脚d:\data\Desktop\card-stylophone\pitches.h

void setup(void)
{  
  tone(outputpin, NOTE_A4, 500); //初始化 Arduino 板并发出蜂鸣声以表明设备正在工作。
}

/////////////////////////////////////////////////////////////////////////////////////
void loop(void)
{



 aeoliancap();   

}
/////////////////////////////////////////////////////////////////////////////////////


#include "pins_arduino.h" 
uint8_t readCapacitivePin(int pinToMeasure) {

  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;

  byte bitmask;
  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));

  *port &= ~(bitmask);
  *ddr  |= bitmask;
  delay(1);

  noInterrupts();

  *ddr &= ~(bitmask);
  *port |= bitmask;


  uint8_t cycles = 17;
       if (*pin & bitmask) { cycles =  0;}
  else if (*pin & bitmask) { cycles =  1;}
  else if (*pin & bitmask) { cycles =  2;}
  else if (*pin & bitmask) { cycles =  3;}
  else if (*pin & bitmask) { cycles =  4;}
  else if (*pin & bitmask) { cycles =  5;}
  else if (*pin & bitmask) { cycles =  6;}
  else if (*pin & bitmask) { cycles =  7;}
  else if (*pin & bitmask) { cycles =  8;}
  else if (*pin & bitmask) { cycles =  9;}
  else if (*pin & bitmask) { cycles = 10;}
  else if (*pin & bitmask) { cycles = 11;}
  else if (*pin & bitmask) { cycles = 12;}
  else if (*pin & bitmask) { cycles = 13;}
  else if (*pin & bitmask) { cycles = 14;}
  else if (*pin & bitmask) { cycles = 15;}
  else if (*pin & bitmask) { cycles = 16;}

  interrupts();

  *port &= ~(bitmask);
  *ddr  |= bitmask;

  return cycles;
}

void aeoliancap(void)
{
  if(readCapacitivePin(6) > capacitance)   {tone(outputpin, NOTE_A4, notelength);}
  if(readCapacitivePin(5) > capacitance)   {tone(outputpin, NOTE_B4, notelength);}
  if(readCapacitivePin(4) > capacitance)   {tone(outputpin, NOTE_C5, notelength);}
  if(readCapacitivePin(3) > capacitance)   {tone(outputpin, NOTE_D5, notelength);}
  if(readCapacitivePin(2) > capacitance)   {tone(outputpin, NOTE_E5, notelength);}
  if(readCapacitivePin(7) > capacitance)   {tone(outputpin, NOTE_F5, notelength);}
  if(readCapacitivePin(8) > capacitance)   {tone(outputpin, NOTE_G5, notelength);}
  if(readCapacitivePin(10) > capacitance)  {tone(outputpin, NOTE_A5, notelength);}
  if(readCapacitivePin(11) > capacitance)  {tone(outputpin, NOTE_B5, notelength);}
  if(readCapacitivePin(12) > capacitance)  {tone(outputpin, NOTE_C6, notelength);}
}

void aeolianbt(void)
{
  if(readCapacitivePin(6) > capacitance)    {tone(outputpin, NOTE_A1, notelength);}
  if(readCapacitivePin(5) > capacitance)    {tone(outputpin, NOTE_C2, notelength);}
  if(readCapacitivePin(4) > capacitance)    {tone(outputpin, NOTE_E2, notelength);}
  if(readCapacitivePin(3) > capacitance)    {tone(outputpin, NOTE_G2, notelength);}
  if(readCapacitivePin(2) > capacitance)    {tone(outputpin, NOTE_A2, notelength);}
  if(readCapacitivePin(7) > capacitance)    {tone(outputpin, NOTE_A4, notelength);}
  if(readCapacitivePin(8) > capacitance)    {tone(outputpin, NOTE_C5, notelength);}
  if(readCapacitivePin(10) > capacitance)   {tone(outputpin, NOTE_E5, notelength);}
  if(readCapacitivePin(11) > capacitance)   {tone(outputpin, NOTE_G5, notelength);}
  if(readCapacitivePin(12) > capacitance)   {tone(outputpin, NOTE_A5, notelength);}
}

void pentatonic(void) {
  if(readCapacitivePin(6) > capacitance)   {amscale();}
  if(readCapacitivePin(5) > capacitance)   {dmscale();}
  if(readCapacitivePin(4) > capacitance)   {e7scale();}
  if(readCapacitivePin(3) > capacitance)   {fscale();}
  if(readCapacitivePin(2) > capacitance)   {gscale();}
}

void amscale(void) {
  if(readCapacitivePin(7) > capacitance)    {tone(outputpin, NOTE_A4, notelength);}
  if(readCapacitivePin(8) > capacitance)    {tone(outputpin, NOTE_C5, notelength);}
  if(readCapacitivePin(10) > capacitance)   {tone(outputpin, NOTE_E5, notelength);}
  if(readCapacitivePin(11) > capacitance)   {tone(outputpin, NOTE_G5, notelength);}
  if(readCapacitivePin(12) > capacitance)   {tone(outputpin, NOTE_A5, notelength);}
}

void dmscale(void) {
  if(readCapacitivePin(7) > capacitance)    {tone(outputpin, NOTE_D5, notelength);}
  if(readCapacitivePin(8) > capacitance)    {tone(outputpin, NOTE_F5, notelength);}
  if(readCapacitivePin(10) > capacitance)   {tone(outputpin, NOTE_A5, notelength);}
  if(readCapacitivePin(11) > capacitance)   {tone(outputpin, NOTE_C6, notelength);}
  if(readCapacitivePin(12) > capacitance)   {tone(outputpin, NOTE_D6, notelength);}
}

void e7scale(void) {
  if(readCapacitivePin(7) > capacitance)    {tone(outputpin, NOTE_E5, notelength);}
  if(readCapacitivePin(8) > capacitance)    {tone(outputpin, NOTE_GS5, notelength);}
  if(readCapacitivePin(10) > capacitance)   {tone(outputpin, NOTE_B5, notelength);}
  if(readCapacitivePin(11) > capacitance)   {tone(outputpin, NOTE_D6, notelength);}
  if(readCapacitivePin(12) > capacitance)   {tone(outputpin, NOTE_E6, notelength);}
}

void cscale(void) {
  if(readCapacitivePin(7) > capacitance)    {tone(outputpin, NOTE_C5, notelength);tone(outputpin, NOTE_C5, notelength);tone(outputpin, NOTE_C5, notelength);tone(outputpin, NOTE_C5, notelength);}
  if(readCapacitivePin(8) > capacitance)    {tone(outputpin, NOTE_E5, notelength);}
  if(readCapacitivePin(10) > capacitance)   {tone(outputpin, NOTE_G5, notelength);}
  if(readCapacitivePin(11) > capacitance)   {tone(outputpin, NOTE_B5, notelength);}
  if(readCapacitivePin(12) > capacitance)   {tone(outputpin, NOTE_C6, notelength);}
}

void fscale(void) {
  if(readCapacitivePin(7) > capacitance)   {tone(outputpin, NOTE_F5, notelength);}
  if(readCapacitivePin(8) > capacitance)   {tone(outputpin, NOTE_A5, notelength);}
  if(readCapacitivePin(10) > capacitance)   {tone(outputpin, NOTE_C6, notelength);}
  if(readCapacitivePin(11) > capacitance)   {tone(outputpin, NOTE_E6, notelength);}
  if(readCapacitivePin(12) > capacitance)   {tone(outputpin, NOTE_F6, notelength);}
}

void gscale(void) {
  if(readCapacitivePin(7) > capacitance)   {tone(outputpin, NOTE_G5, notelength);}
  if(readCapacitivePin(8) > capacitance)   {tone(outputpin, NOTE_B5, notelength);}
  if(readCapacitivePin(10) > capacitance)   {tone(outputpin, NOTE_D6, notelength);}
  if(readCapacitivePin(11) > capacitance)   {tone(outputpin, NOTE_F6, notelength);}
  if(readCapacitivePin(12) > capacitance)   {tone(outputpin, NOTE_G6, notelength);}
}





