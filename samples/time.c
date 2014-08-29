#include <linux/mm.h>
#include <linux/interrupt.h>
#include <trace/events/timer.h>

static struct timeval itimer_get_remtime(struct hrtimer *timer)
{
  ktime_t rem = hrtimer_get_remaining(timer);

  if (hrtimer_active(timer)) {
    if (rem.tv64 <= 0)
      rem.tv64 = NSEC_PER_USEC;
  } else
    rem.tv64 = 0;

  return ktime_to_timeval(rem);
}
