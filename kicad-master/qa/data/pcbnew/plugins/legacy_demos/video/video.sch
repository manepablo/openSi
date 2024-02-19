EESchema Schematic File Version 1
LIBS:power,device,conn,brooktre,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,analog_switches,philips,.\video.cache
EELAYER 20  0
EELAYER END
$Descr A3 16535 11700
Sheet 1 8
Title "Video"
Date "31 dec 2006"
Rev "2.0B"
Comp "Kicad EDA"
Comment1 "Feuille Principale"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	10600 5150 11300 5150
Text Label 10650 5150 0    60   ~
CSYNC-OUT
Wire Wire Line
	10600 5400 11300 5400
Text Label 10750 5400 0    60   ~
CLAMP
Text Label 10750 5300 0    60   ~
BLANK-
Wire Wire Line
	10600 5300 11300 5300
Wire Wire Line
	10700 5000 11300 5000
Text Label 10800 5000 0    60   ~
ACQ_ON
Wire Wire Line
	3800 7650 4400 7650
Text Label 3900 7650 0    60   ~
ACQ_ON
Text Label 14250 3550 0    60   ~
C_OUT
Text Label 14250 3750 0    60   ~
Y_OUT
Wire Wire Line
	14900 3750 14200 3750
Wire Wire Line
	14200 3550 14900 3550
Connection ~ 14800 3650
Connection ~ 14800 3350
Wire Wire Line
	14900 3350 14800 3350
Wire Wire Line
	14900 3150 14800 3150
Wire Wire Line
	14800 3150 14800 4050
Text Label 14800 1700 0    60   ~
Y_OUT
Text Label 14800 1300 0    60   ~
C_OUT
Wire Wire Line
	1450 7750 2000 7750
Wire Wire Line
	1450 7650 2000 7650
Wire Wire Line
	1450 7850 2000 7850
Text Label 1500 7750 0    60   ~
IRQ-
Text Label 1500 7650 0    60   ~
X_IRQ
Text Label 1500 7850 0    60   ~
IRQ_SRL
Wire Wire Line
	3800 1550 4350 1550
Wire Wire Line
	3800 1450 4350 1450
Wire Wire Line
	3800 1350 4350 1350
Text Label 3850 1550 0    60   ~
IRQ-
Text Label 3850 1450 0    60   ~
X_IRQ
Text Label 3850 1350 0    60   ~
IRQ_SRL
Text Label 3900 8650 0    60   ~
PCA[0..2]
Wire Bus Line
	3800 8650 4600 8650
Text Label 6200 3800 0    60   ~
PCA[0..1]
Wire Bus Line
	6100 3800 6900 3800
Wire Bus Line
	3800 5250 4600 5250
Text Label 3900 5250 0    60   ~
TVI[0..1]
Wire Wire Line
	10500 4700 11300 4700
Wire Wire Line
	10500 4800 11300 4800
Text Label 10600 4700 0    60   ~
ACCES_RAM-
Text Label 10600 4800 0    60   ~
WRITE_RAM
Wire Wire Line
	3800 8450 4600 8450
Wire Wire Line
	3800 8350 4600 8350
Text Label 3900 8450 0    60   ~
ACCES_RAM-
Text Label 3900 8350 0    60   ~
WRITE_RAM
Text Label 10600 4550 0    60   ~
DQ[0..31]
Wire Bus Line
	10500 4550 11300 4550
Wire Bus Line
	8800 6000 9750 6000
Text Label 8900 6000 0    60   ~
TVRAM[0..31]
Wire Wire Line
	10800 4250 11300 4250
Wire Wire Line
	10800 4350 11300 4350
Text Label 10850 4350 0    60   ~
CLKCAD
Text Label 10850 4250 0    60   ~
CLKCDA
Wire Wire Line
	10700 3950 11300 3950
Wire Wire Line
	10700 3850 11300 3850
Wire Wire Line
	10700 3750 11300 3750
Wire Wire Line
	10700 3650 11300 3650
Text Label 10800 3950 0    60   ~
X_PROG-
Text Label 10800 3850 0    60   ~
X_DONE
Text Label 10800 3750 0    60   ~
X_CLK
Text Label 10800 3650 0    60   ~
X_DATA
Wire Wire Line
	3800 8150 4400 8150
Wire Wire Line
	3800 8050 4400 8050
Wire Wire Line
	3800 7950 4400 7950
Wire Wire Line
	3800 7850 4400 7850
Text Label 3900 8150 0    60   ~
X_PROG-
Text Label 3900 8050 0    60   ~
X_DONE
Text Label 3900 7950 0    60   ~
X_CLK
Text Label 3900 7850 0    60   ~
X_DATA
Wire Bus Line
	12950 3950 13900 3950
Wire Bus Line
	12950 3850 13900 3850
Wire Bus Line
	12950 3750 13900 3750
Text Label 13050 3950 0    60   ~
TVB[0..7]
Text Label 13050 3850 0    60   ~
TVG[0..7]
Text Label 13050 3750 0    60   ~
TVR[0..7]
$Sheet
S 11300 3550 1650 1950
F0 "muxdata" 60
F1 "muxdata.sch" 60
F2 "X_DIN" I L 11300 3650 60 
F3 "X_CLK" I L 11300 3750 60 
F4 "CLKCDA" I L 11300 4250 60 
F5 "CLKCAD" I L 11300 4350 60 
F6 "X_DONE" O L 11300 3850 60 
F7 "X_PROG-" I L 11300 3950 60 
F8 "TVB[0..7]" B R 12950 3950 60 
F9 "TVG[0..7]" B R 12950 3850 60 
F10 "TVR[0..7]" B R 12950 3750 60 
F11 "VRAM[0..31]" B R 12950 4250 60 
F12 "DPC[0..31]" B L 11300 4550 60 
F13 "ACCES_RAM-" I L 11300 4700 60 
F14 "DATA_WR" I L 11300 4800 60 
F15 "ACQ_ON" I L 11300 5000 60 
F16 "CSYNC-OUT" I L 11300 5150 60 
F17 "BLANK-" I L 11300 5300 60 
F18 "CLAMP" I L 11300 5400 60 
$EndSheet
Wire Wire Line
	12600 1850 13300 1850
Text Label 12650 1850 0    60   ~
CSYNC-OUT
Text Label 12600 1500 0    60   ~
BLUE_OUT
Text Label 12600 1400 0    60   ~
GREEN_OUT
Text Label 12600 1300 0    60   ~
RED_OUT
Wire Wire Line
	12550 1500 13300 1500
Wire Wire Line
	12550 1400 13300 1400
Wire Wire Line
	12550 1300 13300 1300
Text Label 14200 3450 0    60   ~
BLUE_OUT
Text Label 14200 3250 0    60   ~
GREEN_OUT
Text Label 14200 3050 0    60   ~
RED_OUT
Wire Wire Line
	14150 3450 14900 3450
Wire Wire Line
	14150 3250 14900 3250
Wire Wire Line
	14150 3050 14900 3050
Text Label 8900 2350 0    60   ~
BLUE_OUT
Text Label 8900 2250 0    60   ~
GREEN_OUT
Text Label 8900 2150 0    60   ~
RED_OUT
Wire Wire Line
	8850 2350 9500 2350
Wire Wire Line
	8850 2250 9500 2250
Wire Wire Line
	8850 2150 9500 2150
$Comp
L GND #GND01
U 1 1 84DFBB6C
P 14800 4050
F 0 "#GND01" H 14800 4150 60  0001 C C
F 1 "GND" H 14800 3950 60  0000 C C
	1    14800 4050
	1    0    0    -1  
$EndComp
$Comp
L DB9 J4
U 1 1 84DFBB8F
P 15350 3450
F 0 "J4" H 15350 4000 70  0000 C C
F 1 "DB9FEM" H 15350 2900 70  0000 C C
	1    15350 3450
	1    0    0    1   
$EndComp
Connection ~ 14800 3850
Wire Wire Line
	14800 3650 14900 3650
Wire Wire Line
	14800 3850 14900 3850
Wire Wire Line
	14650 2100 15200 2100
Wire Wire Line
	15200 1700 14650 1700
Wire Wire Line
	14650 1300 15200 1300
$Comp
L GND #GND02
U 1 1 30705D34
P 15350 2300
F 0 "#GND02" H 15350 2400 60  0001 C C
F 1 "GND" H 15350 2200 60  0000 C C
	1    15350 2300
	1    0    0    -1  
$EndComp
$Comp
L BNC P8
U 1 1 30705D02
P 15350 2100
F 0 "P8" H 15360 2220 60  0000 C C
F 1 "BNC" V 15460 2040 40  0000 C C
	1    15350 2100
	1    0    0    -1  
$EndComp
$Sheet
S 13300 1150 1350 1100
F0 "modul" 60
F1 "modul.sch" 60
F2 "BLEU" I L 13300 1300 60 
F3 "VERT" I L 13300 1400 60 
F4 "ROUGE" I L 13300 1500 60 
F5 "CVBSOUT" O R 14650 2100 60 
F6 "YOUT" O R 14650 1700 60 
F7 "COUT" O R 14650 1300 60 
F8 "CSYNC-OUT" I L 13300 1850 60 
$EndSheet
Wire Wire Line
	9400 4350 8800 4350
Wire Wire Line
	9400 4450 8800 4450
Wire Wire Line
	9400 4550 8800 4550
Text Label 8900 4350 0    60   ~
F_PALIN
Text Label 8900 4450 0    60   ~
HD_PAL-
Text Label 8900 4550 0    60   ~
VD_PAL-
Wire Wire Line
	2000 7500 1400 7500
Wire Wire Line
	2000 7400 1400 7400
Wire Wire Line
	2000 7300 1400 7300
Text Label 1500 7500 0    60   ~
F_PALIN
Text Label 1500 7400 0    60   ~
HD_PAL-
Text Label 1500 7300 0    60   ~
VD_PAL-
Wire Wire Line
	6150 4400 6900 4400
Wire Wire Line
	6150 4300 6900 4300
Text Label 6200 4400 0    60   ~
BT812_WR-
Text Label 6200 4300 0    60   ~
BT812_RD-
Wire Wire Line
	3800 7400 4550 7400
Wire Wire Line
	3800 7300 4550 7300
Text Label 3850 7400 0    60   ~
BT812_WR-
Text Label 3850 7300 0    60   ~
BT812_RD-
Wire Wire Line
	6300 4950 6900 4950
Text Label 6350 4950 0    60   ~
OE_PAL-
Wire Wire Line
	8850 2600 9450 2600
Text Label 8900 2600 0    60   ~
OE_PAL-
Wire Wire Line
	6850 2500 6200 2500
Text Label 6250 2500 0    60   ~
BLUE_IN
Wire Wire Line
	6850 2400 6200 2400
Text Label 6250 2400 0    60   ~
GREEN_IN
Wire Wire Line
	6300 2300 6850 2300
Text Label 6350 2300 0    60   ~
RED_IN
Wire Wire Line
	6900 4000 6250 4000
Text Label 6300 4000 0    60   ~
GREEN_IN
Wire Wire Line
	6350 4100 6900 4100
Text Label 6400 4100 0    60   ~
RED_IN
Wire Wire Line
	11950 2800 11300 2800
Wire Wire Line
	11950 2000 11300 2000
Wire Wire Line
	11400 1200 11950 1200
Text Label 11350 2800 0    60   ~
BLUE_IN
Text Label 11350 2000 0    60   ~
GREEN_IN
Text Label 11450 1200 0    60   ~
RED_IN
$Comp
L GND #GND03
U 1 1 32FA02CD
P 12100 2200
F 0 "#GND03" H 12100 2200 40  0001 C C
F 1 "GND" H 12100 2130 40  0000 C C
	1    12100 2200
	1    0    0    -1  
$EndComp
$Comp
L GND #GND04
U 1 1 32FA02C6
P 12100 3000
F 0 "#GND04" H 12100 3000 40  0001 C C
F 1 "GND" H 12100 2930 40  0000 C C
	1    12100 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #GND05
U 1 1 32FA02C2
P 12100 1400
F 0 "#GND05" H 12100 1400 40  0001 C C
F 1 "GND" H 12100 1330 40  0000 C C
	1    12100 1400
	1    0    0    -1  
$EndComp
$Comp
L BNC P3
U 1 1 32F9F1AD
P 12100 2800
F 0 "P3" H 12110 2920 60  0000 C C
F 1 "BNC" V 12210 2740 40  0000 C C
	1    12100 2800
	1    0    0    -1  
$EndComp
$Comp
L BNC P2
U 1 1 32F9F1A3
P 12100 2000
F 0 "P2" H 12110 2120 60  0000 C C
F 1 "BNC" V 12210 1940 40  0000 C C
	1    12100 2000
	1    0    0    -1  
$EndComp
$Comp
L BNC P1
U 1 1 32F9F198
P 12100 1200
F 0 "P1" H 12110 1320 60  0000 C C
F 1 "BNC" V 12210 1140 40  0000 C C
	1    12100 1200
	1    0    0    -1  
$EndComp
Text Label 6200 3700 0    60   ~
DQ[0..7]
Wire Bus Line
	6100 3700 6900 3700
Wire Wire Line
	6350 3900 6900 3900
Text Label 6400 3900 0    60   ~
SYSRST-
Wire Wire Line
	3800 3000 4350 3000
Wire Bus Line
	8800 3950 9750 3950
Wire Bus Line
	8800 3850 9750 3850
Wire Bus Line
	8800 3750 9750 3750
Text Label 8900 3950 0    60   ~
TVB[0..7]
Text Label 8900 3850 0    60   ~
TVG[0..7]
Text Label 8900 3750 0    60   ~
TVR[0..7]
$Sheet
S 6900 3550 1900 1550
F0 "pal-ntsc.sch" 60
F1 "pal-ntsc.sch" 60
F2 "F_PALIN" O R 8800 4350 60 
F3 "TVR[0..7]" B R 8800 3750 60 
F4 "PC_D[0..7]" B L 6900 3700 60 
F5 "PC_A[0..1]" I L 6900 3800 60 
F6 "RESET-" I L 6900 3900 60 
F7 "GREEN_IN" I L 6900 4000 60 
F8 "RED_IN" I L 6900 4100 60 
F9 "OE_PAL-" I L 6900 4950 60 
F10 "HD_PAL-" O R 8800 4450 60 
F11 "VD_PAL-" O R 8800 4550 60 
F12 "TVB[0..7]" B R 8800 3950 60 
F13 "TVG[0..7]" B R 8800 3850 60 
F14 "BT812_WR-" I L 6900 4400 60 
F15 "BT812_RD-" I L 6900 4300 60 
$EndSheet
Text Label 6150 1200 0    60   ~
PCA[0..2]
Wire Bus Line
	6050 1200 6850 1200
Text Label 1450 5350 0    60   ~
RDFIFO-
Text Label 1450 5250 0    60   ~
WRFIFDO-
Wire Wire Line
	2000 5350 1400 5350
Wire Wire Line
	2000 5250 1400 5250
Text Label 1400 2150 0    60   ~
RDFIFO-
Text Label 1400 2050 0    60   ~
WRFIFDO-
Wire Wire Line
	1950 2150 1350 2150
Wire Wire Line
	1950 2050 1350 2050
Wire Wire Line
	3800 2850 4350 2850
Wire Wire Line
	3800 2750 4350 2750
Text Label 3900 2850 0    60   ~
RDEMPTY
Text Label 3900 2750 0    60   ~
WRFULL
Wire Wire Line
	1450 7100 2000 7100
Wire Wire Line
	1450 7000 2000 7000
Text Label 1500 7100 0    60   ~
RDEMPTY
Text Label 1500 7000 0    60   ~
WRFULL
Text Label 1550 5750 0    60   ~
PTRDY-
Wire Wire Line
	1400 5750 2000 5750
Wire Wire Line
	1350 6300 2000 6300
Text Label 1450 6300 0    60   ~
PTBURST
Wire Wire Line
	3800 2350 4450 2350
Text Label 3900 2350 0    60   ~
PTBURST
Text Label 1400 1800 0    60   ~
PTRDY-
Wire Wire Line
	1350 1800 1950 1800
Wire Wire Line
	2000 6400 1400 6400
Text Label 1450 6400 0    60   ~
SELECT-
Wire Wire Line
	1500 6200 2000 6200
Text Label 1600 6200 0    60   ~
PTWR
Wire Wire Line
	3800 2450 4300 2450
Wire Wire Line
	1950 1900 1350 1900
Text Label 3900 2450 0    60   ~
PTWR
Text Label 1400 1900 0    60   ~
SELECT-
Wire Wire Line
	1500 6100 2000 6100
Wire Wire Line
	1500 5650 2000 5650
Text Label 1550 5650 0    60   ~
PTATN-
Text Label 1550 6100 0    60   ~
PTADR-
Wire Wire Line
	2000 6500 1500 6500
Text Label 1500 6500 0    60   ~
BPCLK
Wire Wire Line
	3800 2550 4300 2550
Wire Wire Line
	3800 2050 4300 2050
Wire Wire Line
	3800 1950 4300 1950
Text Label 3900 2550 0    60   ~
BPCLK
Text Label 3850 1950 0    60   ~
PTATN-
Text Label 3850 2050 0    60   ~
PTADR-
Wire Bus Line
	2000 6800 1300 6800
Text Label 1350 6800 0    60   ~
BE-[0..3]
Wire Bus Line
	3800 2150 4600 2150
Text Label 3850 2150 0    60   ~
PTBE-[0..3]
Wire Bus Line
	1200 6000 2000 6000
Wire Bus Line
	1950 1200 1250 1200
Text Label 1300 1200 0    60   ~
BE-[0..3]
Text Label 1250 6000 0    60   ~
PTBE-[0..3]
Wire Wire Line
	1400 5900 2000 5900
Wire Wire Line
	1400 6700 2000 6700
Text Label 1500 6700 0    60   ~
PTNUM0
Text Label 1500 5900 0    60   ~
PTNUM1
Wire Wire Line
	1450 6600 2000 6600
Text Label 1500 6600 0    60   ~
SYSRST-
Text Label 3900 3000 0    60   ~
SYSRST-
Text Label 3900 1850 0    60   ~
PTNUM1
Text Label 3900 1750 0    60   ~
PTNUM0
Wire Wire Line
	3800 1850 4300 1850
Wire Wire Line
	3800 1750 4300 1750
Text Label 1300 4750 0    60   ~
ADR[2..6]
Text Label 3950 5050 0    60   ~
BLANK-
Wire Wire Line
	3800 5050 4350 5050
Text Label 3850 4750 0    60   ~
CSYNC-OUT
Text Label 1250 5500 0    60   ~
CSYNCIN-
Wire Wire Line
	1150 5500 2000 5500
Text Label 8950 1800 0    60   ~
CSYNCIN-
Wire Wire Line
	8850 1800 9700 1800
Wire Wire Line
	6150 2850 6850 2850
Wire Wire Line
	3800 4750 4500 4750
Text Label 6200 2850 0    60   ~
CSYNC-OUT
Text Label 6550 5950 0    60   ~
WRAM-
Wire Wire Line
	6450 5950 6950 5950
Text Label 3900 6300 0    60   ~
WRAM-
Wire Wire Line
	3800 6300 4300 6300
Wire Wire Line
	6350 1400 6850 1400
Wire Wire Line
	6350 1500 6850 1500
Wire Wire Line
	6350 1600 6850 1600
Wire Wire Line
	6350 1700 6850 1700
Text Label 6400 1400 0    60   ~
WRCAD-
Text Label 6400 1500 0    60   ~
RDCAD-
Text Label 6400 1600 0    60   ~
WRCDA-
Text Label 6400 1700 0    60   ~
RDCDA-
Wire Wire Line
	3800 7200 4300 7200
Wire Wire Line
	3800 7100 4300 7100
Wire Wire Line
	3800 7000 4300 7000
Wire Wire Line
	3800 6900 4300 6900
Text Label 3850 7200 0    60   ~
WRCAD-
Text Label 3850 7100 0    60   ~
RDCAD-
Text Label 3850 7000 0    60   ~
WRCDA-
Text Label 3850 6900 0    60   ~
RDCDA-
Text Label 6550 7300 0    60   ~
RAS7-
Text Label 6550 7200 0    60   ~
RAS6-
Text Label 6550 7100 0    60   ~
RAS5-
Text Label 6550 7000 0    60   ~
RAS4-
Text Label 6550 6900 0    60   ~
RAS3-
Text Label 6550 6800 0    60   ~
RAS2-
Text Label 6550 6700 0    60   ~
RAS1-
Text Label 6550 6600 0    60   ~
RAS0-
Wire Wire Line
	6450 7300 6950 7300
Wire Wire Line
	6450 7200 6950 7200
Wire Wire Line
	6450 7100 6950 7100
Wire Wire Line
	6450 7000 6950 7000
Wire Wire Line
	6450 6900 6950 6900
Wire Wire Line
	6450 6800 6950 6800
Wire Wire Line
	6450 6700 6950 6700
Wire Wire Line
	6450 6600 6950 6600
Text Label 6550 6400 0    60   ~
CAS3-
Text Label 6550 6300 0    60   ~
CAS2-
Text Label 6550 6200 0    60   ~
CAS1-
Text Label 6550 6100 0    60   ~
CAS0-
Wire Wire Line
	6450 6400 6950 6400
Wire Wire Line
	6450 6300 6950 6300
Wire Wire Line
	6450 6200 6950 6200
Wire Wire Line
	6450 6100 6950 6100
Text Label 3900 6700 0    60   ~
CAS3-
Text Label 3900 6600 0    60   ~
CAS2-
Text Label 3900 6500 0    60   ~
CAS1-
Text Label 3900 6400 0    60   ~
CAS0-
Text Label 3900 6150 0    60   ~
RAS7-
Text Label 3900 6050 0    60   ~
RAS6-
Text Label 3900 5950 0    60   ~
RAS5-
Text Label 3900 5850 0    60   ~
RAS4-
Text Label 3900 5750 0    60   ~
RAS3-
Text Label 3900 5650 0    60   ~
RAS2-
Text Label 3900 5550 0    60   ~
RAS1-
Text Label 3900 5450 0    60   ~
RAS0-
Wire Wire Line
	3800 6700 4300 6700
Wire Wire Line
	3800 6600 4300 6600
Wire Wire Line
	3800 6500 4300 6500
Wire Wire Line
	3800 6400 4300 6400
Wire Wire Line
	3800 6150 4300 6150
Wire Wire Line
	3800 6050 4300 6050
Wire Wire Line
	3800 5950 4300 5950
Wire Wire Line
	3800 5850 4300 5850
Wire Wire Line
	3800 5750 4300 5750
Wire Wire Line
	3800 5650 4300 5650
Wire Wire Line
	3800 5550 4300 5550
Wire Wire Line
	3800 5450 4300 5450
Text Label 1500 4950 0    60   ~
/PCWR
Text Label 1500 5050 0    60   ~
/PCRD
Wire Wire Line
	1300 4950 2000 4950
Wire Wire Line
	1300 5050 2000 5050
Wire Bus Line
	1200 4750 2000 4750
Text Label 1300 4650 0    60   ~
DQ[0..15]
Wire Bus Line
	1200 4650 2000 4650
Wire Wire Line
	6150 2750 6850 2750
Text Label 6300 2750 0    60   ~
CLAMP
Wire Wire Line
	3800 4950 4300 4950
Text Label 3950 4950 0    60   ~
CLAMP
Wire Bus Line
	6100 7450 6950 7450
Text Label 6250 7450 0    60   ~
MXA[0..10]
Wire Bus Line
	3800 5350 4600 5350
Text Label 3900 5350 0    60   ~
MXA[0..10]
Wire Wire Line
	6350 2100 6850 2100
Wire Wire Line
	6350 2000 6850 2000
Text Label 6400 2000 0    60   ~
CLKCAD
Text Label 6400 2100 0    60   ~
CLKCDA
Wire Wire Line
	3800 4650 4300 4650
Wire Wire Line
	3800 4550 4300 4550
Text Label 3850 4550 0    60   ~
CLKCAD
Text Label 3850 4650 0    60   ~
CLKCDA
$Sheet
S 2000 4350 1800 4650
F0 "graphic" 60
F1 "graphic.sch" 60
F2 "CSYNC-OUT" O R 3800 4750 60 
F3 "DQ[0..15]" B L 2000 4650 60 
F4 "ADR[2..6]" O L 2000 4750 60 
F5 "CADCLK" O R 3800 4550 60 
F6 "CDACLK" O R 3800 4650 60 
F7 "CLAMP" O R 3800 4950 60 
F8 "CSYNCIN-" I L 2000 5500 60 
F9 "MXA[0..10]" O R 3800 5350 60 
F10 "RAS7-" O R 3800 6150 60 
F11 "RAS6-" O R 3800 6050 60 
F12 "RAS5-" O R 3800 5950 60 
F13 "RAS4-" O R 3800 5850 60 
F14 "RAS3-" O R 3800 5750 60 
F15 "RAS2-" O R 3800 5650 60 
F16 "RAS1-" O R 3800 5550 60 
F17 "RAS0-" O R 3800 5450 60 
F18 "CAS2-" O R 3800 6600 60 
F19 "CAS1-" O R 3800 6500 60 
F20 "CAS0-" O R 3800 6400 60 
F21 "RD-" I L 2000 5050 60 
F22 "WR-" I L 2000 4950 60 
F23 "CAS3-" O R 3800 6700 60 
F24 "RDCDA-" O R 3800 6900 60 
F25 "WRCDA-" O R 3800 7000 60 
F26 "RDCAD-" O R 3800 7100 60 
F27 "WRCAD-" O R 3800 7200 60 
F28 "WRAM-" O R 3800 6300 60 
F29 "BLANK-" O R 3800 5050 60 
F30 "PTATN-" I L 2000 5650 60 
F31 "PTRDY-" O L 2000 5750 60 
F32 "PTNUM1" I L 2000 5900 60 
F33 "PTBE-[0..3]" I L 2000 6000 60 
F34 "PTADR-" O L 2000 6100 60 
F35 "PTWR" I L 2000 6200 60 
F36 "PTBURST-" I L 2000 6300 60 
F37 "SELECT-" O L 2000 6400 60 
F38 "BPCLK" I L 2000 6500 60 
F39 "SYSRST-" I L 2000 6600 60 
F40 "PTNUM0" I L 2000 6700 60 
F41 "BE-[0..3]" O L 2000 6800 60 
F42 "WRFULL" O L 2000 7000 60 
F43 "RDEMPTY" O L 2000 7100 60 
F44 "RDFIFO-" O L 2000 5350 60 
F45 "WRFIFO-" O L 2000 5250 60 
F46 "BT812_WR-" O R 3800 7400 60 
F47 "BT812_RD-" O R 3800 7300 60 
F48 "VD_PAL-" I L 2000 7300 60 
F49 "HD_PAL-" I L 2000 7400 60 
F50 "F_PALIN" I L 2000 7500 60 
F51 "X_DOUT" O R 3800 7850 60 
F52 "X_CLK" O R 3800 7950 60 
F53 "X_DONE" O R 3800 8050 60 
F54 "X_PROG-" O R 3800 8150 60 
F55 "WRITE_RAM" O R 3800 8350 60 
F56 "ACCES_RAM-" O R 3800 8450 60 
F57 "TVI[0..1]" O R 3800 5250 60 
F58 "PCA[0..2]" O R 3800 8650 60 
F59 "X_IRQ" B L 2000 7650 60 
F60 "IRQ-" I L 2000 7750 60 
F61 "IRQ_SLR" B L 2000 7850 60 
F62 "ACQ_ON" O R 3800 7650 60 
$EndSheet
Wire Bus Line
	8850 1600 9800 1600
Text Label 8950 1600 0    60   ~
TVI[0..1]
Wire Bus Line
	12950 4250 13900 4250
Text Label 13050 4250 0    60   ~
TVRAM[0..31]
$Sheet
S 6950 5850 1850 1700
F0 "RAMS" 60
F1 "rams.sch" 60
F2 "TVRAM[0..31]" T R 8800 6000 60 
F3 "WRAM-" I L 6950 5950 60 
F4 "CAS3-" I L 6950 6400 60 
F5 "RAS7-" I L 6950 7300 60 
F6 "RAS6-" I L 6950 7200 60 
F7 "RAS5-" I L 6950 7100 60 
F8 "RAS4-" I L 6950 7000 60 
F9 "RAS3-" I L 6950 6900 60 
F10 "RAS2-" I L 6950 6800 60 
F11 "RAS1-" I L 6950 6700 60 
F12 "RAS0-" I L 6950 6600 60 
F13 "CAS2-" I L 6950 6300 60 
F14 "CAS1-" I L 6950 6200 60 
F15 "CAS0-" I L 6950 6100 60 
F16 "MXA[0..10]" I L 6950 7450 60 
$EndSheet
Wire Bus Line
	6850 1300 6000 1300
Wire Bus Line
	8850 1500 9800 1500
Wire Bus Line
	8850 1400 9800 1400
Wire Bus Line
	8850 1300 9800 1300
Text Label 8950 1500 0    60   ~
TVB[0..7]
Text Label 8950 1400 0    60   ~
TVG[0..7]
$Sheet
S 1950 1000 1850 2400
F0 "buspci.sch" 60
F1 "bus_pci.sch" 60
F2 "WR-" I L 1950 1350 60 
F3 "RD-" I L 1950 1450 60 
F4 "DQ[0..31]" B R 3800 1200 60 
F5 "ADR[2..6]" I L 1950 1600 60 
F6 "BE-[0..3]" I L 1950 1200 60 
F7 "IRQ_SRL" B R 3800 1350 60 
F8 "X_IRQ" B R 3800 1450 60 
F9 "PTNUM0" O R 3800 1750 60 
F10 "PTNUM1" O R 3800 1850 60 
F11 "PTATN-" O R 3800 1950 60 
F12 "PTRDY-" I L 1950 1800 60 
F13 "PTBE-[0..3]" O R 3800 2150 60 
F14 "PTWR" O R 3800 2450 60 
F15 "PTBURST-" O R 3800 2350 60 
F16 "SELECT-" I L 1950 1900 60 
F17 "BPCLK" O R 3800 2550 60 
F18 "SYSRST-" O R 3800 3000 60 
F19 "WRFULL" O R 3800 2750 60 
F20 "RDEMPTY" O R 3800 2850 60 
F21 "WRFIFO-" I L 1950 2050 60 
F22 "RDFIFO-" I L 1950 2150 60 
F23 "IRQ-" O R 3800 1550 60 
F24 "PTADR-" O R 3800 2050 60 
$EndSheet
Text Label 1250 1600 0    60   ~
ADR[2..6]
Text Label 1400 1350 0    60   ~
/PCWR
Text Label 1400 1450 0    60   ~
/PCRD
Text Label 6150 1300 0    60   ~
DQ[0..7]
Text Label 8950 1300 0    60   ~
TVR[0..7]
Text Label 3900 1200 0    60   ~
DQ[0..31]
Text Label 6300 2650 0    60   ~
BLANK-
Wire Wire Line
	1250 1350 1950 1350
Wire Wire Line
	1250 1450 1950 1450
Wire Wire Line
	6150 2650 6850 2650
Wire Bus Line
	3800 1200 4600 1200
Wire Bus Line
	1150 1600 1950 1600
$Sheet
S 6850 1050 2000 2150
F0 "ESVIDEO-RVB" 60
F1 "esvideo.sch" 60
F2 "DPC[0..7]" B L 6850 1300 60 
F3 "TVR[0..7]" O R 8850 1300 60 
F4 "BLANK-" I L 6850 2650 60 
F5 "TVG[0..7]" O R 8850 1400 60 
F6 "TVB[0..7]" O R 8850 1500 60 
F7 "WRCAD-" I L 6850 1400 60 
F8 "RDCAD-" I L 6850 1500 60 
F9 "WRCDA-" I L 6850 1600 60 
F10 "RDCDA-" I L 6850 1700 60 
F11 "CSYNCIN-" O R 8850 1800 60 
F12 "CSYNCOUT-" I L 6850 2850 60 
F13 "CLKCAD" I L 6850 2000 60 
F14 "CLKCDA" I L 6850 2100 60 
F15 "TVI[0..1]" O R 8850 1600 60 
F16 "CLAMP" I L 6850 2750 60 
F17 "BLUE_IN" I L 6850 2500 60 
F18 "GREEN_IN" I L 6850 2400 60 
F19 "RED_IN" I L 6850 2300 60 
F20 "RED" O R 8850 2150 60 
F21 "GREEN" O R 8850 2250 60 
F22 "BLUE" O R 8850 2350 60 
F23 "PCA[0..2]" I L 6850 1200 60 
F24 "OE_PAL-" O R 8850 2600 60 
$EndSheet
$EndSCHEMATC