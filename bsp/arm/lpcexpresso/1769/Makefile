#
#	Top-Level Makefile for BitThunder on the lpcxpresso 1769 platform.
#

BASE=$(shell pwd)/../../../../
BUILD_BASE=$(BASE)
MODULE_NAME="lpc-bsp"

TARGETS=kernel.img

TARGET_DEPS=kernel.elf


BUILD_DIR=$(shell pwd)/build/

TOOLCHAIN= /opt/codesourcery/bin/arm-none-eabi-

include $(BASE).dbuild/dbuild.mk

test:
	@echo $(BSP_DIR)

all: kernel.elf kernel.list kernel.img kernel.syms
	$(Q)$(SIZE) kernel.elf

kernel.img: kernel.elf
	$(Q)$(PRETTY) IMAGE $(MODULE_NAME) $@
	$(Q)$(OBJCOPY) kernel.elf -O binary $@

kernel.list: kernel.elf
	$(Q)$(PRETTY) LIST $(MODULE_NAME) $@
	$(Q)$(OBJDUMP) -D kernel.elf > $@

kernel.syms: kernel.elf
#	$(Q)$(PRETTY) SYMS $(MODULE_NAME) $@
#	$(Q)$(OBJDUMP) -t kernel.elf > $@




kernel.elf: LDFLAGS += -L"/opt/codesourcery/lib/gcc/arm-none-eabi/4.7.2/thumb2"
kernel.elf: LDFLAGS += -L"/opt/codesourcery/arm-none-eabi/lib/thumb2"
kernel.elf: LDLIBS += -lc -lgcc
kernel.elf: $(OBJECTS)
	$(Q)$(PRETTY) --dbuild "LD" $(MODULE_NAME) $@
	$(Q)$(LD) $(LDFLAGS) --gc-sections -Map kernel.map -o $@ -T $(LINKER_SCRIPT) $(OBJECTS) $(LDLIBS)

