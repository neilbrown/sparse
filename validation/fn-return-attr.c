
int * __attribute__((noderef)) func(void);
int * __attribute__((safe)) safe_func(void);

static int t(void)
{
	int x;

	if (safe_func())
		x = *func();
}

/*
 * check-name: preserve modifiers of function return type.
 *
 * check-error-start
fn-return-attr.c:9:22: warning: testing a 'safe expression'
fn-return-attr.c:10:26: warning: dereference of noderef expression
 * check-error-end
 */
