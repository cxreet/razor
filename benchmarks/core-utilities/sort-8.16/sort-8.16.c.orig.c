typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;
struct timespec {
   __time_t tv_sec ;
   __syscall_slong_t tv_nsec ;
};
typedef unsigned long size_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef __uid_t uid_t;
struct stat {
   __dev_t st_dev ;
   __ino_t st_ino ;
   __nlink_t st_nlink ;
   __mode_t st_mode ;
   __uid_t st_uid ;
   __gid_t st_gid ;
   int __pad0 ;
   __dev_t st_rdev ;
   __off_t st_size ;
   __blksize_t st_blksize ;
   __blkcnt_t st_blocks ;
   struct timespec st_atim ;
   struct timespec st_mtim ;
   struct timespec st_ctim ;
   __syscall_slong_t __glibc_reserved[3] ;
};
typedef __ino_t ino_t;
typedef __dev_t dev_t;
struct hash_tuning {
   float shrink_threshold ;
   float shrink_factor ;
   float growth_threshold ;
   float growth_factor ;
   _Bool is_n_buckets ;
};
typedef struct hash_tuning Hash_tuning;
struct hash_table;
struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
typedef unsigned long uintmax_t;
typedef long __off64_t;
struct _IO_FILE;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;
struct _IO_marker {
   struct _IO_marker *_next ;
   struct _IO_FILE *_sbuf ;
   int _pos ;
};
struct _IO_FILE {
   int _flags ;
   char *_IO_read_ptr ;
   char *_IO_read_end ;
   char *_IO_read_base ;
   char *_IO_write_base ;
   char *_IO_write_ptr ;
   char *_IO_write_end ;
   char *_IO_buf_base ;
   char *_IO_buf_end ;
   char *_IO_save_base ;
   char *_IO_backup_base ;
   char *_IO_save_end ;
   struct _IO_marker *_markers ;
   struct _IO_FILE *_chain ;
   int _fileno ;
   int _flags2 ;
   __off_t _old_offset ;
   unsigned short _cur_column ;
   signed char _vtable_offset ;
   char _shortbuf[1] ;
   _IO_lock_t *_lock ;
   __off64_t _offset ;
   void *__pad1 ;
   void *__pad2 ;
   void *__pad3 ;
   void *__pad4 ;
   size_t __pad5 ;
   int _mode ;
   char _unused2[(15UL * sizeof(int ) - 4UL * sizeof(void *)) - sizeof(size_t )] ;
};
typedef __off_t off_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;
struct allocator;
struct allocator;
struct allocator;
struct allocator {
   void *(*allocate)(size_t  ) ;
   void *(*reallocate)(void * , size_t  ) ;
   void (*free)(void * ) ;
   void (*die)(size_t  ) ;
};
typedef long ptrdiff_t;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
enum quoting_style {
    literal_quoting_style = 0,
    shell_quoting_style = 1,
    shell_always_quoting_style = 2,
    c_quoting_style = 3,
    c_maybe_quoting_style = 4,
    escape_quoting_style = 5,
    locale_quoting_style = 6,
    clocale_quoting_style = 7,
    custom_quoting_style = 8
} ;
enum strtol_error {
    LONGINT_OK = 0,
    LONGINT_OVERFLOW = 1,
    LONGINT_INVALID_SUFFIX_CHAR = 2,
    LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
    LONGINT_INVALID = 4
} ;
typedef enum strtol_error strtol_error;
struct option {
   char const   *name ;
   int has_arg ;
   int *flag ;
   int val ;
};
typedef unsigned int uint32_t;
typedef int __pid_t;
typedef __pid_t pid_t;
typedef int wchar_t;
typedef int nl_item;
typedef unsigned int wint_t;
typedef long __suseconds_t;
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
};
union __anonunion___value_23 {
   unsigned int __wch ;
   char __wchb[4] ;
};
struct __anonstruct___mbstate_t_22 {
   int __count ;
   union __anonunion___value_23 __value ;
};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
typedef __mbstate_t mbstate_t;
struct mbchar {
   char const   *ptr ;
   size_t bytes ;
   _Bool wc_valid ;
   wchar_t wc ;
   char buf[24] ;
};
struct __anonstruct___sigset_t_9 {
   unsigned long __val[1024UL / (8UL * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___sigset_t_9 __sigset_t;
typedef __sigset_t sigset_t;
struct timezone {
   int tz_minuteswest ;
   int tz_dsttime ;
};
struct obstack;
struct obstack;
struct obstack;
struct _obstack_chunk {
   char *limit ;
   struct _obstack_chunk *prev ;
   char contents[4] ;
};
union __anonunion_temp_26 {
   long tempint ;
   void *tempptr ;
};
struct obstack {
   long chunk_size ;
   struct _obstack_chunk *chunk ;
   char *object_base ;
   char *next_free ;
   char *chunk_limit ;
   union __anonunion_temp_26 temp ;
   int alignment_mask ;
   struct _obstack_chunk *(*chunkfun)(void * , long  ) ;
   void (*freefun)(void * , struct _obstack_chunk * ) ;
   void *extra_arg ;
   unsigned int use_extra_arg : 1 ;
   unsigned int maybe_empty_object : 1 ;
   unsigned int alloc_failed : 1 ;
};
struct Tokens {
   size_t n_tok ;
   char **tok ;
   size_t *tok_len ;
   struct obstack o_data ;
   struct obstack o_tok ;
   struct obstack o_tok_len ;
};
struct randread_source;
struct randread_source;
struct randread_source;
typedef unsigned long uint_least64_t;
typedef struct timezone * __restrict  __timezone_ptr_t;
typedef uint_least64_t isaac_word;
struct isaac_state {
   isaac_word m[1 << 8] ;
   isaac_word a ;
   isaac_word b ;
   isaac_word c ;
};
union __anonunion_data_31 {
   isaac_word w[1 << 8] ;
   unsigned char b[(unsigned long )(1 << 8) * sizeof(isaac_word )] ;
};
struct isaac {
   size_t buffered ;
   struct isaac_state state ;
   union __anonunion_data_31 data ;
};
union __anonunion_buf_30 {
   char c[2UL * ((unsigned long )(1 << 8) * sizeof(isaac_word ))] ;
   struct isaac isaac ;
};
struct randread_source {
   FILE *source ;
   void (*handler)(void const   * ) ;
   void const   *handler_arg ;
   union __anonunion_buf_30 buf ;
};
struct quoting_options;
struct quoting_options;
struct quoting_options;
struct quoting_options {
   enum quoting_style style ;
   int flags ;
   unsigned int quote_these_too[255UL / (sizeof(int ) * 8UL) + 1UL] ;
   char const   *left_quote ;
   char const   *right_quote ;
};
struct slotvec {
   size_t size ;
   char *val ;
};
struct mbuiter_multi {
   _Bool in_shift ;
   mbstate_t state ;
   _Bool next_done ;
   struct mbchar cur ;
};
typedef struct mbuiter_multi mbui_iterator_t;
enum nproc_query {
    NPROC_ALL = 0,
    NPROC_CURRENT = 1,
    NPROC_CURRENT_OVERRIDABLE = 2
} ;
typedef unsigned long __cpu_mask;
struct __anonstruct_cpu_set_t_24 {
   __cpu_mask __bits[1024UL / (8UL * sizeof(__cpu_mask ))] ;
};
typedef struct __anonstruct_cpu_set_t_24 cpu_set_t;
struct md5_ctx {
   uint32_t A ;
   uint32_t B ;
   uint32_t C ;
   uint32_t D ;
   uint32_t total[2] ;
   uint32_t buflen ;
   uint32_t buffer[32] ;
};
struct __pthread_internal_list {
   struct __pthread_internal_list *__prev ;
   struct __pthread_internal_list *__next ;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_mutex_s {
   int __lock ;
   unsigned int __count ;
   int __owner ;
   unsigned int __nusers ;
   int __kind ;
   short __spins ;
   short __elision ;
   __pthread_list_t __list ;
};
union __anonunion_pthread_mutex_t_11 {
   struct __pthread_mutex_s __data ;
   char __size[40] ;
   long __align ;
};
typedef union __anonunion_pthread_mutex_t_11 pthread_mutex_t;
union __anonunion_pthread_mutexattr_t_12 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_mutexattr_t_12 pthread_mutexattr_t;
struct lconv {
   char *decimal_point ;
   char *thousands_sep ;
   char *grouping ;
   char *int_curr_symbol ;
   char *currency_symbol ;
   char *mon_decimal_point ;
   char *mon_thousands_sep ;
   char *mon_grouping ;
   char *positive_sign ;
   char *negative_sign ;
   char int_frac_digits ;
   char frac_digits ;
   char p_cs_precedes ;
   char p_sep_by_space ;
   char n_cs_precedes ;
   char n_sep_by_space ;
   char p_sign_posn ;
   char n_sign_posn ;
   char int_p_cs_precedes ;
   char int_p_sep_by_space ;
   char int_n_cs_precedes ;
   char int_n_sep_by_space ;
   char int_p_sign_posn ;
   char int_n_sign_posn ;
};
struct heap;
struct heap;
struct heap;
struct heap {
   void **array ;
   size_t capacity ;
   size_t count ;
   int (*compare)(void const   * , void const   * ) ;
};
struct hash_entry {
   void *data ;
   struct hash_entry *next ;
};
struct hash_table {
   struct hash_entry *bucket ;
   struct hash_entry  const  *bucket_limit ;
   size_t n_buckets ;
   size_t n_buckets_used ;
   size_t n_entries ;
   Hash_tuning const   *tuning ;
   size_t (*hasher)(void const   * , size_t  ) ;
   _Bool (*comparator)(void const   * , void const   * ) ;
   void (*data_freer)(void * ) ;
   struct hash_entry *free_entry_list ;
};
struct F_triple {
   char *name ;
   ino_t st_ino ;
   dev_t st_dev ;
};
typedef long __clock_t;
union sigval {
   int sival_int ;
   void *sival_ptr ;
};
typedef union sigval sigval_t;
typedef __clock_t __sigchld_clock_t;
struct __anonstruct__kill_23 {
   __pid_t si_pid ;
   __uid_t si_uid ;
};
struct __anonstruct__timer_24 {
   int si_tid ;
   int si_overrun ;
   sigval_t si_sigval ;
};
struct __anonstruct__rt_25 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   sigval_t si_sigval ;
};
struct __anonstruct__sigchld_26 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   int si_status ;
   __sigchld_clock_t si_utime ;
   __sigchld_clock_t si_stime ;
};
struct __anonstruct__sigfault_27 {
   void *si_addr ;
   short si_addr_lsb ;
};
struct __anonstruct__sigpoll_28 {
   long si_band ;
   int si_fd ;
};
struct __anonstruct__sigsys_29 {
   void *_call_addr ;
   int _syscall ;
   unsigned int _arch ;
};
union __anonunion__sifields_22 {
   int _pad[128UL / sizeof(int ) - 4UL] ;
   struct __anonstruct__kill_23 _kill ;
   struct __anonstruct__timer_24 _timer ;
   struct __anonstruct__rt_25 _rt ;
   struct __anonstruct__sigchld_26 _sigchld ;
   struct __anonstruct__sigfault_27 _sigfault ;
   struct __anonstruct__sigpoll_28 _sigpoll ;
   struct __anonstruct__sigsys_29 _sigsys ;
};
struct __anonstruct_siginfo_t_21 {
   int si_signo ;
   int si_errno ;
   int si_code ;
   union __anonunion__sifields_22 _sifields ;
};
typedef struct __anonstruct_siginfo_t_21 siginfo_t;
union __anonunion___sigaction_handler_41 {
   void (*sa_handler)(int  ) ;
   void (*sa_sigaction)(int  , siginfo_t * , void * ) ;
};
struct sigaction {
   union __anonunion___sigaction_handler_41 __sigaction_handler ;
   __sigset_t sa_mask ;
   int sa_flags ;
   void (*sa_restorer)(void) ;
};
enum __anonenum_fadvice_t_19 {
    FADVISE_NORMAL = 0,
    FADVISE_SEQUENTIAL = 2,
    FADVISE_NOREUSE = 5,
    FADVISE_DONTNEED = 4,
    FADVISE_WILLNEED = 3,
    FADVISE_RANDOM = 1
} ;
typedef enum __anonenum_fadvice_t_19 fadvice_t;
typedef unsigned long __rlim_t;
typedef unsigned long pthread_t;
union pthread_attr_t {
   char __size[56] ;
   long __align ;
};
typedef union pthread_attr_t pthread_attr_t;
struct __anonstruct___data_7 {
   int __lock ;
   unsigned int __futex ;
   unsigned long long __total_seq ;
   unsigned long long __wakeup_seq ;
   unsigned long long __woken_seq ;
   void *__mutex ;
   unsigned int __nwaiters ;
   unsigned int __broadcast_seq ;
};
union __anonunion_pthread_cond_t_6 {
   struct __anonstruct___data_7 __data ;
   char __size[48] ;
   long long __align ;
};
typedef union __anonunion_pthread_cond_t_6 pthread_cond_t;
union __anonunion_pthread_condattr_t_8 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_condattr_t_8 pthread_condattr_t;
typedef void (*__sighandler_t)(int  );
enum __rlimit_resource {
    RLIMIT_CPU = 0,
    RLIMIT_FSIZE = 1,
    RLIMIT_DATA = 2,
    RLIMIT_STACK = 3,
    RLIMIT_CORE = 4,
    __RLIMIT_RSS = 5,
    RLIMIT_NOFILE = 7,
    __RLIMIT_OFILE = 7,
    RLIMIT_AS = 9,
    __RLIMIT_NPROC = 6,
    __RLIMIT_MEMLOCK = 8,
    __RLIMIT_LOCKS = 10,
    __RLIMIT_SIGPENDING = 11,
    __RLIMIT_MSGQUEUE = 12,
    __RLIMIT_NICE = 13,
    __RLIMIT_RTPRIO = 14,
    __RLIMIT_RTTIME = 15,
    __RLIMIT_NLIMITS = 16,
    __RLIM_NLIMITS = 16
} ;
typedef __rlim_t rlim_t;
struct rlimit {
   rlim_t rlim_cur ;
   rlim_t rlim_max ;
};
typedef enum __rlimit_resource __rlimit_resource_t;
enum blanktype {
    bl_start = 0,
    bl_end = 1,
    bl_both = 2
} ;
struct line {
   char *text ;
   size_t length ;
   char *keybeg ;
   char *keylim ;
};
struct buffer {
   char *buf ;
   size_t used ;
   size_t nlines ;
   size_t alloc ;
   size_t left ;
   size_t line_bytes ;
   _Bool eof ;
};
struct keyfield {
   size_t sword ;
   size_t schar ;
   size_t eword ;
   size_t echar ;
   _Bool const   *ignore ;
   char const   *translate ;
   _Bool skipsblanks ;
   _Bool skipeblanks ;
   _Bool numeric ;
   _Bool random ;
   _Bool general_numeric ;
   _Bool human_numeric ;
   _Bool month ;
   _Bool reverse ;
   _Bool version ;
   _Bool obsolete_used ;
   struct keyfield *next ;
};
struct month {
   char const   *name ;
   int val ;
};
struct merge_node {
   struct line *lo ;
   struct line *hi ;
   struct line *end_lo ;
   struct line *end_hi ;
   struct line **dest ;
   size_t nlo ;
   size_t nhi ;
   struct merge_node *parent ;
   struct merge_node *lo_child ;
   struct merge_node *hi_child ;
   unsigned int level ;
   _Bool queued ;
   pthread_mutex_t lock ;
};
struct merge_node_queue {
   struct heap *priority_queue ;
   pthread_mutex_t mutex ;
   pthread_cond_t cond ;
};
struct cs_status {
   _Bool valid ;
   sigset_t sigs ;
};
struct tempnode {
   struct tempnode * volatile  next ;
   pid_t pid ;
   char state ;
   char name[1] ;
};
struct sortfile {
   char const   *name ;
   struct tempnode *temp ;
};
union __anonunion_101 {
   int __in ;
   int __i ;
};
union __anonunion_102 {
   int __in ;
   int __i ;
};
struct thread_args {
   struct line *lines ;
   size_t nthreads ;
   size_t total_lines ;
   struct merge_node *node ;
   struct merge_node_queue *queue ;
   FILE *tfp ;
   char const   *output_temp ;
};
struct timespec dtotimespec(double sec ) ;
struct timespec dtotimespec(double sec ) 
{ 
  double min_representable ;
  double max_representable ;
  struct timespec r ;
  time_t s ;
  double frac ;
  long ns ;

  {
  min_representable = (double )(~ (((1L << (sizeof(time_t ) * 8UL - 2UL)) - 1L) * 2L + 1L));
  max_representable = ((double )(((1L << (sizeof(time_t ) * 8UL - 2UL)) - 1L) * 2L + 1L) * (double )1000000000 + (double )999999999) / (double )1000000000;
  if (! (min_representable < sec)) {
    r.tv_sec = ~ (((1L << (sizeof(time_t ) * 8UL - 2UL)) - 1L) * 2L + 1L);
    r.tv_nsec = (__syscall_slong_t )0;
  } else
  if (! (sec < max_representable)) {
    r.tv_sec = ((1L << (sizeof(time_t ) * 8UL - 2UL)) - 1L) * 2L + 1L;
    r.tv_nsec = (__syscall_slong_t )999999999;
  } else {
    s = (time_t )sec;
    frac = (double )1000000000 * (sec - (double )s);
    ns = (long )frac;
    ns += (long )((double )ns < frac);
    s += ns / 1000000000L;
    ns %= 1000000000L;
    if (ns < 0L) {
      s --;
      ns += 1000000000L;
    }
    r.tv_sec = s;
    r.tv_nsec = ns;
  }
  return (r);
}
}
 __attribute__((__noreturn__)) void xalloc_die(void) ;
char *last_component(char const   *name )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2), __leaf__)) memcpy)(void * __restrict  __dest ,
                                                                                                 void const   * __restrict  __src ,
                                                                                                 size_t __n ) ;
extern  __attribute__((__nothrow__)) int *( __attribute__((__leaf__)) __errno_location)(void)  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) stat)(char const   * __restrict  __file ,
                                                                                             struct stat * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd ,
                                                                                            struct stat *__buf ) ;
extern int close(int __fd ) ;
char const   diacrit_base[256] ;
char const   diacrit_diac[256] ;
char const   diacrit_base[256]  = 
  {      (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )'A',      (char const   )'B',      (char const   )'C', 
        (char const   )'D',      (char const   )'E',      (char const   )'F',      (char const   )'G', 
        (char const   )'H',      (char const   )'I',      (char const   )'J',      (char const   )'K', 
        (char const   )'L',      (char const   )'M',      (char const   )'N',      (char const   )'O', 
        (char const   )'P',      (char const   )'Q',      (char const   )'R',      (char const   )'S', 
        (char const   )'T',      (char const   )'U',      (char const   )'V',      (char const   )'W', 
        (char const   )'X',      (char const   )'Y',      (char const   )'Z',      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )'a',      (char const   )'b',      (char const   )'c', 
        (char const   )'d',      (char const   )'e',      (char const   )'f',      (char const   )'g', 
        (char const   )'h',      (char const   )'i',      (char const   )'j',      (char const   )'k', 
        (char const   )'l',      (char const   )'m',      (char const   )'n',      (char const   )'o', 
        (char const   )'p',      (char const   )'q',      (char const   )'r',      (char const   )'s', 
        (char const   )'t',      (char const   )'u',      (char const   )'v',      (char const   )'w', 
        (char const   )'x',      (char const   )'y',      (char const   )'z',      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )'A',      (char const   )'A',      (char const   )'A',      (char const   )'A', 
        (char const   )'A',      (char const   )'A',      (char const   )'A',      (char const   )'C', 
        (char const   )'E',      (char const   )'E',      (char const   )'E',      (char const   )'E', 
        (char const   )'I',      (char const   )'I',      (char const   )'I',      (char const   )'I', 
        (char const   )0,      (char const   )'N',      (char const   )'O',      (char const   )'O', 
        (char const   )'O',      (char const   )'O',      (char const   )'O',      (char const   )0, 
        (char const   )'O',      (char const   )'U',      (char const   )'U',      (char const   )'U', 
        (char const   )'U',      (char const   )'Y',      (char const   )0,      (char const   )0, 
        (char const   )'a',      (char const   )'a',      (char const   )'a',      (char const   )'a', 
        (char const   )'a',      (char const   )'a',      (char const   )'a',      (char const   )'c', 
        (char const   )'e',      (char const   )'e',      (char const   )'e',      (char const   )'e', 
        (char const   )'i',      (char const   )'i',      (char const   )'i',      (char const   )'i', 
        (char const   )0,      (char const   )'n',      (char const   )'o',      (char const   )'o', 
        (char const   )'o',      (char const   )'o',      (char const   )'o',      (char const   )0, 
        (char const   )'o',      (char const   )'u',      (char const   )'u',      (char const   )'u', 
        (char const   )'u',      (char const   )'y',      (char const   )0,      (char const   )'y'};
char const   diacrit_diac[256]  = 
  {      (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )4,      (char const   )0, 
        (char const   )3,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )6,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )6, 
        (char const   )5,      (char const   )8,      (char const   )1,      (char const   )7, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )5, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )5, 
        (char const   )0,      (char const   )6,      (char const   )3,      (char const   )2, 
        (char const   )4,      (char const   )6,      (char const   )5,      (char const   )0, 
        (char const   )9,      (char const   )3,      (char const   )2,      (char const   )4, 
        (char const   )5,      (char const   )2,      (char const   )0,      (char const   )0, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )6, 
        (char const   )5,      (char const   )8,      (char const   )1,      (char const   )7, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )5, 
        (char const   )3,      (char const   )2,      (char const   )4,      (char const   )5, 
        (char const   )0,      (char const   )6,      (char const   )3,      (char const   )2, 
        (char const   )4,      (char const   )6,      (char const   )5,      (char const   )0, 
        (char const   )9,      (char const   )3,      (char const   )2,      (char const   )4, 
        (char const   )5,      (char const   )2,      (char const   )0,      (char const   )0};
Hash_table *( __attribute__((__warn_unused_result__)) hash_initialize)(size_t candidate ,
                                                                       Hash_tuning const   *tuning ,
                                                                       size_t (*hasher)(void const   * ,
                                                                                        size_t  ) ,
                                                                       _Bool (*comparator)(void const   * ,
                                                                                           void const   * ) ,
                                                                       void (*data_freer)(void * ) ) ;
void *( __attribute__((__warn_unused_result__)) hash_insert)(Hash_table *table___0 ,
                                                             void const   *entry ) ;
int hash_insert_if_absent(Hash_table *table___0 , void const   *entry , void const   **matched_ent ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) __assert_fail)(char const   *__assertion ,
                                                                                                   char const   *__file ,
                                                                                                   unsigned int __line ,
                                                                                                   char const   *__function ) ;
int fd_safer(int fd ) ;
extern void error(int __status , int __errnum , char const   *__format  , ...) ;
char const   *quote(char const   *name ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) gettext)(char const   *__msgid )  __attribute__((__format_arg__(1))) ;
void close_stdout(void) ;
extern struct _IO_FILE *stdout ;
extern struct _IO_FILE *stderr ;
extern  __attribute__((__noreturn__)) void _exit(int __status ) ;
int close_stream(FILE *stream ) ;
int volatile   exit_failure ;
char *quotearg_colon(char const   *arg ) ;
static char const   *file_name  ;
static _Bool ignore_EPIPE  ;
void close_stdout(void) 
{ 
  char const   *write_error ;
  char const   *tmp ;
  char *tmp___0 ;
  int *tmp___1 ;
  int *tmp___2 ;
  int tmp___3 ;
  int *tmp___4 ;
  int tmp___5 ;

  {
  tmp___3 = close_stream(stdout);
  if (tmp___3 != 0) {
    if (ignore_EPIPE) {
      tmp___4 = __errno_location();
      if (! (*tmp___4 == 32)) {
        goto _L;
      }
    } else {
      _L: 
      tmp = (char const   *)gettext("write error");
      write_error = tmp;
      if (file_name) {
        tmp___0 = quotearg_colon(file_name);
        tmp___1 = __errno_location();
        error(0, *tmp___1, "%s: %s", tmp___0, write_error);
      } else {
        tmp___2 = __errno_location();
        error(0, *tmp___2, "%s", write_error);
      }
      _exit((int )exit_failure);
    }
  }
  tmp___5 = close_stream(stderr);
  if (tmp___5 != 0) {
    _exit((int )exit_failure);
  }
  return;
}
}
extern struct _IO_FILE *stdin ;
int rpl_fflush(FILE *stream ) ;
int ( __attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp , off_t offset , int whence ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ferror_unlocked)(FILE *__stream ) ;
int ( __attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) __fpending)(FILE *__fp ) ;
int close_stream(FILE *stream ) 
{ 
  _Bool some_pending ;
  size_t tmp ;
  _Bool prev_fail ;
  int tmp___0 ;
  _Bool fclose_fail ;
  int tmp___1 ;
  int *tmp___2 ;
  int *tmp___3 ;

  {
  tmp = __fpending(stream);
  some_pending = (_Bool )(tmp != 0UL);
  tmp___0 = ferror_unlocked(stream);
  prev_fail = (_Bool )(tmp___0 != 0);
  tmp___1 = rpl_fclose(stream);
  fclose_fail = (_Bool )(tmp___1 != 0);
  if (prev_fail) {
    goto _L___0;
  } else
  if (fclose_fail) {
    if (some_pending) {
      goto _L___0;
    } else {
      tmp___3 = __errno_location();
      if (*tmp___3 != 9) {
        _L___0: 
        if (! fclose_fail) {
          tmp___2 = __errno_location();
          *tmp___2 = 0;
        }
        return (-1);
      }
    }
  }
  return (0);
}
}
int rpl_fcntl(int fd , int action  , ...) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memchr)(void const   *__s ,
                                                                                               int __c ,
                                                                                               size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1), __leaf__)) strlen)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) abort)(void) ;
struct allocator  const  stdlib_allocator ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2), __leaf__)) memmove)(void *__dest ,
                                                                                                  void const   *__src ,
                                                                                                  size_t __n ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strchr)(char const   *__s ,
                                                                                               int __c )  __attribute__((__pure__)) ;
size_t triple_hash(void const   *x , size_t table_size )  __attribute__((__pure__)) ;
_Bool triple_compare_ino_str(void const   *x , void const   *y )  __attribute__((__pure__)) ;
void *xmalloc(size_t n )  __attribute__((__malloc__, __alloc_size__(1))) ;
void *xrealloc(void *p , size_t n )  __attribute__((__alloc_size__(2))) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strdup)(char const   *__s )  __attribute__((__malloc__)) ;
int c_tolower(int c )  __attribute__((__const__)) ;
int c_strcasecmp(char const   *s1 , char const   *s2 )  __attribute__((__pure__)) ;
int c_strcasecmp(char const   *s1 , char const   *s2 )  __attribute__((__pure__)) ;
int c_strcasecmp(char const   *s1 , char const   *s2 ) 
{ 
  register unsigned char const   *p1 ;
  register unsigned char const   *p2 ;
  unsigned char c1 ;
  unsigned char c2 ;

  {
  p1 = (unsigned char const   *)s1;
  p2 = (unsigned char const   *)s2;
  if ((unsigned long )p1 == (unsigned long )p2) {
    return (0);
  }
  while (1) {
    c1 = (unsigned char )c_tolower((int )*p1);
    c2 = (unsigned char )c_tolower((int )*p2);
    if ((int )c1 == 0) {
      goto while_break;
    }
    p1 ++;
    p2 ++;
    if (! ((int )c1 == (int )c2)) {
      goto while_break;
    }
  }
  while_break: ;
  return ((int )c1 - (int )c2);
}
}
_Bool c_isalnum(int c )  __attribute__((__const__)) ;
_Bool c_isalpha(int c )  __attribute__((__const__)) ;
_Bool c_isdigit(int c )  __attribute__((__const__)) ;
_Bool c_isspace(int c )  __attribute__((__const__)) ;
_Bool c_isalnum(int c )  __attribute__((__const__)) ;
_Bool c_isalnum(int c ) 
{ 
  int tmp ;

  {
  if (c >= 48) {
    if (c <= 57) {
      tmp = 1;
    } else {
      goto _L;
    }
  } else
  _L: 
  if ((c & -33) >= 65) {
    if ((c & -33) <= 90) {
      tmp = 1;
    } else {
      tmp = 0;
    }
  } else {
    tmp = 0;
  }
  return ((_Bool )tmp);
}
}
_Bool c_isalpha(int c )  __attribute__((__const__)) ;
_Bool c_isalpha(int c ) 
{ 
  int tmp ;

  {
  if ((c & -33) >= 65) {
    if ((c & -33) <= 90) {
      tmp = 1;
    } else {
      tmp = 0;
    }
  } else {
    tmp = 0;
  }
  return ((_Bool )tmp);
}
}
_Bool c_isdigit(int c )  __attribute__((__const__)) ;
_Bool c_isdigit(int c ) 
{ 
  int tmp ;

  {
  if (c >= 48) {
    if (c <= 57) {
      tmp = 1;
    } else {
      tmp = 0;
    }
  } else {
    tmp = 0;
  }
  return ((_Bool )tmp);
}
}
_Bool c_isspace(int c )  __attribute__((__const__)) ;
_Bool c_isspace(int c ) 
{ 
  int tmp ;

  {
  if (c == 32) {
    tmp = 1;
  } else
  if (c == 9) {
    tmp = 1;
  } else
  if (c == 10) {
    tmp = 1;
  } else
  if (c == 11) {
    tmp = 1;
  } else
  if (c == 12) {
    tmp = 1;
  } else
  if (c == 13) {
    tmp = 1;
  } else {
    tmp = 0;
  }
  return ((_Bool )tmp);
}
}
int c_tolower(int c )  __attribute__((__const__)) ;
int c_tolower(int c ) 
{ 
  int tmp ;

  {
  if (c >= 65) {
    if (c <= 90) {
      tmp = (c - 65) + 97;
    } else {
      tmp = c;
    }
  } else {
    tmp = c;
  }
  return (tmp);
}
}
char *last_component(char const   *name )  __attribute__((__pure__)) ;
char *last_component(char const   *name ) 
{ 
  char const   *base ;
  char const   *p ;
  _Bool saw_slash ;

  {
  base = name + 0;
  saw_slash = (_Bool)0;
  while (1) {

    if (! ((int const   )*base == 47)) {
      goto while_break;
    }
    base ++;
  }
  while_break: 
  p = base;
  while (1) {

    if (! *p) {
      goto while_break___0;
    }
    if ((int const   )*p == 47) {
      saw_slash = (_Bool)1;
    } else
    if (saw_slash) {
      base = p;
      saw_slash = (_Bool)0;
    }
    p ++;
  }
  while_break___0: ;
  return ((char *)base);
}
}
__inline static unsigned char to_uchar(char ch ) 
{ 


  {
  return ((unsigned char )ch);
}
}
char const   *simple_backup_suffix ;
void (*argmatch_die)(void) ;
ptrdiff_t __xargmatch_internal(char const   *context , char const   *arg , char const   * const  *arglist ,
                               char const   *vallist , size_t valsize , void (*exit_fn)(void) ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) getenv)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) memcmp)(void const   *__s1 ,
                                                                                               void const   *__s2 ,
                                                                                               size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2), __leaf__)) strcpy)(char * __restrict  __dest ,
                                                                                                 char const   * __restrict  __src ) ;
char const   *simple_backup_suffix  =    "~";
ptrdiff_t argmatch(char const   *arg , char const   * const  *arglist , char const   *vallist ,
                   size_t valsize )  __attribute__((__pure__)) ;
void argmatch_invalid(char const   *context , char const   *value , ptrdiff_t problem ) ;
void argmatch_valid(char const   * const  *arglist , char const   *vallist , size_t valsize ) ;
extern int fprintf(FILE * __restrict  __stream , char const   * __restrict  __format 
                   , ...) ;
extern int putc_unlocked(int __c , FILE *__stream ) ;
extern int fputs_unlocked(char const   * __restrict  __s , FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strncmp)(char const   *__s1 ,
                                                                                                char const   *__s2 ,
                                                                                                size_t __n )  __attribute__((__pure__)) ;
char *quotearg_n_style(int n , enum quoting_style s , char const   *arg ) ;
char const   *quote_n(int n , char const   *name ) ;
 __attribute__((__noreturn__)) void usage(int status ) ;
static void __argmatch_die(void) 
{ 


  {
  usage(1);
  return;
}
}
void (*argmatch_die)(void)  =    & __argmatch_die;
ptrdiff_t argmatch(char const   *arg , char const   * const  *arglist , char const   *vallist ,
                   size_t valsize )  __attribute__((__pure__)) ;
ptrdiff_t argmatch(char const   *arg , char const   * const  *arglist , char const   *vallist ,
                   size_t valsize ) 
{ 
  size_t i ;
  size_t arglen ;
  ptrdiff_t matchind ;
  _Bool ambiguous ;
  int tmp ;
  size_t tmp___0 ;
  int tmp___1 ;

  {
  matchind = (ptrdiff_t )-1;
  ambiguous = (_Bool)0;
  arglen = strlen(arg);
  i = (size_t )0;
  while (1) {

    if (! *(arglist + i)) {
      goto while_break;
    }
    tmp___1 = strncmp((char const   *)*(arglist + i), arg, arglen);
    if (! tmp___1) {
      tmp___0 = strlen((char const   *)*(arglist + i));
      if (tmp___0 == arglen) {
        return ((ptrdiff_t )i);
      } else
      if (matchind == -1L) {
        matchind = (ptrdiff_t )i;
      } else
      if ((unsigned long )vallist == (unsigned long )((void *)0)) {
        ambiguous = (_Bool)1;
      } else {
        tmp = memcmp((void const   *)(vallist + valsize * (size_t )matchind), (void const   *)(vallist + valsize * i),
                     valsize);
        if (tmp) {
          ambiguous = (_Bool)1;
        }
      }
    }
    i ++;
  }
  while_break: ;
  if (ambiguous) {
    return ((ptrdiff_t )-2);
  } else {
    return (matchind);
  }
}
}
void argmatch_invalid(char const   *context , char const   *value , ptrdiff_t problem ) 
{ 
  char const   *format ;
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char const   *tmp___2 ;
  char *tmp___3 ;

  {
  if (problem == -1L) {
    tmp = gettext("invalid argument %s for %s");
    tmp___1 = tmp;
  } else {
    tmp___0 = gettext("ambiguous argument %s for %s");
    tmp___1 = tmp___0;
  }
  format = (char const   *)tmp___1;
  tmp___2 = quote_n(1, context);
  tmp___3 = quotearg_n_style(0, (enum quoting_style )6, value);
  error(0, 0, format, tmp___3, tmp___2);
  return;
}
}
void argmatch_valid(char const   * const  *arglist , char const   *vallist , size_t valsize ) 
{ 
  size_t i ;
  char const   *last_val ;
  char *tmp ;
  char const   *tmp___0 ;
  char const   *tmp___1 ;
  int tmp___2 ;

  {
  last_val = (char const   *)((void *)0);
  tmp = gettext("Valid arguments are:");
  fputs_unlocked((char const   *)tmp, stderr);
  i = (size_t )0;
  while (1) {

    if (! *(arglist + i)) {
      goto while_break;
    }
    if (i == 0UL) {
      tmp___0 = quote((char const   *)*(arglist + i));
      fprintf(stderr, "\n  - %s", tmp___0);
      last_val = vallist + valsize * i;
    } else {
      tmp___2 = memcmp((void const   *)last_val, (void const   *)(vallist + valsize * i),
                       valsize);
      if (tmp___2) {
        tmp___0 = quote((char const   *)*(arglist + i));
        fprintf(stderr, "\n  - %s", tmp___0);
        last_val = vallist + valsize * i;
      } else {
        tmp___1 = quote((char const   *)*(arglist + i));
        fprintf(stderr, ", %s", tmp___1);
      }
    }
    i ++;
  }
  while_break: 
  putc_unlocked('\n', stderr);
  return;
}
}
ptrdiff_t __xargmatch_internal(char const   *context , char const   *arg , char const   * const  *arglist ,
                               char const   *vallist , size_t valsize , void (*exit_fn)(void) ) 
{ 
  ptrdiff_t res ;
  ptrdiff_t tmp ;

  {
  tmp = argmatch(arg, arglist, vallist, valsize);
  res = tmp;
  if (res >= 0L) {
    return (res);
  }
  argmatch_invalid(context, arg, res);
  argmatch_valid(arglist, vallist, valsize);
  (*exit_fn)();
  return ((ptrdiff_t )-1);
}
}
extern  __attribute__((__nothrow__)) void *( __attribute__((__warn_unused_result__,
__leaf__)) realloc)(void *__ptr , size_t __size ) ;
struct allocator  const  stdlib_allocator  =    {(void *(*)(size_t  ))(& malloc), (void *(*)(void * , size_t  ))(& realloc), (void (*)(void * ))(& free),
    (void (*)(size_t  ))((void *)0)};
__inline static void *xnmalloc(size_t n , size_t s )  __attribute__((__malloc__, __alloc_size__(1,2))) ;
__inline static void *xnmalloc(size_t n , size_t s )  __attribute__((__malloc__, __alloc_size__(1,2))) ;
__inline static void *xnmalloc(size_t n , size_t s ) 
{ 
  int tmp ;
  void *tmp___0 ;

  {
  if (sizeof(ptrdiff_t ) <= sizeof(size_t )) {
    tmp = -1;
  } else {
    tmp = -2;
  }
  if ((size_t )tmp / s < n) {
    xalloc_die();
  }
  tmp___0 = xmalloc(n * s);
  return (tmp___0);
}
}
extern  __attribute__((__nothrow__)) unsigned short const   **( __attribute__((__leaf__)) __ctype_b_loc)(void)  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) uintmax_t ( __attribute__((__leaf__)) strtoumax)(char const   * __restrict  __nptr ,
                                                                                      char ** __restrict  __endptr ,
                                                                                      int __base ) ;
strtol_error xstrtoumax(char const   *s , char **ptr , int strtol_base , uintmax_t *val ,
                        char const   *valid_suffixes ) ;
static strtol_error bkm_scale(uintmax_t *x , int scale_factor ) 
{ 


  {
  if (0xffffffffffffffffUL / (unsigned long )scale_factor < *x) {
    *x = 0xffffffffffffffffUL;
    return ((strtol_error )1);
  }
  *x *= (uintmax_t )scale_factor;
  return ((strtol_error )0);
}
}
static strtol_error bkm_scale_by_power(uintmax_t *x , int base , int power ) 
{ 
  strtol_error err ;
  strtol_error tmp ;
  int tmp___0 ;

  {
  err = (strtol_error )0;
  while (1) {
    tmp___0 = power;
    power --;
    if (! tmp___0) {
      goto while_break;
    }
    tmp = bkm_scale(x, base);
    err = (strtol_error )((unsigned int )err | (unsigned int )tmp);
  }
  while_break: ;
  return (err);
}
}
strtol_error xstrtoumax(char const   *s , char **ptr , int strtol_base , uintmax_t *val ,
                        char const   *valid_suffixes ) 
{ 
  char *t_ptr ;
  char **p ;
  uintmax_t tmp ;
  strtol_error err ;
  char const   *q ;
  unsigned char ch ;
  unsigned short const   **tmp___0 ;
  int *tmp___1 ;
  char *tmp___2 ;
  int *tmp___3 ;
  int *tmp___4 ;
  int base ;
  int suffixes ;
  strtol_error overflow ;
  char *tmp___5 ;
  char *tmp___6 ;

  {
  err = (strtol_error )0;
  if (0 <= strtol_base) {
    if (! (strtol_base <= 36)) {
      __assert_fail("0 <= strtol_base && strtol_base <= 36", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/xstrtol.c",
                    96U, "xstrtoumax");
    }
  } else {
    __assert_fail("0 <= strtol_base && strtol_base <= 36", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/xstrtol.c",
                  96U, "xstrtoumax");
  }
  if (ptr) {
    p = ptr;
  } else {
    p = & t_ptr;
  }
  q = s;
  ch = (unsigned char )*q;
  while (1) {
    tmp___0 = __ctype_b_loc();
    if (! ((int const   )*(*tmp___0 + (int )ch) & 8192)) {
      goto while_break;
    }
    q ++;
    ch = (unsigned char )*q;
  }
  while_break: ;
  if ((int )ch == 45) {
    return ((strtol_error )4);
  }
  tmp___1 = __errno_location();
  *tmp___1 = 0;
  tmp = strtoumax(s, p, strtol_base);
  if ((unsigned long )*p == (unsigned long )s) {
    if (valid_suffixes) {
      if (*(*p)) {
        tmp___2 = strchr(valid_suffixes, (int )*(*p));
        if (tmp___2) {
          tmp = (uintmax_t )1;
        } else {
          return ((strtol_error )4);
        }
      } else {
        return ((strtol_error )4);
      }
    } else {
      return ((strtol_error )4);
    }
  } else {
    tmp___4 = __errno_location();
    if (*tmp___4 != 0) {
      tmp___3 = __errno_location();
      if (*tmp___3 != 34) {
        return ((strtol_error )4);
      }
      err = (strtol_error )1;
    }
  }
  if (! valid_suffixes) {
    *val = tmp;
    return (err);
  }
  if ((int )*(*p) != 0) {
    base = 1024;
    suffixes = 1;
    tmp___5 = strchr(valid_suffixes, (int )*(*p));
    if (! tmp___5) {
      *val = tmp;
      return ((strtol_error )((unsigned int )err | 2U));
    }
    tmp___6 = strchr(valid_suffixes, '0');
    if (tmp___6) {
      if ((int )*(*(p + 0) + 1) == 105) {
        goto case_105;
      }
      if ((int )*(*(p + 0) + 1) == 66) {
        goto case_66;
      }
      if ((int )*(*(p + 0) + 1) == 68) {
        goto case_66;
      }
      goto switch_break;
      case_105: 
      if ((int )*(*(p + 0) + 2) == 66) {
        suffixes += 2;
      }
      goto switch_break;
      case_66: 
      base = 1000;
      suffixes ++;
      goto switch_break;
      switch_break: ;
    }
    if ((int )*(*p) == 98) {
      goto case_98;
    }
    if ((int )*(*p) == 66) {
      goto case_66___0;
    }
    if ((int )*(*p) == 99) {
      goto case_99;
    }
    if ((int )*(*p) == 69) {
      goto case_69;
    }
    if ((int )*(*p) == 71) {
      goto case_71;
    }
    if ((int )*(*p) == 103) {
      goto case_71;
    }
    if ((int )*(*p) == 107) {
      goto case_107;
    }
    if ((int )*(*p) == 75) {
      goto case_107;
    }
    if ((int )*(*p) == 77) {
      goto case_77;
    }
    if ((int )*(*p) == 109) {
      goto case_77;
    }
    if ((int )*(*p) == 80) {
      goto case_80;
    }
    if ((int )*(*p) == 84) {
      goto case_84;
    }
    if ((int )*(*p) == 116) {
      goto case_84;
    }
    if ((int )*(*p) == 119) {
      goto case_119;
    }
    if ((int )*(*p) == 89) {
      goto case_89;
    }
    if ((int )*(*p) == 90) {
      goto case_90;
    }
    goto switch_default;
    case_98: 
    overflow = bkm_scale(& tmp, 512);
    goto switch_break___0;
    case_66___0: 
    overflow = bkm_scale(& tmp, 1024);
    goto switch_break___0;
    case_99: 
    overflow = (strtol_error )0;
    goto switch_break___0;
    case_69: 
    overflow = bkm_scale_by_power(& tmp, base, 6);
    goto switch_break___0;
    case_71: 
    overflow = bkm_scale_by_power(& tmp, base, 3);
    goto switch_break___0;
    case_107: 
    overflow = bkm_scale_by_power(& tmp, base, 1);
    goto switch_break___0;
    case_77: 
    overflow = bkm_scale_by_power(& tmp, base, 2);
    goto switch_break___0;
    case_80: 
    overflow = bkm_scale_by_power(& tmp, base, 5);
    goto switch_break___0;
    case_84: 
    overflow = bkm_scale_by_power(& tmp, base, 4);
    goto switch_break___0;
    case_119: 
    overflow = bkm_scale(& tmp, 2);
    goto switch_break___0;
    case_89: 
    overflow = bkm_scale_by_power(& tmp, base, 8);
    goto switch_break___0;
    case_90: 
    overflow = bkm_scale_by_power(& tmp, base, 7);
    goto switch_break___0;
    switch_default: 
    *val = tmp;
    return ((strtol_error )((unsigned int )err | 2U));
    switch_break___0: 
    err = (strtol_error )((unsigned int )err | (unsigned int )overflow);
    *p += suffixes;
    if (*(*p)) {
      err = (strtol_error )((unsigned int )err | 2U);
    }
  }
  *val = tmp;
  return (err);
}
}
strtol_error xstrtoul(char const   *s , char **ptr , int strtol_base , unsigned long *val ,
                      char const   *valid_suffixes ) ;
extern  __attribute__((__nothrow__)) unsigned long ( __attribute__((__nonnull__(1),
__leaf__)) strtoul)(char const   * __restrict  __nptr , char ** __restrict  __endptr ,
                    int __base ) ;
static strtol_error bkm_scale___0(unsigned long *x , int scale_factor ) 
{ 


  {
  if (0xffffffffffffffffUL / (unsigned long )scale_factor < *x) {
    *x = 0xffffffffffffffffUL;
    return ((strtol_error )1);
  }
  *x *= (unsigned long )scale_factor;
  return ((strtol_error )0);
}
}
static strtol_error bkm_scale_by_power___0(unsigned long *x , int base , int power ) 
{ 
  strtol_error err ;
  strtol_error tmp ;
  int tmp___0 ;

  {
  err = (strtol_error )0;
  while (1) {
    tmp___0 = power;
    power --;
    if (! tmp___0) {
      goto while_break;
    }
    tmp = bkm_scale___0(x, base);
    err = (strtol_error )((unsigned int )err | (unsigned int )tmp);
  }
  while_break: ;
  return (err);
}
}
strtol_error xstrtoul(char const   *s , char **ptr , int strtol_base , unsigned long *val ,
                      char const   *valid_suffixes ) 
{ 
  char *t_ptr ;
  char **p ;
  unsigned long tmp ;
  strtol_error err ;
  char const   *q ;
  unsigned char ch ;
  unsigned short const   **tmp___0 ;
  int *tmp___1 ;
  char *tmp___2 ;
  int *tmp___3 ;
  int *tmp___4 ;
  int base ;
  int suffixes ;
  strtol_error overflow ;
  char *tmp___5 ;
  char *tmp___6 ;

  {
  err = (strtol_error )0;
  if (0 <= strtol_base) {
    if (! (strtol_base <= 36)) {
      __assert_fail("0 <= strtol_base && strtol_base <= 36", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/xstrtol.c",
                    96U, "xstrtoul");
    }
  } else {
    __assert_fail("0 <= strtol_base && strtol_base <= 36", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/xstrtol.c",
                  96U, "xstrtoul");
  }
  if (ptr) {
    p = ptr;
  } else {
    p = & t_ptr;
  }
  q = s;
  ch = (unsigned char )*q;
  while (1) {
    tmp___0 = __ctype_b_loc();
    if (! ((int const   )*(*tmp___0 + (int )ch) & 8192)) {
      goto while_break;
    }
    q ++;
    ch = (unsigned char )*q;
  }
  while_break: ;
  if ((int )ch == 45) {
    return ((strtol_error )4);
  }
  tmp___1 = __errno_location();
  *tmp___1 = 0;
  tmp = strtoul(s, p, strtol_base);
  if ((unsigned long )*p == (unsigned long )s) {
    if (valid_suffixes) {
      if (*(*p)) {
        tmp___2 = strchr(valid_suffixes, (int )*(*p));
        if (tmp___2) {
          tmp = 1UL;
        } else {
          return ((strtol_error )4);
        }
      } else {
        return ((strtol_error )4);
      }
    } else {
      return ((strtol_error )4);
    }
  } else {
    tmp___4 = __errno_location();
    if (*tmp___4 != 0) {
      tmp___3 = __errno_location();
      if (*tmp___3 != 34) {
        return ((strtol_error )4);
      }
      err = (strtol_error )1;
    }
  }
  if (! valid_suffixes) {
    *val = tmp;
    return (err);
  }
  if ((int )*(*p) != 0) {
    base = 1024;
    suffixes = 1;
    tmp___5 = strchr(valid_suffixes, (int )*(*p));
    if (! tmp___5) {
      *val = tmp;
      return ((strtol_error )((unsigned int )err | 2U));
    }
    tmp___6 = strchr(valid_suffixes, '0');
    if (tmp___6) {
      if ((int )*(*(p + 0) + 1) == 105) {
        goto case_105;
      }
      if ((int )*(*(p + 0) + 1) == 66) {
        goto case_66;
      }
      if ((int )*(*(p + 0) + 1) == 68) {
        goto case_66;
      }
      goto switch_break;
      case_105: 
      if ((int )*(*(p + 0) + 2) == 66) {
        suffixes += 2;
      }
      goto switch_break;
      case_66: 
      base = 1000;
      suffixes ++;
      goto switch_break;
      switch_break: ;
    }
    if ((int )*(*p) == 98) {
      goto case_98;
    }
    if ((int )*(*p) == 66) {
      goto case_66___0;
    }
    if ((int )*(*p) == 99) {
      goto case_99;
    }
    if ((int )*(*p) == 69) {
      goto case_69;
    }
    if ((int )*(*p) == 71) {
      goto case_71;
    }
    if ((int )*(*p) == 103) {
      goto case_71;
    }
    if ((int )*(*p) == 107) {
      goto case_107;
    }
    if ((int )*(*p) == 75) {
      goto case_107;
    }
    if ((int )*(*p) == 77) {
      goto case_77;
    }
    if ((int )*(*p) == 109) {
      goto case_77;
    }
    if ((int )*(*p) == 80) {
      goto case_80;
    }
    if ((int )*(*p) == 84) {
      goto case_84;
    }
    if ((int )*(*p) == 116) {
      goto case_84;
    }
    if ((int )*(*p) == 119) {
      goto case_119;
    }
    if ((int )*(*p) == 89) {
      goto case_89;
    }
    if ((int )*(*p) == 90) {
      goto case_90;
    }
    goto switch_default;
    case_98: 
    overflow = bkm_scale___0(& tmp, 512);
    goto switch_break___0;
    case_66___0: 
    overflow = bkm_scale___0(& tmp, 1024);
    goto switch_break___0;
    case_99: 
    overflow = (strtol_error )0;
    goto switch_break___0;
    case_69: 
    overflow = bkm_scale_by_power___0(& tmp, base, 6);
    goto switch_break___0;
    case_71: 
    overflow = bkm_scale_by_power___0(& tmp, base, 3);
    goto switch_break___0;
    case_107: 
    overflow = bkm_scale_by_power___0(& tmp, base, 1);
    goto switch_break___0;
    case_77: 
    overflow = bkm_scale_by_power___0(& tmp, base, 2);
    goto switch_break___0;
    case_80: 
    overflow = bkm_scale_by_power___0(& tmp, base, 5);
    goto switch_break___0;
    case_84: 
    overflow = bkm_scale_by_power___0(& tmp, base, 4);
    goto switch_break___0;
    case_119: 
    overflow = bkm_scale___0(& tmp, 2);
    goto switch_break___0;
    case_89: 
    overflow = bkm_scale_by_power___0(& tmp, base, 8);
    goto switch_break___0;
    case_90: 
    overflow = bkm_scale_by_power___0(& tmp, base, 7);
    goto switch_break___0;
    switch_default: 
    *val = tmp;
    return ((strtol_error )((unsigned int )err | 2U));
    switch_break___0: 
    err = (strtol_error )((unsigned int )err | (unsigned int )overflow);
    *p += suffixes;
    if (*(*p)) {
      err = (strtol_error )((unsigned int )err | 2U);
    }
  }
  *val = tmp;
  return (err);
}
}
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1), __leaf__)) strtol)(char const   * __restrict  __nptr ,
                                                                                              char ** __restrict  __endptr ,
                                                                                              int __base ) ;
 __attribute__((__noreturn__)) void xstrtol_fatal(enum strtol_error err , int opt_idx ,
                                                  char c , struct option  const  *long_options___2 ,
                                                  char const   *arg ) ;
static void xstrtol_error(enum strtol_error err , int opt_idx , char c , struct option  const  *long_options___2 ,
                          char const   *arg , int exit_status ) 
{ 
  char const   *hyphens ;
  char const   *msgid ;
  char const   *option ;
  char option_buffer[2] ;
  char *tmp ;

  {
  hyphens = "--";
  if ((unsigned int )err == 4U) {
    goto case_4;
  }
  if ((unsigned int )err == 2U) {
    goto case_2;
  }
  if ((unsigned int )err == 3U) {
    goto case_2;
  }
  if ((unsigned int )err == 1U) {
    goto case_1;
  }
  goto switch_default;
  switch_default: 
  abort();
  case_4: 
  msgid = "invalid %s%s argument \'%s\'";
  goto switch_break;
  case_2: 
  msgid = "invalid suffix in %s%s argument \'%s\'";
  goto switch_break;
  case_1: 
  msgid = "%s%s argument \'%s\' too large";
  goto switch_break;
  switch_break: ;
  if (opt_idx < 0) {
    hyphens -= opt_idx;
    option_buffer[0] = c;
    option_buffer[1] = (char )'\000';
    option = (char const   *)(option_buffer);
  } else {
    option = (char const   *)(long_options___2 + opt_idx)->name;
  }
  tmp = gettext(msgid);
  error(exit_status, 0, (char const   *)tmp, hyphens, option, arg);
  return;
}
}
 __attribute__((__noreturn__)) void xstrtol_fatal(enum strtol_error err , int opt_idx ,
                                                  char c , struct option  const  *long_options___2 ,
                                                  char const   *arg ) ;
void xstrtol_fatal(enum strtol_error err , int opt_idx , char c , struct option  const  *long_options___2 ,
                   char const   *arg ) 
{ 


  {
  xstrtol_error(err, opt_idx, c, long_options___2, arg, (int )exit_failure);
  abort();
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ferror)(FILE *__stream ) ;
int xnanosleep(double seconds ) ;
int ( __attribute__((__nonnull__(1))) rpl_nanosleep)(struct timespec  const  *requested_delay ,
                                                     struct timespec *remaining_delay ) ;
int xnanosleep(double seconds ) 
{ 
  struct timespec ts_sleep ;
  struct timespec tmp ;
  int *tmp___0 ;
  int tmp___1 ;
  int *tmp___2 ;
  int *tmp___3 ;

  {
  tmp = dtotimespec(seconds);
  ts_sleep = tmp;
  while (1) {
    tmp___0 = __errno_location();
    *tmp___0 = 0;
    tmp___1 = rpl_nanosleep((struct timespec  const  *)(& ts_sleep), (struct timespec *)((void *)0));
    if (tmp___1 == 0) {
      goto while_break;
    }
    tmp___2 = __errno_location();
    if (*tmp___2 != 4) {
      tmp___3 = __errno_location();
      if (*tmp___3 != 0) {
        return (-1);
      }
    }
  }
  while_break: ;
  return (0);
}
}
int memcoll0(char const   *s1 , size_t s1size , char const   *s2 , size_t s2size ) ;
char *quotearg_n_style_mem(int n , enum quoting_style s , char const   *arg , size_t argsize ) ;
int xmemcoll0(char const   *s1 , size_t s1size , char const   *s2 , size_t s2size ) ;
static void collate_error(int collation_errno , char const   *s1 , size_t s1len ,
                          char const   *s2 , size_t s2len ) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char *tmp___3 ;

  {
  tmp = gettext("string comparison failed");
  error(0, collation_errno, (char const   *)tmp);
  tmp___0 = gettext("Set LC_ALL=\'C\' to work around the problem.");
  error(0, 0, (char const   *)tmp___0);
  tmp___1 = quotearg_n_style_mem(1, (enum quoting_style )6, s2, s2len);
  tmp___2 = quotearg_n_style_mem(0, (enum quoting_style )6, s1, s1len);
  tmp___3 = gettext("The strings compared were %s and %s.");
  error((int )exit_failure, 0, (char const   *)tmp___3, tmp___2, tmp___1);
  return;
}
}
int xmemcoll0(char const   *s1 , size_t s1size , char const   *s2 , size_t s2size ) 
{ 
  int diff ;
  int tmp ;
  int collation_errno ;
  int *tmp___0 ;

  {
  tmp = memcoll0(s1, s1size, s2, s2size);
  diff = tmp;
  tmp___0 = __errno_location();
  collation_errno = *tmp___0;
  if (collation_errno) {
    collate_error(collation_errno, s1, s1size - 1UL, s2, s2size - 1UL);
  }
  return (diff);
}
}
void *xcalloc(size_t n , size_t s )  __attribute__((__malloc__, __alloc_size__(1,2))) ;
void *xmemdup(void const   *p , size_t s )  __attribute__((__malloc__, __alloc_size__(2))) ;
__inline static void *x2nrealloc(void *p , size_t *pn , size_t s ) 
{ 
  size_t n ;
  void *tmp ;

  {
  n = *pn;
  if (! p) {
    if (! n) {
      n = 128UL / s;
      n += (size_t )(! n);
    }
  } else {
    if (0xaaaaaaaaaaaaaaaaUL / s <= n) {
      xalloc_die();
    }
    n += (n + 1UL) / 2UL;
  }
  *pn = n;
  tmp = xrealloc(p, n * s);
  return (tmp);
}
}
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1), __leaf__)) memset)(void *__s ,
                                                                                               int __c ,
                                                                                               size_t __n ) ;
void *xmalloc(size_t n )  __attribute__((__malloc__, __alloc_size__(1))) ;
void *xmalloc(size_t n ) 
{ 
  void *p ;
  void *tmp ;

  {
  tmp = malloc(n);
  p = tmp;
  if (! p) {
    if (n != 0UL) {
      xalloc_die();
    }
  }
  return (p);
}
}
void *xrealloc(void *p , size_t n )  __attribute__((__alloc_size__(2))) ;
void *xrealloc(void *p , size_t n ) 
{ 


  {
  if (! n) {
    if (p) {
      free(p);
      return ((void *)0);
    }
  }
  p = realloc(p, n);
  if (! p) {
    if (n) {
      xalloc_die();
    }
  }
  return (p);
}
}
void *xcalloc(size_t n , size_t s )  __attribute__((__malloc__, __alloc_size__(1,2))) ;
void *xcalloc(size_t n , size_t s ) 
{ 
  void *p ;

  {
  p = calloc(n, s);
  if (! p) {
    xalloc_die();
  }
  return (p);
}
}
void *xmemdup(void const   *p , size_t s )  __attribute__((__malloc__, __alloc_size__(2))) ;
void *xmemdup(void const   *p , size_t s ) 
{ 
  void *tmp ;
  void *tmp___0 ;

  {
  tmp = xmalloc(s);
  tmp___0 = memcpy(tmp, p, s);
  return (tmp___0);
}
}
 __attribute__((__noreturn__)) void xalloc_die(void) ;
void xalloc_die(void) 
{ 
  char *tmp ;

  {
  tmp = gettext("memory exhausted");
  error((int )exit_failure, 0, "%s", tmp);
  abort();
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strcmp)(char const   *__s1 ,
                                                                                               char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) atexit)(void (*__func)(void) ) ;
extern __pid_t waitpid(__pid_t __pid , int *__stat_loc , int __options ) ;
extern int printf(char const   * __restrict  __format  , ...) ;
char const   version_etc_copyright[47] ;
void version_etc_arn(FILE *stream , char const   *command_name , char const   *package ,
                     char const   *version , char const   * const  *authors , size_t n_authors ) ;
void version_etc_va(FILE *stream , char const   *command_name , char const   *package ,
                    char const   *version , va_list authors ) ;
void version_etc(FILE *stream , char const   *command_name , char const   *package ,
                 char const   *version  , ...)  __attribute__((__sentinel__)) ;
void version_etc_arn(FILE *stream , char const   *command_name , char const   *package ,
                     char const   *version , char const   * const  *authors , size_t n_authors ) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  char *tmp___6 ;
  char *tmp___7 ;
  char *tmp___8 ;
  char *tmp___9 ;
  char *tmp___10 ;

  {
  if (command_name) {
    fprintf(stream, "%s (%s) %s\n", command_name, package, version);
  } else {
    fprintf(stream, "%s %s\n", package, version);
  }
  tmp = gettext("(C)");
  fprintf(stream, version_etc_copyright, tmp, 2012);
  tmp___0 = gettext("\nLicense GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n\n");
  fputs_unlocked((char const   *)tmp___0, stream);
  if (n_authors == 0UL) {
    goto case_0;
  }
  if (n_authors == 1UL) {
    goto case_1;
  }
  if (n_authors == 2UL) {
    goto case_2;
  }
  if (n_authors == 3UL) {
    goto case_3;
  }
  if (n_authors == 4UL) {
    goto case_4;
  }
  if (n_authors == 5UL) {
    goto case_5;
  }
  if (n_authors == 6UL) {
    goto case_6;
  }
  if (n_authors == 7UL) {
    goto case_7;
  }
  if (n_authors == 8UL) {
    goto case_8;
  }
  if (n_authors == 9UL) {
    goto case_9;
  }
  goto switch_default;
  case_0: 
  abort();
  case_1: 
  tmp___1 = gettext("Written by %s.\n");
  fprintf(stream, (char const   *)tmp___1, *(authors + 0));
  goto switch_break;
  case_2: 
  tmp___2 = gettext("Written by %s and %s.\n");
  fprintf(stream, (char const   *)tmp___2, *(authors + 0), *(authors + 1));
  goto switch_break;
  case_3: 
  tmp___3 = gettext("Written by %s, %s, and %s.\n");
  fprintf(stream, (char const   *)tmp___3, *(authors + 0), *(authors + 1), *(authors + 2));
  goto switch_break;
  case_4: 
  tmp___4 = gettext("Written by %s, %s, %s,\nand %s.\n");
  fprintf(stream, (char const   *)tmp___4, *(authors + 0), *(authors + 1), *(authors + 2),
          *(authors + 3));
  goto switch_break;
  case_5: 
  tmp___5 = gettext("Written by %s, %s, %s,\n%s, and %s.\n");
  fprintf(stream, (char const   *)tmp___5, *(authors + 0), *(authors + 1), *(authors + 2),
          *(authors + 3), *(authors + 4));
  goto switch_break;
  case_6: 
  tmp___6 = gettext("Written by %s, %s, %s,\n%s, %s, and %s.\n");
  fprintf(stream, (char const   *)tmp___6, *(authors + 0), *(authors + 1), *(authors + 2),
          *(authors + 3), *(authors + 4), *(authors + 5));
  goto switch_break;
  case_7: 
  tmp___7 = gettext("Written by %s, %s, %s,\n%s, %s, %s, and %s.\n");
  fprintf(stream, (char const   *)tmp___7, *(authors + 0), *(authors + 1), *(authors + 2),
          *(authors + 3), *(authors + 4), *(authors + 5), *(authors + 6));
  goto switch_break;
  case_8: 
  tmp___8 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\nand %s.\n");
  fprintf(stream, (char const   *)tmp___8, *(authors + 0), *(authors + 1), *(authors + 2),
          *(authors + 3), *(authors + 4), *(authors + 5), *(authors + 6), *(authors + 7));
  goto switch_break;
  case_9: 
  tmp___9 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, and %s.\n");
  fprintf(stream, (char const   *)tmp___9, *(authors + 0), *(authors + 1), *(authors + 2),
          *(authors + 3), *(authors + 4), *(authors + 5), *(authors + 6), *(authors + 7),
          *(authors + 8));
  goto switch_break;
  switch_default: 
  tmp___10 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, %s, and others.\n");
  fprintf(stream, (char const   *)tmp___10, *(authors + 0), *(authors + 1), *(authors + 2),
          *(authors + 3), *(authors + 4), *(authors + 5), *(authors + 6), *(authors + 7),
          *(authors + 8));
  goto switch_break;
  switch_break: ;
  return;
}
}
void version_etc_va(FILE *stream , char const   *command_name , char const   *package ,
                    char const   *version , va_list authors ) 
{ 
  size_t n_authors ;
  char const   *authtab[10] ;
  char const   *tmp ;

  {
  n_authors = (size_t )0;
  while (1) {

    if (n_authors < 10UL) {
      tmp = __builtin_va_arg(authors, char const   *);
      authtab[n_authors] = tmp;
      if (! ((unsigned long )tmp != (unsigned long )((void *)0))) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    n_authors ++;
  }
  while_break: 
  version_etc_arn(stream, command_name, package, version, (char const   * const  *)(authtab),
                  n_authors);
  return;
}
}
void version_etc(FILE *stream , char const   *command_name , char const   *package ,
                 char const   *version  , ...)  __attribute__((__sentinel__)) ;
void version_etc(FILE *stream , char const   *command_name , char const   *package ,
                 char const   *version  , ...) 
{ 
  va_list authors ;

  {
  __builtin_va_start(authors, version);
  version_etc_va(stream, command_name, package, version, authors);
  __builtin_va_end(authors);
  return;
}
}
char const   version_etc_copyright[47]  = 
  {      (char const   )'C',      (char const   )'o',      (char const   )'p',      (char const   )'y', 
        (char const   )'r',      (char const   )'i',      (char const   )'g',      (char const   )'h', 
        (char const   )'t',      (char const   )' ',      (char const   )'%',      (char const   )'s', 
        (char const   )' ',      (char const   )'%',      (char const   )'d',      (char const   )' ', 
        (char const   )'F',      (char const   )'r',      (char const   )'e',      (char const   )'e', 
        (char const   )' ',      (char const   )'S',      (char const   )'o',      (char const   )'f', 
        (char const   )'t',      (char const   )'w',      (char const   )'a',      (char const   )'r', 
        (char const   )'e',      (char const   )' ',      (char const   )'F',      (char const   )'o', 
        (char const   )'u',      (char const   )'n',      (char const   )'d',      (char const   )'a', 
        (char const   )'t',      (char const   )'i',      (char const   )'o',      (char const   )'n', 
        (char const   )',',      (char const   )' ',      (char const   )'I',      (char const   )'n', 
        (char const   )'c',      (char const   )'.',      (char const   )'\000'};
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) nl_langinfo)(nl_item __item ) ;
char *( __attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i , char *buf___1 ) ;
char const   *locale_charset(void) ;
#pragma GCC diagnostic ignored "-Wtype-limits"
char *( __attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i , char *buf___1 ) 
{ 
  char *p ;

  {
  p = buf___1 + ((sizeof(uintmax_t ) * 8UL) * 146UL + 484UL) / 485UL;
  *p = (char)0;
  if (i < 0UL) {
    while (1) {
      p --;
      *p = (char )(48UL - i % 10UL);
      i /= 10UL;
      if (! (i != 0UL)) {
        goto while_break;
      }
    }
    while_break: 
    p --;
    *p = (char )'-';
  } else {
    while (1) {
      p --;
      *p = (char )(48UL + i % 10UL);
      i /= 10UL;
      if (! (i != 0UL)) {
        goto while_break___0;
      }
    }
    while_break___0: ;
  }
  return (p);
}
}
#pragma GCC diagnostic ignored "-Wtype-limits"
char *( __attribute__((__warn_unused_result__)) uinttostr)(unsigned int i , char *buf___1 ) ;
char *( __attribute__((__warn_unused_result__)) uinttostr)(unsigned int i , char *buf___1 ) 
{ 
  char *p ;

  {
  p = buf___1 + ((sizeof(unsigned int ) * 8UL) * 146UL + 484UL) / 485UL;
  *p = (char)0;
  if (i < 0U) {
    while (1) {
      p --;
      *p = (char )(48U - i % 10U);
      i /= 10U;
      if (! (i != 0U)) {
        goto while_break;
      }
    }
    while_break: 
    p --;
    *p = (char )'-';
  } else {
    while (1) {
      p --;
      *p = (char )(48U + i % 10U);
      i /= 10U;
      if (! (i != 0U)) {
        goto while_break___0;
      }
    }
    while_break___0: ;
  }
  return (p);
}
}
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) __ctype_get_mb_cur_max)(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) mbsinit)(mbstate_t const   *__ps )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) mbrtowc)(wchar_t * __restrict  __pwc ,
                                                                                 char const   * __restrict  __s ,
                                                                                 size_t __n ,
                                                                                 mbstate_t * __restrict  __p ) ;
unsigned int const   is_basic_table[8] ;
__inline static _Bool is_basic(char c ) 
{ 


  {
  return ((_Bool )((is_basic_table[(int )((unsigned char )c) >> 5] >> ((int )((unsigned char )c) & 31)) & 1U));
}
}
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file , int __oflag 
                                                   , ...) ;
int __attribute__((__pure__))  strnumcmp(char const   *a , char const   *b , int decimal_point___0 ,
                                         int thousands_sep___0 ) ;
__inline static int __attribute__((__pure__))  fraccompare(char const   *a , char const   *b ,
                                                           char decimal_point___0 ) 
{ 
  char const   *tmp ;
  char const   *tmp___0 ;

  {
  if ((int const   )*a == (int const   )decimal_point___0) {
    if ((int const   )*b == (int const   )decimal_point___0) {
      while (1) {
        a ++;
        b ++;
        if (! ((int const   )*a == (int const   )*b)) {
          goto while_break;
        }
        if (! ((unsigned int )*a - 48U <= 9U)) {
          return ((int __attribute__((__pure__))  )0);
        }
      }
      while_break: ;
      if ((unsigned int )*a - 48U <= 9U) {
        if ((unsigned int )*b - 48U <= 9U) {
          return ((int __attribute__((__pure__))  )((int const   )*a - (int const   )*b));
        }
      }
      if ((unsigned int )*a - 48U <= 9U) {
        goto a_trailing_nonzero;
      }
      if ((unsigned int )*b - 48U <= 9U) {
        goto b_trailing_nonzero;
      }
      return ((int __attribute__((__pure__))  )0);
    } else {
      goto _L;
    }
  } else {
    _L: 
    tmp___0 = a;
    a ++;
    if ((int const   )*tmp___0 == (int const   )decimal_point___0) {
      a_trailing_nonzero: 
      while (1) {

        if (! ((int const   )*a == 48)) {
          goto while_break___0;
        }
        a ++;
      }
      while_break___0: ;
      return ((int __attribute__((__pure__))  )((unsigned int )*a - 48U <= 9U));
    } else {
      tmp = b;
      b ++;
      if ((int const   )*tmp == (int const   )decimal_point___0) {
        b_trailing_nonzero: 
        while (1) {

          if (! ((int const   )*b == 48)) {
            goto while_break___1;
          }
          b ++;
        }
        while_break___1: ;
        return ((int __attribute__((__pure__))  )(- ((unsigned int )*b - 48U <= 9U)));
      }
    }
  }
  return ((int __attribute__((__pure__))  )0);
}
}
__inline static int __attribute__((__pure__))  numcompare(char const   *a , char const   *b ,
                                                          int decimal_point___0 ,
                                                          int thousands_sep___0 ) 
{ 
  unsigned char tmpa ;
  unsigned char tmpb ;
  int tmp ;
  size_t log_a ;
  size_t log_b ;
  int __attribute__((__pure__))  tmp___0 ;
  int tmp___1 ;
  int __attribute__((__pure__))  tmp___2 ;
  int tmp___3 ;

  {
  tmpa = (unsigned char )*a;
  tmpb = (unsigned char )*b;
  if ((int )tmpa == 45) {
    while (1) {
      a ++;
      tmpa = (unsigned char )*a;
      if (! ((int )tmpa == 48)) {
        if (! ((int )tmpa == thousands_sep___0)) {
          goto while_break;
        }
      }
    }
    while_break: ;
    if ((int )tmpb != 45) {
      if ((int )tmpa == decimal_point___0) {
        while (1) {
          a ++;
          tmpa = (unsigned char )*a;
          if (! ((int )tmpa == 48)) {
            goto while_break___0;
          }
        }
        while_break___0: ;
      }
      if ((unsigned int )tmpa - 48U <= 9U) {
        return ((int __attribute__((__pure__))  )-1);
      }
      while (1) {

        if (! ((int )tmpb == 48)) {
          if (! ((int )tmpb == thousands_sep___0)) {
            goto while_break___1;
          }
        }
        b ++;
        tmpb = (unsigned char )*b;
      }
      while_break___1: ;
      if ((int )tmpb == decimal_point___0) {
        while (1) {
          b ++;
          tmpb = (unsigned char )*b;
          if (! ((int )tmpb == 48)) {
            goto while_break___2;
          }
        }
        while_break___2: ;
      }
      return ((int __attribute__((__pure__))  )(- ((unsigned int )tmpb - 48U <= 9U)));
    }
    while (1) {
      b ++;
      tmpb = (unsigned char )*b;
      if (! ((int )tmpb == 48)) {
        if (! ((int )tmpb == thousands_sep___0)) {
          goto while_break___3;
        }
      }
    }
    while_break___3: ;
    while (1) {

      if ((int )tmpa == (int )tmpb) {
        if (! ((unsigned int )tmpa - 48U <= 9U)) {
          goto while_break___4;
        }
      } else {
        goto while_break___4;
      }
      while (1) {
        a ++;
        tmpa = (unsigned char )*a;
        if (! ((int )tmpa == thousands_sep___0)) {
          goto while_break___5;
        }
      }
      while_break___5: ;
      while (1) {
        b ++;
        tmpb = (unsigned char )*b;
        if (! ((int )tmpb == thousands_sep___0)) {
          goto while_break___6;
        }
      }
      while_break___6: ;
    }
    while_break___4: ;
    if ((int )tmpa == decimal_point___0) {
      if (! ((unsigned int )tmpb - 48U <= 9U)) {
        tmp___0 = fraccompare(b, a, (char )decimal_point___0);
        return (tmp___0);
      } else {
        goto _L;
      }
    } else
    _L: 
    if ((int )tmpb == decimal_point___0) {
      if (! ((unsigned int )tmpa - 48U <= 9U)) {
        tmp___0 = fraccompare(b, a, (char )decimal_point___0);
        return (tmp___0);
      }
    }
    tmp = (int )tmpb - (int )tmpa;
    log_a = (size_t )0;
    while (1) {

      if (! ((unsigned int )tmpa - 48U <= 9U)) {
        goto while_break___7;
      }
      while (1) {
        a ++;
        tmpa = (unsigned char )*a;
        if (! ((int )tmpa == thousands_sep___0)) {
          goto while_break___8;
        }
      }
      while_break___8: 
      log_a ++;
    }
    while_break___7: 
    log_b = (size_t )0;
    while (1) {

      if (! ((unsigned int )tmpb - 48U <= 9U)) {
        goto while_break___9;
      }
      while (1) {
        b ++;
        tmpb = (unsigned char )*b;
        if (! ((int )tmpb == thousands_sep___0)) {
          goto while_break___10;
        }
      }
      while_break___10: 
      log_b ++;
    }
    while_break___9: ;
    if (log_a != log_b) {
      if (log_a < log_b) {
        tmp___1 = 1;
      } else {
        tmp___1 = -1;
      }
      return ((int __attribute__((__pure__))  )tmp___1);
    }
    if (! log_a) {
      return ((int __attribute__((__pure__))  )0);
    }
    return ((int __attribute__((__pure__))  )tmp);
  } else
  if ((int )tmpb == 45) {
    while (1) {
      b ++;
      tmpb = (unsigned char )*b;
      if (! ((int )tmpb == 48)) {
        if (! ((int )tmpb == thousands_sep___0)) {
          goto while_break___11;
        }
      }
    }
    while_break___11: ;
    if ((int )tmpb == decimal_point___0) {
      while (1) {
        b ++;
        tmpb = (unsigned char )*b;
        if (! ((int )tmpb == 48)) {
          goto while_break___12;
        }
      }
      while_break___12: ;
    }
    if ((unsigned int )tmpb - 48U <= 9U) {
      return ((int __attribute__((__pure__))  )1);
    }
    while (1) {

      if (! ((int )tmpa == 48)) {
        if (! ((int )tmpa == thousands_sep___0)) {
          goto while_break___13;
        }
      }
      a ++;
      tmpa = (unsigned char )*a;
    }
    while_break___13: ;
    if ((int )tmpa == decimal_point___0) {
      while (1) {
        a ++;
        tmpa = (unsigned char )*a;
        if (! ((int )tmpa == 48)) {
          goto while_break___14;
        }
      }
      while_break___14: ;
    }
    return ((int __attribute__((__pure__))  )((unsigned int )tmpa - 48U <= 9U));
  } else {
    while (1) {

      if (! ((int )tmpa == 48)) {
        if (! ((int )tmpa == thousands_sep___0)) {
          goto while_break___15;
        }
      }
      a ++;
      tmpa = (unsigned char )*a;
    }
    while_break___15: ;
    while (1) {

      if (! ((int )tmpb == 48)) {
        if (! ((int )tmpb == thousands_sep___0)) {
          goto while_break___16;
        }
      }
      b ++;
      tmpb = (unsigned char )*b;
    }
    while_break___16: ;
    while (1) {

      if ((int )tmpa == (int )tmpb) {
        if (! ((unsigned int )tmpa - 48U <= 9U)) {
          goto while_break___17;
        }
      } else {
        goto while_break___17;
      }
      while (1) {
        a ++;
        tmpa = (unsigned char )*a;
        if (! ((int )tmpa == thousands_sep___0)) {
          goto while_break___18;
        }
      }
      while_break___18: ;
      while (1) {
        b ++;
        tmpb = (unsigned char )*b;
        if (! ((int )tmpb == thousands_sep___0)) {
          goto while_break___19;
        }
      }
      while_break___19: ;
    }
    while_break___17: ;
    if ((int )tmpa == decimal_point___0) {
      if (! ((unsigned int )tmpb - 48U <= 9U)) {
        tmp___2 = fraccompare(a, b, (char )decimal_point___0);
        return (tmp___2);
      } else {
        goto _L___0;
      }
    } else
    _L___0: 
    if ((int )tmpb == decimal_point___0) {
      if (! ((unsigned int )tmpa - 48U <= 9U)) {
        tmp___2 = fraccompare(a, b, (char )decimal_point___0);
        return (tmp___2);
      }
    }
    tmp = (int )tmpa - (int )tmpb;
    log_a = (size_t )0;
    while (1) {

      if (! ((unsigned int )tmpa - 48U <= 9U)) {
        goto while_break___20;
      }
      while (1) {
        a ++;
        tmpa = (unsigned char )*a;
        if (! ((int )tmpa == thousands_sep___0)) {
          goto while_break___21;
        }
      }
      while_break___21: 
      log_a ++;
    }
    while_break___20: 
    log_b = (size_t )0;
    while (1) {

      if (! ((unsigned int )tmpb - 48U <= 9U)) {
        goto while_break___22;
      }
      while (1) {
        b ++;
        tmpb = (unsigned char )*b;
        if (! ((int )tmpb == thousands_sep___0)) {
          goto while_break___23;
        }
      }
      while_break___23: 
      log_b ++;
    }
    while_break___22: ;
    if (log_a != log_b) {
      if (log_a < log_b) {
        tmp___3 = -1;
      } else {
        tmp___3 = 1;
      }
      return ((int __attribute__((__pure__))  )tmp___3);
    }
    if (! log_a) {
      return ((int __attribute__((__pure__))  )0);
    }
    return ((int __attribute__((__pure__))  )tmp);
  }
}
}
int __attribute__((__pure__))  strnumcmp(char const   *a , char const   *b , int decimal_point___0 ,
                                         int thousands_sep___0 ) 
{ 
  int __attribute__((__pure__))  tmp ;

  {
  tmp = numcompare(a, b, decimal_point___0, thousands_sep___0);
  return (tmp);
}
}
size_t strnlen1(char const   *string , size_t maxlen )  __attribute__((__pure__)) ;
size_t strnlen1(char const   *string , size_t maxlen )  __attribute__((__pure__)) ;
size_t strnlen1(char const   *string , size_t maxlen ) 
{ 
  char const   *end ;
  char const   *tmp ;

  {
  tmp = (char const   *)memchr((void const   *)string, '\000', maxlen);
  end = tmp;
  if ((unsigned long )end != (unsigned long )((void *)0)) {
    return ((size_t )((end - string) + 1L));
  } else {
    return (maxlen);
  }
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) tolower)(int __c ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) toupper)(int __c ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) sigprocmask)(int __how ,
                                                                                  sigset_t const   * __restrict  __set ,
                                                                                  sigset_t * __restrict  __oset ) ;
extern size_t fread_unlocked(void * __restrict  __ptr , size_t __size , size_t __n ,
                             FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) feof_unlocked)(FILE *__stream ) ;
__inline static void set_uint32(char *cp , uint32_t v ) 
{ 


  {
  memcpy((void *)cp, (void const   *)(& v), sizeof(v));
  return;
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) raise)(int __sig ) ;
extern  __attribute__((__nothrow__)) __pid_t fork(void) ;
extern ssize_t read(int __fd , void *__buf , size_t __nbytes ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) unlink)(char const   *__name ) ;
extern int fgetc(FILE *__stream ) ;
extern void _obstack_newchunk(struct obstack * , int  ) ;
extern int _obstack_begin(struct obstack * , int  , int  , void *(*)(long  ) , void (*)(void * ) ) ;
void readtokens0_init(struct Tokens *t ) ;
_Bool readtokens0(FILE *in , struct Tokens *t ) ;
void readtokens0_init(struct Tokens *t ) 
{ 


  {
  t->n_tok = (size_t )0;
  t->tok = (char **)((void *)0);
  t->tok_len = (size_t *)((void *)0);
  _obstack_begin(& t->o_data, 0, 0, (void *(*)(long  ))(& malloc), (void (*)(void * ))(& free));
  _obstack_begin(& t->o_tok, 0, 0, (void *(*)(long  ))(& malloc), (void (*)(void * ))(& free));
  _obstack_begin(& t->o_tok_len, 0, 0, (void *(*)(long  ))(& malloc), (void (*)(void * ))(& free));
  return;
}
}
static void save_token(struct Tokens *t ) 
{ 
  size_t len ;
  struct obstack  const  *__o ;
  char const   *s ;
  struct obstack *__o1 ;
  void *__value ;
  char *tmp ;
  char *tmp___0 ;
  struct obstack *__o___0 ;
  struct obstack *__o1___0 ;
  struct obstack *__o___1 ;
  int __len ;

  {
  __o = (struct obstack  const  *)(& t->o_data);
  len = (size_t )((unsigned int )(__o->next_free - __o->object_base) - 1U);
  __o1 = & t->o_data;
  __value = (void *)__o1->object_base;
  if ((unsigned long )__o1->next_free == (unsigned long )__value) {
    __o1->maybe_empty_object = 1U;
  }
  if (sizeof(long ) < sizeof(void *)) {
    tmp = __o1->object_base;
  } else {
    tmp = (char *)0;
  }
  if (sizeof(long ) < sizeof(void *)) {
    tmp___0 = __o1->object_base;
  } else {
    tmp___0 = (char *)0;
  }
  __o1->next_free = tmp + (((__o1->next_free - tmp___0) + (long )__o1->alignment_mask) & (long )(~ __o1->alignment_mask));
  if (__o1->next_free - (char *)__o1->chunk > __o1->chunk_limit - (char *)__o1->chunk) {
    __o1->next_free = __o1->chunk_limit;
  }
  __o1->object_base = __o1->next_free;
  s = (char const   *)__value;
  __o___0 = & t->o_tok;
  if ((unsigned long )(__o___0->next_free + sizeof(void *)) > (unsigned long )__o___0->chunk_limit) {
    _obstack_newchunk(__o___0, (int )sizeof(void *));
  }
  __o1___0 = __o___0;
  *((void const   **)__o1___0->next_free) = (void const   *)s;
  __o1___0->next_free += sizeof(void const   *);
  __o___1 = & t->o_tok_len;
  __len = (int )sizeof(len);
  if ((unsigned long )(__o___1->next_free + __len) > (unsigned long )__o___1->chunk_limit) {
    _obstack_newchunk(__o___1, __len);
  }
  memcpy((void *)__o___1->next_free, (void const   *)(& len), (size_t )__len);
  __o___1->next_free += __len;
  (t->n_tok) ++;
  return;
}
}
_Bool readtokens0(FILE *in , struct Tokens *t ) 
{ 
  int c ;
  int tmp ;
  size_t len ;
  struct obstack  const  *__o ;
  struct obstack *__o___0 ;
  char *tmp___0 ;
  struct obstack *__o___1 ;
  char *tmp___1 ;
  struct obstack *__o___2 ;
  struct obstack *__o1 ;
  struct obstack *__o1___0 ;
  void *__value ;
  char *tmp___2 ;
  char *tmp___3 ;
  struct obstack *__o1___1 ;
  void *__value___0 ;
  char *tmp___4 ;
  char *tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;

  {
  while (1) {
    tmp = fgetc(in);
    c = tmp;
    if (c == -1) {
      __o = (struct obstack  const  *)(& t->o_data);
      len = (size_t )((unsigned int )(__o->next_free - __o->object_base));
      if (len) {
        __o___0 = & t->o_data;
        if ((unsigned long )(__o___0->next_free + 1) > (unsigned long )__o___0->chunk_limit) {
          _obstack_newchunk(__o___0, 1);
        }
        tmp___0 = __o___0->next_free;
        (__o___0->next_free) ++;
        *tmp___0 = (char )'\000';
        save_token(t);
      }
      goto while_break;
    }
    __o___1 = & t->o_data;
    if ((unsigned long )(__o___1->next_free + 1) > (unsigned long )__o___1->chunk_limit) {
      _obstack_newchunk(__o___1, 1);
    }
    tmp___1 = __o___1->next_free;
    (__o___1->next_free) ++;
    *tmp___1 = (char )c;
    if (c == 0) {
      save_token(t);
    }
  }
  while_break: 
  __o___2 = & t->o_tok;
  if ((unsigned long )(__o___2->next_free + sizeof(void *)) > (unsigned long )__o___2->chunk_limit) {
    _obstack_newchunk(__o___2, (int )sizeof(void *));
  }
  __o1 = __o___2;
  *((void const   **)__o1->next_free) = (void const   *)((void *)0);
  __o1->next_free += sizeof(void const   *);
  __o1___0 = & t->o_tok;
  __value = (void *)__o1___0->object_base;
  if ((unsigned long )__o1___0->next_free == (unsigned long )__value) {
    __o1___0->maybe_empty_object = 1U;
  }
  if (sizeof(long ) < sizeof(void *)) {
    tmp___2 = __o1___0->object_base;
  } else {
    tmp___2 = (char *)0;
  }
  if (sizeof(long ) < sizeof(void *)) {
    tmp___3 = __o1___0->object_base;
  } else {
    tmp___3 = (char *)0;
  }
  __o1___0->next_free = tmp___2 + (((__o1___0->next_free - tmp___3) + (long )__o1___0->alignment_mask) & (long )(~ __o1___0->alignment_mask));
  if (__o1___0->next_free - (char *)__o1___0->chunk > __o1___0->chunk_limit - (char *)__o1___0->chunk) {
    __o1___0->next_free = __o1___0->chunk_limit;
  }
  __o1___0->object_base = __o1___0->next_free;
  t->tok = (char **)__value;
  __o1___1 = & t->o_tok_len;
  __value___0 = (void *)__o1___1->object_base;
  if ((unsigned long )__o1___1->next_free == (unsigned long )__value___0) {
    __o1___1->maybe_empty_object = 1U;
  }
  if (sizeof(long ) < sizeof(void *)) {
    tmp___4 = __o1___1->object_base;
  } else {
    tmp___4 = (char *)0;
  }
  if (sizeof(long ) < sizeof(void *)) {
    tmp___5 = __o1___1->object_base;
  } else {
    tmp___5 = (char *)0;
  }
  __o1___1->next_free = tmp___4 + (((__o1___1->next_free - tmp___5) + (long )__o1___1->alignment_mask) & (long )(~ __o1___1->alignment_mask));
  if (__o1___1->next_free - (char *)__o1___1->chunk > __o1___1->chunk_limit - (char *)__o1___1->chunk) {
    __o1___1->next_free = __o1___1->chunk_limit;
  }
  __o1___1->object_base = __o1___1->next_free;
  t->tok_len = (size_t *)__value___0;
  tmp___6 = ferror(in);
  if (tmp___6) {
    tmp___7 = 0;
  } else {
    tmp___7 = 1;
  }
  return ((_Bool )tmp___7);
}
}
extern int getc_unlocked(FILE *__stream ) ;
extern FILE *fopen(char const   * __restrict  __filename , char const   * __restrict  __modes ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fileno)(FILE *__stream ) ;
struct randread_source *randread_new(char const   *name , size_t bytes_bound ) ;
void randread(struct randread_source *s , void *buf___1 , size_t size ) ;
int randread_free(struct randread_source *s ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) setvbuf)(FILE * __restrict  __stream ,
                                                                              char * __restrict  __buf ,
                                                                              int __modes ,
                                                                              size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) gettimeofday)(struct timeval * __restrict  __tv ,
                                                                                                   __timezone_ptr_t __tz ) ;
extern  __attribute__((__nothrow__)) __pid_t ( __attribute__((__leaf__)) getpid)(void) ;
extern  __attribute__((__nothrow__)) __pid_t ( __attribute__((__leaf__)) getppid)(void) ;
extern  __attribute__((__nothrow__)) __uid_t ( __attribute__((__leaf__)) getuid)(void) ;
extern  __attribute__((__nothrow__)) __gid_t ( __attribute__((__leaf__)) getgid)(void) ;
void isaac_seed(struct isaac_state *s ) ;
void isaac_refill(struct isaac_state *s , isaac_word *result ) ;
FILE *fopen_safer(char const   *file , char const   *mode ) ;
static void randread_error(void const   *file_name___3 ) 
{ 
  char *tmp ;
  char const   *tmp___1 ;
  int *tmp___2 ;
  char *tmp___3 ;
  int *tmp___4 ;

  {
  if (file_name___3) {
    tmp = quotearg_colon(file_name___3);
    tmp___2 = __errno_location();
    if (*tmp___2 == 0) {
      tmp___1 = "%s: end of file";
    } else {
      tmp___1 = "%s: read error";
    }
    tmp___3 = gettext(tmp___1);
    tmp___4 = __errno_location();
    error(exit_failure, *tmp___4, tmp___3, tmp);
  }
  abort();
}
}
static struct randread_source *simple_new(FILE *source , void const   *handler_arg ) 
{ 
  struct randread_source *s ;
  struct randread_source *tmp ;

  {
  tmp = (struct randread_source *)xmalloc(sizeof(*s));
  s = tmp;
  s->source = source;
  s->handler = & randread_error;
  s->handler_arg = handler_arg;
  return (s);
}
}
static void get_nonce(void *buffer , size_t bufsize___1 , size_t bytes_bound ) 
{ 
  char *buf___1 ;
  ssize_t seeded ;
  int fd ;
  int tmp ;
  size_t tmp___0 ;
  struct timeval v ;
  size_t nbytes ;
  unsigned long tmp___1 ;
  pid_t v___0 ;
  size_t nbytes___0 ;
  unsigned long tmp___2 ;
  pid_t v___1 ;
  size_t nbytes___1 ;
  unsigned long tmp___3 ;
  uid_t v___2 ;
  size_t nbytes___2 ;
  unsigned long tmp___4 ;
  uid_t v___3 ;
  size_t nbytes___3 ;
  unsigned long tmp___5 ;

  {
  buf___1 = (char *)buffer;
  seeded = (ssize_t )0;
  tmp = open("/dev/urandom", 0);
  fd = tmp;
  if (0 <= fd) {
    if (bufsize___1 < bytes_bound) {
      tmp___0 = bufsize___1;
    } else {
      tmp___0 = bytes_bound;
    }
    seeded = read(fd, (void *)buf___1, tmp___0);
    if (seeded < 0L) {
      seeded = (ssize_t )0;
    }
    close(fd);
  }
  if ((size_t )seeded < bufsize___1) {
    if (sizeof(v) < bufsize___1 - (size_t )seeded) {
      tmp___1 = sizeof(v);
    } else {
      tmp___1 = bufsize___1 - (size_t )seeded;
    }
    nbytes = tmp___1;
    gettimeofday(& v, (__timezone_ptr_t )((void *)0));
    memcpy((void *)(buf___1 + seeded), (void const   *)(& v), nbytes);
    seeded = (ssize_t )((size_t )seeded + nbytes);
  }
  if ((size_t )seeded < bufsize___1) {
    if (sizeof(v___0) < bufsize___1 - (size_t )seeded) {
      tmp___2 = sizeof(v___0);
    } else {
      tmp___2 = bufsize___1 - (size_t )seeded;
    }
    nbytes___0 = tmp___2;
    v___0 = getpid();
    memcpy((void *)(buf___1 + seeded), (void const   *)(& v___0), nbytes___0);
    seeded = (ssize_t )((size_t )seeded + nbytes___0);
  }
  if ((size_t )seeded < bufsize___1) {
    if (sizeof(v___1) < bufsize___1 - (size_t )seeded) {
      tmp___3 = sizeof(v___1);
    } else {
      tmp___3 = bufsize___1 - (size_t )seeded;
    }
    nbytes___1 = tmp___3;
    v___1 = getppid();
    memcpy((void *)(buf___1 + seeded), (void const   *)(& v___1), nbytes___1);
    seeded = (ssize_t )((size_t )seeded + nbytes___1);
  }
  if ((size_t )seeded < bufsize___1) {
    if (sizeof(v___2) < bufsize___1 - (size_t )seeded) {
      tmp___4 = sizeof(v___2);
    } else {
      tmp___4 = bufsize___1 - (size_t )seeded;
    }
    nbytes___2 = tmp___4;
    v___2 = getuid();
    memcpy((void *)(buf___1 + seeded), (void const   *)(& v___2), nbytes___2);
    seeded = (ssize_t )((size_t )seeded + nbytes___2);
  }
  if ((size_t )seeded < bufsize___1) {
    if (sizeof(v___3) < bufsize___1 - (size_t )seeded) {
      tmp___5 = sizeof(v___3);
    } else {
      tmp___5 = bufsize___1 - (size_t )seeded;
    }
    nbytes___3 = tmp___5;
    v___3 = getgid();
    memcpy((void *)(buf___1 + seeded), (void const   *)(& v___3), nbytes___3);
    seeded = (ssize_t )((size_t )seeded + nbytes___3);
  }
  return;
}
}
struct randread_source *randread_new(char const   *name , size_t bytes_bound ) 
{ 
  struct randread_source *tmp ;
  FILE *source ;
  struct randread_source *s ;
  unsigned long tmp___0 ;

  {
  if (bytes_bound == 0UL) {
    tmp = simple_new((FILE *)((void *)0), (void const   *)((void *)0));
    return (tmp);
  } else {
    source = (FILE *)((void *)0);
    if (name) {
      source = fopen_safer(name, "rb");
      if (! source) {
        return ((struct randread_source *)((void *)0));
      }
    }
    s = simple_new(source, (void const   *)name);
    if (source) {
      if (sizeof(s->buf.c) < bytes_bound) {
        tmp___0 = sizeof(s->buf.c);
      } else {
        tmp___0 = bytes_bound;
      }
      setvbuf(source, s->buf.c, 0, tmp___0);
    } else {
      s->buf.isaac.buffered = (size_t )0;
      get_nonce((void *)(s->buf.isaac.state.m), sizeof(s->buf.isaac.state.m), bytes_bound);
      isaac_seed(& s->buf.isaac.state);
    }
    return (s);
  }
}
}
static void readsource(struct randread_source *s , unsigned char *p , size_t size ) 
{ 
  size_t inbytes ;
  size_t tmp ;
  int fread_errno ;
  int *tmp___0 ;
  int *tmp___1 ;
  int tmp___3 ;

  {
  while (1) {
    tmp = fread_unlocked((void *)p, sizeof(*p), size, s->source);
    inbytes = tmp;
    tmp___0 = __errno_location();
    fread_errno = *tmp___0;
    p += inbytes;
    size -= inbytes;
    if (size == 0UL) {
      goto while_break;
    }
    tmp___1 = __errno_location();
    tmp___3 = ferror_unlocked(s->source);
    if (tmp___3) {
      *tmp___1 = fread_errno;
    } else {
      *tmp___1 = 0;
    }
    (*(s->handler))(s->handler_arg);
  }
  while_break: ;
  return;
}
}
static void readisaac(struct isaac *isaac , unsigned char *p , size_t size ) 
{ 
  size_t inbytes ;
  isaac_word *wp ;

  {
  inbytes = isaac->buffered;
  while (1) {

    if (size <= inbytes) {
      memcpy((void *)p, (void const   *)((isaac->data.b + (unsigned long )(1 << 8) * sizeof(isaac_word )) - inbytes),
             size);
      isaac->buffered = inbytes - size;
      return;
    }
    memcpy((void *)p, (void const   *)((isaac->data.b + (unsigned long )(1 << 8) * sizeof(isaac_word )) - inbytes),
           inbytes);
    p += inbytes;
    size -= inbytes;
    wp = (isaac_word *)p;
    while (1) {

      if (! ((unsigned long )(1 << 8) * sizeof(isaac_word ) <= size)) {
        goto while_break___0;
      }
      isaac_refill(& isaac->state, wp);
      wp += 1 << 8;
      size -= (unsigned long )(1 << 8) * sizeof(isaac_word );
      if (size == 0UL) {
        isaac->buffered = (size_t )0;
        return;
      }
    }
    while_break___0: 
    p = (unsigned char *)wp;
    isaac_refill(& isaac->state, isaac->data.w);
    inbytes = (unsigned long )(1 << 8) * sizeof(isaac_word );
  }

  return;
}
}
void randread(struct randread_source *s , void *buf___1 , size_t size ) 
{ 


  {
  if (s->source) {
    readsource(s, (unsigned char *)buf___1, size);
  } else {
    readisaac(& s->buf.isaac, (unsigned char *)buf___1, size);
  }
  return;
}
}
int randread_free(struct randread_source *s ) 
{ 
  FILE *source ;
  int tmp ;
  int tmp___0 ;

  {
  source = s->source;
  memset((void *)s, 0, sizeof(*s));
  free((void *)s);
  if (source) {
    tmp = rpl_fclose(source);
    tmp___0 = tmp;
  } else {
    tmp___0 = 0;
  }
  return (tmp___0);
}
}
void *hash_delete(Hash_table *table___0 , void const   *entry ) ;
__inline static isaac_word just(isaac_word a ) 
{ 
  isaac_word desired_bits ;

  {
  desired_bits = ((1UL << 1) << ((1 << 6) - 1)) - 1UL;
  return (a & desired_bits);
}
}
__inline static isaac_word ind(isaac_word const   *m , isaac_word x ) 
{ 
  isaac_word tmp ;

  {
  if (sizeof(*m) * 8UL == (unsigned long )(1 << 6)) {
    tmp = *((isaac_word *)((char *)m + (x & (unsigned long )((1 << 8) - 1) * sizeof(*m))));
  } else {
    tmp = (isaac_word )*(m + (x / (isaac_word )((1 << 6) / 8) & (unsigned long )((1 << 8) - 1)));
  }
  return (tmp);
}
}
void isaac_refill(struct isaac_state *s , isaac_word *result ) 
{ 
  isaac_word a ;
  isaac_word b ;
  isaac_word *m ;
  isaac_word *r ;
  isaac_word x ;
  isaac_word y ;
  isaac_word tmp ;
  isaac_word tmp___0 ;
  isaac_word tmp___1 ;
  isaac_word tmp___2 ;
  isaac_word x___0 ;
  isaac_word y___0 ;
  isaac_word tmp___3 ;
  isaac_word tmp___4 ;
  isaac_word tmp___5 ;
  isaac_word tmp___6 ;
  isaac_word tmp___7 ;
  isaac_word tmp___8 ;
  isaac_word x___1 ;
  isaac_word y___1 ;
  isaac_word tmp___9 ;
  isaac_word tmp___10 ;
  isaac_word tmp___11 ;
  isaac_word tmp___12 ;
  isaac_word x___2 ;
  isaac_word y___2 ;
  isaac_word tmp___13 ;
  isaac_word tmp___14 ;
  isaac_word tmp___15 ;
  isaac_word tmp___16 ;
  isaac_word tmp___17 ;
  isaac_word tmp___18 ;
  isaac_word x___3 ;
  isaac_word y___3 ;
  isaac_word tmp___19 ;
  isaac_word tmp___20 ;
  isaac_word tmp___21 ;
  isaac_word tmp___22 ;
  isaac_word x___4 ;
  isaac_word y___4 ;
  isaac_word tmp___23 ;
  isaac_word tmp___24 ;
  isaac_word tmp___25 ;
  isaac_word tmp___26 ;
  isaac_word tmp___27 ;
  isaac_word tmp___28 ;
  isaac_word x___5 ;
  isaac_word y___5 ;
  isaac_word tmp___29 ;
  isaac_word tmp___30 ;
  isaac_word tmp___31 ;
  isaac_word tmp___32 ;
  isaac_word x___6 ;
  isaac_word y___6 ;
  isaac_word tmp___33 ;
  isaac_word tmp___34 ;
  isaac_word tmp___35 ;
  isaac_word tmp___36 ;
  isaac_word tmp___37 ;
  isaac_word tmp___38 ;

  {
  a = s->a;
  (s->c) ++;
  b = s->b + s->c;
  m = s->m;
  r = result;
  while (1) {

    if (1 << 6 == 32) {
      tmp = a;
    } else {
      tmp = (isaac_word )0;
    }
    if (1 << 6 == 32) {
      tmp___0 = a << 13;
    } else {
      tmp___0 = ~ (a ^ (a << 21));
    }
    a = (tmp ^ tmp___0) + *(m + 128);
    x = *(m + 0);
    tmp___1 = ind((isaac_word const   *)(s->m), x);
    y = (tmp___1 + a) + b;
    *(m + 0) = y;
    tmp___2 = ind((isaac_word const   *)(s->m), y >> 8);
    b = just(tmp___2 + x);
    *(r + 0) = b;
    if (1 << 6 == 32) {
      tmp___3 = a;
    } else {
      tmp___3 = (isaac_word )0;
    }
    if (1 << 6 == 32) {
      tmp___4 = just(a);
      tmp___6 = tmp___4 >> 6;
    } else {
      tmp___5 = just(a);
      tmp___6 = a ^ (tmp___5 >> 5);
    }
    a = (tmp___3 ^ tmp___6) + *(m + 129);
    x___0 = *(m + 1);
    tmp___7 = ind((isaac_word const   *)(s->m), x___0);
    y___0 = (tmp___7 + a) + b;
    *(m + 1) = y___0;
    tmp___8 = ind((isaac_word const   *)(s->m), y___0 >> 8);
    b = just(tmp___8 + x___0);
    *(r + 1) = b;
    if (1 << 6 == 32) {
      tmp___9 = a;
    } else {
      tmp___9 = (isaac_word )0;
    }
    if (1 << 6 == 32) {
      tmp___10 = a << 2;
    } else {
      tmp___10 = a ^ (a << 12);
    }
    a = (tmp___9 ^ tmp___10) + *(m + 130);
    x___1 = *(m + 2);
    tmp___11 = ind((isaac_word const   *)(s->m), x___1);
    y___1 = (tmp___11 + a) + b;
    *(m + 2) = y___1;
    tmp___12 = ind((isaac_word const   *)(s->m), y___1 >> 8);
    b = just(tmp___12 + x___1);
    *(r + 2) = b;
    if (1 << 6 == 32) {
      tmp___13 = a;
    } else {
      tmp___13 = (isaac_word )0;
    }
    if (1 << 6 == 32) {
      tmp___14 = just(a);
      tmp___16 = tmp___14 >> 16;
    } else {
      tmp___15 = just(a);
      tmp___16 = a ^ (tmp___15 >> 33);
    }
    a = (tmp___13 ^ tmp___16) + *(m + 131);
    x___2 = *(m + 3);
    tmp___17 = ind((isaac_word const   *)(s->m), x___2);
    y___2 = (tmp___17 + a) + b;
    *(m + 3) = y___2;
    tmp___18 = ind((isaac_word const   *)(s->m), y___2 >> 8);
    b = just(tmp___18 + x___2);
    *(r + 3) = b;
    r += 4;
    m += 4;
    if (! ((unsigned long )m < (unsigned long )(s->m + 128))) {
      goto while_break;
    }
  }
  while_break: ;
  while (1) {

    if (1 << 6 == 32) {
      tmp___19 = a;
    } else {
      tmp___19 = (isaac_word )0;
    }
    if (1 << 6 == 32) {
      tmp___20 = a << 13;
    } else {
      tmp___20 = ~ (a ^ (a << 21));
    }
    a = (tmp___19 ^ tmp___20) + *(m + -128);
    x___3 = *(m + 0);
    tmp___21 = ind((isaac_word const   *)(s->m), x___3);
    y___3 = (tmp___21 + a) + b;
    *(m + 0) = y___3;
    tmp___22 = ind((isaac_word const   *)(s->m), y___3 >> 8);
    b = just(tmp___22 + x___3);
    *(r + 0) = b;
    if (1 << 6 == 32) {
      tmp___23 = a;
    } else {
      tmp___23 = (isaac_word )0;
    }
    if (1 << 6 == 32) {
      tmp___24 = just(a);
      tmp___26 = tmp___24 >> 6;
    } else {
      tmp___25 = just(a);
      tmp___26 = a ^ (tmp___25 >> 5);
    }
    a = (tmp___23 ^ tmp___26) + *(m + -127);
    x___4 = *(m + 1);
    tmp___27 = ind((isaac_word const   *)(s->m), x___4);
    y___4 = (tmp___27 + a) + b;
    *(m + 1) = y___4;
    tmp___28 = ind((isaac_word const   *)(s->m), y___4 >> 8);
    b = just(tmp___28 + x___4);
    *(r + 1) = b;
    if (1 << 6 == 32) {
      tmp___29 = a;
    } else {
      tmp___29 = (isaac_word )0;
    }
    if (1 << 6 == 32) {
      tmp___30 = a << 2;
    } else {
      tmp___30 = a ^ (a << 12);
    }
    a = (tmp___29 ^ tmp___30) + *(m + -126);
    x___5 = *(m + 2);
    tmp___31 = ind((isaac_word const   *)(s->m), x___5);
    y___5 = (tmp___31 + a) + b;
    *(m + 2) = y___5;
    tmp___32 = ind((isaac_word const   *)(s->m), y___5 >> 8);
    b = just(tmp___32 + x___5);
    *(r + 2) = b;
    if (1 << 6 == 32) {
      tmp___33 = a;
    } else {
      tmp___33 = (isaac_word )0;
    }
    if (1 << 6 == 32) {
      tmp___34 = just(a);
      tmp___36 = tmp___34 >> 16;
    } else {
      tmp___35 = just(a);
      tmp___36 = a ^ (tmp___35 >> 33);
    }
    a = (tmp___33 ^ tmp___36) + *(m + -125);
    x___6 = *(m + 3);
    tmp___37 = ind((isaac_word const   *)(s->m), x___6);
    y___6 = (tmp___37 + a) + b;
    *(m + 3) = y___6;
    tmp___38 = ind((isaac_word const   *)(s->m), y___6 >> 8);
    b = just(tmp___38 + x___6);
    *(r + 3) = b;
    r += 4;
    m += 4;
    if (! ((unsigned long )m < (unsigned long )(s->m + (1 << 8)))) {
      goto while_break___0;
    }
  }
  while_break___0: 
  s->a = a;
  s->b = b;
  return;
}
}
void isaac_seed(struct isaac_state *s ) 
{ 
  isaac_word a ;
  unsigned long tmp ;
  isaac_word b ;
  unsigned long tmp___0 ;
  isaac_word c ;
  unsigned long tmp___1 ;
  isaac_word d ;
  unsigned long tmp___2 ;
  isaac_word e ;
  unsigned long tmp___3 ;
  isaac_word f ;
  unsigned long tmp___4 ;
  isaac_word g ;
  unsigned long tmp___5 ;
  isaac_word h ;
  unsigned long tmp___6 ;
  int i ;
  isaac_word tmp___7 ;
  isaac_word tmp___8 ;
  isaac_word tmp___9 ;
  isaac_word tmp___10 ;
  int i___0 ;
  isaac_word tmp___11 ;
  isaac_word tmp___12 ;
  isaac_word tmp___13 ;
  isaac_word tmp___14 ;
  isaac_word tmp___15 ;
  isaac_word tmp___16 ;

  {
  if (1 << 6 == 32) {
    tmp = 325574490UL;
  } else {
    tmp = 7240739780546808700UL;
  }
  a = tmp;
  if (1 << 6 == 32) {
    tmp___0 = 2514026585UL;
  } else {
    tmp___0 = 0xb9f8b322c73ac862UL;
  }
  b = tmp___0;
  if (1 << 6 == 32) {
    tmp___1 = 3273014859UL;
  } else {
    tmp___1 = 0x8c0ea5053d4712a0UL;
  }
  c = tmp___1;
  if (1 << 6 == 32) {
    tmp___2 = 255990488UL;
  } else {
    tmp___2 = 0xb29b2e824a595524UL;
  }
  d = tmp___2;
  if (1 << 6 == 32) {
    tmp___3 = 3643427448UL;
  } else {
    tmp___3 = 0x82f053db8355e0ceUL;
  }
  e = tmp___3;
  if (1 << 6 == 32) {
    tmp___4 = 2769960009UL;
  } else {
    tmp___4 = 5259722845879046933UL;
  }
  f = tmp___4;
  if (1 << 6 == 32) {
    tmp___5 = 3304057371UL;
  } else {
    tmp___5 = 0xae985bf2cbfc89edUL;
  }
  g = tmp___5;
  if (1 << 6 == 32) {
    tmp___6 = 811634969UL;
  } else {
    tmp___6 = 0x98f5704f6c44c0abUL;
  }
  h = tmp___6;
  i = 0;
  while (1) {

    if (! (i < 1 << 8)) {
      goto while_break;
    }
    a += s->m[i];
    b += s->m[i + 1];
    c += s->m[i + 2];
    d += s->m[i + 3];
    e += s->m[i + 4];
    f += s->m[i + 5];
    g += s->m[i + 6];
    h += s->m[i + 7];
    a -= e;
    tmp___7 = just(h);
    f ^= tmp___7 >> 9;
    h += a;
    b -= f;
    g ^= a << 9;
    a += b;
    c -= g;
    tmp___8 = just(b);
    h ^= tmp___8 >> 23;
    b += c;
    d -= h;
    a ^= c << 15;
    c += d;
    e -= a;
    tmp___9 = just(d);
    b ^= tmp___9 >> 14;
    d += e;
    f -= b;
    c ^= e << 20;
    e += f;
    g -= c;
    tmp___10 = just(f);
    d ^= tmp___10 >> 17;
    f += g;
    h -= d;
    e ^= g << 14;
    g += h;
    s->m[i] = a;
    s->m[i + 1] = b;
    s->m[i + 2] = c;
    s->m[i + 3] = d;
    s->m[i + 4] = e;
    s->m[i + 5] = f;
    s->m[i + 6] = g;
    s->m[i + 7] = h;
    i += 8;
  }
  while_break: 
  i___0 = 0;
  while (1) {

    if (! (i___0 < 1 << 8)) {
      goto while_break___0;
    }
    a += s->m[i___0];
    b += s->m[i___0 + 1];
    c += s->m[i___0 + 2];
    d += s->m[i___0 + 3];
    e += s->m[i___0 + 4];
    f += s->m[i___0 + 5];
    g += s->m[i___0 + 6];
    h += s->m[i___0 + 7];
    a -= e;
    tmp___11 = just(h);
    f ^= tmp___11 >> 9;
    h += a;
    b -= f;
    g ^= a << 9;
    a += b;
    c -= g;
    tmp___12 = just(b);
    h ^= tmp___12 >> 23;
    b += c;
    d -= h;
    a ^= c << 15;
    c += d;
    e -= a;
    tmp___13 = just(d);
    b ^= tmp___13 >> 14;
    d += e;
    f -= b;
    c ^= e << 20;
    e += f;
    g -= c;
    tmp___14 = just(f);
    d ^= tmp___14 >> 17;
    f += g;
    h -= d;
    e ^= g << 14;
    g += h;
    s->m[i___0] = a;
    s->m[i___0 + 1] = b;
    s->m[i___0 + 2] = c;
    s->m[i___0 + 3] = d;
    s->m[i___0 + 4] = e;
    s->m[i___0 + 5] = f;
    s->m[i___0 + 6] = g;
    s->m[i___0 + 7] = h;
    i___0 += 8;
  }
  while_break___0: 
  tmp___16 = (isaac_word )0;
  s->c = tmp___16;
  tmp___15 = tmp___16;
  s->b = tmp___15;
  s->a = tmp___15;
  return;
}
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
char const   * const  quoting_style_args[9] ;
enum quoting_style  const  quoting_style_vals[8] ;
int set_char_quoting(struct quoting_options *o , char c , int i ) ;
char *quotearg_char(char const   *arg , char ch ) ;
char *quotearg_char_mem(char const   *arg , size_t argsize , char ch ) ;
struct quoting_options quote_quoting_options ;
__inline static char *xcharalloc(size_t n )  __attribute__((__malloc__, __alloc_size__(1))) ;
__inline static char *xcharalloc(size_t n )  __attribute__((__malloc__, __alloc_size__(1))) ;
__inline static char *xcharalloc(size_t n ) 
{ 
  void *tmp ;
  void *tmp___0 ;
  void *tmp___1 ;

  {
  if (sizeof(char ) == 1UL) {
    tmp = xmalloc(n);
    tmp___1 = tmp;
  } else {
    tmp___0 = xnmalloc(n, sizeof(char ));
    tmp___1 = tmp___0;
  }
  return ((char *)tmp___1);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) iswprint)(wint_t __wc ) ;
char const   * const  quoting_style_args[9]  = 
  {      "literal",      "shell",      "shell-always",      "c", 
        "c-maybe",      "escape",      "locale",      "clocale", 
        (char const   *)0};
enum quoting_style  const  quoting_style_vals[8]  = 
  {      (enum quoting_style  const  )0,      (enum quoting_style  const  )1,      (enum quoting_style  const  )2,      (enum quoting_style  const  )3, 
        (enum quoting_style  const  )4,      (enum quoting_style  const  )5,      (enum quoting_style  const  )6,      (enum quoting_style  const  )7};
static struct quoting_options default_quoting_options  ;
int set_char_quoting(struct quoting_options *o , char c , int i ) 
{ 
  unsigned char uc ;
  unsigned int *p ;
  struct quoting_options *tmp ;
  int shift ;
  int r ;

  {
  uc = (unsigned char )c;
  if (o) {
    tmp = o;
  } else {
    tmp = & default_quoting_options;
  }
  p = tmp->quote_these_too + (unsigned long )uc / (sizeof(int ) * 8UL);
  shift = (int )((unsigned long )uc % (sizeof(int ) * 8UL));
  r = (int )((*p >> shift) & 1U);
  *p ^= (unsigned int )(((i & 1) ^ r) << shift);
  return (r);
}
}
static struct quoting_options quoting_options_from_style(enum quoting_style style ) 
{ 
  struct quoting_options o ;
  unsigned int tmp ;

  {
  o.style = (enum quoting_style )0;
  o.flags = 0;
  o.quote_these_too[0] = 0U;
  tmp = 1U;
  while (1) {

    if (! (! (tmp >= 8U))) {
      goto while_break;
    }
    o.quote_these_too[tmp] = 0U;
    tmp ++;
  }
  while_break: 
  o.left_quote = (char const   *)((void *)0);
  o.right_quote = (char const   *)((void *)0);
  if ((unsigned int )style == 8U) {
    abort();
  }
  o.style = style;
  return (o);
}
}
static char const   *gettext_quote(char const   *msgid , enum quoting_style s ) 
{ 
  char const   *translation ;
  char const   *tmp ;
  char const   *locale_code ;
  char const   *tmp___0 ;
  int tmp___1 ;
  char const   *tmp___2 ;
  int tmp___3 ;
  char const   *tmp___4 ;

  {
  tmp = (char const   *)gettext(msgid);
  translation = tmp;
  if ((unsigned long )translation != (unsigned long )msgid) {
    return (translation);
  }
  locale_code = locale_charset();
  tmp___1 = c_strcasecmp(locale_code, "UTF-8");
  if (tmp___1 == 0) {
    if ((int const   )*(msgid + 0) == 96) {
      tmp___0 = "\342\200\230";
    } else {
      tmp___0 = "\342\200\231";
    }
    return (tmp___0);
  }
  tmp___3 = c_strcasecmp(locale_code, "GB18030");
  if (tmp___3 == 0) {
    if ((int const   )*(msgid + 0) == 96) {
      tmp___2 = "\241\ae";
    } else {
      tmp___2 = "\241\257";
    }
    return (tmp___2);
  }
  if ((unsigned int )s == 7U) {
    tmp___4 = "\"";
  } else {
    tmp___4 = "\'";
  }
  return (tmp___4);
}
}
static size_t quotearg_buffer_restyled(char *buffer , size_t buffersize , char const   *arg ,
                                       size_t argsize , enum quoting_style quoting_style ,
                                       int flags , unsigned int const   *quote_these_too ,
                                       char const   *left_quote , char const   *right_quote ) 
{ 
  size_t i ;
  size_t len ;
  char const   *quote_string ;
  size_t quote_string_len ;
  _Bool backslash_escapes ;
  _Bool unibyte_locale ;
  size_t tmp ;
  _Bool elide_outer_quotes ;
  unsigned char c ;
  unsigned char esc ;
  _Bool is_right_quote ;
  int tmp___0 ;
  int tmp___1 ;
  size_t m ;
  _Bool printable ;
  unsigned short const   **tmp___2 ;
  mbstate_t mbstate ;
  wchar_t w ;
  size_t bytes ;
  size_t tmp___3 ;
  size_t j ;
  int tmp___4 ;
  int tmp___5 ;
  size_t ilim ;
  int tmp___6 ;
  size_t tmp___7 ;

  {
  len = (size_t )0;
  quote_string = (char const   *)0;
  quote_string_len = (size_t )0;
  backslash_escapes = (_Bool)0;
  tmp = __ctype_get_mb_cur_max();
  unibyte_locale = (_Bool )(tmp == 1UL);
  elide_outer_quotes = (_Bool )((flags & 2) != 0);
  if ((unsigned int )quoting_style == 4U) {
    goto case_4;
  }
  if ((unsigned int )quoting_style == 3U) {
    goto case_3;
  }
  if ((unsigned int )quoting_style == 5U) {
    goto case_5;
  }
  if ((unsigned int )quoting_style == 6U) {
    goto case_6;
  }
  if ((unsigned int )quoting_style == 7U) {
    goto case_6;
  }
  if ((unsigned int )quoting_style == 8U) {
    goto case_6;
  }
  if ((unsigned int )quoting_style == 1U) {
    goto case_1;
  }
  if ((unsigned int )quoting_style == 2U) {
    goto case_2;
  }
  if ((unsigned int )quoting_style == 0U) {
    goto case_0;
  }
  goto switch_default;
  case_4: 
  quoting_style = (enum quoting_style )3;
  elide_outer_quotes = (_Bool)1;
  case_3: 
  if (! elide_outer_quotes) {
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char )'\"';
      }
      len ++;
      goto while_break;
    }
    while_break: ;
  }
  backslash_escapes = (_Bool)1;
  quote_string = "\"";
  quote_string_len = (size_t )1;
  goto switch_break;
  case_5: 
  backslash_escapes = (_Bool)1;
  elide_outer_quotes = (_Bool)0;
  goto switch_break;
  case_6: 
  if ((unsigned int )quoting_style != 8U) {
    left_quote = gettext_quote("`", quoting_style);
    right_quote = gettext_quote("\'", quoting_style);
  }
  if (! elide_outer_quotes) {
    quote_string = left_quote;
    while (1) {

      if (! *quote_string) {
        goto while_break___0;
      }
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char )*quote_string;
        }
        len ++;
        goto while_break___1;
      }
      while_break___1: 
      quote_string ++;
    }
    while_break___0: ;
  }
  backslash_escapes = (_Bool)1;
  quote_string = right_quote;
  quote_string_len = strlen(quote_string);
  goto switch_break;
  case_1: 
  quoting_style = (enum quoting_style )2;
  elide_outer_quotes = (_Bool)1;
  case_2: 
  if (! elide_outer_quotes) {
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char )'\'';
      }
      len ++;
      goto while_break___2;
    }
    while_break___2: ;
  }
  quote_string = "\'";
  quote_string_len = (size_t )1;
  goto switch_break;
  case_0: 
  elide_outer_quotes = (_Bool)0;
  goto switch_break;
  switch_default: 
  abort();
  switch_break: 
  i = (size_t )0;
  while (1) {

    if (argsize == 0xffffffffffffffffUL) {
      tmp___6 = (int const   )*(arg + i) == 0;
    } else {
      tmp___6 = i == argsize;
    }
    if (tmp___6) {
      goto while_break___3;
    }
    is_right_quote = (_Bool)0;
    if (backslash_escapes) {
      if (quote_string_len) {
        if (i + quote_string_len <= argsize) {
          tmp___0 = memcmp((void const   *)(arg + i), (void const   *)quote_string,
                           quote_string_len);
          if (tmp___0 == 0) {
            if (elide_outer_quotes) {
              goto force_outer_quoting_style;
            }
            is_right_quote = (_Bool)1;
          }
        }
      }
    }
    c = (unsigned char )*(arg + i);
    if ((int )c == 0) {
      goto case_0___0;
    }
    if ((int )c == 63) {
      goto case_63;
    }
    if ((int )c == 7) {
      goto case_7___0;
    }
    if ((int )c == 8) {
      goto case_8___0;
    }
    if ((int )c == 12) {
      goto case_12;
    }
    if ((int )c == 10) {
      goto case_10;
    }
    if ((int )c == 13) {
      goto case_13;
    }
    if ((int )c == 9) {
      goto case_9;
    }
    if ((int )c == 11) {
      goto case_11;
    }
    if ((int )c == 92) {
      goto case_92;
    }
    if ((int )c == 123) {
      goto case_123;
    }
    if ((int )c == 125) {
      goto case_123;
    }
    if ((int )c == 35) {
      goto case_35;
    }
    if ((int )c == 126) {
      goto case_35;
    }
    if ((int )c == 32) {
      goto case_32;
    }
    if ((int )c == 33) {
      goto case_32;
    }
    if ((int )c == 34) {
      goto case_32;
    }
    if ((int )c == 36) {
      goto case_32;
    }
    if ((int )c == 38) {
      goto case_32;
    }
    if ((int )c == 40) {
      goto case_32;
    }
    if ((int )c == 41) {
      goto case_32;
    }
    if ((int )c == 42) {
      goto case_32;
    }
    if ((int )c == 59) {
      goto case_32;
    }
    if ((int )c == 60) {
      goto case_32;
    }
    if ((int )c == 61) {
      goto case_32;
    }
    if ((int )c == 62) {
      goto case_32;
    }
    if ((int )c == 91) {
      goto case_32;
    }
    if ((int )c == 94) {
      goto case_32;
    }
    if ((int )c == 96) {
      goto case_32;
    }
    if ((int )c == 124) {
      goto case_32;
    }
    if ((int )c == 39) {
      goto case_39___0;
    }
    if ((int )c == 37) {
      goto case_37;
    }
    if ((int )c == 43) {
      goto case_37;
    }
    if ((int )c == 44) {
      goto case_37;
    }
    if ((int )c == 45) {
      goto case_37;
    }
    if ((int )c == 46) {
      goto case_37;
    }
    if ((int )c == 47) {
      goto case_37;
    }
    if ((int )c == 48) {
      goto case_37;
    }
    if ((int )c == 49) {
      goto case_37;
    }
    if ((int )c == 50) {
      goto case_37;
    }
    if ((int )c == 51) {
      goto case_37;
    }
    if ((int )c == 52) {
      goto case_37;
    }
    if ((int )c == 53) {
      goto case_37;
    }
    if ((int )c == 54) {
      goto case_37;
    }
    if ((int )c == 55) {
      goto case_37;
    }
    if ((int )c == 56) {
      goto case_37;
    }
    if ((int )c == 57) {
      goto case_37;
    }
    if ((int )c == 58) {
      goto case_37;
    }
    if ((int )c == 65) {
      goto case_37;
    }
    if ((int )c == 66) {
      goto case_37;
    }
    if ((int )c == 67) {
      goto case_37;
    }
    if ((int )c == 68) {
      goto case_37;
    }
    if ((int )c == 69) {
      goto case_37;
    }
    if ((int )c == 70) {
      goto case_37;
    }
    if ((int )c == 71) {
      goto case_37;
    }
    if ((int )c == 72) {
      goto case_37;
    }
    if ((int )c == 73) {
      goto case_37;
    }
    if ((int )c == 74) {
      goto case_37;
    }
    if ((int )c == 75) {
      goto case_37;
    }
    if ((int )c == 76) {
      goto case_37;
    }
    if ((int )c == 77) {
      goto case_37;
    }
    if ((int )c == 78) {
      goto case_37;
    }
    if ((int )c == 79) {
      goto case_37;
    }
    if ((int )c == 80) {
      goto case_37;
    }
    if ((int )c == 81) {
      goto case_37;
    }
    if ((int )c == 82) {
      goto case_37;
    }
    if ((int )c == 83) {
      goto case_37;
    }
    if ((int )c == 84) {
      goto case_37;
    }
    if ((int )c == 85) {
      goto case_37;
    }
    if ((int )c == 86) {
      goto case_37;
    }
    if ((int )c == 87) {
      goto case_37;
    }
    if ((int )c == 88) {
      goto case_37;
    }
    if ((int )c == 89) {
      goto case_37;
    }
    if ((int )c == 90) {
      goto case_37;
    }
    if ((int )c == 93) {
      goto case_37;
    }
    if ((int )c == 95) {
      goto case_37;
    }
    if ((int )c == 97) {
      goto case_37;
    }
    if ((int )c == 98) {
      goto case_37;
    }
    if ((int )c == 99) {
      goto case_37;
    }
    if ((int )c == 100) {
      goto case_37;
    }
    if ((int )c == 101) {
      goto case_37;
    }
    if ((int )c == 102) {
      goto case_37;
    }
    if ((int )c == 103) {
      goto case_37;
    }
    if ((int )c == 104) {
      goto case_37;
    }
    if ((int )c == 105) {
      goto case_37;
    }
    if ((int )c == 106) {
      goto case_37;
    }
    if ((int )c == 107) {
      goto case_37;
    }
    if ((int )c == 108) {
      goto case_37;
    }
    if ((int )c == 109) {
      goto case_37;
    }
    if ((int )c == 110) {
      goto case_37;
    }
    if ((int )c == 111) {
      goto case_37;
    }
    if ((int )c == 112) {
      goto case_37;
    }
    if ((int )c == 113) {
      goto case_37;
    }
    if ((int )c == 114) {
      goto case_37;
    }
    if ((int )c == 115) {
      goto case_37;
    }
    if ((int )c == 116) {
      goto case_37;
    }
    if ((int )c == 117) {
      goto case_37;
    }
    if ((int )c == 118) {
      goto case_37;
    }
    if ((int )c == 119) {
      goto case_37;
    }
    if ((int )c == 120) {
      goto case_37;
    }
    if ((int )c == 121) {
      goto case_37;
    }
    if ((int )c == 122) {
      goto case_37;
    }
    goto switch_default___2;
    case_0___0: 
    if (backslash_escapes) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char )'\\';
        }
        len ++;
        goto while_break___4;
      }
      while_break___4: ;
      if (i + 1UL < argsize) {
        if (48 <= (int )*(arg + (i + 1UL))) {
          if ((int const   )*(arg + (i + 1UL)) <= 57) {
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char )'0';
              }
              len ++;
              goto while_break___5;
            }
            while_break___5: ;
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char )'0';
              }
              len ++;
              goto while_break___6;
            }
            while_break___6: ;
          }
        }
      }
      c = (unsigned char )'0';
    } else
    if (flags & 1) {
      goto __Cont;
    }
    goto switch_break___0;
    case_63: 
    if ((unsigned int )quoting_style == 2U) {
      goto case_2___0;
    }
    if ((unsigned int )quoting_style == 3U) {
      goto case_3___0;
    }
    goto switch_default___1;
    case_2___0: 
    if (elide_outer_quotes) {
      goto force_outer_quoting_style;
    }
    goto switch_break___1;
    case_3___0: 
    if (flags & 4) {
      if (i + 2UL < argsize) {
        if ((int const   )*(arg + (i + 1UL)) == 63) {
          if ((int const   )*(arg + (i + 2UL)) == 33) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 39) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 40) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 41) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 45) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 47) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 60) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 61) {
            goto case_33;
          }
          if ((int const   )*(arg + (i + 2UL)) == 62) {
            goto case_33;
          }
          goto switch_default___0;
          case_33: 
          if (elide_outer_quotes) {
            goto force_outer_quoting_style;
          }
          c = (unsigned char )*(arg + (i + 2UL));
          i += 2UL;
          while (1) {

            if (len < buffersize) {
              *(buffer + len) = (char )'?';
            }
            len ++;
            goto while_break___7;
          }
          while_break___7: ;
          while (1) {

            if (len < buffersize) {
              *(buffer + len) = (char )'\"';
            }
            len ++;
            goto while_break___8;
          }
          while_break___8: ;
          while (1) {

            if (len < buffersize) {
              *(buffer + len) = (char )'\"';
            }
            len ++;
            goto while_break___9;
          }
          while_break___9: ;
          while (1) {

            if (len < buffersize) {
              *(buffer + len) = (char )'?';
            }
            len ++;
            goto while_break___10;
          }
          while_break___10: ;
          goto switch_break___2;
          switch_default___0: 
          goto switch_break___2;
          switch_break___2: ;
        }
      }
    }
    goto switch_break___1;
    switch_default___1: 
    goto switch_break___1;
    switch_break___1: ;
    goto switch_break___0;
    case_7___0: 
    esc = (unsigned char )'a';
    goto c_escape;
    case_8___0: 
    esc = (unsigned char )'b';
    goto c_escape;
    case_12: 
    esc = (unsigned char )'f';
    goto c_escape;
    case_10: 
    esc = (unsigned char )'n';
    goto c_and_shell_escape;
    case_13: 
    esc = (unsigned char )'r';
    goto c_and_shell_escape;
    case_9: 
    esc = (unsigned char )'t';
    goto c_and_shell_escape;
    case_11: 
    esc = (unsigned char )'v';
    goto c_escape;
    case_92: 
    esc = c;
    if (backslash_escapes) {
      if (elide_outer_quotes) {
        if (quote_string_len) {
          goto store_c;
        }
      }
    }
    c_and_shell_escape: 
    if ((unsigned int )quoting_style == 2U) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
    }
    c_escape: 
    if (backslash_escapes) {
      c = esc;
      goto store_escape;
    }
    goto switch_break___0;
    case_123: 
    if (argsize == 0xffffffffffffffffUL) {
      tmp___1 = (int const   )*(arg + 1) == 0;
    } else {
      tmp___1 = argsize == 1UL;
    }
    if (! tmp___1) {
      goto switch_break___0;
    }
    case_35: 
    if (i != 0UL) {
      goto switch_break___0;
    }
    case_32: 
    if ((unsigned int )quoting_style == 2U) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
    }
    goto switch_break___0;
    case_39___0: 
    if ((unsigned int )quoting_style == 2U) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char )'\'';
        }
        len ++;
        goto while_break___11;
      }
      while_break___11: ;
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char )'\\';
        }
        len ++;
        goto while_break___12;
      }
      while_break___12: ;
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char )'\'';
        }
        len ++;
        goto while_break___13;
      }
      while_break___13: ;
    }
    goto switch_break___0;
    case_37: 
    goto switch_break___0;
    switch_default___2: 
    if (unibyte_locale) {
      m = (size_t )1;
      tmp___2 = __ctype_b_loc();
      printable = (_Bool )(((int const   )*(*tmp___2 + (int )c) & 16384) != 0);
    } else {
      memset((void *)(& mbstate), 0, sizeof(mbstate));
      m = (size_t )0;
      printable = (_Bool)1;
      if (argsize == 0xffffffffffffffffUL) {
        argsize = strlen(arg);
      }
      while (1) {
        tmp___3 = mbrtowc(& w, arg + (i + m), argsize - (i + m), & mbstate);
        bytes = tmp___3;
        if (bytes == 0UL) {
          goto while_break___14;
        } else
        if (bytes == 0xffffffffffffffffUL) {
          printable = (_Bool)0;
          goto while_break___14;
        } else
        if (bytes == 0xfffffffffffffffeUL) {
          printable = (_Bool)0;
          while (1) {

            if (i + m < argsize) {
              if (! *(arg + (i + m))) {
                goto while_break___15;
              }
            } else {
              goto while_break___15;
            }
            m ++;
          }
          while_break___15: ;
          goto while_break___14;
        } else {
          if (elide_outer_quotes) {
            if ((unsigned int )quoting_style == 2U) {
              j = (size_t )1;
              while (1) {

                if (! (j < bytes)) {
                  goto while_break___16;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 91) {
                  goto case_91___0;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 92) {
                  goto case_91___0;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 94) {
                  goto case_91___0;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 96) {
                  goto case_91___0;
                }
                if ((int const   )*(arg + ((i + m) + j)) == 124) {
                  goto case_91___0;
                }
                goto switch_default___3;
                case_91___0: 
                goto force_outer_quoting_style;
                switch_default___3: 
                goto switch_break___3;
                switch_break___3: 
                j ++;
              }
              while_break___16: ;
            }
          }
          tmp___4 = iswprint((wint_t )w);
          if (! tmp___4) {
            printable = (_Bool)0;
          }
          m += bytes;
        }
        tmp___5 = mbsinit((mbstate_t const   *)(& mbstate));
        if (tmp___5) {
          goto while_break___14;
        }
      }
      while_break___14: ;
    }
    if (1UL < m) {
      goto _L___0;
    } else
    if (backslash_escapes) {
      if (! printable) {
        _L___0: 
        ilim = i + m;
        while (1) {

          if (backslash_escapes) {
            if (! printable) {
              if (elide_outer_quotes) {
                goto force_outer_quoting_style;
              }
              while (1) {

                if (len < buffersize) {
                  *(buffer + len) = (char )'\\';
                }
                len ++;
                goto while_break___18;
              }
              while_break___18: ;
              while (1) {

                if (len < buffersize) {
                  *(buffer + len) = (char )(48 + ((int )c >> 6));
                }
                len ++;
                goto while_break___19;
              }
              while_break___19: ;
              while (1) {

                if (len < buffersize) {
                  *(buffer + len) = (char )(48 + (((int )c >> 3) & 7));
                }
                len ++;
                goto while_break___20;
              }
              while_break___20: 
              c = (unsigned char )(48 + ((int )c & 7));
            } else {
              goto _L;
            }
          } else
          _L: 
          if (is_right_quote) {
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char )'\\';
              }
              len ++;
              goto while_break___21;
            }
            while_break___21: 
            is_right_quote = (_Bool)0;
          }
          if (ilim <= i + 1UL) {
            goto while_break___17;
          }
          while (1) {

            if (len < buffersize) {
              *(buffer + len) = (char )c;
            }
            len ++;
            goto while_break___22;
          }
          while_break___22: 
          i ++;
          c = (unsigned char )*(arg + i);
        }
        while_break___17: ;
        goto store_c;
      }
    }
    switch_break___0: ;
    if (backslash_escapes) {
      goto _L___3;
    } else
    if (elide_outer_quotes) {
      _L___3: 
      if (quote_these_too) {
        if (! (*(quote_these_too + (unsigned long )c / (sizeof(int ) * 8UL)) & (unsigned int const   )(1 << (unsigned long )c % (sizeof(int ) * 8UL)))) {
          goto _L___2;
        }
      } else {
        goto _L___2;
      }
    } else
    _L___2: 
    if (! is_right_quote) {
      goto store_c;
    }
    store_escape: 
    if (elide_outer_quotes) {
      goto force_outer_quoting_style;
    }
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char )'\\';
      }
      len ++;
      goto while_break___23;
    }
    while_break___23: ;
    store_c: 
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char )c;
      }
      len ++;
      goto while_break___24;
    }
    while_break___24: ;
    __Cont: 
    i ++;
  }
  while_break___3: ;
  if (len == 0UL) {
    if ((unsigned int )quoting_style == 2U) {
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
    }
  }
  if (quote_string) {
    if (! elide_outer_quotes) {
      while (1) {

        if (! *quote_string) {
          goto while_break___25;
        }
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char )*quote_string;
          }
          len ++;
          goto while_break___26;
        }
        while_break___26: 
        quote_string ++;
      }
      while_break___25: ;
    }
  }
  if (len < buffersize) {
    *(buffer + len) = (char )'\000';
  }
  return (len);
  force_outer_quoting_style: 
  tmp___7 = quotearg_buffer_restyled(buffer, buffersize, arg, argsize, quoting_style,
                                     flags & -3, (unsigned int const   *)((void *)0),
                                     left_quote, right_quote);
  return (tmp___7);
}
}
static char slot0[256]  ;
static unsigned int nslots  =    1U;
static struct slotvec slotvec0  =    {sizeof(slot0), slot0};
static struct slotvec *slotvec  =    & slotvec0;
static char *quotearg_n_options(int n , char const   *arg , size_t argsize , struct quoting_options  const  *options ) 
{ 
  int e ;
  int *tmp ;
  unsigned int n0 ;
  struct slotvec *sv ;
  size_t n1 ;
  _Bool preallocated ;
  int tmp___0 ;
  struct slotvec *tmp___1 ;
  size_t size ;
  char *val ;
  int flags ;
  size_t qsize ;
  size_t tmp___2 ;
  int *tmp___3 ;

  {
  tmp = __errno_location();
  e = *tmp;
  n0 = (unsigned int )n;
  sv = slotvec;
  if (n < 0) {
    abort();
  }
  if (nslots <= n0) {
    n1 = (size_t )(n0 + 1U);
    preallocated = (_Bool )((unsigned long )sv == (unsigned long )(& slotvec0));
    if (sizeof(ptrdiff_t ) <= sizeof(size_t )) {
      tmp___0 = -1;
    } else {
      tmp___0 = -2;
    }
    if ((size_t )tmp___0 / sizeof(*sv) < n1) {
      xalloc_die();
    }
    if (preallocated) {
      tmp___1 = (struct slotvec *)((void *)0);
    } else {
      tmp___1 = sv;
    }
    sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
    slotvec = sv;
    if (preallocated) {
      *sv = slotvec0;
    }
    memset((void *)(sv + nslots), 0, (n1 - (size_t )nslots) * sizeof(*sv));
    nslots = (unsigned int )n1;
  }
  size = (sv + n)->size;
  val = (sv + n)->val;
  flags = (int )(options->flags | 1);
  tmp___2 = quotearg_buffer_restyled(val, size, arg, argsize, (enum quoting_style )options->style,
                                     flags, (unsigned int const   *)(options->quote_these_too),
                                     (char const   *)options->left_quote, (char const   *)options->right_quote);
  qsize = tmp___2;
  if (size <= qsize) {
    size = qsize + 1UL;
    (sv + n)->size = size;
    if ((unsigned long )val != (unsigned long )(slot0)) {
      free((void *)val);
    }
    val = xcharalloc(size);
    (sv + n)->val = val;
    quotearg_buffer_restyled(val, size, arg, argsize, (enum quoting_style )options->style,
                             flags, (unsigned int const   *)(options->quote_these_too),
                             (char const   *)options->left_quote, (char const   *)options->right_quote);
  }
  tmp___3 = __errno_location();
  *tmp___3 = e;
  return (val);
}
}
char *quotearg_n_style(int n , enum quoting_style s , char const   *arg ) 
{ 
  struct quoting_options o ;
  struct quoting_options tmp ;
  char *tmp___0 ;

  {
  tmp = quoting_options_from_style(s);
  o = tmp;
  tmp___0 = quotearg_n_options(n, arg, (size_t )-1, (struct quoting_options  const  *)(& o));
  return (tmp___0);
}
}
char *quotearg_n_style_mem(int n , enum quoting_style s , char const   *arg , size_t argsize ) 
{ 
  struct quoting_options o ;
  struct quoting_options tmp ;
  char *tmp___0 ;

  {
  tmp = quoting_options_from_style(s);
  o = tmp;
  tmp___0 = quotearg_n_options(n, arg, argsize, (struct quoting_options  const  *)(& o));
  return (tmp___0);
}
}
char *quotearg_char_mem(char const   *arg , size_t argsize , char ch ) 
{ 
  struct quoting_options options ;
  char *tmp ;

  {
  options = default_quoting_options;
  set_char_quoting(& options, ch, 1);
  tmp = quotearg_n_options(0, arg, argsize, (struct quoting_options  const  *)(& options));
  return (tmp);
}
}
char *quotearg_char(char const   *arg , char ch ) 
{ 
  char *tmp ;

  {
  tmp = quotearg_char_mem(arg, (size_t )-1, ch);
  return (tmp);
}
}
char *quotearg_colon(char const   *arg ) 
{ 
  char *tmp ;

  {
  tmp = quotearg_char(arg, (char )':');
  return (tmp);
}
}
struct quoting_options quote_quoting_options  =    {(enum quoting_style )6, 0, {0U}, (char const   *)((void *)0), (char const   *)((void *)0)};
char const   *quote_n(int n ,
                      char const   *name ) 
{ 
  char const   *tmp ;

  {
  tmp = (char const   *)quotearg_n_options(n, name, (size_t )-1, (struct quoting_options  const  *)(& quote_quoting_options));
  return (tmp);
}
}
char const   *quote(char const   *name ) 
{ 
  char const   *tmp ;

  {
  tmp = quote_n(0, name);
  return (tmp);
}
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
__inline static void mbuiter_multi_next(struct mbuiter_multi *iter ) 
{ 
  int tmp ;
  size_t tmp___0 ;
  size_t tmp___1 ;
  int tmp___2 ;
  _Bool tmp___3 ;

  {
  if (iter->next_done) {
    return;
  }
  if (iter->in_shift) {
    goto with_shift;
  }
  tmp___3 = is_basic((char )*(iter->cur.ptr));
  if (tmp___3) {
    iter->cur.bytes = (size_t )1;
    iter->cur.wc = (wchar_t )*(iter->cur.ptr);
    iter->cur.wc_valid = (_Bool)1;
  } else {
    tmp = mbsinit((mbstate_t const   *)(& iter->state));
    if (! tmp) {
      __assert_fail("mbsinit (&iter->state)", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/mbuiter.h",
                    142U, "mbuiter_multi_next");
    }
    iter->in_shift = (_Bool)1;
    with_shift: 
    tmp___0 = __ctype_get_mb_cur_max();
    tmp___1 = strnlen1(iter->cur.ptr, tmp___0);
    iter->cur.bytes = mbrtowc(& iter->cur.wc, iter->cur.ptr, tmp___1, & iter->state);
    if (iter->cur.bytes == 0xffffffffffffffffUL) {
      iter->cur.bytes = (size_t )1;
      iter->cur.wc_valid = (_Bool)0;
    } else
    if (iter->cur.bytes == 0xfffffffffffffffeUL) {
      iter->cur.bytes = strlen(iter->cur.ptr);
      iter->cur.wc_valid = (_Bool)0;
    } else {
      if (iter->cur.bytes == 0UL) {
        iter->cur.bytes = (size_t )1;
        if (! ((int const   )*(iter->cur.ptr) == 0)) {
          __assert_fail("*iter->cur.ptr == \'\\0\'", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/mbuiter.h",
                        170U, "mbuiter_multi_next");
        }
        if (! (iter->cur.wc == 0)) {
          __assert_fail("iter->cur.wc == 0", "/home/khheo/project/program-reduce/benchmark/coreutils-8.16/lib/mbuiter.h",
                        171U, "mbuiter_multi_next");
        }
      }
      iter->cur.wc_valid = (_Bool)1;
      tmp___2 = mbsinit((mbstate_t const   *)(& iter->state));
      if (tmp___2) {
        iter->in_shift = (_Bool)0;
      }
    }
  }
  iter->next_done = (_Bool)1;
  return;
}
}
char const   *program_name ;
void set_program_name(char const   *argv0 ) ;
extern char *program_invocation_name ;
extern char *program_invocation_short_name ;
extern int fputs(char const   * __restrict  __s , FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1), __leaf__)) strrchr)(char const   *__s ,
                                                                                                int __c )  __attribute__((__pure__)) ;
char const   *program_name  =    (char const   *)((void *)0);
void set_program_name(char const   *argv0 ) 
{ 
  char const   *slash ;
  char const   *base ;
  int tmp ;
  int tmp___0 ;

  {
  if ((unsigned long )argv0 == (unsigned long )((void *)0)) {
    fputs("A NULL argv[0] was passed through an exec system call.\n", stderr);
    abort();
  }
  slash = (char const   *)strrchr(argv0, '/');
  if ((unsigned long )slash != (unsigned long )((void *)0)) {
    base = slash + 1;
  } else {
    base = argv0;
  }
  if (base - argv0 >= 7L) {
    tmp___0 = strncmp(base - 7, "/.libs/", (size_t )7);
    if (tmp___0 == 0) {
      argv0 = base;
      tmp = strncmp(base, "lt-", (size_t )3);
      if (tmp == 0) {
        argv0 = base + 3;
        program_invocation_short_name = (char *)argv0;
      }
    }
  }
  program_name = argv0;
  program_invocation_name = (char *)argv0;
  return;
}
}
int posix2_version(void) ;
int posix2_version(void) 
{ 
  long v ;
  char const   *s ;
  char const   *tmp ;
  char *e ;
  long i ;
  long tmp___0 ;
  long tmp___1 ;
  long tmp___2 ;

  {
  v = 200809L;
  tmp = (char const   *)getenv("_POSIX2_VERSION");
  s = tmp;
  if (s) {
    if (*s) {
      tmp___0 = strtol(s, & e, 10);
      i = tmp___0;
      if (! *e) {
        v = i;
      }
    }
  }
  if (v < (-0x7FFFFFFF-1)) {
    tmp___2 = (-0x7FFFFFFF-1);
  } else {
    if (v < 2147483647L) {
      tmp___1 = v;
    } else {
      tmp___1 = 2147483647L;
    }
    tmp___2 = tmp___1;
  }
  return ((int )tmp___2);
}
}
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2), __leaf__)) stpcpy)(char * __restrict  __dest ,
                                                                                                 char const   * __restrict  __src ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) pipe)(int *__pipedes ) ;
double physmem_total(void) ;
double physmem_available(void) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) sysconf)(int __name ) ;
double physmem_total(void) 
{ 
  double pages ;
  double tmp ;
  double pagesize ;
  double tmp___0 ;

  {
  tmp = (double )sysconf(85);
  pages = tmp;
  tmp___0 = (double )sysconf(30);
  pagesize = tmp___0;
  if ((double )0 <= pages) {
    if ((double )0 <= pagesize) {
      return (pages * pagesize);
    }
  }
  return ((double )67108864);
}
}
double physmem_available(void) 
{ 
  double pages ;
  double tmp ;
  double pagesize ;
  double tmp___0 ;
  double tmp___1 ;

  {
  tmp = (double )sysconf(86);
  pages = tmp;
  tmp___0 = (double )sysconf(30);
  pagesize = tmp___0;
  if ((double )0 <= pages) {
    if ((double )0 <= pagesize) {
      return (pages * pagesize);
    }
  }
  tmp___1 = physmem_total();
  return (tmp___1 / (double )4);
}
}
int dup_safer(int fd ) ;
#pragma GCC diagnostic ignored "-Wtype-limits"
unsigned long num_processors(enum nproc_query query ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __sched_cpucount)(size_t __setsize ,
                                                                                       cpu_set_t const   *__setp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) sched_getaffinity)(__pid_t __pid ,
                                                                                        size_t __cpusetsize ,
                                                                                        cpu_set_t *__cpuset ) ;
static unsigned long num_processors_via_affinity_mask(void) 
{ 
  cpu_set_t set ;
  unsigned long count ;
  int tmp ;

  {
  tmp = sched_getaffinity(0, sizeof(set), & set);
  if (tmp == 0) {
    count = (unsigned long )__sched_cpucount(sizeof(cpu_set_t ), (cpu_set_t const   *)(& set));
    if (count > 0UL) {
      return (count);
    }
  }
  return (0UL);
}
}
unsigned long num_processors(enum nproc_query query ) 
{ 
  char const   *envvalue ;
  char const   *tmp ;
  _Bool tmp___0 ;
  char *endptr ;
  unsigned long value ;
  unsigned long tmp___1 ;
  _Bool tmp___2 ;
  unsigned long tmp___3 ;
  _Bool tmp___4 ;
  unsigned long nprocs___0 ;
  unsigned long tmp___5 ;
  long nprocs___1 ;
  long tmp___6 ;
  long nprocs___2 ;
  long tmp___7 ;
  unsigned long nprocs_current ;
  unsigned long tmp___8 ;

  {
  if ((unsigned int )query == 2U) {
    tmp = (char const   *)getenv("OMP_NUM_THREADS");
    envvalue = tmp;
    if ((unsigned long )envvalue != (unsigned long )((void *)0)) {
      while (1) {

        if ((int const   )*envvalue != 0) {
          tmp___0 = c_isspace((int )*envvalue);
          if (! tmp___0) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        envvalue ++;
      }
      while_break: 
      tmp___4 = c_isdigit((int )*envvalue);
      if (tmp___4) {
        endptr = (char *)((void *)0);
        tmp___1 = strtoul(envvalue, & endptr, 10);
        value = tmp___1;
        if ((unsigned long )endptr != (unsigned long )((void *)0)) {
          while (1) {

            if ((int )*endptr != 0) {
              tmp___2 = c_isspace((int )*endptr);
              if (! tmp___2) {
                goto while_break___0;
              }
            } else {
              goto while_break___0;
            }
            endptr ++;
          }
          while_break___0: ;
          if ((int )*endptr == 0) {
            if (value > 0UL) {
              tmp___3 = value;
            } else {
              tmp___3 = 1UL;
            }
            return (tmp___3);
          }
        }
      }
    }
    query = (enum nproc_query )1;
  }
  if ((unsigned int )query == 1U) {
    tmp___5 = num_processors_via_affinity_mask();
    nprocs___0 = tmp___5;
    if (nprocs___0 > 0UL) {
      return (nprocs___0);
    }
    tmp___6 = sysconf(84);
    nprocs___1 = tmp___6;
    if (nprocs___1 > 0L) {
      return ((unsigned long )nprocs___1);
    }
  } else {
    tmp___7 = sysconf(83);
    nprocs___2 = tmp___7;
    if (nprocs___2 == 1L) {
      tmp___8 = num_processors_via_affinity_mask();
      nprocs_current = tmp___8;
      if (nprocs_current > 0UL) {
        nprocs___2 = (long )nprocs_current;
      }
    }
    if (nprocs___2 > 0L) {
      return ((unsigned long )nprocs___2);
    }
  }
  return (1UL);
}
}
extern int nanosleep(struct timespec  const  *__requested_time , struct timespec *__remaining ) ;
int ( __attribute__((__nonnull__(1))) rpl_nanosleep)(struct timespec  const  *requested_delay ,
                                                     struct timespec *remaining_delay ) 
{ 
  int *tmp ;
  time_t limit ;
  time_t seconds ;
  struct timespec intermediate ;
  int result ;
  int tmp___0 ;

  {
  if (requested_delay->tv_nsec < 0L) {
    tmp = __errno_location();
    *tmp = 22;
    return (-1);
  } else
  if (1000000000L <= (long )requested_delay->tv_nsec) {
    tmp = __errno_location();
    *tmp = 22;
    return (-1);
  }
  limit = (time_t )2073600;
  seconds = (time_t )requested_delay->tv_sec;
  intermediate.tv_nsec = (__syscall_slong_t )requested_delay->tv_nsec;
  while (1) {

    if (! (limit < seconds)) {
      goto while_break;
    }
    intermediate.tv_sec = limit;
    result = nanosleep((struct timespec  const  *)(& intermediate), remaining_delay);
    seconds -= limit;
    if (result) {
      if (remaining_delay) {
        remaining_delay->tv_sec += seconds;
      }
      return (result);
    }
    intermediate.tv_nsec = (__syscall_slong_t )0;
  }
  while_break: 
  intermediate.tv_sec = seconds;
  tmp___0 = nanosleep((struct timespec  const  *)(& intermediate), remaining_delay);
  return (tmp___0);
}
}
int mkstemp_safer(char *templ ) ;
extern int ( __attribute__((__nonnull__(1))) mkstemp)(char *__template ) ;
int mkstemp_safer(char *templ ) 
{ 
  int tmp ;
  int tmp___0 ;

  {
  tmp = mkstemp(templ);
  tmp___0 = fd_safer(tmp);
  return (tmp___0);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) strcoll)(char const   *__s1 ,
                                                                                                char const   *__s2 )  __attribute__((__pure__)) ;
__inline static int strcoll_loop(char const   *s1 , size_t s1size , char const   *s2 ,
                                 size_t s2size ) 
{ 
  int diff ;
  size_t size1 ;
  size_t tmp ;
  size_t size2 ;
  size_t tmp___0 ;
  int *tmp___1 ;
  int *tmp___2 ;
  int tmp___3 ;

  {
  while (1) {
    tmp___1 = __errno_location();
    *tmp___1 = 0;
    diff = strcoll(s1, s2);
    if (diff) {
      tmp___3 = 1;
    } else {
      tmp___2 = __errno_location();
      if (*tmp___2) {
        tmp___3 = 1;
      } else {
        tmp___3 = 0;
      }
    }
    if (tmp___3) {
      goto while_break;
    }
    tmp = strlen(s1);
    size1 = tmp + 1UL;
    tmp___0 = strlen(s2);
    size2 = tmp___0 + 1UL;
    s1 += size1;
    s2 += size2;
    s1size -= size1;
    s2size -= size2;
    if (s1size == 0UL) {
      return (- (s2size != 0UL));
    }
    if (s2size == 0UL) {
      return (1);
    }
  }
  while_break: ;
  return (diff);
}
}
int memcoll0(char const   *s1 , size_t s1size , char const   *s2 , size_t s2size ) 
{ 
  int *tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  if (s1size == s2size) {
    tmp___1 = memcmp((void const   *)s1, (void const   *)s2, s1size);
    if (tmp___1 == 0) {
      tmp = __errno_location();
      *tmp = 0;
      return (0);
    } else {
      tmp___0 = strcoll_loop(s1, s1size, s2, s2size);
      return (tmp___0);
    }
  } else {
    tmp___0 = strcoll_loop(s1, s1size, s2, s2size);
    return (tmp___0);
  }
}
}
 __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) md5_init_ctx)(struct md5_ctx *ctx ) ;
 __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) md5_process_block)(void const   *buffer ,
                                                                                  size_t len ,
                                                                                  struct md5_ctx *ctx ) ;
 __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) md5_process_bytes)(void const   *buffer ,
                                                                                  size_t len ,
                                                                                  struct md5_ctx *ctx ) ;
 __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) md5_finish_ctx)(struct md5_ctx *ctx ,
                                                                                void *resbuf ) ;
 __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) md5_read_ctx)(struct md5_ctx  const  *ctx ,
                                                                              void *resbuf ) ;
static unsigned char const   fillbuf___2[64]  = {      (unsigned char const   )128,      (unsigned char const   )0};
 __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) md5_init_ctx)(struct md5_ctx *ctx ) ;
void ( __attribute__((__leaf__)) md5_init_ctx)(struct md5_ctx *ctx ) 
{ 
  uint32_t tmp ;

  {
  ctx->A = (uint32_t )1732584193;
  ctx->B = 4023233417U;
  ctx->C = 2562383102U;
  ctx->D = (uint32_t )271733878;
  tmp = (uint32_t )0;
  ctx->total[1] = tmp;
  ctx->total[0] = tmp;
  ctx->buflen = (uint32_t )0;
  return;
}
}
 __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) md5_read_ctx)(struct md5_ctx  const  *ctx ,
                                                                              void *resbuf ) ;
void *( __attribute__((__leaf__)) md5_read_ctx)(struct md5_ctx  const  *ctx , void *resbuf ) 
{ 
  char *r ;

  {
  r = (char *)resbuf;
  set_uint32(r + 0UL, (uint32_t )ctx->A);
  set_uint32(r + sizeof(ctx->B), (uint32_t )ctx->B);
  set_uint32(r + 2UL * sizeof(ctx->C), (uint32_t )ctx->C);
  set_uint32(r + 3UL * sizeof(ctx->D), (uint32_t )ctx->D);
  return (resbuf);
}
}
 __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) md5_finish_ctx)(struct md5_ctx *ctx ,
                                                                                void *resbuf ) ;
void *( __attribute__((__leaf__)) md5_finish_ctx)(struct md5_ctx *ctx , void *resbuf ) 
{ 
  uint32_t bytes ;
  size_t size ;
  int tmp ;
  void *tmp___0 ;

  {
  bytes = ctx->buflen;
  if (bytes < 56U) {
    tmp = 16;
  } else {
    tmp = 32;
  }
  size = (size_t )tmp;
  ctx->total[0] += bytes;
  if (ctx->total[0] < bytes) {
    (ctx->total[1]) ++;
  }
  ctx->buffer[size - 2UL] = ctx->total[0] << 3;
  ctx->buffer[size - 1UL] = (ctx->total[1] << 3) | (ctx->total[0] >> 29);
  memcpy((void *)((char *)(ctx->buffer) + bytes), (void const   *)(fillbuf___2), (size - 2UL) * 4UL - (size_t )bytes);
  md5_process_block((void const   *)(ctx->buffer), size * 4UL, ctx);
  tmp___0 = md5_read_ctx((struct md5_ctx  const  *)ctx, resbuf);
  return (tmp___0);
}
}
 __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) md5_process_bytes)(void const   *buffer ,
                                                                                  size_t len ,
                                                                                  struct md5_ctx *ctx ) ;
void ( __attribute__((__leaf__)) md5_process_bytes)(void const   *buffer , size_t len ,
                                                    struct md5_ctx *ctx ) 
{ 
  size_t left_over ;
  size_t add ;
  size_t tmp ;
  size_t left_over___0 ;

  {
  if (ctx->buflen != 0U) {
    left_over = (size_t )ctx->buflen;
    if (128UL - left_over > len) {
      tmp = len;
    } else {
      tmp = 128UL - left_over;
    }
    add = tmp;
    memcpy((void *)((char *)(ctx->buffer) + left_over), buffer, add);
    ctx->buflen = (uint32_t )((size_t )ctx->buflen + add);
    if (ctx->buflen > 64U) {
      md5_process_block((void const   *)(ctx->buffer), (size_t )(ctx->buflen & 4294967232U),
                        ctx);
      ctx->buflen &= 63U;
      memcpy((void *)(ctx->buffer), (void const   *)((char *)(ctx->buffer) + ((left_over + add) & 0xffffffffffffffc0UL)),
             (size_t )ctx->buflen);
    }
    buffer = (void const   *)((char const   *)buffer + add);
    len -= add;
  }
  if (len >= 64UL) {
    md5_process_block(buffer, len & 0xffffffffffffffc0UL, ctx);
    buffer = (void const   *)((char const   *)buffer + (len & 0xffffffffffffffc0UL));
    len &= 63UL;
  }
  if (len > 0UL) {
    left_over___0 = (size_t )ctx->buflen;
    memcpy((void *)((char *)(ctx->buffer) + left_over___0), buffer, len);
    left_over___0 += len;
    if (left_over___0 >= 64UL) {
      md5_process_block((void const   *)(ctx->buffer), (size_t )64, ctx);
      left_over___0 -= 64UL;
      memcpy((void *)(ctx->buffer), (void const   *)(& ctx->buffer[16]), left_over___0);
    }
    ctx->buflen = (uint32_t )left_over___0;
  }
  return;
}
}
 __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) md5_process_block)(void const   *buffer ,
                                                                                  size_t len ,
                                                                                  struct md5_ctx *ctx ) ;
void ( __attribute__((__leaf__)) md5_process_block)(void const   *buffer , size_t len ,
                                                    struct md5_ctx *ctx ) 
{ 
  uint32_t correct_words[16] ;
  uint32_t const   *words ;
  size_t nwords ;
  uint32_t const   *endp ;
  uint32_t A ;
  uint32_t B ;
  uint32_t C ;
  uint32_t D ;
  uint32_t *cwp ;
  uint32_t A_save ;
  uint32_t B_save ;
  uint32_t C_save ;
  uint32_t D_save ;
  uint32_t *tmp ;
  uint32_t tmp___0 ;
  uint32_t *tmp___1 ;
  uint32_t tmp___2 ;
  uint32_t *tmp___3 ;
  uint32_t tmp___4 ;
  uint32_t *tmp___5 ;
  uint32_t tmp___6 ;
  uint32_t *tmp___7 ;
  uint32_t tmp___8 ;
  uint32_t *tmp___9 ;
  uint32_t tmp___10 ;
  uint32_t *tmp___11 ;
  uint32_t tmp___12 ;
  uint32_t *tmp___13 ;
  uint32_t tmp___14 ;
  uint32_t *tmp___15 ;
  uint32_t tmp___16 ;
  uint32_t *tmp___17 ;
  uint32_t tmp___18 ;
  uint32_t *tmp___19 ;
  uint32_t tmp___20 ;
  uint32_t *tmp___21 ;
  uint32_t tmp___22 ;
  uint32_t *tmp___23 ;
  uint32_t tmp___24 ;
  uint32_t *tmp___25 ;
  uint32_t tmp___26 ;
  uint32_t *tmp___27 ;
  uint32_t tmp___28 ;
  uint32_t *tmp___29 ;
  uint32_t tmp___30 ;

  {
  words = (uint32_t const   *)buffer;
  nwords = len / sizeof(uint32_t );
  endp = words + nwords;
  A = ctx->A;
  B = ctx->B;
  C = ctx->C;
  D = ctx->D;
  ctx->total[0] = (uint32_t )((size_t )ctx->total[0] + len);
  if ((size_t )ctx->total[0] < len) {
    (ctx->total[1]) ++;
  }
  while (1) {

    if (! ((unsigned long )words < (unsigned long )endp)) {
      goto while_break;
    }
    cwp = correct_words;
    A_save = A;
    B_save = B;
    C_save = C;
    D_save = D;
    while (1) {
      tmp = cwp;
      cwp ++;
      tmp___0 = (uint32_t )*words;
      *tmp = tmp___0;
      A += ((D ^ (B & (C ^ D))) + tmp___0) + 3614090360U;
      words ++;
      A = (A << 7) | (A >> 25);
      A += B;
      goto while_break___0;
    }
    while_break___0: ;
    while (1) {
      tmp___1 = cwp;
      cwp ++;
      tmp___2 = (uint32_t )*words;
      *tmp___1 = tmp___2;
      D += ((C ^ (A & (B ^ C))) + tmp___2) + 3905402710U;
      words ++;
      D = (D << 12) | (D >> 20);
      D += A;
      goto while_break___1;
    }
    while_break___1: ;
    while (1) {
      tmp___3 = cwp;
      cwp ++;
      tmp___4 = (uint32_t )*words;
      *tmp___3 = tmp___4;
      C += ((B ^ (D & (A ^ B))) + tmp___4) + 606105819U;
      words ++;
      C = (C << 17) | (C >> 15);
      C += D;
      goto while_break___2;
    }
    while_break___2: ;
    while (1) {
      tmp___5 = cwp;
      cwp ++;
      tmp___6 = (uint32_t )*words;
      *tmp___5 = tmp___6;
      B += ((A ^ (C & (D ^ A))) + tmp___6) + 3250441966U;
      words ++;
      B = (B << 22) | (B >> 10);
      B += C;
      goto while_break___3;
    }
    while_break___3: ;
    while (1) {
      tmp___7 = cwp;
      cwp ++;
      tmp___8 = (uint32_t )*words;
      *tmp___7 = tmp___8;
      A += ((D ^ (B & (C ^ D))) + tmp___8) + 4118548399U;
      words ++;
      A = (A << 7) | (A >> 25);
      A += B;
      goto while_break___4;
    }
    while_break___4: ;
    while (1) {
      tmp___9 = cwp;
      cwp ++;
      tmp___10 = (uint32_t )*words;
      *tmp___9 = tmp___10;
      D += ((C ^ (A & (B ^ C))) + tmp___10) + 1200080426U;
      words ++;
      D = (D << 12) | (D >> 20);
      D += A;
      goto while_break___5;
    }
    while_break___5: ;
    while (1) {
      tmp___11 = cwp;
      cwp ++;
      tmp___12 = (uint32_t )*words;
      *tmp___11 = tmp___12;
      C += ((B ^ (D & (A ^ B))) + tmp___12) + 2821735955U;
      words ++;
      C = (C << 17) | (C >> 15);
      C += D;
      goto while_break___6;
    }
    while_break___6: ;
    while (1) {
      tmp___13 = cwp;
      cwp ++;
      tmp___14 = (uint32_t )*words;
      *tmp___13 = tmp___14;
      B += ((A ^ (C & (D ^ A))) + tmp___14) + 4249261313U;
      words ++;
      B = (B << 22) | (B >> 10);
      B += C;
      goto while_break___7;
    }
    while_break___7: ;
    while (1) {
      tmp___15 = cwp;
      cwp ++;
      tmp___16 = (uint32_t )*words;
      *tmp___15 = tmp___16;
      A += ((D ^ (B & (C ^ D))) + tmp___16) + 1770035416U;
      words ++;
      A = (A << 7) | (A >> 25);
      A += B;
      goto while_break___8;
    }
    while_break___8: ;
    while (1) {
      tmp___17 = cwp;
      cwp ++;
      tmp___18 = (uint32_t )*words;
      *tmp___17 = tmp___18;
      D += ((C ^ (A & (B ^ C))) + tmp___18) + 2336552879U;
      words ++;
      D = (D << 12) | (D >> 20);
      D += A;
      goto while_break___9;
    }
    while_break___9: ;
    while (1) {
      tmp___19 = cwp;
      cwp ++;
      tmp___20 = (uint32_t )*words;
      *tmp___19 = tmp___20;
      C += ((B ^ (D & (A ^ B))) + tmp___20) + 4294925233U;
      words ++;
      C = (C << 17) | (C >> 15);
      C += D;
      goto while_break___10;
    }
    while_break___10: ;
    while (1) {
      tmp___21 = cwp;
      cwp ++;
      tmp___22 = (uint32_t )*words;
      *tmp___21 = tmp___22;
      B += ((A ^ (C & (D ^ A))) + tmp___22) + 2304563134U;
      words ++;
      B = (B << 22) | (B >> 10);
      B += C;
      goto while_break___11;
    }
    while_break___11: ;
    while (1) {
      tmp___23 = cwp;
      cwp ++;
      tmp___24 = (uint32_t )*words;
      *tmp___23 = tmp___24;
      A += ((D ^ (B & (C ^ D))) + tmp___24) + 1804603682U;
      words ++;
      A = (A << 7) | (A >> 25);
      A += B;
      goto while_break___12;
    }
    while_break___12: ;
    while (1) {
      tmp___25 = cwp;
      cwp ++;
      tmp___26 = (uint32_t )*words;
      *tmp___25 = tmp___26;
      D += ((C ^ (A & (B ^ C))) + tmp___26) + 4254626195U;
      words ++;
      D = (D << 12) | (D >> 20);
      D += A;
      goto while_break___13;
    }
    while_break___13: ;
    while (1) {
      tmp___27 = cwp;
      cwp ++;
      tmp___28 = (uint32_t )*words;
      *tmp___27 = tmp___28;
      C += ((B ^ (D & (A ^ B))) + tmp___28) + 2792965006U;
      words ++;
      C = (C << 17) | (C >> 15);
      C += D;
      goto while_break___14;
    }
    while_break___14: ;
    while (1) {
      tmp___29 = cwp;
      cwp ++;
      tmp___30 = (uint32_t )*words;
      *tmp___29 = tmp___30;
      B += ((A ^ (C & (D ^ A))) + tmp___30) + 1236535329U;
      words ++;
      B = (B << 22) | (B >> 10);
      B += C;
      goto while_break___15;
    }
    while_break___15: ;
    while (1) {
      A += ((C ^ (D & (B ^ C))) + correct_words[1]) + 4129170786U;
      A = (A << 5) | (A >> 27);
      A += B;
      goto while_break___16;
    }
    while_break___16: ;
    while (1) {
      D += ((B ^ (C & (A ^ B))) + correct_words[6]) + 3225465664U;
      D = (D << 9) | (D >> 23);
      D += A;
      goto while_break___17;
    }
    while_break___17: ;
    while (1) {
      C += ((A ^ (B & (D ^ A))) + correct_words[11]) + 643717713U;
      C = (C << 14) | (C >> 18);
      C += D;
      goto while_break___18;
    }
    while_break___18: ;
    while (1) {
      B += ((D ^ (A & (C ^ D))) + correct_words[0]) + 3921069994U;
      B = (B << 20) | (B >> 12);
      B += C;
      goto while_break___19;
    }
    while_break___19: ;
    while (1) {
      A += ((C ^ (D & (B ^ C))) + correct_words[5]) + 3593408605U;
      A = (A << 5) | (A >> 27);
      A += B;
      goto while_break___20;
    }
    while_break___20: ;
    while (1) {
      D += ((B ^ (C & (A ^ B))) + correct_words[10]) + 38016083U;
      D = (D << 9) | (D >> 23);
      D += A;
      goto while_break___21;
    }
    while_break___21: ;
    while (1) {
      C += ((A ^ (B & (D ^ A))) + correct_words[15]) + 3634488961U;
      C = (C << 14) | (C >> 18);
      C += D;
      goto while_break___22;
    }
    while_break___22: ;
    while (1) {
      B += ((D ^ (A & (C ^ D))) + correct_words[4]) + 3889429448U;
      B = (B << 20) | (B >> 12);
      B += C;
      goto while_break___23;
    }
    while_break___23: ;
    while (1) {
      A += ((C ^ (D & (B ^ C))) + correct_words[9]) + 568446438U;
      A = (A << 5) | (A >> 27);
      A += B;
      goto while_break___24;
    }
    while_break___24: ;
    while (1) {
      D += ((B ^ (C & (A ^ B))) + correct_words[14]) + 3275163606U;
      D = (D << 9) | (D >> 23);
      D += A;
      goto while_break___25;
    }
    while_break___25: ;
    while (1) {
      C += ((A ^ (B & (D ^ A))) + correct_words[3]) + 4107603335U;
      C = (C << 14) | (C >> 18);
      C += D;
      goto while_break___26;
    }
    while_break___26: ;
    while (1) {
      B += ((D ^ (A & (C ^ D))) + correct_words[8]) + 1163531501U;
      B = (B << 20) | (B >> 12);
      B += C;
      goto while_break___27;
    }
    while_break___27: ;
    while (1) {
      A += ((C ^ (D & (B ^ C))) + correct_words[13]) + 2850285829U;
      A = (A << 5) | (A >> 27);
      A += B;
      goto while_break___28;
    }
    while_break___28: ;
    while (1) {
      D += ((B ^ (C & (A ^ B))) + correct_words[2]) + 4243563512U;
      D = (D << 9) | (D >> 23);
      D += A;
      goto while_break___29;
    }
    while_break___29: ;
    while (1) {
      C += ((A ^ (B & (D ^ A))) + correct_words[7]) + 1735328473U;
      C = (C << 14) | (C >> 18);
      C += D;
      goto while_break___30;
    }
    while_break___30: ;
    while (1) {
      B += ((D ^ (A & (C ^ D))) + correct_words[12]) + 2368359562U;
      B = (B << 20) | (B >> 12);
      B += C;
      goto while_break___31;
    }
    while_break___31: ;
    while (1) {
      A += (((B ^ C) ^ D) + correct_words[5]) + 4294588738U;
      A = (A << 4) | (A >> 28);
      A += B;
      goto while_break___32;
    }
    while_break___32: ;
    while (1) {
      D += (((A ^ B) ^ C) + correct_words[8]) + 2272392833U;
      D = (D << 11) | (D >> 21);
      D += A;
      goto while_break___33;
    }
    while_break___33: ;
    while (1) {
      C += (((D ^ A) ^ B) + correct_words[11]) + 1839030562U;
      C = (C << 16) | (C >> 16);
      C += D;
      goto while_break___34;
    }
    while_break___34: ;
    while (1) {
      B += (((C ^ D) ^ A) + correct_words[14]) + 4259657740U;
      B = (B << 23) | (B >> 9);
      B += C;
      goto while_break___35;
    }
    while_break___35: ;
    while (1) {
      A += (((B ^ C) ^ D) + correct_words[1]) + 2763975236U;
      A = (A << 4) | (A >> 28);
      A += B;
      goto while_break___36;
    }
    while_break___36: ;
    while (1) {
      D += (((A ^ B) ^ C) + correct_words[4]) + 1272893353U;
      D = (D << 11) | (D >> 21);
      D += A;
      goto while_break___37;
    }
    while_break___37: ;
    while (1) {
      C += (((D ^ A) ^ B) + correct_words[7]) + 4139469664U;
      C = (C << 16) | (C >> 16);
      C += D;
      goto while_break___38;
    }
    while_break___38: ;
    while (1) {
      B += (((C ^ D) ^ A) + correct_words[10]) + 3200236656U;
      B = (B << 23) | (B >> 9);
      B += C;
      goto while_break___39;
    }
    while_break___39: ;
    while (1) {
      A += (((B ^ C) ^ D) + correct_words[13]) + 681279174U;
      A = (A << 4) | (A >> 28);
      A += B;
      goto while_break___40;
    }
    while_break___40: ;
    while (1) {
      D += (((A ^ B) ^ C) + correct_words[0]) + 3936430074U;
      D = (D << 11) | (D >> 21);
      D += A;
      goto while_break___41;
    }
    while_break___41: ;
    while (1) {
      C += (((D ^ A) ^ B) + correct_words[3]) + 3572445317U;
      C = (C << 16) | (C >> 16);
      C += D;
      goto while_break___42;
    }
    while_break___42: ;
    while (1) {
      B += (((C ^ D) ^ A) + correct_words[6]) + 76029189U;
      B = (B << 23) | (B >> 9);
      B += C;
      goto while_break___43;
    }
    while_break___43: ;
    while (1) {
      A += (((B ^ C) ^ D) + correct_words[9]) + 3654602809U;
      A = (A << 4) | (A >> 28);
      A += B;
      goto while_break___44;
    }
    while_break___44: ;
    while (1) {
      D += (((A ^ B) ^ C) + correct_words[12]) + 3873151461U;
      D = (D << 11) | (D >> 21);
      D += A;
      goto while_break___45;
    }
    while_break___45: ;
    while (1) {
      C += (((D ^ A) ^ B) + correct_words[15]) + 530742520U;
      C = (C << 16) | (C >> 16);
      C += D;
      goto while_break___46;
    }
    while_break___46: ;
    while (1) {
      B += (((C ^ D) ^ A) + correct_words[2]) + 3299628645U;
      B = (B << 23) | (B >> 9);
      B += C;
      goto while_break___47;
    }
    while_break___47: ;
    while (1) {
      A += ((C ^ (B | ~ D)) + correct_words[0]) + 4096336452U;
      A = (A << 6) | (A >> 26);
      A += B;
      goto while_break___48;
    }
    while_break___48: ;
    while (1) {
      D += ((B ^ (A | ~ C)) + correct_words[7]) + 1126891415U;
      D = (D << 10) | (D >> 22);
      D += A;
      goto while_break___49;
    }
    while_break___49: ;
    while (1) {
      C += ((A ^ (D | ~ B)) + correct_words[14]) + 2878612391U;
      C = (C << 15) | (C >> 17);
      C += D;
      goto while_break___50;
    }
    while_break___50: ;
    while (1) {
      B += ((D ^ (C | ~ A)) + correct_words[5]) + 4237533241U;
      B = (B << 21) | (B >> 11);
      B += C;
      goto while_break___51;
    }
    while_break___51: ;
    while (1) {
      A += ((C ^ (B | ~ D)) + correct_words[12]) + 1700485571U;
      A = (A << 6) | (A >> 26);
      A += B;
      goto while_break___52;
    }
    while_break___52: ;
    while (1) {
      D += ((B ^ (A | ~ C)) + correct_words[3]) + 2399980690U;
      D = (D << 10) | (D >> 22);
      D += A;
      goto while_break___53;
    }
    while_break___53: ;
    while (1) {
      C += ((A ^ (D | ~ B)) + correct_words[10]) + 4293915773U;
      C = (C << 15) | (C >> 17);
      C += D;
      goto while_break___54;
    }
    while_break___54: ;
    while (1) {
      B += ((D ^ (C | ~ A)) + correct_words[1]) + 2240044497U;
      B = (B << 21) | (B >> 11);
      B += C;
      goto while_break___55;
    }
    while_break___55: ;
    while (1) {
      A += ((C ^ (B | ~ D)) + correct_words[8]) + 1873313359U;
      A = (A << 6) | (A >> 26);
      A += B;
      goto while_break___56;
    }
    while_break___56: ;
    while (1) {
      D += ((B ^ (A | ~ C)) + correct_words[15]) + 4264355552U;
      D = (D << 10) | (D >> 22);
      D += A;
      goto while_break___57;
    }
    while_break___57: ;
    while (1) {
      C += ((A ^ (D | ~ B)) + correct_words[6]) + 2734768916U;
      C = (C << 15) | (C >> 17);
      C += D;
      goto while_break___58;
    }
    while_break___58: ;
    while (1) {
      B += ((D ^ (C | ~ A)) + correct_words[13]) + 1309151649U;
      B = (B << 21) | (B >> 11);
      B += C;
      goto while_break___59;
    }
    while_break___59: ;
    while (1) {
      A += ((C ^ (B | ~ D)) + correct_words[4]) + 4149444226U;
      A = (A << 6) | (A >> 26);
      A += B;
      goto while_break___60;
    }
    while_break___60: ;
    while (1) {
      D += ((B ^ (A | ~ C)) + correct_words[11]) + 3174756917U;
      D = (D << 10) | (D >> 22);
      D += A;
      goto while_break___61;
    }
    while_break___61: ;
    while (1) {
      C += ((A ^ (D | ~ B)) + correct_words[2]) + 718787259U;
      C = (C << 15) | (C >> 17);
      C += D;
      goto while_break___62;
    }
    while_break___62: ;
    while (1) {
      B += ((D ^ (C | ~ A)) + correct_words[9]) + 3951481745U;
      B = (B << 21) | (B >> 11);
      B += C;
      goto while_break___63;
    }
    while_break___63: 
    A += A_save;
    B += B_save;
    C += C_save;
    D += D_save;
  }
  while_break: 
  ctx->A = A;
  ctx->B = B;
  ctx->C = C;
  ctx->D = D;
  return;
}
}
int mbsnwidth(char const   *string , size_t nbytes , int flags ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) wcwidth)(wchar_t __c ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) iswcntrl)(wint_t __wc ) ;
int mbsnwidth(char const   *string , size_t nbytes , int flags ) 
{ 
  char const   *p ;
  char const   *plimit ;
  int width ;
  mbstate_t mbstate ;
  wchar_t wc ;
  size_t bytes ;
  int w ;
  int tmp ;
  int tmp___0 ;
  size_t tmp___1 ;
  unsigned char c ;
  char const   *tmp___2 ;
  unsigned short const   **tmp___3 ;
  unsigned short const   **tmp___4 ;

  {
  p = string;
  plimit = p + nbytes;
  width = 0;
  tmp___1 = __ctype_get_mb_cur_max();
  if (tmp___1 > 1UL) {
    while (1) {

      if (! ((unsigned long )p < (unsigned long )plimit)) {
        goto while_break;
      }
      if ((int const   )*p == 32) {
        goto case_32;
      }
      if ((int const   )*p == 33) {
        goto case_32;
      }
      if ((int const   )*p == 34) {
        goto case_32;
      }
      if ((int const   )*p == 35) {
        goto case_32;
      }
      if ((int const   )*p == 37) {
        goto case_32;
      }
      if ((int const   )*p == 38) {
        goto case_32;
      }
      if ((int const   )*p == 39) {
        goto case_32;
      }
      if ((int const   )*p == 40) {
        goto case_32;
      }
      if ((int const   )*p == 41) {
        goto case_32;
      }
      if ((int const   )*p == 42) {
        goto case_32;
      }
      if ((int const   )*p == 43) {
        goto case_32;
      }
      if ((int const   )*p == 44) {
        goto case_32;
      }
      if ((int const   )*p == 45) {
        goto case_32;
      }
      if ((int const   )*p == 46) {
        goto case_32;
      }
      if ((int const   )*p == 47) {
        goto case_32;
      }
      if ((int const   )*p == 48) {
        goto case_32;
      }
      if ((int const   )*p == 49) {
        goto case_32;
      }
      if ((int const   )*p == 50) {
        goto case_32;
      }
      if ((int const   )*p == 51) {
        goto case_32;
      }
      if ((int const   )*p == 52) {
        goto case_32;
      }
      if ((int const   )*p == 53) {
        goto case_32;
      }
      if ((int const   )*p == 54) {
        goto case_32;
      }
      if ((int const   )*p == 55) {
        goto case_32;
      }
      if ((int const   )*p == 56) {
        goto case_32;
      }
      if ((int const   )*p == 57) {
        goto case_32;
      }
      if ((int const   )*p == 58) {
        goto case_32;
      }
      if ((int const   )*p == 59) {
        goto case_32;
      }
      if ((int const   )*p == 60) {
        goto case_32;
      }
      if ((int const   )*p == 61) {
        goto case_32;
      }
      if ((int const   )*p == 62) {
        goto case_32;
      }
      if ((int const   )*p == 63) {
        goto case_32;
      }
      if ((int const   )*p == 65) {
        goto case_32;
      }
      if ((int const   )*p == 66) {
        goto case_32;
      }
      if ((int const   )*p == 67) {
        goto case_32;
      }
      if ((int const   )*p == 68) {
        goto case_32;
      }
      if ((int const   )*p == 69) {
        goto case_32;
      }
      if ((int const   )*p == 70) {
        goto case_32;
      }
      if ((int const   )*p == 71) {
        goto case_32;
      }
      if ((int const   )*p == 72) {
        goto case_32;
      }
      if ((int const   )*p == 73) {
        goto case_32;
      }
      if ((int const   )*p == 74) {
        goto case_32;
      }
      if ((int const   )*p == 75) {
        goto case_32;
      }
      if ((int const   )*p == 76) {
        goto case_32;
      }
      if ((int const   )*p == 77) {
        goto case_32;
      }
      if ((int const   )*p == 78) {
        goto case_32;
      }
      if ((int const   )*p == 79) {
        goto case_32;
      }
      if ((int const   )*p == 80) {
        goto case_32;
      }
      if ((int const   )*p == 81) {
        goto case_32;
      }
      if ((int const   )*p == 82) {
        goto case_32;
      }
      if ((int const   )*p == 83) {
        goto case_32;
      }
      if ((int const   )*p == 84) {
        goto case_32;
      }
      if ((int const   )*p == 85) {
        goto case_32;
      }
      if ((int const   )*p == 86) {
        goto case_32;
      }
      if ((int const   )*p == 87) {
        goto case_32;
      }
      if ((int const   )*p == 88) {
        goto case_32;
      }
      if ((int const   )*p == 89) {
        goto case_32;
      }
      if ((int const   )*p == 90) {
        goto case_32;
      }
      if ((int const   )*p == 91) {
        goto case_32;
      }
      if ((int const   )*p == 92) {
        goto case_32;
      }
      if ((int const   )*p == 93) {
        goto case_32;
      }
      if ((int const   )*p == 94) {
        goto case_32;
      }
      if ((int const   )*p == 95) {
        goto case_32;
      }
      if ((int const   )*p == 97) {
        goto case_32;
      }
      if ((int const   )*p == 98) {
        goto case_32;
      }
      if ((int const   )*p == 99) {
        goto case_32;
      }
      if ((int const   )*p == 100) {
        goto case_32;
      }
      if ((int const   )*p == 101) {
        goto case_32;
      }
      if ((int const   )*p == 102) {
        goto case_32;
      }
      if ((int const   )*p == 103) {
        goto case_32;
      }
      if ((int const   )*p == 104) {
        goto case_32;
      }
      if ((int const   )*p == 105) {
        goto case_32;
      }
      if ((int const   )*p == 106) {
        goto case_32;
      }
      if ((int const   )*p == 107) {
        goto case_32;
      }
      if ((int const   )*p == 108) {
        goto case_32;
      }
      if ((int const   )*p == 109) {
        goto case_32;
      }
      if ((int const   )*p == 110) {
        goto case_32;
      }
      if ((int const   )*p == 111) {
        goto case_32;
      }
      if ((int const   )*p == 112) {
        goto case_32;
      }
      if ((int const   )*p == 113) {
        goto case_32;
      }
      if ((int const   )*p == 114) {
        goto case_32;
      }
      if ((int const   )*p == 115) {
        goto case_32;
      }
      if ((int const   )*p == 116) {
        goto case_32;
      }
      if ((int const   )*p == 117) {
        goto case_32;
      }
      if ((int const   )*p == 118) {
        goto case_32;
      }
      if ((int const   )*p == 119) {
        goto case_32;
      }
      if ((int const   )*p == 120) {
        goto case_32;
      }
      if ((int const   )*p == 121) {
        goto case_32;
      }
      if ((int const   )*p == 122) {
        goto case_32;
      }
      if ((int const   )*p == 123) {
        goto case_32;
      }
      if ((int const   )*p == 124) {
        goto case_32;
      }
      if ((int const   )*p == 125) {
        goto case_32;
      }
      if ((int const   )*p == 126) {
        goto case_32;
      }
      goto switch_default;
      case_32: 
      p ++;
      width ++;
      goto switch_break;
      switch_default: 
      memset((void *)(& mbstate), 0, sizeof(mbstate));
      while (1) {
        bytes = mbrtowc(& wc, p, (size_t )(plimit - p), & mbstate);
        if (bytes == 0xffffffffffffffffUL) {
          if (! (flags & 1)) {
            p ++;
            width ++;
            goto while_break___0;
          } else {
            return (-1);
          }
        }
        if (bytes == 0xfffffffffffffffeUL) {
          if (! (flags & 1)) {
            p = plimit;
            width ++;
            goto while_break___0;
          } else {
            return (-1);
          }
        }
        if (bytes == 0UL) {
          bytes = (size_t )1;
        }
        w = wcwidth(wc);
        if (w >= 0) {
          if (w > 2147483647 - width) {
            goto overflow;
          }
          width += w;
        } else
        if (! (flags & 2)) {
          tmp = iswcntrl((wint_t )wc);
          if (! tmp) {
            if (width == 2147483647) {
              goto overflow;
            }
            width ++;
          }
        } else {
          return (-1);
        }
        p += bytes;
        tmp___0 = mbsinit((mbstate_t const   *)(& mbstate));
        if (tmp___0) {
          goto while_break___0;
        }
      }
      while_break___0: ;
      goto switch_break;
      switch_break: ;
    }
    while_break: ;
    return (width);
  }
  while (1) {

    if (! ((unsigned long )p < (unsigned long )plimit)) {
      goto while_break___1;
    }
    tmp___2 = p;
    p ++;
    c = (unsigned char )*tmp___2;
    tmp___4 = __ctype_b_loc();
    if ((int const   )*(*tmp___4 + (int )c) & 16384) {
      if (width == 2147483647) {
        goto overflow;
      }
      width ++;
    } else
    if (! (flags & 2)) {
      tmp___3 = __ctype_b_loc();
      if (! ((int const   )*(*tmp___3 + (int )c) & 2)) {
        if (width == 2147483647) {
          goto overflow;
        }
        width ++;
      }
    } else {
      return (-1);
    }
  }
  while_break___1: ;
  return (width);
  overflow: 
  return (2147483647);
}
}
int ( __attribute__((__nonnull__(1,2))) mbscasecmp)(char const   *s1 , char const   *s2 ) ;
extern  __attribute__((__nothrow__)) wint_t ( __attribute__((__leaf__)) towlower)(wint_t __wc ) ;
int ( __attribute__((__nonnull__(1,2))) mbscasecmp)(char const   *s1 , char const   *s2 ) 
{ 
  mbui_iterator_t iter1 ;
  mbui_iterator_t iter2 ;
  int cmp ;
  wint_t tmp ;
  wint_t tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  unsigned char const   *p1 ;
  unsigned char const   *p2 ;
  unsigned char c1 ;
  unsigned char c2 ;
  int tmp___18 ;
  unsigned short const   **tmp___19 ;
  int tmp___21 ;
  unsigned short const   **tmp___22 ;
  size_t tmp___25 ;

  {
  if ((unsigned long )s1 == (unsigned long )s2) {
    return (0);
  }
  tmp___25 = __ctype_get_mb_cur_max();
  if (tmp___25 > 1UL) {
    iter1.cur.ptr = s1;
    iter1.in_shift = (_Bool)0;
    memset((void *)(& iter1.state), '\000', sizeof(mbstate_t ));
    iter1.next_done = (_Bool)0;
    iter2.cur.ptr = s2;
    iter2.in_shift = (_Bool)0;
    memset((void *)(& iter2.state), '\000', sizeof(mbstate_t ));
    iter2.next_done = (_Bool)0;
    while (1) {
      mbuiter_multi_next(& iter1);
      if (iter1.cur.wc_valid) {
        if (iter1.cur.wc == 0) {
          tmp___13 = 0;
        } else {
          tmp___13 = 1;
        }
      } else {
        tmp___13 = 1;
      }
      if (tmp___13) {
        mbuiter_multi_next(& iter2);
        if (iter2.cur.wc_valid) {
          if (iter2.cur.wc == 0) {
            tmp___14 = 0;
          } else {
            tmp___14 = 1;
          }
        } else {
          tmp___14 = 1;
        }
        if (! tmp___14) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      if (iter1.cur.wc_valid) {
        if (iter2.cur.wc_valid) {
          tmp = towlower((wint_t )iter1.cur.wc);
          tmp___0 = towlower((wint_t )iter2.cur.wc);
          tmp___1 = (int )tmp - (int )tmp___0;
        } else {
          tmp___1 = -1;
        }
        tmp___12 = tmp___1;
      } else {
        if (iter2.cur.wc_valid) {
          tmp___11 = 1;
        } else {
          if (iter1.cur.bytes == iter2.cur.bytes) {
            tmp___2 = memcmp((void const   *)iter1.cur.ptr, (void const   *)iter2.cur.ptr,
                             iter1.cur.bytes);
            tmp___10 = tmp___2;
          } else {
            if (iter1.cur.bytes < iter2.cur.bytes) {
              tmp___5 = memcmp((void const   *)iter1.cur.ptr, (void const   *)iter2.cur.ptr,
                               iter1.cur.bytes);
              if (tmp___5 > 0) {
                tmp___4 = 1;
              } else {
                tmp___4 = -1;
              }
              tmp___9 = tmp___4;
            } else {
              tmp___8 = memcmp((void const   *)iter1.cur.ptr, (void const   *)iter2.cur.ptr,
                               iter2.cur.bytes);
              if (tmp___8 >= 0) {
                tmp___7 = 1;
              } else {
                tmp___7 = -1;
              }
              tmp___9 = tmp___7;
            }
            tmp___10 = tmp___9;
          }
          tmp___11 = tmp___10;
        }
        tmp___12 = tmp___11;
      }
      cmp = tmp___12;
      if (cmp != 0) {
        return (cmp);
      }
      iter1.cur.ptr += iter1.cur.bytes;
      iter1.next_done = (_Bool)0;
      iter2.cur.ptr += iter2.cur.bytes;
      iter2.next_done = (_Bool)0;
    }
    while_break: 
    mbuiter_multi_next(& iter1);
    if (iter1.cur.wc_valid) {
      if (iter1.cur.wc == 0) {
        tmp___15 = 0;
      } else {
        tmp___15 = 1;
      }
    } else {
      tmp___15 = 1;
    }
    if (tmp___15) {
      return (1);
    }
    mbuiter_multi_next(& iter2);
    if (iter2.cur.wc_valid) {
      if (iter2.cur.wc == 0) {
        tmp___16 = 0;
      } else {
        tmp___16 = 1;
      }
    } else {
      tmp___16 = 1;
    }
    if (tmp___16) {
      return (-1);
    }
    return (0);
  } else {
    p1 = (unsigned char const   *)s1;
    p2 = (unsigned char const   *)s2;
    while (1) {
      tmp___19 = __ctype_b_loc();
      if ((int const   )*(*tmp___19 + (int )*p1) & 256) {
        tmp___18 = tolower((int )*p1);
        c1 = (unsigned char )tmp___18;
      } else {
        c1 = (unsigned char )*p1;
      }
      tmp___22 = __ctype_b_loc();
      if ((int const   )*(*tmp___22 + (int )*p2) & 256) {
        tmp___21 = tolower((int )*p2);
        c2 = (unsigned char )tmp___21;
      } else {
        c2 = (unsigned char )*p2;
      }
      if ((int )c1 == 0) {
        goto while_break___0;
      }
      p1 ++;
      p2 ++;
      if (! ((int )c1 == (int )c2)) {
        goto while_break___0;
      }
    }
    while_break___0: ;
    return ((int )c1 - (int )c2);
  }
}
}
unsigned int const   is_basic_table[8]  = {      (unsigned int const   )6656,      (unsigned int const   )4294967279U,      (unsigned int const   )4294967294U,      (unsigned int const   )2147483646};
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
extern int optind ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) getopt_long)(int ___argc ,
                                                                                  char * const  *___argv ,
                                                                                  char const   *__shortopts ,
                                                                                  struct option  const  *__longopts ,
                                                                                  int *__longind ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_init)(pthread_mutex_t *__mutex ,
                                                                                                         pthread_mutexattr_t const   *__mutexattr ) ;
#pragma weak pthread_mutex_init
#pragma weak pthread_mutex_lock
#pragma weak pthread_mutex_unlock
#pragma weak pthread_mutex_destroy
#pragma weak pthread_rwlock_init
#pragma weak pthread_rwlock_rdlock
#pragma weak pthread_rwlock_wrlock
#pragma weak pthread_rwlock_unlock
#pragma weak pthread_rwlock_destroy
#pragma weak pthread_once
#pragma weak pthread_cond_init
#pragma weak pthread_cond_wait
#pragma weak pthread_cond_signal
#pragma weak pthread_cond_broadcast
#pragma weak pthread_cond_destroy
#pragma weak pthread_mutexattr_init
#pragma weak pthread_mutexattr_settype
#pragma weak pthread_mutexattr_destroy
#pragma weak pthread_self
#pragma weak pthread_cancel
extern  __attribute__((__nothrow__)) FILE *( __attribute__((__leaf__)) fdopen)(int __fd ,
                                                                               char const   *__modes ) ;
extern int fscanf(FILE * __restrict  __stream , char const   * __restrict  __format 
                  , ...) ;
extern int ungetc(int __c , FILE *__stream ) ;
static char const   * volatile  charset_aliases  ;
static char const   *get_charset_aliases(void) 
{ 
  char const   *cp ;
  char const   *dir ;
  char const   *base ;
  char *file_name___3 ;
  size_t dir_len___0 ;
  size_t tmp ;
  size_t base_len___0 ;
  size_t tmp___0 ;
  int add_slash ;
  int tmp___1 ;
  int fd ;
  FILE *fp ;
  char *res_ptr ;
  size_t res_size ;
  int c ;
  char buf1[51] ;
  char buf2[51] ;
  size_t l1 ;
  size_t l2 ;
  char *old_res_ptr ;
  int tmp___3 ;

  {
  cp = (char const   *)charset_aliases;
  if ((unsigned long )cp == (unsigned long )((void *)0)) {
    base = "charset.alias";
    dir = (char const   *)getenv("CHARSETALIASDIR");
    if ((unsigned long )dir == (unsigned long )((void *)0)) {
      dir = "/usr/local/lib";
    } else
    if ((int const   )*(dir + 0) == 0) {
      dir = "/usr/local/lib";
    }
    tmp = strlen(dir);
    dir_len___0 = tmp;
    tmp___0 = strlen(base);
    base_len___0 = tmp___0;
    if (dir_len___0 > 0UL) {
      if (! ((int const   )*(dir + (dir_len___0 - 1UL)) == 47)) {
        tmp___1 = 1;
      } else {
        tmp___1 = 0;
      }
    } else {
      tmp___1 = 0;
    }
    add_slash = tmp___1;
    file_name___3 = (char *)malloc(((dir_len___0 + (size_t )add_slash) + base_len___0) + 1UL);
    if ((unsigned long )file_name___3 != (unsigned long )((void *)0)) {
      memcpy((void *)file_name___3, (void const   *)dir, dir_len___0);
      if (add_slash) {
        *(file_name___3 + dir_len___0) = (char )'/';
      }
      memcpy((void *)((file_name___3 + dir_len___0) + add_slash), (void const   *)base,
             base_len___0 + 1UL);
    }
    if ((unsigned long )file_name___3 == (unsigned long )((void *)0)) {
      cp = "";
    } else {
      fd = open((char const   *)file_name___3, 131072);
      if (fd < 0) {
        cp = "";
      } else {
        fp = fdopen(fd, "r");
        if ((unsigned long )fp == (unsigned long )((void *)0)) {
          close(fd);
          cp = "";
        } else {
          res_ptr = (char *)((void *)0);
          res_size = (size_t )0;
          while (1) {
            c = getc_unlocked(fp);
            if (c == -1) {
              goto while_break;
            }
            if (c == 10) {
              goto __Cont;
            } else
            if (c == 32) {
              goto __Cont;
            } else
            if (c == 9) {
              goto __Cont;
            }
            if (c == 35) {
              while (1) {
                c = getc_unlocked(fp);
                if (c == -1) {
                  goto while_break___0;
                } else
                if (c == 10) {
                  goto while_break___0;
                }
              }
              while_break___0: ;
              if (c == -1) {
                goto while_break;
              }
              goto __Cont;
            }
            ungetc(c, fp);
            tmp___3 = fscanf(fp, "%50s %50s", buf1, buf2);
            if (tmp___3 < 2) {
              goto while_break;
            }
            l1 = strlen((char const   *)(buf1));
            l2 = strlen((char const   *)(buf2));
            old_res_ptr = res_ptr;
            if (res_size == 0UL) {
              res_size = ((l1 + 1UL) + l2) + 1UL;
              res_ptr = (char *)malloc(res_size + 1UL);
            } else {
              res_size += ((l1 + 1UL) + l2) + 1UL;
              res_ptr = (char *)realloc((void *)res_ptr, res_size + 1UL);
            }
            if ((unsigned long )res_ptr == (unsigned long )((void *)0)) {
              res_size = (size_t )0;
              free((void *)old_res_ptr);
              goto while_break;
            }
            strcpy(((res_ptr + res_size) - (l2 + 1UL)) - (l1 + 1UL), (char const   *)(buf1));
            strcpy((res_ptr + res_size) - (l2 + 1UL), (char const   *)(buf2));
            __Cont: ;
          }
          while_break: 
          rpl_fclose(fp);
          if (res_size == 0UL) {
            cp = "";
          } else {
            *(res_ptr + res_size) = (char )'\000';
            cp = (char const   *)res_ptr;
          }
        }
      }
      free((void *)file_name___3);
    }
    charset_aliases = cp;
  }
  return (cp);
}
}
char const   *locale_charset(void) 
{ 
  char const   *codeset ;
  char const   *aliases ;
  size_t tmp ;
  size_t tmp___0 ;
  size_t tmp___1 ;
  int tmp___2 ;

  {
  codeset = (char const   *)nl_langinfo(14);
  if ((unsigned long )codeset == (unsigned long )((void *)0)) {
    codeset = "";
  }
  aliases = get_charset_aliases();
  while (1) {

    if (! ((int const   )*aliases != 0)) {
      goto while_break;
    }
    tmp___2 = strcmp(codeset, aliases);
    if (tmp___2 == 0) {
      tmp___1 = strlen(aliases);
      codeset = (aliases + tmp___1) + 1;
      goto while_break;
    } else
    if ((int const   )*(aliases + 0) == 42) {
      if ((int const   )*(aliases + 1) == 0) {
        tmp___1 = strlen(aliases);
        codeset = (aliases + tmp___1) + 1;
        goto while_break;
      }
    }
    tmp = strlen(aliases);
    aliases += tmp + 1UL;
    tmp___0 = strlen(aliases);
    aliases += tmp___0 + 1UL;
  }
  while_break: ;
  if ((int const   )*(codeset + 0) == 0) {
    codeset = "ASCII";
  }
  return (codeset);
}
}
extern  __attribute__((__nothrow__)) long double ( __attribute__((__nonnull__(1),
__leaf__)) strtold)(char const   * __restrict  __nptr , char ** __restrict  __endptr ) ;
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
extern  __attribute__((__nothrow__)) struct lconv *( __attribute__((__leaf__)) localeconv)(void) ;
struct heap *heap_alloc(int (*compare___0)(void const   * , void const   * ) , size_t n_reserve ) ;
void heap_free(struct heap *heap ) ;
int heap_insert(struct heap *heap , void *item ) ;
void *heap_remove_top(struct heap *heap ) ;
static size_t heapify_down(void **array , size_t count , size_t initial , int (*compare___0)(void const   * ,
                                                                                             void const   * ) ) ;
static void heapify_up(void **array , size_t count , int (*compare___0)(void const   * ,
                                                                        void const   * ) ) ;
static int heap_default_compare(void const   *a , void const   *b ) 
{ 


  {
  return (0);
}
}
struct heap *heap_alloc(int (*compare___0)(void const   * , void const   * ) , size_t n_reserve ) 
{ 
  struct heap *heap ;
  struct heap *tmp ;

  {
  tmp = (struct heap *)xmalloc(sizeof(*heap));
  heap = tmp;
  if (n_reserve == 0UL) {
    n_reserve = (size_t )1;
  }
  heap->array = (void **)xnmalloc(n_reserve, sizeof(*(heap->array)));
  *(heap->array + 0) = (void *)0;
  heap->capacity = n_reserve;
  heap->count = (size_t )0;
  if (compare___0) {
    heap->compare = compare___0;
  } else {
    heap->compare = & heap_default_compare;
  }
  return (heap);
}
}
void heap_free(struct heap *heap ) 
{ 


  {
  free((void *)heap->array);
  free((void *)heap);
  return;
}
}
int heap_insert(struct heap *heap , void *item ) 
{ 


  {
  if (heap->capacity - 1UL <= heap->count) {
    heap->array = (void **)x2nrealloc((void *)heap->array, & heap->capacity, sizeof(*(heap->array)));
  }
  (heap->count) ++;
  *(heap->array + heap->count) = item;
  heapify_up(heap->array, heap->count, heap->compare);
  return (0);
}
}
void *heap_remove_top(struct heap *heap ) 
{ 
  void *top ;
  size_t tmp ;

  {
  if (heap->count == 0UL) {
    return ((void *)0);
  }
  top = *(heap->array + 1);
  tmp = heap->count;
  (heap->count) --;
  *(heap->array + 1) = *(heap->array + tmp);
  heapify_down(heap->array, heap->count, (size_t )1, heap->compare);
  return (top);
}
}
static size_t heapify_down(void **array , size_t count , size_t initial , int (*compare___0)(void const   * ,
                                                                                             void const   * ) ) 
{ 
  void *element ;
  size_t parent ;
  size_t child ;
  int tmp ;
  int tmp___0 ;

  {
  element = *(array + initial);
  parent = initial;
  while (1) {

    if (! (parent <= count / 2UL)) {
      goto while_break;
    }
    child = 2UL * parent;
    if (child < count) {
      tmp = (*compare___0)((void const   *)*(array + child), (void const   *)*(array + (child + 1UL)));
      if (tmp < 0) {
        child ++;
      }
    }
    tmp___0 = (*compare___0)((void const   *)*(array + child), (void const   *)element);
    if (tmp___0 <= 0) {
      goto while_break;
    }
    *(array + parent) = *(array + child);
    parent = child;
  }
  while_break: 
  *(array + parent) = element;
  return (parent);
}
}
static void heapify_up(void **array , size_t count , int (*compare___0)(void const   * ,
                                                                        void const   * ) ) 
{ 
  size_t k ;
  void *new_element ;
  int tmp ;

  {
  k = count;
  new_element = *(array + k);
  while (1) {

    if (k != 1UL) {
      tmp = (*compare___0)((void const   *)*(array + k / 2UL), (void const   *)new_element);
      if (! (tmp <= 0)) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    *(array + k) = *(array + k / 2UL);
    k /= 2UL;
  }
  while_break: 
  *(array + k) = new_element;
  return;
}
}
size_t hash_string(char const   *string , size_t n_buckets )  __attribute__((__pure__)) ;
_Bool ( __attribute__((__warn_unused_result__)) hash_rehash)(Hash_table *table___0 ,
                                                             size_t candidate ) ;
__inline static size_t rotr_sz(size_t x , int n ) 
{ 


  {
  return (((x >> n) | (x << (8UL * sizeof(x) - (unsigned long )n))) & 0xffffffffffffffffUL);
}
}
static struct hash_tuning  const  default_tuning  =    {0.0f, 1.0f, 0.8f, 1.414f, (_Bool)0};
static struct hash_entry *safe_hasher(Hash_table const   *table___0 , void const   *key ) 
{ 
  size_t n ;
  size_t tmp ;

  {
  tmp = (*(table___0->hasher))(key, (size_t )table___0->n_buckets);
  n = tmp;
  if (! (n < (size_t )table___0->n_buckets)) {
    abort();
  }
  return ((struct hash_entry *)(table___0->bucket + n));
}
}
size_t hash_string(char const   *string , size_t n_buckets )  __attribute__((__pure__)) ;
size_t hash_string(char const   *string , size_t n_buckets ) 
{ 
  size_t value ;
  unsigned char ch ;

  {
  value = (size_t )0;
  while (1) {
    ch = (unsigned char )*string;
    if (! ch) {
      goto while_break;
    }
    value = (value * 31UL + (size_t )ch) % n_buckets;
    string ++;
  }
  while_break: ;
  return (value);
}
}
static _Bool is_prime(size_t candidate )  __attribute__((__const__)) ;
static _Bool is_prime(size_t candidate )  __attribute__((__const__)) ;
static _Bool is_prime(size_t candidate ) 
{ 
  size_t divisor ;
  size_t square ;
  int tmp ;

  {
  divisor = (size_t )3;
  square = divisor * divisor;
  while (1) {

    if (square < candidate) {
      if (! (candidate % divisor)) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    divisor ++;
    square += 4UL * divisor;
    divisor ++;
  }
  while_break: ;
  if (candidate % divisor) {
    tmp = 1;
  } else {
    tmp = 0;
  }
  return ((_Bool )tmp);
}
}
static size_t next_prime(size_t candidate )  __attribute__((__const__)) ;
static size_t next_prime(size_t candidate )  __attribute__((__const__)) ;
static size_t next_prime(size_t candidate ) 
{ 
  _Bool tmp ;

  {
  if (candidate < 10UL) {
    candidate = (size_t )10;
  }
  candidate |= 1UL;
  while (1) {

    if (0xffffffffffffffffUL != candidate) {
      tmp = is_prime(candidate);
      if (tmp) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    candidate += 2UL;
  }
  while_break: ;
  return (candidate);
}
}
static size_t raw_hasher(void const   *data , size_t n ) 
{ 
  size_t val ;
  size_t tmp ;

  {
  tmp = rotr_sz((size_t )data, 3);
  val = tmp;
  return (val % n);
}
}
static _Bool raw_comparator(void const   *a , void const   *b ) 
{ 


  {
  return ((_Bool )((unsigned long )a == (unsigned long )b));
}
}
static _Bool check_tuning(Hash_table *table___0 ) 
{ 
  Hash_tuning const   *tuning ;
  float epsilon ;

  {
  tuning = table___0->tuning;
  if ((unsigned long )tuning == (unsigned long )(& default_tuning)) {
    return ((_Bool)1);
  }
  epsilon = 0.1f;
  if (epsilon < (float )tuning->growth_threshold) {
    if (tuning->growth_threshold < (float const   )((float )1 - epsilon)) {
      if ((float )1 + epsilon < (float )tuning->growth_factor) {
        if ((float const   )0 <= tuning->shrink_threshold) {
          if (tuning->shrink_threshold + (float const   )epsilon < tuning->shrink_factor) {
            if (tuning->shrink_factor <= (float const   )1) {
              if (tuning->shrink_threshold + (float const   )epsilon < tuning->growth_threshold) {
                return ((_Bool)1);
              }
            }
          }
        }
      }
    }
  }
  table___0->tuning = & default_tuning;
  return ((_Bool)0);
}
}
static size_t __attribute__((__pure__))  compute_bucket_size(size_t candidate , Hash_tuning const   *tuning ) 
{ 
  float new_candidate ;
  int tmp ;

  {
  if (! tuning->is_n_buckets) {
    new_candidate = (float )((float const   )candidate / tuning->growth_threshold);
    if ((float )0xffffffffffffffffUL <= new_candidate) {
      return ((size_t __attribute__((__pure__))  )0);
    }
    candidate = (size_t )new_candidate;
  }
  candidate = next_prime(candidate);
  if (sizeof(ptrdiff_t ) <= sizeof(size_t )) {
    tmp = -1;
  } else {
    tmp = -2;
  }
  if ((size_t )tmp / sizeof(struct hash_entry *) < candidate) {
    return ((size_t __attribute__((__pure__))  )0);
  }
  return ((size_t __attribute__((__pure__))  )candidate);
}
}
Hash_table *( __attribute__((__warn_unused_result__)) hash_initialize)(size_t candidate ,
                                                                       Hash_tuning const   *tuning ,
                                                                       size_t (*hasher)(void const   * ,
                                                                                        size_t  ) ,
                                                                       _Bool (*comparator)(void const   * ,
                                                                                           void const   * ) ,
                                                                       void (*data_freer)(void * ) ) 
{ 
  Hash_table *table___0 ;
  _Bool tmp ;

  {
  if ((unsigned long )hasher == (unsigned long )((void *)0)) {
    hasher = & raw_hasher;
  }
  if ((unsigned long )comparator == (unsigned long )((void *)0)) {
    comparator = & raw_comparator;
  }
  table___0 = (Hash_table *)malloc(sizeof(*table___0));
  if ((unsigned long )table___0 == (unsigned long )((void *)0)) {
    return ((Hash_table *)((void *)0));
  }
  if (! tuning) {
    tuning = & default_tuning;
  }
  table___0->tuning = tuning;
  tmp = check_tuning(table___0);
  if (! tmp) {
    goto fail;
  }
  table___0->n_buckets = (size_t )compute_bucket_size(candidate, tuning);
  if (! table___0->n_buckets) {
    goto fail;
  }
  table___0->bucket = (struct hash_entry *)calloc(table___0->n_buckets, sizeof(*(table___0->bucket)));
  if ((unsigned long )table___0->bucket == (unsigned long )((void *)0)) {
    goto fail;
  }
  table___0->bucket_limit = (struct hash_entry  const  *)(table___0->bucket + table___0->n_buckets);
  table___0->n_buckets_used = (size_t )0;
  table___0->n_entries = (size_t )0;
  table___0->hasher = hasher;
  table___0->comparator = comparator;
  table___0->data_freer = data_freer;
  table___0->free_entry_list = (struct hash_entry *)((void *)0);
  return (table___0);
  fail: 
  free((void *)table___0);
  return ((Hash_table *)((void *)0));
}
}
static struct hash_entry *allocate_entry(Hash_table *table___0 ) 
{ 
  struct hash_entry *new ;

  {
  if (table___0->free_entry_list) {
    new = table___0->free_entry_list;
    table___0->free_entry_list = new->next;
  } else {
    new = (struct hash_entry *)malloc(sizeof(*new));
  }
  return (new);
}
}
static void free_entry(Hash_table *table___0 , struct hash_entry *entry ) 
{ 


  {
  entry->data = (void *)0;
  entry->next = table___0->free_entry_list;
  table___0->free_entry_list = entry;
  return;
}
}
static void *hash_find_entry(Hash_table *table___0 , void const   *entry , struct hash_entry **bucket_head ,
                             _Bool delete ) 
{ 
  struct hash_entry *bucket ;
  struct hash_entry *tmp ;
  struct hash_entry *cursor ;
  void *data ;
  struct hash_entry *next ;
  _Bool tmp___0 ;
  void *data___0 ;
  struct hash_entry *next___0 ;
  _Bool tmp___1 ;

  {
  tmp = safe_hasher((Hash_table const   *)table___0, entry);
  bucket = tmp;
  *bucket_head = bucket;
  if ((unsigned long )bucket->data == (unsigned long )((void *)0)) {
    return ((void *)0);
  }
  if ((unsigned long )entry == (unsigned long )bucket->data) {
    goto _L;
  } else {
    tmp___0 = (*(table___0->comparator))(entry, (void const   *)bucket->data);
    if (tmp___0) {
      _L: 
      data = bucket->data;
      if (delete) {
        if (bucket->next) {
          next = bucket->next;
          *bucket = *next;
          free_entry(table___0, next);
        } else {
          bucket->data = (void *)0;
        }
      }
      return (data);
    }
  }
  cursor = bucket;
  while (1) {

    if (! cursor->next) {
      goto while_break;
    }
    if ((unsigned long )entry == (unsigned long )(cursor->next)->data) {
      goto _L___0;
    } else {
      tmp___1 = (*(table___0->comparator))(entry, (void const   *)(cursor->next)->data);
      if (tmp___1) {
        _L___0: 
        data___0 = (cursor->next)->data;
        if (delete) {
          next___0 = cursor->next;
          cursor->next = next___0->next;
          free_entry(table___0, next___0);
        }
        return (data___0);
      }
    }
    cursor = cursor->next;
  }
  while_break: ;
  return ((void *)0);
}
}
static _Bool transfer_entries(Hash_table *dst , Hash_table *src , _Bool safe ) 
{ 
  struct hash_entry *bucket ;
  struct hash_entry *cursor ;
  struct hash_entry *next ;
  void *data ;
  struct hash_entry *new_bucket ;
  struct hash_entry *new_entry ;
  struct hash_entry *tmp ;

  {
  bucket = src->bucket;
  while (1) {

    if (! ((unsigned long )bucket < (unsigned long )src->bucket_limit)) {
      goto while_break;
    }
    if (bucket->data) {
      cursor = bucket->next;
      while (1) {

        if (! cursor) {
          goto while_break___0;
        }
        data = cursor->data;
        new_bucket = safe_hasher((Hash_table const   *)dst, (void const   *)data);
        next = cursor->next;
        if (new_bucket->data) {
          cursor->next = new_bucket->next;
          new_bucket->next = cursor;
        } else {
          new_bucket->data = data;
          (dst->n_buckets_used) ++;
          free_entry(dst, cursor);
        }
        cursor = next;
      }
      while_break___0: 
      data = bucket->data;
      bucket->next = (struct hash_entry *)((void *)0);
      if (safe) {
        goto __Cont;
      }
      new_bucket = safe_hasher((Hash_table const   *)dst, (void const   *)data);
      if (new_bucket->data) {
        tmp = allocate_entry(dst);
        new_entry = tmp;
        if ((unsigned long )new_entry == (unsigned long )((void *)0)) {
          return ((_Bool)0);
        }
        new_entry->data = data;
        new_entry->next = new_bucket->next;
        new_bucket->next = new_entry;
      } else {
        new_bucket->data = data;
        (dst->n_buckets_used) ++;
      }
      bucket->data = (void *)0;
      (src->n_buckets_used) --;
    }
    __Cont: 
    bucket ++;
  }
  while_break: ;
  return ((_Bool)1);
}
}
_Bool ( __attribute__((__warn_unused_result__)) hash_rehash)(Hash_table *table___0 ,
                                                             size_t candidate ) 
{ 
  Hash_table storage ;
  Hash_table *new_table ;
  size_t new_size ;
  size_t tmp ;
  _Bool tmp___0 ;
  _Bool tmp___1 ;
  _Bool tmp___2 ;

  {
  tmp = (size_t )compute_bucket_size(candidate, table___0->tuning);
  new_size = tmp;
  if (! new_size) {
    return ((_Bool)0);
  }
  if (new_size == table___0->n_buckets) {
    return ((_Bool)1);
  }
  new_table = & storage;
  new_table->bucket = (struct hash_entry *)calloc(new_size, sizeof(*(new_table->bucket)));
  if ((unsigned long )new_table->bucket == (unsigned long )((void *)0)) {
    return ((_Bool)0);
  }
  new_table->n_buckets = new_size;
  new_table->bucket_limit = (struct hash_entry  const  *)(new_table->bucket + new_size);
  new_table->n_buckets_used = (size_t )0;
  new_table->n_entries = (size_t )0;
  new_table->tuning = table___0->tuning;
  new_table->hasher = table___0->hasher;
  new_table->comparator = table___0->comparator;
  new_table->data_freer = table___0->data_freer;
  new_table->free_entry_list = table___0->free_entry_list;
  tmp___0 = transfer_entries(new_table, table___0, (_Bool)0);
  if (tmp___0) {
    free((void *)table___0->bucket);
    table___0->bucket = new_table->bucket;
    table___0->bucket_limit = new_table->bucket_limit;
    table___0->n_buckets = new_table->n_buckets;
    table___0->n_buckets_used = new_table->n_buckets_used;
    table___0->free_entry_list = new_table->free_entry_list;
    return ((_Bool)1);
  }
  table___0->free_entry_list = new_table->free_entry_list;
  tmp___1 = transfer_entries(table___0, new_table, (_Bool)1);
  if (tmp___1) {
    tmp___2 = transfer_entries(table___0, new_table, (_Bool)0);
    if (! tmp___2) {
      abort();
    }
  } else {
    abort();
  }
  free((void *)new_table->bucket);
  return ((_Bool)0);
}
}
int hash_insert_if_absent(Hash_table *table___0 , void const   *entry , void const   **matched_ent ) 
{ 
  void *data ;
  struct hash_entry *bucket ;
  Hash_tuning const   *tuning ;
  float candidate ;
  float tmp ;
  _Bool tmp___0 ;
  void *tmp___1 ;
  struct hash_entry *new_entry ;
  struct hash_entry *tmp___2 ;

  {
  if (! entry) {
    abort();
  }
  data = hash_find_entry(table___0, entry, & bucket, (_Bool)0);
  if ((unsigned long )data != (unsigned long )((void *)0)) {
    if (matched_ent) {
      *matched_ent = (void const   *)data;
    }
    return (0);
  }
  if ((float const   )table___0->n_buckets_used > (table___0->tuning)->growth_threshold * (float const   )table___0->n_buckets) {
    check_tuning(table___0);
    if ((float const   )table___0->n_buckets_used > (table___0->tuning)->growth_threshold * (float const   )table___0->n_buckets) {
      tuning = table___0->tuning;
      if (tuning->is_n_buckets) {
        tmp = (float )((float const   )table___0->n_buckets * tuning->growth_factor);
      } else {
        tmp = (float )(((float const   )table___0->n_buckets * tuning->growth_factor) * tuning->growth_threshold);
      }
      candidate = tmp;
      if ((float )0xffffffffffffffffUL <= candidate) {
        return (-1);
      }
      tmp___0 = hash_rehash(table___0, (size_t )candidate);
      if (! tmp___0) {
        return (-1);
      }
      tmp___1 = hash_find_entry(table___0, entry, & bucket, (_Bool)0);
      if ((unsigned long )tmp___1 != (unsigned long )((void *)0)) {
        abort();
      }
    }
  }
  if (bucket->data) {
    tmp___2 = allocate_entry(table___0);
    new_entry = tmp___2;
    if ((unsigned long )new_entry == (unsigned long )((void *)0)) {
      return (-1);
    }
    new_entry->data = (void *)entry;
    new_entry->next = bucket->next;
    bucket->next = new_entry;
    (table___0->n_entries) ++;
    return (1);
  }
  bucket->data = (void *)entry;
  (table___0->n_entries) ++;
  (table___0->n_buckets_used) ++;
  return (1);
}
}
void *( __attribute__((__warn_unused_result__)) hash_insert)(Hash_table *table___0 ,
                                                             void const   *entry ) 
{ 
  void const   *matched_ent ;
  int err ;
  int tmp ;
  void const   *tmp___0 ;
  void *tmp___1 ;

  {
  tmp = hash_insert_if_absent(table___0, entry, & matched_ent);
  err = tmp;
  if (err == -1) {
    tmp___1 = (void *)0;
  } else {
    if (err == 0) {
      tmp___0 = matched_ent;
    } else {
      tmp___0 = entry;
    }
    tmp___1 = (void *)tmp___0;
  }
  return (tmp___1);
}
}
void *hash_delete(Hash_table *table___0 , void const   *entry ) 
{ 
  void *data ;
  struct hash_entry *bucket ;
  Hash_tuning const   *tuning ;
  size_t candidate ;
  float tmp ;
  struct hash_entry *cursor ;
  struct hash_entry *next ;
  _Bool tmp___0 ;

  {
  data = hash_find_entry(table___0, entry, & bucket, (_Bool)1);
  if (! data) {
    return ((void *)0);
  }
  (table___0->n_entries) --;
  if (! bucket->data) {
    (table___0->n_buckets_used) --;
    if ((float const   )table___0->n_buckets_used < (table___0->tuning)->shrink_threshold * (float const   )table___0->n_buckets) {
      check_tuning(table___0);
      if ((float const   )table___0->n_buckets_used < (table___0->tuning)->shrink_threshold * (float const   )table___0->n_buckets) {
        tuning = table___0->tuning;
        if (tuning->is_n_buckets) {
          tmp = (float )((float const   )table___0->n_buckets * tuning->shrink_factor);
        } else {
          tmp = (float )(((float const   )table___0->n_buckets * tuning->shrink_factor) * tuning->growth_threshold);
        }
        candidate = (size_t )tmp;
        tmp___0 = hash_rehash(table___0, candidate);
        if (! tmp___0) {
          cursor = table___0->free_entry_list;
          while (1) {

            if (! cursor) {
              goto while_break;
            }
            next = cursor->next;
            free((void *)cursor);
            cursor = next;
          }
          while_break: 
          table___0->free_entry_list = (struct hash_entry *)((void *)0);
        }
      }
    }
  }
  return (data);
}
}
size_t hash_pjw(void const   *x , size_t tablesize )  __attribute__((__pure__)) ;
size_t triple_hash(void const   *x , size_t table_size )  __attribute__((__pure__)) ;
size_t triple_hash(void const   *x , size_t table_size ) 
{ 
  struct F_triple  const  *p ;
  size_t tmp ;
  size_t tmp___0 ;

  {
  p = (struct F_triple  const  *)x;
  tmp___0 = hash_pjw((void const   *)p->name, table_size);
  tmp = tmp___0;
  return ((tmp ^ (unsigned long )p->st_ino) % table_size);
}
}
_Bool triple_compare_ino_str(void const   *x , void const   *y )  __attribute__((__pure__)) ;
_Bool triple_compare_ino_str(void const   *x , void const   *y ) 
{ 
  struct F_triple  const  *a ;
  struct F_triple  const  *b ;
  int tmp___0 ;
  int tmp___1 ;

  {
  a = (struct F_triple  const  *)x;
  b = (struct F_triple  const  *)y;
  if (a->st_ino == b->st_ino) {
    if (a->st_dev == b->st_dev) {
      tmp___1 = strcmp((char const   *)a->name, (char const   *)b->name);
      if (tmp___1 == 0) {
        tmp___0 = 1;
      } else {
        tmp___0 = 0;
      }
    } else {
      tmp___0 = 0;
    }
  } else {
    tmp___0 = 0;
  }
  return ((_Bool )tmp___0);
}
}
size_t hash_pjw(void const   *x , size_t tablesize )  __attribute__((__pure__)) ;
size_t hash_pjw(void const   *x , size_t tablesize ) 
{ 
  char const   *s ;
  size_t h ;

  {
  h = (size_t )0;
  s = (char const   *)x;
  while (1) {

    if (! *s) {
      goto while_break;
    }
    h = (unsigned long )*s + ((h << 9) | (h >> (sizeof(size_t ) * 8UL - 9UL)));
    s ++;
  }
  while_break: ;
  return (h % tablesize);
}
}
_Bool hard_locale(int category ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) setlocale)(int __category ,
                                                                                  char const   *__locale ) ;
_Bool hard_locale(int category ) 
{ 
  _Bool hard ;
  char const   *p ;
  char const   *tmp ;
  int tmp___0 ;
  int tmp___1 ;
  char *locale ;
  char *tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;

  {
  hard = (_Bool)1;
  tmp = (char const   *)setlocale(category, (char const   *)((void *)0));
  p = tmp;
  if (p) {
    if (1) {
      tmp___0 = strcmp(p, "C");
      if (tmp___0 == 0) {
        hard = (_Bool)0;
      } else {
        tmp___1 = strcmp(p, "POSIX");
        if (tmp___1 == 0) {
          hard = (_Bool)0;
        }
      }
    } else {
      tmp___2 = strdup(p);
      locale = tmp___2;
      if (locale) {
        p = (char const   *)setlocale(category, "C");
        if (p) {
          tmp___3 = strcmp(p, (char const   *)locale);
          if (tmp___3 == 0) {
            hard = (_Bool)0;
          } else {
            goto _L;
          }
        } else {
          _L: 
          p = (char const   *)setlocale(category, "POSIX");
          if (p) {
            tmp___4 = strcmp(p, (char const   *)locale);
            if (tmp___4 == 0) {
              hard = (_Bool)0;
            }
          }
        }
        setlocale(category, (char const   *)locale);
        free((void *)locale);
      }
    }
  }
  return (hard);
}
}
extern int fflush_unlocked(FILE *__stream ) ;
extern void ( __attribute__((__nonnull__(1,4))) qsort)(void *__base , size_t __nmemb ,
                                                       size_t __size , int (*__compar)(void const   * ,
                                                                                       void const   * ) ) ;
extern int fseeko(FILE *__stream , __off_t __off , int __whence ) ;
extern  __attribute__((__nothrow__)) __off_t ( __attribute__((__leaf__)) lseek)(int __fd ,
                                                                                __off_t __offset ,
                                                                                int __whence ) ;
int ( __attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp , off_t offset , int whence ) 
{ 
  off_t pos ;
  int tmp ;
  off_t tmp___0 ;
  int tmp___1 ;

  {
  if ((unsigned long )fp->_IO_read_end == (unsigned long )fp->_IO_read_ptr) {
    if ((unsigned long )fp->_IO_write_ptr == (unsigned long )fp->_IO_write_base) {
      if ((unsigned long )fp->_IO_save_base == (unsigned long )((void *)0)) {
        tmp = fileno(fp);
        tmp___0 = lseek(tmp, offset, whence);
        pos = tmp___0;
        if (pos == -1L) {
          return (-1);
        }
        fp->_flags &= -17;
        fp->_offset = pos;
        return (0);
      }
    }
  }
  tmp___1 = fseeko(fp, offset, whence);
  return (tmp___1);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) dup2)(int __fd ,
                                                                           int __fd2 ) ;
FILE *fopen_safer(char const   *file , char const   *mode ) 
{ 
  FILE *fp ;
  FILE *tmp ;
  int fd ;
  int tmp___0 ;
  int f ;
  int tmp___1 ;
  int e ;
  int *tmp___2 ;
  int *tmp___3 ;
  int e___0 ;
  int *tmp___4 ;
  int *tmp___5 ;
  int tmp___6 ;

  {
  tmp = fopen(file, mode);
  fp = tmp;
  if (fp) {
    tmp___0 = fileno(fp);
    fd = tmp___0;
    if (0 <= fd) {
      if (fd <= 2) {
        tmp___1 = dup_safer(fd);
        f = tmp___1;
        if (f < 0) {
          tmp___2 = __errno_location();
          e = *tmp___2;
          rpl_fclose(fp);
          tmp___3 = __errno_location();
          *tmp___3 = e;
          return ((FILE *)((void *)0));
        }
        tmp___6 = rpl_fclose(fp);
        if (tmp___6 != 0) {
          goto _L;
        } else {
          fp = fdopen(f, mode);
          if (! fp) {
            _L: 
            tmp___4 = __errno_location();
            e___0 = *tmp___4;
            close(f);
            tmp___5 = __errno_location();
            *tmp___5 = e___0;
            return ((FILE *)((void *)0));
          }
        }
      }
    }
  }
  return (fp);
}
}
int filevercmp(char const   *s1 , char const   *s2 ) ;
static char const   *match_suffix(char const   **str ) 
{ 
  char const   *match ;
  _Bool read_alpha ;
  _Bool tmp ;
  _Bool tmp___0 ;

  {
  match = (char const   *)((void *)0);
  read_alpha = (_Bool)0;
  while (1) {

    if (! *(*str)) {
      goto while_break;
    }
    if (read_alpha) {
      read_alpha = (_Bool)0;
      tmp = c_isalpha((int )*(*str));
      if (! tmp) {
        if (126 != (int )*(*str)) {
          match = (char const   *)((void *)0);
        }
      }
    } else
    if (46 == (int )*(*str)) {
      read_alpha = (_Bool)1;
      if (! match) {
        match = *str;
      }
    } else {
      tmp___0 = c_isalnum((int )*(*str));
      if (! tmp___0) {
        if (126 != (int )*(*str)) {
          match = (char const   *)((void *)0);
        }
      }
    }
    (*str) ++;
  }
  while_break: ;
  return (match);
}
}
__inline static int order(unsigned char c ) 
{ 
  _Bool tmp ;
  _Bool tmp___0 ;

  {
  tmp___0 = c_isdigit((int )c);
  if (tmp___0) {
    return (0);
  } else {
    tmp = c_isalpha((int )c);
    if (tmp) {
      return ((int )c);
    } else
    if ((int )c == 126) {
      return (-1);
    } else {
      return (((int )c + 255) + 1);
    }
  }
}
}
static int __attribute__((__pure__))  verrevcmp(char const   *s1 , size_t s1_len ,
                                                char const   *s2 , size_t s2_len ) 
{ 
  size_t s1_pos ;
  size_t s2_pos ;
  int first_diff ;
  int s1_c ;
  int tmp ;
  int tmp___0 ;
  int s2_c ;
  int tmp___1 ;
  int tmp___2 ;
  _Bool tmp___3 ;
  _Bool tmp___4 ;
  _Bool tmp___5 ;
  _Bool tmp___6 ;
  _Bool tmp___7 ;
  _Bool tmp___8 ;

  {
  s1_pos = (size_t )0;
  s2_pos = (size_t )0;
  while (1) {

    if (! (s1_pos < s1_len)) {
      if (! (s2_pos < s2_len)) {
        goto while_break;
      }
    }
    first_diff = 0;
    while (1) {

      if (s1_pos < s1_len) {
        tmp___3 = c_isdigit((int )*(s1 + s1_pos));
        if (tmp___3) {
          goto _L;
        }
      } else
      _L: 
      if (s2_pos < s2_len) {
        tmp___4 = c_isdigit((int )*(s2 + s2_pos));
        if (tmp___4) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      if (s1_pos == s1_len) {
        tmp___0 = 0;
      } else {
        tmp = order((unsigned char )*(s1 + s1_pos));
        tmp___0 = tmp;
      }
      s1_c = tmp___0;
      if (s2_pos == s2_len) {
        tmp___2 = 0;
      } else {
        tmp___1 = order((unsigned char )*(s2 + s2_pos));
        tmp___2 = tmp___1;
      }
      s2_c = tmp___2;
      if (s1_c != s2_c) {
        return ((int __attribute__((__pure__))  )(s1_c - s2_c));
      }
      s1_pos ++;
      s2_pos ++;
    }
    while_break___0: ;
    while (1) {

      if (! ((int const   )*(s1 + s1_pos) == 48)) {
        goto while_break___1;
      }
      s1_pos ++;
    }
    while_break___1: ;
    while (1) {

      if (! ((int const   )*(s2 + s2_pos) == 48)) {
        goto while_break___2;
      }
      s2_pos ++;
    }
    while_break___2: ;
    while (1) {
      tmp___5 = c_isdigit((int )*(s1 + s1_pos));
      if (tmp___5) {
        tmp___6 = c_isdigit((int )*(s2 + s2_pos));
        if (! tmp___6) {
          goto while_break___3;
        }
      } else {
        goto while_break___3;
      }
      if (! first_diff) {
        first_diff = (int )((int const   )*(s1 + s1_pos) - (int const   )*(s2 + s2_pos));
      }
      s1_pos ++;
      s2_pos ++;
    }
    while_break___3: 
    tmp___7 = c_isdigit((int )*(s1 + s1_pos));
    if (tmp___7) {
      return ((int __attribute__((__pure__))  )1);
    }
    tmp___8 = c_isdigit((int )*(s2 + s2_pos));
    if (tmp___8) {
      return ((int __attribute__((__pure__))  )-1);
    }
    if (first_diff) {
      return ((int __attribute__((__pure__))  )first_diff);
    }
  }
  while_break: ;
  return ((int __attribute__((__pure__))  )0);
}
}
int filevercmp(char const   *s1 , char const   *s2 ) 
{ 
  char const   *s1_pos ;
  char const   *s2_pos ;
  char const   *s1_suffix ;
  char const   *s2_suffix ;
  size_t s1_len ;
  size_t s2_len ;
  int result ;
  int simple_cmp ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  char const   *tmp___4 ;
  char const   *tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;

  {
  tmp = strcmp(s1, s2);
  simple_cmp = tmp;
  if (simple_cmp == 0) {
    return (0);
  }
  if (! *s1) {
    return (-1);
  }
  if (! *s2) {
    return (1);
  }
  tmp___0 = strcmp(".", s1);
  if (0 == tmp___0) {
    return (-1);
  }
  tmp___1 = strcmp(".", s2);
  if (0 == tmp___1) {
    return (1);
  }
  tmp___2 = strcmp("..", s1);
  if (0 == tmp___2) {
    return (-1);
  }
  tmp___3 = strcmp("..", s2);
  if (0 == tmp___3) {
    return (1);
  }
  if ((int const   )*s1 == 46) {
    if ((int const   )*s2 != 46) {
      return (-1);
    }
  }
  if ((int const   )*s1 != 46) {
    if ((int const   )*s2 == 46) {
      return (1);
    }
  }
  if ((int const   )*s1 == 46) {
    if ((int const   )*s2 == 46) {
      s1 ++;
      s2 ++;
    }
  }
  s1_pos = s1;
  s2_pos = s2;
  s1_suffix = match_suffix(& s1_pos);
  s2_suffix = match_suffix(& s2_pos);
  if (s1_suffix) {
    tmp___4 = s1_suffix;
  } else {
    tmp___4 = s1_pos;
  }
  s1_len = (size_t )(tmp___4 - s1);
  if (s2_suffix) {
    tmp___5 = s2_suffix;
  } else {
    tmp___5 = s2_pos;
  }
  s2_len = (size_t )(tmp___5 - s2);
  if (s1_suffix) {
    goto _L;
  } else
  if (s2_suffix) {
    _L: 
    if (s1_len == s2_len) {
      tmp___6 = strncmp(s1, s2, s1_len);
      if (0 == tmp___6) {
        s1_len = (size_t )(s1_pos - s1);
        s2_len = (size_t )(s2_pos - s2);
      }
    }
  }
  result = (int )verrevcmp(s1, s1_len, s2, s2_len);
  if (result == 0) {
    tmp___7 = simple_cmp;
  } else {
    tmp___7 = result;
  }
  return (tmp___7);
}
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
extern int fflush(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __freading)(FILE *__fp ) ;
__inline static void clear_ungetc_buffer_preserving_position(FILE *fp ) 
{ 


  {
  if (fp->_flags & 256) {
    rpl_fseeko(fp, (off_t )0, 1);
  }
  return;
}
}
int rpl_fflush(FILE *stream ) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  if ((unsigned long )stream == (unsigned long )((void *)0)) {
    tmp = fflush(stream);
    return (tmp);
  } else {
    tmp___0 = __freading(stream);
    if (! (tmp___0 != 0)) {
      tmp = fflush(stream);
      return (tmp);
    }
  }
  clear_ungetc_buffer_preserving_position(stream);
  tmp___1 = fflush(stream);
  return (tmp___1);
}
}
int fd_safer(int fd ) 
{ 
  int f ;
  int tmp ;
  int e ;
  int *tmp___0 ;
  int *tmp___1 ;

  {
  if (0 <= fd) {
    if (fd <= 2) {
      tmp = dup_safer(fd);
      f = tmp;
      tmp___0 = __errno_location();
      e = *tmp___0;
      close(fd);
      tmp___1 = __errno_location();
      *tmp___1 = e;
      fd = f;
    }
  }
  return (fd);
}
}
extern int fcntl(int __fd , int __cmd  , ...) ;
static int have_dupfd_cloexec  =    0;
int rpl_fcntl(int fd , int action  , ...) 
{ 
  va_list arg ;
  int result ;
  int target ;
  int tmp ;
  int *tmp___0 ;
  int flags ;
  int tmp___1 ;
  int saved_errno ;
  int *tmp___2 ;
  int *tmp___3 ;
  int tmp___4 ;
  void *p ;
  void *tmp___5 ;

  {
  result = -1;
  __builtin_va_start(arg, action);
  if (action == 1030) {
    goto case_1030;
  }
  goto switch_default;
  case_1030: 
  tmp = __builtin_va_arg(arg, int );
  target = tmp;
  if (0 <= have_dupfd_cloexec) {
    result = fcntl(fd, action, target);
    if (0 <= result) {
      have_dupfd_cloexec = 1;
    } else {
      tmp___0 = __errno_location();
      if (*tmp___0 != 22) {
        have_dupfd_cloexec = 1;
      } else {
        result = rpl_fcntl(fd, 0, target);
        if (result < 0) {
          goto switch_break;
        }
        have_dupfd_cloexec = -1;
      }
    }
  } else {
    result = rpl_fcntl(fd, 0, target);
  }
  if (0 <= result) {
    if (have_dupfd_cloexec == -1) {
      tmp___1 = fcntl(result, 1);
      flags = tmp___1;
      if (flags < 0) {
        goto _L;
      } else {
        tmp___4 = fcntl(result, 2, flags | 1);
        if (tmp___4 == -1) {
          _L: 
          tmp___2 = __errno_location();
          saved_errno = *tmp___2;
          close(result);
          tmp___3 = __errno_location();
          *tmp___3 = saved_errno;
          result = -1;
        }
      }
    }
  }
  goto switch_break;
  switch_default: 
  tmp___5 = __builtin_va_arg(arg, void *);
  p = tmp___5;
  result = fcntl(fd, action, p);
  goto switch_break;
  switch_break: 
  __builtin_va_end(arg);
  return (result);
}
}
extern int fclose(FILE *__stream ) ;
int ( __attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp ) 
{ 
  int saved_errno ;
  int fd ;
  int result ;
  int tmp ;
  int *tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  __off_t tmp___3 ;
  int tmp___4 ;
  int *tmp___5 ;

  {
  saved_errno = 0;
  result = 0;
  fd = fileno(fp);
  if (fd < 0) {
    tmp = fclose(fp);
    return (tmp);
  }
  tmp___1 = __freading(fp);
  if (tmp___1 != 0) {
    tmp___2 = fileno(fp);
    tmp___3 = lseek(tmp___2, (__off_t )0, 1);
    if (tmp___3 != -1L) {
      _L: 
      tmp___4 = rpl_fflush(fp);
      if (tmp___4) {
        tmp___0 = __errno_location();
        saved_errno = *tmp___0;
      }
    }
  } else {
    goto _L;
  }
  result = fclose(fp);
  if (saved_errno != 0) {
    tmp___5 = __errno_location();
    *tmp___5 = saved_errno;
    result = -1;
  }
  return (result);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) sigemptyset)(sigset_t *__set ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) sigaddset)(sigset_t *__set ,
                                                                                                int __signo ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) sigaction)(int __sig ,
                                                                                struct sigaction  const  * __restrict  __act ,
                                                                                struct sigaction * __restrict  __oact ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) posix_fadvise)(int __fd ,
                                                                                    off_t __offset ,
                                                                                    off_t __len ,
                                                                                    int __advise ) ;
void fdadvise(int fd , off_t offset , off_t len , fadvice_t advice ) ;
void fadvise(FILE *fp , fadvice_t advice ) ;
void fdadvise(int fd , off_t offset , off_t len , fadvice_t advice ) 
{ 
  int __x ;
  int tmp ;

  {
  tmp = posix_fadvise(fd, offset, len, (int )advice);
  __x = tmp;
  return;
}
}
void fadvise(FILE *fp , fadvice_t advice ) 
{ 
  int tmp ;

  {
  if (fp) {
    tmp = fileno(fp);
    fdadvise(tmp, (off_t )0, (off_t )0, advice);
  }
  return;
}
}
int volatile   exit_failure  =    (int volatile   )1;
int dup_safer(int fd ) 
{ 
  int tmp ;

  {
  tmp = rpl_fcntl(fd, 0, 3);
  return (tmp);
}
}
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma weak pthread_mutex_init
#pragma weak pthread_mutex_lock
#pragma weak pthread_mutex_unlock
#pragma weak pthread_mutex_destroy
#pragma weak pthread_rwlock_init
#pragma weak pthread_rwlock_rdlock
#pragma weak pthread_rwlock_wrlock
#pragma weak pthread_rwlock_unlock
#pragma weak pthread_rwlock_destroy
#pragma weak pthread_once
#pragma weak pthread_cond_init
#pragma weak pthread_cond_wait
#pragma weak pthread_cond_signal
#pragma weak pthread_cond_broadcast
#pragma weak pthread_cond_destroy
#pragma weak pthread_mutexattr_init
#pragma weak pthread_mutexattr_settype
#pragma weak pthread_mutexattr_destroy
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
char const   *Version  =    "8.16";
extern char *optarg ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,3))) pthread_create)(pthread_t * __restrict  __newthread ,
                                                                                             pthread_attr_t const   * __restrict  __attr ,
                                                                                             void *(*__start_routine)(void * ) ,
                                                                                             void * __restrict  __arg ) ;
extern int pthread_join(pthread_t __th , void **__thread_return ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_destroy)(pthread_mutex_t *__mutex ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) pthread_mutex_lock)(pthread_mutex_t *__mutex ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) pthread_mutex_unlock)(pthread_mutex_t *__mutex ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) pthread_cond_init)(pthread_cond_t * __restrict  __cond ,
                                                                                                        pthread_condattr_t const   * __restrict  __cond_attr ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) pthread_cond_destroy)(pthread_cond_t *__cond ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) pthread_cond_signal)(pthread_cond_t *__cond ) ;
extern int ( __attribute__((__nonnull__(1,2))) pthread_cond_wait)(pthread_cond_t * __restrict  __cond ,
                                                                  pthread_mutex_t * __restrict  __mutex ) ;
extern  __attribute__((__nothrow__)) __sighandler_t ( __attribute__((__leaf__)) signal)(int __sig ,
                                                                                        void (*__handler)(int  ) ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1), __leaf__)) sigismember)(sigset_t const   *__set ,
                                                                                                  int __signo ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2), __leaf__)) execlp)(char const   *__file ,
                                                                                               char const   *__arg 
                                                                                               , ...) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(2), __leaf__)) strxfrm)(char * __restrict  __dest ,
                                                                                                 char const   * __restrict  __src ,
                                                                                                 size_t __n ) ;
__inline static void initialize_exit_failure(int status ) 
{ 


  {
  if (status != 1) {
    exit_failure = (int volatile   )status;
  }
  return;
}
}
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) ngettext)(char const   *__msgid1 ,
                                                                                 char const   *__msgid2 ,
                                                                                 unsigned long __n )  __attribute__((__format_arg__(2),
__format_arg__(1))) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) textdomain)(char const   *__domainname ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) bindtextdomain)(char const   *__domainname ,
                                                                                       char const   *__dirname ) ;
__inline static unsigned long select_plural(uintmax_t n ) 
{ 
  uintmax_t tmp ;

  {
  if (n <= 0xffffffffffffffffUL) {
    tmp = n;
  } else {
    tmp = n % 1000000UL + 1000000UL;
  }
  return (tmp);
}
}
extern int fputc_unlocked(int __c , FILE *__stream ) ;
extern int putchar_unlocked(int __c ) ;
extern size_t fwrite_unlocked(void const   * __restrict  __ptr , size_t __size , size_t __n ,
                              FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) clearerr_unlocked)(FILE *__stream ) ;
__inline static void emit_ancillary_info(void) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char const   *lc_messages ;
  char const   *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  int tmp___6 ;
  char *tmp___7 ;
  char *tmp___8 ;

  {
  tmp = last_component(program_name);
  tmp___0 = gettext("\nReport %s bugs to %s\n");
  printf((char const   *)tmp___0, tmp, "bug-coreutils@gnu.org");
  tmp___1 = gettext("%s home page: <%s>\n");
  printf((char const   *)tmp___1, "GNU coreutils", "http://www.gnu.org/software/coreutils/");
  tmp___2 = gettext("General help using GNU software: <http://www.gnu.org/gethelp/>\n");
  fputs_unlocked((char const   *)tmp___2, stdout);
  tmp___3 = (char const   *)setlocale(5, (char const   *)((void *)0));
  lc_messages = tmp___3;
  if (lc_messages) {
    tmp___6 = strncmp(lc_messages, "en_", sizeof("en_") - 1UL);
    if (tmp___6) {
      tmp___4 = last_component(program_name);
      tmp___5 = gettext("Report %s translation bugs to <http://translationproject.org/team/>\n");
      printf((char const   *)tmp___5, tmp___4);
    }
  }
  tmp___7 = last_component(program_name);
  tmp___8 = gettext("For complete documentation, run: info coreutils \'%s invocation\'\n");
  printf((char const   *)tmp___8, tmp___7);
  return;
}
}
__inline static void emit_try_help(void) 
{ 
  char *tmp ;

  {
  tmp = gettext("Try \'%s --help\' for more information.\n");
  fprintf(stderr, (char const   *)tmp, program_name);
  return;
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) getrlimit)(__rlimit_resource_t __resource ,
                                                                                struct rlimit *__rlimits ) ;
static int decimal_point  ;
static int thousands_sep  ;
static _Bool hard_LC_COLLATE  ;
static _Bool hard_LC_TIME  ;
static char eolchar  =    (char )'\n';
static _Bool blanks[256]  ;
static _Bool nonprinting[256]  ;
static _Bool nondictionary[256]  ;
static char fold_toupper[256]  ;
static struct month monthtab[12]  = 
  {      {"APR", 4}, 
        {"AUG", 8}, 
        {"DEC", 12}, 
        {"FEB", 2}, 
        {"JAN", 1}, 
        {"JUL", 7}, 
        {"JUN", 6}, 
        {"MAR", 3}, 
        {"MAY", 5}, 
        {"NOV", 11}, 
        {"OCT", 10}, 
        {"SEP", 9}};
static size_t merge_buffer_size  =    (size_t )262144;
static size_t sort_size  ;
static char const   **temp_dirs  ;
static size_t temp_dir_count  ;
static size_t temp_dir_alloc  ;
static _Bool reverse  ;
static _Bool stable  ;
static int tab  =    128;
static _Bool unique  ;
static _Bool have_read_stdin  ;
static struct keyfield *keylist  ;
static char const   *compress_program  ;
static _Bool debug  ;
static unsigned int nmerge  =    16U;
static  __attribute__((__noreturn__)) void die(char const   *message , char const   *file ) ;
static  __attribute__((__noreturn__)) void die(char const   *message , char const   *file ) ;
static void die(char const   *message , char const   *file ) 
{ 
  char *tmp ;
  char const   *tmp___0 ;
  int *tmp___1 ;

  {
  if (file) {
    tmp___0 = file;
  } else {
    tmp = gettext("standard output");
    tmp___0 = (char const   *)tmp;
  }
  tmp___1 = __errno_location();
  error(0, *tmp___1, "%s: %s", message, tmp___0);
  exit(2);
}
}
 __attribute__((__noreturn__)) void usage(int status ) ;
void usage(int status ) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  char *tmp___6 ;
  char *tmp___7 ;
  char *tmp___8 ;
  char *tmp___9 ;
  char *tmp___10 ;
  char *tmp___11 ;
  char *tmp___12 ;
  char *tmp___13 ;
  char *tmp___14 ;
  char *tmp___15 ;
  char *tmp___16 ;
  char *tmp___17 ;
  char *tmp___18 ;
  char *tmp___19 ;

  {
  if (status != 0) {
    emit_try_help();
  } else {
    tmp = gettext("Usage: %s [OPTION]... [FILE]...\n  or:  %s [OPTION]... --files0-from=F\n");
    printf((char const   *)tmp, program_name, program_name);
    tmp___0 = gettext("Write sorted concatenation of all FILE(s) to standard output.\n\n");
    fputs_unlocked((char const   *)tmp___0, stdout);
    tmp___1 = gettext("Mandatory arguments to long options are mandatory for short options too.\n");
    fputs_unlocked((char const   *)tmp___1, stdout);
    tmp___2 = gettext("Ordering options:\n\n");
    fputs_unlocked((char const   *)tmp___2, stdout);
    tmp___3 = gettext("  -b, --ignore-leading-blanks  ignore leading blanks\n  -d, --dictionary-order      consider only blanks and alphanumeric characters\n  -f, --ignore-case           fold lower case to upper case characters\n");
    fputs_unlocked((char const   *)tmp___3, stdout);
    tmp___4 = gettext("  -g, --general-numeric-sort  compare according to general numerical value\n  -i, --ignore-nonprinting    consider only printable characters\n  -M, --month-sort            compare (unknown) < \'JAN\' < ... < \'DEC\'\n");
    fputs_unlocked((char const   *)tmp___4, stdout);
    tmp___5 = gettext("  -h, --human-numeric-sort    compare human readable numbers (e.g., 2K 1G)\n");
    fputs_unlocked((char const   *)tmp___5, stdout);
    tmp___6 = gettext("  -n, --numeric-sort          compare according to string numerical value\n  -R, --random-sort           sort by random hash of keys\n      --random-source=FILE    get random bytes from FILE\n  -r, --reverse               reverse the result of comparisons\n");
    fputs_unlocked((char const   *)tmp___6, stdout);
    tmp___7 = gettext("      --sort=WORD             sort according to WORD:\n                                general-numeric -g, human-numeric -h, month -M,\n                                numeric -n, random -R, version -V\n  -V, --version-sort          natural sort of (version) numbers within text\n\n");
    fputs_unlocked((char const   *)tmp___7, stdout);
    tmp___8 = gettext("Other options:\n\n");
    fputs_unlocked((char const   *)tmp___8, stdout);
    tmp___9 = gettext("      --batch-size=NMERGE   merge at most NMERGE inputs at once;\n                            for more use temp files\n");
    fputs_unlocked((char const   *)tmp___9, stdout);
    tmp___10 = gettext("  -c, --check, --check=diagnose-first  check for sorted input; do not sort\n  -C, --check=quiet, --check=silent  like -c, but do not report first bad line\n      --compress-program=PROG  compress temporaries with PROG;\n                              decompress them with PROG -d\n");
    fputs_unlocked((char const   *)tmp___10, stdout);
    tmp___11 = gettext("      --debug               annotate the part of the line used to sort,\n                              and warn about questionable usage to stderr\n      --files0-from=F       read input from the files specified by\n                            NUL-terminated names in file F;\n                            If F is - then read names from standard input\n");
    fputs_unlocked((char const   *)tmp___11, stdout);
    tmp___12 = gettext("  -k, --key=KEYDEF          sort via a key; KEYDEF gives location and type\n  -m, --merge               merge already sorted files; do not sort\n");
    fputs_unlocked((char const   *)tmp___12, stdout);
    tmp___13 = gettext("  -o, --output=FILE         write result to FILE instead of standard output\n  -s, --stable              stabilize sort by disabling last-resort comparison\n  -S, --buffer-size=SIZE    use SIZE for main memory buffer\n");
    fputs_unlocked((char const   *)tmp___13, stdout);
    tmp___14 = gettext("  -t, --field-separator=SEP  use SEP instead of non-blank to blank transition\n  -T, --temporary-directory=DIR  use DIR for temporaries, not $TMPDIR or %s;\n                              multiple options specify multiple directories\n      --parallel=N          change the number of sorts run concurrently to N\n  -u, --unique              with -c, check for strict ordering;\n                              without -c, output only the first of an equal run\n");
    printf((char const   *)tmp___14, "/tmp");
    tmp___15 = gettext("  -z, --zero-terminated     end lines with 0 byte, not newline\n");
    fputs_unlocked((char const   *)tmp___15, stdout);
    tmp___16 = gettext("      --help     display this help and exit\n");
    fputs_unlocked((char const   *)tmp___16, stdout);
    tmp___17 = gettext("      --version  output version information and exit\n");
    fputs_unlocked((char const   *)tmp___17, stdout);
    tmp___18 = gettext("\nKEYDEF is F[.C][OPTS][,F[.C][OPTS]] for start and stop position, where F is a\nfield number and C a character position in the field; both are origin 1, and\nthe stop position defaults to the line\'s end.  If neither -t nor -b is in\neffect, characters in a field are counted from the beginning of the preceding\nwhitespace.  OPTS is one or more single-letter ordering options [bdfgiMhnRrV],\nwhich override global ordering options for that key.  If no key is given, use\nthe entire line as the key.\n\nSIZE may be followed by the following multiplicative suffixes:\n");
    fputs_unlocked((char const   *)tmp___18, stdout);
    tmp___19 = gettext("% 1% of memory, b 1, K 1024 (default), and so on for M, G, T, P, E, Z, Y.\n\nWith no FILE, or when FILE is -, read standard input.\n\n*** WARNING ***\nThe locale specified by the environment affects sort order.\nSet LC_ALL=C to get the traditional sort order that uses\nnative byte values.\n");
    fputs_unlocked((char const   *)tmp___19, stdout);
    emit_ancillary_info();
  }
  exit(status);
}
}
static char const   short_options[31]  = 
  {      (char const   )'-',      (char const   )'b',      (char const   )'c',      (char const   )'C', 
        (char const   )'d',      (char const   )'f',      (char const   )'g',      (char const   )'h', 
        (char const   )'i',      (char const   )'k',      (char const   )':',      (char const   )'m', 
        (char const   )'M',      (char const   )'n',      (char const   )'o',      (char const   )':', 
        (char const   )'r',      (char const   )'R',      (char const   )'s',      (char const   )'S', 
        (char const   )':',      (char const   )'t',      (char const   )':',      (char const   )'T', 
        (char const   )':',      (char const   )'u',      (char const   )'V',      (char const   )'y', 
        (char const   )':',      (char const   )'z',      (char const   )'\000'};
static struct option  const  long_options___1[31]  = 
  {      {"ignore-leading-blanks", 0, (int *)((void *)0), 'b'}, 
        {"check", 2, (int *)((void *)0), 128}, 
        {"compress-program", 1, (int *)((void *)0), 129}, 
        {"debug", 0, (int *)((void *)0), 130}, 
        {"dictionary-order", 0, (int *)((void *)0), 'd'}, 
        {"ignore-case", 0, (int *)((void *)0), 'f'}, 
        {"files0-from", 1, (int *)((void *)0), 131}, 
        {"general-numeric-sort", 0, (int *)((void *)0), 'g'}, 
        {"ignore-nonprinting", 0, (int *)((void *)0), 'i'}, 
        {"key", 1, (int *)((void *)0), 'k'}, 
        {"merge", 0, (int *)((void *)0), 'm'}, 
        {"month-sort", 0, (int *)((void *)0), 'M'}, 
        {"numeric-sort", 0, (int *)((void *)0), 'n'}, 
        {"human-numeric-sort", 0, (int *)((void *)0), 'h'}, 
        {"version-sort", 0, (int *)((void *)0), 'V'}, 
        {"random-sort", 0, (int *)((void *)0), 'R'}, 
        {"random-source", 1, (int *)((void *)0), 133}, 
        {"sort", 1, (int *)((void *)0), 134}, 
        {"output", 1, (int *)((void *)0), 'o'}, 
        {"reverse", 0, (int *)((void *)0), 'r'}, 
        {"stable", 0, (int *)((void *)0), 's'}, 
        {"batch-size", 1, (int *)((void *)0), 132}, 
        {"buffer-size", 1, (int *)((void *)0), 'S'}, 
        {"field-separator", 1, (int *)((void *)0), 't'}, 
        {"temporary-directory", 1, (int *)((void *)0), 'T'}, 
        {"unique", 0, (int *)((void *)0), 'u'}, 
        {"zero-terminated", 0, (int *)((void *)0), 'z'}, 
        {"parallel", 1, (int *)((void *)0), 135}, 
        {"help", 0, (int *)((void *)0), -130}, 
        {"version", 0, (int *)((void *)0), -131}, 
        {(char const   *)((void *)0), 0, (int *)((void *)0), 0}};
static char const   * const  check_args[4]  = {      "quiet",      "silent",      "diagnose-first",      (char const   *)((void *)0)};
static char const   check_types[3]  = {      (char const   )'C',      (char const   )'C',      (char const   )'c'};
static char const   * const  sort_args[7]  = {      "general-numeric",      "human-numeric",      "month",      "numeric", 
        "random",      "version",      (char const   *)((void *)0)};
static char const   sort_types[6]  = {      (char const   )'g',      (char const   )'h',      (char const   )'M',      (char const   )'n', 
        (char const   )'R',      (char const   )'V'};
static sigset_t caught_signals  ;
static struct cs_status cs_enter(void) 
{ 
  struct cs_status status ;
  int tmp ;

  {
  tmp = sigprocmask(0, (sigset_t const   *)(& caught_signals), & status.sigs);
  status.valid = (_Bool )(tmp == 0);
  return (status);
}
}
static void cs_leave(struct cs_status status ) 
{ 


  {
  if (status.valid) {
    sigprocmask(2, (sigset_t const   *)(& status.sigs), (sigset_t *)((void *)0));
  }
  return;
}
}
static struct tempnode * volatile  temphead  ;
static struct tempnode * volatile  *temptail  =    & temphead;
static Hash_table *proctab  ;
static size_t proctab_hasher(void const   *entry , size_t tabsize ) 
{ 
  struct tempnode  const  *node ;

  {
  node = (struct tempnode  const  *)entry;
  return ((unsigned long )node->pid % tabsize);
}
}
static _Bool proctab_comparator(void const   *e1 , void const   *e2 ) 
{ 
  struct tempnode  const  *n1 ;
  struct tempnode  const  *n2 ;

  {
  n1 = (struct tempnode  const  *)e1;
  n2 = (struct tempnode  const  *)e2;
  return ((_Bool )(n1->pid == n2->pid));
}
}
static pid_t nprocs  ;
static _Bool delete_proc(pid_t pid ) ;
static pid_t reap(pid_t pid ) 
{ 
  int status ;
  pid_t cpid ;
  int tmp ;
  pid_t tmp___0 ;
  pid_t tmp___1 ;
  char *tmp___2 ;
  int *tmp___3 ;
  char *tmp___4 ;
  union __anonunion_101 __constr_expr_82 ;
  union __anonunion_102 __constr_expr_83 ;
  _Bool tmp___5 ;

  {
  if (pid) {
    tmp = 0;
  } else {
    tmp = 1;
  }
  if (pid) {
    tmp___0 = pid;
  } else {
    tmp___0 = -1;
  }
  tmp___1 = waitpid(tmp___0, & status, tmp);
  cpid = tmp___1;
  if (cpid < 0) {
    tmp___2 = gettext("waiting for %s [-d]");
    tmp___3 = __errno_location();
    error(2, *tmp___3, (char const   *)tmp___2, compress_program);
  } else
  if (0 < cpid) {
    if (0 < pid) {
      goto _L;
    } else {
      tmp___5 = delete_proc(cpid);
      if (tmp___5) {
        _L: 
        __constr_expr_82.__in = status;
        if ((__constr_expr_82.__i & 127) == 0) {
          __constr_expr_83.__in = status;
          if ((__constr_expr_83.__i & 65280) >> 8) {
            tmp___4 = gettext("%s [-d] terminated abnormally");
            error(2, 0, (char const   *)tmp___4, compress_program);
          }
        } else {
          tmp___4 = gettext("%s [-d] terminated abnormally");
          error(2, 0, (char const   *)tmp___4, compress_program);
        }
        nprocs --;
      }
    }
  }
  return (cpid);
}
}
static void register_proc(struct tempnode *temp ) 
{ 
  void *tmp ;

  {
  if (! proctab) {
    proctab = hash_initialize((size_t )47, (Hash_tuning const   *)((void *)0), & proctab_hasher,
                              & proctab_comparator, (void (*)(void * ))((void *)0));
    if (! proctab) {
      xalloc_die();
    }
  }
  temp->state = (char)1;
  tmp = hash_insert(proctab, (void const   *)temp);
  if (! tmp) {
    xalloc_die();
  }
  return;
}
}
static _Bool delete_proc(pid_t pid ) 
{ 
  struct tempnode test ;
  struct tempnode *node ;
  struct tempnode *tmp ;

  {
  test.pid = pid;
  tmp = (struct tempnode *)hash_delete(proctab, (void const   *)(& test));
  node = tmp;
  if (! node) {
    return ((_Bool)0);
  }
  node->state = (char)2;
  return ((_Bool)1);
}
}
static void wait_proc(pid_t pid ) 
{ 
  _Bool tmp ;

  {
  tmp = delete_proc(pid);
  if (tmp) {
    reap(pid);
  }
  return;
}
}
static void reap_exited(void) 
{ 
  pid_t tmp ;

  {
  while (1) {
    while_continue: ;
    if (0 < nprocs) {
      tmp = reap(0);
      if (! tmp) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    goto while_continue;
  }
  while_break: ;
  return;
}
}
static void reap_some(void) 
{ 


  {
  reap(-1);
  reap_exited();
  return;
}
}
static void reap_all(void) 
{ 


  {
  while (1) {

    if (! (0 < nprocs)) {
      goto while_break;
    }
    reap(-1);
  }
  while_break: ;
  return;
}
}
static void cleanup(void) 
{ 
  struct tempnode  const  *node ;

  {
  node = (struct tempnode  const  *)temphead;
  while (1) {

    if (! node) {
      goto while_break;
    }
    unlink((char const   *)(node->name));
    node = (struct tempnode  const  *)node->next;
  }
  while_break: 
  temphead = (struct tempnode *)((void *)0);
  return;
}
}
static void exit_cleanup(void) 
{ 
  struct cs_status cs ;
  struct cs_status tmp ;

  {
  if (temphead) {
    tmp = cs_enter();
    cs = tmp;
    cleanup();
    cs_leave(cs);
  }
  close_stdout();
  return;
}
}
static struct tempnode *create_temp_file(int *pfd , _Bool survive_fd_exhaustion ) ;
static char const   slashbase[12]  = 
  {      (char const   )'/',      (char const   )'s',      (char const   )'o',      (char const   )'r', 
        (char const   )'t',      (char const   )'X',      (char const   )'X',      (char const   )'X', 
        (char const   )'X',      (char const   )'X',      (char const   )'X',      (char const   )'\000'};
static size_t temp_dir_index  ;
static struct tempnode *create_temp_file(int *pfd , _Bool survive_fd_exhaustion ) 
{ 
  int fd ;
  int saved_errno ;
  char const   *temp_dir ;
  size_t len ;
  size_t tmp ;
  struct tempnode *node ;
  struct tempnode *tmp___0 ;
  char *file ;
  struct cs_status cs ;
  int *tmp___1 ;
  int *tmp___2 ;
  char const   *tmp___3 ;
  char *tmp___4 ;
  int *tmp___5 ;
  int *tmp___6 ;

  {
  temp_dir = *(temp_dirs + temp_dir_index);
  tmp = strlen(temp_dir);
  len = tmp;
  tmp___0 = (struct tempnode *)xmalloc(((unsigned long )(& ((struct tempnode *)0)->name) + len) + sizeof(slashbase));
  node = tmp___0;
  file = node->name;
  memcpy((void *)file, (void const   *)temp_dir, len);
  memcpy((void *)(file + len), (void const   *)(slashbase), sizeof(slashbase));
  node->next = (struct tempnode *)((void *)0);
  temp_dir_index ++;
  if (temp_dir_index == temp_dir_count) {
    temp_dir_index = (size_t )0;
  }
  cs = cs_enter();
  fd = mkstemp_safer(file);
  if (0 <= fd) {
    *temptail = node;
    temptail = & node->next;
  }
  tmp___1 = __errno_location();
  saved_errno = *tmp___1;
  cs_leave(cs);
  tmp___2 = __errno_location();
  *tmp___2 = saved_errno;
  if (fd < 0) {
    if (survive_fd_exhaustion) {
      tmp___6 = __errno_location();
      if (! (*tmp___6 == 24)) {
        tmp___3 = quote(temp_dir);
        tmp___4 = gettext("cannot create temporary file in %s");
        tmp___5 = __errno_location();
        error(2, *tmp___5, (char const   *)tmp___4, tmp___3);
      }
    } else {
      tmp___3 = quote(temp_dir);
      tmp___4 = gettext("cannot create temporary file in %s");
      tmp___5 = __errno_location();
      error(2, *tmp___5, (char const   *)tmp___4, tmp___3);
    }
    free((void *)node);
    node = (struct tempnode *)((void *)0);
  }
  *pfd = fd;
  return (node);
}
}
static FILE *stream_open(char const   *file , char const   *how ) 
{ 
  FILE *fp ;
  int tmp ;
  FILE *tmp___0 ;

  {
  if (! file) {
    return (stdout);
  }
  if ((int const   )*how == 114) {
    tmp = strcmp(file, "-");
    if (tmp == 0) {
      have_read_stdin = (_Bool)1;
      fp = stdin;
    } else {
      fp = fopen_safer(file, how);
    }
    fadvise(fp, (fadvice_t )2);
    return (fp);
  }
  tmp___0 = fopen_safer(file, how);
  return (tmp___0);
}
}
static FILE *xfopen(char const   *file , char const   *how ) 
{ 
  FILE *fp ;
  FILE *tmp ;
  char *tmp___0 ;

  {
  tmp = stream_open(file, how);
  fp = tmp;
  if (! fp) {
    tmp___0 = gettext("open failed");
    die((char const   *)tmp___0, file);
  }
  return (fp);
}
}
static void xfclose(FILE *fp , char const   *file ) 
{ 
  int tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;
  char *tmp___3 ;
  int tmp___4 ;

  {
  tmp = fileno(fp);
  if (tmp == 0) {
    goto case_0;
  }
  if (tmp == 1) {
    goto case_1;
  }
  goto switch_default;
  case_0: 
  tmp___0 = feof_unlocked(fp);
  if (tmp___0) {
    clearerr_unlocked(fp);
  }
  goto switch_break;
  case_1: 
  tmp___2 = fflush_unlocked(fp);
  if (tmp___2 != 0) {
    tmp___1 = gettext("fflush failed");
    die((char const   *)tmp___1, file);
  }
  goto switch_break;
  switch_default: 
  tmp___4 = rpl_fclose(fp);
  if (tmp___4 != 0) {
    tmp___3 = gettext("close failed");
    die((char const   *)tmp___3, file);
  }
  goto switch_break;
  switch_break: ;
  return;
}
}
static void dup2_or_die(int oldfd , int newfd ) 
{ 
  char *tmp ;
  int *tmp___0 ;
  int tmp___1 ;

  {
  tmp___1 = dup2(oldfd, newfd);
  if (tmp___1 < 0) {
    tmp = gettext("dup2 failed");
    tmp___0 = __errno_location();
    error(2, *tmp___0, (char const   *)tmp);
  }
  return;
}
}
static pid_t pipe_fork(int *pipefds , size_t tries ) 
{ 
  struct tempnode *saved_temphead ;
  int saved_errno ;
  double wait_retry ;
  pid_t pid ;
  struct cs_status cs ;
  int tmp ;
  int *tmp___0 ;
  int *tmp___1 ;
  int *tmp___2 ;
  size_t tmp___3 ;
  int *tmp___4 ;
  int *tmp___5 ;

  {
  wait_retry = 0.25;
  tmp = pipe(pipefds);
  if (tmp < 0) {
    return (-1);
  }
  if (nmerge + 1U < (unsigned int )nprocs) {
    reap_some();
  }
  while (1) {
    tmp___3 = tries;
    tries --;
    if (! tmp___3) {
      goto while_break;
    }
    cs = cs_enter();
    saved_temphead = (struct tempnode *)temphead;
    temphead = (struct tempnode *)((void *)0);
    pid = fork();
    tmp___0 = __errno_location();
    saved_errno = *tmp___0;
    if (pid) {
      temphead = saved_temphead;
    }
    cs_leave(cs);
    tmp___1 = __errno_location();
    *tmp___1 = saved_errno;
    if (0 <= pid) {
      goto while_break;
    } else {
      tmp___2 = __errno_location();
      if (*tmp___2 != 11) {
        goto while_break;
      } else {
        xnanosleep(wait_retry);
        wait_retry *= (double )2;
        reap_exited();
      }
    }
  }
  while_break: ;
  if (pid < 0) {
    tmp___4 = __errno_location();
    saved_errno = *tmp___4;
    close(*(pipefds + 0));
    close(*(pipefds + 1));
    tmp___5 = __errno_location();
    *tmp___5 = saved_errno;
  } else
  if (pid == 0) {
    close(0);
    close(1);
  } else {
    nprocs ++;
  }
  return (pid);
}
}
static struct tempnode *maybe_create_temp(FILE **pfp , _Bool survive_fd_exhaustion ) 
{ 
  int tempfd ;
  struct tempnode *node ;
  struct tempnode *tmp ;
  int pipefds[2] ;
  char *tmp___0 ;
  int *tmp___1 ;
  int tmp___2 ;
  char *tmp___3 ;

  {
  tmp = create_temp_file(& tempfd, survive_fd_exhaustion);
  node = tmp;
  if (! node) {
    return ((struct tempnode *)((void *)0));
  }
  node->state = (char)0;
  if (compress_program) {
    node->pid = pipe_fork(pipefds, (size_t )4);
    if (0 < node->pid) {
      close(tempfd);
      close(pipefds[0]);
      tempfd = pipefds[1];
      register_proc(node);
    } else
    if (node->pid == 0) {
      close(pipefds[1]);
      dup2_or_die(tempfd, 1);
      close(tempfd);
      dup2_or_die(pipefds[0], 0);
      close(pipefds[0]);
      tmp___2 = execlp(compress_program, compress_program, (char *)((void *)0));
      if (tmp___2 < 0) {
        tmp___0 = gettext("couldn\'t execute %s");
        tmp___1 = __errno_location();
        error(2, *tmp___1, (char const   *)tmp___0, compress_program);
      }
    }
  }
  *pfp = fdopen(tempfd, "w");
  if (! *pfp) {
    tmp___3 = gettext("couldn\'t create temporary file");
    die((char const   *)tmp___3, (char const   *)(node->name));
  }
  return (node);
}
}
static struct tempnode *create_temp(FILE **pfp ) 
{ 
  struct tempnode *tmp ;

  {
  tmp = maybe_create_temp(pfp, (_Bool)0);
  return (tmp);
}
}
static FILE *open_temp(struct tempnode *temp ) 
{ 
  int tempfd ;
  int pipefds[2] ;
  FILE *fp ;
  pid_t child ;
  pid_t tmp ;
  char *tmp___0 ;
  int *tmp___1 ;
  int *tmp___2 ;
  int *tmp___3 ;
  char *tmp___4 ;
  int *tmp___5 ;
  int saved_errno ;
  int *tmp___6 ;
  int *tmp___7 ;

  {
  fp = (FILE *)((void *)0);
  if ((int )temp->state == 1) {
    wait_proc(temp->pid);
  }
  tempfd = open((char const   *)(temp->name), 0);
  if (tempfd < 0) {
    return ((FILE *)((void *)0));
  }
  tmp = pipe_fork(pipefds, (size_t )9);
  child = tmp;
  if (child == -1) {
    goto case_neg_1;
  }
  if (child == 0) {
    goto case_0;
  }
  goto switch_default;
  case_neg_1: 
  tmp___2 = __errno_location();
  if (*tmp___2 != 24) {
    tmp___0 = gettext("couldn\'t create process for %s -d");
    tmp___1 = __errno_location();
    error(2, *tmp___1, (char const   *)tmp___0, compress_program);
  }
  close(tempfd);
  tmp___3 = __errno_location();
  *tmp___3 = 24;
  goto switch_break;
  case_0: 
  close(pipefds[0]);
  dup2_or_die(tempfd, 0);
  close(tempfd);
  dup2_or_die(pipefds[1], 1);
  close(pipefds[1]);
  execlp(compress_program, compress_program, "-d", (char *)((void *)0));
  tmp___4 = gettext("couldn\'t execute %s -d");
  tmp___5 = __errno_location();
  error(2, *tmp___5, (char const   *)tmp___4, compress_program);
  switch_default: 
  temp->pid = child;
  register_proc(temp);
  close(tempfd);
  close(pipefds[1]);
  fp = fdopen(pipefds[0], "r");
  if (! fp) {
    tmp___6 = __errno_location();
    saved_errno = *tmp___6;
    close(pipefds[0]);
    tmp___7 = __errno_location();
    *tmp___7 = saved_errno;
  }
  goto switch_break;
  switch_break: ;
  return (fp);
}
}
static void add_temp_dir(char const   *dir ) 
{ 
  size_t tmp ;

  {
  if (temp_dir_count == temp_dir_alloc) {
    temp_dirs = (char const   **)x2nrealloc((void *)temp_dirs, & temp_dir_alloc, sizeof(*temp_dirs));
  }
  tmp = temp_dir_count;
  temp_dir_count ++;
  *(temp_dirs + tmp) = dir;
  return;
}
}
static void zaptemp(char const   *name ) 
{ 
  struct tempnode * volatile  *pnode ;
  struct tempnode *node ;
  struct tempnode *next ;
  int unlink_status ;
  int unlink_errno ;
  struct cs_status cs ;
  int *tmp ;
  char *tmp___0 ;

  {
  unlink_errno = 0;
  pnode = & temphead;
  while (1) {
    node = (struct tempnode *)*pnode;
    if (! ((unsigned long )(node->name) != (unsigned long )name)) {
      goto while_break;
    }
    goto __Cont;
    __Cont: 
    pnode = & node->next;
  }
  while_break: ;
  if ((int )node->state == 1) {
    wait_proc(node->pid);
  }
  next = (struct tempnode *)node->next;
  cs = cs_enter();
  unlink_status = unlink(name);
  tmp = __errno_location();
  unlink_errno = *tmp;
  *pnode = next;
  cs_leave(cs);
  if (unlink_status != 0) {
    tmp___0 = gettext("warning: cannot remove: %s");
    error(0, unlink_errno, (char const   *)tmp___0, name);
  }
  if (! next) {
    temptail = pnode;
  }
  free((void *)node);
  return;
}
}
static int struct_month_cmp(void const   *m1 , void const   *m2 ) 
{ 
  struct month  const  *month1 ;
  struct month  const  *month2 ;
  int tmp ;

  {
  month1 = (struct month  const  *)m1;
  month2 = (struct month  const  *)m2;
  tmp = strcmp((char const   *)month1->name, (char const   *)month2->name);
  return (tmp);
}
}
static void inittables(void) 
{ 
  size_t i ;
  unsigned short const   **tmp ;
  int tmp___0 ;
  unsigned short const   **tmp___1 ;
  int tmp___2 ;
  unsigned short const   **tmp___3 ;
  unsigned short const   **tmp___4 ;
  int tmp___5 ;
  char const   *s ;
  size_t s_len ;
  size_t j ;
  size_t k ;
  char *name ;
  size_t tmp___6 ;
  unsigned char tmp___7 ;
  unsigned short const   **tmp___8 ;
  unsigned char tmp___9 ;

  {
  i = (size_t )0;
  while (1) {

    if (! (i < 256UL)) {
      goto while_break;
    }
    tmp = __ctype_b_loc();
    if ((int const   )*(*tmp + (int )i) & 1) {
      tmp___0 = 1;
    } else {
      tmp___0 = 0;
    }
    blanks[i] = (_Bool )tmp___0;
    tmp___1 = __ctype_b_loc();
    if ((int const   )*(*tmp___1 + (int )i) & 16384) {
      tmp___2 = 0;
    } else {
      tmp___2 = 1;
    }
    nonprinting[i] = (_Bool )tmp___2;
    tmp___3 = __ctype_b_loc();
    if ((int const   )*(*tmp___3 + (int )i) & 8) {
      tmp___5 = 0;
    } else {
      tmp___4 = __ctype_b_loc();
      if ((int const   )*(*tmp___4 + (int )i) & 1) {
        tmp___5 = 0;
      } else {
        tmp___5 = 1;
      }
    }
    nondictionary[i] = (_Bool )tmp___5;
    fold_toupper[i] = (char )toupper((int )i);
    i ++;
  }
  while_break: ;
  if (hard_LC_TIME) {
    i = (size_t )0;
    while (1) {

      if (! (i < 12UL)) {
        goto while_break___0;
      }
      s = (char const   *)nl_langinfo((nl_item )(131086UL + i));
      s_len = strlen(s);
      name = (char *)xmalloc(s_len + 1UL);
      monthtab[i].name = (char const   *)name;
      monthtab[i].val = (int )(i + 1UL);
      k = (size_t )0;
      j = k;
      while (1) {

        if (! (j < s_len)) {
          goto while_break___1;
        }
        tmp___8 = __ctype_b_loc();
        tmp___9 = to_uchar((char )*(s + j));
        if (! ((int const   )*(*tmp___8 + (int )tmp___9) & 1)) {
          tmp___6 = k;
          k ++;
          tmp___7 = to_uchar((char )*(s + j));
          *(name + tmp___6) = fold_toupper[tmp___7];
        }
        j ++;
      }
      while_break___1: 
      *(name + k) = (char )'\000';
      i ++;
    }
    while_break___0: 
    qsort((void *)(monthtab), (size_t )12, sizeof(monthtab[0]), & struct_month_cmp);
  }
  return;
}
}
static void specify_nmerge(int oi , char c , char const   *s ) 
{ 
  uintmax_t n ;
  struct rlimit rlimit ;
  enum strtol_error e ;
  enum strtol_error tmp ;
  unsigned int max_nmerge ;
  rlim_t tmp___1 ;
  int tmp___2 ;
  char const   *tmp___3 ;
  char *tmp___4 ;
  char const   *tmp___5 ;
  char *tmp___6 ;
  char max_nmerge_buf[((sizeof(max_nmerge) * 8UL) * 146UL + 484UL) / 485UL + 1UL] ;
  char const   *tmp___7 ;
  char *tmp___8 ;
  char *tmp___9 ;
  char *tmp___10 ;

  {
  tmp = xstrtoumax(s, (char **)((void *)0), 10, & n, (char const   *)((void *)0));
  e = tmp;
  tmp___2 = getrlimit((__rlimit_resource_t )7, & rlimit);
  if (tmp___2 == 0) {
    tmp___1 = rlimit.rlim_cur;
  } else {
    tmp___1 = (rlim_t )20;
  }
  max_nmerge = (unsigned int )(tmp___1 - 3UL);
  if ((unsigned int )e == 0U) {
    nmerge = (unsigned int )n;
    if ((uintmax_t )nmerge != n) {
      e = (enum strtol_error )1;
    } else
    if (nmerge < 2U) {
      tmp___3 = quote(s);
      tmp___4 = gettext("invalid --%s argument %s");
      error(0, 0, (char const   *)tmp___4, long_options___1[oi].name, tmp___3);
      tmp___5 = quote("2");
      tmp___6 = gettext("minimum --%s argument is %s");
      error(2, 0, (char const   *)tmp___6, long_options___1[oi].name, tmp___5);
    } else
    if (max_nmerge < nmerge) {
      e = (enum strtol_error )1;
    } else {
      return;
    }
  }
  if ((unsigned int )e == 1U) {
    tmp___7 = quote(s);
    tmp___8 = gettext("--%s argument %s too large");
    error(0, 0, (char const   *)tmp___8, long_options___1[oi].name, tmp___7);
    tmp___9 = uinttostr(max_nmerge, max_nmerge_buf);
    tmp___10 = gettext("maximum --%s argument with current rlimit is %s");
    error(2, 0, (char const   *)tmp___10, long_options___1[oi].name, tmp___9);
  } else {
    xstrtol_fatal(e, oi, c, long_options___1, s);
  }
  return;
}
}
static void specify_sort_size(int oi , char c , char const   *s ) 
{ 
  uintmax_t n ;
  char *suffix ;
  enum strtol_error e ;
  enum strtol_error tmp ;
  double mem ;
  double tmp___0 ;

  {
  tmp = xstrtoumax(s, & suffix, 10, & n, "EgGkKmMPtTYZ");
  e = tmp;
  if ((unsigned int )e == 0U) {
    if ((unsigned int )*(suffix + -1) - 48U <= 9U) {
      if (n <= 18014398509481983UL) {
        n *= 1024UL;
      } else {
        e = (enum strtol_error )1;
      }
    }
  }
  if ((unsigned int )e == 2U) {
    if ((unsigned int )*(suffix + -1) - 48U <= 9U) {
      if (! *(suffix + 1)) {
        if ((int )*(suffix + 0) == 98) {
          goto case_98;
        }
        if ((int )*(suffix + 0) == 37) {
          goto case_37;
        }
        goto switch_break;
        case_98: 
        e = (enum strtol_error )0;
        goto switch_break;
        case_37: 
        tmp___0 = physmem_total();
        mem = (tmp___0 * (double )n) / (double )100;
        if (mem < (double )0xffffffffffffffffUL) {
          n = (uintmax_t )mem;
          e = (enum strtol_error )0;
        } else {
          e = (enum strtol_error )1;
        }
        goto switch_break;
        switch_break: ;
      }
    }
  }
  if ((unsigned int )e == 0U) {
    if (n < sort_size) {
      return;
    }
    sort_size = n;
    if (sort_size == n) {
      if (sort_size > (unsigned long )nmerge * (2UL + sizeof(struct line ))) {
        sort_size = sort_size;
      } else {
        sort_size = (unsigned long )nmerge * (2UL + sizeof(struct line ));
      }
      return;
    }
    e = (enum strtol_error )1;
  }
  xstrtol_fatal(e, oi, c, long_options___1, s);
}
}
static size_t specify_nthreads(int oi , char c , char const   *s ) 
{ 
  unsigned long nthreads ;
  enum strtol_error e ;
  enum strtol_error tmp ;
  char *tmp___0 ;

  {
  tmp = xstrtoul(s, (char **)((void *)0), 10, & nthreads, "");
  e = tmp;
  if ((unsigned int )e == 1U) {
    return (0xffffffffffffffffUL);
  }
  if ((unsigned int )e != 0U) {
    xstrtol_fatal(e, oi, c, long_options___1, s);
  }
  if (0xffffffffffffffffUL < nthreads) {
    nthreads = 0xffffffffffffffffUL;
  }
  if (nthreads == 0UL) {
    tmp___0 = gettext("number in parallel must be nonzero");
    error(2, 0, (char const   *)tmp___0);
  }
  return (nthreads);
}
}
static size_t default_sort_size(void) 
{ 
  double avail ;
  double tmp ;
  double total ;
  double tmp___0 ;
  double mem ;
  double tmp___1 ;
  struct rlimit rlimit ;
  size_t size ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  size_t tmp___5 ;

  {
  tmp = physmem_available();
  avail = tmp;
  tmp___0 = physmem_total();
  total = tmp___0;
  if (avail > total / (double )8) {
    tmp___1 = avail;
  } else {
    tmp___1 = total / (double )8;
  }
  mem = tmp___1;
  size = 0xffffffffffffffffUL;
  tmp___2 = getrlimit((__rlimit_resource_t )2, & rlimit);
  if (tmp___2 == 0) {
    if (rlimit.rlim_cur < size) {
      size = rlimit.rlim_cur;
    }
  }
  tmp___3 = getrlimit((__rlimit_resource_t )9, & rlimit);
  if (tmp___3 == 0) {
    if (rlimit.rlim_cur < size) {
      size = rlimit.rlim_cur;
    }
  }
  size /= 2UL;
  tmp___4 = getrlimit((__rlimit_resource_t )5, & rlimit);
  if (tmp___4 == 0) {
    if ((rlimit.rlim_cur / 16UL) * 15UL < size) {
      size = (rlimit.rlim_cur / 16UL) * 15UL;
    }
  }
  if (mem < (double )size) {
    size = (size_t )mem;
  }
  if (size > (unsigned long )nmerge * (2UL + sizeof(struct line ))) {
    tmp___5 = size;
  } else {
    tmp___5 = (unsigned long )nmerge * (2UL + sizeof(struct line ));
  }
  return (tmp___5);
}
}
static size_t size_bound  ;
static size_t sort_buffer_size(FILE * const  *fps , size_t nfps , char * const  *files ,
                               size_t nfiles , size_t line_bytes ) 
{ 
  size_t worst_case_per_input_byte ;
  size_t size ;
  size_t i ;
  struct stat st ;
  off_t file_size ;
  size_t worst_case ;
  char *tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;

  {
  worst_case_per_input_byte = line_bytes + 1UL;
  size = worst_case_per_input_byte + 1UL;
  i = (size_t )0;
  while (1) {

    if (! (i < nfiles)) {
      goto while_break;
    }
    if (i < nfps) {
      tmp___0 = fileno((FILE *)*(fps + i));
      tmp___1 = fstat(tmp___0, & st);
      tmp___7 = tmp___1;
    } else {
      tmp___6 = strcmp((char const   *)*(files + i), "-");
      if (tmp___6 == 0) {
        tmp___3 = fstat(0, & st);
        tmp___5 = tmp___3;
      } else {
        tmp___4 = stat((char const   *)*(files + i), & st);
        tmp___5 = tmp___4;
      }
      tmp___7 = tmp___5;
    }
    if (tmp___7 != 0) {
      tmp = gettext("stat failed");
      die((char const   *)tmp, (char const   *)*(files + i));
    }
    if ((st.st_mode & 61440U) == 32768U) {
      file_size = st.st_size;
    } else {
      if (sort_size) {
        return (sort_size);
      }
      file_size = (off_t )131072;
    }
    if (! size_bound) {
      size_bound = sort_size;
      if (! size_bound) {
        size_bound = default_sort_size();
      }
    }
    worst_case = (size_t )file_size * worst_case_per_input_byte + 1UL;
    if ((size_t )file_size != worst_case / worst_case_per_input_byte) {
      return (size_bound);
    } else
    if (size_bound - size <= worst_case) {
      return (size_bound);
    }
    size += worst_case;
    i ++;
  }
  while_break: ;
  return (size);
}
}
static void initbuf(struct buffer *buf___1 , size_t line_bytes , size_t alloc ) 
{ 
  size_t tmp ;
  size_t tmp___0 ;

  {
  while (1) {
    alloc += sizeof(struct line ) - alloc % sizeof(struct line );
    buf___1->buf = (char *)malloc(alloc);
    if (buf___1->buf) {
      goto while_break;
    }
    alloc /= 2UL;
    if (alloc <= line_bytes + 1UL) {
      xalloc_die();
    }
  }
  while_break: 
  buf___1->line_bytes = line_bytes;
  buf___1->alloc = alloc;
  tmp___0 = (size_t )0;
  buf___1->nlines = tmp___0;
  tmp = tmp___0;
  buf___1->left = tmp;
  buf___1->used = tmp;
  buf___1->eof = (_Bool)0;
  return;
}
}
__inline static struct line *buffer_linelim(struct buffer  const  *buf___1 ) 
{ 


  {
  return ((struct line *)(buf___1->buf + buf___1->alloc));
}
}
static char *begfield(struct line  const  *line , struct keyfield  const  *key ) 
{ 
  char *ptr ;
  char *lim ;
  size_t sword ;
  size_t schar ;
  size_t tmp ;
  unsigned char tmp___0 ;
  unsigned char tmp___1 ;
  size_t tmp___2 ;
  unsigned char tmp___3 ;

  {
  ptr = (char *)line->text;
  lim = (ptr + line->length) - 1;
  sword = (size_t )key->sword;
  schar = (size_t )key->schar;
  if (tab != 128) {
    while (1) {

      if ((unsigned long )ptr < (unsigned long )lim) {
        tmp = sword;
        sword --;
        if (! tmp) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      while (1) {

        if ((unsigned long )ptr < (unsigned long )lim) {
          if (! ((int )*ptr != tab)) {
            goto while_break___0;
          }
        } else {
          goto while_break___0;
        }
        ptr ++;
      }
      while_break___0: ;
      if ((unsigned long )ptr < (unsigned long )lim) {
        ptr ++;
      }
    }
    while_break: ;
  } else {
    while (1) {

      if ((unsigned long )ptr < (unsigned long )lim) {
        tmp___2 = sword;
        sword --;
        if (! tmp___2) {
          goto while_break___1;
        }
      } else {
        goto while_break___1;
      }
      while (1) {

        if ((unsigned long )ptr < (unsigned long )lim) {
          tmp___0 = to_uchar(*ptr);
          if (! blanks[tmp___0]) {
            goto while_break___2;
          }
        } else {
          goto while_break___2;
        }
        ptr ++;
      }
      while_break___2: ;
      while (1) {

        if ((unsigned long )ptr < (unsigned long )lim) {
          tmp___1 = to_uchar(*ptr);
          if (blanks[tmp___1]) {
            goto while_break___3;
          }
        } else {
          goto while_break___3;
        }
        ptr ++;
      }
      while_break___3: ;
    }
    while_break___1: ;
  }
  if (key->skipsblanks) {
    while (1) {

      if ((unsigned long )ptr < (unsigned long )lim) {
        tmp___3 = to_uchar(*ptr);
        if (! blanks[tmp___3]) {
          goto while_break___4;
        }
      } else {
        goto while_break___4;
      }
      ptr ++;
    }
    while_break___4: ;
  }
  if ((unsigned long )lim < (unsigned long )(ptr + schar)) {
    ptr = lim;
  } else {
    ptr += schar;
  }
  return (ptr);
}
}
static char *limfield(struct line  const  *line , struct keyfield  const  *key ) 
{ 
  char *ptr ;
  char *lim ;
  size_t eword ;
  size_t echar ;
  size_t tmp ;
  unsigned char tmp___0 ;
  unsigned char tmp___1 ;
  size_t tmp___2 ;
  unsigned char tmp___3 ;

  {
  ptr = (char *)line->text;
  lim = (ptr + line->length) - 1;
  eword = (size_t )key->eword;
  echar = (size_t )key->echar;
  if (echar == 0UL) {
    eword ++;
  }
  if (tab != 128) {
    while (1) {

      if ((unsigned long )ptr < (unsigned long )lim) {
        tmp = eword;
        eword --;
        if (! tmp) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      while (1) {

        if ((unsigned long )ptr < (unsigned long )lim) {
          if (! ((int )*ptr != tab)) {
            goto while_break___0;
          }
        } else {
          goto while_break___0;
        }
        ptr ++;
      }
      while_break___0: ;
      if ((unsigned long )ptr < (unsigned long )lim) {
        if (eword) {
          ptr ++;
        } else
        if (echar) {
          ptr ++;
        }
      }
    }
    while_break: ;
  } else {
    while (1) {

      if ((unsigned long )ptr < (unsigned long )lim) {
        tmp___2 = eword;
        eword --;
        if (! tmp___2) {
          goto while_break___1;
        }
      } else {
        goto while_break___1;
      }
      while (1) {

        if ((unsigned long )ptr < (unsigned long )lim) {
          tmp___0 = to_uchar(*ptr);
          if (! blanks[tmp___0]) {
            goto while_break___2;
          }
        } else {
          goto while_break___2;
        }
        ptr ++;
      }
      while_break___2: ;
      while (1) {

        if ((unsigned long )ptr < (unsigned long )lim) {
          tmp___1 = to_uchar(*ptr);
          if (blanks[tmp___1]) {
            goto while_break___3;
          }
        } else {
          goto while_break___3;
        }
        ptr ++;
      }
      while_break___3: ;
    }
    while_break___1: ;
  }
  if (echar != 0UL) {
    if (key->skipeblanks) {
      while (1) {

        if ((unsigned long )ptr < (unsigned long )lim) {
          tmp___3 = to_uchar(*ptr);
          if (! blanks[tmp___3]) {
            goto while_break___4;
          }
        } else {
          goto while_break___4;
        }
        ptr ++;
      }
      while_break___4: ;
    }
    if ((unsigned long )lim < (unsigned long )(ptr + echar)) {
      ptr = lim;
    } else {
      ptr += echar;
    }
  }
  return (ptr);
}
}
static _Bool fillbuf___7(struct buffer *buf___1 , FILE *fp , char const   *file ) 
{ 
  struct keyfield  const  *key ;
  char eol ;
  size_t line_bytes ;
  size_t mergesize ;
  char *ptr ;
  struct line *linelim ;
  struct line *tmp ;
  struct line *line ;
  size_t avail ;
  char *line_start ;
  char *tmp___0 ;
  size_t readsize ;
  size_t bytes_read ;
  size_t tmp___1 ;
  char *ptrlim ;
  char *p ;
  char *tmp___2 ;
  int tmp___3 ;
  char *tmp___4 ;
  int tmp___5 ;
  char *tmp___6 ;
  unsigned char tmp___7 ;
  struct line *tmp___8 ;
  size_t line_alloc ;

  {
  key = (struct keyfield  const  *)keylist;
  eol = eolchar;
  line_bytes = buf___1->line_bytes;
  mergesize = merge_buffer_size - (2UL + sizeof(struct line ));
  if (buf___1->eof) {
    return ((_Bool)0);
  }
  if (buf___1->used != buf___1->left) {
    memmove((void *)buf___1->buf, (void const   *)((buf___1->buf + buf___1->used) - buf___1->left),
            buf___1->left);
    buf___1->used = buf___1->left;
    buf___1->nlines = (size_t )0;
  }
  while (1) {
    ptr = buf___1->buf + buf___1->used;
    tmp = buffer_linelim((struct buffer  const  *)buf___1);
    linelim = tmp;
    line = linelim - buf___1->nlines;
    avail = (size_t )(((char *)linelim - buf___1->nlines * line_bytes) - ptr);
    if (buf___1->nlines) {
      tmp___0 = line->text + line->length;
    } else {
      tmp___0 = buf___1->buf;
    }
    line_start = tmp___0;
    while (1) {

      if (! (line_bytes + 1UL < avail)) {
        goto while_break___0;
      }
      readsize = (avail - 1UL) / (line_bytes + 1UL);
      tmp___1 = fread_unlocked((void *)ptr, (size_t )1, readsize, fp);
      bytes_read = tmp___1;
      ptrlim = ptr + bytes_read;
      avail -= bytes_read;
      if (bytes_read != readsize) {
        tmp___3 = ferror_unlocked(fp);
        if (tmp___3) {
          tmp___2 = gettext("read failed");
          die((char const   *)tmp___2, file);
        }
        tmp___5 = feof_unlocked(fp);
        if (tmp___5) {
          buf___1->eof = (_Bool)1;
          if ((unsigned long )buf___1->buf == (unsigned long )ptrlim) {
            return ((_Bool)0);
          }
          if ((unsigned long )line_start != (unsigned long )ptrlim) {
            if ((int )*(ptrlim + -1) != (int )eol) {
              tmp___4 = ptrlim;
              ptrlim ++;
              *tmp___4 = eol;
            }
          }
        }
      }
      while (1) {
        p = (char *)memchr((void const   *)ptr, (int )eol, (size_t )(ptrlim - ptr));
        if (! p) {
          goto while_break___1;
        }
        *p = (char )'\000';
        ptr = p + 1;
        line --;
        line->text = line_start;
        line->length = (size_t )(ptr - line_start);
        if (mergesize > line->length) {
          mergesize = mergesize;
        } else {
          mergesize = line->length;
        }
        avail -= line_bytes;
        if (key) {
          if (key->eword == 0xffffffffffffffffUL) {
            line->keylim = p;
          } else {
            tmp___6 = limfield((struct line  const  *)line, key);
            line->keylim = tmp___6;
          }
          if (key->sword != 0xffffffffffffffffUL) {
            line->keybeg = begfield((struct line  const  *)line, key);
          } else {
            if (key->skipsblanks) {
              while (1) {
                tmp___7 = to_uchar(*line_start);
                if (! blanks[tmp___7]) {
                  goto while_break___2;
                }
                line_start ++;
              }
              while_break___2: ;
            }
            line->keybeg = line_start;
          }
        }
        line_start = ptr;
      }
      while_break___1: 
      ptr = ptrlim;
      if (buf___1->eof) {
        goto while_break___0;
      }
    }
    while_break___0: 
    buf___1->used = (size_t )(ptr - buf___1->buf);
    tmp___8 = buffer_linelim((struct buffer  const  *)buf___1);
    buf___1->nlines = (size_t )(tmp___8 - line);
    if (buf___1->nlines != 0UL) {
      buf___1->left = (size_t )(ptr - line_start);
      merge_buffer_size = mergesize + (2UL + sizeof(struct line ));
      return ((_Bool)1);
    }
    line_alloc = buf___1->alloc / sizeof(struct line );
    buf___1->buf = (char *)x2nrealloc((void *)buf___1->buf, & line_alloc, sizeof(struct line ));
    buf___1->alloc = line_alloc * sizeof(struct line );
  }

  return ((_Bool)0);
}
}
static char const   unit_order[256]  = 
  {      (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )6,      (char const   )0,      (char const   )3, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )1, 
        (char const   )0,      (char const   )2,      (char const   )0,      (char const   )0, 
        (char const   )5,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )4,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )8,      (char const   )7,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )1, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0, 
        (char const   )0,      (char const   )0,      (char const   )0,      (char const   )0};
static int __attribute__((__pure__))  find_unit_order(char const   *number ) 
{ 
  _Bool minus_sign ;
  char const   *p ;
  int nonzero ;
  unsigned char ch ;
  char const   *tmp ;
  char const   *tmp___0 ;
  int order___0 ;
  int tmp___1 ;

  {
  minus_sign = (_Bool )((int const   )*number == 45);
  p = number + (int )minus_sign;
  nonzero = 0;
  while (1) {

    while (1) {
      tmp = p;
      p ++;
      ch = (unsigned char )*tmp;
      if (! ((unsigned int )ch - 48U <= 9U)) {
        goto while_break___0;
      }
      nonzero |= (int )ch - 48;
    }
    while_break___0: ;
    if (! ((int )ch == thousands_sep)) {
      goto while_break;
    }
  }
  while_break: ;
  if ((int )ch == decimal_point) {
    while (1) {
      tmp___0 = p;
      p ++;
      ch = (unsigned char )*tmp___0;
      if (! ((unsigned int )ch - 48U <= 9U)) {
        goto while_break___1;
      }
      nonzero |= (int )ch - 48;
    }
    while_break___1: ;
  }
  if (nonzero) {
    order___0 = (int )unit_order[ch];
    if (minus_sign) {
      tmp___1 = - order___0;
    } else {
      tmp___1 = order___0;
    }
    return ((int __attribute__((__pure__))  )tmp___1);
  } else {
    return ((int __attribute__((__pure__))  )0);
  }
}
}
static int human_numcompare(char const   *a , char const   *b ) 
{ 
  unsigned char tmp ;
  unsigned char tmp___0 ;
  int diff ;
  int __attribute__((__pure__))  tmp___1 ;
  int __attribute__((__pure__))  tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;

  {
  while (1) {
    tmp = to_uchar((char )*a);
    if (! blanks[tmp]) {
      goto while_break;
    }
    a ++;
  }
  while_break: ;
  while (1) {
    tmp___0 = to_uchar((char )*b);
    if (! blanks[tmp___0]) {
      goto while_break___0;
    }
    b ++;
  }
  while_break___0: 
  tmp___1 = find_unit_order(a);
  tmp___2 = find_unit_order(b);
  diff = (int )(tmp___1 - tmp___2);
  if (diff) {
    tmp___4 = diff;
  } else {
    tmp___3 = (int )strnumcmp(a, b, decimal_point, thousands_sep);
    tmp___4 = tmp___3;
  }
  return (tmp___4);
}
}
static int numcompare___3(char const   *a , char const   *b ) 
{ 
  unsigned char tmp ;
  unsigned char tmp___0 ;
  int tmp___1 ;

  {
  while (1) {
    tmp = to_uchar((char )*a);
    if (! blanks[tmp]) {
      goto while_break;
    }
    a ++;
  }
  while_break: ;
  while (1) {
    tmp___0 = to_uchar((char )*b);
    if (! blanks[tmp___0]) {
      goto while_break___0;
    }
    b ++;
  }
  while_break___0: 
  tmp___1 = (int )strnumcmp(a, b, decimal_point, thousands_sep);
  return (tmp___1);
}
}
static int nan_compare(char const   *sa , char const   *sb ) 
{ 
  long double a ;
  long double b ;
  int tmp ;

  {
  memset((void *)(& a), 0, sizeof(a));
  a = strtold(sa, (char **)((void *)0));
  memset((void *)(& b), 0, sizeof(b));
  b = strtold(sb, (char **)((void *)0));
  tmp = memcmp((void const   *)(& a), (void const   *)(& b), sizeof(a));
  return (tmp);
}
}
static int general_numcompare(char const   *sa , char const   *sb ) 
{ 
  char *ea ;
  char *eb ;
  long double a ;
  long double tmp ;
  long double b ;
  long double tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;

  {
  tmp = strtold(sa, & ea);
  a = tmp;
  tmp___0 = strtold(sb, & eb);
  b = tmp___0;
  if ((unsigned long )sa == (unsigned long )ea) {
    if ((unsigned long )sb == (unsigned long )eb) {
      tmp___1 = 0;
    } else {
      tmp___1 = -1;
    }
    return (tmp___1);
  }
  if ((unsigned long )sb == (unsigned long )eb) {
    return (1);
  }
  if (a < b) {
    tmp___7 = -1;
  } else {
    if (a > b) {
      tmp___6 = 1;
    } else {
      if (a == b) {
        tmp___5 = 0;
      } else {
        if (b == b) {
          tmp___4 = -1;
        } else {
          if (a == a) {
            tmp___3 = 1;
          } else {
            tmp___2 = nan_compare(sa, sb);
            tmp___3 = tmp___2;
          }
          tmp___4 = tmp___3;
        }
        tmp___5 = tmp___4;
      }
      tmp___6 = tmp___5;
    }
    tmp___7 = tmp___6;
  }
  return (tmp___7);
}
}
static int getmonth(char const   *month , char **ea ) 
{ 
  size_t lo ;
  size_t hi ;
  unsigned char tmp ;
  size_t ix ;
  char const   *m ;
  char const   *n ;
  unsigned char tmp___0 ;
  unsigned char tmp___1 ;
  unsigned char tmp___2 ;
  unsigned char tmp___3 ;
  unsigned char tmp___4 ;
  unsigned char tmp___5 ;

  {
  lo = (size_t )0;
  hi = (size_t )12;
  while (1) {
    tmp = to_uchar((char )*month);
    if (! blanks[tmp]) {
      goto while_break;
    }
    month ++;
  }
  while_break: ;
  while (1) {
    ix = (lo + hi) / 2UL;
    m = month;
    n = monthtab[ix].name;
    while (1) {

      if (! *n) {
        if (ea) {
          *ea = (char *)m;
        }
        return (monthtab[ix].val);
      }
      tmp___3 = to_uchar((char )*m);
      tmp___4 = to_uchar(fold_toupper[tmp___3]);
      tmp___5 = to_uchar((char )*n);
      if ((int )tmp___4 < (int )tmp___5) {
        hi = ix;
        goto while_break___1;
      } else {
        tmp___0 = to_uchar((char )*m);
        tmp___1 = to_uchar(fold_toupper[tmp___0]);
        tmp___2 = to_uchar((char )*n);
        if ((int )tmp___1 > (int )tmp___2) {
          lo = ix + 1UL;
          goto while_break___1;
        }
      }
      m ++;
      n ++;
    }
    while_break___1: ;
    if (! (lo < hi)) {
      goto while_break___0;
    }
  }
  while_break___0: ;
  return (0);
}
}
static struct md5_ctx random_md5_state  ;
static void random_md5_state_init(char const   *random_source ) 
{ 
  unsigned char buf___1[16] ;
  struct randread_source *r ;
  struct randread_source *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;

  {
  tmp = randread_new(random_source, sizeof(buf___1));
  r = tmp;
  if (! r) {
    tmp___0 = gettext("open failed");
    die((char const   *)tmp___0, random_source);
  }
  randread(r, (void *)(buf___1), sizeof(buf___1));
  tmp___2 = randread_free(r);
  if (tmp___2 != 0) {
    tmp___1 = gettext("close failed");
    die((char const   *)tmp___1, random_source);
  }
  md5_init_ctx(& random_md5_state);
  md5_process_bytes((void const   *)(buf___1), sizeof(buf___1), & random_md5_state);
  return;
}
}
static size_t xstrxfrm(char * __restrict  dest , char const   * __restrict  src ,
                       size_t destsize ) 
{ 
  int *tmp ;
  size_t translated_size ;
  size_t tmp___0 ;
  char *tmp___1 ;
  int *tmp___2 ;
  char *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  int *tmp___6 ;

  {
  tmp = __errno_location();
  *tmp = 0;
  tmp___0 = strxfrm(dest, src, destsize);
  translated_size = tmp___0;
  tmp___6 = __errno_location();
  if (*tmp___6) {
    tmp___1 = gettext("string transformation failed");
    tmp___2 = __errno_location();
    error(0, *tmp___2, (char const   *)tmp___1);
    tmp___3 = gettext("set LC_ALL=\'C\' to work around the problem");
    error(0, 0, (char const   *)tmp___3);
    tmp___4 = quotearg_n_style(0, (enum quoting_style )6, (char const   *)src);
    tmp___5 = gettext("the untransformed string was %s");
    error(2, 0, (char const   *)tmp___5, tmp___4);
  }
  return (translated_size);
}
}
static int compare_random(char * __restrict  texta , size_t lena , char * __restrict  textb ,
                          size_t lenb ) 
{ 
  int xfrm_diff ;
  char stackbuf[4000] ;
  char *buf___1 ;
  size_t bufsize___1 ;
  void *allocated ;
  uint32_t dig[2][16UL / sizeof(uint32_t )] ;
  struct md5_ctx s[2] ;
  char const   *lima ;
  char const   *limb ;
  size_t guess_bufsize ;
  size_t sizea ;
  size_t tmp ;
  size_t tmp___0 ;
  _Bool a_fits ;
  size_t sizeb ;
  size_t tmp___1 ;
  char *tmp___2 ;
  size_t tmp___3 ;
  size_t tmp___4 ;
  size_t tmp___5 ;
  size_t tmp___6 ;
  size_t tmp___7 ;
  int diff ;
  int tmp___8 ;
  size_t tmp___9 ;

  {
  xfrm_diff = 0;
  buf___1 = stackbuf;
  bufsize___1 = sizeof(stackbuf);
  allocated = (void *)0;
  s[1] = random_md5_state;
  s[0] = s[1];
  if (hard_LC_COLLATE) {
    lima = (char const   *)(texta + lena);
    limb = (char const   *)(textb + lenb);
    while (1) {
      guess_bufsize = 3UL * (lena + lenb) + 2UL;
      if (bufsize___1 < guess_bufsize) {
        if (guess_bufsize > (bufsize___1 * 3UL) / 2UL) {
          bufsize___1 = guess_bufsize;
        } else {
          bufsize___1 = (bufsize___1 * 3UL) / 2UL;
        }
        free(allocated);
        allocated = malloc(bufsize___1);
        buf___1 = (char *)allocated;
        if (! buf___1) {
          buf___1 = stackbuf;
          bufsize___1 = sizeof(stackbuf);
        }
      }
      if ((unsigned long )texta < (unsigned long )lima) {
        tmp = xstrxfrm(buf___1, (char const   *)texta, bufsize___1);
        tmp___0 = tmp + 1UL;
      } else {
        tmp___0 = (size_t )0;
      }
      sizea = tmp___0;
      a_fits = (_Bool )(sizea <= bufsize___1);
      if ((unsigned long )textb < (unsigned long )limb) {
        if (a_fits) {
          tmp___1 = bufsize___1 - sizea;
        } else {
          tmp___1 = (size_t )0;
        }
        if (a_fits) {
          tmp___2 = buf___1 + sizea;
        } else {
          tmp___2 = (char *)((void *)0);
        }
        tmp___3 = xstrxfrm(tmp___2, (char const   *)textb, tmp___1);
        tmp___4 = tmp___3 + 1UL;
      } else {
        tmp___4 = (size_t )0;
      }
      sizeb = tmp___4;
      if (a_fits) {
        if (! (sizea + sizeb <= bufsize___1)) {
          goto _L;
        }
      } else {
        _L: 
        bufsize___1 = sizea + sizeb;
        if (bufsize___1 < 6148914691236517205UL) {
          bufsize___1 = (bufsize___1 * 3UL) / 2UL;
        }
        free(allocated);
        allocated = xmalloc(bufsize___1);
        buf___1 = (char *)allocated;
        if ((unsigned long )texta < (unsigned long )lima) {
          strxfrm(buf___1, (char const   *)texta, sizea);
        }
        if ((unsigned long )textb < (unsigned long )limb) {
          strxfrm(buf___1 + sizea, (char const   *)textb, sizeb);
        }
      }
      if ((unsigned long )texta < (unsigned long )lima) {
        tmp___5 = strlen((char const   *)texta);
        texta += tmp___5 + 1UL;
      }
      if ((unsigned long )textb < (unsigned long )limb) {
        tmp___6 = strlen((char const   *)textb);
        textb += tmp___6 + 1UL;
      }
      if (! ((unsigned long )texta < (unsigned long )lima)) {
        if (! ((unsigned long )textb < (unsigned long )limb)) {
          lena = sizea;
          texta = buf___1;
          lenb = sizeb;
          textb = buf___1 + sizea;
          goto while_break;
        }
      }
      md5_process_bytes((void const   *)buf___1, sizea, & s[0]);
      md5_process_bytes((void const   *)(buf___1 + sizea), sizeb, & s[1]);
      if (! xfrm_diff) {
        if (sizea < sizeb) {
          tmp___7 = sizea;
        } else {
          tmp___7 = sizeb;
        }
        xfrm_diff = memcmp((void const   *)buf___1, (void const   *)(buf___1 + sizea),
                           tmp___7);
        if (! xfrm_diff) {
          xfrm_diff = (sizea > sizeb) - (sizea < sizeb);
        }
      }
    }
    while_break: ;
  }
  md5_process_bytes((void const   *)texta, lena, & s[0]);
  md5_finish_ctx(& s[0], (void *)(dig[0]));
  md5_process_bytes((void const   *)textb, lenb, & s[1]);
  md5_finish_ctx(& s[1], (void *)(dig[1]));
  tmp___8 = memcmp((void const   *)(dig[0]), (void const   *)(dig[1]), sizeof(dig[0]));
  diff = tmp___8;
  if (! diff) {
    if (! xfrm_diff) {
      if (lena < lenb) {
        tmp___9 = lena;
      } else {
        tmp___9 = lenb;
      }
      xfrm_diff = memcmp((void const   *)texta, (void const   *)textb, tmp___9);
      if (! xfrm_diff) {
        xfrm_diff = (lena > lenb) - (lena < lenb);
      }
    }
    diff = xfrm_diff;
  }
  free(allocated);
  return (diff);
}
}
static size_t debug_width(char const   *text , char const   *lim ) 
{ 
  size_t width ;
  size_t tmp ;
  char const   *tmp___0 ;

  {
  tmp = (size_t )mbsnwidth(text, (size_t )(lim - text), 0);
  width = tmp;
  while (1) {

    if (! ((unsigned long )text < (unsigned long )lim)) {
      goto while_break;
    }
    tmp___0 = text;
    text ++;
    width += (size_t )((int const   )*tmp___0 == 9);
  }
  while_break: ;
  return (width);
}
}
static void mark_key(size_t offset , size_t width ) 
{ 
  size_t tmp ;
  char *tmp___0 ;

  {
  while (1) {
    tmp = offset;
    offset --;
    if (! tmp) {
      goto while_break;
    }
    putchar_unlocked(' ');
  }
  while_break: ;
  if (! width) {
    tmp___0 = gettext("^ no match for key\n");
    printf((char const   *)tmp___0);
  } else {
    while (1) {
      putchar_unlocked('_');
      width --;
      if (! width) {
        goto while_break___0;
      }
    }
    while_break___0: 
    putchar_unlocked('\n');
  }
  return;
}
}
__inline static _Bool key_numeric(struct keyfield  const  *key ) 
{ 
  int tmp ;

  {
  if (key->numeric) {
    tmp = 1;
  } else
  if (key->general_numeric) {
    tmp = 1;
  } else
  if (key->human_numeric) {
    tmp = 1;
  } else {
    tmp = 0;
  }
  return ((_Bool )tmp);
}
}
static void debug_key(struct line  const  *line , struct keyfield  const  *key ) 
{ 
  char *text ;
  char *beg ;
  char *lim ;
  char saved___0 ;
  unsigned char tmp ;
  char *tighter_lim ;
  long double __x ;
  long double tmp___0 ;
  char *p ;
  int tmp___1 ;
  _Bool found_digit ;
  unsigned char ch ;
  char *tmp___2 ;
  char *tmp___3 ;
  int tmp___4 ;
  _Bool tmp___5 ;
  size_t offset ;
  size_t tmp___6 ;
  size_t width ;
  size_t tmp___7 ;

  {
  text = (char *)line->text;
  beg = text;
  lim = (text + line->length) - 1;
  if (key) {
    if (key->sword != 0xffffffffffffffffUL) {
      beg = begfield(line, key);
    }
    if (key->eword != 0xffffffffffffffffUL) {
      lim = limfield(line, key);
    }
    if (key->skipsblanks) {
      goto _L___0;
    } else
    if (key->month) {
      goto _L___0;
    } else {
      tmp___5 = key_numeric(key);
      if (tmp___5) {
        _L___0: 
        saved___0 = *lim;
        *lim = (char )'\000';
        while (1) {
          tmp = to_uchar(*beg);
          if (! blanks[tmp]) {
            goto while_break;
          }
          beg ++;
        }
        while_break: 
        tighter_lim = beg;
        if ((unsigned long )lim < (unsigned long )beg) {
          tighter_lim = lim;
        } else
        if (key->month) {
          getmonth((char const   *)beg, & tighter_lim);
        } else
        if (key->general_numeric) {
          tmp___0 = strtold((char const   *)beg, & tighter_lim);
          __x = tmp___0;
        } else
        if (key->numeric) {
          goto _L;
        } else
        if (key->human_numeric) {
          _L: 
          if ((unsigned long )beg < (unsigned long )lim) {
            if ((int )*beg == 45) {
              tmp___1 = 1;
            } else {
              tmp___1 = 0;
            }
          } else {
            tmp___1 = 0;
          }
          p = beg + tmp___1;
          found_digit = (_Bool)0;
          while (1) {

            while (1) {
              tmp___2 = p;
              p ++;
              ch = (unsigned char )*tmp___2;
              if (! ((unsigned int )ch - 48U <= 9U)) {
                goto while_break___1;
              }
              found_digit = (_Bool)1;
            }
            while_break___1: ;
            if (! ((int )ch == thousands_sep)) {
              goto while_break___0;
            }
          }
          while_break___0: ;
          if ((int )ch == decimal_point) {
            while (1) {
              tmp___3 = p;
              p ++;
              ch = (unsigned char )*tmp___3;
              if (! ((unsigned int )ch - 48U <= 9U)) {
                goto while_break___2;
              }
              found_digit = (_Bool)1;
            }
            while_break___2: ;
          }
          if (found_digit) {
            if (key->human_numeric) {
              if (unit_order[ch]) {
                tmp___4 = 0;
              } else {
                tmp___4 = 1;
              }
            } else {
              tmp___4 = 1;
            }
            tighter_lim = p - tmp___4;
          }
        } else {
          tighter_lim = lim;
        }
        *lim = saved___0;
        lim = tighter_lim;
      }
    }
  }
  tmp___6 = debug_width((char const   *)text, (char const   *)beg);
  offset = tmp___6;
  tmp___7 = debug_width((char const   *)beg, (char const   *)lim);
  width = tmp___7;
  mark_key(offset, width);
  return;
}
}
static void debug_line(struct line  const  *line ) 
{ 
  struct keyfield  const  *key ;

  {
  key = (struct keyfield  const  *)keylist;
  while (1) {
    debug_key(line, key);
    if (key) {
      key = (struct keyfield  const  *)key->next;
      if (! key) {
        if (unique) {
          goto while_break;
        } else
        if (stable) {
          goto while_break;
        }
      }
    } else {
      goto while_break;
    }
  }
  while_break: ;
  return;
}
}
static _Bool default_key_compare(struct keyfield  const  *key ) 
{ 
  _Bool tmp ;
  int tmp___0 ;

  {
  if (key->ignore) {
    tmp___0 = 0;
  } else
  if (key->translate) {
    tmp___0 = 0;
  } else
  if (key->skipsblanks) {
    tmp___0 = 0;
  } else
  if (key->skipeblanks) {
    tmp___0 = 0;
  } else {
    tmp = key_numeric(key);
    if (tmp) {
      tmp___0 = 0;
    } else
    if (key->month) {
      tmp___0 = 0;
    } else
    if (key->version) {
      tmp___0 = 0;
    } else
    if (key->random) {
      tmp___0 = 0;
    } else {
      tmp___0 = 1;
    }
  }
  return ((_Bool )tmp___0);
}
}
static void key_to_opts(struct keyfield  const  *key , char *opts___1 ) 
{ 
  char *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  char *tmp___6 ;
  char *tmp___7 ;
  char *tmp___8 ;
  char *tmp___9 ;

  {
  if (key->skipsblanks) {
    tmp = opts___1;
    opts___1 ++;
    *tmp = (char )'b';
  } else
  if (key->skipeblanks) {
    tmp = opts___1;
    opts___1 ++;
    *tmp = (char )'b';
  }
  if ((unsigned long )key->ignore == (unsigned long )(nondictionary)) {
    tmp___0 = opts___1;
    opts___1 ++;
    *tmp___0 = (char )'d';
  }
  if (key->translate) {
    tmp___1 = opts___1;
    opts___1 ++;
    *tmp___1 = (char )'f';
  }
  if (key->general_numeric) {
    tmp___2 = opts___1;
    opts___1 ++;
    *tmp___2 = (char )'g';
  }
  if (key->human_numeric) {
    tmp___3 = opts___1;
    opts___1 ++;
    *tmp___3 = (char )'h';
  }
  if ((unsigned long )key->ignore == (unsigned long )(nonprinting)) {
    tmp___4 = opts___1;
    opts___1 ++;
    *tmp___4 = (char )'i';
  }
  if (key->month) {
    tmp___5 = opts___1;
    opts___1 ++;
    *tmp___5 = (char )'M';
  }
  if (key->numeric) {
    tmp___6 = opts___1;
    opts___1 ++;
    *tmp___6 = (char )'n';
  }
  if (key->random) {
    tmp___7 = opts___1;
    opts___1 ++;
    *tmp___7 = (char )'R';
  }
  if (key->reverse) {
    tmp___8 = opts___1;
    opts___1 ++;
    *tmp___8 = (char )'r';
  }
  if (key->version) {
    tmp___9 = opts___1;
    opts___1 ++;
    *tmp___9 = (char )'V';
  }
  *opts___1 = (char )'\000';
  return;
}
}
static void key_warnings(struct keyfield  const  *gkey , _Bool gkey_only ) 
{ 
  struct keyfield  const  *key ;
  struct keyfield ugkey ;
  unsigned long keynum ;
  size_t sword ;
  size_t eword ;
  char tmp[((sizeof(uintmax_t ) * 8UL) * 146UL + 484UL) / 485UL + 1UL] ;
  char obuf[(((sizeof(sword) * 8UL) * 146UL + 484UL) / 485UL + 1UL) * 2UL + 4UL] ;
  char nbuf[(((sizeof(sword) * 8UL) * 146UL + 484UL) / 485UL + 1UL) * 2UL + 5UL] ;
  char *po ;
  char *pn ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  char *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  char *tmp___6 ;
  char *tmp___7 ;
  char const   *tmp___8 ;
  char const   *tmp___9 ;
  char *tmp___10 ;
  char *tmp___11 ;
  _Bool implicit_skip ;
  _Bool tmp___12 ;
  int tmp___13 ;
  _Bool maybe_space_aligned ;
  _Bool tmp___14 ;
  int tmp___15 ;
  _Bool line_offset ;
  int tmp___16 ;
  char *tmp___17 ;
  size_t sword___0 ;
  size_t eword___0 ;
  char *tmp___18 ;
  _Bool tmp___19 ;
  _Bool ugkey_reverse ;
  char opts___1[sizeof(short_options)] ;
  size_t tmp___20 ;
  unsigned long tmp___21 ;
  char *tmp___22 ;
  _Bool tmp___23 ;
  char *tmp___24 ;

  {
  ugkey = (struct keyfield )*gkey;
  keynum = 1UL;
  key = (struct keyfield  const  *)keylist;
  while (1) {

    if (! key) {
      goto while_break;
    }
    if (key->obsolete_used) {
      sword = (size_t )key->sword;
      eword = (size_t )key->eword;
      po = obuf;
      pn = nbuf;
      if (sword == 0xffffffffffffffffUL) {
        sword ++;
      }
      tmp___0 = umaxtostr(sword, tmp);
      tmp___1 = stpcpy(po, "+");
      po = stpcpy(tmp___1, (char const   *)tmp___0);
      tmp___2 = umaxtostr(sword + 1UL, tmp);
      tmp___3 = stpcpy(pn, "-k ");
      pn = stpcpy(tmp___3, (char const   *)tmp___2);
      if (key->eword != 0xffffffffffffffffUL) {
        tmp___4 = umaxtostr(eword + 1UL, tmp);
        tmp___5 = stpcpy(po, " -");
        stpcpy(tmp___5, (char const   *)tmp___4);
        tmp___6 = umaxtostr((eword + 1UL) + (size_t )(key->echar == 0xffffffffffffffffUL),
                            tmp);
        tmp___7 = stpcpy(pn, ",");
        stpcpy(tmp___7, (char const   *)tmp___6);
      }
      tmp___8 = quote_n(1, (char const   *)(nbuf));
      tmp___9 = quote_n(0, (char const   *)(obuf));
      tmp___10 = gettext("obsolescent key %s used; consider %s instead");
      error(0, 0, (char const   *)tmp___10, tmp___9, tmp___8);
    }
    if (key->sword != 0xffffffffffffffffUL) {
      if (key->eword < key->sword) {
        tmp___11 = gettext("key %lu has zero width and will be ignored");
        error(0, 0, (char const   *)tmp___11, keynum);
      }
    }
    tmp___12 = key_numeric(key);
    if (tmp___12) {
      tmp___13 = 1;
    } else
    if (key->month) {
      tmp___13 = 1;
    } else {
      tmp___13 = 0;
    }
    implicit_skip = (_Bool )tmp___13;
    if (! hard_LC_COLLATE) {
      tmp___14 = default_key_compare(key);
      if (tmp___14) {
        if (key->schar) {
          tmp___15 = 0;
        } else
        if (key->echar) {
          tmp___15 = 0;
        } else {
          tmp___15 = 1;
        }
      } else {
        tmp___15 = 0;
      }
    } else {
      tmp___15 = 0;
    }
    maybe_space_aligned = (_Bool )tmp___15;
    if (key->eword == 0UL) {
      if (key->echar != 0UL) {
        tmp___16 = 1;
      } else {
        tmp___16 = 0;
      }
    } else {
      tmp___16 = 0;
    }
    line_offset = (_Bool )tmp___16;
    if (! gkey_only) {
      if (tab == 128) {
        if (! line_offset) {
          if (! key->skipsblanks) {
            if (implicit_skip) {
              goto _L___0;
            } else
            if (maybe_space_aligned) {
              goto _L___0;
            } else {
              tmp___17 = gettext("leading blanks are significant in key %lu; consider also specifying \'b\'");
              error(0, 0, (char const   *)tmp___17, keynum);
            }
          } else
          _L___0: 
          if (! key->skipsblanks) {
            if (key->schar) {
              tmp___17 = gettext("leading blanks are significant in key %lu; consider also specifying \'b\'");
              error(0, 0, (char const   *)tmp___17, keynum);
            } else {
              goto _L;
            }
          } else
          _L: 
          if (! key->skipeblanks) {
            if (key->echar) {
              tmp___17 = gettext("leading blanks are significant in key %lu; consider also specifying \'b\'");
              error(0, 0, (char const   *)tmp___17, keynum);
            }
          }
        }
      }
    }
    if (! gkey_only) {
      tmp___19 = key_numeric(key);
      if (tmp___19) {
        sword___0 = (size_t )(key->sword + 1UL);
        eword___0 = (size_t )(key->eword + 1UL);
        if (! sword___0) {
          sword___0 ++;
        }
        if (! eword___0) {
          tmp___18 = gettext("key %lu is numeric and spans multiple fields");
          error(0, 0, (char const   *)tmp___18, keynum);
        } else
        if (sword___0 < eword___0) {
          tmp___18 = gettext("key %lu is numeric and spans multiple fields");
          error(0, 0, (char const   *)tmp___18, keynum);
        }
      }
    }
    if (ugkey.ignore) {
      if ((unsigned long )ugkey.ignore == (unsigned long )key->ignore) {
        ugkey.ignore = (_Bool const   *)((void *)0);
      }
    }
    if (ugkey.translate) {
      if ((unsigned long )ugkey.translate == (unsigned long )key->translate) {
        ugkey.translate = (char const   *)((void *)0);
      }
    }
    ugkey.skipsblanks = (_Bool )((int )ugkey.skipsblanks & ! key->skipsblanks);
    ugkey.skipeblanks = (_Bool )((int )ugkey.skipeblanks & ! key->skipeblanks);
    ugkey.month = (_Bool )((int )ugkey.month & ! key->month);
    ugkey.numeric = (_Bool )((int )ugkey.numeric & ! key->numeric);
    ugkey.general_numeric = (_Bool )((int )ugkey.general_numeric & ! key->general_numeric);
    ugkey.human_numeric = (_Bool )((int )ugkey.human_numeric & ! key->human_numeric);
    ugkey.random = (_Bool )((int )ugkey.random & ! key->random);
    ugkey.version = (_Bool )((int )ugkey.version & ! key->version);
    ugkey.reverse = (_Bool )((int )ugkey.reverse & ! key->reverse);
    key = (struct keyfield  const  *)key->next;
    keynum ++;
  }
  while_break: 
  tmp___23 = default_key_compare((struct keyfield  const  *)(& ugkey));
  if (tmp___23) {
    if (ugkey.reverse) {
      if (stable) {
        goto _L___2;
      } else
      if (unique) {
        _L___2: 
        if (keylist) {
          _L___1: 
          ugkey_reverse = ugkey.reverse;
          if (! stable) {
            if (! unique) {
              ugkey.reverse = (_Bool)0;
            }
          }
          key_to_opts((struct keyfield  const  *)(& ugkey), opts___1);
          tmp___20 = strlen((char const   *)(opts___1));
          tmp___21 = select_plural(tmp___20);
          tmp___22 = ngettext("option \'-%s\' is ignored", "options \'-%s\' are ignored",
                              tmp___21);
          error(0, 0, (char const   *)tmp___22, opts___1);
          ugkey.reverse = ugkey_reverse;
        }
      }
    }
  } else {
    goto _L___1;
  }
  if (ugkey.reverse) {
    if (! stable) {
      if (! unique) {
        if (keylist) {
          tmp___24 = gettext("option \'-r\' only applies to last-resort comparison");
          error(0, 0, (char const   *)tmp___24);
        }
      }
    }
  }
  return;
}
}
static int keycompare(struct line  const  *a , struct line  const  *b ) 
{ 
  struct keyfield *key ;
  char *texta ;
  char *textb ;
  char *lima ;
  char *limb ;
  int diff ;
  char const   *translate ;
  _Bool const   *ignore ;
  size_t lena ;
  size_t lenb ;
  char *ta ;
  char *tb ;
  size_t tlena ;
  size_t tlenb ;
  char enda ;
  char endb ;
  void *allocated ;
  char stackbuf[4000] ;
  size_t i ;
  size_t size ;
  size_t tmp ;
  unsigned char tmp___0 ;
  unsigned char tmp___1 ;
  size_t tmp___2 ;
  unsigned char tmp___3 ;
  unsigned char tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  unsigned char tmp___7 ;
  unsigned char tmp___8 ;
  unsigned char tmp___9 ;
  unsigned char tmp___10 ;
  unsigned char tmp___11 ;
  unsigned char tmp___12 ;
  unsigned char tmp___13 ;
  unsigned char tmp___14 ;
  unsigned char tmp___15 ;
  unsigned char tmp___16 ;
  char *tmp___17 ;
  unsigned char tmp___18 ;
  unsigned char tmp___19 ;
  char *tmp___20 ;
  unsigned char tmp___21 ;
  unsigned char tmp___22 ;
  size_t tmp___23 ;
  _Bool tmp___24 ;
  unsigned char tmp___25 ;
  unsigned char tmp___26 ;
  int tmp___27 ;

  {
  key = keylist;
  texta = (char *)a->keybeg;
  textb = (char *)b->keybeg;
  lima = (char *)a->keylim;
  limb = (char *)b->keylim;
  while (1) {
    translate = key->translate;
    ignore = key->ignore;
    if ((unsigned long )texta > (unsigned long )lima) {
      lima = texta;
    } else {
      lima = lima;
    }
    if ((unsigned long )textb > (unsigned long )limb) {
      limb = textb;
    } else {
      limb = limb;
    }
    lena = (size_t )(lima - texta);
    lenb = (size_t )(limb - textb);
    if (hard_LC_COLLATE) {
      goto _L___2;
    } else {
      tmp___24 = key_numeric((struct keyfield  const  *)key);
      if (tmp___24) {
        goto _L___2;
      } else
      if (key->month) {
        goto _L___2;
      } else
      if (key->random) {
        goto _L___2;
      } else
      if (key->version) {
        _L___2: 
        if (ignore) {
          goto _L___1;
        } else
        if (translate) {
          _L___1: 
          size = ((lena + 1UL) + lenb) + 1UL;
          if (size <= sizeof(stackbuf)) {
            ta = stackbuf;
            allocated = (void *)0;
          } else {
            allocated = xmalloc(size);
            ta = (char *)allocated;
          }
          tb = (ta + lena) + 1;
          i = (size_t )0;
          tlena = i;
          while (1) {

            if (! (i < lena)) {
              goto while_break___0;
            }
            if (ignore) {
              tmp___1 = to_uchar(*(texta + i));
              if (! *(ignore + (int )tmp___1)) {
                goto _L;
              }
            } else {
              _L: 
              tmp = tlena;
              tlena ++;
              if (translate) {
                tmp___0 = to_uchar(*(texta + i));
                *(ta + tmp) = (char )*(translate + (int )tmp___0);
              } else {
                *(ta + tmp) = *(texta + i);
              }
            }
            i ++;
          }
          while_break___0: 
          *(ta + tlena) = (char )'\000';
          i = (size_t )0;
          tlenb = i;
          while (1) {

            if (! (i < lenb)) {
              goto while_break___1;
            }
            if (ignore) {
              tmp___4 = to_uchar(*(textb + i));
              if (! *(ignore + (int )tmp___4)) {
                goto _L___0;
              }
            } else {
              _L___0: 
              tmp___2 = tlenb;
              tlenb ++;
              if (translate) {
                tmp___3 = to_uchar(*(textb + i));
                *(tb + tmp___2) = (char )*(translate + (int )tmp___3);
              } else {
                *(tb + tmp___2) = *(textb + i);
              }
            }
            i ++;
          }
          while_break___1: 
          *(tb + tlenb) = (char )'\000';
        } else {
          ta = texta;
          tlena = lena;
          enda = *(ta + tlena);
          *(ta + tlena) = (char )'\000';
          tb = textb;
          tlenb = lenb;
          endb = *(tb + tlenb);
          *(tb + tlenb) = (char )'\000';
        }
        if (key->numeric) {
          diff = numcompare___3((char const   *)ta, (char const   *)tb);
        } else
        if (key->general_numeric) {
          diff = general_numcompare((char const   *)ta, (char const   *)tb);
        } else
        if (key->human_numeric) {
          diff = human_numcompare((char const   *)ta, (char const   *)tb);
        } else
        if (key->month) {
          tmp___5 = getmonth((char const   *)ta, (char **)((void *)0));
          tmp___6 = getmonth((char const   *)tb, (char **)((void *)0));
          diff = tmp___5 - tmp___6;
        } else
        if (key->random) {
          diff = compare_random(ta, tlena, tb, tlenb);
        } else
        if (key->version) {
          diff = filevercmp((char const   *)ta, (char const   *)tb);
        } else
        if (tlena == 0UL) {
          diff = - (tlenb != 0UL);
        } else
        if (tlenb == 0UL) {
          diff = 1;
        } else {
          diff = xmemcoll0((char const   *)ta, tlena + 1UL, (char const   *)tb, tlenb + 1UL);
        }
        if (ignore) {
          free(allocated);
        } else
        if (translate) {
          free(allocated);
        } else {
          *(ta + tlena) = enda;
          *(tb + tlenb) = endb;
        }
      } else
      if (ignore) {
        if (translate) {
          while (1) {

            while (1) {

              while (1) {

                if ((unsigned long )texta < (unsigned long )lima) {
                  tmp___7 = to_uchar(*texta);
                  if (! *(ignore + (int )tmp___7)) {
                    goto while_break___4;
                  }
                } else {
                  goto while_break___4;
                }
                texta ++;
              }
              while_break___4: ;
              while (1) {

                if ((unsigned long )textb < (unsigned long )limb) {
                  tmp___8 = to_uchar(*textb);
                  if (! *(ignore + (int )tmp___8)) {
                    goto while_break___5;
                  }
                } else {
                  goto while_break___5;
                }
                textb ++;
              }
              while_break___5: ;
              if ((unsigned long )texta < (unsigned long )lima) {
                if (! ((unsigned long )textb < (unsigned long )limb)) {
                  goto while_break___3;
                }
              } else {
                goto while_break___3;
              }
              tmp___9 = to_uchar(*texta);
              tmp___10 = to_uchar((char )*(translate + (int )tmp___9));
              tmp___11 = to_uchar(*textb);
              tmp___12 = to_uchar((char )*(translate + (int )tmp___11));
              diff = (int )tmp___10 - (int )tmp___12;
              if (diff) {
                goto not_equal;
              }
              texta ++;
              textb ++;
            }
            while_break___3: 
            diff = ((unsigned long )texta < (unsigned long )lima) - ((unsigned long )textb < (unsigned long )limb);
            goto while_break___2;
          }
          while_break___2: ;
        } else {
          while (1) {

            while (1) {

              while (1) {

                if ((unsigned long )texta < (unsigned long )lima) {
                  tmp___13 = to_uchar(*texta);
                  if (! *(ignore + (int )tmp___13)) {
                    goto while_break___8;
                  }
                } else {
                  goto while_break___8;
                }
                texta ++;
              }
              while_break___8: ;
              while (1) {

                if ((unsigned long )textb < (unsigned long )limb) {
                  tmp___14 = to_uchar(*textb);
                  if (! *(ignore + (int )tmp___14)) {
                    goto while_break___9;
                  }
                } else {
                  goto while_break___9;
                }
                textb ++;
              }
              while_break___9: ;
              if ((unsigned long )texta < (unsigned long )lima) {
                if (! ((unsigned long )textb < (unsigned long )limb)) {
                  goto while_break___7;
                }
              } else {
                goto while_break___7;
              }
              tmp___15 = to_uchar(*texta);
              tmp___16 = to_uchar(*textb);
              diff = (int )tmp___15 - (int )tmp___16;
              if (diff) {
                goto not_equal;
              }
              texta ++;
              textb ++;
            }
            while_break___7: 
            diff = ((unsigned long )texta < (unsigned long )lima) - ((unsigned long )textb < (unsigned long )limb);
            goto while_break___6;
          }
          while_break___6: ;
        }
      } else
      if (lena == 0UL) {
        diff = - (lenb != 0UL);
      } else
      if (lenb == 0UL) {
        goto greater;
      } else {
        if (translate) {
          while (1) {

            if ((unsigned long )texta < (unsigned long )lima) {
              if (! ((unsigned long )textb < (unsigned long )limb)) {
                goto while_break___10;
              }
            } else {
              goto while_break___10;
            }
            tmp___17 = texta;
            texta ++;
            tmp___18 = to_uchar(*tmp___17);
            tmp___19 = to_uchar((char )*(translate + (int )tmp___18));
            tmp___20 = textb;
            textb ++;
            tmp___21 = to_uchar(*tmp___20);
            tmp___22 = to_uchar((char )*(translate + (int )tmp___21));
            diff = (int )tmp___19 - (int )tmp___22;
            if (diff) {
              goto not_equal;
            }
          }
          while_break___10: ;
        } else {
          if (lena < lenb) {
            tmp___23 = lena;
          } else {
            tmp___23 = lenb;
          }
          diff = memcmp((void const   *)texta, (void const   *)textb, tmp___23);
          if (diff) {
            goto not_equal;
          }
        }
        if (lena < lenb) {
          diff = -1;
        } else {
          diff = lena != lenb;
        }
      }
    }
    if (diff) {
      goto not_equal;
    }
    key = key->next;
    if (! key) {
      goto while_break;
    }
    if (key->eword != 0xffffffffffffffffUL) {
      lima = limfield(a, (struct keyfield  const  *)key);
      limb = limfield(b, (struct keyfield  const  *)key);
    } else {
      lima = (char *)((a->text + a->length) - 1);
      limb = (char *)((b->text + b->length) - 1);
    }
    if (key->sword != 0xffffffffffffffffUL) {
      texta = begfield(a, (struct keyfield  const  *)key);
      textb = begfield(b, (struct keyfield  const  *)key);
    } else {
      texta = (char *)a->text;
      textb = (char *)b->text;
      if (key->skipsblanks) {
        while (1) {

          if ((unsigned long )texta < (unsigned long )lima) {
            tmp___25 = to_uchar(*texta);
            if (! blanks[tmp___25]) {
              goto while_break___11;
            }
          } else {
            goto while_break___11;
          }
          texta ++;
        }
        while_break___11: ;
        while (1) {

          if ((unsigned long )textb < (unsigned long )limb) {
            tmp___26 = to_uchar(*textb);
            if (! blanks[tmp___26]) {
              goto while_break___12;
            }
          } else {
            goto while_break___12;
          }
          textb ++;
        }
        while_break___12: ;
      }
    }
  }
  while_break: ;
  return (0);
  greater: 
  diff = 1;
  not_equal: 
  if (key->reverse) {
    tmp___27 = - diff;
  } else {
    tmp___27 = diff;
  }
  return (tmp___27);
}
}
static int compare(struct line  const  *a , struct line  const  *b ) 
{ 
  int diff ;
  size_t alen ;
  size_t blen ;
  size_t tmp ;
  int tmp___0 ;

  {
  if (keylist) {
    diff = keycompare(a, b);
    if (diff) {
      return (diff);
    } else
    if (unique) {
      return (diff);
    } else
    if (stable) {
      return (diff);
    }
  }
  alen = (size_t )(a->length - 1UL);
  blen = (size_t )(b->length - 1UL);
  if (alen == 0UL) {
    diff = - (blen != 0UL);
  } else
  if (blen == 0UL) {
    diff = 1;
  } else
  if (hard_LC_COLLATE) {
    diff = xmemcoll0((char const   *)a->text, alen + 1UL, (char const   *)b->text,
                     blen + 1UL);
  } else {
    if (alen < blen) {
      tmp = alen;
    } else {
      tmp = blen;
    }
    diff = memcmp((void const   *)a->text, (void const   *)b->text, tmp);
    if (! diff) {
      if (alen < blen) {
        diff = -1;
      } else {
        diff = alen != blen;
      }
    }
  }
  if (reverse) {
    tmp___0 = - diff;
  } else {
    tmp___0 = diff;
  }
  return (tmp___0);
}
}
static void write_line(struct line  const  *line , FILE *fp , char const   *output_file ) 
{ 
  char *buf___1 ;
  size_t n_bytes ;
  char *ebuf ;
  char const   *c ;
  char wc ;
  char const   *tmp ;
  char *tmp___0 ;
  int tmp___1 ;
  char *tmp___2 ;
  size_t tmp___3 ;

  {
  buf___1 = (char *)line->text;
  n_bytes = (size_t )line->length;
  ebuf = buf___1 + n_bytes;
  if (! output_file) {
    if (debug) {
      c = (char const   *)buf___1;
      while (1) {

        if (! ((unsigned long )c < (unsigned long )ebuf)) {
          goto while_break;
        }
        tmp = c;
        c ++;
        wc = (char )*tmp;
        if ((int )wc == 9) {
          wc = (char )'>';
        } else
        if ((unsigned long )c == (unsigned long )ebuf) {
          wc = (char )'\n';
        }
        tmp___1 = fputc_unlocked((int )wc, fp);
        if (tmp___1 == -1) {
          tmp___0 = gettext("write failed");
          die((char const   *)tmp___0, output_file);
        }
      }
      while_break: 
      debug_line(line);
    } else {
      goto _L;
    }
  } else {
    _L: 
    *(ebuf + -1) = eolchar;
    tmp___3 = fwrite_unlocked((void const   *)buf___1, (size_t )1, n_bytes, fp);
    if (tmp___3 != n_bytes) {
      tmp___2 = gettext("write failed");
      die((char const   *)tmp___2, output_file);
    }
    *(ebuf + -1) = (char )'\000';
  }
  return;
}
}
static _Bool check(char const   *file_name___3 , char checkonly ) 
{ 
  FILE *fp ;
  FILE *tmp ;
  struct buffer buf___1 ;
  struct line temp ;
  size_t alloc ;
  uintmax_t line_number ;
  struct keyfield  const  *key ;
  _Bool nonunique ;
  _Bool ordered ;
  size_t tmp___0 ;
  struct line  const  *line ;
  struct line  const  *tmp___1 ;
  struct line  const  *linebase ;
  struct line  const  *disorder_line ;
  uintmax_t disorder_line_number ;
  struct line *tmp___2 ;
  char hr_buf[((sizeof(disorder_line_number) * 8UL) * 146UL + 484UL) / 485UL + 1UL] ;
  char *tmp___3 ;
  char *tmp___4 ;
  char *tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  _Bool tmp___8 ;

  {
  tmp = xfopen(file_name___3, "r");
  fp = tmp;
  alloc = (size_t )0;
  line_number = (uintmax_t )0;
  key = (struct keyfield  const  *)keylist;
  nonunique = (_Bool )(! unique);
  ordered = (_Bool)1;
  if (merge_buffer_size > sort_size) {
    tmp___0 = merge_buffer_size;
  } else {
    tmp___0 = sort_size;
  }
  initbuf(& buf___1, sizeof(struct line ), tmp___0);
  temp.text = (char *)((void *)0);
  while (1) {
    tmp___8 = fillbuf___7(& buf___1, fp, file_name___3);
    if (! tmp___8) {
      goto while_break;
    }
    tmp___1 = (struct line  const  *)buffer_linelim((struct buffer  const  *)(& buf___1));
    line = tmp___1;
    linebase = line - buf___1.nlines;
    if (alloc) {
      tmp___6 = compare((struct line  const  *)(& temp), line - 1);
      if ((int )nonunique <= tmp___6) {
        found_disorder: 
        if ((int )checkonly == 99) {
          disorder_line = line - 1;
          tmp___2 = buffer_linelim((struct buffer  const  *)(& buf___1));
          disorder_line_number = (uintmax_t )(tmp___2 - (struct line *)disorder_line) + line_number;
          tmp___3 = umaxtostr(disorder_line_number, hr_buf);
          tmp___4 = gettext("%s: %s:%s: disorder: ");
          fprintf(stderr, (char const   *)tmp___4, program_name, file_name___3, tmp___3);
          tmp___5 = gettext("standard error");
          write_line(disorder_line, stderr, (char const   *)tmp___5);
        }
        ordered = (_Bool)0;
        goto while_break;
      }
    }
    while (1) {
      line --;
      if (! ((unsigned long )linebase < (unsigned long )line)) {
        goto while_break___0;
      }
      tmp___7 = compare(line, line - 1);
      if ((int )nonunique <= tmp___7) {
        goto found_disorder;
      }
    }
    while_break___0: 
    line_number += buf___1.nlines;
    if (alloc < (size_t )line->length) {
      while (1) {
        alloc *= 2UL;
        if (! alloc) {
          alloc = (size_t )line->length;
          goto while_break___1;
        }
        if (! (alloc < (size_t )line->length)) {
          goto while_break___1;
        }
      }
      while_break___1: 
      free((void *)temp.text);
      temp.text = (char *)xmalloc(alloc);
    }
    memcpy((void *)temp.text, (void const   *)line->text, (size_t )line->length);
    temp.length = (size_t )line->length;
    if (key) {
      temp.keybeg = temp.text + (line->keybeg - line->text);
      temp.keylim = temp.text + (line->keylim - line->text);
    }
  }
  while_break: 
  xfclose(fp, file_name___3);
  free((void *)buf___1.buf);
  free((void *)temp.text);
  return (ordered);
}
}
static size_t open_input_files(struct sortfile *files , size_t nfiles , FILE ***pfps ) 
{ 
  FILE **fps ;
  FILE **tmp ;
  int i ;
  FILE *tmp___0 ;
  FILE *tmp___1 ;

  {
  tmp = (FILE **)xnmalloc(nfiles, sizeof(*fps));
  *pfps = tmp;
  fps = tmp;
  i = 0;
  while (1) {

    if (! ((size_t )i < nfiles)) {
      goto while_break;
    }
    if ((files + i)->temp) {
      if ((int )((files + i)->temp)->state != 0) {
        tmp___0 = open_temp((files + i)->temp);
        *(fps + i) = tmp___0;
      } else {
        tmp___1 = stream_open((files + i)->name, "r");
        *(fps + i) = tmp___1;
      }
    } else {
      tmp___1 = stream_open((files + i)->name, "r");
      *(fps + i) = tmp___1;
    }
    if (! *(fps + i)) {
      goto while_break;
    }
    i ++;
  }
  while_break: ;
  return ((size_t )i);
}
}
static void mergefps(struct sortfile *files , size_t ntemps , size_t nfiles , FILE *ofp ,
                     char const   *output_file , FILE **fps ) 
{ 
  struct buffer *buffer ;
  struct buffer *tmp ;
  struct line saved___0 ;
  struct line  const  *savedline ;
  size_t savealloc ;
  struct line  const  **cur ;
  struct line  const  **tmp___0 ;
  struct line  const  **base ;
  struct line  const  **tmp___1 ;
  size_t *ord ;
  size_t *tmp___2 ;
  size_t i ;
  size_t j ;
  size_t t ;
  struct keyfield  const  *key ;
  size_t tmp___3 ;
  struct line  const  *linelim ;
  struct line  const  *tmp___4 ;
  _Bool tmp___5 ;
  int tmp___6 ;
  struct line  const  *smallest ;
  int tmp___7 ;
  struct line  const  *linelim___0 ;
  struct line  const  *tmp___8 ;
  _Bool tmp___9 ;
  size_t lo ;
  size_t hi ;
  size_t probe ;
  size_t ord0 ;
  size_t count_of_smaller_lines ;
  int cmp ;
  int tmp___10 ;

  {
  tmp = (struct buffer *)xnmalloc(nfiles, sizeof(*buffer));
  buffer = tmp;
  savedline = (struct line  const  *)((void *)0);
  savealloc = (size_t )0;
  tmp___0 = (struct line  const  **)xnmalloc(nfiles, sizeof(*cur));
  cur = tmp___0;
  tmp___1 = (struct line  const  **)xnmalloc(nfiles, sizeof(*base));
  base = tmp___1;
  tmp___2 = (size_t *)xnmalloc(nfiles, sizeof(*ord));
  ord = tmp___2;
  key = (struct keyfield  const  *)keylist;
  saved___0.text = (char *)((void *)0);
  i = (size_t )0;
  while (1) {

    if (! (i < nfiles)) {
      goto while_break;
    }
    if (merge_buffer_size > sort_size / nfiles) {
      tmp___3 = merge_buffer_size;
    } else {
      tmp___3 = sort_size / nfiles;
    }
    initbuf(buffer + i, sizeof(struct line ), tmp___3);
    tmp___5 = fillbuf___7(buffer + i, *(fps + i), (files + i)->name);
    if (tmp___5) {
      tmp___4 = (struct line  const  *)buffer_linelim((struct buffer  const  *)(buffer + i));
      linelim = tmp___4;
      *(cur + i) = linelim - 1;
      *(base + i) = linelim - (buffer + i)->nlines;
      i ++;
    } else {
      xfclose(*(fps + i), (files + i)->name);
      if (i < ntemps) {
        ntemps --;
        zaptemp((files + i)->name);
      }
      free((void *)(buffer + i)->buf);
      nfiles --;
      j = i;
      while (1) {

        if (! (j < nfiles)) {
          goto while_break___0;
        }
        *(files + j) = *(files + (j + 1UL));
        *(fps + j) = *(fps + (j + 1UL));
        j ++;
      }
      while_break___0: ;
    }
  }
  while_break: 
  i = (size_t )0;
  while (1) {

    if (! (i < nfiles)) {
      goto while_break___1;
    }
    *(ord + i) = i;
    i ++;
  }
  while_break___1: 
  i = (size_t )1;
  while (1) {

    if (! (i < nfiles)) {
      goto while_break___2;
    }
    tmp___6 = compare(*(cur + *(ord + (i - 1UL))), *(cur + *(ord + i)));
    if (0 < tmp___6) {
      t = *(ord + (i - 1UL));
      *(ord + (i - 1UL)) = *(ord + i);
      *(ord + i) = t;
      i = (size_t )0;
    }
    i ++;
  }
  while_break___2: ;
  while (1) {
    while_continue___3: ;
    if (! nfiles) {
      goto while_break___3;
    }
    smallest = *(cur + *(ord + 0));
    if (unique) {
      if (savedline) {
        tmp___7 = compare(savedline, smallest);
        if (tmp___7) {
          savedline = (struct line  const  *)((void *)0);
          write_line((struct line  const  *)(& saved___0), ofp, output_file);
        }
      }
      if (! savedline) {
        savedline = (struct line  const  *)(& saved___0);
        if (savealloc < (size_t )smallest->length) {
          while (1) {

            if (! savealloc) {
              savealloc = (size_t )smallest->length;
              goto while_break___4;
            }
            savealloc *= 2UL;
            if (! (savealloc < (size_t )smallest->length)) {
              goto while_break___4;
            }
          }
          while_break___4: 
          free((void *)saved___0.text);
          saved___0.text = (char *)xmalloc(savealloc);
        }
        saved___0.length = (size_t )smallest->length;
        memcpy((void *)saved___0.text, (void const   *)smallest->text, saved___0.length);
        if (key) {
          saved___0.keybeg = saved___0.text + (smallest->keybeg - smallest->text);
          saved___0.keylim = saved___0.text + (smallest->keylim - smallest->text);
        }
      }
    } else {
      write_line(smallest, ofp, output_file);
    }
    if ((unsigned long )*(base + *(ord + 0)) < (unsigned long )smallest) {
      *(cur + *(ord + 0)) = smallest - 1;
    } else {
      tmp___9 = fillbuf___7(buffer + *(ord + 0), *(fps + *(ord + 0)), (files + *(ord + 0))->name);
      if (tmp___9) {
        tmp___8 = (struct line  const  *)buffer_linelim((struct buffer  const  *)(buffer + *(ord + 0)));
        linelim___0 = tmp___8;
        *(cur + *(ord + 0)) = linelim___0 - 1;
        *(base + *(ord + 0)) = linelim___0 - (buffer + *(ord + 0))->nlines;
      } else {
        i = (size_t )1;
        while (1) {

          if (! (i < nfiles)) {
            goto while_break___5;
          }
          if (*(ord + i) > *(ord + 0)) {
            (*(ord + i)) --;
          }
          i ++;
        }
        while_break___5: 
        nfiles --;
        xfclose(*(fps + *(ord + 0)), (files + *(ord + 0))->name);
        if (*(ord + 0) < ntemps) {
          ntemps --;
          zaptemp((files + *(ord + 0))->name);
        }
        free((void *)(buffer + *(ord + 0))->buf);
        i = *(ord + 0);
        while (1) {

          if (! (i < nfiles)) {
            goto while_break___6;
          }
          *(fps + i) = *(fps + (i + 1UL));
          *(files + i) = *(files + (i + 1UL));
          *(buffer + i) = *(buffer + (i + 1UL));
          *(cur + i) = *(cur + (i + 1UL));
          *(base + i) = *(base + (i + 1UL));
          i ++;
        }
        while_break___6: 
        i = (size_t )0;
        while (1) {

          if (! (i < nfiles)) {
            goto while_break___7;
          }
          *(ord + i) = *(ord + (i + 1UL));
          i ++;
        }
        while_break___7: ;
        goto while_continue___3;
      }
    }
    lo = (size_t )1;
    hi = nfiles;
    probe = lo;
    ord0 = *(ord + 0);
    while (1) {

      if (! (lo < hi)) {
        goto while_break___8;
      }
      tmp___10 = compare(*(cur + ord0), *(cur + *(ord + probe)));
      cmp = tmp___10;
      if (cmp < 0) {
        hi = probe;
      } else
      if (cmp == 0) {
        if (ord0 < *(ord + probe)) {
          hi = probe;
        } else {
          lo = probe + 1UL;
        }
      } else {
        lo = probe + 1UL;
      }
      probe = (lo + hi) / 2UL;
    }
    while_break___8: 
    count_of_smaller_lines = lo - 1UL;
    j = (size_t )0;
    while (1) {

      if (! (j < count_of_smaller_lines)) {
        goto while_break___9;
      }
      *(ord + j) = *(ord + (j + 1UL));
      j ++;
    }
    while_break___9: 
    *(ord + count_of_smaller_lines) = ord0;
  }
  while_break___3: ;
  if (unique) {
    if (savedline) {
      write_line((struct line  const  *)(& saved___0), ofp, output_file);
      free((void *)saved___0.text);
    }
  }
  xfclose(ofp, output_file);
  free((void *)fps);
  free((void *)buffer);
  free((void *)ord);
  free((void *)base);
  free((void *)cur);
  return;
}
}
static size_t mergefiles(struct sortfile *files , size_t ntemps , size_t nfiles ,
                         FILE *ofp , char const   *output_file ) 
{ 
  FILE **fps ;
  size_t nopened ;
  size_t tmp ;
  char *tmp___0 ;

  {
  tmp = open_input_files(files, nfiles, & fps);
  nopened = tmp;
  if (nopened < nfiles) {
    if (nopened < 2UL) {
      tmp___0 = gettext("open failed");
      die((char const   *)tmp___0, (files + nopened)->name);
    }
  }
  mergefps(files, ntemps, nopened, ofp, output_file, fps);
  return (nopened);
}
}
static void mergelines(struct line * __restrict  t , size_t nlines , struct line  const  * __restrict  lo ) 
{ 
  size_t nlo ;
  size_t nhi ;
  struct line *hi ;
  int tmp ;

  {
  nlo = nlines / 2UL;
  nhi = nlines - nlo;
  hi = (struct line *)(t - nlo);
  while (1) {
    tmp = compare((struct line  const  *)(lo - 1), (struct line  const  *)(hi - 1));
    if (tmp <= 0) {
      t --;
      lo --;
      *t = (struct line )*lo;
      nlo --;
      if (! nlo) {
        return;
      }
    } else {
      t --;
      hi --;
      *t = *hi;
      nhi --;
      if (! nhi) {
        while (1) {
          t --;
          lo --;
          *t = (struct line )*lo;
          nlo --;
          if (! nlo) {
            goto while_break___0;
          }
        }
        while_break___0: ;
        return;
      }
    }
  }

  return;
}
}
static void sequential_sort(struct line * __restrict  lines , size_t nlines , struct line * __restrict  temp ,
                            _Bool to_temp ) 
{ 
  int swap___1 ;
  int tmp ;
  size_t nlo ;
  size_t nhi ;
  struct line *lo ;
  struct line *hi ;
  size_t tmp___0 ;
  struct line *dest ;
  struct line  const  *sorted_lo ;

  {
  if (nlines == 2UL) {
    tmp = compare((struct line  const  *)(lines + -1), (struct line  const  *)(lines + -2));
    swap___1 = 0 < tmp;
    if (to_temp) {
      *(temp + -1) = *(lines + (-1 - swap___1));
      *(temp + -2) = *(lines + (-2 + swap___1));
    } else
    if (swap___1) {
      *(temp + -1) = *(lines + -1);
      *(lines + -1) = *(lines + -2);
      *(lines + -2) = *(temp + -1);
    }
  } else {
    nlo = nlines / 2UL;
    nhi = nlines - nlo;
    lo = (struct line *)lines;
    hi = (struct line *)(lines - nlo);
    if (to_temp) {
      tmp___0 = nlo;
    } else {
      tmp___0 = (size_t )0;
    }
    sequential_sort(hi, nhi, temp - tmp___0, to_temp);
    if (1UL < nlo) {
      sequential_sort(lo, nlo, temp, (_Bool )(! to_temp));
    } else
    if (! to_temp) {
      *(temp + -1) = *(lo + -1);
    }
    if (to_temp) {
      dest = (struct line *)temp;
      sorted_lo = (struct line  const  *)lines;
    } else {
      dest = (struct line *)lines;
      sorted_lo = (struct line  const  *)temp;
    }
    mergelines(dest, nlines, sorted_lo);
  }
  return;
}
}
static struct merge_node *init_node(struct merge_node * __restrict  parent , struct merge_node * __restrict  node_pool ,
                                    struct line *dest , size_t nthreads , size_t total_lines ,
                                    _Bool is_lo_child ) ;
static struct merge_node *merge_tree_init(size_t nthreads , size_t nlines , struct line *dest ) 
{ 
  struct merge_node *merge_tree ;
  struct merge_node *tmp ;
  struct merge_node *root ;
  struct line *tmp___0 ;
  struct line *tmp___1 ;
  struct line *tmp___2 ;
  size_t tmp___3 ;

  {
  tmp = (struct merge_node *)xmalloc((2UL * sizeof(*merge_tree)) * nthreads);
  merge_tree = tmp;
  root = merge_tree;
  tmp___2 = (struct line *)((void *)0);
  root->end_hi = tmp___2;
  tmp___1 = tmp___2;
  root->end_lo = tmp___1;
  tmp___0 = tmp___1;
  root->hi = tmp___0;
  root->lo = tmp___0;
  root->dest = (struct line **)((void *)0);
  tmp___3 = nlines;
  root->nhi = tmp___3;
  root->nlo = tmp___3;
  root->parent = (struct merge_node *)((void *)0);
  root->level = 0U;
  root->queued = (_Bool)0;
  pthread_mutex_init(& root->lock, (pthread_mutexattr_t const   *)((void *)0));
  init_node(root, root + 1, dest, nthreads, nlines, (_Bool)0);
  return (merge_tree);
}
}
static void merge_tree_destroy(struct merge_node *merge_tree ) 
{ 


  {
  free((void *)merge_tree);
  return;
}
}
static struct merge_node *init_node(struct merge_node * __restrict  parent , struct merge_node * __restrict  node_pool ,
                                    struct line *dest , size_t nthreads , size_t total_lines ,
                                    _Bool is_lo_child ) 
{ 
  size_t nlines ;
  size_t tmp ;
  size_t nlo ;
  size_t nhi ;
  struct line *lo ;
  struct line *hi ;
  struct line **parent_end ;
  struct line **tmp___0 ;
  struct merge_node *node ;
  struct merge_node * __restrict  tmp___1 ;
  struct line *tmp___2 ;
  struct line *tmp___3 ;
  size_t lo_threads ;
  size_t hi_threads ;
  struct merge_node *tmp___4 ;
  struct merge_node *tmp___5 ;

  {
  if (is_lo_child) {
    tmp = parent->nlo;
  } else {
    tmp = parent->nhi;
  }
  nlines = tmp;
  nlo = nlines / 2UL;
  nhi = nlines - nlo;
  lo = dest - total_lines;
  hi = lo - nlo;
  if (is_lo_child) {
    tmp___0 = & parent->end_lo;
  } else {
    tmp___0 = & parent->end_hi;
  }
  parent_end = tmp___0;
  tmp___1 = node_pool;
  node_pool ++;
  node = (struct merge_node *)tmp___1;
  tmp___2 = lo;
  node->end_lo = tmp___2;
  node->lo = tmp___2;
  tmp___3 = hi;
  node->end_hi = tmp___3;
  node->hi = tmp___3;
  node->dest = parent_end;
  node->nlo = nlo;
  node->nhi = nhi;
  node->parent = (struct merge_node *)parent;
  node->level = parent->level + 1U;
  node->queued = (_Bool)0;
  pthread_mutex_init(& node->lock, (pthread_mutexattr_t const   *)((void *)0));
  if (nthreads > 1UL) {
    lo_threads = nthreads / 2UL;
    hi_threads = nthreads - lo_threads;
    node->lo_child = (struct merge_node *)node_pool;
    tmp___4 = init_node(node, node_pool, lo, lo_threads, total_lines, (_Bool)1);
    node_pool = tmp___4;
    node->hi_child = (struct merge_node *)node_pool;
    tmp___5 = init_node(node, node_pool, hi, hi_threads, total_lines, (_Bool)0);
    node_pool = tmp___5;
  } else {
    node->lo_child = (struct merge_node *)((void *)0);
    node->hi_child = (struct merge_node *)((void *)0);
  }
  return ((struct merge_node *)node_pool);
}
}
static int compare_nodes(void const   *a , void const   *b ) 
{ 
  struct merge_node  const  *nodea ;
  struct merge_node  const  *nodeb ;

  {
  nodea = (struct merge_node  const  *)a;
  nodeb = (struct merge_node  const  *)b;
  if (nodea->level == nodeb->level) {
    return (nodea->nlo + nodea->nhi < nodeb->nlo + nodeb->nhi);
  }
  return (nodea->level < nodeb->level);
}
}
__inline static void lock_node(struct merge_node *node ) 
{ 


  {
  pthread_mutex_lock(& node->lock);
  return;
}
}
__inline static void unlock_node(struct merge_node *node ) 
{ 


  {
  pthread_mutex_unlock(& node->lock);
  return;
}
}
static void queue_destroy(struct merge_node_queue *queue ) 
{ 


  {
  heap_free(queue->priority_queue);
  pthread_cond_destroy(& queue->cond);
  pthread_mutex_destroy(& queue->mutex);
  return;
}
}
static void queue_init(struct merge_node_queue *queue , size_t nthreads ) 
{ 


  {
  queue->priority_queue = heap_alloc(& compare_nodes, 2UL * nthreads);
  pthread_mutex_init(& queue->mutex, (pthread_mutexattr_t const   *)((void *)0));
  pthread_cond_init(& queue->cond, (pthread_condattr_t const   *)((void *)0));
  return;
}
}
static void queue_insert(struct merge_node_queue *queue , struct merge_node *node ) 
{ 


  {
  pthread_mutex_lock(& queue->mutex);
  heap_insert(queue->priority_queue, (void *)node);
  node->queued = (_Bool)1;
  pthread_mutex_unlock(& queue->mutex);
  pthread_cond_signal(& queue->cond);
  return;
}
}
static struct merge_node *queue_pop(struct merge_node_queue *queue ) 
{ 
  struct merge_node *node ;

  {
  pthread_mutex_lock(& queue->mutex);
  while (1) {
    node = (struct merge_node *)heap_remove_top(queue->priority_queue);
    if (node) {
      goto while_break;
    }
    pthread_cond_wait(& queue->cond, & queue->mutex);
  }
  while_break: 
  pthread_mutex_unlock(& queue->mutex);
  lock_node(node);
  node->queued = (_Bool)0;
  return (node);
}
}
static struct line saved  ;
static void write_unique(struct line  const  *line , FILE *tfp , char const   *temp_output ) 
{ 
  int tmp ;

  {
  if (unique) {
    if (saved.text) {
      tmp = compare(line, (struct line  const  *)(& saved));
      if (! tmp) {
        return;
      }
    }
    saved = (struct line )*line;
  }
  write_line(line, tfp, temp_output);
  return;
}
}
static void mergelines_node(struct merge_node * __restrict  node , size_t total_lines ,
                            FILE *tfp , char const   *temp_output ) 
{ 
  struct line *lo_orig ;
  struct line *hi_orig ;
  size_t to_merge ;
  size_t merged_lo ;
  size_t merged_hi ;
  struct line *dest ;
  int tmp ;
  size_t tmp___0 ;
  size_t tmp___1 ;
  size_t tmp___2 ;
  int tmp___3 ;
  size_t tmp___4 ;
  size_t tmp___5 ;
  size_t tmp___6 ;

  {
  lo_orig = node->lo;
  hi_orig = node->hi;
  to_merge = (total_lines >> 2U * (node->level + 1U)) + 1UL;
  if (node->level > 1U) {
    dest = *(node->dest);
    while (1) {

      if ((unsigned long )node->lo != (unsigned long )node->end_lo) {
        if ((unsigned long )node->hi != (unsigned long )node->end_hi) {
          tmp___0 = to_merge;
          to_merge --;
          if (! tmp___0) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      tmp = compare((struct line  const  *)(node->lo - 1), (struct line  const  *)(node->hi - 1));
      if (tmp <= 0) {
        dest --;
        (node->lo) --;
        *dest = *(node->lo);
      } else {
        dest --;
        (node->hi) --;
        *dest = *(node->hi);
      }
    }
    while_break: 
    merged_lo = (size_t )(lo_orig - node->lo);
    merged_hi = (size_t )(hi_orig - node->hi);
    if (node->nhi == merged_hi) {
      while (1) {

        if ((unsigned long )node->lo != (unsigned long )node->end_lo) {
          tmp___1 = to_merge;
          to_merge --;
          if (! tmp___1) {
            goto while_break___0;
          }
        } else {
          goto while_break___0;
        }
        dest --;
        (node->lo) --;
        *dest = *(node->lo);
      }
      while_break___0: ;
    } else
    if (node->nlo == merged_lo) {
      while (1) {

        if ((unsigned long )node->hi != (unsigned long )node->end_hi) {
          tmp___2 = to_merge;
          to_merge --;
          if (! tmp___2) {
            goto while_break___1;
          }
        } else {
          goto while_break___1;
        }
        dest --;
        (node->hi) --;
        *dest = *(node->hi);
      }
      while_break___1: ;
    }
    *(node->dest) = dest;
  } else {
    while (1) {

      if ((unsigned long )node->lo != (unsigned long )node->end_lo) {
        if ((unsigned long )node->hi != (unsigned long )node->end_hi) {
          tmp___4 = to_merge;
          to_merge --;
          if (! tmp___4) {
            goto while_break___2;
          }
        } else {
          goto while_break___2;
        }
      } else {
        goto while_break___2;
      }
      tmp___3 = compare((struct line  const  *)(node->lo - 1), (struct line  const  *)(node->hi - 1));
      if (tmp___3 <= 0) {
        (node->lo) --;
        write_unique((struct line  const  *)node->lo, tfp, temp_output);
      } else {
        (node->hi) --;
        write_unique((struct line  const  *)node->hi, tfp, temp_output);
      }
    }
    while_break___2: 
    merged_lo = (size_t )(lo_orig - node->lo);
    merged_hi = (size_t )(hi_orig - node->hi);
    if (node->nhi == merged_hi) {
      while (1) {

        if ((unsigned long )node->lo != (unsigned long )node->end_lo) {
          tmp___5 = to_merge;
          to_merge --;
          if (! tmp___5) {
            goto while_break___3;
          }
        } else {
          goto while_break___3;
        }
        (node->lo) --;
        write_unique((struct line  const  *)node->lo, tfp, temp_output);
      }
      while_break___3: ;
    } else
    if (node->nlo == merged_lo) {
      while (1) {

        if ((unsigned long )node->hi != (unsigned long )node->end_hi) {
          tmp___6 = to_merge;
          to_merge --;
          if (! tmp___6) {
            goto while_break___4;
          }
        } else {
          goto while_break___4;
        }
        (node->hi) --;
        write_unique((struct line  const  *)node->hi, tfp, temp_output);
      }
      while_break___4: ;
    }
  }
  merged_lo = (size_t )(lo_orig - node->lo);
  merged_hi = (size_t )(hi_orig - node->hi);
  node->nlo -= merged_lo;
  node->nhi -= merged_hi;
  return;
}
}
static void queue_check_insert(struct merge_node_queue *queue , struct merge_node *node ) 
{ 
  _Bool lo_avail ;
  _Bool hi_avail ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  if (! node->queued) {
    lo_avail = (_Bool )(node->lo - node->end_lo != 0L);
    hi_avail = (_Bool )(node->hi - node->end_hi != 0L);
    if (lo_avail) {
      if (hi_avail) {
        tmp = 1;
      } else
      if (! node->nhi) {
        tmp = 1;
      } else {
        tmp = 0;
      }
      tmp___1 = tmp;
    } else {
      if (hi_avail) {
        if (! node->nlo) {
          tmp___0 = 1;
        } else {
          tmp___0 = 0;
        }
      } else {
        tmp___0 = 0;
      }
      tmp___1 = tmp___0;
    }
    if (tmp___1) {
      queue_insert(queue, node);
    }
  }
  return;
}
}
static void queue_check_insert_parent(struct merge_node_queue *queue , struct merge_node *node ) 
{ 


  {
  if (node->level > 1U) {
    lock_node(node->parent);
    queue_check_insert(queue, node->parent);
    unlock_node(node->parent);
  } else
  if (node->nlo + node->nhi == 0UL) {
    queue_insert(queue, node->parent);
  }
  return;
}
}
static void merge_loop(struct merge_node_queue *queue , size_t total_lines , FILE *tfp ,
                       char const   *temp_output ) 
{ 
  struct merge_node *node ;
  struct merge_node *tmp ;

  {
  while (1) {
    tmp = queue_pop(queue);
    node = tmp;
    if (node->level == 0U) {
      unlock_node(node);
      queue_insert(queue, node);
      goto while_break;
    }
    mergelines_node(node, total_lines, tfp, temp_output);
    queue_check_insert(queue, node);
    queue_check_insert_parent(queue, node);
    unlock_node(node);
  }
  while_break: ;
  return;
}
}
static void sortlines(struct line * __restrict  lines , size_t nthreads , size_t total_lines ,
                      struct merge_node *node , struct merge_node_queue *queue , FILE *tfp ,
                      char const   *temp_output ) ;
static void *sortlines_thread(void *data ) 
{ 
  struct thread_args  const  *args ;

  {
  args = (struct thread_args  const  *)data;
  sortlines((struct line *)args->lines, (size_t )args->nthreads, (size_t )args->total_lines,
            (struct merge_node *)args->node, (struct merge_node_queue *)args->queue,
            (FILE *)args->tfp, (char const   *)args->output_temp);
  return ((void *)0);
}
}
static void sortlines(struct line * __restrict  lines , size_t nthreads , size_t total_lines ,
                      struct merge_node *node , struct merge_node_queue *queue , FILE *tfp ,
                      char const   *temp_output ) 
{ 
  size_t nlines ;
  size_t lo_threads ;
  size_t hi_threads ;
  pthread_t thread ;
  struct thread_args args ;
  size_t nlo ;
  size_t nhi ;
  struct line *temp ;
  int tmp ;

  {
  nlines = node->nlo + node->nhi;
  lo_threads = nthreads / 2UL;
  hi_threads = nthreads - lo_threads;
  args.lines = (struct line *)lines;
  args.nthreads = lo_threads;
  args.total_lines = total_lines;
  args.node = node->lo_child;
  args.queue = queue;
  args.tfp = tfp;
  args.output_temp = temp_output;
  if (nthreads > 1UL) {
    if (131072UL <= nlines) {
      tmp = pthread_create(& thread, (pthread_attr_t const   *)((void *)0), & sortlines_thread,
                           (void *)(& args));
      if (tmp == 0) {
        sortlines(lines - node->nlo, hi_threads, total_lines, node->hi_child, queue,
                  tfp, temp_output);
        pthread_join(thread, (void **)((void *)0));
      } else {
        goto _L___0;
      }
    } else {
      goto _L___0;
    }
  } else {
    _L___0: 
    nlo = node->nlo;
    nhi = node->nhi;
    temp = (struct line *)(lines - total_lines);
    if (1UL < nhi) {
      sequential_sort(lines - nlo, nhi, temp - nlo / 2UL, (_Bool)0);
    }
    if (1UL < nlo) {
      sequential_sort(lines, nlo, temp, (_Bool)0);
    }
    node->lo = (struct line *)lines;
    node->hi = (struct line *)(lines - nlo);
    node->end_lo = (struct line *)(lines - nlo);
    node->end_hi = (struct line *)((lines - nlo) - nhi);
    queue_insert(queue, node);
    merge_loop(queue, total_lines, tfp, temp_output);
  }
  pthread_mutex_destroy(& node->lock);
  return;
}
}
static void avoid_trashing_input(struct sortfile *files , size_t ntemps , size_t nfiles ,
                                 char const   *outfile ) 
{ 
  size_t i ;
  _Bool got_outstat ;
  struct stat outstat ;
  struct tempnode *tempcopy ;
  _Bool is_stdin ;
  int tmp ;
  _Bool same ;
  struct stat instat ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  FILE *tftp ;

  {
  got_outstat = (_Bool)0;
  tempcopy = (struct tempnode *)((void *)0);
  i = ntemps;
  while (1) {

    if (! (i < nfiles)) {
      goto while_break;
    }
    tmp = strcmp((files + i)->name, "-");
    is_stdin = (_Bool )(tmp == 0);
    if (outfile) {
      tmp___7 = strcmp(outfile, (files + i)->name);
      if (tmp___7 == 0) {
        if (! is_stdin) {
          same = (_Bool)1;
        } else {
          goto _L___0;
        }
      } else {
        goto _L___0;
      }
    } else {
      _L___0: 
      if (! got_outstat) {
        if (outfile) {
          tmp___0 = stat(outfile, & outstat);
          tmp___2 = tmp___0;
        } else {
          tmp___1 = fstat(1, & outstat);
          tmp___2 = tmp___1;
        }
        if (tmp___2 != 0) {
          goto while_break;
        }
        got_outstat = (_Bool)1;
      }
      if (is_stdin) {
        tmp___3 = fstat(0, & instat);
        tmp___5 = tmp___3;
      } else {
        tmp___4 = stat((files + i)->name, & instat);
        tmp___5 = tmp___4;
      }
      if (tmp___5 == 0) {
        if (instat.st_ino == outstat.st_ino) {
          if (instat.st_dev == outstat.st_dev) {
            tmp___6 = 1;
          } else {
            tmp___6 = 0;
          }
        } else {
          tmp___6 = 0;
        }
      } else {
        tmp___6 = 0;
      }
      same = (_Bool )tmp___6;
    }
    if (same) {
      if (! tempcopy) {
        tempcopy = create_temp(& tftp);
        mergefiles(files + i, (size_t )0, (size_t )1, tftp, (char const   *)(tempcopy->name));
      }
      (files + i)->name = (char const   *)(tempcopy->name);
      (files + i)->temp = tempcopy;
    }
    i ++;
  }
  while_break: ;
  return;
}
}
static void merge(struct sortfile *files , size_t ntemps , size_t nfiles , char const   *output_file ) 
{ 
  size_t in ;
  size_t out ;
  size_t remainder ;
  size_t cheap_slots ;
  FILE *tfp ;
  struct tempnode *temp ;
  struct tempnode *tmp ;
  size_t num_merged ;
  size_t tmp___0 ;
  size_t tmp___1 ;
  size_t tmp___2 ;
  size_t nshortmerge ;
  FILE *tfp___0 ;
  struct tempnode *temp___0 ;
  struct tempnode *tmp___3 ;
  size_t num_merged___0 ;
  size_t tmp___4 ;
  size_t tmp___5 ;
  size_t tmp___6 ;
  size_t tmp___7 ;
  FILE **fps ;
  size_t nopened ;
  size_t tmp___8 ;
  FILE *ofp ;
  FILE *tmp___9 ;
  char *tmp___10 ;
  int *tmp___11 ;
  char *tmp___12 ;
  FILE *tfp___1 ;
  struct tempnode *temp___1 ;
  size_t tmp___13 ;
  size_t tmp___14 ;

  {
  while (1) {

    if (! ((size_t )nmerge < nfiles)) {
      goto while_break;
    }
    in = (size_t )0;
    out = in;
    while (1) {

      if (! ((size_t )nmerge <= nfiles - in)) {
        goto while_break___0;
      }
      tmp = create_temp(& tfp);
      temp = tmp;
      if (ntemps < (size_t )nmerge) {
        tmp___0 = ntemps;
      } else {
        tmp___0 = (size_t )nmerge;
      }
      tmp___1 = mergefiles(files + in, tmp___0, (size_t )nmerge, tfp, (char const   *)(temp->name));
      num_merged = tmp___1;
      if (ntemps < num_merged) {
        tmp___2 = ntemps;
      } else {
        tmp___2 = num_merged;
      }
      ntemps -= tmp___2;
      (files + out)->name = (char const   *)(temp->name);
      (files + out)->temp = temp;
      in += num_merged;
      out ++;
    }
    while_break___0: 
    remainder = nfiles - in;
    cheap_slots = (unsigned long )nmerge - out % (unsigned long )nmerge;
    if (cheap_slots < remainder) {
      nshortmerge = (remainder - cheap_slots) + 1UL;
      tmp___3 = create_temp(& tfp___0);
      temp___0 = tmp___3;
      if (ntemps < nshortmerge) {
        tmp___4 = ntemps;
      } else {
        tmp___4 = nshortmerge;
      }
      tmp___5 = mergefiles(files + in, tmp___4, nshortmerge, tfp___0, (char const   *)(temp___0->name));
      num_merged___0 = tmp___5;
      if (ntemps < num_merged___0) {
        tmp___6 = ntemps;
      } else {
        tmp___6 = num_merged___0;
      }
      ntemps -= tmp___6;
      (files + out)->name = (char const   *)(temp___0->name);
      tmp___7 = out;
      out ++;
      (files + tmp___7)->temp = temp___0;
      in += num_merged___0;
    }
    memmove((void *)(files + out), (void const   *)(files + in), (nfiles - in) * sizeof(*files));
    ntemps += out;
    nfiles -= in - out;
  }
  while_break: 
  avoid_trashing_input(files, ntemps, nfiles, output_file);
  while (1) {
    tmp___8 = open_input_files(files, nfiles, & fps);
    nopened = tmp___8;
    if (nopened == nfiles) {
      tmp___9 = stream_open(output_file, "w");
      ofp = tmp___9;
      if (ofp) {
        mergefps(files, ntemps, nfiles, ofp, output_file, fps);
        goto while_break___1;
      }
      tmp___11 = __errno_location();
      if (*tmp___11 != 24) {
        tmp___10 = gettext("open failed");
        die((char const   *)tmp___10, output_file);
      } else
      if (nopened <= 2UL) {
        tmp___10 = gettext("open failed");
        die((char const   *)tmp___10, output_file);
      }
    } else
    if (nopened <= 2UL) {
      tmp___12 = gettext("open failed");
      die((char const   *)tmp___12, (files + nopened)->name);
    }
    while (1) {
      nopened --;
      xfclose(*(fps + nopened), (files + nopened)->name);
      temp___1 = maybe_create_temp(& tfp___1, (_Bool )(! (nopened <= 2UL)));
      if (! (! temp___1)) {
        goto while_break___2;
      }
    }
    while_break___2: ;
    if (ntemps < nopened) {
      tmp___13 = ntemps;
    } else {
      tmp___13 = nopened;
    }
    mergefps(files + 0, tmp___13, nopened, tfp___1, (char const   *)(temp___1->name),
             fps);
    if (ntemps < nopened) {
      tmp___14 = ntemps;
    } else {
      tmp___14 = nopened;
    }
    ntemps -= tmp___14;
    (files + 0)->name = (char const   *)(temp___1->name);
    (files + 0)->temp = temp___1;
    memmove((void *)(files + 1), (void const   *)(files + nopened), (nfiles - nopened) * sizeof(*files));
    ntemps ++;
    nfiles -= nopened - 1UL;
  }
  while_break___1: ;
  return;
}
}
static void sort(char * const  *files , size_t nfiles , char const   *output_file ,
                 size_t nthreads ) 
{ 
  struct buffer buf___1 ;
  size_t ntemps ;
  _Bool output_file_created ;
  char const   *temp_output ;
  char const   *file ;
  FILE *fp ;
  FILE *tmp ;
  FILE *tfp ;
  size_t bytes_per_line ;
  size_t tmp___0 ;
  size_t mult ;
  size_t tmp___1 ;
  struct line *line ;
  struct tempnode *tmp___2 ;
  struct merge_node_queue queue ;
  struct merge_node *merge_tree ;
  struct merge_node *tmp___3 ;
  struct merge_node *root ;
  _Bool tmp___4 ;
  size_t i ;
  struct tempnode *node ;
  struct sortfile *tempfiles ;
  struct sortfile *tmp___5 ;

  {
  ntemps = (size_t )0;
  output_file_created = (_Bool)0;
  buf___1.alloc = (size_t )0;
  while (1) {

    if (! nfiles) {
      goto while_break;
    }
    file = (char const   *)*files;
    tmp = xfopen(file, "r");
    fp = tmp;
    if (nthreads > 1UL) {
      tmp___0 = (size_t )1;
      mult = (size_t )1;
      while (1) {

        if (! (tmp___0 < nthreads)) {
          goto while_break___0;
        }
        tmp___0 *= 2UL;
        mult ++;
      }
      while_break___0: 
      bytes_per_line = mult * sizeof(struct line );
    } else {
      bytes_per_line = (sizeof(struct line ) * 3UL) / 2UL;
    }
    if (! buf___1.alloc) {
      tmp___1 = sort_buffer_size((FILE * const  *)(& fp), (size_t )1, files, nfiles,
                                 bytes_per_line);
      initbuf(& buf___1, bytes_per_line, tmp___1);
    }
    buf___1.eof = (_Bool)0;
    files ++;
    nfiles --;
    while (1) {
      tmp___4 = fillbuf___7(& buf___1, fp, file);
      if (! tmp___4) {
        goto while_break___1;
      }
      if (buf___1.eof) {
        if (nfiles) {
          if (bytes_per_line + 1UL < (buf___1.alloc - buf___1.used) - bytes_per_line * buf___1.nlines) {
            buf___1.left = buf___1.used;
            goto while_break___1;
          }
        }
      }
      line = buffer_linelim((struct buffer  const  *)(& buf___1));
      if (buf___1.eof) {
        if (! nfiles) {
          if (! ntemps) {
            if (! buf___1.left) {
              xfclose(fp, file);
              tfp = xfopen(output_file, "w");
              temp_output = output_file;
              output_file_created = (_Bool)1;
            } else {
              ntemps ++;
              tmp___2 = create_temp(& tfp);
              temp_output = (char const   *)(tmp___2->name);
            }
          } else {
            ntemps ++;
            tmp___2 = create_temp(& tfp);
            temp_output = (char const   *)(tmp___2->name);
          }
        } else {
          ntemps ++;
          tmp___2 = create_temp(& tfp);
          temp_output = (char const   *)(tmp___2->name);
        }
      } else {
        ntemps ++;
        tmp___2 = create_temp(& tfp);
        temp_output = (char const   *)(tmp___2->name);
      }
      if (1UL < buf___1.nlines) {
        queue_init(& queue, nthreads);
        tmp___3 = merge_tree_init(nthreads, buf___1.nlines, line);
        merge_tree = tmp___3;
        root = merge_tree + 1;
        sortlines(line, nthreads, buf___1.nlines, root, & queue, tfp, temp_output);
        queue_destroy(& queue);
        pthread_mutex_destroy(& root->lock);
        merge_tree_destroy(merge_tree);
      } else {
        write_unique((struct line  const  *)(line - 1), tfp, temp_output);
      }
      xfclose(tfp, temp_output);
      if (output_file_created) {
        goto finish;
      }
    }
    while_break___1: 
    xfclose(fp, file);
  }
  while_break: ;
  finish: 
  free((void *)buf___1.buf);
  if (! output_file_created) {
    node = (struct tempnode *)temphead;
    tmp___5 = (struct sortfile *)xnmalloc(ntemps, sizeof(*tempfiles));
    tempfiles = tmp___5;
    i = (size_t )0;
    while (1) {

      if (! node) {
        goto while_break___2;
      }
      (tempfiles + i)->name = (char const   *)(node->name);
      (tempfiles + i)->temp = node;
      node = (struct tempnode *)node->next;
      i ++;
    }
    while_break___2: 
    merge(tempfiles, ntemps, ntemps, output_file);
    free((void *)tempfiles);
  }
  reap_all();
  return;
}
}
static void insertkey(struct keyfield *key_arg ) 
{ 
  struct keyfield **p ;
  struct keyfield *key ;
  struct keyfield *tmp ;

  {
  tmp = (struct keyfield *)xmemdup((void const   *)key_arg, sizeof(*key));
  key = tmp;
  p = & keylist;
  while (1) {

    if (! *p) {
      goto while_break;
    }
    goto __Cont;
    __Cont: 
    p = & (*p)->next;
  }
  while_break: 
  *p = key;
  key->next = (struct keyfield *)((void *)0);
  return;
}
}
static  __attribute__((__noreturn__)) void badfieldspec(char const   *spec , char const   *msgid ) ;
static  __attribute__((__noreturn__)) void badfieldspec(char const   *spec , char const   *msgid ) ;
static void badfieldspec(char const   *spec , char const   *msgid ) 
{ 
  char const   *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;

  {
  tmp = quote(spec);
  tmp___0 = gettext(msgid);
  tmp___1 = gettext("%s: invalid field specification %s");
  error(2, 0, (char const   *)tmp___1, tmp___0, tmp);
  abort();
}
}
static  __attribute__((__noreturn__)) void incompatible_options(char const   *opts___1 ) ;
static  __attribute__((__noreturn__)) void incompatible_options(char const   *opts___1 ) ;
static void incompatible_options(char const   *opts___1 ) 
{ 
  char *tmp ;

  {
  tmp = gettext("options \'-%s\' are incompatible");
  error(2, 0, (char const   *)tmp, opts___1);
  abort();
}
}
static void check_ordering_compatibility(void) 
{ 
  struct keyfield *key ;
  char opts___1[sizeof(short_options)] ;
  _Bool tmp ;
  _Bool tmp___0 ;

  {
  key = keylist;
  while (1) {

    if (! key) {
      goto while_break;
    }
    if (1 < ((((int )key->numeric + (int )key->general_numeric) + (int )key->human_numeric) + (int )key->month) + (((int )key->version | (int )key->random) | ! (! key->ignore))) {
      tmp___0 = (_Bool)0;
      key->reverse = tmp___0;
      tmp = tmp___0;
      key->skipeblanks = tmp;
      key->skipsblanks = tmp;
      key_to_opts((struct keyfield  const  *)key, opts___1);
      incompatible_options((char const   *)(opts___1));
    }
    key = key->next;
  }
  while_break: ;
  return;
}
}
static char const   *parse_field_count(char const   *string , size_t *val , char const   *msgid ) 
{ 
  char *suffix ;
  uintmax_t n ;
  strtol_error tmp ;
  char const   *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;

  {
  tmp = xstrtoumax(string, & suffix, 10, & n, "");
  if ((unsigned int )tmp == 0U) {
    goto case_0;
  }
  if ((unsigned int )tmp == 2U) {
    goto case_0;
  }
  if ((unsigned int )tmp == 1U) {
    goto case_1;
  }
  if ((unsigned int )tmp == 3U) {
    goto case_1;
  }
  if ((unsigned int )tmp == 4U) {
    goto case_4;
  }
  goto switch_break;
  case_0: 
  *val = n;
  if (*val == n) {
    goto switch_break;
  }
  case_1: 
  *val = 0xffffffffffffffffUL;
  goto switch_break;
  case_4: 
  if (msgid) {
    tmp___0 = quote(string);
    tmp___1 = gettext(msgid);
    tmp___2 = gettext("%s: invalid count at start of %s");
    error(2, 0, (char const   *)tmp___2, tmp___1, tmp___0);
  }
  return ((char const   *)((void *)0));
  switch_break: ;
  return ((char const   *)suffix);
}
}
static char *set_ordering(char const   *s , struct keyfield *key , enum blanktype blanktype ) 
{ 


  {
  while (1) {

    if (! *s) {
      goto while_break;
    }
    if ((int const   )*s == 98) {
      goto case_98;
    }
    if ((int const   )*s == 100) {
      goto case_100;
    }
    if ((int const   )*s == 102) {
      goto case_102;
    }
    if ((int const   )*s == 103) {
      goto case_103;
    }
    if ((int const   )*s == 104) {
      goto case_104;
    }
    if ((int const   )*s == 105) {
      goto case_105;
    }
    if ((int const   )*s == 77) {
      goto case_77;
    }
    if ((int const   )*s == 110) {
      goto case_110;
    }
    if ((int const   )*s == 82) {
      goto case_82;
    }
    if ((int const   )*s == 114) {
      goto case_114;
    }
    if ((int const   )*s == 86) {
      goto case_86;
    }
    goto switch_default;
    case_98: 
    if ((unsigned int )blanktype == 0U) {
      key->skipsblanks = (_Bool)1;
    } else
    if ((unsigned int )blanktype == 2U) {
      key->skipsblanks = (_Bool)1;
    }
    if ((unsigned int )blanktype == 1U) {
      key->skipeblanks = (_Bool)1;
    } else
    if ((unsigned int )blanktype == 2U) {
      key->skipeblanks = (_Bool)1;
    }
    goto switch_break;
    case_100: 
    key->ignore = (_Bool const   *)(nondictionary);
    goto switch_break;
    case_102: 
    key->translate = (char const   *)(fold_toupper);
    goto switch_break;
    case_103: 
    key->general_numeric = (_Bool)1;
    goto switch_break;
    case_104: 
    key->human_numeric = (_Bool)1;
    goto switch_break;
    case_105: 
    if (! key->ignore) {
      key->ignore = (_Bool const   *)(nonprinting);
    }
    goto switch_break;
    case_77: 
    key->month = (_Bool)1;
    goto switch_break;
    case_110: 
    key->numeric = (_Bool)1;
    goto switch_break;
    case_82: 
    key->random = (_Bool)1;
    goto switch_break;
    case_114: 
    key->reverse = (_Bool)1;
    goto switch_break;
    case_86: 
    key->version = (_Bool)1;
    goto switch_break;
    switch_default: 
    return ((char *)s);
    switch_break: 
    s ++;
  }
  while_break: ;
  return ((char *)s);
}
}
static struct keyfield *key_init(struct keyfield *key ) 
{ 


  {
  memset((void *)key, 0, sizeof(*key));
  key->eword = 0xffffffffffffffffUL;
  return (key);
}
}
static void sighandler(int sig___0 ) 
{ 


  {
  cleanup();
  signal(sig___0, (void (*)(int  ))0);
  raise(sig___0);
  return;
}
}
int main(int argc , char **argv ) ;
static int const   sig[11]  = 
  {      (int const   )14,      (int const   )1,      (int const   )2,      (int const   )13, 
        (int const   )3,      (int const   )15,      (int const   )29,      (int const   )27, 
        (int const   )26,      (int const   )24,      (int const   )25};
static char opts[10]  = 
  {      (char )'X',      (char )' ',      (char )'-',      (char )'-', 
        (char )'d',      (char )'e',      (char )'b',      (char )'u', 
        (char )'g',      (char )'\000'};
static char *minus  =    (char *)"-";
static char opts___0[3]  = {      (char)0,      (char )'o',      (char)0};
int main(int argc , char **argv ) 
{ 
  struct keyfield *key ;
  struct keyfield key_buf ;
  struct keyfield gkey ;
  _Bool gkey_only ;
  char const   *s ;
  int c ;
  char checkonly ;
  _Bool mergeonly ;
  char *random_source ;
  _Bool need_random ;
  size_t nthreads ;
  size_t nfiles ;
  _Bool posixly_correct ;
  char *tmp ;
  _Bool obsolete_usage ;
  int tmp___0 ;
  char **files ;
  char *files_from ;
  struct Tokens tok ;
  char const   *outfile ;
  struct lconv  const  *locale ;
  struct lconv  const  *tmp___1 ;
  size_t i ;
  struct sigaction act ;
  int tmp___2 ;
  int oi ;
  size_t tmp___3 ;
  int tmp___4 ;
  _Bool minus_pos_usage ;
  int tmp___5 ;
  int tmp___6 ;
  char const   *optarg1 ;
  int tmp___7 ;
  char *tmp___8 ;
  char *tmp___9 ;
  size_t tmp___10 ;
  ptrdiff_t tmp___11 ;
  char str[2] ;
  ptrdiff_t tmp___12 ;
  char *tmp___13 ;
  int tmp___14 ;
  size_t tmp___15 ;
  size_t tmp___16 ;
  size_t tmp___17 ;
  char *tmp___18 ;
  int tmp___19 ;
  char *tmp___20 ;
  int tmp___21 ;
  char newtab ;
  char *tmp___22 ;
  char const   *tmp___23 ;
  char *tmp___24 ;
  int tmp___25 ;
  char *tmp___26 ;
  char const   *p ;
  FILE *stream ;
  char const   *tmp___27 ;
  char *tmp___28 ;
  char *tmp___29 ;
  char const   *tmp___30 ;
  char *tmp___31 ;
  int *tmp___32 ;
  int tmp___33 ;
  char const   *tmp___34 ;
  char *tmp___35 ;
  _Bool tmp___36 ;
  int tmp___37 ;
  size_t i___0 ;
  char const   *tmp___38 ;
  char *tmp___39 ;
  unsigned long file_number ;
  char *tmp___40 ;
  char *tmp___41 ;
  int tmp___42 ;
  char const   *tmp___43 ;
  char *tmp___44 ;
  _Bool tmp___45 ;
  _Bool tmp___46 ;
  char *tmp___47 ;
  char const   *tmp___48 ;
  char *tmp___49 ;
  char *tmp___50 ;
  char const   *tmp_dir ;
  char const   *tmp___51 ;
  char const   *tmp___52 ;
  char const   *tmp___53 ;
  char *tmp___54 ;
  int tmp___56 ;
  _Bool tmp___57 ;
  struct sortfile *sortfiles ;
  struct sortfile *tmp___58 ;
  size_t i___1 ;
  unsigned long np ;
  unsigned long tmp___59 ;
  size_t nthreads_max ;
  char *tmp___60 ;
  int tmp___61 ;

  {
  gkey_only = (_Bool)0;
  c = 0;
  checkonly = (char)0;
  mergeonly = (_Bool)0;
  random_source = (char *)((void *)0);
  need_random = (_Bool)0;
  nthreads = (size_t )0;
  nfiles = (size_t )0;
  tmp = getenv("POSIXLY_CORRECT");
  posixly_correct = (_Bool )((unsigned long )tmp != (unsigned long )((void *)0));
  tmp___0 = posix2_version();
  obsolete_usage = (_Bool )(tmp___0 < 200112);
  files_from = (char *)((void *)0);
  outfile = (char const   *)((void *)0);
  set_program_name((char const   *)*(argv + 0));
  setlocale(6, "");
  bindtextdomain("coreutils", "/usr/local/share/locale");
  textdomain("coreutils");
  initialize_exit_failure(2);
  hard_LC_COLLATE = hard_locale(3);
  hard_LC_TIME = hard_locale(2);
  tmp___1 = (struct lconv  const  *)localeconv();
  locale = tmp___1;
  decimal_point = (int )to_uchar(*(locale->decimal_point + 0));
  if (! decimal_point) {
    decimal_point = '.';
  } else
  if (*(locale->decimal_point + 1)) {
    decimal_point = '.';
  }
  thousands_sep = (int )to_uchar(*(locale->thousands_sep));
  if (! thousands_sep) {
    thousands_sep = -1;
  } else
  if (*(locale->thousands_sep + 1)) {
    thousands_sep = -1;
  }
  have_read_stdin = (_Bool)0;
  inittables();
  sigemptyset(& caught_signals);
  i = (size_t )0;
  while (1) {

    if (! (i < 11UL)) {
      goto while_break;
    }
    sigaction((int )sig[i], (struct sigaction  const  *)((void *)0), & act);
    if ((unsigned long )act.__sigaction_handler.sa_handler != (unsigned long )((void (*)(int  ))1)) {
      sigaddset(& caught_signals, (int )sig[i]);
    }
    i ++;
  }
  while_break: 
  act.__sigaction_handler.sa_handler = & sighandler;
  act.sa_mask = caught_signals;
  act.sa_flags = 0;
  i = (size_t )0;
  while (1) {

    if (! (i < 11UL)) {
      goto while_break___0;
    }
    tmp___2 = sigismember((sigset_t const   *)(& caught_signals), (int )sig[i]);
    if (tmp___2) {
      sigaction((int )sig[i], (struct sigaction  const  *)(& act), (struct sigaction *)((void *)0));
    }
    i ++;
  }
  while_break___0: 
  signal(17, (void (*)(int  ))0);
  atexit(& exit_cleanup);
  key_init(& gkey);
  gkey.sword = 0xffffffffffffffffUL;
  files = (char **)xnmalloc((size_t )argc, sizeof(*files));
  while (1) {
    oi = -1;
    if (c == -1) {
      goto _L;
    } else
    if (posixly_correct) {
      if (nfiles != 0UL) {
        if (obsolete_usage) {
          if (! checkonly) {
            if (optind != argc) {
              if ((int )*(*(argv + optind) + 0) == 45) {
                if ((int )*(*(argv + optind) + 1) == 111) {
                  if (*(*(argv + optind) + 2)) {
                    goto _L___1;
                  } else
                  if (optind + 1 != argc) {
                    goto _L___1;
                  } else {
                    goto _L;
                  }
                } else {
                  goto _L;
                }
              } else {
                goto _L;
              }
            } else {
              goto _L;
            }
          } else {
            goto _L;
          }
        } else {
          goto _L;
        }
      } else {
        goto _L___1;
      }
    } else {
      _L___1: 
      c = getopt_long(argc, (char * const  *)argv, short_options, long_options___1,
                      & oi);
      if (c == -1) {
        _L: 
        if (argc <= optind) {
          goto while_break___1;
        }
        tmp___3 = nfiles;
        nfiles ++;
        tmp___4 = optind;
        optind ++;
        *(files + tmp___3) = *(argv + tmp___4);
      } else {
        if (c == 1) {
          goto case_1;
        }
        if (c == 134) {
          goto case_134;
        }
        if (c == 98) {
          goto case_98;
        }
        if (c == 100) {
          goto case_98;
        }
        if (c == 102) {
          goto case_98;
        }
        if (c == 103) {
          goto case_98;
        }
        if (c == 104) {
          goto case_98;
        }
        if (c == 105) {
          goto case_98;
        }
        if (c == 77) {
          goto case_98;
        }
        if (c == 110) {
          goto case_98;
        }
        if (c == 114) {
          goto case_98;
        }
        if (c == 82) {
          goto case_98;
        }
        if (c == 86) {
          goto case_98;
        }
        if (c == 128) {
          goto case_128;
        }
        if (c == 99) {
          goto case_99;
        }
        if (c == 67) {
          goto case_99;
        }
        if (c == 129) {
          goto case_129;
        }
        if (c == 130) {
          goto case_130;
        }
        if (c == 131) {
          goto case_131;
        }
        if (c == 107) {
          goto case_107;
        }
        if (c == 109) {
          goto case_109;
        }
        if (c == 132) {
          goto case_132;
        }
        if (c == 111) {
          goto case_111;
        }
        if (c == 133) {
          goto case_133;
        }
        if (c == 115) {
          goto case_115;
        }
        if (c == 83) {
          goto case_83;
        }
        if (c == 116) {
          goto case_116;
        }
        if (c == 84) {
          goto case_84;
        }
        if (c == 135) {
          goto case_135;
        }
        if (c == 117) {
          goto case_117;
        }
        if (c == 121) {
          goto case_121;
        }
        if (c == 122) {
          goto case_122;
        }
        if (c == -130) {
          goto case_neg_130;
        }
        if (c == -131) {
          goto case_neg_131;
        }
        goto switch_default;
        case_1: 
        key = (struct keyfield *)((void *)0);
        if ((int )*(optarg + 0) == 43) {
          if (optind != argc) {
            if ((int )*(*(argv + optind) + 0) == 45) {
              if ((unsigned int )*(*(argv + optind) + 1) - 48U <= 9U) {
                tmp___5 = 1;
              } else {
                tmp___5 = 0;
              }
            } else {
              tmp___5 = 0;
            }
          } else {
            tmp___5 = 0;
          }
          minus_pos_usage = (_Bool )tmp___5;
          if (minus_pos_usage) {
            if (! posixly_correct) {
              tmp___6 = 1;
            } else {
              tmp___6 = 0;
            }
          } else {
            tmp___6 = 0;
          }
          obsolete_usage = (_Bool )((int )obsolete_usage | tmp___6);
          if (obsolete_usage) {
            key = key_init(& key_buf);
            s = parse_field_count((char const   *)(optarg + 1), & key->sword, (char const   *)((void *)0));
            if (s) {
              if ((int const   )*s == 46) {
                s = parse_field_count(s + 1, & key->schar, (char const   *)((void *)0));
              }
            }
            if (! key->sword) {
              if (! key->schar) {
                key->sword = 0xffffffffffffffffUL;
              }
            }
            if (! s) {
              key = (struct keyfield *)((void *)0);
            } else {
              tmp___9 = set_ordering(s, key, (enum blanktype )0);
              if (*tmp___9) {
                key = (struct keyfield *)((void *)0);
              } else {
                if (minus_pos_usage) {
                  tmp___7 = optind;
                  optind ++;
                  optarg1 = (char const   *)*(argv + tmp___7);
                  s = parse_field_count(optarg1 + 1, & key->eword, "invalid number after \'-\'");
                  if ((int const   )*s == 46) {
                    s = parse_field_count(s + 1, & key->echar, "invalid number after \'.\'");
                  }
                  if (! key->echar) {
                    if (key->eword) {
                      (key->eword) --;
                    }
                  }
                  tmp___8 = set_ordering(s, key, (enum blanktype )1);
                  if (*tmp___8) {
                    badfieldspec(optarg1, "stray character in field spec");
                  }
                }
                key->obsolete_used = (_Bool)1;
                insertkey(key);
              }
            }
          }
        }
        if (! key) {
          tmp___10 = nfiles;
          nfiles ++;
          *(files + tmp___10) = optarg;
        }
        goto switch_break;
        case_134: 
        tmp___11 = __xargmatch_internal("--sort", (char const   *)optarg, sort_args,
                                        sort_types, sizeof(sort_types[0]), argmatch_die);
        c = (int )sort_types[tmp___11];
        case_98: 
        str[0] = (char )c;
        str[1] = (char )'\000';
        set_ordering((char const   *)(str), & gkey, (enum blanktype )2);
        goto switch_break;
        case_128: 
        if (optarg) {
          tmp___12 = __xargmatch_internal("--check", (char const   *)optarg, check_args,
                                          check_types, sizeof(check_types[0]), argmatch_die);
          c = (int )check_types[tmp___12];
        } else {
          c = 'c';
        }
        case_99: 
        if (checkonly) {
          if ((int )checkonly != c) {
            incompatible_options("cC");
          }
        }
        checkonly = (char )c;
        goto switch_break;
        case_129: 
        if (compress_program) {
          tmp___14 = strcmp(compress_program, (char const   *)optarg);
          if (! (tmp___14 == 0)) {
            tmp___13 = gettext("multiple compress programs specified");
            error(2, 0, (char const   *)tmp___13);
          }
        }
        compress_program = (char const   *)optarg;
        goto switch_break;
        case_130: 
        debug = (_Bool)1;
        goto switch_break;
        case_131: 
        files_from = optarg;
        goto switch_break;
        case_107: 
        key = key_init(& key_buf);
        s = parse_field_count((char const   *)optarg, & key->sword, "invalid number at field start");
        tmp___15 = key->sword;
        (key->sword) --;
        if (! tmp___15) {
          badfieldspec((char const   *)optarg, "field number is zero");
        }
        if ((int const   )*s == 46) {
          s = parse_field_count(s + 1, & key->schar, "invalid number after \'.\'");
          tmp___16 = key->schar;
          (key->schar) --;
          if (! tmp___16) {
            badfieldspec((char const   *)optarg, "character offset is zero");
          }
        }
        if (! key->sword) {
          if (! key->schar) {
            key->sword = 0xffffffffffffffffUL;
          }
        }
        s = (char const   *)set_ordering(s, key, (enum blanktype )0);
        if ((int const   )*s != 44) {
          key->eword = 0xffffffffffffffffUL;
          key->echar = (size_t )0;
        } else {
          s = parse_field_count(s + 1, & key->eword, "invalid number after \',\'");
          tmp___17 = key->eword;
          (key->eword) --;
          if (! tmp___17) {
            badfieldspec((char const   *)optarg, "field number is zero");
          }
          if ((int const   )*s == 46) {
            s = parse_field_count(s + 1, & key->echar, "invalid number after \'.\'");
          }
          s = (char const   *)set_ordering(s, key, (enum blanktype )1);
        }
        if (*s) {
          badfieldspec((char const   *)optarg, "stray character in field spec");
        }
        insertkey(key);
        goto switch_break;
        case_109: 
        mergeonly = (_Bool)1;
        goto switch_break;
        case_132: 
        specify_nmerge(oi, (char )c, (char const   *)optarg);
        goto switch_break;
        case_111: 
        if (outfile) {
          tmp___19 = strcmp(outfile, (char const   *)optarg);
          if (! (tmp___19 == 0)) {
            tmp___18 = gettext("multiple output files specified");
            error(2, 0, (char const   *)tmp___18);
          }
        }
        outfile = (char const   *)optarg;
        goto switch_break;
        case_133: 
        if (random_source) {
          tmp___21 = strcmp((char const   *)random_source, (char const   *)optarg);
          if (! (tmp___21 == 0)) {
            tmp___20 = gettext("multiple random sources specified");
            error(2, 0, (char const   *)tmp___20);
          }
        }
        random_source = optarg;
        goto switch_break;
        case_115: 
        stable = (_Bool)1;
        goto switch_break;
        case_83: 
        specify_sort_size(oi, (char )c, (char const   *)optarg);
        goto switch_break;
        case_116: 
        newtab = *(optarg + 0);
        if (! newtab) {
          tmp___22 = gettext("empty tab");
          error(2, 0, (char const   *)tmp___22);
        }
        if (*(optarg + 1)) {
          tmp___25 = strcmp((char const   *)optarg, "\\0");
          if (tmp___25 == 0) {
            newtab = (char )'\000';
          } else {
            tmp___23 = quote((char const   *)optarg);
            tmp___24 = gettext("multi-character tab %s");
            error(2, 0, (char const   *)tmp___24, tmp___23);
          }
        }
        if (tab != 128) {
          if (tab != (int )newtab) {
            tmp___26 = gettext("incompatible tabs");
            error(2, 0, (char const   *)tmp___26);
          }
        }
        tab = (int )newtab;
        goto switch_break;
        case_84: 
        add_temp_dir((char const   *)optarg);
        goto switch_break;
        case_135: 
        nthreads = specify_nthreads(oi, (char )c, (char const   *)optarg);
        goto switch_break;
        case_117: 
        unique = (_Bool)1;
        goto switch_break;
        case_121: 
        if ((unsigned long )optarg == (unsigned long )*(argv + (optind - 1))) {
          p = (char const   *)optarg;
          while (1) {

            if (! ((unsigned int )*p - 48U <= 9U)) {
              goto while_break___2;
            }
            goto __Cont;
            __Cont: 
            p ++;
          }
          while_break___2: 
          optind -= (int const   )*p != 0;
        }
        goto switch_break;
        case_122: 
        eolchar = (char)0;
        goto switch_break;
        case_neg_130: 
        usage(0);
        goto switch_break;
        case_neg_131: 
        version_etc(stdout, "sort", "GNU coreutils", Version, "Mike Haertel", "Paul Eggert",
                    (char *)((void *)0));
        exit(0);
        goto switch_break;
        switch_default: 
        usage(2);
        switch_break: ;
      }
    }
  }
  while_break___1: ;
  if (files_from) {
    if (nfiles) {
      tmp___27 = quote((char const   *)*(files + 0));
      tmp___28 = gettext("extra operand %s");
      error(0, 0, (char const   *)tmp___28, tmp___27);
      tmp___29 = gettext("file operands cannot be combined with --files0-from");
      fprintf(stderr, "%s\n", tmp___29);
      usage(2);
    }
    tmp___33 = strcmp((char const   *)files_from, "-");
    if (tmp___33 == 0) {
      stream = stdin;
    } else {
      stream = fopen_safer((char const   *)files_from, "r");
      if ((unsigned long )stream == (unsigned long )((void *)0)) {
        tmp___30 = quote((char const   *)files_from);
        tmp___31 = gettext("cannot open %s for reading");
        tmp___32 = __errno_location();
        error(2, *tmp___32, (char const   *)tmp___31, tmp___30);
      }
    }
    readtokens0_init(& tok);
    tmp___36 = readtokens0(stream, & tok);
    if (tmp___36) {
      tmp___37 = rpl_fclose(stream);
      if (tmp___37 != 0) {
        tmp___34 = quote((char const   *)files_from);
        tmp___35 = gettext("cannot read file names from %s");
        error(2, 0, (char const   *)tmp___35, tmp___34);
      }
    } else {
      tmp___34 = quote((char const   *)files_from);
      tmp___35 = gettext("cannot read file names from %s");
      error(2, 0, (char const   *)tmp___35, tmp___34);
    }
    if (tok.n_tok) {
      free((void *)files);
      files = tok.tok;
      nfiles = tok.n_tok;
      i___0 = (size_t )0;
      while (1) {

        if (! (i___0 < nfiles)) {
          goto while_break___3;
        }
        tmp___42 = strcmp((char const   *)*(files + i___0), "-");
        if (tmp___42 == 0) {
          tmp___38 = quote((char const   *)*(files + i___0));
          tmp___39 = gettext("when reading file names from stdin, no file name of %s allowed");
          error(2, 0, (char const   *)tmp___39, tmp___38);
        } else
        if ((int )*(*(files + i___0) + 0) == 0) {
          file_number = i___0 + 1UL;
          tmp___40 = quotearg_colon((char const   *)files_from);
          tmp___41 = gettext("%s:%lu: invalid zero-length file name");
          error(2, 0, (char const   *)tmp___41, tmp___40, file_number);
        }
        i___0 ++;
      }
      while_break___3: ;
    } else {
      tmp___43 = quote((char const   *)files_from);
      tmp___44 = gettext("no input from %s");
      error(2, 0, (char const   *)tmp___44, tmp___43);
    }
  }
  key = keylist;
  while (1) {

    if (! key) {
      goto while_break___4;
    }
    tmp___45 = default_key_compare((struct keyfield  const  *)key);
    if (tmp___45) {
      if (! key->reverse) {
        key->ignore = gkey.ignore;
        key->translate = gkey.translate;
        key->skipsblanks = gkey.skipsblanks;
        key->skipeblanks = gkey.skipeblanks;
        key->month = gkey.month;
        key->numeric = gkey.numeric;
        key->general_numeric = gkey.general_numeric;
        key->human_numeric = gkey.human_numeric;
        key->version = gkey.version;
        key->random = gkey.random;
        key->reverse = gkey.reverse;
      }
    }
    need_random = (_Bool )((int )need_random | (int )key->random);
    key = key->next;
  }
  while_break___4: ;
  if (! keylist) {
    tmp___46 = default_key_compare((struct keyfield  const  *)(& gkey));
    if (! tmp___46) {
      gkey_only = (_Bool)1;
      insertkey(& gkey);
      need_random = (_Bool )((int )need_random | (int )gkey.random);
    }
  }
  check_ordering_compatibility();
  if (debug) {
    if (checkonly) {
      goto _L___2;
    } else
    if (outfile) {
      _L___2: 
      if (checkonly) {
        opts[0] = checkonly;
      } else {
        opts[0] = (char )'o';
      }
      incompatible_options((char const   *)(opts));
    }
    if (hard_LC_COLLATE) {
      tmp___47 = setlocale(3, (char const   *)((void *)0));
      tmp___48 = quote((char const   *)tmp___47);
      tmp___49 = gettext("using %s sorting rules");
      error(0, 0, (char const   *)tmp___49, tmp___48);
    } else {
      tmp___50 = gettext("using simple byte comparison");
      error(0, 0, (char const   *)tmp___50);
    }
    key_warnings((struct keyfield  const  *)(& gkey), gkey_only);
  }
  reverse = gkey.reverse;
  if (need_random) {
    random_md5_state_init((char const   *)random_source);
  }
  if (temp_dir_count == 0UL) {
    tmp___51 = (char const   *)getenv("TMPDIR");
    tmp_dir = tmp___51;
    if (tmp_dir) {
      tmp___52 = tmp_dir;
    } else {
      tmp___52 = "/tmp";
    }
    add_temp_dir(tmp___52);
  }
  if (nfiles == 0UL) {
    nfiles = (size_t )1;
    free((void *)files);
    files = & minus;
  }
  if (0UL < sort_size) {
    if (sort_size > (unsigned long )nmerge * (2UL + sizeof(struct line ))) {
      sort_size = sort_size;
    } else {
      sort_size = (unsigned long )nmerge * (2UL + sizeof(struct line ));
    }
  }
  if (checkonly) {
    if (nfiles > 1UL) {
      tmp___53 = quote((char const   *)*(files + 1));
      tmp___54 = gettext("extra operand %s not allowed with -%c");
      error(2, 0, (char const   *)tmp___54, tmp___53, (int )checkonly);
    }
    if (outfile) {
      opts___0[0] = checkonly;
      incompatible_options((char const   *)(opts___0));
    }
    tmp___57 = check((char const   *)*(files + 0), checkonly);
    if (tmp___57) {
      tmp___56 = 0;
    } else {
      tmp___56 = 1;
    }
    exit(tmp___56);
  }
  if (mergeonly) {
    tmp___58 = (struct sortfile *)xcalloc(nfiles, sizeof(*sortfiles));
    sortfiles = tmp___58;
    i___1 = (size_t )0;
    while (1) {

      if (! (i___1 < nfiles)) {
        goto while_break___5;
      }
      (sortfiles + i___1)->name = (char const   *)*(files + i___1);
      i___1 ++;
    }
    while_break___5: 
    merge(sortfiles, (size_t )0, nfiles, outfile);
  } else {
    if (! nthreads) {
      tmp___59 = num_processors((enum nproc_query )2);
      np = tmp___59;
      if (np < 8UL) {
        nthreads = np;
      } else {
        nthreads = (size_t )8;
      }
    }
    nthreads_max = 0xffffffffffffffffUL / (2UL * sizeof(struct merge_node ));
    if (nthreads < nthreads_max) {
      nthreads = nthreads;
    } else {
      nthreads = nthreads_max;
    }
    sort((char * const  *)files, nfiles, outfile, nthreads);
  }
  if (have_read_stdin) {
    tmp___61 = rpl_fclose(stdin);
    if (tmp___61 == -1) {
      tmp___60 = gettext("close failed");
      die((char const   *)tmp___60, "-");
    }
  }
  exit(0);
}
}
