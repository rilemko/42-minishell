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

PROJECT_NAME			:=	minishell
PROJECT_ARCHIVES		:=	./libraries/42-libft/libft.a
PROJECT_DEPENDENCIES	:=	./libraries/42-libft
PROJECT_HEADERS			:=	./includes ./libraries/42-libft/includes
PROJECT_LIBRARIES		:=	

# > COMPILATION <<<<<<<<<<

COMPILER_PROGRAM		:=	clang-12
COMPILER_PROGRAM_DEBUG	:=	-fsanitize=undefined
COMPILER_PROGRAM_FLAGS	:=	-O3 -o
COMPILER_PROGRAM_OTHER	:=	-lreadline
COMPILER_OBJECTS		:=	clang-12
COMPILER_OBJECTS_FLAGS	:=	-O3 -g -Wall -Werror -Wextra

# > EXTENSIONS <<<<<<<<<<<

EXTENSION_SOURCE		:=	.c
EXTENSION_OBJECT		:=	.o

# > DIRECTORIES <<<<<<<<<<

FOLDER_SOURCES			:=	./sources

#///// PROJECT : SOURCES //////////////////////////////////////////////////////#

# > MANDATORY <<<<<<<<<<<<

PROJECT_SOURCES			:=	$(addprefix $(FOLDER_SOURCES)/, main.c					\
							app/aborting/ft_abort_cct.c								\
							app/aborting/ft_abort_doc.c								\
							app/ft_app_abort.c										\
							app/ft_app_set_prompt.c									\
							app/ft_app_set_status.c									\
							builtins/export/ft_check_export_arg.c					\
							builtins/export/ft_env_display.c						\
							builtins/export/ft_export_no_arg.c						\
							builtins/export/ft_export.c								\
							builtins/ft_cd.c										\
							builtins/ft_exit_builtin.c								\
							builtins/ft_echo.c										\
							builtins/ft_env_builtin.c								\
							builtins/ft_pwd.c										\
							builtins/ft_unset.c										\
							commands/argument/ft_arg_add.c							\
							commands/argument/ft_arg_get.c							\
							commands/command/ft_cmd_add.c							\
							commands/command/ft_cmd_get.c							\
							core/ft_exit.c											\
							core/ft_fork.c											\
							environment/ft_env_add.c								\
							environment/ft_env_del.c								\
							environment/ft_env_get.c								\
							environment/ft_env_has.c								\
							environment/ft_env_set.c								\
							errors/ft_perror.c										\
							filesystem/ft_alphasort.c								\
							filesystem/ft_basename.c								\
							filesystem/ft_chdir.c									\
							filesystem/ft_close.c									\
							filesystem/ft_closedir.c								\
							filesystem/ft_dirname.c									\
							filesystem/ft_dup.c										\
							filesystem/ft_dup2.c									\
							filesystem/ft_exists.c									\
							filesystem/ft_fopen.c									\
							filesystem/ft_fread.c									\
							filesystem/ft_fwrite.c									\
							filesystem/ft_getcwd.c									\
							filesystem/ft_glob.c									\
							filesystem/ft_is_readable.c								\
							filesystem/ft_is_writable.c								\
							filesystem/ft_is_xcutable.c								\
							filesystem/ft_isatty.c									\
							filesystem/ft_open.c									\
							filesystem/ft_opendir.c									\
							filesystem/ft_read.c									\
							filesystem/ft_readdir.c									\
							filesystem/ft_scandir.c									\
							filesystem/ft_size.c									\
							filesystem/ft_unlink.c									\
							filesystem/ft_write.c									\
							history/ft_history_add.c								\
							history/ft_history_clear.c								\
							history/ft_history_load.c								\
							parsing/executer/ft_main_execve.c						\
							parsing/executer/ft_execute_cmd.c						\
							parsing/executer/ft_set_and_close.c						\
							parsing/executer/ft_set_exit_status.c					\
							parsing/executer/ft_simple_builtin.c					\
							parsing/executer/ft_simple_cmd.c						\
							parsing/executer/ft_exec_cmd.c							\
							parsing/executer/ft_count_cmds.c						\
							parsing/executer/ft_which_builtin.c						\
							parsing/executer/ft_infile.c							\
							parsing/executer/debug.c								\
							parsing/executer/ft_outfile.c							\
							parsing/executer/ft_heredoc.c							\
							parsing/executer/ft_checking_status.c					\
							parsing/executer/piping/ft_pipe_cmd.c					\
							parsing/executer/piping/ft_pipe_close.c					\
							parsing/executer/piping/ft_pipe_creation.c				\
							parsing/executer/piping/ft_pipe_redirection.c			\
							parsing/interpreter/ft_interpret.c						\
							parsing/interpreter/process/ft_itp_process_arg.c		\
							parsing/interpreter/process/ft_itp_process_cmd.c		\
							parsing/interpreter/process/ft_itp_process_doc.c		\
							parsing/interpreter/process/ft_itp_process_opt.c		\
							parsing/interpreter/process/ft_itp_process_pfi.c		\
							parsing/interpreter/process/ft_itp_process_pfo.c		\
							parsing/interpreter/process/ft_itp_process_var.c		\
							parsing/interpreter/utilities/ft_interpret_asterisk.c	\
							parsing/interpreter/utilities/ft_interpret_concate.c	\
							parsing/interpreter/utilities/ft_interpret_normalize.c	\
							parsing/interpreter/utilities/ft_interpret_variable.c	\
							parsing/parser/ft_parse.c								\
							parsing/parser/process/ft_prs_process_000.c				\
							parsing/parser/process/ft_prs_process_009.c				\
							parsing/parser/process/ft_prs_process_012.c				\
							parsing/parser/process/ft_prs_process_032.c				\
							parsing/parser/process/ft_prs_process_034.c				\
							parsing/parser/process/ft_prs_process_035.c				\
							parsing/parser/process/ft_prs_process_036.c				\
							parsing/parser/process/ft_prs_process_038.c				\
							parsing/parser/process/ft_prs_process_039.c				\
							parsing/parser/process/ft_prs_process_040.c				\
							parsing/parser/process/ft_prs_process_041.c				\
							parsing/parser/process/ft_prs_process_042.c				\
							parsing/parser/process/ft_prs_process_045.c				\
							parsing/parser/process/ft_prs_process_059.c				\
							parsing/parser/process/ft_prs_process_060.c				\
							parsing/parser/process/ft_prs_process_061.c				\
							parsing/parser/process/ft_prs_process_062.c				\
							parsing/parser/process/ft_prs_process_124.c				\
							parsing/parser/process/ft_prs_process_176.c				\
							parsing/parser/process/ft_prs_process_default.c			\
							parsing/parser/reading/ft_prs_reading_arg.c				\
							parsing/parser/reading/ft_prs_reading_cmd.c				\
							parsing/parser/reading/ft_prs_reading_cmt.c				\
							parsing/parser/reading/ft_prs_reading_del.c				\
							parsing/parser/reading/ft_prs_reading_doc.c				\
							parsing/parser/reading/ft_prs_reading_err.c				\
							parsing/parser/reading/ft_prs_reading_opt.c				\
							parsing/parser/reading/ft_prs_reading_rfi.c				\
							parsing/parser/reading/ft_prs_reading_rfo.c				\
							parsing/parser/reading/ft_prs_reading_str.c				\
							parsing/parser/reading/ft_prs_reading_var.c				\
							parsing/parser/utilities/ft_parse_abort.c				\
							parsing/parser/utilities/ft_parse_error.c				\
							parsing/parser/utilities/ft_parse_follow.c				\
							parsing/parser/utilities/ft_parse_read.c				\
							readline/ft_readline.c									\
							signals/ft_kill.c										\
							signals/ft_signal.c										\
							signals/handler/ft_sig_handler_cct.c					\
							signals/handler/ft_sig_handler_def.c					\
							signals/handler/ft_sig_handler_rtm.c					\
							structures/s_app.c										\
							structures/s_arg.c										\
							structures/s_cfg.c										\
							structures/s_cmd.c										\
							structures/s_exe.c										\
							structures/s_fds.c										\
							structures/s_lne.c										\
							structures/s_ope.c										\
							structures/s_ptr.c										\
							structures/s_rdl.c										\
							structures/s_rdr.c										\
							structures/s_rio.c										\
							structures/s_seg.c										\
							structures/s_sts.c										\
							structures/s_sub.c										\
							structures/s_tio.c										\
							structures/s_tkn.c										\
							structures/s_tpl.c										\
							tokens/ft_tkn_add.c										\
							tokens/ft_tkn_get.c										\
							tokens/ft_tkn_has.c										\
							variables/ft_var_add.c									\
							variables/ft_var_del.c									\
							variables/ft_var_get.c									\
							variables/ft_var_has.c									\
							variables/ft_var_set.c									\
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
							@mkdir -p storage
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
							@rm -rf $(PROJECT_NAME) storage/.history;
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
