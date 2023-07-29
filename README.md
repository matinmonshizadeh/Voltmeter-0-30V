# Voltmeter 0-30V

- **Electric Circuits course project (Fall 2021)**

### To make Voltmeter 0-30V, you are going to need the following:
1. Perforated Board (1600 points)
2. Square Battery
3. Battery Clip Connector
4. AVR Programmer
5. Character LCD (2 X 16)
6. (5.813K) Ohm Resistor
7. (43.23K) Ohm Resistor
8. Solder Wire
9. Jumper Wire
10. 2-Pin Male Connector
11. 2-Pin Female Connector
12. LM7805 Regulator
13. 10µF 16V Radial Electrolytic Capacitor
14. 100µF 16V Radial Electrolytic Capacitor
15. 100nF Ceramic Capacitor
16. ATmega32 Microcontroller
17. 40 Pin IC Socket
18. Female Pin Header
19. Male Pin Header
20. 6 Pin Push Button On/Off Switch
21. 2 Pin Terminal Block
22. (10K) Ohm Potentiometer
23. Two Pieces of wire

## Project Steps:
This project will be divided into two hardware and software sections. Firstly we discuss the hardware section.

### Hardware Section:
- We first sand the perforated board until its surface is shiny.
- Then, we need to solder the female and male pins to the LCD's 16th pin of the LCD (The purpose of this work is to use it on other projects because LCD is a relatively expensive part. Do not solder directly on the board; instead, use a male header pin. This LCD can be used in another circuit in the future)
- In the next step, we will solder the rest of the parts. (resistors, capacitors, connectors. 2-pin male connector, potentiometer, 1x40 female header pin, two-pin terminal, 6-pin switch Regulator, on/off)
- We solder the 40-pin IC socket on the board. A microcontroller is relatively expensive; don't solder it directly on the board. Instead, we use a 40-pin IC socket so that it can be connected to the microcontroller in the future using another circuit)


```diff
- we solder the parts on the board differently when We wanted to use a wire jumper to solder it. (Proper spacing)
```

```diff
- be careful how to connect the wire jumper and soldering carefully. We have done the simulation.
```

```diff
- we should be careful when soldering; we should mark the points with Solder carefully because otherwise, if we are not careful, a short circuit may occur and cause some parts to burn.
```

- In the end, we removed the 2-pin female telecommunication connector and two pieces of wire to the battery head. We connect a book and a book battery.
- Now, when we press the 6 Pin Push Button, if we have followed all the steps correctly, LCD turns on, but the LCD screen does not show us any information. Now We come to the software and programming part.


<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184623661-3f16b6f5-9376-4d70-9515-833b1b8734b7.jpg" width="360" height="640" />
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184623753-353c30d8-fd99-4ab9-aa14-040db3f3a45a.jpg" width="640" height="360"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184623886-c0f20ef5-f79c-4bab-b630-eae4e0372435.jpg" width="360" height="640"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184623939-19d9db2d-d39c-4f2f-9570-746b47464508.jpg" width="360" height="640"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184623981-97eb767a-dcbe-46e8-9f35-d55cb85f8b60.jpg" width="360" height="640"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184624117-fbbcafe1-059e-4af5-bdcc-6b070ecf7dce.jpg" width="360" height="640"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184624174-4806e5c7-0592-4373-80ea-8a3906f9274a.jpg" width="640" height="360"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184624262-64b0e71b-be21-4c52-b5df-647ef4141d93.jpg" width="640" height="360"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184624334-e03e83c5-e0fd-4c93-8a28-ea2c90d5f73e.jpg" width="640" height="360"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184624412-9e78f677-25a0-4cd7-ad83-ac2131789f21.jpg" width="640" height="360"/>
</p>

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/184624468-afbb1d73-bb40-4a9d-9022-64b21b4f723b.jpg" width="360" height="640"/>
</p>

### Software Section:
- We need an AVR programmer to write a program for its software part. A program is written in C language. Let me explain in summer what we should do. What we do for us in this code is first write a message for 2 seconds. Display the desired (my name is Matin), and then it shows the voltage when the circuit is connected to the power supply.


### Application of Some Pieces:
- #### AVR Programmer:
	It is a device that transfers the code file from the computer to the microcontroller.
- #### Character LCD (2 X 16):
	We use LCD to display the voltage read in the microcontroller.
- #### LM7805 Regulator:
	You get an input voltage from the regulator, which gives you a constant and stable output voltage (here, 5 volts).
- #### ATmega32 Microcontroller:
	It is a tiny computer. It has some other parts like a real computer, with CPU and memory. We can put a program on it and its microcontroller to execute. For that, we use the C programming language because it is a compiler language and converts the code we write into machine language or the same 0 and 1, and the microcontroller can run it.
	There is a point, this is a part of the microcontroller, and it works to read the voltage. This part works when it is 1 in the microcontroller, and when it is 0, it does not give us the voltage read.
	

### The microcontroller has 40 pins, 8 of which can read the voltage. Pay attention to the image below:
<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/185788241-30cf6245-5058-493d-ad03-8ea0f0596701.png" />
</p>

- From ADC0 to ADC7, they can read voltage.
- We specify in our code which pin of the microcontroller is going to be the voltage for us (We use PA0 or the same ADC0 here.) (In the code, this part We have determined that if we put 000, it will be adc0 and if 001, it will be adc1 and...))


## Schematic
<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/185788310-403df6e1-32ec-49e2-9473-de96ca81ec74.png" />
</p>

- As shown in the picture above, we connect the points marked by wire jumpers.
- For example:

<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/185788362-85bcc617-6a4d-419a-b5bd-8e2f02f4ee0a.png" />
</p>

## Final Result:
<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/185788423-6ed76ed2-05a9-4a06-bee2-e027ad3c28d5.jpg" width="360" height="640"/>
</p>
<p align="center">
		<img src="https://user-images.githubusercontent.com/96329489/185788425-fe91c6c9-3ee6-40c7-8a87-f8f5ee129b21.jpg" width="360" height="640"/>
</p>



##

In appreciation of Reza Hessami



