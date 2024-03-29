/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <errno.h>
#include <sys/cdefs.h>
#include <limits.h>		/* For LONG_BIT */
#include <string.h>		/* For memset() */
#include <sys/types.h>
#include <asm/signal.h>

#define __ARCH_SI_UID_T __kernel_uid32_t
#include <asm/siginfo.h>
#undef __ARCH_SI_UID_T

__BEGIN_DECLS

typedef int sig_atomic_t;

/* _NSIG is used by the SIGRTMAX definition under <asm/signal.h>, however
 * its definition is part of a #if __KERNEL__ .. #endif block in the original
 * kernel headers and is thus not part of our cleaned-up versions.
 *
 * Looking at the current kernel sources, it is defined as 64 for all
 * architectures except for the 'mips' one which set it to 128.
 */
#ifndef _NSIG
#  define _NSIG  64
#endif

extern const char* const sys_siglist[];
extern const char* const sys_signame[];

// modified by cmjo for VS2010
// - before C90, variable must be declared first!!!

static __inline__ int sigismember(const sigset_t* set, int signum) {
  const unsigned long* local_set;
  int bit = signum - 1; // Signal numbers start at 1, but bit positions start at 0.
  if (set == NULL || bit < 0 || bit >= (int) (8*sizeof(sigset_t))) {
    errno = EINVAL;
    return -1;
  }
  local_set = (const unsigned long*) set;
  return (int) ((local_set[bit / LONG_BIT] >> (bit % LONG_BIT)) & 1);
}

static __inline__ int sigaddset(sigset_t* set, int signum) {
  unsigned long* local_set;
  int bit = signum - 1; // Signal numbers start at 1, but bit positions start at 0.
  if (set == NULL || bit < 0 || bit >= (int) (8*sizeof(sigset_t))) {
    errno = EINVAL;
    return -1;
  }
  local_set = (unsigned long*) set;
  local_set[bit / LONG_BIT] |= 1UL << (bit % LONG_BIT);
  return 0;
}

static __inline__ int sigdelset(sigset_t* set, int signum) {
  unsigned long* local_set;
  int bit = signum - 1; // Signal numbers start at 1, but bit positions start at 0.
  if (set == NULL || bit < 0 || bit >= (int) (8*sizeof(sigset_t))) {
    errno = EINVAL;
    return -1;
  }
  local_set = (unsigned long*) set;
  local_set[bit / LONG_BIT] &= ~(1UL << (bit % LONG_BIT));
  return 0;
}

static __inline__ int sigemptyset(sigset_t* set) {
  if (set == NULL) {
    errno = EINVAL;
    return -1;
  }
  memset(set, 0, sizeof *set);
  return 0;
}

static __inline__ int sigfillset(sigset_t* set) {
  if (set == NULL) {
    errno = EINVAL;
    return -1;
  }
  memset(set, ~0, sizeof *set);
  return 0;
}


/* compatibility types */
typedef void  (*sig_t)(int);
typedef sig_t sighandler_t;

/* differentiater between sysv and bsd behaviour 8*/
extern __sighandler_t sysv_signal(int, __sighandler_t);
extern __sighandler_t bsd_signal(int, __sighandler_t);

/* the default is bsd */
static __inline__ __sighandler_t signal(int s, __sighandler_t f)
{
    return bsd_signal(s,f);
}

/* the syscall itself */
extern __sighandler_t __signal(int, __sighandler_t, int);

extern int sigprocmask(int, const sigset_t *, sigset_t *);
extern int sigaction(int, const struct sigaction *, struct sigaction *);

extern int sigpending(sigset_t *);
extern int sigsuspend(const sigset_t *);
extern int sigwait(const sigset_t *set, int *sig);
extern int siginterrupt(int  sig, int  flag);

extern int raise(int);
extern int kill(pid_t, int);
extern int killpg(int pgrp, int sig);
extern int sigaltstack(const stack_t *ss, stack_t *oss);

extern void psiginfo(const siginfo_t* si, const char* message);
extern void psignal(int signal_number, const char* message);

__END_DECLS

#endif /* _SIGNAL_H_ */
