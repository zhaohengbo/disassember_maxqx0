DISASSEMBER FOR MAXQx0

This is a disassember for maxim's secure mcu MAXQ10, MAXQ20 and MAXQ30(E)

WARNING:A few instructions in MAXQ30(E) are supported due to the limit access to the INSTRUCTION SET

这是针对Maxim(美信)MAXQ10、MAXQ20和MAXQ30(E)系列MCU设计的反汇编工具

这并不是一个完善的工具，没有用任何设计技巧，只是机械的按照指令手册完成了指令的翻译工作

MAXQx0的CPU指令集设计的太过于鸡肋(猜测应该是早期为了简化译码器设计)，所有的指令都是MOVE DST,SRC的助记符，因此不存在不能译码的指令，但数据和指令也变得无法区分

注意：MAXQ30(E)的支持并不完善，尚有少部分指令不被支持，因为无法得到更详细的指令手册

test文件夹下提供了一个测试样例，这个测试样例中，MAX79356的G3固件的CPU1部分被反汇编