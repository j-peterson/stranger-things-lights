# Halloween 2016 Costume Code

### Stranger Things Christmas Trees Lights WS2811+Arduino Halloween Costume

![example gif](/run.gif "Will says RUN")

Why? Because Stranger Things is an awesome show and the girlfriend wanted to do topical costumes (she went as Eleven). I couldn't pass up an opportunity to make something.

I'm posting my code here as a starting point for anyone out there wanting to get a jump start on making their own Stranger Things light display.

### Inventory / Tips

- Arduino

   I used the standard UNO but you'd be better off with the Pro Mini 5V (if you have an FTDI cable)

- WS2811 LEDs

   I bought 100 WS2811 LEDs off [Amazon](https://www.amazon.com/dp/B00MECZ06G). They come in two strings of 50 each. The WS2811 LEDs have three wires: data (white), +5V power (red), and ground (blue). For convenience, the WS2811 strings are terminated with JST connectors for data with an extra ground wire pre-soldered. The LED chip is labeled with a big arrow to indicate which direction to feed data into. Power should be connected every 50 LEDs or so (depending on your source). There is tons of info out there on WS2811s.
   
- Portable USB charger battery

   I used a 2200mAh stick (5V 1.2A) I got free at a conference. The shirt lasted a few hours per charge. Arduinos are supposed to run on 7V - 12V but if you're not doing too much computationally and not using the Arduino's output voltage supplies, they will happily run on 5V. They're great, resilient little boards. If you start having weird issues with timing or LED behavior, it's most likely the power. Also if you edit the code, test the current draw from the supply so you don't rapidly discharge the battery and overheat it. I used a [USB multimeter](https://www.amazon.com/dp/B00S2HJAUE/) to ensure the light display wasn't pulling more current than the battery claimed it could maximally output. Caution: batteries can be dangerous.

- Sacrificial USB cable, solder, heat shrink, tape, etc.

   You'll need to wire it all together somehow...

- A shirt, fabric paint, and a metric ton of safety pins (or whatever you want to mount them too)


### Setup

- This is a [FastLED](https://github.com/FastLED/FastLED) based project (FastLED rocks! Thanks devs!). In order to have the preprocessor find the header file, you'll need to download and add the FastLED library .ZIP to your installed Arduino Sketch application by clicking 'Sketch' > 'Include Library' > 'Add .ZIP Library...'.

- You'll need to change the `ALPHA_OFFSET` to the number of the LED that corresponds to Z. You may also have to totally change the letter `int`s to correspond to correct letter if you don't lay the lights out like I did.

- The output to the LEDs is a PWM signal. I ran the two WS2811 strings in parallel with data connected to ports 5 and 6. (PWM ports are marked with a tilde ~ on the Arduino).

- Wire it together however you want, but I'll explain what I did.

   The USB plug (from battery) was cut and the 5V (typically red but double check) was connected to the 5V power connectors on both LED strings (also red), and a scrap of wire (choose red) which was plugged into Vin on the Arduino. The USB ground was connected to the Arduino ground and the LED ground. Data was connected from the LED strings to Arduino pins 5 and 6.

![wiring drawing](/wiring.png "This is how I did it. Don't hurt yourself.")

