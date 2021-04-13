#include <stdarg.h>

int add_ints(int count, ...) {
  int sum = 0;
  va_list ap;
  va_start(ap, count);
  for (int i = 0; i < count; i++) {
    sum += va_arg(ap, int);
  }
  va_end(ap);
  return sum;
}

/* void va_start(va_list ap, last_arg);
 * This initializes ap variable to be used with the va_arg and va_end macros.
 * The last_arg is the last known fixed argument being passed to the function
 * i.e. the argument before the ellipsis.
 */
