#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>

#include "ptys.h"

static int	save_out_fd = -1;

static void default_assert_callback(char *test_name, char *expected_fp, char *actual_fp, int diff_ret, int ref_ret, int actual_ret)
{
	(void)expected_fp;
	(void)actual_fp;
	if (diff_ret != 0) {
		printf("%-30s[\033[1;31mKO\033[0m] output differs. Diff can be found at %s/diff/%s.diff\n",
			test_name, LOG_DIR, test_name);
		framework.fail_cnt++;
	} else if (ref_ret != actual_ret) {
		printf("%-30s[\033[1;31mKO\033[0m] return value differ: expected %d, got %d\n", 
			test_name, ref_ret, actual_ret);
		framework.fail_cnt++;
	} else {
		printf("%-30s[\033[1;32mOK\033[0m]\n", test_name);
		++framework.pass_cnt;
	}
	++framework.test_nb;
	fflush(stdout);
}

struct framework framework = {
	.default_test_name = "test",
	.fail_cnt = 0,
	.pass_cnt = 0,
	.test_nb = 0,
	.assert_callback = &default_assert_callback,
};

void	ptys_setup(void)
{
	mkdir(LOG_DIR, 0755);
	mkdir(LOG_DIR"/ref", 0755);
	mkdir(LOG_DIR"/actual", 0755);
	mkdir(LOG_DIR"/diff", 0755);
}

void	ptys_terminate(void)
{
	printf("----- TEST SUMMARY -----\nPassed: \033[1;32m%ld\n\033[0mFailed: \033[1;31m%ld\n\033[0mTotal: %ld\n",
		framework.pass_cnt, framework.fail_cnt, framework.test_nb);
	exit(framework.fail_cnt > 0 ? 1 : 0); 
}

void	assert_by_diff(char *test_name, char *expected_fp, char *actual_fp, int ref_ret, int actual_ret)
{
	char	cmd[PATH_MAX] = { 0 };

	snprintf(cmd, PATH_MAX, "diff -u %s %s &> %s/diff/%s.diff", expected_fp, actual_fp, LOG_DIR, test_name);

	// run diff command

	int diff_ret = system(cmd);
	framework.assert_callback(test_name, expected_fp, actual_fp, diff_ret, ref_ret, actual_ret);
}

bool	output_redirect(const char *filepath)
{
	save_out_fd = dup(fileno(stdout));
	if (!freopen(filepath, "w", stdout)) {
		perror("freopen: ");
	}
	return (true);
}

bool	output_restore(void)
{
	if (fflush(stdout) != 0) {
		perror("fflush stdout: ");
		return (false);
	}
	dup2(save_out_fd, fileno(stdout));
	return (true);
}