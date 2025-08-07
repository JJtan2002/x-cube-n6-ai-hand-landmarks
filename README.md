# x-cube-n6-ai-hand-landmarks Application

Computer Vision application demonstrating the deployment of several object detection models execution in series on the STM32N6570-DK or NUCLEO-N657X0-Q board. The chosen use case is single-hand landmark detection. It consists of two models that execute sequentially:

1. A palm detection (pd) model is executed in the first stage to detect the hand’s palm.
2. A hand landmark (hl) detection model is executed in the second stage to identify the landmarks of the hand detected during the first stage. After the execution of the first model, a resize operation takes place to provide the expected input to the second model.
   On STM32N6570-DK GPU2D is used to also perform a rotation to orient hand vertically.

This top README gives an overview of the app. Additional documentation is available in the [Doc](./Doc/) folder. 

This application is to be adapted to run a face detection moddel and a face landmarking model. The original application architecture will be extended to run an iris landmarking model as well.

![Screenshot of application running](_htmresc/screenshot.png)


## Features Demonstrated in This Example

- Multi-threaded application flow (FreeRTOS)
- NPU accelerated quantized AI model inference
- GPU2D usage to perform resize + rotation transformation
- Execute multiple models in series
- Dual DCMIPP pipes
- DCMIPP crop, decimation, downscale
- LTDC dual-layer implementation
- DCMIPP ISP usage
- Dev mode
- Boot from external flash

## Hardware Support

### MB1939 STM32N6570-DK

  - The board should be connected to the onboard ST-LINK debug adapter CN6 with a __USB-C to USB-C cable to ensure sufficient power__
  - OTP fuses are set in this example for xSPI IOs to get the maximum speed (200MHz) on xSPI interfaces.

![Board](_htmresc/ImageBoard.JPG)

STM32N6570-DK board with MB1854B IMX335.

## Tools Version

- IAR Embedded Workbench for Arm (**EWARM 9.40.1**) + N6 patch ([**EWARMv9_STM32N6xx_V1.0.0**](STM32Cube_FW_N6/Utilities/PC_Software/EWARMv9_STM32N6xx_V1.0.0.zip))
- [STM32CubeIDE](https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-ides/stm32cubeide.html) (**STM32CubeIDE 1.17.0**)
- [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html) (**v2.18.0**)
- [STEdgeAI](https://www.st.com/en/development-tools/stedgeai-core.html) (**v2.1.0**)

## Boot Modes

The STM32N6 does not have any internal flash. To retain your firmware after a reboot, you must program it in the external flash. Alternatively, you can load your firmware directly from SRAM (dev mode). However, in dev mode, if you turn off the board, your program will be lost.

__Boot modes:__
- Dev mode (BOOT0 and BOOT1 to the right): load firmware from debug session in RAM, program firmware in external flash
- Boot from flash (BOOT0 and BOOT1 to the left)

## Console parameters

You can see application messages by attaching a console application to the ST-Link console output. Use the following console parameters:
- Baud rate of 115200 bps.
- No parity.
- One stop bit.

## Quickstart Using Prebuilt Binaries

### Flash Prebuilt Binaries

Three binaries must be programmed in the board's external flash using the following procedure:

1. Set both switches to the right side.
2. Program `Binary/ai_fsbl.hex` (to be done once) (First stage boot loader).
3. Program `Binary/palm_detector_data.hex` (parameters of the palm detector model).
4. Program `Binary/hand_landmark_data.hex` (parameters of the hand landmarks model).
5. Program `Binary/x-cube-n6-ai-hand-landmarks-dk.hex` (firmware application) for STM32N6570-DK. For MB1940 NUCLEO-N657X0-Q select either
   `Binary/x-cube-n6-ai-hand-landmarks-nucleo-uvc.hex` or `Binary/x-cube-n6-ai-hand-landmarks-nucleo-spi.hex`
6. Set both switches to the left side.
7. Power cycle the board.

### How to Program Hex Files Using Command Line

Make sure to have the STM32CubeProgrammer bin folder added to your path.

```bash
export DKEL="<STM32CubeProgrammer_N6 Install Folder>/bin/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr"

# First Stage Boot Loader
STM32_Programmer_CLI -c port=SWD mode=HOTPLUG -el $DKEL -hardRst -w Binary/ai_fsbl.hex

# Network Parameters and Biases
STM32_Programmer_CLI -c port=SWD mode=HOTPLUG -el $DKEL -hardRst -w Binary/palm_detector_data.hex
STM32_Programmer_CLI -c port=SWD mode=HOTPLUG -el $DKEL -hardRst -w Binary/hand_landmark_data.hex

# Application Firmware
STM32_Programmer_CLI -c port=SWD mode=HOTPLUG -el $DKEL -hardRst -w Binary/x-cube-n6-ai-hand-landmarks-dk.hex
```

## Quickstart Using Source Code

Before building and running the application, you have to program `palm_detector_data.hex` and `hand_landmark_data.hex` (model weights and biases).

This step only has to be done once unless you change the AI model. See [Quickstart Using Prebuilt Binaries](#quickstart-using-prebuilt-binaries) for details.

More information about boot modes is available in the [Boot Overview](Doc/Boot-Overview.md).



### Application Build and Run - Boot from Flash

__Make sure to have both switches to the right side.__

Before running the commands below, make sure to have the necessary commands in your PATH.

1. Build the project using the provided `Makefile`:

```bash
make -j8
```

Once your app is built with Makefile, STM32CubeIDE, or EWARM, you must add a signature to the bin file:
```bash
STM32_SigningTool_CLI -bin build/Project.bin -nk -t ssbl -hv 2.3 -o build/Project_sign.bin
```

You can program the signed bin file at the address `0x70100000`.

```bash
export DKEL="<STM32CubeProgrammer_N6 Install Folder>/bin/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr"

# Adapt build path to your IDE
STM32_Programmer_CLI -c port=SWD mode=HOTPLUG -el $DKEL -hardRst -w build/Project_sign.bin 0x70100000
```

Note: Only the App binary needs to be programmed if the FSBL and network_data.hex were previously programmed.

__Set both switches to the left side.__

Do a power cycle to boot from the external flash.

### Application Build and Run - Dev Mode

__Make sure to have both switches to the right side.__
Intructions below are for STM32N6570-DK. For NUCLEO-N657X0-Q you have to select one of the two nucleo project according to your use case.

#### STM32CubeIDE

Double-click on `STM32CubeIDE/STM32N6570-DK/.project` to open the project in STM32CubeIDE. Build and run using the build and run buttons.

#### IAR EWARM

Double-click on `EWARM/STM32N6570-DK/x-cube-n6-ai-hand-landmarks-dk.eww` to open the project in the IAR IDE. Build and run using the build and run buttons.

#### Makefile

Before running the commands below, make sure to have the necessary commands in your PATH.

1. Build the project using the provided `Makefile`:

```bash
make -j8
```

2. Open a GDB server connected to the STM32 target:

```bash
ST-LINK_gdbserver -p 61234 -l 1 -d -s -cp /home/tanjiajun2002/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin -m 1 -g
```

3. In a separate terminal session, launch a GDB session to load the firmware image into the device memory:

```bash
$ arm-none-eabi-gdb build/Project.elf
(gdb) target remote :61234
(gdb) monitor reset
(gdb) load
(gdb) continue
```
