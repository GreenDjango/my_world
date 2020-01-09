##
## EPITECH PROJECT, 2018
## makefile
## File description:
## day10
##

#-------	--------#
#	  Flag  	#
#-------	--------#
cc	=	gcc
header_dir	=	include
cflags	=	-W -Wall -Werror -Wextra -fno-builtin -I $(header_dir)

#-------	--------#
#	Variables	#
#-------	--------#
lib	=	libmy.a
obj-dir	=	build
dirs	=	string system mtg_graph
src	=	$(foreach dir,$(dirs),$(wildcard $(dir)/*.c))
obj	=	$(patsubst %.c, $(obj-dir)/%.o,$(notdir $(src)))
headers	=	$(wildcard include/*.h)
desth	=	$(patsubst %.h, ../../include/lib/%.h, $(notdir $(headers)))
green	=	\033[1;32m
white	=	\033[1;37m
nocolor	=	\033[1;0m


#-------		--------#
#     Generate my programme	#
#-------		--------#
all: $(obj-dir) $(lib) $(desth)

$(lib): $(obj)
	@ar rcs $@ $(obj)

$(obj-dir):
	@mkdir -p $@

$(desth):
	@mkdir ../../include/lib
	@cp $(headers) ../../include/lib/

define get_obj
$(patsubst %.c, $(obj-dir)/%.o,$(notdir $1)): $1
	@printf "compiling $(white)$$<$(nocolor)..."
	@$(cc) $(cflags) -c -o $$@ $$<
	@printf "$(green)[ok]$(nocolor)\n"
endef

$(foreach source,$(src), $(eval \
	$(call get_obj,$(source))))

#-------		--------#
#	Clean & reinstall	#
#-------		--------#
clean:
	rm -f $(obj)

fclean: clean
	rm -f $(lib)
	rm -rf $(obj-dir)
	rm -f $(desth)
	rm -rf ../../include/lib

re: fclean all
