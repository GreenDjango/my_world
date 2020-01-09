##
## EPITECH PROJECT, 2018
## Makefile, by fred
## File description:
## Need for build C-Project
##

#-------	--------#
#	  Flag		#
#-------	--------#
cc	=	gcc
header	=	-I include
cflags	=	-W -Wall -Wextra -fno-builtin $(header)
extra	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lm

#-------	--------#
#	Variables	#
#-------	--------#
exe	=	my_world
obj-dir	=	build
dirs	=	src src/setup src/menu src/engine
src	=	$(foreach dir,$(dirs),$(wildcard $(dir)/*.c))
obj	=	$(patsubst %.c, $(obj-dir)/%.o,$(notdir $(src)))
red	=	\033[1;31m
green	=	\033[1;32m
blue	=	\033[1;34m
white	=	\033[1;37m
nocolor	=	\033[1;0m

#-------		--------#
#     Generate my programme	#
#-------		--------#
all: $(obj-dir) $(exe)

$(exe): $(obj)
	@printf "$(green)/-------\n/  Assemble obj file\n/-------$(nocolor)\n"
	$(cc) $(cflags) -o $@ $(obj) $(extra)
	cat readme.txt

$(obj-dir):
	@printf "$(blue)/-------\n/  Create build obj\n/-------$(nocolor)\n"
	mkdir -p $@

define get_obj
$(patsubst %.c, $(obj-dir)/%.o,$(notdir $1)): $1
	@printf "compiling $(white)$$<$(nocolor)..."
	@$(cc) $(cflags) -c -o $$@ $$< $(extra)
	@printf "$(green)[ok]$(nocolor)\n"
endef

$(foreach source,$(src), $(eval \
	$(call get_obj,$(source))))

#-------		--------#
#	Clean & reinstall	#
#-------		--------#
clean:
	@printf "$(red)/-------\n/  Delete obj\n/-------$(nocolor)\n"
	rm -f $(obj)

fclean:	clean
	@printf "$(red)/-------\n/  Delete exe, obj and lib\n/-------$(nocolor)\n"
	rm -f $(exe)
	rm -rf $(obj-dir)

re: fclean all
