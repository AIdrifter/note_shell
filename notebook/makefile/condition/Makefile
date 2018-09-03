include config.mk

all:

#ifeq ($(TEE_ENABLE), 1)
#ifeq ($(shell [[ $(TEE_ENABLE) == 1 || $(OPTEE_ENABLE) == 1 ]] && echo true ),true)
ifneq (,$(filter 1,$(TEE_ENABLE) $(OPTEE_ENABLE)))
	@echo "success"
else
	@echo "failed"
endif
