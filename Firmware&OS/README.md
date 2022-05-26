# Firmware&OS Guide 

As we offer you two core board options on Cheetah Mix, so there are 3 combinations of firmware and OS.

1. RaspiberryPi CM4(OctoPi OS) + MCU(Marlin)
2. RaspiberryPi CM4(OctoPi OS with Klipper) + MCU(Klipper)
3. M10 core(KlipperWrt OS) + MCU(Klipper)

We provide you OctoPi image in this folder, check the `README.md` file there.

## 1.1 OS Guide

### 1.1.1 RaspiberryPi OS

We can run several OS on RaspberryPi, but i recommend to start from [OctoPi](https://github.com/guysoft/OctoPi) OS first as it already integrated several softwares and Optimize the system for our use case. You can try our provided OS `OctoPi-octodash.img` in this folder or use OctoPi v0.18.0 or later - see the [OctoPi releases](https://github.com/guysoft/OctoPi/releases) for release information. 

##### Provided OctoPi

We provide you OctoPi OS, it is base on OctoPi v0.18.0 integrated Octodash and Klipper. 

You can login in Octoprint with the following account and password.

```
Account: FYSETC
Password: 12345678
```

OS SSH login account and password

```
Account: pi
Password: raspberry
```

Now, we can flash the OS to CM4.

#### 1.1.1.1 Flash RaspiberryPi OS

CM4 has two types, with or without eMMC.

##### No eMMC

If your CM4 don't have eMMC, follow the steps below to flash OS.

Step 1: Power off the board

Step 2: Install CM4 to Cheetah Mix

Step 3: Flash OS to micro-sd card

 You can follow the instruction here to flash downloaded OctoPi OS to your micro-sd card, then insert your micro-SD card to SYS_SD slot.

![](..\images\sys_sd.png)

##### eMMC integrated

If your CM4 has eMMC then follow the steps below.

Step 1: Power off the board

Step 2: Install CM4 to Cheetah Mix

Step 3: Set Pi boot jumper

![image-20220225152923346](..\images\pi_boot.png)

Step 4: Connect Cheetah Mix

Connect Cheetah Mix to your computer with micro-usb cable and power on Cheetah Mix.

![](..\images\pi_usb.png)

Step 4: Flash OS to CM4 eMMC

Follow the instruction [here](https://www.raspberrypi.com/documentation/computers/compute-module.html#for-windows-users) on RaspberryPi website.

#### 1.1.1.2 Find IP address

If you flash Raspberrypi OS raspbian, you should refer to [this](https://www.raspberrypi.com/documentation/computers/remote-access.html#ip-address). 

If you use OctoPi OS, you can follow [here](https://community.octoprint.org/t/finding-the-pis-ip-address/844). 

If you use our OctoPi OS and your Cheetah Mix is runing our provided Marlin, you can send `M711` command from your computer to get IP address from Cheetah Mix TypeC USB port( need install serial tool on your computer). Remember to remove two jumpers below or it will connect to RaspberryPi CM4 but not your computer.

 ![](..\images\usb_jumper.png)

#### 1.1.1.3 Expand OS fs

If you use our provided OctoPi OS image, after you flash OS you need to expand the file system. Follow the instruction [here](https://piwithvic.com/raspberry-pi-expand-filesystem-micro-sd-card).

#### 1.1.1.4 Config Octoprint

Our OctoPi OS is pre-config for Marlin, if you want to run Klipper, you need to config Octoprint, follow the instruction [here](https://www.klipper3d.org/Installation.html#configuring-octoprint-to-use-klipper).

### 1.1.2 KlipperWrt

We can follow the steps below to install KlipperWrt

Step 1: Power off motherboard

Step 2: Install m10 core board to Cheetah Mix

Step 3: Insert an empty micro-sd card to `SYS_SD` slot

Step 4: Connect Cheetah Mix directly to your computer with network cable

Step 5: Download KlipperWrt from [here](https://github.com/ihrapsa/KlipperWrt).

Step 6: Prepare KlipperWrt firmware

Copy and rename KlipperWrt file `MainsailWrt-SYSUPGRADE-ramips-mt76x8-creality_wb-01-squashfs-k5.10.46.bin` or `fluiddWrt-SYSUPGRADE-ramips-mt76x8-creality_wb-01-squashfs-k5.10.46.bin` ( you can find them in `KlipperWrt\Firmware\OpenWrt_snapshot` folder) to `root_uImage.bin`.

Step 7: Reset m10

Press and hold `m10RST` button and power on the Cheetah Mix with 24v, wait for 6s then loose the button

Step 8: Upload firmware

Visit 192.168.1.1 web page. Click `选择文件` button ![](..\images\m10_choose_file.png) and choose `root_uImage.bin` and click `Firmware update` button to upload firmware to m10, wait for finish.

Step 8: Reboot

Power off and power on Cheetah Mix

Wait for your computer to recognize m10 network ![](..\images\m10_network.png)

Step 9: Install KlipperWrt software

Then follow the instruction [here](https://github.com/ihrapsa/KlipperWrt#automatic-steps) (i recommend [this method](https://github.com/ihrapsa/KlipperWrt#extroot-script-method))to install and config KlipperWrt software. 

## 1.2 Firmware Guide

### 1.2.1 Marlin

#### 1.2.1.1 Download Vscode + platformio

To compile the firmware , you need to install Visual Studio Code and the platformio pulg-in. You can learn more on Marlin official website [here](https://marlinfw.org/docs/basics/auto_build_marlin.html).

#### 1.2.1.2 Config firmware

You can find Marlin source code in `firmware/Marlin` folder. We already set the base configurations of motherboard, so you can change the configurations in `configuration.h` and `configuration_adv.h` file according to your machine such machine size,stepper direction etc base on our work.

#### 1.2.1.3 Compile the firmware

Open Vscode and open platformio main page and click the "Open Project" button , and direct to the folder where you put your firmware.

![1561099422559](..\images\AIO_f1.png)

If everything goes fine , at the bottom you can see several buttons

![1561099546202](..\images\AIO_f2.png)

The check mark is for compiling , click it to compile. You can find built `firmware.bin` at `Marlin\.pio\build\CREALITY_3D_PI` folder.

#### 1.2.1.4 Upload firmware

Follow Firmware Upload guide [here](#jump0).

### 1.2.2 Klipper

We put Klipper related files like `printer.cfg` in `Klipper` folder. Please read the `README.md` there for details. 

If you want to use Klipper. You need to follow the Klipper [installation guide](https://www.klipper3d.org/Installation.html) to install [Klipper](https://github.com/KevinOConnor/klipper) first (M10 core don't have build environment, so still need raspberrypi to build klipper). On the step of building, we call `make menuconfig` to choose build options, please select options for Cheetah Mix as describe below.

#### 1.2.2.1 menuconfig

Please choose these options for Cheetah Mix.

- ##### Enable `extra low-level configuration options`

- ##### Micro-controller Architecture

Select `STMicroelectronics STM32`

- ##### Processor model

Select `STM32F401`

- ##### Clock reference

Select `8 MHz crystal`

- ##### Bootloader offset

  You have two choose, select it according to your flashed bootloader. 

- ###### 1. No bootloader

If you choose `No bootloader` bootloader offset in Klipper `make menuconfig`, means you don't have any bootloader flashed or don't want any bootloader, then you can follow [Upload the firmware(DFU)](#jump) to upload the firmware to Cheetah Mix board. **But you need to set the 'Start address' to 0x08000000**. We build a pre-build firmware using this option for you `klipper.bin` in `Klipper` folder. 

**Note: pre-build firmware will be outdated if Klipper update and will not match your new downloaded Klipper and cause annoying issues. We recommend to build the firmware yourself with the options we provide.**

![image-20210705151440643](..\images\menuconfig.png)

- ###### 2. 32KiB bootloader

At the time i writing this README, Klipper don't have 32Kib bootloader support originally, so we need to change Klipper code first, you can follow my PR [here](https://github.com/Klipper3d/klipper/pull/5155) to change the code. After that `32KiB bootloader ` will show up.

If you choose `32kiB bootloader`，we need Cheetah Mix board bootloader named `Bootloader.hex` to work with this option. 

**Note: Cheetah Mix has stock bootloader when it leave the factory, so if you did not crack the bootloader, you don't need to flash bootloader. But if crashed, flash it. The bootloader is in the folder named `bootloader`, please follow the README in that folder to flash.**

We provide pre-build firmwares with `32KiB bootloader` named `klipper-32k.bin`, it is in `firmware&OS` folder. 

**Note pre-build firmware will be outdated if Klipper update and will not match your new downloaded Klipper and cause annoying issues. We recommend to build the firmware yourself.**

![image-20210705151337765](..\images\menuconfig2.png)

- ##### Communication interface

  Select the high-light option show below.


![image-20210705154625673](..\images\menuconfig3.png)

#### 1.2.2.2 Compile firmware

```
make
```

#### 1.2.2.3 Upload firmware

Follow Firmware Update guide [below](#jump0).

#### 1.2.2.3 Config Klipper

You should config Klipper printer.cfg after uploading. Follow the instruction [here](https://www.klipper3d.org/Installation.html#configuring-klipper).

### 1.2.3  <span id="jump0">Firmware Upload</span>

We provide several ways to upload the firmware including SDCARD, dfu-util, DFU and platformio.

#### 1.2.3.1 <span id="jump1">Upload the firmware(SDCARD)</span>

Cheetah Mix has stock bootloader, so we can upload the firmware with SD card. Copy your compiled firmware file ```firmware.bin```(If you use klipper firmware, you need to rename `klipper.bin` to `firmware.bin`) to the SD card , and insert it to the SD card slot which is at the right side of the board, and then power on the board. You may need to wait for about 30s to finish uploading. And the `firmware.bin` renamed to `old.bin` when it finished. You can check it on your computer.

**Note: If you once upload the firmware to Cheetah Mix flash address `0x08000000`, then the bootloader will be cracked (as it stays at 0x08000000~0x08008000), then you need to upload the bootloader to Cheetah Mix yourself, please follow the README in `Bootloader` folder to flash the bootloader.**

##### Remember to set jumper on RaspberryPi USB connection pins and click the mcuRST button after uploading.

![](..\images\usb_jumper.png)

**Note: If you have Klipper connection issue, you can try to power off-on the board.**

#### 1.2.3.2 <span id="jump4">Upload the firmware(dfu-util)</span>

This method works in linux, that means should work in raspberry pi.

##### Step 1. Set jumpers and connect

1. First power off the board
2. Set jumper for 5v  <img src="E:/Projects/BOARD-FYSETC-CHEETAH_MIX/Creality-3D_Pi/Creality-3D_Pi/images/5v_jumper.jpg" style="zoom:50%;" />
3. Set jumper on RaspberryPi USB connection pins ![](E:/Projects/BOARD-FYSETC-CHEETAH_MIX/Creality-3D_Pi/Creality-3D_Pi/images/usb_jumper.png)
4. Power up the board with 24v 

##### Step 2. Install dfu-util

Check if stm32flash is installed by `stm32flash -h`, it will shows like

```
Usage: stm32flash [-bvngfhc] [-[rw] filename] [tty_device | i2c_device]
        -a bus_address  Bus address (e.g. for I2C port)
        -b rate         Baud rate (default 57600)
        -m mode         Serial port mode (default 8e1)
        -r filename     Read flash to file (or - stdout)
        -w filename     Write flash from file (or - stdout)
        -C              Compute CRC of flash content
        -u              Disable the flash write-protection
        -j              Enable the flash read-protection
        -k              Disable the flash read-protection
        -o              Erase only
        -e n            Only erase n pages before writing the flash
        -v              Verify writes
        -n count        Retry failed writes up to count times (default 10)
        -g address      Start execution at specified address (0 = flash start)
        -S address[:length]     Specify start address and optionally length for
                                read/write/erase operations
        -F RX_length[:TX_length]  Specify the max length of RX and TX frame
        -s start_page   Flash at specified page (0 = flash start)
        -f              Force binary parser
        -h              Show this help
        -c              Resume the connection (don't send initial INIT)
                        *Baud rate must be kept the same as the first init*
                        This is useful if the reset fails
        -R              Reset device at exit.
        -i GPIO_string  GPIO sequence to enter/exit bootloader mode
                        GPIO_string=[entry_seq][:[exit_seq]]
                        sequence=[[-]signal]&|,[sequence]
```

If not , you should install it first, you can get it [here](https://sourceforge.net/projects/stm32flash/). Or use the package manager of your distribution to get the latest version, like

```
sudo apt-get install stm32flash
```

##### Step 3. Use command to upload firmware

Enter the folder which contains your firmware. Then use the command below to upload the firmware. You should replace `firmware.bin` below with your built firmware bin(or hex) file location like `out/klipper.bin`. If you use klipper firmware and you choose boot address `No bootloader` when compiling it, you need to change flash address `0x08008000` to `0x08000000`.

```
stm32flash -R -w firmware.bin -S 0x08008000 -v -i rts,,-dtr,,dtr, /dev/ttyUSB0
```

**Note: if you failed once, try again or click the mcuRST button and try again**

##### Step 4. Set jumper on RaspberryPi USB connection pins and click the mcuRST button

![](..\images\usb_jumper.png)

**Note: If you have Klipper connection issue, you can try to power off-on the board.**

#### 1.2.3.3 <span id="jump">Upload the firmware(DFU)</span>

This method only works in Windows OS.

##### Step 1. Download stm32cubeprogrammer 

You can download it from ST website.

https://www.st.com/zh/development-tools/stm32cubeprog.html

Open the STM32CubeProgrammer software.

![1574332767079](..\images\S6_1574332767079.png)

##### Step 2. Enter DFU mode

1. First power off the board
2. Set jumper on 5V <img src="..\images\5v_jumper.jpg" style="zoom:50%;" />
3. Place jumper on BT0 to 3.3V pin ![](..\images\mcu_boot.png)
4. Make sure no jumpers on USB connection pins ![](..\images\usb_jumper_no.png)
4. Connect board TypeC USB port and your computer  with USB cable
5. Power up the board with 24v 

Now the board is in DFU mode. If not, try to click the mcu reset button `mcuRST`. 

***REMEMBER to remove BT0 jumper if you finish uploading firmware or it will enter DFU mode again.***

##### Step 3. Upload the firmware

Now you can connect and flash the Spider board with stm32cubeprogrammer with the following operation.

![1574386395071](..\images\S6_1574386395071.png)

Do as the red number shows in the screen shot.

1. Click the button to find the DFU port.
2. Connect the DFU 
3. Choose the "firmware.bin" file. (or .hex file).
4. Fill in the 'Start address' `0x08008000`. (If you use klipper firmware and you choose boot address `No bootloader` when compiling it, you need to change address `0x08008000` to `0x08000000`.).
5. Start Programming

##### Step 4. Set jumper on RaspberryPi USB connection pins and click the mcuRST button

![](..\images\usb_jumper.png)

**Note: If you have Klipper connection issue, you can try to power off-on the board.**

#### 1.2.3.4 Upload the firmware(platformio)

If you compile Marlin yourself with platformio, you can follow the instructions below to upload the firmware.

##### Step 1. Enter DFU mode first

1. First power off the board
2. Set jumper on 5V <img src="..\images\5v_jumper.jpg" style="zoom:50%;" />
3. Place jumper on BT0 to 3.3V pin ![](..\images\mcu_boot.png)
4. Make sure no jumpers on USB connection pins ![](..\images\usb_jumper_no.png)
5. Connect board TypeC USB port and your computer
6. Power up the board with 24v 

Now the board is in DFU mode. If not, try to click the mcu reset button `mcuRST`. 

***REMEMBER to remove BT0 jumper if you finish uploading firmware or it will enter DFU mode again.***

##### Step 2. Click the upload button to upload firmware

![](..\images\platformio_upload.png)

##### Step 3. Set jumper on RaspberryPi USB connection pins and click the mcuRST button

![](..\images\usb_jumper.png)

**Note: If you have Klipper connection issue, you can try to power off-on the board.**
