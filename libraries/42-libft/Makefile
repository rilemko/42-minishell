# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 23:43:39 by mconreau          #+#    #+#              #
#    Updated: 2024/03/28 14:30:02 by mconreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#///// PROJECT : CONFIGURATION ////////////////////////////////////////////////#

# > GENERAL <<<<<<<<<<<<<<

PROJECT_NAME			:=	libft.a
PROJECT_ARCHIVES		:=	
PROJECT_DEPENDENCIES	:=	
PROJECT_HEADERS			:=	./includes
PROJECT_LIBRARIES		:=	

# > COMPILATION <<<<<<<<<<

COMPILER_PROGRAM		:=	ar
COMPILER_PROGRAM_DEBUG	:=
COMPILER_PROGRAM_FLAGS	:=	 -rcs
COMPILER_PROGRAM_OTHER	:=	
COMPILER_OBJECTS		:=	clang-12
COMPILER_OBJECTS_FLAGS	:=	-fPIC -O3 -g -Wall -Werror -Wextra

# > EXTENSIONS <<<<<<<<<<<

EXTENSION_SOURCE		:=	.c
EXTENSION_OBJECT		:=	.o

# > DIRECTORIES <<<<<<<<<<

FOLDER_SOURCES			:=	./sources

#///// PROJECT : SOURCES //////////////////////////////////////////////////////#

# > MANDATORY <<<<<<<<<<<<

PROJECT_SOURCES			:=	$(addprefix $(FOLDER_SOURCES)/,					\
							alloc/ft_calloc.c								\
							alloc/ft_free_deep.c							\
							alloc/ft_free.c									\
							array/ft_arraysize.c							\
							char/ft_isalnum.c								\
							char/ft_isalpha.c								\
							char/ft_isascii.c								\
							char/ft_isdigit.c								\
							char/ft_islower.c								\
							char/ft_isprint.c								\
							char/ft_isspace.c								\
							char/ft_isupper.c								\
							char/ft_tolower.c								\
							char/ft_toupper.c								\
							get_next_line/get_next_line.c					\
							integer/ft_atoi.c								\
							integer/ft_intdup.c								\
							integer/ft_itoa.c								\
							integer/ft_nbrlen.c								\
							list/ft_lstadd_back.c							\
							list/ft_lstadd_front.c							\
							list/ft_lstclear.c								\
							list/ft_lstdelone.c								\
							list/ft_lstfromarr.c							\
							list/ft_lstget.c								\
							list/ft_lstgetcontent.c							\
							list/ft_lstgetindex.c							\
							list/ft_lstlast.c								\
							list/ft_lstnew.c								\
							list/ft_lstsize.c								\
							list/ft_lsttoarr.c								\
							list/ft_lstunlist.c								\
							memory/ft_bzero.c								\
							memory/ft_memchr.c								\
							memory/ft_memcmp.c								\
							memory/ft_memcpy.c								\
							memory/ft_memmove.c								\
							memory/ft_mempos.c								\
							memory/ft_memrev.c								\
							memory/ft_memset.c								\
							memory/ft_qsort.c								\
							string/ft_chrcat.c								\
							string/ft_split.c								\
							string/ft_strchr.c								\
							string/ft_strcmp.c								\
							string/ft_strcnt.c								\
							string/ft_strdup.c								\
							string/ft_strjoin.c								\
							string/ft_strlcat.c								\
							string/ft_strlcpy.c								\
							string/ft_strlen.c								\
							string/ft_strltrim.c							\
							string/ft_strmjoin.c							\
							string/ft_strncmp.c								\
							string/ft_strnstr.c								\
							string/ft_strpos.c								\
							string/ft_strrchr.c								\
							string/ft_strrev.c								\
							string/ft_strrtrim.c							\
							string/ft_strtrim.c								\
							string/ft_substr.c								\
							ternary/ft_ternary.c							\
							ternary/ft_ternary_int.c						\
							)

#///// MAKEFILE : CONFIGURATION ///////////////////////////////////////////////#

# > REPORTS <<<<<<<<<<<<<<

REPORT_COMMON_TASK		:=	yes
REPORT_COMPILATION		:=	yes
REPORT_COMPILATION_LOGS	:=	no
REPORT_COMPILE_COUNTER	:=	yes
REPORT_ERRORS			:=	yes
REPORT_MAKE_CALL		:=	yes
REPORT_PRIMARY_TASK		:=	yes
REPORT_TIMESTAMPS		:=	no
REPORT_WARNINGS			:=	yes

# > MESSAGES SYMBOLS <<<<<

MSG_SYMBOL_FAILURE		:=	X
MSG_SYMBOL_REPORTS		:=	i
MSG_SYMBOL_SUCCESS		:=	✓
MSG_SYMBOL_WARNING		:=	!
MSG_SYMBOL_WORKING		:=	>

# > MESSAGES COLORS <<<<<<

MSG_BCOLOR_FAILURE		:=	\001\e[1;31m\002
MSG_BCOLOR_LOGGING		:=	\001\e[1;37m\002
MSG_BCOLOR_PRIMARY		:=	\001\e[1;36m\002
MSG_BCOLOR_REPORTS		:=	\001\e[1;35m\002
MSG_BCOLOR_SUCCESS		:=	\001\e[1;32m\002
MSG_BCOLOR_WARNING		:=	\001\e[1;33m\002
MSG_NCOLOR_FAILURE		:=	\001\e[0;31m\002
MSG_NCOLOR_LOGGING		:=	\001\e[0;37m\002
MSG_NCOLOR_PRIMARY		:=	\001\e[0;36m\002
MSG_NCOLOR_REPORTS		:=	\001\e[0;35m\002
MSG_NCOLOR_SUCCESS		:=	\001\e[0;32m\002
MSG_NCOLOR_WARNING		:=	\001\e[0;33m\002

# > TERMINAL <<<<<<<<<<<<<

TERM_CONTROL_CLEAR		:=	\001\e[1;1H\e[2J\002
TERM_CONTROL_RESET		:=	\001\e[0m\002

# > VARIABLES <<<<<<<<<<<<

V_ARGUMENTS				:=	$(MAKECMDGOALS)
V_COUNTER				:=	1
V_DISPLAY_NAME			:=	$(shell printf "[%-16s]" "$(PROJECT_NAME)")
V_INCLUDE_ARCHIVES		:=	$(PROJECT_ARCHIVES)
V_INCLUDE_HEADERS		:=	$(addprefix -I, $(PROJECT_HEADERS))
V_INCLUDES_LIBRARIES	:=	$(addprefix -L, $(PROJECT_LIBRARIES))
V_OBJECTS				:=	$(PROJECT_SOURCES:%$(EXTENSION_SOURCE)=%$(EXTENSION_OBJECT))
V_OBJECTS_TOTAL			:=	$(words $(V_OBJECTS))
V_OS					:=	$(shell uname)

ifeq ($(filter-out $@,$(V_ARGUMENTS)), debug)
COMPILER_PROGRAM_FLAGS	:=	$(addprefix $(COMPILER_PROGRAM_DEBUG) , $(COMPILER_PROGRAM_FLAGS))
endif

# > OBJECTS <<<<<<<<<<<<<<

O_COUNTER				=	$(shell printf "%02d/%02d" "$(V_COUNTER)" "$(V_OBJECTS_TOTAL)")
O_CURRENT_TIME			=	$(shell date +"%H:%M:%S")

#///// MAKEFILE : COMMANDS ////////////////////////////////////////////////////#

$(PROJECT_NAME)			:	$(V_OBJECTS)
							@for dependency in $(PROJECT_DEPENDENCIES) ; do\
								if [ $(REPORT_MAKE_CALL) = "yes" ]; then\
									printf "$(MSG_BCOLOR_REPORTS)[ $(MSG_SYMBOL_REPORTS) ]";\
									printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
									if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
										printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
									fi;\
									printf "$(MSG_NCOLOR_LOGGING) @make \"$${dependency}\"...\n";\
									printf "$(TERM_CONTROL_RESET)";\
								fi;\
								if [ -d $${dependency}/ ]; then\
									if [ -f $${dependency}/Makefile ]; then\
										$(MAKE) -C $${dependency} --no-print-directory ;\
									else\
										if [ $(REPORT_ERRORS) = "yes" ]; then\
											printf "$(MSG_BCOLOR_FAILURE)[ $(MSG_SYMBOL_FAILURE) ]";\
											printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
											if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
												printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
											fi;\
											printf "$(MSG_BCOLOR_FAILURE) Dependency \"$${dependency}\" does not contain Makefile !\n";\
											printf "$(TERM_CONTROL_RESET)";\
										fi;\
										exit 1;\
									fi;\
								else\
									if [ $(REPORT_ERRORS) = "yes" ]; then\
										printf "$(MSG_BCOLOR_FAILURE)[ $(MSG_SYMBOL_FAILURE) ]";\
										printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
										if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
											printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
										fi;\
										printf "$(MSG_BCOLOR_FAILURE) Directory \"$${dependency}\" does not exists !\n";\
										printf "$(TERM_CONTROL_RESET)";\
									fi;\
									exit 1;\
								fi;\
							done
							@for library in $(PROJECT_LIBRARIES) ; do\
								if [ ! -e $${library} ]; then\
									if [ $(REPORT_ERRORS) = "yes" ]; then\
										printf "$(MSG_BCOLOR_FAILURE)[ $(MSG_SYMBOL_FAILURE) ]";\
										printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
										if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
											printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
										fi;\
										printf "$(MSG_BCOLOR_FAILURE) Library \"$${library}\" does not exists !\n";\
										printf "$(TERM_CONTROL_RESET)";\
									fi;\
									exit 1;\
								fi;\
							done
							@for archive in $(PROJECT_ARCHIVES) ; do\
								if [ ! -e $${archive} ]; then\
									if [ $(REPORT_ERRORS) = "yes" ]; then\
										printf "$(MSG_BCOLOR_FAILURE)[ $(MSG_SYMBOL_FAILURE) ]";\
										printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
										if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
											printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
										fi;\
										printf "$(MSG_BCOLOR_FAILURE) Archive \"$${archive}\" does not exists !\n";\
										printf "$(TERM_CONTROL_RESET)";\
									fi;\
									exit 1;\
								fi;\
							done
							@if [ $(REPORT_COMMON_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_REPORTS)[ $(MSG_SYMBOL_REPORTS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_NCOLOR_LOGGING) Creating program...\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi
							@$(COMPILER_PROGRAM) $(COMPILER_PROGRAM_FLAGS) $(PROJECT_NAME) $(V_OBJECTS) $(V_INCLUDES_LIBRARIES) $(V_INCLUDE_ARCHIVES) $(COMPILER_PROGRAM_OTHER)
							@chmod 755 $(PROJECT_NAME)
							@if [ $(REPORT_PRIMARY_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_SUCCESS)[ $(MSG_SYMBOL_SUCCESS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_BCOLOR_SUCCESS) Program successfuly created !\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi

%$(EXTENSION_OBJECT)	:	%$(EXTENSION_SOURCE)
							@if [ $(REPORT_COMPILATION_LOGS) = "yes" ]; then\
								printf "$(MSG_BCOLOR_REPORTS)[ $(MSG_SYMBOL_REPORTS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								if [ $(REPORT_COMPILE_COUNTER) = "yes" ]; then\
									printf "$(MSG_BCOLOR_LOGGING) $(O_COUNTER) >";\
								fi;\
								printf "$(MSG_NCOLOR_LOGGING) Compiling...    <";\
								printf "$(MSG_NCOLOR_LOGGING) $<\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi
							@$(COMPILER_OBJECTS) $(COMPILER_OBJECTS_FLAGS) $(V_INCLUDE_HEADERS) -c $< -o $@
							@if [ $(REPORT_COMPILATION) = "yes" ]; then\
								printf "$(MSG_BCOLOR_PRIMARY)[ $(MSG_SYMBOL_WORKING) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								if [ $(REPORT_COMPILE_COUNTER) = "yes" ]; then\
									printf "$(MSG_BCOLOR_PRIMARY) $(O_COUNTER) >";\
								fi;\
								printf "$(MSG_BCOLOR_PRIMARY) File compiled ! >";\
								printf "$(MSG_NCOLOR_LOGGING) $@\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi
							$(eval V_COUNTER=$(shell echo $$(($(V_COUNTER)+1))))

all						:	$(PROJECT_NAME)							

clean					:	lclean
							@if [ $(REPORT_COMMON_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_REPORTS)[ $(MSG_SYMBOL_REPORTS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_NCOLOR_LOGGING) Deleting objects...\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi
							@rm -f $(V_OBJECTS);
							@if [ $(REPORT_PRIMARY_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_SUCCESS)[ $(MSG_SYMBOL_SUCCESS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_BCOLOR_SUCCESS) Objects deleted successfully !\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi

debug					:	re
							@if [ $(REPORT_WARNINGS) = "yes" ]; then\
								printf "$(MSG_BCOLOR_WARNING)[ $(MSG_SYMBOL_WARNING) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_BCOLOR_WARNING) Program compiled in debugging mode.\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi


lclean					:	
							@for dependency in $(PROJECT_DEPENDENCIES); do\
								if [ -d $${dependency} ] && [ -f $${dependency}/Makefile ]; then\
									$(MAKE) fclean -C $${dependency} --no-print-directory ;\
								fi;\
							done

fclean					:	clean lclean
							@rm -f $(PROJECT_NAME);
							@if [ $(REPORT_PRIMARY_TASK) = "yes" ]; then\
								printf "$(MSG_BCOLOR_SUCCESS)[ $(MSG_SYMBOL_SUCCESS) ]";\
								printf "$(MSG_NCOLOR_LOGGING)$(V_DISPLAY_NAME)";\
								if [ $(REPORT_TIMESTAMPS) = "yes" ]; then\
									printf "$(MSG_NCOLOR_LOGGING) $(O_CURRENT_TIME) |";\
								fi;\
								printf "$(MSG_BCOLOR_SUCCESS) Program deleted successfully !\n";\
								printf "$(TERM_CONTROL_RESET)";\
							fi

re						:	fclean all

.PHONY					:	all clean debug lclean fclean re
