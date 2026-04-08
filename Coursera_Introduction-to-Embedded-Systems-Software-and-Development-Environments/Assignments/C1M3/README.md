### <ins>Assignment 3 Requirements</ins>:  

In this programming assignment you will need to analyze some allocated memory. 

You will need to specify where the listed symbols will be placed in the program. Once you have figured out your memory space, you can take the Programming Assignment Quiz where you will provide details about specific symbol elements including:

- Location Top segment or Type - Code, Data, Peripheral, Register, None.
- Location Sub-segment - Stack, Heap, BSS, Data, const/rodata, None.
- Access Permissions  - Read (R), Write (W) Read-write (RW), None.
- Lifetime - Function/Block, Program, Indefinite, None

There are multiple suggestions of tools you can use to help determine these answers besides just inspection. 

1. You may generate a `.map` file using the linker flag `-Wl,-Map=main.map`:
  > - With this file you can look find certain assignments listed in the code.

2. You can use the GCC binary utility `nm` to investigate the code symbols:
  > - This will print code/data symbols with the memory properties

3. You can use the GCC toolchain and dump a file to assembly with the `-S` option: 
  > - This will provide some details on how a piece of data is allocated

4. You can add code to this to investigate the addresses that have been assigned to the variables and print those to the terminal.

### <ins>Output</ins>:  

Note: Click on each image for better visibility.

Image: PLATFORM=MSP432
![alt text](https://github.com/renatosoriano/Coursera-Introduction-to-Embedded-Systems-Software-and-Development-Environments/blob/master/Assignments/C1M3/C1M3.png)


Author: Renato Soriano.
