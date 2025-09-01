/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:39:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 17:05:24 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_includes.h"
#include "_definitions.h"

extern t_app	*g_minishell;

/*///// APPLICATION //////////////////////////////////////////////////////////*/

t_rt	ft_app_abort(t_app *app);
void	ft_app_set_prompt(t_app *app, const char *prompt);
void	ft_app_set_status(t_app *app, int status);
t_rt	ft_abort_cct(t_app *app, t_lne *lne);
t_rt	ft_abort_doc(t_app *app, t_lne *lne);

/*///// BUILTINS /////////////////////////////////////////////////////////////*/

int		ft_echo(t_cmd *cmd, char *arg, char *opt);
int		ft_exit_builtin(t_app *app, t_cmd *cmd);
int		ft_pwd(t_cmd *cmd, t_app *app);
int		ft_unset(t_cmd *cmd, t_app *app, char *arg);
int		ft_cd(t_app *app, char *arg);
int		ft_env_builtin(t_cmd *cmd, char **env);
int		ft_export(t_cmd *cmd, t_app *app, char **env, char *arg);
int		ft_check_arg(char *arg);
void	ft_display_env(char *str);
void	ft_export_env(t_cmd *cmd, char **env_arg);

/*///// COMMANDS /////////////////////////////////////////////////////////////*/

void	ft_arg_add(t_lst **lst, t_arg *argument);
t_arg	*ft_arg_get(t_lst **lst, size_t index);
void	ft_cmd_add(t_lst **lst, t_cmd *command);
t_cmd	*ft_cmd_get(t_lst **lst, size_t index);

/*///// CORE /////////////////////////////////////////////////////////////////*/

void	ft_exit(t_app *app, int exit_code, const char *message);
void	ft_exit_failure(t_app *app, const char *message);
void	ft_exit_success(t_app *app, const char *message);
t_pid	ft_fork(t_pid *process_id);

/*///// ENVIRONMENT //////////////////////////////////////////////////////////*/

void	ft_env_add(t_lst **env, const char *key, const char *value,
			t_bool equal);
t_bool	ft_env_has(t_lst **env, const char *key, t_bool equal);
void	ft_env_del(t_lst **env, const char *key, t_bool equal);
char	*ft_env_get(t_lst **env, const char *key, const char *def_value);
void	ft_env_set(t_lst **env, const char *key, const char *value,
			t_bool equal);

/*///// ERRORS ///////////////////////////////////////////////////////////////*/

void	ft_perror(const char *name, const char *prefix, const char *argument,
			const char *message);

/*///// FILESYSTEM ///////////////////////////////////////////////////////////*/

int		ft_alphasort(void *ptr1, void *ptr2);
void	ft_basename(const char *pathname, char *buffer);
t_rt	ft_chdir(const char *pathname, char *buffer);
t_rt	ft_close(t_fd file_descriptor);
t_rt	ft_closedir(t_ds *stream);
void	ft_dirname(const char *pathname, char *buffer);
t_fd	ft_dup(t_fd file_descriptor);
t_fd	ft_dup2(t_fd file_descriptor, int new_descritptor);
t_bool	ft_exists(const char *pathname, t_bool check_file,
			t_bool check_directory);
t_fd	ft_fopen(const char *pathname, t_bool read, t_bool write, int flags);
t_rt	ft_fread(const char *pathname, char *buffer);
t_rt	ft_fwrite(const char *pathname, const char *content, t_bool append,
			t_bool erase);
t_rt	ft_getcwd(char *buffer);
size_t	ft_glob(const char *pattern, char ***matches);
t_bool	ft_is_readable(const char *pathname, t_bool check_file,
			t_bool check_directory);
t_bool	ft_is_writable(const char *pathname, t_bool check_file,
			t_bool check_directory);
t_bool	ft_is_xcutable(const char *pathname, t_bool check_file,
			t_bool check_directory);
t_rt	ft_isatty(t_fd file_descriptor);
t_fd	ft_open(const char *pathname, int flags);
t_ds	*ft_opendir(const char *pathname);
t_rt	ft_read(t_fd file_descriptor, char *buffer, char delimiter, int size);
t_rt	ft_readdir(t_ds *stream, struct dirent *node);
size_t	ft_scandir(const char *pathname, char ***names,
			t_rt (*filter)(struct dirent *), int (*compare)(void *, void *));
t_bytes	ft_size(const char *pathname);
t_rt	ft_unlink(const char *pathname);
t_rt	ft_write(t_fd file_descriptor, const char *content);

/*///// HISTORY //////////////////////////////////////////////////////////////*/

void	ft_history_add(const char *content, const char *file_history);
void	ft_history_clear(const char *file_history);
void	ft_history_load(const char *file_history, t_bool clear);

/*///// PARSING //////////////////////////////////////////////////////////////*/

void	ft_execute(t_app *app, t_exe *exe, t_lst *lst, size_t depth);
void	ft_count_cmds(t_exe *exec, t_lst *cmd_list, size_t depth);
int		ft_which_builtin(t_cmd *cmd, t_app *app);
pid_t	ft_simple_cmd(t_app *app, t_exe *exe, t_cmd *cmd);
void	ft_simple_builtin(t_app *app, t_exe *exe, t_cmd *cmd);
void	ft_set_and_close(t_exe *exe, t_lst *lst, size_t depth);
void	ft_execute_cmd(t_app *app, t_exe *exe, t_cmd *cmd);
void	ft_set_exit_status(t_app *app, t_pid *pid, t_exe *exe);
void	ft_execute_sub(t_app *app, t_exe *exe, t_lst *lst, size_t depth);
void	ft_execute_simple_cmd(t_app *app, t_exe *exe, t_lst *lst, size_t depth);
void	ft_exec_cmd(t_app *app, t_exe *exec, t_lst *cmd_list);
void	ft_inner_execution(t_cmd *cmd, t_exe *exec, t_app *app);
void	ft_change_infile(t_app *app, t_exe *exec, t_cmd *cmd);
void	ft_change_outfile(t_app *app, t_exe *exec, t_cmd *cmd);
void	ft_pipe_cmd(t_exe *exec, t_cmd *cmd);
void	ft_pipe_close(t_exe *exec, t_cmd *cmd);
int		ft_check_last_status(t_exe *exec, t_cmd *cmd);
void	ft_pipe_creation(t_exe *exec, t_cmd *cmd, t_app *app);
void	ft_pipe_redirection(t_app *app, t_cmd *cmd, t_exe *exec);
void	ft_heredoc(t_cmd *cmd, t_exe *exec);
void	debug(t_cmd *current_cmd);

void	ft_interpret(t_app *app, t_cmd *cmd);
void	ft_interpret_asterisk(t_arg *arg, char *buffer);
void	ft_interpret_concate(t_lst **lst, t_app *app, char *buffer,
			t_bool preserve);
void	ft_interpret_normalize(char *content);
void	ft_interpret_variable(t_arg *arg, char *buffer, t_app *app,
			t_bool preserve);
void	ft_itp_process_arg(t_cmd *cmd, t_app *app);
void	ft_itp_process_cmd(t_cmd *cmd, t_app *app);
void	ft_itp_process_doc(t_cmd *cmd, t_app *app);
void	ft_itp_process_opt(t_cmd *cmd, t_app *app);
void	ft_itp_process_pfi(t_cmd *cmd, t_app *app);
void	ft_itp_process_pfo(t_cmd *cmd, t_app *app);
void	ft_itp_process_var(t_cmd *cmd, t_app *app);

t_rt	ft_parse(t_app *app, t_lne *lne);
t_rt	ft_parse_abort(t_lne *lne, t_bool force);
t_rt	ft_parse_error(t_app *app, t_lne *lne);
void	ft_parse_follow(t_lne *lne);
void	ft_parse_read(t_lne *lne, t_bool cut);
void	ft_prs_process_000(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_009(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_012(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_032(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_034(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_035(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_036(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_038(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_039(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_040(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_041(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_042(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_045(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_059(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_060(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_061(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_062(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_124(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_176(t_lne *lne, t_tkn *tkn);
void	ft_prs_process_default(t_lne *lne);

void	ft_prs_reading_arg(t_lne *lne, t_bool cut);
void	ft_prs_reading_cmd(t_lne *lne, t_bool cut);
void	ft_prs_reading_cmt(t_lne *lne, t_bool cut);
void	ft_prs_reading_del(t_lne *lne, t_bool cut);
void	ft_prs_reading_doc(t_lne *lne, t_bool cut);
void	ft_prs_reading_err(t_lne *lne, t_bool cut);
void	ft_prs_reading_opt(t_lne *lne, t_bool cut);
void	ft_prs_reading_rfi(t_lne *lne, t_bool cut);
void	ft_prs_reading_rfo(t_lne *lne, t_bool cut);
void	ft_prs_reading_str(t_lne *lne, t_bool cut);
void	ft_prs_reading_var(t_lne *lne, t_bool cut);

/*///// READLINE /////////////////////////////////////////////////////////////*/

t_rt	ft_readline(const char *prompt, char *buffer);
void	ft_readline_nl(const char *content);
void	ft_readline_sl(const char *content);

/*///// SIGNALS //////////////////////////////////////////////////////////////*/

t_rt	ft_kill(pid_t process_id, int signal);
void	ft_signal(t_mod signal_mode);
void	ft_signal_register(void (*handler)(int));
void	ft_sig_handler_cct(int type);
void	ft_sig_handler_def(int type);
void	ft_sig_handler_rtm(int type);

/*///// STRUCTURES ///////////////////////////////////////////////////////////*/

void	st_app_clear(t_app *app);
void	st_app_initialize(t_app *app, int argc, char **argv, char **envp);
void	st_arg_clear(t_arg *arg);
void	st_arg_initialize(t_arg *arg);
void	st_cfg_clear(t_cfg *cfg);
void	st_cfg_initialize(t_cfg *cfg);
void	st_cmd_clear(t_cmd *cmd);
void	st_cmd_initialize(t_cmd *cmd);
void	st_exe_clear(t_exe *exe);
void	st_exe_initialize(t_exe *exe);
void	st_fds_clear(t_fds *fds);
void	st_fds_initialize(t_fds *fds, t_app *app);
void	st_lne_clear(t_lne *lne);
void	st_lne_initialize(t_lne *lne, t_app *app);
void	st_ope_clear(t_ope *ope);
void	st_ope_initialize(t_ope *ope);
void	st_ptr_clear(t_ptr *ptr);
void	st_ptr_initialize(t_ptr *ptr);
void	st_rdl_clear(t_rdl *rdl);
void	st_rdl_initialize(t_rdl *rdl);
void	st_rdr_clear(t_rdr *rdr);
void	st_rdr_initialize(t_rdr *rdr);
void	st_rio_clear(t_rio *rio);
void	st_rio_initialize(t_rio *rio);
void	st_seg_clear(t_seg *seg);
void	st_seg_initialize(t_seg *seg);
void	st_sts_clear(t_sts *sts);
void	st_sts_initialize(t_sts *sts);
void	st_sub_clear(t_sub *sub);
void	st_sub_initialize(t_sub *sub);
void	st_tio_clear(t_tio *tio);
void	st_tio_initialize(t_tio *tio);
void	st_tkn_clear(t_tkn *tkn);
void	st_tkn_initialize(t_tkn *tkn);
void	st_tpl_clear(t_tpl *tpl);
void	st_tpl_initialize(t_tpl *tpl);

/*///// TOKENS ///////////////////////////////////////////////////////////////*/

void	ft_tkn_add(t_lst **lst, char token, void (*process)(t_lne *, t_tkn *),
			size_t repeat, const char *display);
t_tkn	*ft_tkn_get(t_lst **lst, char token);
t_bool	ft_tkn_has(t_lst **lst, char token);

/*///// VARIABLES ////////////////////////////////////////////////////////////*/

void	ft_var_add(t_lst **var, const char *key, const char *value);
t_bool	ft_var_has(t_lst **var, const char *key);
void	ft_var_del(t_lst **var, const char *key);
char	*ft_var_get(t_lst **var, const char *key, const char *def_value);
void	ft_var_set(t_lst **var, const char *key, const char *value);
