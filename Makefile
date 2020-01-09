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
cflags	=	-W -Wall -Wextra -fno-builtin -g $(header)
extra	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

#-------	--------#
#	Variables	#
#-------	--------#
exe	=	my_world
obj-dir	=	build
dirs	=	src src/user_input src/input src/setup src/menu src/map \
			src/engine src/toolbar src/tools_get src/free
src	=	$(foreach dir,$(dirs),$(wildcard $(dir)/*.c))
obj	=	$(patsubst %.c, $(obj-dir)/%.o,$(notdir $(src)))
lib	=	lib/my/libmy.a
red	=	\033[1;31m
green	=	\033[1;32m
blue	=	\033[1;34m
white	=	\033[1;37m
nocolor	=	\033[1;0m

#-------		--------#
#     Generate my programme	#
#-------		--------#
all: $(obj-dir) $(exe)

$(exe): $(lib) $(obj)
	@printf "$(green)/-------\n/  Assemble obj file\n/-------$(nocolor)\n"
	$(cc) $(cflags) -o $@ $(obj) -L./lib/my -lmy $(extra)

$(obj-dir):
	@printf "$(blue)/-------\n/  Create build obj\n/-------$(nocolor)\n"
	mkdir -p $@

$(lib):
	@printf "$(blue)/-------\n/  Generate Lib\n/-------$(nocolor)\n"
	@make -C lib/my/
	@printf "$(blue)/-------\n/  Generate obj\n/-------$(nocolor)\n"

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
	make fclean -s -C lib/my/

re: fclean all
