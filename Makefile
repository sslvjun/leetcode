ROOT_PATH=$(shell pwd)
BUILD_PATH=$(ROOT_PATH)/build
TARGET=$(BUILD_PATH)/leetcode

SOURCES=$(shell find $(ROOT_PATH) -name '*.c')
OBJS=$(patsubst %.c,%.o,$(subst $(ROOT_PATH),$(BUILD_PATH),$(SOURCES)))
DEPS=$(patsubst %.o,%.d,$(OBJS))

CFLAGS := -g
INCLUDE:= -I$(ROOT_PATH)
LIB    :=

all: $(TARGET)

$(TARGET): $(OBJS)
	@if [ ! -d $(BUILD_PATH) ]; then \
		mkdir -p $(BUILD_PATH); \
	fi
	@gcc -o $@ $(OBJS) $(LIB)
	@echo LD $@

-include $(DEPS)

$(BUILD_PATH)/%.o:$(ROOT_PATH)/%.c
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
	fi
	@gcc $(CFLAGS) $(INCLUDE) -MM -MT $@ -MT $(patsubst %.o,%.d,$@) -MF $(patsubst %.o,%.d,$@) $<
	@gcc -c -o $@ $< $(CFLAGS) $(INCLUDE)
	@echo CC $@

clean:
	rm -rf $(BUILD_PATH)

