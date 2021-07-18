#ifndef PRINTF_TYS
# define PRINTF_TYS
# include <stdbool.h>
# include <stdio.h>

# define LOG_DIR "./logs"

# define	ASSERT(test_name, printf_call) \
			{ \
			output_redirect(LOG_DIR"/ref/ref_"test_name); \
			int ref_ret = printf_call; \
			output_restore(); \
			output_redirect(LOG_DIR"/actual/actual_"test_name); \
			int actual_ret = ft_ ## printf_call; \
			output_restore(); \
			assert_by_diff(test_name, LOG_DIR"/ref/ref_"test_name, LOG_DIR"/actual/actual_"test_name, ref_ret, actual_ret); \
			}


typedef void (*assert_callback)(char *test_name, char *expected_fp, char *actual_fp, int diff_ret, int ref_ret, int actual_ret);

struct framework
{
	const char		*default_test_name;
	assert_callback	assert_callback;
	size_t			test_nb;
	size_t			fail_cnt;
	size_t			pass_cnt;
};

extern struct framework framework;

int		ft_printf(const char *fmt, ...);

void	assert_by_diff(char *test_name, char *expected_fp, char *actual_fp, int ref_ret, int actual_ret);
bool	output_redirect(const char *filepath);
bool	output_restore(void);

void	ptys_setup(void);
void	ptys_terminate(void);

#endif